# Importa o módulo necessário para criar classes abstratas
from abc import ABC, abstractmethod

# Define uma interface para a classe de acesso
class iAcesso(ABC):
    """
    Classe abstrata que define a interface para manipulação de acessos.
    Implementa um método abstrato que deve ser sobrescrito pelas classes derivadas.
    """

    @abstractmethod
    def cadastrar_acesso(acesso: str = None, tag: str = None):
        """
        Método abstrato para cadastrar um acesso.
        As classes que herdam de `iAcesso` devem implementar esta funcionalidade.

        :param acesso: Representa o tipo ou nome do acesso (string).
        :param tag: Representa uma tag associada ao acesso (string).
        """
        pass  # Indica que a implementação será feita na classe derivada
