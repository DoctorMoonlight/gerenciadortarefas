#ifndef NOTIFICACAO_H
#define NOTIFICACAO_H

#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class Notificacao 
{
public:
    // Construtor padrão
    Notificacao();
    
    // Construtor que inicializa uma notificação com mensagem, data e horário
    Notificacao(const string& mensagem, const string& data, const string& horario);
    
    // Setter para a mensagem da notificação
    void setMensagem(const string& mensagem);
    // Getter para obter a mensagem da notificação
    string getMensagem() const;
    
    // Setter para a data da notificação
    void setData(const string& data);
    // Getter para obter a data da notificação
    string getData() const;
    
    // Setter para o horário da notificação
    void setHorario(const string& horario);
    // Getter para obter o horário da notificação
    string getHorario() const;
    
    // Função para notificar (emitir um som e imprimir algo)
    void notificar() const;
    
    // Função para verificar se a notificação deve ser exibida
    bool verificarHoraNotificacao() const;

private:
    string mensagem;
    string data;
    string horario;
    
    // Converte uma string de data e hora para std::tm
    tm stringParaTm(const string& data, const string& horario) const;

friend class TEST_CASE;
};

#endif // NOTIFICACAO_H

