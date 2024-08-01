#ifndef HISTORICO_H
#define HISTORICO_H

#include "tarefa.h" // Inclui o arquivo de cabeçalho pra definir a classe Tarefa
#include <vector> // Inclui a biblioteca padrão vector do C++

using namespace std; // Adiciona o namespace std

// Inicialização da classe Historico
class Historico {
public:
    void adicionarTarefaConcluida(const Tarefa& tarefa); // Adiciona uma tarefa concluída ao histórico
    void exibirHistorico() const; // Exibe o histórico das tarefas concluídas

private:
    vector<Tarefa> tarefasConcluidas; // Vetor privado que armazena as tarefas concluídas
};

#endif // Encerra a prevenção de inclusão múltipla
