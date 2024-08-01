#define CATCH_CONFIG_MAIN
 
#include <iostream>
#include <sstream> // Adiciona a inclusão do sstream
 
#include "catch_amalgamated.hpp"
 
#include "gerenciador_de_tarefa.h"
#include "tarefa.h"
#include "etiqueta.h"
#include "notificacao.h"
 
using namespace std;
 
// Teste para adicionar e eliminar tarefa
TEST_CASE("Adicionar e Eliminar Tarefa") {
    GerenciadorDeTarefas g;
 
    Etiqueta etiqueta("Importante", 3);
    Notificacao notificacao("Reunião", "28/07/2024", "10:00");
    Tarefa t("Tarefa 1", "28/07/2024", "09:00", etiqueta, notificacao);
 
    g.adicionarTarefa(t);
    REQUIRE(g.getTarefas().size() == 1);
 
    g.eliminarTarefa("Tarefa 1");
    REQUIRE(g.getTarefas().size() == 0);
}
 
// Teste para editar tarefa
TEST_CASE("Editar Tarefa") {
    GerenciadorDeTarefas g;
 
    Etiqueta etiqueta1("Urgente", 5);
    Notificacao notificacao1("Notificar", "28/07/2024", "10:00");
    Tarefa t1("Tarefa 1", "28/07/2024", "09:00", etiqueta1, notificacao1);
 
    Etiqueta etiqueta2("Importante", 2);
    Notificacao notificacao2("Atualizar", "29/07/2024", "11:00");
    Tarefa t2("Tarefa 1", "29/07/2024", "10:00", etiqueta2, notificacao2);
 
    g.adicionarTarefa(t1);
    g.editarTarefa("Tarefa 1", t2);
 
    REQUIRE(g.getTarefas().size() == 1);
    REQUIRE(g.getTarefas()[0].getDescricao() == "Tarefa 1");
    REQUIRE(g.getTarefas()[0].getData() == "29/07/2024");
    REQUIRE(g.getTarefas()[0].getHorario() == "10:00");
    REQUIRE(g.getTarefas()[0].getEtiqueta().getPrioridade() == 2);
}
 
// Teste para ordenar tarefas por prioridade
TEST_CASE("Ordenar Tarefas por Prioridade") {
    GerenciadorDeTarefas g;
 
    Etiqueta etiqueta1("Baixa", 1);
    Etiqueta etiqueta2("Alta", 5);
    Notificacao notificacao("Notificar", "28/07/2024", "10:00");
    Tarefa t1("Tarefa 1", "28/07/2024", "09:00", etiqueta1, notificacao);
    Tarefa t2("Tarefa 2", "28/07/2024", "10:00", etiqueta2, notificacao);
 
    g.adicionarTarefa(t1);
    g.adicionarTarefa(t2);
    g.ordenarPorPrioridade();
 
    REQUIRE(g.getTarefas()[0].getEtiqueta().getPrioridade() == 5);
    REQUIRE(g.getTarefas()[1].getEtiqueta().getPrioridade() == 1);
}
 
// Teste para marcar tarefa como concluída e exibir histórico
TEST_CASE("Marcar Tarefa como Concluída e Exibir Histórico") {
    GerenciadorDeTarefas g;
 
    Etiqueta etiqueta("Importante", 2);
    Notificacao notificacao("Notificar", "28/07/2024", "10:00");
    Tarefa t("Tarefa 1", "28/07/2024", "09:00", etiqueta, notificacao);
 
    g.adicionarTarefa(t);
    g.marcarComoConcluida("Tarefa 1");
 
    // Verificar se o histórico foi atualizado
    ostringstream oss;
    {
        streambuf* p_cout_streambuf = cout.rdbuf();
        cout.rdbuf(oss.rdbuf());
 
        g.exibirHistorico();
 
        cout.rdbuf(p_cout_streambuf);
    }
 
    string output = oss.str();
    REQUIRE(output == "Tarefa: Tarefa 1, Data: 28/07/2024, Horário: 09:00\n");
}
