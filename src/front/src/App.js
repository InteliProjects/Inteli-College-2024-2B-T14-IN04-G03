import React, { useState, useEffect } from 'react';
import './App.css';
import { BrowserRouter as Router, Routes, Route, useNavigate } from 'react-router-dom';
import About from './pages/About';
import Home from './pages/Home';
import Eventos from './pages/Eventos';
import Dash from './pages/Dash';
import Gerenciar from './pages/Gerenciar';
import Prof from './pages/Prof';
import { FaHome } from 'react-icons/fa';


function App() {
  const [isAuthenticated, setIsAuthenticated] = useState(false);
  const [userRole, setUserRole] = useState('');

  const handleLogin = (role) => {
    setIsAuthenticated(true);
    setUserRole(role);
  };

  return (
    <Router>
      <div className="App">
        {!isAuthenticated ? (
          <Login onLogin={handleLogin} />
        ) : (
          <>
            <Navbar userRole={userRole} />
            <Routes>
              <Route path="/home" element={<Home />} />
              <Route path="/about" element={<About />} />
              <Route path="/eventos" element={<Eventos />} />
              <Route path="/dash" element={<Dash />} />
              <Route path="/gerenciar" element={<Gerenciar />} />
              <Route path="/prof" element={<Prof />} />
            </Routes>
          </>
        )}
      </div>
    </Router>
  );
}

function Navbar({ userRole }) {
  const navigate = useNavigate();

  const handleHomeClick = () => {
    if (userRole === 'coordenador') {
      navigate('/home');
    } else if (userRole === 'professor') {
      navigate('/prof');
    }
  };

  return (
    <nav className="navbar">
      <div className="navbar-logo">
        <img src="apontar.png" alt="Logo" className="logo" />
      </div>
      <ul className="navbar-links">
        <li>
          <button onClick={handleHomeClick} className="icon-button">
            <FaHome size={30} />
          </button>
        </li>
        <li><Link to="/">Home</Link></li>
        <li><Link to="/about">Sobre Nós</Link></li>
        <li><Link to="/Eventos">Contato</Link></li>
      </ul>
    </nav>
  );
}

function Login({ onLogin }) {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const navigate = useNavigate();

  useEffect(() => {
    // Sempre redireciona para a rota raiz '/' ao carregar a página
    navigate('/');
  }, [navigate]);

  const handleSubmit = (e) => {
    e.preventDefault();
    if (username.toLowerCase() === 'coordenador' && password === '12345') {
      onLogin('coordenador');
      navigate('/home');
    } else if (username.toLowerCase() === 'professor' && password === '12345') {
      onLogin('professor');
      navigate('/prof');
    } else {
      alert('Usuário ou senha incorretos!');
    }
  };

  return (
    <div className="login-background">
      <div className="login-card">
        <img src="apontar.png" alt="Login Visual" className="login-image" />
        <form onSubmit={handleSubmit}>
          <div className="form-group">
            <label>Usuário:</label>
            <input 
              type="text" 
              placeholder="Digite seu usuário" 
              value={username} 
              onChange={(e) => setUsername(e.target.value)} 
              required 
            />
          </div>
          <div className="form-group">
            <label>Senha:</label>
            <input 
              type="password" 
              placeholder="Digite sua senha" 
              value={password} 
              onChange={(e) => setPassword(e.target.value)} 
              required 
            />
          </div>
          <button className="button" type="submit">Entrar</button>
        </form>
      </div>
    </div>
  );
}

export default App;
