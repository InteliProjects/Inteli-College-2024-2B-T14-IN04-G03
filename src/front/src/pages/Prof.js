import '../App.css';
import { FaChartLine, FaCalendarDay } from 'react-icons/fa'; // Ícones
import { useNavigate } from 'react-router-dom';

function Home() {
  const navigate = useNavigate();
  
  return (
    <div className="container">
      <div className="row">
        <div className="card" onClick={() => navigate('/dash')} style={{ cursor: 'pointer' }}>
          <FaChartLine size={60} className="iconuser" />
          <p className="cardtext">Relatórios & Dashboards</p>
        </div>

        <div className="card" onClick={() => navigate('/eventos')} style={{ cursor: 'pointer' }}>
          <FaCalendarDay size={60} className="iconuser" />
          <p className="cardtext">Registro de Eventos</p>
        </div>
      </div>
    </div>
  );
}

export default Home;