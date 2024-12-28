import React, { useState, useEffect } from "react";
import './Dash.css';
import * as XLSX from 'xlsx';
import { FaFileExcel } from 'react-icons/fa';

function Dash() {
    const [usuarios, setUsuarios] = useState([]);
    const [loading, setLoading] = useState(true);
    const [frequencias, setFrequencias] = useState([]);
    const [filtroNome, setFiltroNome] = useState("");
    const [filtroCargo, setFiltroCargo] = useState("");
    const [filtroCPF, setFiltroCPF] = useState("");
    const [filtroData, setFiltroData] = useState("");
    const [filtroHorario, setFiltroHorario] = useState("");

    // Mapeamento de cargos
    const cargoMap = {
        1: "Professor",
        2: "Aluno",
        3: "Coordenador",
        4: "Visitante"
    };

    useEffect(() => {
        // Fazendo a requisição para a API de usuários
        fetch("https://two024-2b-t14-in04-g03.onrender.com/usuario/")
            .then((response) => {
                if (!response.ok) {
                    throw new Error("Erro ao buscar dados da API");
                }
                return response.json();
            })
            .then((data) => {
                console.log("Dados recebidos da API:", data);
                
                // Extraindo apenas o array de usuários, ignorando a mensagem
                const usuariosArray = Array.isArray(data) ? data : Object.values(data).filter(item => 
                    typeof item === 'object' && !Array.isArray(item) && item !== null
                );
                
                // Ordenando por ID
                const sortedData = usuariosArray.sort((a, b) => a.id - b.id);
                setUsuarios(sortedData);
                setLoading(false);
            })
            .catch((error) => {
                console.error("Erro:", error);
                setLoading(false);
            });

        // Chamada API para frequências
        fetch("https://two024-2b-t14-in04-g03.onrender.com/frequencia/listar")
            .then((response) => {
                if (!response.ok) {
                    throw new Error("Erro ao buscar dados de frequência");
                }
                return response.json();
            })
            .then((data) => {
                // Pegando diretamente o array de frequências
                const frequenciasArray = data.frequencias || [];
                setFrequencias(frequenciasArray);
            })
            .catch((error) => {
                console.error("Erro ao buscar frequências:", error);
                setFrequencias([]);
            });
    }, []);

    // Função de filtro atualizada para incluir data e horário
    const frequenciasFiltradas = frequencias.filter(frequencia => {
        const usuario = usuarios.find(u => u.id === frequencia.id_usuario);
        if (!usuario) return false;

        const matchNome = usuario.nome.toLowerCase().includes(filtroNome.toLowerCase());
        const matchCargo = filtroCargo === "" || usuario.id_titulo_usuario === parseInt(filtroCargo);
        const matchCPF = usuario.cpf.includes(filtroCPF);
        const matchData = filtroData === "" || frequencia.data.includes(filtroData);
        const matchHorario = filtroHorario === "" || frequencia.horario.includes(filtroHorario);

        return matchNome && matchCargo && matchCPF && matchData && matchHorario;
    });

    // Função atualizada para exportar XLSX
    const exportarXLSX = () => {
        // Prepara os dados para o Excel
        const dadosExcel = frequencias.map(frequencia => {
            const usuario = usuarios.find(u => u.id === frequencia.id_usuario);
            return {
                ID: frequencia.id,
                Data: frequencia.data,
                Horário: frequencia.horario,
                Nome: usuario ? usuario.nome : 'N/A',
                CPF: usuario ? usuario.cpf : 'N/A',
                Cargo: usuario ? cargoMap[usuario.id_titulo_usuario] : 'N/A'
            };
        });

        // Cria uma nova planilha
        const ws = XLSX.utils.json_to_sheet(dadosExcel);
        const wb = XLSX.utils.book_new();
        XLSX.utils.book_append_sheet(wb, ws, "Frequências");

        // Gera o arquivo e faz o download
        XLSX.writeFile(wb, "frequencias.xlsx");
    };

    return (
        <div className="dash-page">
            <div className="dash-sidebar">
                <h3>Filtros</h3>
                
                <div className="sidebar-filter">
                    <label>Data:</label>
                    <input 
                        type="date" 
                        value={filtroData}
                        onChange={(e) => setFiltroData(e.target.value)}
                    />
                </div>

                <div className="sidebar-filter">
                    <label>Horário:</label>
                    <input 
                        type="time" 
                        value={filtroHorario}
                        onChange={(e) => setFiltroHorario(e.target.value)}
                    />
                </div>

                <div className="sidebar-filter">
                    <label>Nome:</label>
                    <input 
                        type="text" 
                        placeholder="Filtrar por nome..."
                        value={filtroNome}
                        onChange={(e) => setFiltroNome(e.target.value)}
                    />
                </div>

                <div className="sidebar-filter">
                    <label>Cargo:</label>
                    <select 
                        value={filtroCargo} 
                        onChange={(e) => setFiltroCargo(e.target.value)}
                    >
                        <option value="">Todos</option>
                        <option value="1">Professor</option>
                        <option value="2">Aluno</option>
                        <option value="3">Coordenador</option>
                        <option value="4">Visitante</option>
                    </select>
                </div>
                
                <div className="sidebar-filter">
                    <label>CPF:</label>
                    <input 
                        type="text" 
                        placeholder="Filtrar por CPF..."
                        value={filtroCPF}
                        onChange={(e) => setFiltroCPF(e.target.value)}
                    />
                </div>
            </div>

            <div className="dash-container">
                <h2 className="dash-title">Registro de Frequências</h2>
                
                <button 
                    className="export-button" 
                    onClick={exportarXLSX}
                    title="Exportar para Excel"
                >
                    <FaFileExcel size={24} />
                </button>

                {loading ? (
                    <p className="dash-loading">Carregando dados...</p>
                ) : frequenciasFiltradas.length > 0 ? (
                    <div className="dash-table-container">
                        <table className="dash-table">
                            <thead>
                                <tr>
                                    <th>ID</th>
                                    <th>Data</th>
                                    <th>Horário</th>
                                    <th>Nome do Usuário</th>
                                    <th>CPF</th>
                                    <th>Cargo</th>
                                </tr>
                            </thead>
                            <tbody>
                                {frequenciasFiltradas.map((frequencia) => {
                                    const usuario = usuarios.find(u => u.id === frequencia.id_usuario);
                                    return (
                                        <tr key={frequencia.id}>
                                            <td>{frequencia.id}</td>
                                            <td>{frequencia.data}</td>
                                            <td>{frequencia.horario}</td>
                                            <td>{usuario ? usuario.nome : 'Usuário não encontrado'}</td>
                                            <td>{usuario ? usuario.cpf : 'N/A'}</td>
                                            <td>{usuario ? cargoMap[usuario.id_titulo_usuario] : 'N/A'}</td>
                                        </tr>
                                    );
                                })}
                            </tbody>
                        </table>
                    </div>
                ) : (
                    <p className="dash-no-data">Nenhum registro de frequência encontrado.</p>
                )}
            </div>
        </div>
    );
}

export default Dash;