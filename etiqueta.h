#ifndef ETIQUETA_H
#define ETIQUETA_H


#include <string>


class Etiqueta {
public:
    // Construtor padrão
    Etiqueta() : nome(""), prioridade(0) {}
    
    // Construtor que aceita um nome e uma prioridade com valor padrão 0
    Etiqueta(const std::string& nome, int prioridade = 0);


    // Define o nome da etiqueta
    void setNome(const std::string& nome);


    // Retorna o nome da etiqueta
    std::string getNome() const;


    // Define a prioridade da etiqueta
    void setPrioridade(int prioridade);


    // Retorna a prioridade da etiqueta
    int getPrioridade() const;


private:
    std::string nome;  // Membro de dados para armazenar o nome da etiqueta
    int prioridade;   // Membro de dados para armazenar a prioridade da etiqueta
};


#endif // ETIQUETA_H
