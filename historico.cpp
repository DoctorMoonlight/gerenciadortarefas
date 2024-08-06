#include "historico.h"
#include <iostream>

using namespace std;

// Adiciona uma tarefa concluída ao histórico
void Historico::adicionarTarefaConcluida(const Tarefa& tarefa) 
{
    tarefasConcluidas.push_back(tarefa);
}

// Exibe o histórico das tarefas concluídas
void Historico::exibirHistorico() const 
{
    // Se o vetor de tarefas concluídas estiver não estiver vazio, exibe a lista na tela
    if(!tarefasConcluidas.empty())
    {
        cout << "\nAs tarefas concluídas são:\n";
        for (const auto& tarefa : tarefasConcluidas) 
        {
            cout << "Tarefa: " << tarefa.getDescricao() << ", Data: " << tarefa.getData() << ", Horário: " << tarefa.getHorario() << endl << endl;
        }
    }

    // Se não, exibe uma mensagem informando que não há tarefas concluídas
    else
    {
        cout << "\nNão há nenhuma tarefa concluída a ser exibida.\n\n";
    }
}
