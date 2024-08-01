#include "tarefa.h" 
 
using namespace std;
 
// Construtor que inicializa a tarefa com descrição, data, horário, etiqueta e notificação. 
Tarefa::Tarefa(const string& descricao, const string& data, const string& horario, const Etiqueta& etiqueta, const Notificacao& notificacao) 
    : descricao(descricao), data(data), horario(horario), etiqueta(etiqueta), concluida(false), notificacao(notificacao) { 
} 
 
// Define a descrição da tarefa. 
void Tarefa::setDescricao(const string& descricao) { 
    this->descricao = descricao; 
} 
 
// Retorna a descrição da tarefa. 
string Tarefa::getDescricao() const { 
    return descricao; 
} 
 
// Define a data da tarefa. 
void Tarefa::setData(const string& data) { 
    this->data = data; 
} 
 
// Retorna a data da tarefa. 
string Tarefa::getData() const { 
    return data; 
} 
 
// Define o horário da tarefa. 
void Tarefa::setHorario(const string& horario) { 
    this->horario = horario; 
} 
 
// Retorna o horário da tarefa. 
string Tarefa::getHorario() const { 
    return horario; 
} 
 
// Define a etiqueta da tarefa. 
void Tarefa::setEtiqueta(const Etiqueta& etiqueta) { 
    this->etiqueta = etiqueta; 
} 
 
// Retorna a etiqueta da tarefa. 
Etiqueta Tarefa::getEtiqueta() const { 
    return etiqueta; 
} 
 
// Define o status de conclusão da tarefa. 
void Tarefa::setStatus(bool concluida) { 
    this->concluida = concluida; 
} 
 
// Retorna se a tarefa está concluída. 
bool Tarefa::isConcluida() const { 
    return concluida; 
} 
 
// Define a notificação da tarefa. 
void Tarefa::setNotificacao(const Notificacao& notificacao) { 
    this->notificacao = notificacao; 
} 
 
// Retorna a notificação da tarefa. 
Notificacao Tarefa::getNotificacao() const { 
    return notificacao; 
}
