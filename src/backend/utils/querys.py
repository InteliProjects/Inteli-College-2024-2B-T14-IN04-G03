class Querys:
    def __init__(self, db_instance):
        self.db = db_instance

    def add_new(self, new):
        """
        Adiciona um novo registro ao banco de dados.
        :param new: Instância do modelo a ser adicionada.
        """
        self.db.session.add(new)
        self.db.session.commit()  # Confirma a transação para salvar a alteração
        print("Elemento cadastrado no banco de dados com sucesso")

    def update_user(self):
        """
        Atualiza informações de um registro existente no banco de dados.
        """
        self.db.session.commit()  # Confirma a transação de atualização
        print("Elemento atualizado no banco de dados com sucesso!")

    def delete_user(self, user):
        """
        Remove um registro do banco de dados.
        :param user: Instância do modelo a ser deletada.
        """
        self.db.session.delete(user)  # Marca o registro para exclusão
        self.db.session.commit()  # Confirma a transação de exclusão
        print("Elemento deletado do banco de dados com sucesso!")

    def list_all(self, table):
        return table.query.all()

    def listar_usuario(self, nome, cpf, table):
        """
        Busca um usuário no banco de dados com base no nome ou CPF.

        :param nome: Nome do usuário a ser buscado (string).
        :param cpf: CPF do usuário a ser buscado (string ou numérico).
        :param table: Classe do modelo ORM para consulta no banco de dados.
        :return: Instância do usuário encontrada ou `None` se não houver correspondência.
        """
        if nome:  # Busca o usuário pelo nome, se fornecido
            usuario = table.query.filter_by(nome=nome).first()
            if usuario:
                print("Usuário encontrado!")
                return usuario

        elif cpf:  # Busca o usuário pelo CPF, se fornecido
            usuario = table.query.filter_by(cpf=cpf).first()
            if usuario:
                print("Usuário encontrado!")
                return usuario

        print(f"Usuário não encontrado com o {'nome' if nome else 'CPF'} {nome if nome else cpf}")
        return None
    
    def listar_id(self, id, table):
        id_volta = table.query.filter_by(id=id).first()
        if id_volta:
            print("Id encontrado!")
            return id_volta
        
    def listar_acesso_usuario(self, id_esp, table):
        id_usuario = table.query.filter_by(id_esp=id_esp)
        if id_usuario:
            print("Usuário encontrado!")
            return id_usuario

    def listar_ultimo_id(self, table):
        return table.query.order_by(table.id.desc()).first()
