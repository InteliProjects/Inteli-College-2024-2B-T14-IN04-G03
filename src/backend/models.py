from utils.database import db

# Tabela 'titulo_usuario'
class TituloUsuario(db.Model):
    __tablename__ = 'titulo_usuario'
    id = db.Column(db.Integer, primary_key=True)
    titulo = db.Column(db.String(100), nullable=False)

# Tabela 'acesso'
class Acesso(db.Model):
    __tablename__ = 'acesso'
    id = db.Column(db.Integer, primary_key=True)
    forma_acesso = db.Column(db.String(100), nullable=False)

# Tabela 'usuario'
class Usuario(db.Model):
    __tablename__ = 'usuario'
    id = db.Column(db.Integer, primary_key=True)
    nome = db.Column(db.String(100), nullable=False)
    cpf = db.Column(db.String(11), unique=True, nullable=False)
    id_titulo_usuario = db.Column(db.Integer, db.ForeignKey('titulo_usuario.id', ondelete='CASCADE'))

# Tabela 'acesso_usuario'
class AcessoUsuario(db.Model):
    __tablename__ = 'acesso_usuario'
    id = db.Column(db.Integer, primary_key=True)
    id_acesso = db.Column(db.Integer, db.ForeignKey('acesso.id', ondelete='CASCADE'))
    id_usuario = db.Column(db.Integer, db.ForeignKey('usuario.id', ondelete='CASCADE'))
    id_esp = db.Column(db.Text, nullable=True)


# Tabela 'frequencia'
class Frequencia(db.Model):
    __tablename__ = 'frequencia'
    id = db.Column(db.Integer, primary_key=True)
    id_usuario = db.Column(db.Integer, db.ForeignKey('usuario.id', ondelete='CASCADE'))
    horario = db.Column(db.Time)
    data = db.Column(db.Date)

class Esp(db.Model):
    __tablename__ = 'esp'
    id = db.Column(db.Integer, primary_key=True)
    id_esp = db.Column(db.Integer, nullable=False)  # Nova coluna adicionada
