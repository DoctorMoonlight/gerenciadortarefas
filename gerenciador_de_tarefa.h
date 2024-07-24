#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <vector>
#include "tarefa.h"
#include "notificacao.h"
#include "etiqueta.h"
#include "historico.h"

class GerenciadorDeTarefas {
public:
    void adicionarTarefa(const Tarefa& tarefa);
    void eliminarTarefa(const std::string& descricao);
    void editarTarefa(const std::string& descricao, const Tarefa& tarefaAtualizada);
    void exibirTarefas() const;
    void marcarComoConcluida(const std::string& descricao);
    void gerenciarEtiquetas(const std::string& descricao, const Etiqueta& etiqueta);
    void exibirHistorico() const;

private:
    std::vector<Tarefa> tarefas;
    Historico historico;
};

#endif
