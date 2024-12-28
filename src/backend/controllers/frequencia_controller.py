from flask_mqtt import Mqtt
from repositories.frequencia_repository import FrequenciaRepository
from flask import Flask, jsonify, Blueprint

# Definição do Blueprint do Controller
frequencia = Blueprint("frequencia", __name__)

# Instancia o cliente MQTT para comunicação com o Broker
mqtt_client = Mqtt(frequencia)

# Callback executado quando o cliente se conecta ao Broker MQTT
@mqtt_client.on_connect()
def handle_connect(client, userdata, flags, rc):
    """
    Função de callback chamada ao conectar com o Broker MQTT.
    - Confirma se a conexão foi bem-sucedida (rc == 0).
    - Inscreve o cliente em tópicos específicos.
    """
    if rc == 0:
        print("A conexão com o Broker foi efetuada.")
        # Inscreve-se no tópico para receber mensagens relacionadas ao ESP
        topic1 = mqtt_client.subscribe("exodia/esp/conectado")
        print(f"Inscritos com sucesso nos tópicos: {topic1},")
    else:
        print("Erro ao se conectar com o Broker...")

# Variáveis globais para gerenciar a comunicação MQTT
topic = None   # Armazena o tópico atual recebido
cliente = None # Armazena o cliente MQTT
frequencia = None # Armazena o estado de conexão recebido do ESP

# Callback executado quando uma mensagem MQTT é recebida
@mqtt_client.on_message
def handle_mqtt_message(client, userdata, message):
    """
    Função de callback chamada ao receber uma mensagem MQTT.
    - Atualiza as variáveis globais com informações do tópico e do payload.
    - Verifica se o tópico corresponde ao ESP conectado.
    """
    global topic, frequencia, cliente
    cliente = client                        # Atualiza o cliente
    topic = message.topic                   # Atualiza o tópico recebido
    payload = message.payload.decode()      # Decodifica o payload da mensagem

    if topic == "exodia/esp/frequencia":     # Verifica se o tópico é o esperado
        frequencia = payload                   # Atualiza o estado de conexão

freq = FrequenciaRepository()

# Define uma rota POST para registrar frequência
@frequencia.route("/frequencia", methods=["POST"])
def registra_frequencia():
    """
    Endpoint para registrar uma frequência no banco de dados.
    - Obtém informações da mensagem MQTT e as utiliza para registrar a frequência.
    - Retorna erro se os dados não forem recebidos corretamente.
    """
    global frequencia
    print(frequencia)
    # Desempacota os dados da frequência
    liberado = frequencia[0] if frequencia else None
    id_esp = frequencia[1] if frequencia else None
    horario = frequencia[2] if frequencia else None

    if liberado and horario:
        print(f"Dados de frequência recebidos: {liberado}, {id_esp}, {horario}")
        freq.registra_frequencia(liberado, id_esp, horario)  # Registra a frequência no banco
        return jsonify({"message": "Frequência registrada com sucesso"}), 200
    else:
        print("Erro: Dados de frequência não foram recebidos corretamente.")
        return jsonify({"error": "Dados relacionados à frequência não foram recebidos corretamente"}), 400