#ifndef NOTIFICACAO_H
#define NOTIFICACAO_H
#include <string>
#include <chrono>
#include <ctime>
class Notificacao {
public:
 // Construtor padrão
 Notificacao();

 // Construtor que inicializa uma notificação com mensagem, data e horário
 Notificacao(const std::string& mensagem, const std::string& data, const std::string&
horario);

 // Setter para a mensagem da notificação
 void setMensagem(const std::string& mensagem);
 // Getter para obter a mensagem da notificação
 std::string getMensagem() const;

 // Setter para a data da notificação
 void setData(const std::string& data);
 // Getter para obter a data da notificação
 std::string getData() const;
// Setter para o horário da notificação
 void setHorario(const std::string& horario);
 // Getter para obter o horário da notificação
 std::string getHorario() const;

 // Função para notificar (emitir um som e imprimir algo)
 void notificar() const;

 // Função para verificar se a notificação deve ser exibida
 bool verificarHoraNotificacao() const;
private:
 std::string mensagem;
 std::string data;
 std::string horario;
// Converte uma string de data e hora para std::tm
 std::tm stringParaTm(const std::string& data, const std::string& horario) const;
};
#endif // NOTIFICACAO_H
