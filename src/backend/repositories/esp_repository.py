# Importa a interface iEsp, que define o contrato para o funcionamento do método esp_conectado
from interfaces.iesp import iEsp
# Importa jsonify para criar respostas JSON para a API
from flask import jsonify

# Define a classe EspRepository, que implementa a interface iEsp
class EspRepository(iEsp):

    # Implementação do método esp_conectado, que verifica o estado de conexão do dispositivo ESP
    # O parâmetro 'connect' é opcional e tem valor padrão None
    def esp_conectado(self, connect=None):
        conectado = connect == "dispositivo conectado"
        mensagem = "ESP32 conectado com sucesso!" if conectado else "O ESP32 ainda não está conectado..."
        status = 200 if conectado else 400
        print(mensagem)
        return jsonify({"message" if conectado else "error": mensagem}), status
