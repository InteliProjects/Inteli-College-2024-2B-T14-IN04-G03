from flask import jsonify
from interfaces.ifrequencia import iFrequencia
from utils.querys import Querys
from models import Frequencia
from datetime import datetime

# Define a classe FrequenciaRepository, que implementa a interface iFrequencia
class FrequenciaRepository(iFrequencia):
    def __init__(self, db_instance):
        self.query = Querys(db_instance)

    def registra_frequencia(self, id_usuario: int, hora: str, data: str):
        """
        Método responsável por registrar uma atividade de frequência no banco de dados.

        Parâmetros:
        - id_usuario (int): ID do usuário a ser registrado.
        - hora (str): Horário no formato 'HH:MM:SS'.
        - data (str): Data no formato 'YYYY-MM-DD'.

        Retorno:
        - JSON contendo uma mensagem sobre o resultado da operação e o status HTTP.
        """
        try:
            # Converte as strings de hora e data para os tipos datetime apropriados
            hora_obj = datetime.strptime(hora, '%H:%M:%S').time()
            data_obj = datetime.strptime(data, '%Y-%m-%d').date()

            # Cria uma nova entrada de frequência
            atividade = Frequencia(
                id_usuario=id_usuario,
                horario=hora_obj,
                data=data_obj
            )

            # Adiciona ao banco de dados
            self.query.add_new(atividade)

            # Define a mensagem de sucesso
            mensagem = "Frequência registrada com sucesso"
            print(f"\"{mensagem}\" para o usuário ID {id_usuario} no banco de dados!")
            return jsonify({"message": f"{mensagem} para o usuário ID {id_usuario} no banco de dados!"}), 200

        except ValueError as e: # Erro na conversão de hora ou data
            return jsonify({"message": f"Erro nos formatos de hora ou data: {str(e)}"}), 400

        except Exception as e: # Captura outras exceções
            return jsonify({"message": f"Erro ao registrar frequência: {str(e)}"}), 500

        
    def listar_frequencias(self):
        try:
            frequencias = Frequencia.query.all()
            frequencias_lista = []
            
            for freq in frequencias:
                frequencias_lista.append({
                    'id': freq.id,
                    'id_usuario': freq.id_usuario,
                    'horario': freq.horario.strftime('%H:%M:%S') if freq.horario else None,
                    'data': freq.data.strftime('%Y-%m-%d') if freq.data else None
                })
            
            return jsonify({
                'message': 'Frequências listadas com sucesso',
                'frequencias': frequencias_lista
            }), 200
        except Exception as e:
            return jsonify({
                'error': f'Erro ao listar frequências: {str(e)}'
            }), 400