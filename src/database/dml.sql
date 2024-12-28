-- Inserindo permissões
INSERT INTO permissao (tipo_permissao) VALUES ('Permissao 1'), ('Permissao 2'), ('Permissao 3'), ('Permissao 4');

-- Inserindo títulos de usuários
INSERT INTO titulo_usuario (titulo) VALUES ('Professor'), ('Aluno'), ('Coordenador'), ('Visitante');

-- Relacionando permissões e títulos de usuários
INSERT INTO permissao_titulo_usuario (id_permissao, id_titulo_usuario) VALUES (1, 1), (2, 2), (3, 3), (4, 4);

-- Inserindo formas de acesso
INSERT INTO acesso (forma_acesso) VALUES ('Biometria'), ('Cartao'), ('Facial');

-- Inserindo usuários
INSERT INTO usuario (nome, cpf, id_titulo_usuario) VALUES ('João Silva', '12345678901', 1), ('Maria Santos', '23456789012', 2), ('Carlos Lima', '34567890123', 3), ('Pietra Albuquerque', '45678901234', 4);

-- Relacionando acessos e usuários
INSERT INTO acesso_usuario (id_acesso, id_usuario, codigo_acesso) VALUES (1, 1, 'wEIyzP'), (1, 2, 'VZbehK'), (1, 3, 'IZCcbf'), (2, 1, 'p0pHnk'), (2, 3, 'c1BUz6'), (3, 1, 'dci9y8'), (3, 2, 'ZyUlf9'), (3, 3, '8D9xPk'), (4, 2, 'YmAY1o');

-- Inserindo atividades
INSERT INTO atividade (tipo_atividade) VALUES ('Aula de Robotica'), ('Aula de Ingles'), ('Cinema');

-- Inserindo locais
INSERT INTO local (unidade, andar, sala) VALUES ('Unidade Santo Berco', 1, '101'), ('Unidade Santa Menefreda', 0, '14-B');

-- Inserindo eventos
INSERT INTO evento (id_professor, id_atividade, id_local, data_evento, hora_inicio, hora_fim, evento_interno) VALUES (1, 1, 1, '2024-11-20', '10:00', '12:00', TRUE), (1, 2, 2, '2024-11-25', '14:00', '16:00', true ), (1, 2, null, '2024-11-26', '13:30', '16:00', false);

-- Relacionando usuários e atividades
INSERT INTO usuario_atividade (id_usuario, id_atividade) VALUES (1, 1), (2, 2);

-- Inserindo visitas
INSERT INTO visita (id_usuario, data_visita, hora_entrada_visita, hora_saida_visita) VALUES (4, '2024-11-18', '09:00', '11:00');

-- Inserindo frequência
INSERT INTO frequencia (id_usuario, id_evento, hora_chegada, hora_saida, data) VALUES (1, 1, '10:05', '12:03', '2024-11-20');