#ifndef TAREFA_H
#define TAREFA_H

#include <string>
#include <vector>
#include "etiqueta.h"
#include "notificacao.h"

class Tarefa {
public:
    Tarefa(const std::string& descricao, const std::string& data, const std::string& horario);
    void setDescricao(const std::string& descricao);
    std::string getDescricao() const;
    void setData(const std::string& data);
    std::string getData() const;
    void setHorario(const std::string& horario);
    std::string getHorario() const;
    void setEtiqueta(const Etiqueta& etiqueta);
    Etiqueta getEtiqueta() const;
    void setStatus(bool concluida);
    bool isConcluida() const;
    void setNotificacao(const Notificacao& notificacao);
    Notificacao getNotificacao() const;

private:
    std::string descricao;
    std::string data;
    std::string horario;
    Etiqueta etiqueta;
    bool concluida;
    Notificacao notificacao;
};

#endif // TAREFA_H
