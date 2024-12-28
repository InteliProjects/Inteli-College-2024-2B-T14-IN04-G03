-- Inserindo títulos de usuários
INSERT INTO titulo_usuario (titulo) VALUES ('Professor'), ('Aluno'), ('Coordenador'), ('Visitante');

-- Inserindo formas de acesso
INSERT INTO acesso (forma_acesso) VALUES ('Biometria'), ('Cartao'), ('Facial');

-- Inserindo usuários
INSERT INTO usuario (nome, cpf, id_titulo_usuario) VALUES ('João Silva', '12345678901', 1), ('Maria Santos', '23456789012', 2), ('Carlos Lima', '34567890123', 3), ('Pietra Albuquerque', '45678901234', 4);

-- Inserindo esp
INSErT INTO esp (id_esp) VALUES (1234), (2466), (3235), (4657), (5123), (6086), (7236);

-- Relacionando acessos e usuários
INSERT INTO acesso_usuario (id_acesso, id_usuario, id_esp) VALUES (1, 1, 1), (1, 2, 2), (1, 3, 3), (2, 1, 4), (2, 3, 5), (3, 1, 6), (3, 2, 7), (3, 3, '8D9xPk'), (4, 2, 'YmAY1o');

-- Inserindo frequência
INSERT INTO frequencia (id_usuario, horario, data) VALUES (1, '10:05', '2024-11-20'), (2, '10:07', '2024-11-20'), (3, '10:15', '2024-11-20');