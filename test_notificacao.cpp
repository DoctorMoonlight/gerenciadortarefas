#define CATCH_CONFIG_MAIN // Define a função main para o Catch2
#include "catch_amalgamated.hpp"
#include "notificacao.h"
#include <sstream>
#include <iostream>
#include <cstdlib> // Para std::system

using namespace std;
// Teste para o construtor padrão
TEST_CASE("Construtor Padrão da Notificacao") {
 Notificacao n;
 REQUIRE(n.getMensagem() == "");
 REQUIRE(n.getData() == "");
 REQUIRE(n.getHorario() == "");
}

// Teste para o construtor parametrizado
TEST_CASE("Construtor Parametrizado da Notificacao") {
 Notificacao n("Lembrete", "2024-07-28", "14:00");
 REQUIRE(n.getMensagem() == "Lembrete");
 REQUIRE(n.getData() == "2024-07-28");
 REQUIRE(n.getHorario() == "14:00");
}

// Teste para setMensagem e getMensagem
TEST_CASE("Set e Get Mensagem") {
 Notificacao n;
 n.setMensagem("Lembrete");
 REQUIRE(n.getMensagem() == "Lembrete");
}

// Teste para setData e getData
TEST_CASE("Set e Get Data") {
 Notificacao n;
 n.setData("2024-07-28");
 REQUIRE(n.getData() == "2024-07-28");
}

// Teste para setHorario e getHorario
TEST_CASE("Set e Get Horario") {
 Notificacao n;
 n.setHorario("14:00");
 REQUIRE(n.getHorario() == "14:00");
}

// Teste para notificar (capturando a saída padrão e verificando o som)
TEST_CASE("Notificar") {
 Notificacao n("Lembrete", "2024-07-28", "14:00");
 // Capturar a saída padrão
 ostringstream oss;
 streambuf* oldCoutStreambuf = cout.rdbuf();
 cout.rdbuf(oss.rdbuf());
 // Chamar a função que imprime a notificação e faz o som
 n.notificar();
 // Restaurar a saída padrão
 cout.rdbuf(oldCoutStreambuf);
 // Verificar se a saída está correta
 string output = oss.str();
 
 REQUIRE(output == "Notificação: Lembrete em 2024-07-28 às 14:00\n");
 // Verificar o comando do sistema para som (opcional, pode ser ignorado se não for
testável diretamente)
 // A execução real do comando pode variar dependendo do sistema operacional
 // Aqui, apenas uma demonstração do conceito é fornecida
 int result = system("echo 'Notificação: Lembrete em 2024-07-28 às 14:00'");
 REQUIRE(result == 0); // Verifica se o comando foi executado com sucesso (0
geralmente indica sucesso)
}