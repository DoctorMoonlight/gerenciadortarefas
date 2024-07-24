#ifndef GERENCIADOR_H
#define GERENCIADOR_H
// Incluindo as bibliotecas necessárias
#include <vector>           // Biblioteca padrão para utilização de vetores
#include "tarefa.h"         // Inclusão do cabeçalho da classe Tarefa
#include "notificacao.h"    // Inclusão do cabeçalho da classe Notificação
#include "etiqueta.h"       // Inclusão do cabeçalho da classe Etiqueta
#include "historico.h"      // Inclusão do cabeçalho da classe Historico

// Declaração da classe GerenciadorDeTarefas
class GerenciadorDeTarefas {
public:
    // Método para adicionar uma nova tarefa
    void adicionarTarefa(const Tarefa& tarefa);
    // Método para eliminar uma tarefa baseada na descrição
    void eliminarTarefa(const std::string& descricao);
    // Método para editar uma tarefa existente
    void editarTarefa(const std::string& descricao, const Tarefa& tarefaAtualizada);
    // Método para exibir todas as tarefas
    void exibirTarefas() const;
    // Método para marcar uma tarefa como concluída
    void marcarComoConcluida(const std::string& descricao);
    // Método para gerenciar etiquetas de uma tarefa específica
    void gerenciarEtiquetas(const std::string& descricao, const Etiqueta& etiqueta);
    // Método para exibir o histórico de tarefas
    void exibirHistorico() const;
private:
    std::vector<Tarefa> tarefas;  // Vetor que armazena as tarefas
    Historico historico;          // Objeto que armazena o histórico das tarefas
};
#endif // GERENCIADOR_H
