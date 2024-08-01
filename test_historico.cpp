#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "tarefa.h"
#include "etiqueta.h"
#include "notificacao.h"

// Teste para o construtor e os métodos de Tarefa
TEST_CASE("Teste Tarefa") {
Etiqueta etiqueta("Importante", 3);
Notificacao notificacao("Lembrete", "28/07/2024", "14:00");
Tarefa t("Tarefa 1", "28/07/2024", "10:00", etiqueta, notificacao);
  
REQUIRE(t.getDescricao() == "Tarefa 1");
REQUIRE(t.getData() == "28/07/2024");
REQUIRE(t.getHorario() == "10:00");
REQUIRE(t.getEtiqueta().getPrioridade() == 3);
REQUIRE(t.getNotificacao().getMensagem() == "Lembrete");
REQUIRE(t.isConcluida() == false);
  
t.setDescricao("Nova Descrição");
t.setData("29/07/2024");
t.setHorario("11:00");
t.setEtiqueta(Etiqueta("Urgente", 5));
t.setNotificacao(Notificacao("Atualizar", "29/07/2024", "11:00"));
t.setStatus(true);
  
REQUIRE(t.getDescricao() == "Nova Descrição");
REQUIRE(t.getData() == "29/07/2024");
REQUIRE(t.getHorario() == "11:00");
REQUIRE(t.getEtiqueta().getPrioridade() == 5);
REQUIRE(t.getNotificacao().getMensagem() == "Atualizar");
REQUIRE(t.isConcluida() == true);
}
