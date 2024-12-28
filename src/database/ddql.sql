-- Tabela 'permissao' define os tipos de permissões.
CREATE TABLE permissao (
	id SERIAL PRIMARY KEY,  
	tipo_permissao VARCHAR(100) NOT NULL  
);

-- Tabela 'titulo_usuario' define os títulos dos usuários.
CREATE TABLE titulo_usuario (
	id SERIAL PRIMARY KEY,  
	titulo VARCHAR(100) NOT NULL  
);

-- Tabela intermediária 'permissao_titulo_usuario' para relacionar permissões e títulos de usuários.
CREATE TABLE permissao_titulo_usuario (
	id SERIAL PRIMARY KEY,
	id_permissao INTEGER,
	id_titulo_usuario INTEGER,
	CONSTRAINT fk_permissao
		FOREIGN KEY (id_permissao) 
		REFERENCES permissao(id)
		ON DELETE CASCADE,
	CONSTRAINT fk_titulo_usuario
		FOREIGN KEY (id_titulo_usuario) 
		REFERENCES titulo_usuario(id)
		ON DELETE CASCADE
);

-- Tabela 'acesso' define as formas de acesso.
CREATE TABLE acesso (
	id SERIAL PRIMARY KEY,  
	forma_acesso VARCHAR(100) NOT NULL  
);

-- Tabela 'usuario' armazena informações sobre os usuários.
CREATE TABLE usuario (
	id SERIAL PRIMARY KEY,  
	nome VARCHAR(100) NOT NULL,  
	cpf VARCHAR(11) UNIQUE NOT NULL,  
	id_titulo_usuario INTEGER,
	CONSTRAINT fk_titulo_usuario
		FOREIGN KEY (id_titulo_usuario)
		REFERENCES titulo_usuario(id)
		ON DELETE CASCADE
);

-- Tabela intermediária 'acesso_usuario' relaciona acessos e usuários.
CREATE TABLE acesso_usuario (
	id SERIAL PRIMARY KEY,
	id_acesso INTEGER,
	id_usuario INTEGER,
    codigo_acesso VARCHAR NOT NULL,
	CONSTRAINT fk_acesso
		FOREIGN KEY (id_acesso) 
		REFERENCES acesso(id)
		ON DELETE CASCADE,
	CONSTRAINT fk_usuario
		FOREIGN KEY (id_usuario)
		REFERENCES usuario(id)
		ON DELETE CASCADE
);

-- Tabela 'atividade' define as atividades disponíveis.
CREATE TABLE atividade (
	id SERIAL PRIMARY KEY,  
	tipo_atividade VARCHAR(100) NOT NULL  
);

-- Tabela 'local' define os locais dos eventos.
CREATE TABLE local (
	id SERIAL PRIMARY KEY,  
	unidade VARCHAR(100),  
	andar INTEGER,
	sala VARCHAR(100)
);

-- Tabela 'evento' armazena os eventos realizados.
CREATE TABLE evento (
	id SERIAL PRIMARY KEY,  
	id_professor INTEGER,  
	id_atividade INTEGER,  
	id_local INTEGER,  
	data_evento DATE,  
	hora_inicio TIME,  
	hora_fim TIME,  
	evento_interno BOOLEAN,
	CONSTRAINT fk_professor
		FOREIGN KEY (id_professor) 
		REFERENCES usuario(id)
		ON DELETE SET NULL,
	CONSTRAINT fk_atividade
		FOREIGN KEY (id_atividade) 
		REFERENCES atividade(id)
		ON DELETE CASCADE,
	CONSTRAINT fk_local
		FOREIGN KEY (id_local) 
		REFERENCES local(id)
		ON DELETE SET NULL
);

-- Tabela intermediária 'usuario_atividade' relaciona usuários e atividades.
CREATE TABLE usuario_atividade (
	id SERIAL PRIMARY KEY,  
	id_usuario INTEGER,  
	id_atividade INTEGER,
	CONSTRAINT fk_usuario
		FOREIGN KEY (id_usuario) 
		REFERENCES usuario(id)
		ON DELETE CASCADE,
	CONSTRAINT fk_atividade
		FOREIGN KEY (id_atividade) 
		REFERENCES atividade(id)
		ON DELETE CASCADE
);	

-- Tabela 'visita' registra as visitas de usuários.
CREATE TABLE visita (
	id SERIAL PRIMARY KEY,  
	id_usuario INTEGER,  
	data_visita DATE,  
	hora_entrada_visita TIME,  
	hora_saida_visita TIME,
	CONSTRAINT fk_usuario_visita
		FOREIGN KEY (id_usuario) 
		REFERENCES usuario(id)
		ON DELETE CASCADE
);

-- Tabela 'frequencia' registra a frequência dos usuários nos eventos.
CREATE TABLE frequencia (
	id SERIAL PRIMARY KEY,  
	id_usuario INTEGER,  
	id_evento INTEGER,  
	hora_chegada TIME,  
	hora_saida TIME,  
	data DATE,
	CONSTRAINT fk_usuario_frequencia
		FOREIGN KEY (id_usuario) 
		REFERENCES usuario(id)
		ON DELETE CASCADE,
	CONSTRAINT fk_evento_frequencia
		FOREIGN KEY (id_evento) 
		REFERENCES evento(id)
		ON DELETE CASCADE
);