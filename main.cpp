#include <iostream>
#include <thread>
#include <chrono>
#include "gerenciador_de_tarefa.h"
#include "tarefa.h"
#include "etiqueta.h"
#include "notificacao.h"
#include "historico.h" 

// Função para exibir o menu principal do gerenciador de tarefas
void mostrarMenu() {
    std::cout << "==== Gerenciador de Tarefas ====\n";
    std::cout << "1. Adicionar nova tarefa\n";
    std::cout << "2. Editar tarefa\n";
    std::cout << "3. Eliminar tarefa\n";
    std::cout << "4. Exibir todas as tarefas\n";
    std::cout << "5. Marcar tarefa como concluída\n";
    std::cout << "6. Gerenciar etiquetas\n";
    std::cout << "7. Exibir histórico de tarefas\n";
    std::cout << "8. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int main() {
    // Cria uma instância do GerenciadorDeTarefas
    GerenciadorDeTarefas gerenciador;
    int opcao;

    // Loop principal do programa que exibe o menu e processa a entrada do usuário
    while (true) {
        mostrarMenu(); // Exibe o menu de opções
        std::cin >> opcao; // Lê a opção escolhida pelo usuário
        std::cin.ignore(); // Ignora o caractere de nova linha deixado no buffer

        // Verifica se a opção escolhida é para sair do programa
        if (opcao == 8) break;

        // Declara variáveis para armazenar os dados da tarefa, etiqueta e notificação
        std::string descricao, data, horario, nomeEtiqueta, mensagemNotificacao, dataNotificacao, horarioNotificacao;
        int prioridade;

        // Processa a opção escolhida pelo usuário
        switch (opcao) {
            case 1: // Adicionar nova tarefa
                std::cout << "Digite a descrição da tarefa: ";
                std::getline(std::cin, descricao);
                std::cout << "Digite a data da tarefa (DD/MM/AAAA): ";
                std::getline(std::cin, data);
                std::cout << "Digite o horário da tarefa (HH:MM): ";
                std::getline(std::cin, horario);
                std::cout << "Digite o nome da etiqueta: ";
                std::getline(std::cin, nomeEtiqueta);
                std::cout << "Digite a prioridade da etiqueta: ";
                std::cin >> prioridade;
                std::cin.ignore();
                std::cout << "Digite a mensagem da notificação: ";
                std::getline(std::cin, mensagemNotificacao);
                std::cout << "Digite a data da notificação (DD/MM/AAAA): ";
                std::getline(std::cin, dataNotificacao);
                std::cout << "Digite o horário da notificação (HH:MM): ";
                std::getline(std::cin, horarioNotificacao);
                // Adiciona uma nova tarefa ao gerenciador
                gerenciador.adicionarTarefa(Tarefa(descricao, data, horario, Etiqueta(nomeEtiqueta, prioridade), Notificacao(mensagemNotificacao, dataNotificacao, horarioNotificacao)));
                break;

            case 2: // Editar tarefa existente
                std::cout << "Digite a descrição da tarefa a ser editada: ";
                std::getline(std::cin, descricao);
                std::cout << "Digite a nova data da tarefa (DD/MM/AAAA): ";
                std::getline(std::cin, data);
                std::cout << "Digite o novo horário da tarefa (HH:MM): ";
                std::getline(std::cin, horario);
                std::cout << "Digite o nome da nova etiqueta: ";
                std::getline(std::cin, nomeEtiqueta);
                std::cout << "Digite a nova prioridade da etiqueta: ";
                std::cin >> prioridade;
                std::cin.ignore();
                std::cout << "Digite a nova mensagem da notificação: ";
                std::getline(std::cin, mensagemNotificacao);
                std::cout << "Digite a nova data da notificação (DD/MM/AAAA): ";
                std::getline(std::cin, dataNotificacao);
                std::cout << "Digite o novo horário da notificação (HH:MM): ";
                std::getline(std::cin, horarioNotificacao);
                // Edita a tarefa existente no gerenciador
                gerenciador.editarTarefa(descricao, Tarefa(descricao, data, horario, Etiqueta(nomeEtiqueta, prioridade), Notificacao(mensagemNotificacao, dataNotificacao, horarioNotificacao)));
                break;

            case 3: // Eliminar tarefa
                std::cout << "Digite a descrição da tarefa a ser eliminada: ";
                std::getline(std::cin, descricao);
                // Remove a tarefa com a descrição fornecida
                gerenciador.eliminarTarefa(descricao);
                break;

            case 4: // Exibir todas as tarefas
                // Exibe todas as tarefas armazenadas no gerenciador
                gerenciador.exibirTarefas();
                break;

            case 5: // Marcar tarefa como concluída
                std::cout << "Digite a descrição da tarefa a ser marcada como concluída: ";
                std::getline(std::cin, descricao);
                // Marca a tarefa com a descrição fornecida como concluída
                gerenciador.marcarComoConcluida(descricao);
                break;

            case 6: // Gerenciar etiquetas
                std::cout << "Digite a descrição da tarefa para gerenciar etiquetas: ";
                std::getline(std::cin, descricao);
                std::cout << "Digite o nome da etiqueta: ";
                std::getline(std::cin, nomeEtiqueta);
                std::cout << "Digite a prioridade da etiqueta: ";
                std::cin >> prioridade;
                std::cin.ignore();
                // Gerencia as etiquetas de uma tarefa específica
                gerenciador.gerenciarEtiquetas(descricao, Etiqueta(nomeEtiqueta, prioridade));
                break;

            case 7: // Exibir histórico de tarefas
                // Exibe o histórico de tarefas realizadas
                gerenciador.exibirHistorico();
                break;

            default: // Opção inválida
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }

    // Verifica e notifica as tarefas se a hora de notificação chegou
    for (const auto& tarefa : gerenciador.getTarefas()) {
        if (tarefa.getNotificacao().verificarHoraNotificacao()) {
            tarefa.getNotificacao().notificar();
        }
    }

    // Pausa para não sobrecarregar o sistema
    std::this_thread::sleep_for(std::chrono::minutes(1));

    return 0;
}

