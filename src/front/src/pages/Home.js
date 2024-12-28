import '../App.css';
import { FaUserPlus, FaChartLine, FaCalendarDay, FaUsers } from 'react-icons/fa'; // Ícones
import { BrowserRouter as Router, Routes, Route, useNavigate, Link } from 'react-router-dom';



function Home() {
    const navigate = useNavigate();
  
    return (
      <div className="container">
        <div className="row">
          <div className="card" onClick={() => navigate('/about')} style={{ cursor: 'pointer' }}>
            <FaUserPlus size={60} className="iconuser" />
            <p className="cardtext">Adicionar Usuários</p>
          </div>
          <div className="card" onClick={() => navigate('/dash')} style={{ cursor: 'pointer' }}>
            <FaChartLine size={60} className="iconuser" />
            <p className="cardtext">Relatórios & Dashboards</p>
          </div>
        </div>
        <div className="row">
          <div className="card"  onClick={() => navigate('/eventos')} style={{ cursor: 'pointer' }}>
            <FaCalendarDay size={60} className="iconuser"  />
            <p className="cardtext">Registro de Eventos</p>
          </div>
          <div className="card" onClick={() => navigate('/gerenciar')} style={{ cursor: 'pointer' }}>
            <FaUsers size={60} className="iconuser" />
            <p className="cardtext">Gerenciar Usuários</p>
          </div>
        </div>
      </div>
    );
  }

export default Home;