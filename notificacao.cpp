#include "notificacao.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <chrono>

using namespace std;

// Construtor padrão da classe Notificacao
Notificacao::Notificacao() : mensagem(""), data(""), horario("") {}

// Construtor da classe Notificacao com parâmetros
Notificacao::Notificacao(const string& mensagem, const string& data, const string& horario) : mensagem(mensagem), data(data), horario(horario) {}

// Define a mensagem da notificação
void Notificacao::setMensagem(const string& mensagem) 
{
    this->mensagem = mensagem;
} 

// Retorna a mensagem da notificação
string Notificacao::getMensagem() const 
{
    return mensagem;
}

// Define a data da notificação
void Notificacao::setData(const string& data) 
{
    this->data = data;
}

// Retorna a data da notificação
string Notificacao::getData() const 
{
    return data;
}

// Define o horário da notificação
void Notificacao::setHorario(const string& horario) 
{
    this->horario = horario;
} 

// Retorna o horário da notificação
string Notificacao::getHorario() const 
{
    return horario;
}

// Emite a notificação no terminal
void Notificacao::notificar() const
{
    cout << "\x1b[1;31m\n\nNotificação: " << mensagem << " em " << data << " às " << horario << "\x1b[0m" << endl;

    #ifdef _WIN32
    // Emite um beep no Windows
    system("powershell.exe [console]::beep(500,600)");
    #else
    // Emite um beep em sistemas Unix (Linux, macOS)
    system("echo -e \\a");
    #endif
}

// Converte a data e o horário da notificação para um objeto std::tm
tm Notificacao::stringParaTm(const string& data, const string& horario) const 
{
    tm tm = {}; // Inicializa uma estrutura std::tm vazia
    istringstream ss(data + " " + horario); // Cria um fluxo de string com data e horário
    ss >> get_time(&tm, "%d/%m/%Y %H:%M"); // Analisa a string e preenche o objeto
    return tm;
}

// Verifica se o horário atual é igual ao horário da notificação
bool Notificacao::verificarHoraNotificacao() const 
{
    // Obtém o horário atual do sistema
    auto now = chrono::system_clock::now();
    auto now_c = chrono::system_clock::to_time_t(now);
    tm now_tm = *localtime(&now_c);
    // Converte a data e o horário da notificação para std::tm
    tm notif_tm = stringParaTm(data, horario);
    // Compara a data e o horário atuais com os da notificação
    return (now_tm.tm_year == notif_tm.tm_year 
        && now_tm.tm_mon == notif_tm.tm_mon 
        && now_tm.tm_mday == notif_tm.tm_mday 
        && now_tm.tm_hour == notif_tm.tm_hour 
        && now_tm.tm_min == notif_tm.tm_min);
}
