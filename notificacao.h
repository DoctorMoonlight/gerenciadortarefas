#ifndef NOTIFICACAO_H
#define NOTIFICACAO_H

#include <string>

class Notificacao {
public:
    Notificacao(const std::string& mensagem, const std::string& data, const std::string& horario);
    void setMensagem(const std::string& mensagem);
    std::string getMensagem() const;
    void setData(const std::string& data);
    std::string getData() const;
    void setHorario(const std::string& horario);
    std::string getHorario() const;
    void notificar() const;

private:
    std::string mensagem;
    std::string data;
    std::string horario;
};

#endif // NOTIFICACAO_H
