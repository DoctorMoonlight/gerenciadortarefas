#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "etiqueta.h"

using namespace std;

// Teste para o construtor padrão
TEST_CASE("Construtor Padrão da Etiqueta") 
{
    Etiqueta e;
    REQUIRE(e.getNome() == "");
    REQUIRE(e.getPrioridade() == "");
}

// Teste para o construtor parametrizado
TEST_CASE("Construtor Parametrizado da Etiqueta") 
{
    Etiqueta e("Urgente", "5");
    REQUIRE(e.getNome() == "Urgente");
    REQUIRE(e.getPrioridade() == "5");
}

// Teste para setNome e getNome
TEST_CASE("Set e Get Nome") 
{
    Etiqueta e;
    e.setNome("Importante");
    REQUIRE(e.getNome() == "Importante");
}

// Teste para setPrioridade e getPrioridade
TEST_CASE("Set e Get Prioridade") 
{
    Etiqueta e;
    e.setPrioridade("5");
    REQUIRE(e.getPrioridade() == "5");
}
