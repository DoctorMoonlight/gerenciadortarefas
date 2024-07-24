#ifndef HISTORICO_H
#define HISTORICO_H

#include <vector>
#include "tarefa.h"

class Historico {
public:
    void adicionarTarefaConcluida(const Tarefa& tarefa);
    void exibirHistorico() const;

private:
    std::vector<Tarefa> tarefasConcluidas;};
#endif 
