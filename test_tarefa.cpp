#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "tarefa.h"
#include "etiqueta.h"
#include "notificacao.h"

using namespace std;

// Teste para o construtor e os métodos de Tarefa
TEST_CASE("Teste Tarefa") 
{
    // Cria objetos Etiqueta e Notificacao para usar no teste
    Etiqueta etiqueta("Importante", "3");
    Notificacao notificacao("Lembrete", "28/07/2024", "14:00");

    // Use o construtor que requer todos os parâmetros
    Tarefa t("Tarefa 1", "28/07/2024", "10:00", etiqueta, notificacao);

    REQUIRE(t.getDescricao() == "Tarefa 1");
    REQUIRE(t.getData() == "28/07/2024");
    REQUIRE(t.getHorario() == "10:00");
    REQUIRE(t.getEtiqueta().getPrioridade() == "3");
    REQUIRE(t.getNotificacao().getMensagem() == "Lembrete");
    REQUIRE(t.isConcluida() == false);
    REQUIRE(t.isNotificada() == false);

    // Atualiza a tarefa
    t.setDescricao("Nova Descrição");
    t.setData("29/07/2024");
    t.setHorario("11:00");
    t.setEtiqueta(Etiqueta("Urgente", "5"));
    t.setNotificacao(Notificacao("Atualizar", "29/07/2024", "11:00"));
    t.setStatus(true);
    t.setNotificada(true);

    // Verifica as atualizações
    REQUIRE(t.getDescricao() == "Nova Descrição");
    REQUIRE(t.getData() == "29/07/2024");
    REQUIRE(t.getHorario() == "11:00");
    REQUIRE(t.getEtiqueta().getPrioridade() == "5");
    REQUIRE(t.getNotificacao().getMensagem() == "Atualizar");
    REQUIRE(t.isConcluida() == true);
    REQUIRE(t.isNotificada() == true);
}

