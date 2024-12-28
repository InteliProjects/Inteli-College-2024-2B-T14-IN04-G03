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
    const { name, value, type, checked } = e.target;
    setFormData({
      ...formData,
      [name]: type === 'checkbox' ? checked : value,
    });
  };
  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const response = await fetch('https://two024-2b-t14-in04-g03.onrender.com/evento', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(formData),
      });
      if (!response.ok) {
        const errorData = await response.json();
        throw new Error(errorData.error || 'Erro ao registrar o evento.');
      }
      setSuccess('Evento registrado com sucesso!');
      setError(null);
      setFormData({
        id_professor: '',
        id_atividade: '',
        id_local: '',
        data_evento: '',
        hora_inicio: '',
        hora_fim: '',
        evento_interno: false,
      });
    } catch (err) {
      setSuccess(null);
      setError(err.message);
    }
  };
  return (
    <div className={styles['event-container']}>
      <div className={styles.card}>
        <h2>Cadastrar Evento</h2>
        <form onSubmit={handleSubmit}>
          <div className={styles['form-group']}>
            <label htmlFor="id_professor">ID Professor:</label>
            <input
              type="text"
              id="id_professor"
              name="id_professor"
              value={formData.id_professor}
              onChange={handleChange}
              required
            />
          </div>
          <div className={styles['form-group']}>
            <label htmlFor="id_atividade">ID Atividade:</label>
            <input
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
            <label htmlFor="hora_fim">Hora Fim:</label>
            <input
              type="time"
              id="hora_fim"
              name="hora_fim"
              value={formData.hora_fim}
              onChange={handleChange}
              required
            />
          </div>
          <div className={styles['form-group-checkbox']}>
            <input
              type="checkbox"
              id="evento_interno"
              name="evento_interno"
              checked={formData.evento_interno}
              onChange={handleChange}
            />
            <label htmlFor="evento_interno">Evento Interno</label>
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