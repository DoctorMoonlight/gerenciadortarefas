#include "gerenciador_de_tarefa.h"
#include <iostream>
#include <algorithm>

// Método para adicionar uma nova tarefa
void GerenciadorDeTarefas::adicionarTarefa(const Tarefa& tarefa) {
    tarefas.push_back(tarefa);
}

// Método para eliminar uma tarefa baseada na descrição
void GerenciadorDeTarefas::eliminarTarefa(const std::string& descricao) {
    tarefas.erase(
        std::remove_if(tarefas.begin(), tarefas.end(), [&descricao](const Tarefa& tarefa) {
            return tarefa.getDescricao() == descricao;
        }),
        tarefas.end());
}

// Método para editar uma tarefa existente
void GerenciadorDeTarefas::editarTarefa(const std::string& descricao, const Tarefa& tarefaAtualizada) {
    for (auto& tarefa : tarefas) {
        if (tarefa.getDescricao() == descricao) {
            tarefa = tarefaAtualizada;
            break;
        }
    }
}

// Método para ordenar taredas por prioridade
void GerenciadorDeTarefas::ordenarPorPrioridade() {
    std::sort(tarefas.begin(), tarefas.end(), [](const Tarefa& a, const Tarefa& b) {
        return a.getEtiqueta().getPrioridade() > b.getEtiqueta().getPrioridade();
    });
}

// Método para exibir todas as tarefas
void GerenciadorDeTarefas::exibirTarefas() const {
    // Primeiro, ordena as tarefas por prioridade
    std::vector<Tarefa> tarefasOrdenadas = tarefas;
    std::sort(tarefasOrdenadas.begin(), tarefasOrdenadas.end(), [](const Tarefa& a, const Tarefa& b) {
        return a.getEtiqueta().getPrioridade() > b.getEtiqueta().getPrioridade();
    });

    // Em seguida, exibe as tarefas ordenadas
    for (const auto& tarefa : tarefasOrdenadas) {
        std::cout << "Tarefa: " << tarefa.getDescricao() 
                  << ", Data: " << tarefa.getData() 
                  << ", Horário: " << tarefa.getHorario() 
                  << ", Prioridade: " << tarefa.getEtiqueta().getPrioridade() << std::endl;
    }
}
// Método para marcar uma tarefa como concluída
void GerenciadorDeTarefas::marcarComoConcluida(const std::string& descricao) {
    for (auto& tarefa : tarefas) {
        if (tarefa.getDescricao() == descricao) {
            tarefa.setStatus(true);
            historico.adicionarTarefaConcluida(tarefa);
            break;
        }
    }
}

// Método para gerenciar etiquetas de uma tarefa específica
void GerenciadorDeTarefas::gerenciarEtiquetas(const std::string& descricao, const Etiqueta& etiqueta) {
    for (auto& tarefa : tarefas) {
        if (tarefa.getDescricao() == descricao) {
            tarefa.setEtiqueta(etiqueta);
            break;
        }
    }
}
// Método para exibir o histórico de tarefas
void GerenciadorDeTarefas::exibirHistorico() const {
    historico.exibirHistorico();
}

}
