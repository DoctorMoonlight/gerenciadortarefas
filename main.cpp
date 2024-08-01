#include <iostream>
#include <thread>
#include <chrono>
#include "gerenciador_de_tarefa.h"
#include "tarefa.h"
#include "etiqueta.h"
#include "notificacao.h"
#include "historico.h"

// Usar namespace std para evitar prefixar cada elemento da biblioteca padrão com std::
using namespace std;

// Função para exibir o menu principal do gerenciador de tarefas
void mostrarMenu() {
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

int main() {
    // Cria uma instância do GerenciadorDeTarefas
    GerenciadorDeTarefas gerenciador;
    int opcao;

    // Loop principal do programa que exibe o menu e processa a entrada do usuário
    while (true) {
        mostrarMenu(); // Exibe o menu de opções
        cin >> opcao; // Lê a opção escolhida pelo usuário
        cin.ignore(); // Ignora o caractere de nova linha deixado no buffer

        // Verifica se a opção escolhida é para sair do programa
        if (opcao == 8) break;

        // Declara variáveis para armazenar os dados da tarefa, etiqueta e notificação
        string descricao, data, horario, nomeEtiqueta, mensagemNotificacao, dataNotificacao, horarioNotificacao;
        int prioridade;

        // Processa a opção escolhida pelo usuário
        switch (opcao) {
            case 1: // Adicionar nova tarefa
                cout << "Digite a descrição da tarefa: ";
                getline(cin, descricao);
                cout << "Digite a data da tarefa (DD/MM/AAAA): ";
                getline(cin, data);
                cout << "Digite o horário da tarefa (HH:MM): ";
                getline(cin, horario);
                cout << "Digite o nome da etiqueta: ";
                getline(cin, nomeEtiqueta);
                cout << "Digite a prioridade da etiqueta: ";
                cin >> prioridade;
                cin.ignore();
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
                cout << "Digite a descrição da tarefa a ser editada: ";
                getline(cin, descricao);
                cout << "Digite a nova data da tarefa (DD/MM/AAAA): ";
                getline(cin, data);
                cout << "Digite o novo horário da tarefa (HH:MM): ";
                getline(cin, horario);
                cout << "Digite o nome da nova etiqueta: ";
                getline(cin, nomeEtiqueta);
                cout << "Digite a nova prioridade da etiqueta: ";
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
                break;

            case 3: // Eliminar tarefa
                cout << "Digite a descrição da tarefa a ser eliminada: ";
                getline(cin, descricao);
                // Remove a tarefa com a descrição fornecida
                gerenciador.eliminarTarefa(descricao);
                break;

            case 4: // Exibir todas as tarefas
                // Exibe todas as tarefas armazenadas no gerenciador
                gerenciador.exibirTarefas();
                break;

            case 5: // Marcar tarefa como concluída
                cout << "Digite a descrição da tarefa a ser marcada como concluída: ";
                getline(cin, descricao);
                // Marca a tarefa com a descrição fornecida como concluída
                gerenciador.marcarComoConcluida(descricao);
                break;

            case 6: // Gerenciar etiquetas
                cout << "Digite a descrição da tarefa para gerenciar etiquetas: ";
                getline(cin, descricao);
                cout << "Digite o nome da etiqueta: ";
                getline(cin, nomeEtiqueta);
                cout << "Digite a prioridade da etiqueta: ";
                cin >> prioridade;
                cin.ignore();
                // Gerencia as etiquetas de uma tarefa específica
                gerenciador.gerenciarEtiquetas(descricao, Etiqueta(nomeEtiqueta, prioridade));
                break;

            case 7: // Exibir histórico de tarefas
                // Exibe o histórico de tarefas realizadas
                gerenciador.exibirHistorico();
                break;

            default: // Opção inválida
                cout << "Opção inválida. Tente novamente.\n";
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
    this_thread::sleep_for(chrono::minutes(1));

    return 0;
}
