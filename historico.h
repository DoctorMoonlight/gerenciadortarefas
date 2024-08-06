#ifndef HISTORICO_H
#define HISTORICO_H

#include "tarefa.h"
#include <vector>

using namespace std;

//Inicialização da classe historico
class Historico 
{
public:
    //Adiciona uma tarefa concluída ao histórico
    void adicionarTarefaConcluida(const Tarefa& tarefa); 
    //Exibe o histórico das tarefas concluídas
    void exibirHistorico() const; 

private:
    //Vetor privado que armazena as tarefas concluídas
    vector<Tarefa> tarefasConcluidas; 

friend class TEST_CASE;
};
#endif 
