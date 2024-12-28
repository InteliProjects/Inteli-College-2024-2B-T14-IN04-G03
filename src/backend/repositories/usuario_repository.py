# Importa as interfaces, utilitários e dependências necessárias
from interfaces.iusuario import iUsuario
from utils.util import Util
from utils.querys import Querys
from flask import jsonify
from models import Usuario, TituloUsuario

# Implementação do repositório de usuários, seguindo a interface iUsuario
class UsuarioRepository(iUsuario):
    def __init__(self, db_instance):
        self.util = Util()
        self.query = Querys(db_instance)

    def cadastrar_usuario(self, nome, cpf, id_titulo_usuario):
        validacao = self.util.verify_data(nome, cpf)
        if not isinstance(validacao, list):
            print(f"Os dados recebidos são inválidos, Nome: {nome}, CPF: {cpf}")
            return jsonify({"error": "Dados inválidos."}), 400

        cpf = validacao[1]
        if self.query.listar_usuario(nome, cpf, Usuario):
            print("Usuário já existente no banco dados, cadastro invalidado")
            return jsonify({"error": "Usuário já existente no banco de dados."}), 400

        try:
            novo_usuario = Usuario(cpf=cpf, nome=nome, id_titulo_usuario=id_titulo_usuario)
            self.query.add_new(novo_usuario)
            print(f"Usuário criado com sucesso! {novo_usuario}")
            return jsonify({"message": "Usuário criado com sucesso!"}), 201
        except Exception as e:
            print(f"Erro ao cadastrar usuário: {str(e)}")
            return jsonify({"error": "Erro ao cadastrar usuário."}), 500

    # Método para listar todos os usuários
    def listar_todos_usuarios(self):
        """
        Retorna uma lista de todos os usuários cadastrados no banco de dados.
        - Obtém todos os usuários e organiza os dados em uma lista.
        - Retorna o resultado no formato JSON.
        """        
        usuarios = self.query.list_all(Usuario)

        resultado = []
        for u in usuarios:
            resultado.append({
                "id": u.id,
                "nome": u.nome,
                "cpf": u.cpf,
                "id_titulo_usuario": u.id_titulo_usuario
            })
        print("Usuários listados com sucesso!")
        return jsonify(resultado), 200

    # Método para listar um usuário específico por nome ou CPF
    def listar_usuario(self, nome, cpf):
        """
        Busca um usuário específico no banco de dados usando nome ou CPF.
        - Valida os dados fornecidos.
        - Retorna o usuário encontrado ou um erro caso não exista.
        """
        if not isinstance(self.util.verify_data(nome, cpf), list):
            print(f"Os dados recebidos são inválidos, Nome: {nome}, CPF: {cpf}")
            return self.util.verify_data(nome, cpf), 400
        
        else:
            cpf = self.util.verify_data(nome, cpf)[0]
            tabela_usuario = Usuario
            usuario = self.query.listar_usuario(nome, cpf, tabela_usuario)
            if usuario:
                print(f"Usuário encontrado com sucesso! {usuario}")
                return usuario, 200
            else:
                print("Usuário não encontrado.")
                return jsonify({"error": "Filtro não disponível"}), 400

    # Método para atualizar informações de um usuário
    def atualizar_usuario(self, nome, cpf, id_titulo_usuario):
        """
        Atualiza as informações de um usuário existente.
        - Valida os dados fornecidos.
        - Verifica se o usuário existe.
        - Atualiza os campos informados e salva as alterações no banco.
        """
        if not isinstance(self.util.verify_data(nome, cpf), list):
            print(f"Os dados recebidos são inválidos, Nome: {nome}, CPF: {cpf}")
            return self.util.verify_data(nome, cpf), 400
        else:
            cpf = self.util.verify_data(nome, cpf)[1]
            tabela_usuario = Usuario
            usuario = self.query.listar_usuario(nome, cpf, tabela_usuario)
            if not usuario:
                print("Usuário não encontrado no banco de dados...")
                return jsonify({"error": "Usuário não encontrado no banco de dados"}), 404
            else:
                print(usuario)
                if nome:
                    usuario.nome = nome
                if cpf:
                    usuario.cpf = cpf
                if id_titulo_usuario:
                    usuario.id_titulo_usuario = id_titulo_usuario
                self.query.update_user()
                print(f"Usuário encontrado com sucesso! {nome}, {cpf}, {id_titulo_usuario}")
                return jsonify({"message": "Usuário atualizado com sucesso!"}), 200

    # Método para deletar um usuário
    def deletar_usuario(self, cpf):
        """
        Remove um usuário do banco de dados com base no CPF.
        - Valida o CPF fornecido.
        - Verifica se o usuário existe.
        - Remove o registro e retorna a confirmação.
        """
        # Validação do CPF
        if not isinstance(self.util.verify_data("teste", cpf), list):
            print(f"O CPF fornecido é inválido: {cpf}")
            return jsonify({"error": "CPF inválido"}), 400

        # Obtém o CPF validado
        cpf = self.util.verify_data("teste", cpf)[1]

        # Verifica a existência do usuário no banco
        tabela_usuario = Usuario
        usuario = self.query.listar_usuario(None, cpf, tabela_usuario)
        if usuario:
            # Remove o usuário
            self.query.delete_user(usuario)
            print(f"O usuário com CPF {cpf} foi excluído do banco de dados!")
            return jsonify({"message": "Usuário excluído do banco de dados"}), 200
        else:
            print(f"Usuário com CPF {cpf} não encontrado.")
            return jsonify({"error": "Usuário não encontrado."}), 404


# Método para listar todos os títulos associados a usuários
def listar_todos_titulo_usuario(self):
    """
    Retorna uma lista de todos os títulos associados a usuários cadastrados.
    - Obtém todos os títulos do banco de dados.
    - Retorna o resultado no formato JSON.
    """
    # Obtém todos os registros de títulos de usuários do banco de dados
    todos_titulos = self.query.list_all(TituloUsuario)

    # Verifica se há títulos no banco de dados
    if todos_titulos:
        i = 1  # Inicializa o índice para identificar cada título
        titulos = {}  # Dicionário para armazenar os títulos no formato chave-valor
        titulos_unicos = set()  # Conjunto para garantir que os títulos não se repitam

        # Itera sobre todos os registros de títulos
        for u in todos_titulos:
            # Verifica se o título ainda não foi adicionado ao conjunto de títulos únicos
            if u.titulo not in titulos_unicos:
                # Adiciona o título ao dicionário com uma chave no formato "Título X"
                titulos[f"Título {i}"] = u.titulo
                # Marca o título como já processado, adicionando-o ao conjunto
                titulos_unicos.add(u.titulo)
                i += 1  # Incrementa o índice para o próximo título
        
        print(f"Os títulos foram adquiridos com sucesso! {titulos}")
        # Retorna os títulos no formato JSON com status HTTP 200
        return jsonify(titulos), 200
    else:
        # Caso não haja títulos no banco, imprime uma mensagem no console
        print("Nenhum título no banco de dados :(")
        # Retorna uma mensagem de erro no formato JSON com status HTTP 200
        return jsonify({"error": "Nenhum título no banco de dados :("}), 200
