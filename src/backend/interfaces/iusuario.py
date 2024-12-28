from abc import ABC, abstractmethod

# Interface para manipulação de usuários
class iUsuario:

    # Método abstrato para cadastrar um novo usuário
    @abstractmethod
    def cadastrar_usuario(nome: str = None, cpf: str = None):
        """
        Define a assinatura do método para cadastrar um novo usuário.
        Parâmetros:
        - nome: Nome do usuário.
        - cpf: CPF do usuário.
        """
        pass

    # Método abstrato para listar todos os usuários
    @abstractmethod
    def listar_todos_usuarios():
        """
        Define a assinatura do método para listar todos os usuários cadastrados.
        """
        pass

    # Método abstrato para listar um usuário específico
    @abstractmethod
    def listar_usuario(nome: str = None, cpf: str = None):
        """
        Define a assinatura do método para buscar informações de um usuário específico.
        Parâmetros:
        - nome: Nome do usuário a ser listado.
        - cpf: CPF do usuário a ser listado.
        """
        pass

    # Método abstrato para atualizar informações de um usuário
    @abstractmethod
    def atualizar_usuario(nome: str = None, cpf: str = None, permissao: str = None):
        """
        Define a assinatura do método para atualizar os dados de um usuário.
        Parâmetros:
        - nome: Nome do usuário a ser atualizado.
        - cpf: CPF do usuário a ser atualizado.
        - permissao: Nova permissão atribuída ao usuário.
        """
        pass

    # Método abstrato para deletar um usuário
    @abstractmethod
    def deletar_usuario(nome: str = None, cpf: str = None):
        """
        Define a assinatura do método para deletar um usuário do sistema.
        Parâmetros:
        - nome: Nome do usuário a ser deletado.
        - cpf: CPF do usuário a ser deletado.
        """
        pass

    # Método abstrato para listar títulos associados a todos os usuários
    @abstractmethod
    def listar_todos_titulo_usuario():
        """
        Define a assinatura do método para listar todos os títulos associados a usuários cadastrados.
        """
        pass
