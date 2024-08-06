#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "catch_amalgamated.hpp"
#include "gerenciador_de_tarefa.h"
#include "tarefa.h"
#include "etiqueta.h"
#include "notificacao.h"

using namespace std;

// Teste para o histórico
TEST_CASE("Exibir Histórico de Tarefas Concluídas") 
{
    GerenciadorDeTarefas g;

    // Criar e adicionar tarefas
    Etiqueta etiqueta1("Importante", "3");
    Notificacao notificacao1("Lembrete 1", "28/07/2024", "14:00");
    Tarefa t1("Tarefa 1", "28/07/2024", "10:00", etiqueta1, notificacao1);

    Etiqueta etiqueta2("Urgente", "5");
    Notificacao notificacao2("Lembrete 2", "29/07/2024", "15:00");
    Tarefa t2("Tarefa 2", "29/07/2024", "11:00", etiqueta2, notificacao2);

    g.adicionarTarefa(t1);
    g.adicionarTarefa(t2);

    // Marcar as tarefas como concluídas
    g.marcarComoConcluida("Tarefa 1");
    g.marcarComoConcluida("Tarefa 2");

    // Capturar a saída padrão
    ostringstream oss;
    streambuf* oldCoutStreambuf = std::cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    // Exibir o histórico de tarefas concluídas
    g.exibirHistorico();

    // Restaurar a saída padrão
    cout.rdbuf(oldCoutStreambuf);

    // Verificar se a saída está correta
    string output = oss.str();
    REQUIRE(output == "Tarefa: Tarefa 1, Data: 28/07/2024, Horário: 10:00\n"
                      "Tarefa: Tarefa 2, Data: 29/07/2024, Horário: 11:00\n");
}
