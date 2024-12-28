import React, { useState } from 'react';
import styles from './Eventos.module.css'; // Importe seu CSS Module adequado

function Eventos() {
  const [formData, setFormData] = useState({
    id_professor: '',
    id_atividade: '',
    id_local: '',
    data_evento: '',
    hora_inicio: '',
    hora_fim: '',
    evento_interno: false,
  });

  const [error, setError] = useState(null);
  const [success, setSuccess] = useState(null);

  const handleChange = (e) => {
    const { name, value } = e.target;

    if (name === 'cpf') {
      // Permitir apenas números e limitar a 11 caracteres
      const onlyNumbers = value.replace(/\D/g, '');
      if (onlyNumbers.length <= 11) {
        setFormData({ ...formData, [name]: onlyNumbers });
      }
    } else if (name === 'nome') {
      // Permitir apenas letras (acentos e espaços inclusos)
      const onlyLetters = value.replace(/[^a-zA-ZáàâãäéèêëíìîïóòôõöúùûüçÇÁÀÂÃÄÉÈÊËÍÌÎÏÓÒÔÕÖÚÙÛÜ\s]/g, '');
      setFormData({ ...formData, [name]: onlyLetters });
    } else {
      setFormData({ ...formData, [name]: value });
    }
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    // Log para verificar os dados antes de enviar
    console.log('Dados enviados:', {
      nome: formData.nome,
      cpf: formData.cpf,
      id_titulo_usuario: parseInt(formData.titulo),
    });

    try {
      const response = await fetch('https://two024-2b-t14-in04-g03.onrender.com/usuario/cadastro', {

        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          nome: formData.nome,
          cpf: formData.cpf,
          id_titulo_usuario: parseInt(formData.titulo),
        }),
        body: JSON.stringify(formData),
      });

      if (!response.ok) {
        const errorData = await response.json();
        throw new Error(errorData.error || 'Erro ao registrar o evento.');
      }

      const responseData = await response.json();
      console.log('Resposta da API:', responseData);

      setSuccess(`Usuário ${formData.nome} adicionado com sucesso!`);
      setError(null); // Limpa erros
      setFormData({ nome: '', cpf: '', titulo: '1' }); // Reseta o formulário
    } catch (err) {
      console.error('Erro na submissão:', err.message);
      setSuccess(null); // Limpa mensagens de sucesso
      setError(err.message);
    }
  };

  return (
    <div className={styles['event-container']}>
      <div className={styles.card}>
        <h2 className={styles.title}>Adicionar Usuário</h2>
        <form onSubmit={handleSubmit}>
          <div className={styles['form-group']}>
            <label className={styles.label} htmlFor="nome">Nome:</label>
            <input
              className={styles.input}
              type="text"
              id="nome"
              name="nome"
              value={formData.nome}
              onChange={handleChange}
              required
            />
          </div>
          <div className={styles['form-group']}>
            <label className={styles.label} htmlFor="cpf">CPF:</label>
            <input
              className={styles.input}
              type="text"
              id="id_atividade"
              name="id_atividade"
              value={formData.id_atividade}
              onChange={handleChange}
              required
            />
          </div>
          <div className={styles['form-group']}>
            <label htmlFor="id_local">ID Local:</label>
            <input
              type="text"
              id="id_local"
              name="id_local"
              value={formData.id_local}
              onChange={handleChange}
              required
            />
          </div>
          <div className={styles['form-group']}>
            <label htmlFor="data_evento">Data do Evento:</label>
            <input
              type="date"
              id="data_evento"
              name="data_evento"
              value={formData.data_evento}
              onChange={handleChange}
              required
            />
          </div>
          <div className={styles['form-group']}>
            <label htmlFor="hora_inicio">Hora Início:</label>
            <input
              type="time"
              id="hora_inicio"
              name="hora_inicio"
              value={formData.hora_inicio}
              onChange={handleChange}
              required
            />
          </div>
          <div className={styles['form-group']}>
            <label className={styles.label} htmlFor="titulo">Título:</label>
            <select
              className={styles.select}
              id="titulo"
              name="titulo"
              value={formData.titulo}
              onChange={handleChange}
            >
              <option value="1">Professor</option>
              <option value="2">Aluno</option>
              <option value="3">Coordenador</option>
              <option value="4">Visitante</option>
            </select>
          </div>
          <button className={styles.buttonEvent} type="submit">
            Cadastrar Evento
          </button>
        </form>

        {success && <p className={styles.success}>{success}</p>}
        {error && <p className={styles.error}>{error}</p>}
      </div>
    </div>
  );
}

export default Eventos;
