-- Listar todos os usuários e seus títulos
SELECT u.nome, t.titulo 
FROM usuario u
JOIN titulo_usuario t ON u.id_titulo_usuario = t.id;

-- Consultar eventos e os professores responsáveis
SELECT e.data_evento, e.hora_inicio, e.hora_fim, u.nome AS professor
FROM evento e
LEFT JOIN usuario u ON e.id_professor = u.id;

-- Listar atividades realizadas por usuários
SELECT u.nome, a.tipo_atividade 
FROM usuario_atividade ua
JOIN usuario u ON ua.id_usuario = u.id
JOIN atividade a ON ua.id_atividade = a.id;

-- Consultar frequência em eventos com título dos usuários
SELECT u.nome, t.titulo AS titulo_usuario, e.data_evento, f.hora_chegada, f.hora_saida 
FROM frequencia f
JOIN usuario u ON f.id_usuario = u.id
JOIN titulo_usuario t ON u.id_titulo_usuario = t.id
JOIN evento e ON f.id_evento = e.id;


-- Consultar visitas realizadas por usuários
SELECT u.nome, v.data_visita, v.hora_entrada_visita, v.hora_saida_visita
FROM visita v
JOIN usuario u ON v.id_usuario = u.id;