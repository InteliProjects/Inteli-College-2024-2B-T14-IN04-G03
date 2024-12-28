import pytest
from backend.app import app

@pytest.fixture
def client():
    """Fixture para configurar o cliente de teste do Flask."""
    app.config['TESTING'] = True
    with app.test_client() as client:
        yield client

def test_cadastro_acesso(client, mocker):
    """Teste para a rota /acesso/cadastro."""
    mocker.patch("repositories.acesso_repository.AcessoRepository.cadastrar_acesso", return_value=(1, 123))
    response = client.post(
        "/acesso/cadastro", 
        json={"acesso": "biometria"}
    )
    assert response.status_code == 200
    assert b"biometria foi registrada com sucesso" in response.data

def test_esp_conectado(client, mocker):
    """Teste para a rota /esp."""
    mocker.patch("repositories.esp_repository.EspRepository.esp_conectado", return_value={"status": "connected"})
    response = client.get("/esp")
    assert response.status_code == 200
    assert b"connected" in response.data

def test_cadastrar_usuario(client, mocker):
    """Teste para a rota /usuario/cadastro."""
    mocker.patch("repositories.usuario_repository.UsuarioRepository.cadastrar_usuario", return_value={"message": "Usuário cadastrado com sucesso!"})
    response = client.post(
        "/usuario/cadastro", 
        json={"nome": "João", "cpf": "12345678901", "id_titulo_usuario": 1}
    )
    assert response.status_code == 200
    assert "Usuário cadastrado com sucesso" in response.data

def test_listar_todos_usuarios(client, mocker):
    """Teste para a rota /usuario/."""
    mocker.patch("repositories.usuario_repository.UsuarioRepository.listar_todos_usuarios", return_value={"usuarios": []})
    response = client.get("/usuario/")
    assert response.status_code == 200
    assert b"usuarios" in response.data

def test_listar_usuario(client, mocker):
    """Teste para a rota /usuario/listar."""
    mocker.patch("repositories.usuario_repository.UsuarioRepository.listar_usuario", return_value={"usuario": {"nome": "João", "cpf": "12345678901"}})
    response = client.get(
        "/usuario/listar", 
        json={"nome": "João", "cpf": "12345678901"}
    )
    assert response.status_code == 200
    assert "João" in response.data

def test_atualizar_usuario(client, mocker):
    """Teste para a rota /usuario/atualizar."""
    mocker.patch("repositories.usuario_repository.UsuarioRepository.atualizar_usuario", return_value={"message": "Usuário atualizado com sucesso!"})
    response = client.put(
        "/usuario/atualizar", 
        json={"nome": "João", "cpf": "12345678901", "id_titulo_usuario": 2}
    )
    assert response.status_code == 200
    assert "Usuário atualizado com sucesso" in response.data

def test_deletar_usuario(client, mocker):
    """Teste para a rota /usuario/deletar."""
    mocker.patch("repositories.usuario_repository.UsuarioRepository.deletar_usuario", return_value={"message": "Usuário deletado com sucesso!"})
    response = client.delete(
        "/usuario/deletar", 
        json={"nome": "João", "cpf": "12345678901"}
    )
    assert response.status_code == 200
    assert "Usuário deletado com sucesso" in response.data

def test_listar_todos_titulos_usuario(client, mocker):
    """Teste para a rota /usuario/titulos."""
    mocker.patch("repositories.usuario_repository.UsuarioRepository.listar_todos_titulo_usuario", return_value={"titulos": []})
    response = client.get("/usuario/titulos")
    assert response.status_code == 200
    assert b"titulos" in response.data

def test_registra_frequencia(client, mocker):
    """Teste para a rota /frequencia."""
    mocker.patch("repositories.frequencia_repository.FrequenciaRepository.registra_frequencia", return_value=None)
    response = client.post("/frequencia")
    assert response.status_code == 400
    assert "Dados de frequência não foram recebidos" in response.data
