from flask import jsonify
from interfaces.iacesso import iAcesso
from models import Acesso, Usuario, AcessoUsuario
from utils.querys import Querys

class AcessoRepository(iAcesso):
    def __init__(self, db_instance):
        self.query = Querys(db_instance)
    
    def cadastrar_acesso(self, acesso: str, id_esp) -> list[int] | int:
        try:
            if not isinstance(acesso, str) or not isinstance(id_esp, int):
                raise ValueError("Os parâmetros não estão no formato correto")

            tipo_acesso = {"biometria": 1, "rfid": 2}.get(acesso)
            if not tipo_acesso:
                raise ValueError("Tipo de acesso inválido. Use 'biometria' ou 'rfid'.")

            self.query.add_new(Acesso(forma_acesso=tipo_acesso))

            ultimo_usuario = self.query.listar_ultimo_id(Usuario)
            ultimo_acesso = self.query.listar_ultimo_id(Acesso)

            novo_cadastro = AcessoUsuario(
                id_acesso=ultimo_acesso.id,
                id_usuario=ultimo_usuario.id,
                id_esp=id_esp
            )
            self.query.add_new(novo_cadastro)

            print(f"Novo cadastro feito com sucesso! {novo_cadastro}")
            return [tipo_acesso, novo_cadastro.id_usuario]

        except ValueError as e:
            print(f"Erro: {e}")
            return 3
        except Exception as e:
            print(f"Erro inesperado: {e}")
            return 3
