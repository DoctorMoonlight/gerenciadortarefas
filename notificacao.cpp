#include "notificacao.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <chrono>

// Construtor padrão da classe Notificacao
// Inicializa a mensagem, a data e o horário como strings vazias
Notificacao::Notificacao()
    : mensagem(""), data(""), horario("") {}

// Construtor da classe Notificacao com parâmetros
// Inicializa a mensagem, a data e o horário com os valores fornecidos
Notificacao::Notificacao(const std::string& mensagem, const std::string& data, const std::string& horario)
    : mensagem(mensagem), data(data), horario(horario) {}

// Define a mensagem da notificação
void Notificacao::setMensagem(const std::string& mensagem) {
    this->mensagem = mensagem;
}

// Retorna a mensagem da notificação
std::string Notificacao::getMensagem() const {
    return mensagem;
}

// Define a data da notificação
void Notificacao::setData(const std::string& data) {
    this->data = data;
}

// Retorna a data da notificação
std::string Notificacao::getData() const {
    return data;
}

// Define o horário da notificação
void Notificacao::setHorario(const std::string& horario) {
    this->horario = horario;
}

// Retorna o horário da notificação
std::string Notificacao::getHorario() const {
    return horario;
}

// Emite a notificação no terminal
// Exibe uma mensagem e emite um som (beep) de acordo com o sistema operacional
void Notificacao::notificar() const {
    std::cout << "Notificação: " << mensagem << " em " << data << " às " << horario << std::endl;

    #ifdef _WIN32
        // Emite um beep no Windows
        std::system("echo ^G");
    #else
        // Emite um beep em sistemas Unix (Linux, macOS)
        std::system("echo -e \\a");
    #endif
}

// Converte a data e o horário da notificação para um objeto std::tm
// Utiliza std::get_time para analisar a string e preencher o objeto std::tm
std::tm Notificacao::stringParaTm(const std::string& data, const std::string& horario) const {
    std::tm tm = {}; // Inicializa uma estrutura std::tm vazia
    std::istringstream ss(data + " " + horario); // Cria um fluxo de string com data e horário
    ss >> std::get_time(&tm, "%d/%m/%Y %H:%M"); // Analisa a string e preenche o objeto std::tm
    return tm;
}

// Verifica se o horário atual é igual ao horário da notificação
// Compara a data e o horário atuais com a data e o horário da notificação
bool Notificacao::verificarHoraNotificacao() const {
    // Obtém o horário atual do sistema
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);

    // Converte a data e o horário da notificação para std::tm
    std::tm notif_tm = stringParaTm(data, horario);

    // Compara a data e o horário atuais com os da notificação
    return (now_tm.tm_year == notif_tm.tm_year &&
            now_tm.tm_mon == notif_tm.tm_mon &&
            now_tm.tm_mday == notif_tm.tm_mday &&
            now_tm.tm_hour == notif_tm.tm_hour &&
            now_tm.tm_min == notif_tm.tm_min);
}
