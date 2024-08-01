#include "historico.h"  
#include <iostream> 
using namespace std; 

// Adiciona uma tarefa concluída ao histórico  
void Historico::adicionarTarefaConcluida(const Tarefa& tarefa) {  
    tarefasConcluidas.push_back(tarefa); 
}  

// Exibe o histórico das tarefas concluídas  
void Historico::exibirHistorico() const {  
    for (const auto& tarefa : tarefasConcluidas) {  
        cout << "Tarefa: " << tarefa.getDescricao() << ", Data: " << tarefa.getData() << ", Horário: " << tarefa.getHorario() << endl;  
    }  
} 
