#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <vector>           
#include "tarefa.h"         
#include "notificacao.h"    
#include "etiqueta.h"       
#include "historico.h"      

using namespace std;

// Declaração da classe GerenciadorDeTarefas
class GerenciadorDeTarefas 
{
public:
    // Função para varrer o vetor de tarefas
    bool verificarVetor() const;
    // Função para procurar uma tarefa existente
    bool procurarTarefa(const string& descricao);
    // Método para adicionar uma nova tarefa
    void adicionarTarefa(const Tarefa& tarefa);
    // Método para eliminar uma tarefa baseada na descrição
    void eliminarTarefa(const string& descricao);
    // Método para editar uma tarefa existente
    void editarTarefa(const string& descricao, const Tarefa& tarefaAtualizada);
    // Método para exibir todas as tarefas
    void exibirTarefas() const;
    // Método para marcar uma tarefa como concluída
    void marcarComoConcluida(const string& descricao);
    // Método para gerenciar etiquetas de uma tarefa específica
    void gerenciarEtiquetas(const string& descricao, const Etiqueta& etiqueta);
    // Método para exibir o histórico de tarefas
    void exibirHistorico() const;
    // Método para ordenar as tarefas por prioridade
    void ordenarPorPrioridade();
    // Getter para obter todas as tarefas
    vector<Tarefa> getTarefas() const;
    void marcarComoNotificada (const string& descricao);

private:
    vector<Tarefa> tarefas;  // Vetor que armazena as tarefas
    Historico historico;     // Objeto que armazena o histórico das tarefas

friend class TEST_CASE;
};
#endif // GERENCIADOR_H
