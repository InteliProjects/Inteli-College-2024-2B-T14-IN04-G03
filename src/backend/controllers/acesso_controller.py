from flask import request, jsonify, Blueprint
from repositories.acesso_repository import AcessoRepository
from flask_mqtt import Mqtt

# Definição do blueprint do Controller
acesso = Blueprint("acesso", __name__)

mqtt_client = Mqtt(acesso)

# Evento disparado ao conectar com o broker MQTT
@mqtt_client.on_connect()
def handle_connect(client, userdata, flags, rc):
    """
    Callback executado quando o cliente conecta ao broker MQTT.
    Inscreve o cliente em tópicos e exibe mensagens de conexão.
    """
    if rc == 0:
        print("A conexão com o Broker foi efetuada.")  # Conexão bem-sucedida
        topic1 = mqtt_client.subscribe("exodia/esp/conectado")  # Inscrição no tópico
        print(f"Inscritos com sucesso nos tópicos: {topic1}")
    else:
        print("Erro ao se conectar com o Broker...")  # Mensagem de erro ao conectar

# Variáveis globais para manipular dados do MQTT e API
topic = None  # Último tópico recebido
cliente = None  # Cliente MQTT que enviou a mensagem
codigo_acesso = None  # Código do acesso recebido via MQTT

# Callback executado quando uma mensagem é recebida
@mqtt_client.on_message
def handle_mqtt_message(client, userdata, message):
    """
    Callback para tratar mensagens recebidas via MQTT.
    Decodifica o payload e processa com base no tópico.
    """
    global topic, codigo_acesso, cliente

    # Atualiza as variáveis globais com os dados recebidos
    cliente = client
    topic = message.topic
    payload = message.payload.decode()  # Decodifica o payload da mensagem

    # Verifica o tópico e atualiza o código de acesso
    if topic == "exodia/cadastro":
        codigo_acesso = payload

# Instancia o repositório de acesso para manipular os dados
acess = AcessoRepository()

# Endpoint para cadastro de acesso
@acesso.route("/acesso/cadastro", methods=["POST"])
def cadastro_acesso():
    """
    Endpoint para registrar um novo acesso (biometria ou RFID).
    Publica no tópico MQTT com o ID do usuário cadastrado.
    """
    global codigo_acesso
    print(codigo_acesso)
    # Obtém os dados enviados no corpo da requisição
    data = request.json
    if data and codigo_acesso:
        acesso = data.get("acesso")  # Tipo de acesso ("biometria" ou "rfid")
        print(data)
        # Chama o método do repositório para cadastrar o acesso
        acesso_type = acess.cadastrar_acesso(acesso, codigo_acesso)[0]  # Tipo de acesso retornado
        id_usuario = acess.cadastrar_acesso(acesso, codigo_acesso)[1]  # ID do usuário retornado

        # Verifica o tipo de acesso e retorna a resposta correspondente
        if acesso_type == 1:  # Caso de biometria
            mqtt_client.publish("topico_foda", id_usuario)  # Publica no tópico MQTT
            print("Id do Usuário publicado com sucesso na rota!")
            return jsonify({"message": "A biometria foi registrada com sucesso!"}), 200
        
        if acesso_type == 2:  # Caso de RFID
            mqtt_client.publish("topico_foda", id_usuario)  # Publica no tópico MQTT
            print("Id do Usuário publicado com sucesso na rota!")
            return jsonify({"message": "O RFID foi registrado com sucesso!"}), 200
    
        if acesso_type == 3:  # Caso de erro
            print("Algo deu errado na rota!")
            return jsonify({"error": "Ocorreu algum erro :("}), 400
    
    else:
        return jsonify({"error":"Ocorreu algum erro..."})
