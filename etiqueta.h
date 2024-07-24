#ifndef ETIQUETA_H
#define ETIQUETA_H

#include <string>

class Etiqueta {
public:
    Etiqueta(const std::string& nome, int prioridade = 0);
    void setNome(const std::string& nome);
    std::string getNome() const;
    void setPrioridade(int prioridade);
    int getPrioridade() const;

private:
    std::string nome;
    int prioridade;
};

#endif // ETIQUETA_H
