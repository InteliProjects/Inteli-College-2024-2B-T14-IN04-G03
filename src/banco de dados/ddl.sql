-- Tabela 'titulo_usuario' define os títulos dos usuários.
CREATE TABLE titulo_usuario (
	id SERIAL PRIMARY KEY,  
	titulo VARCHAR(100) NOT NULL  
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

CREATE TABLE esp (
	id SERIAL PRIMARY KEY,
	id_esp INTEGER NOT NULL
);

-- Tabela intermediária 'acesso_usuario' relaciona acessos e usuários.
CREATE TABLE acesso_usuario (
	id SERIAL PRIMARY KEY,
	id_acesso INTEGER,
	id_usuario INTEGER,
	id_espaco INTEGER,
	CONSTRAINT fk_acesso
		FOREIGN KEY (id_acesso) 
		REFERENCES acesso(id)
		ON DELETE CASCADE,
	CONSTRAINT fk_usuario
		FOREIGN KEY (id_usuario)
		REFERENCES usuario(id)
		ON DELETE CASCADE,
	CONSTRAINT fk_id_esp
		FOREIGN KEY (id_esp)
		REFERENCES esp(id)
		ON DELETE CASCADE
);

-- Tabela 'frequencia' registra a frequência dos usuários nos eventos.
CREATE TABLE frequencia (
	id SERIAL PRIMARY KEY,  
	id_usuario INTEGER,   
	horario TIME,  
	hora_saida TIME,  
	data DATE,
	CONSTRAINT fk_usuario_frequencia
		FOREIGN KEY (id_usuario) 
		REFERENCES usuario(id)
		ON DELETE CASCADE,
);