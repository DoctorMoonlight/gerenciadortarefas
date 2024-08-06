#include "gerenciador_de_tarefa.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Função para verificar se o vetor está vazio (Vazio = false)
bool GerenciadorDeTarefas::verificarVetor() const
{
    // retorna falso e exibe uma mensagem dizendo que não há tarefas
    if (tarefas.empty())
    {
        cout << "\nNão há nenhuma tarefa na sua lista.\n\n" ;
        return false;
    }
    return true;
}

// Função para procurar uma tarefa existente (Encontrou = Verdadeiro)
bool GerenciadorDeTarefas::procurarTarefa(const string& descricao) 
{
    // Se o vetor estiver não estiver vazio, varre o vetor em busca da descrição fornecida para apagar a tarefa
    if (verificarVetor())
    {
        // Varre o vetor em busca da descrição fornecida
        for (auto& tarefa : tarefas) 
        {
            if (tarefa.getDescricao() == descricao) 
            {
                return true;
            }
        }
        cout << "Tarefa " << descricao << " não foi encontrada.\n\n";
    }
    return false;
}

// Método para adicionar uma nova tarefa
void GerenciadorDeTarefas::adicionarTarefa(const Tarefa& tarefa) 
{
    tarefas.push_back(tarefa);
}

// Método para eliminar uma tarefa baseada na descrição
void GerenciadorDeTarefas::eliminarTarefa(const string& descricao) 
{
    bool delete_ok = false; // Bit que marca se a variável foi deletada

    // Varre o vetor em busca da descrição fornecida para apagar a tarefa
    for (auto& tarefa : tarefas) 
    {
        if (tarefa.getDescricao() == descricao) 
        {
            cout << "Tarefa " << descricao << " eliminada com sucesso!\n\n";
            tarefas.erase
            (
            remove_if
            (tarefas.begin(), tarefas.end(), [&descricao](const Tarefa& tarefa) 
            {
                return tarefa.getDescricao() == descricao;
            }
            ),
            tarefas.end()
            );

            delete_ok = true;
            break;
        }
    }
}

// Método para editar uma tarefa existente
void GerenciadorDeTarefas::editarTarefa(const string& descricao, const Tarefa& tarefaAtualizada) 
{
    // Se o vetor estiver não estiver vazio, varre o vetor em busca da descrição fornecida para editar a tarefa
    if (verificarVetor())
    {
        for (auto& tarefa : tarefas) 
        {
            if (tarefa.getDescricao() == descricao) 
            {
                tarefa = tarefaAtualizada;
                cout << "Tarefa " << descricao << " editada com sucesso!\n\n";
                break;
            }
        }
    }
}

// Método para ordenar taredas por prioridade
void GerenciadorDeTarefas::ordenarPorPrioridade() 
{
    sort(tarefas.begin(), tarefas.end(), [](const Tarefa& a, const Tarefa& b) 
    {
        return a.getEtiqueta().getPrioridade() > b.getEtiqueta().getPrioridade();
    }
    );
}

// Método para exibir todas as tarefas
void GerenciadorDeTarefas::exibirTarefas() const 
{
    // Se o vetor estiver não estiver vazio, ordena e exibe as tarefas
    if (verificarVetor())
    {
        // Declara o vetor tarefasOrdenadas
        vector<Tarefa> tarefasOrdenadas = tarefas;
        // Primeiro, ordena as tarefas por prioridade
        sort(tarefasOrdenadas.begin(), tarefasOrdenadas.end(), [](const Tarefa& a, const Tarefa& b) 
        {
            return a.getEtiqueta().getPrioridade() > b.getEtiqueta().getPrioridade();
        }
        );

        cout << "\nSuas tarefas são:\n"; 

        // Em seguida, exibe as tarefas ordenadas
        for (const auto& tarefa : tarefasOrdenadas) 
        {
            cout << "Tarefa: " << tarefa.getDescricao() 
                    << ", Data: " << tarefa.getData() 
                    << ", Horário: " << tarefa.getHorario() 
                    << ", Prioridade: " << tarefa.getEtiqueta().getPrioridade() << endl;
        }
        cout << endl;
    }
}

// Método para marcar uma tarefa como concluída
void GerenciadorDeTarefas::marcarComoConcluida(const string& descricao) 
{
    for (auto& tarefa : tarefas) 
    {
        if (tarefa.getDescricao() == descricao) 
        {
            tarefa.setStatus(true);
            historico.adicionarTarefaConcluida(tarefa);
            break;
        }
    }
}

// Método para gerenciar etiquetas de uma tarefa específica
void GerenciadorDeTarefas::gerenciarEtiquetas(const string& descricao, const Etiqueta& etiqueta) 
{
    for (auto& tarefa : tarefas) 
    {
        if (tarefa.getDescricao() == descricao) 
        {
            tarefa.setEtiqueta(etiqueta);
            break;
        }
    }
}

// Método para exibir o histórico de tarefas
void GerenciadorDeTarefas::exibirHistorico() const 
{
    historico.exibirHistorico();
}

// Método que retorna uma cópia do vetor de tarefas do gerenciador de tarefas
vector<Tarefa> GerenciadorDeTarefas::getTarefas() const 
{
    return tarefas;
}

// Método que marca uma tarefa como notificada, dado a descrição da tarefa
void GerenciadorDeTarefas::marcarComoNotificada(const string& descricao)
{
    for (auto& tarefa : tarefas) 
    {
        if (tarefa.getDescricao() == descricao) 
        {
            tarefa.setNotificada(true);
            break;
        }
    }
}
