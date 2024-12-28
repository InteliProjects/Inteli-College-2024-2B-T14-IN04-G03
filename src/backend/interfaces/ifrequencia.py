# Importa os módulos necessários para criar uma classe abstrata
from abc import ABC, abstractmethod

# Define a interface iFrequencia, que será implementada por outras classes
class iFrequencia:

    # Define um método abstrato registra_frequencia, que deve ser implementado pelas classes filhas
    # Os parâmetros 'liberado', 'horario' e 'id' são opcionais e recebem valores padrão 'None'
    @abstractmethod
    def registra_frequencia(liberado: str = None, horario: str = None, id: str = None):
        """
        Método abstrato que será responsável por registrar a frequência de um indivíduo ou dispositivo.
        - O parâmetro 'liberado' indica se o acesso foi permitido ou negado.
        - O parâmetro 'horario' representa o horário do registro de frequência.
        - O parâmetro 'id' identifica o indivíduo ou dispositivo relacionado ao registro.
        - As classes que implementarem essa interface devem fornecer a implementação desse método.
        """
        pass
