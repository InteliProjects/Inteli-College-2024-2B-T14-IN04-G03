from os import getenv

class Config:
    # URL da API que será utilizada para enviar requisições
    API_BASE_URL = "https://two024-2b-t14-in04-g03.onrender.com"

    # Outras configurações opcionais
    DEBUG = True
    ENV = getenv('FLASK_ENV', 'production')  # Usar a variável FLASK_ENV ou 'production' por padrão
