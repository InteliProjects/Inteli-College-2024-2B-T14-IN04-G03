# from flask import Blueprint
# from repositorys.esp_repository import EspRepository 

# # Definição do Blueprint do Controller
# esp = Blueprint("esp", __name__)

# # Callback executado quando o cliente se conecta ao Broker MQTT
# @mqtt_client.on_connect()
# def handle_connect(client, userdata, flags, rc):
#     """
#     Função de callback chamada ao conectar com o Broker MQTT.
#     - Confirma se a conexão foi bem-sucedida (rc == 0).
#     - Inscreve o cliente em tópicos específicos.
#     """
#     if rc == 0:
#         print("A conexão com o Broker foi efetuada.")
#         # Inscreve-se no tópico para receber mensagens relacionadas ao ESP
#         topic1 = mqtt_client.subscribe("exodia/esp/conectado")
#         print(f"Inscritos com sucesso nos tópicos: {topic1},")
#     else:
#         print("Erro ao se conectar com o Broker...")

# # Variáveis globais para gerenciar a comunicação MQTT
# topic = None   # Armazena o tópico atual recebido
# cliente = None # Armazena o cliente MQTT
# connect = None # Armazena o estado de conexão recebido do ESP

# # Callback executado quando uma mensagem MQTT é recebida
# @mqtt_client.on_message
# def handle_mqtt_message(client, userdata, message):
#     """
#     Função de callback chamada ao receber uma mensagem MQTT.
#     - Atualiza as variáveis globais com informações do tópico e do payload.
#     - Verifica se o tópico corresponde ao ESP conectado.
#     """
#     global topic, connect, cliente
#     cliente = client                        # Atualiza o cliente
#     topic = message.topic                   # Atualiza o tópico recebido
#     payload = message.payload.decode()      # Decodifica o payload da mensagem

#     if topic == "exodia/esp/conectado":     # Verifica se o tópico é o esperado
#         connect = payload                   # Atualiza o estado de conexão

# # Instancia o repositório que gerencia operações relacionadas ao ESP
# espRepo = EspRepository()

# # Rota para verificar o estado de conexão do ESP
# @esp.route("/esp", ["GET"])
# def esp_conectado():
#     """
#     Endpoint para verificar o estado de conexão do ESP.
#     - Utiliza o repositório `EspRepository` para processar o estado.
#     - Retorna a resposta apropriada.
#     """
#     global connect
#     print(connect)
#     connect = connect  # Atualiza a variável global (manutenção do estado)
#     print("Esp conectado na rota!")
#     return espRepo.esp_conectado(connect)  # Retorna o resultado do repositório
