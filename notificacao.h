#ifndef NOTIFICACAO_H

#define NOTIFICACAO_H

#include <string> // Inclui a biblioteca de string do C++

class Notificacao {
public:
    // Construtor que inicializa uma notificação com mensagem, data e horário
    Notificacao(const std::string& mensagem, const std::string& data, const std::string& horario);
    
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
    
    // Função para notificar (possivelmente emitir uma notificação ou imprimir algo)
    void notificar() const;

private:
    // Atributo que armazena a mensagem da notificação
    std::string mensagem;
    // Atributo que armazena a data da notificação
    std::string data;
    // Atributo que armazena o horário da notificação
    std::string horario;
};


#endif // NOTIFICACAO_H
