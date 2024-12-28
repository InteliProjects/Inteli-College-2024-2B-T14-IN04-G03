# Importa as bibliotecas e módulos necessários
from flask import Flask, request, Blueprint
from repositories.usuario_repository import UsuarioRepository 

# Definição do Blueprint do Controller
usuario = Blueprint("usuario", __name__)

# Instancia o repositório de usuários, responsável pelas operações no banco de dados
user = UsuarioRepository()

# Endpoint para cadastrar um novo usuário
@usuario.route("/usuario/cadastro", methods=["POST"])
def cadastrar_usuario():
    """
    Rota para cadastrar um novo usuário.
    - Recebe dados do usuário em formato JSON (nome, CPF e ID do título de usuário).
    - Chama o método correspondente no repositório de usuários.
    """
    data = request.json                         # Obtém o corpo da requisição
    print(data)
    if data:
        nome = data.get("nome")                     # Extrai o nome do usuário
        cpf = data.get("cpf")                       # Extrai o CPF do usuário
        id_titulo_usuario = data.get("id_titulo_usuario")  # Extrai o ID do título do usuário
        print("Cadastra todos usuários na rota!")
        return user.cadastrar_usuario(nome, cpf, id_titulo_usuario)  # Realiza o cadastro

# Endpoint para listar todos os usuários cadastrados
@usuario.route("/usuario/", methods=["GET"])
def listar_todos_usuarios():
    """
    Rota para listar todos os usuários cadastrados.
    - Não requer parâmetros.
    - Retorna uma lista de usuários.
    """
    print("Lista todos usuários na rota!")
    return user.listar_todos_usuarios()

# Endpoint para listar um usuário específico com base em nome ou CPF
@usuario.route("/usuario/listar", methods=["GET"])
def listar_usuario():
    """
    Rota para listar um usuário específico.
    - Recebe dados em formato JSON (nome e/ou CPF).
    - Chama o método correspondente no repositório de usuários.
    """
    data = request.json                         # Obtém o corpo da requisição
    print(data)
    nome = data.get("nome")                     # Extrai o nome do usuário
    cpf = data.get("cpf")                       # Extrai o CPF do usuário

    print("Lista usuário na rota!")
    return user.listar_usuario(nome, cpf)       # Realiza a busca no repositório

# Endpoint para atualizar informações de um usuário
@usuario.route("/usuario/atualizar", methods=["PUT"])
def atualizar_usuario():
    """
    Rota para atualizar informações de um usuário.
    - Recebe dados em formato JSON (nome, CPF e ID do título de usuário).
    - Chama o método correspondente no repositório de usuários.
    """
    data = request.json                         # Obtém o corpo da requisição
    print(data)
    nome = data.get("nome")                     # Extrai o novo nome do usuário (se houver)
    cpf = data.get("cpf")                       # Extrai o novo CPF do usuário (se houver)
    id_titulo_usuario = data.get("id_titulo_usuario")  # Extrai o novo ID do título de usuário

    print("Atualiza o usuário na rota!")
    return user.atualizar_usuario(nome, cpf, id_titulo_usuario)  # Realiza a atualização

# Endpoint para deletar um usuário do sistema
@usuario.route("/usuario/deletar", methods=["DELETE"])
def deletar_usuario():
    """
    Rota para deletar um usuário do sistema.
    - Recebe dados em formato JSON (nome e CPF).
    - Chama o método correspondente no repositório de usuários.
    """
    data = request.json                         # Obtém o corpo da requisição
    print(data)
    nome = data.get("nome")                     # Extrai o nome do usuário
    cpf = data.get("cpf")                       # Extrai o CPF do usuário

    print("Deleta usuário na rota!")
    return user.deletar_usuario(nome, cpf)      # Realiza a exclusão no repositório

# Endpoint para listar todos os títulos de usuário
@usuario.route("usuario/titulos", methods=["GET"])
def listar_todos_titulos_usuario():
    """
    Rota para listar todos os títulos de usuário disponíveis.
    - Não requer parâmetros.
    - Retorna uma lista de títulos de usuários.
    """
    print("Lista todos os títulos na rota!")
    return user.listar_todos_titulo_usuario()   # Busca os títulos no repositório
