import React, { useState, useEffect } from "react";
import { FaEdit, FaTrash } from "react-icons/fa";
import './Gerenciar.css';

function Gerenciar() {
    const [usuarios, setUsuarios] = useState([]);
    const [loading, setLoading] = useState(true);
    const [editUsuario, setEditUsuario] = useState(null); // Estado para o popup de edição
    const [deleteUsuario, setDeleteUsuario] = useState(null); // Estado para o popup de exclusão
    const [message, setMessage] = useState(null); // Feedback para o usuário
    const [filtroNome, setFiltroNome] = useState(""); // Novo estado para o filtro

    // Mapeamento de cargos
    const cargoMap = {
        1: "Professor",
        2: "Aluno",
        3: "Coordenador",
        4: "Visitante"
    };

    useEffect(() => {
        fetchUsuarios();
    }, []);

    const fetchUsuarios = () => {
        setLoading(true);
        fetch("https://two024-2b-t14-in04-g03.onrender.com/usuario/")
            .then((response) => {
                if (!response.ok) {
                    throw new Error("Erro ao buscar dados da API");
                }
                return response.json();
            })
            .then((data) => {
                const sortedData = data.sort((a, b) => a.id - b.id); // Ordena os usuários por ID
                setUsuarios(sortedData);
                setLoading(false);
            })
            .catch((error) => {
                console.error("Erro:", error);
                setLoading(false);
            });
    };

    const handleEdit = (usuario) => {
        setEditUsuario({ ...usuario }); // Preenche os dados do usuário no popup
    };

    const handleEditConfirm = () => {
        fetch(`https://two024-2b-t14-in04-g03.onrender.com/usuario/atualizar`, {
            method: "PUT",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({
                nome: editUsuario.nome,
                cpf: editUsuario.cpf,
                id_titulo_usuario: editUsuario.id_titulo_usuario,
            }),
        })
            .then((response) => response.json())
            .then((data) => {
                if (data.error) {
                    throw new Error(data.error);
                }
                fetchUsuarios(); // Recarrega a lista de usuários
                setEditUsuario(null);
                setMessage("Usuário atualizado com sucesso!");
            })
            .catch((error) => {
                console.error("Erro ao atualizar usuário:", error);
                setMessage("Erro ao atualizar o usuário: " + error.message);
            });
    };

    const handleDelete = (usuario) => {
        setDeleteUsuario(usuario); // Define o usuário para excluir
    };

    const handleDeleteConfirm = () => {
        fetch(`https://two024-2b-t14-in04-g03.onrender.com/usuario/deletar/${deleteUsuario.cpf}`, {
            method: "DELETE",
        })
            .then((response) => response.json())
            .then((data) => {
                if (data.error) {
                    throw new Error(data.error);
                }
                fetchUsuarios(); // Recarrega a lista de usuários
                setDeleteUsuario(null);
                setMessage("Usuário excluído com sucesso!");
            })
            .catch((error) => {
                console.error("Erro ao excluir usuário:", error);
                setMessage("Erro ao excluir o usuário: " + error.message);
            });
    };

    const usuariosFiltrados = usuarios.filter(usuario =>
        usuario.nome.toLowerCase().includes(filtroNome.toLowerCase())
    );

    return (
        <div className="gerenciar-container">
            <h2 className="gerenciar-title">Gerenciar Usuários</h2>
            {message && <p className="gerenciar-message">{message}</p>}
            {!loading && usuarios.length > 0 && (
                <div className="gerenciar-filter">
                    <input 
                        type="text" 
                        className="gerenciar-filter-input" 
                        placeholder="Digite o nome para filtrar..." 
                        value={filtroNome} 
                        onChange={(e) => setFiltroNome(e.target.value)} 
                    />
                </div>
            )}
            {loading ? (
                <p className="gerenciar-loading">Carregando dados...</p>
            ) : usuarios.length > 0 ? (
                <div className="gerenciar-table-container">
                    <table className="gerenciar-table">
                        <thead>
                            <tr>
                                <th>ID</th>
                                <th>Nome</th>
                                <th>CPF</th>
                                <th>Cargo</th>
                                <th>Ações</th>
                            </tr>
                        </thead>
                        <tbody>
                            {usuariosFiltrados.map((usuario) => (
                                <tr key={usuario.id}>
                                    <td>{usuario.id}</td>
                                    <td>{usuario.nome}</td>
                                    <td>{usuario.cpf}</td>
                                    <td>{cargoMap[usuario.id_titulo_usuario] || "Desconhecido"}</td>
                                    <td>
                                        <button
                                            className="gerenciar-btn-edit"
                                            onClick={() => handleEdit(usuario)}
                                        >
                                            <FaEdit />
                                        </button>
                                        <button
                                            className="gerenciar-btn-delete"
                                            onClick={() => handleDelete(usuario)}
                                        >
                                            <FaTrash />
                                        </button>
                                    </td>
                                </tr>
                            ))}
                        </tbody>
                    </table>
                </div>
            ) : (
                <p className="gerenciar-no-data">Nenhum dado encontrado.</p>
            )}

            {/* Popup de Edição */}
            {editUsuario && (
                <div className="popup">
                    <div className="popup-content">
                        <h3>Editar Usuário</h3>
                        <label>Nome:</label>
                        <input
                            type="text"
                            value={editUsuario.nome}
                            onChange={(e) =>
                                setEditUsuario({ ...editUsuario, nome: e.target.value })
                            }
                        />
                        <label>CPF:</label>
                        <input
                            type="text"
                            value={editUsuario.cpf}
                            onChange={(e) =>
                                setEditUsuario({ ...editUsuario, cpf: e.target.value })
                            }
                        />
                        <label>Cargo:</label>
                        <select
                            value={editUsuario.id_titulo_usuario}
                            onChange={(e) =>
                                setEditUsuario({
                                    ...editUsuario,
                                    id_titulo_usuario: parseInt(e.target.value),
                                })
                            }
                        >
                            {Object.entries(cargoMap).map(([id, cargo]) => (
                                <option key={id} value={id}>
                                    {cargo}
                                </option>
                            ))}
                        </select>
                        <button className="popup-confirm" onClick={handleEditConfirm}>
                            Confirmar
                        </button>
                        <button className="popup-cancel" onClick={() => setEditUsuario(null)}>
                            Cancelar
                        </button>
                    </div>
                </div>
            )}

            {/* Popup de Exclusão */}
            {deleteUsuario && (
                <div className="popup">
                    <div className="popup-content">
                        <h3>Excluir Usuário</h3>
                        <p>Tem certeza que deseja excluir o usuário {deleteUsuario.nome}?</p>
                        <button className="popup-confirm" onClick={handleDeleteConfirm}>
                            Sim
                        </button>
                        <button className="popup-cancel" onClick={() => setDeleteUsuario(null)}>
                            Não
                        </button>
                    </div>
                </div>
            )}
        </div>
    );
}

export default Gerenciar;