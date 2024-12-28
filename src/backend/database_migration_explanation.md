Step-by-Step Instructions:
Install Flask-Migrate: If you haven't installed Flask-Migrate, you can install it using pip.

```shell
pip install Flask-Migrate
```

Initialize Flask-Migrate: In your app.py, initialize Flask-Migrate.

```python
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from config import Config
from models import db

app = Flask(__name__)
app.config.from_object(Config)
db.init_app(app)
migrate = Migrate(app, db)

if __name__ == '__main__':
    app.run(debug=True)
```

Create Migrations Directory: Initialize the migrations directory.

```shell
flask db init
```

Generate Initial Migration: Create an initial migration script.

```shell
flask db migrate -m "Initial migration."
```

Apply the Migration: Apply the migration to create the tables in the database.

```shell
flask db upgrade
```

Verify the Tables: Ensure that the tables are created in the database. You can use a database client or command-line tool to check the tables.

Example app.py with Flask-Migrate:

```python
from flask import Flask, request, jsonify
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from config import Config
from models import db, Usuario
from sqlalchemy.exc import OperationalError

app = Flask(__name__)
app.config.from_object(Config)
db.init_app(app)
migrate = Migrate(app, db)

@app.route('/usuario', methods=['POST'])
def create_usuario():
    try:
        data = request.get_json()
        if not data:
            return jsonify({'error': 'Invalid JSON payload'}), 400

        nome = data.get('nome')
        cpf = data.get('cpf')
        id_acesso = data.get('id_acesso')
        id_tipo_usuario = data.get('id_tipo_usuario')

        # Verificar se o usuário já existe
        if Usuario.query.filter_by(cpf=cpf).first():
            return jsonify({'error': 'Usuário com este CPF já existe'}), 400

        novo_usuario = Usuario(nome=nome, cpf=cpf, id_acesso=id_acesso, id_tipo_usuario=id_tipo_usuario)
        db.session.add(novo_usuario)
        db.session.commit()

        return jsonify({'message': 'Usuário criado com sucesso'}), 201
    except Exception as e:
        return jsonify({'error': 'Failed to create user', 'message': str(e)}), 400

@app.errorhandler(OperationalError)
def handle_db_error(error):
    return jsonify({'error': 'Erro ao conectar ao banco de dados', 'message': str(error)}), 500

if __name__ == '__main__':
    app.run(debug=True)
```

By following these steps, you should be able to create the necessary tables in your database and resolve the UndefinedTable error.