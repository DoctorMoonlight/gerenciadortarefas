#include "gerenciador_de_tarefa.h"
#include <iostream>
#include <algorithm>
using namespace std;
// Método para adicionar uma nova tarefa
void GerenciadorDeTarefas::adicionarTarefa(const Tarefa& tarefa) {
 tarefas.push_back(tarefa);
}
// Método para eliminar uma tarefa baseada na descrição
void GerenciadorDeTarefas::eliminarTarefa(const string& descricao) {
 tarefas.erase(
 remove_if(tarefas.begin(), tarefas.end(), [&descricao](const Tarefa& tarefa) {
 return tarefa.getDescricao() == descricao;
 }),
 tarefas.end());
}
// Método para editar uma tarefa existente
void GerenciadorDeTarefas::editarTarefa(const string& descricao, const Tarefa&
tarefaAtualizada) {
 for (auto& tarefa : tarefas) {
 if (tarefa.getDescricao() == descricao) {
 tarefa = tarefaAtualizada;
 break;
 }
 }
}
// Método para ordenar taredas por prioridade
void GerenciadorDeTarefas::ordenarPorPrioridade() {
 sort(tarefas.begin(), tarefas.end(), [](const Tarefa& a, const Tarefa& b) {
 return a.getEtiqueta().getPrioridade() > b.getEtiqueta().getPrioridade();
 });
}
// Método para exibir todas as tarefas
void GerenciadorDeTarefas::exibirTarefas() const {
 // Primeiro, ordena as tarefas por prioridade
 vector<Tarefa> tarefasOrdenadas = tarefas;
 sort(tarefasOrdenadas.begin(), tarefasOrdenadas.end(), [](const Tarefa& a, const
Tarefa& b) {
 return a.getEtiqueta().getPrioridade() > b.getEtiqueta().getPrioridade();
 });
 // Em seguida, exibe as tarefas ordenadas
 for (const auto& tarefa : tarefasOrdenadas) {
 cout << "Tarefa: " << tarefa.getDescricao()
 << ", Data: " << tarefa.getData()
 << ", Horário: " << tarefa.getHorario()
 << ", Prioridade: " << tarefa.getEtiqueta().getPrioridade() << endl;
 }
}
// Método para marcar uma tarefa como concluída
void GerenciadorDeTarefas::marcarComoConcluida(const string& descricao) {
 for (auto& tarefa : tarefas) {
 if (tarefa.getDescricao() == descricao) {
 tarefa.setStatus(true);
 historico.adicionarTarefaConcluida(tarefa);
 break;
 }
 }
}
// Método para gerenciar etiquetas de uma tarefa específica
void GerenciadorDeTarefas::gerenciarEtiquetas(const string& descricao, const
Etiqueta& etiqueta) {
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
