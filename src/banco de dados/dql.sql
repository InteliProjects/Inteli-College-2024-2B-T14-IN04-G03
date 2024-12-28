-- 1. Consultar todos os usuários com seus respectivos títulos
SELECT 
    u.id AS id_usuario,
    u.nome,
    u.cpf,
    tu.titulo AS titulo_usuario
FROM 
    usuario u
LEFT JOIN 
    titulo_usuario tu
ON 
    u.id_titulo_usuario = tu.id;

-- 2. Consultar todas as formas de acesso relacionadas aos usuários
SELECT 
    au.id AS id_acesso_usuario,
    a.forma_acesso,
    u.nome AS nome_usuario,
    e.id_esp AS id_espaco
FROM 
    acesso_usuario au
JOIN 
    acesso a ON au.id_acesso = a.id
JOIN 
    usuario u ON au.id_usuario = u.id
JOIN 
    esp e ON au.id_esp = e.id;

-- 3. Consultar a frequência dos usuários nos eventos
SELECT 
    f.id AS id_frequencia,
    u.nome AS nome_usuario,
    f.horario,
    f.hora_saida,
    f.data
FROM 
    frequencia f
JOIN 
    usuario u ON f.id_usuario = u.id;

-- 4. Contar a frequência de cada usuário
SELECT 
    u.nome AS nome_usuario,
    COUNT(f.id) AS total_frequencia
FROM 
    frequencia f
JOIN 
    usuario u ON f.id_usuario = u.id
GROUP BY 
    u.nome;

-- 5. Consultar quais usuários têm acesso a um determinado espaço (por ID)
SELECT 
    u.nome AS nome_usuario,
    e.id_esp AS id_espaco,
    a.forma_acesso
FROM 
    acesso_usuario au
JOIN 
    usuario u ON au.id_usuario = u.id
JOIN 
    esp e ON au.id_esp = e.id
JOIN 
    acesso a ON au.id_acesso = a.id
WHERE 
    e.id_esp = 1234; -- Substitua pelo ID do espaço desejado

-- 6. Listar todos os acessos feitos por usuários em uma data específica
SELECT 
    u.nome AS nome_usuario,
    a.forma_acesso,
    f.data,
    f.horario
FROM 
    frequencia f
JOIN 
    usuario u ON f.id_usuario = u.id
JOIN 
    acesso_usuario au ON au.id_usuario = u.id
JOIN 
    acesso a ON au.id_acesso = a.id
WHERE 
    f.data = '2024-11-20'; -- Substitua pela data desejada
