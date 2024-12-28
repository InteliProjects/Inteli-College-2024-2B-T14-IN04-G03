
from flask import Flask, request, jsonify
from flask_cors import CORS
import requests
from config import Config

# Inicialização do Flask
app = Flask(__name__)

# Configurar o CORS para aceitar requisições de qualquer origem
CORS(app)

# Adicionar cabeçalhos CORS a todas as respostas
@app.after_request
def add_cors_headers(response):
    response.headers["Access-Control-Allow-Origin"] = "*"
    response.headers["Access-Control-Allow-Methods"] = "GET, POST, PUT, DELETE, OPTIONS"
    response.headers["Access-Control-Allow-Headers"] = "Content-Type, Authorization"
    return response

# Base URL da API
API_BASE_URL = Config.API_BASE_URL

# Rota para criar um novo usuário
@app.route('/usuario', methods=['POST', 'OPTIONS'])
def create_usuario():
    if request.method == 'OPTIONS':
        # Responde à requisição preflight
        response = jsonify()
        response.headers["Access-Control-Allow-Origin"] = "*"
        response.headers["Access-Control-Allow-Methods"] = "GET, POST, OPTIONS"
        response.headers["Access-Control-Allow-Headers"] = "Content-Type, Authorization"
        return response, 204
    else:
        # Processa a requisição POST
        data = request.get_json()
        response = requests.post(f"{API_BASE_URL}/usuario", json=data)

        if response.status_code == 201:
            return jsonify(response.json()), 201
        return jsonify(response.json()), response.status_code

# Rota para listar todos os usuários
@app.route('/usuarios', methods=['GET'])
def get_usuarios():
    response = requests.get(f"{API_BASE_URL}/usuarios")

    if response.status_code == 200:
        return jsonify(response.json()), 200
    return jsonify({'error': 'Erro ao buscar usuários'}), response.status_code

# Rota para editar um usuário
@app.route('/usuarios/<int:id>', methods=['PUT'])
def update_usuario(id):
    data = request.get_json()
    response = requests.put(f"{API_BASE_URL}/usuarios/{id}", json=data)

    if response.status_code == 200:
        return jsonify(response.json()), 200
    return jsonify(response.json()), response.status_code

# Rota para excluir um usuário
@app.route('/usuarios/<int:id>', methods=['DELETE'])
def delete_usuario(id):
    response = requests.delete(f"{API_BASE_URL}/usuarios/{id}")

    if response.status_code == 204:
        return jsonify({'message': 'Usuário excluído com sucesso'}), 204
    return jsonify(response.json()), response.status_code

# Rota para listar permissões
@app.route('/permissoes', methods=['GET'])
def get_permissoes():
    response = requests.get(f"{API_BASE_URL}/permissoes")

    if response.status_code == 200:
        return jsonify(response.json()), 200
    return jsonify({'error': 'Erro ao buscar permissões'}), response.status_code

# Rota para listar títulos de usuários
@app.route('/titulos_usuario', methods=['GET'])
def get_titulos_usuario():
    response = requests.get(f"{API_BASE_URL}/titulos_usuario")

    if response.status_code == 200:
        return jsonify(response.json()), 200
    return jsonify({'error': 'Erro ao buscar títulos de usuários'}), response.status_code

# Rota para registrar um evento
@app.route('/evento', methods=['POST', 'OPTIONS'])
def create_evento():
    if request.method == 'OPTIONS':
        # Responde à requisição preflight
        response = jsonify()
        response.headers["Access-Control-Allow-Origin"] = "*"
        response.headers["Access-Control-Allow-Methods"] = "GET, POST, OPTIONS"
        response.headers["Access-Control-Allow-Headers"] = "Content-Type, Authorization"
        return response, 204
    else:
        # Processa a requisição POST
        data = request.get_json()
        response = requests.post(f"{API_BASE_URL}/evento", json=data)

        if response.status_code == 201:
            return jsonify(response.json()), 201
        return jsonify(response.json()), response.status_code

# Rota para listar eventos
@app.route('/eventos', methods=['GET'])
def get_eventos():
    response = requests.get(f"{API_BASE_URL}/eventos")

    if response.status_code == 200:
        return jsonify(response.json()), 200
    return jsonify({'error': 'Erro ao buscar eventos'}), response.status_code

# Inicialização da aplicação
if __name__ == '__main__':
=======
from flask import Flask, jsonify, request
from flask_cors import CORS
from flask_mqtt import Mqtt
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy.exc import OperationalError
from repositories.acesso_repository import AcessoRepository
from repositories.esp_repository import EspRepository
from repositories.frequencia_repository import FrequenciaRepository
from repositories.usuario_repository import UsuarioRepository
from dotenv import load_dotenv
from os import getenv
from utils.database import db
from config import Config
from flask_migrate import Migrate

# Cria a instância do Flask
app = Flask(__name__)

# Cria a instância do CORS
CORS(app)

# Carrega as variáveis de ambiente
load_dotenv()

# Configurações do app
app.config['MQTT_BROKER_URL'] = "broker.hivemq.com"
app.config['MQTT_BROKER_PORT'] = 1883
app.config['MQTT_USERNAME'] = ''
app.config['MQTT_PASSWORD'] = ''
app.config['MQTT_KEEPALIVE'] = 60
app.config['MQTT_TLS_ENABLED'] = False

# Configurações do SQLAlchemy, para conexão no banco de dados
print(getenv('EXTERNAL_DATABASE_URL'))
app.config['SQLALCHEMY_DATABASE_URI'] = getenv('EXTERNAL_DATABASE_URL') 
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

print(app.config['SQLALCHEMY_DATABASE_URI'])

# app.config.from_object(Config)
db.init_app(app)
migrate = Migrate(app, db)

# Inicializa o SQLAlchemy, para manipula��ão do banco de dados
#db.init_app(app)

with app.app_context():
    db.create_all()  # Cria as tabelas no banco de dados

# Tratamento de erros para falhas na conexão com o banco de dados
@app.errorhandler(OperationalError)
def handle_db_error(error):
    """
    Lida com erros de conexão ao banco de dados e retorna uma mensagem JSON.
    """
    print("Erro ao conectar no banco de dados :(")
    return jsonify({'error': 'Erro ao conectar ao banco de dados', 'message': str(error)}), 500

mqtt_client = Mqtt(app)

dados_mqtt = {
    "topic": None,
    "codigo_acesso": None,
    "connect": None,
    "frequencia": None
}

# Evento de conexão com o broker
@mqtt_client.on_connect()
def handle_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Conexão com o Broker efetuada.")
        mqtt_client.subscribe("exodia/esp/conectado")
        mqtt_client.subscribe("exodia/esp/frequencia")
        mqtt_client.subscribe("exodia/cadastro")
    else:
        print("Erro ao conectar com o Broker.")

# Evento de recebimento de mensagens
@mqtt_client.on_message()
def handle_mqtt_message(client, userdata, message):
    payload = message.payload.decode()
    if message.topic == "exodia/esp/conectado":
        dados_mqtt["connect"] = payload
    elif message.topic == "exodia/esp/frequencia":
        dados_mqtt["frequencia"] = payload
    elif message.topic == "exodia/cadastro":
        dados_mqtt["codigo_acesso"] = payload

# Repositórios
acesso_repo = AcessoRepository(db)
esp_repo = EspRepository()
user_repo = UsuarioRepository(db)
freq_repo = FrequenciaRepository(db)

# Rotas
@app.route("/acesso/cadastro", methods=["POST"])
def cadastro_acesso():
    data = request.json
    codigo_acesso = dados_mqtt.get("codigo_acesso")
    if data and codigo_acesso:
        acesso = data.get("acesso")
        acesso_type, id_usuario = acesso_repo.cadastrar_acesso(acesso, codigo_acesso)

        if acesso_type in [1, 2]:
            mqtt_client.publish("topico_foda", id_usuario)
            mensagem = "A biometria foi registrada com sucesso!" if acesso_type == 1 else "O RFID foi registrado com sucesso!"
            return jsonify({"message": mensagem}), 200
        return jsonify({"error": "Ocorreu algum erro :("}), 400
    return jsonify({"error": "Dados incompletos..."}), 400

@app.route("/esp", methods=["GET"])
def esp_conectado():
    connect = dados_mqtt.get("connect")
    return esp_repo.esp_conectado(connect)

@app.route("/usuario/cadastro", methods=["POST"])
def cadastrar_usuario():
    data = request.json
    if not data:
        return jsonify({"error": "Nenhum dado fornecido na requisição"}), 400

    nome = data.get("nome")
    cpf = data.get("cpf")
    id_titulo_usuario = data.get("id_titulo_usuario")

    if not nome or not cpf or id_titulo_usuario is None:
        return jsonify({"error": "Campos obrigatórios faltando: 'nome', 'cpf', ou 'id_titulo_usuario'"}), 400

    response, status_code = user_repo.cadastrar_usuario(nome=nome, cpf=cpf, id_titulo_usuario=id_titulo_usuario)
    return response, status_code

@app.route("/usuario/", methods=["GET"])
def listar_todos_usuarios():
    return user_repo.listar_todos_usuarios()

@app.route("/usuario/listar", methods=["GET"])
def listar_usuario():
    data = request.json
    nome = data.get("nome")
    cpf = data.get("cpf")
    return user_repo.listar_usuario(nome, cpf)

@app.route("/usuario/atualizar", methods=["PUT"])
def atualizar_usuario():
    data = request.json
    nome = data.get("nome")
    cpf = data.get("cpf")
    id_titulo_usuario = data.get("id_titulo_usuario")
    
    response, status_code = user_repo.atualizar_usuario(nome, cpf, id_titulo_usuario)
    return response, status_code

@app.route("/usuario/deletar/<cpf>", methods=["DELETE"])
def deletar_usuario(cpf):
    response, status_code = user_repo.deletar_usuario(cpf=cpf)
    return response, status_code


@app.route("/usuario/titulos", methods=["GET"])
def listar_todos_titulos_usuario():
    response, status_code = user_repo.listar_todos_titulo_usuario()
    return response, status_code

@app.route("/frequencia", methods=["POST"])
def registra_frequencia():
    frequencia = dados_mqtt.get("frequencia")
    if frequencia:
        try:
            liberado, id_usuario, horario = frequencia.split(",")
            freq_repo.registra_frequencia(liberado, id_usuario, horario)
            return jsonify({"message": "Frequência registrada com sucesso!"}), 200
        except Exception as e:
            return jsonify({"error": f"Erro ao processar frequência: {str(e)}"}), 400
    return jsonify({"error": "Dados de frequência não foram recebidos."}), 400

@app.route("/frequencia/listar", methods=["GET"])
def listar_frequencias():
    return freq_repo.listar_frequencias()

if __name__ == "__main__":

    app.run(debug=True)
