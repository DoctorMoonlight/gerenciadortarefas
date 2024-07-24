#ifndef TAREFA_H
#define TAREFA_H

#include <string> // Biblioteca padrão para utilização de strings
#include <vector> // Biblioteca padrão para utilização de vetores
#include "etiqueta.h"  // Inclusão do cabeçalho da classe etiqueta
#include "notificacao.h" // Inclusão do cabeçalho da classe notificação

using namespace std;

// Classe que representa uma Tarefa, contendo descrição, data, horário, etiqueta, status de conclusão e notificação.
class Tarefa {
public:
    Tarefa(const string& descricao, const string& data, const string& horario); // Construtor que inicializa a tarefa com descrição, data e horário.
    void setDescricao(const string& descricao); // Define a descrição da tarefa.
    string getDescricao() const;  // Retorna a descrição da tarefa.
    void setData(const string& data); // Define a data da tarefa.
    string getData() const; // Retorna a data da tarefa.
    void setHorario(const string& horario);  // Define o horário da tarefa.
    string getHorario() const; // Retorna o horário da tarefa.
    void setEtiqueta(const Etiqueta& etiqueta);  // Define a etiqueta da tarefa.
    Etiqueta getEtiqueta() const; // Retorna a etiqueta da tarefa.
    void setStatus(bool concluida); // Define o status de conclusão da tarefa.
    bool isConcluida() const; // Retorna se a tarefa está concluída.
    void setNotificacao(const Notificacao& notificacao); // Define a notificação da tarefa.
    Notificacao getNotificacao() const; // Retorna a notificação da tarefa.

private:
    string descricao;
    string data;
    string horario;
    Etiqueta etiqueta;
    bool concluida;
    Notificacao notificacao;
};

#endif 
