# Importa os módulos necessários para criar uma classe abstrata
from abc import ABC, abstractmethod

# Define a interface iEsp, que será implementada por outras classes
class iEsp:

    # Define um método abstrato esp_conectado, que deve ser implementado pelas classes filhas
    # O parâmetro 'connect' é opcional e recebe um valor padrão 'None'
    @abstractmethod
    def esp_conectado(connect: str = None):
        """
        Método abstrato que será responsável por verificar o status de conexão do dispositivo ESP.
        - O parâmetro 'connect' representa o estado de conexão do ESP e é opcional.
        - As classes que implementarem essa interface devem fornecer a implementação desse método.
        """
        pass

