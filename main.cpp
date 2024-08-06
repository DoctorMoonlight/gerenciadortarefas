#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include "gerenciador_de_tarefa.h"
#include "tarefa.h"
#include "etiqueta.h"
#include "notificacao.h"
#include "historico.h" 
#include "catch_amalgamated.hpp"

// Cria uma instância do GerenciadorDeTarefas
static GerenciadorDeTarefas gerenciador;
std::atomic_bool manterTarefasThread = true;

using namespace std;

// Função para exibir o menu principal do gerenciador de tarefas
void mostrarMenu() 
{
    cout << "==== Gerenciador de Tarefas ====\n";
    cout << "1. Adicionar nova tarefa\n";
    cout << "2. Editar tarefa\n";
    cout << "3. Eliminar tarefa\n";
    cout << "4. Exibir todas as tarefas\n";
    cout << "5. Marcar tarefa como concluída\n";
    cout << "6. Gerenciar etiquetas\n";
    cout << "7. Exibir histórico de tarefas\n";
    cout << "8. Sair\n";
    cout << "Escolha uma opção: ";
}

// Função que verifica se há uma tarefa e notifica no terminal
void verificarTarefas()
{
    while(manterTarefasThread)
    {
        // Verifica e notifica as tarefas se a hora de notificação chegou
        for (const auto& tarefa : gerenciador.getTarefas()) 
        {
            if (tarefa.getNotificacao().verificarHoraNotificacao()) 
            {
                // Se a tarefa já tiver sido notificada, não a exibe no terminal novamente
                if (!tarefa.isNotificada()){
                    tarefa.getNotificacao().notificar();
                    gerenciador.marcarComoNotificada(tarefa.getDescricao()); // Marca a tarefa como notificada para não exibir mais de uma vez
                }
            }
        }

        // A cada 5 segundos essa thread é executada
        this_thread::sleep_for(chrono::seconds(5));
    }
}

int main() 
{
    int opcao;
    thread verificarTarefasThread(&verificarTarefas);

    // Loop principal do programa que exibe o menu e processa a entrada do usuário
    while (true) {
        mostrarMenu(); // Exibe o menu de opções
        cin >> opcao; // Lê a opção escolhida pelo usuário
        cin.ignore(); // Ignora o caractere de nova linha deixado no buffer

        // Verifica se a opção escolhida é para sair do programa
        if (opcao == 8) break;

        // Declara variáveis para armazenar os dados da tarefa, etiqueta e notificação
        string descricao, data, horario, nomeEtiqueta, mensagemNotificacao, dataNotificacao, horarioNotificacao, prioridade;

        // Processa a opção escolhida pelo usuário
        switch (opcao) 
        {
            case 1: // Adicionar nova tarefa
                cout << "\nDigite a descrição da tarefa: ";
                getline(cin, descricao); 
                cout << "Digite a data da tarefa (DD/MM/AAAA): ";
                getline(cin, data);
                cout << "Digite o horário da tarefa (HH:MM): ";
                getline(cin, horario);
                cout << "Digite o nome da etiqueta: ";
                getline(cin, nomeEtiqueta);
                cout << "Digite a prioridade da etiqueta (1 a 5): ";
                getline(cin, prioridade);
                cout << "Digite a mensagem da notificação: ";
                getline(cin, mensagemNotificacao);
                cout << "Digite a data da notificação (DD/MM/AAAA): ";
                getline(cin, dataNotificacao);
                cout << "Digite o horário da notificação (HH:MM): ";
                getline(cin, horarioNotificacao);
                // Adiciona uma nova tarefa ao gerenciador
                gerenciador.adicionarTarefa(Tarefa(descricao, data, horario, Etiqueta(nomeEtiqueta, prioridade), Notificacao(mensagemNotificacao, dataNotificacao, horarioNotificacao)));
                break;

            case 2: // Editar tarefa existente
                // Se o vetor estiver não estiver vazio, inicia a edição da tarefa
                if(gerenciador.verificarVetor())
                {
                    cout << "\nDigite a descrição da tarefa a ser editada: ";
                    getline(cin, descricao);

                    // Se a tarefa for encontrada, inicia a edição 
                    if(gerenciador.procurarTarefa(descricao))
                    {
                        cout << "Digite a nova data da tarefa (DD/MM/AAAA): ";
                        getline(cin, data);
                        cout << "Digite o novo horário da tarefa (HH:MM): ";
                        getline(cin, horario);
                        cout << "Digite o nome da nova etiqueta: ";
                        getline(cin, nomeEtiqueta);
                        cout << "Digite a nova prioridade da etiqueta (1 a 5): ";
                        cin >> prioridade;
                        cin.ignore();
                        cout << "Digite a nova mensagem da notificação: ";
                        getline(cin, mensagemNotificacao);
                        cout << "Digite a nova data da notificação (DD/MM/AAAA): ";
                        getline(cin, dataNotificacao);
                        cout << "Digite o novo horário da notificação (HH:MM): ";
                        getline(cin, horarioNotificacao);
                        // Edita a tarefa existente no gerenciador
                        gerenciador.editarTarefa(descricao, Tarefa(descricao, data, horario, Etiqueta(nomeEtiqueta, prioridade), Notificacao(mensagemNotificacao, dataNotificacao, horarioNotificacao)));
                    }
                }
                break;

            case 3: // Eliminar tarefa
                // Se o vetor estiver não estiver vazio, inicia a eliminação da tarefa
                if(gerenciador.verificarVetor())
                {
                    cout << "\nDigite a descrição da tarefa a ser eliminada: ";
                    getline(cin, descricao);
                    // Se a tarefa for encontrada, inicia a eliminação
                    if(gerenciador.procurarTarefa(descricao))
                    {
                        // Remove a tarefa com a descrição fornecida
                        gerenciador.eliminarTarefa(descricao);
                    }
                }
                break;

            case 4: // Exibir todas as tarefas
                // Exibe todas as tarefas armazenadas no gerenciador
                gerenciador.exibirTarefas();
                break;

            case 5: // Marcar tarefa como concluída
                // Se o vetor estiver não estiver vazio, inicia a edição da tarefa
                if(gerenciador.verificarVetor())
                {
                    cout << "\nDigite a descrição da tarefa a ser marcada como concluída: ";
                    getline(cin, descricao);
                    // Se a tarefa for encontrada, inicia a edição 
                    if(gerenciador.procurarTarefa(descricao)){
                        // Marca a tarefa com a descrição fornecida como concluída
                        gerenciador.marcarComoConcluida(descricao);
                    }
                }
                break;

            case 6: // Gerenciar etiquetas
                // Se o vetor estiver não estiver vazio, inicia o gerenciamento das etiquetas
                if(gerenciador.verificarVetor())
                {
                    cout << "\nDigite a descrição da tarefa para gerenciar etiquetas: ";
                    getline(cin, descricao);
                    // Se a tarefa for encontrada, inicia a edição 
                    if(gerenciador.procurarTarefa(descricao)){
                        cout << "Digite o nome da etiqueta: ";
                        getline(cin, nomeEtiqueta);
                        cout << "Digite a prioridade da etiqueta (1 a 5): ";
                        cin >> prioridade;
                        cin.ignore();
                        // Gerencia as etiquetas de uma tarefa específica
                        gerenciador.gerenciarEtiquetas(descricao, Etiqueta(nomeEtiqueta, prioridade));
                    }
                }
                break;

            case 7: // Exibir histórico de tarefas
            // Se o vetor estiver não estiver vazio, inicia a edição da tarefa
                if(gerenciador.verificarVetor())
                {
                    // Exibe o histórico de tarefas realizadas
                    gerenciador.exibirHistorico();
                }
                break;

            default: // Opção inválida
                cout << "\nOpção inválida. Tente novamente.\n\n";
                break;
        }
    }

    manterTarefasThread = false;
    verificarTarefasThread.detach();

    return 0;
}
