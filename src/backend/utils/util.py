import re  # Biblioteca para trabalhar com expressões regulares
from flask import jsonify  # Utilizada para manipular respostas e requisições HTTP

class Util:
    """
    Classe `Util` contém métodos auxiliares para verificar e procurar dados, como nome e CPF.
    """

    @staticmethod
    def verify_data(name, cpf):
        """
        Verifica a validade dos dados de entrada (nome e CPF).

        - Limpa o CPF de caracteres não numéricos e valida seu formato.
        - Valida o nome para garantir que contenha apenas letras e espaços.

        :param name: Nome do usuário (string).
        :param cpf: CPF do usuário (string ou numérico).
        :return: JSON de erro com código 400 ou lista com nome e CPF limpo.
        """
        # Valida o nome
        if not re.fullmatch(r'[A-Za-zÀ-ÖØ-öø-ÿ\s]+', name):  # Nome pode conter letras e espaços
            return jsonify({"error": "O nome do usuário é inválido. Use apenas letras e espaços."}), 400

        # Limpa o CPF e valida
        cpf = str(cpf) if cpf else ""
        cpf_limpo = re.sub(r'[^0-9]', '', cpf)
        
        if not cpf_limpo or len(cpf_limpo) != 11 or not cpf_limpo.isdigit():
            return jsonify({"error": "O CPF do usuário é inválido. Deve conter exatamente 11 dígitos numéricos."}), 400

        # Retorna os dados limpos para uso posterior
        return [name.strip(), cpf_limpo]
