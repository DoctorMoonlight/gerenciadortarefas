#ifndef ETIQUETA_H
#define ETIQUETA_H

#include <string>

using namespace std;

class Etiqueta 
{
public:
    // Construtor padrão
    Etiqueta() : nome(""), prioridade("") {}
    
    // Construtor que aceita um nome e uma prioridade 
    Etiqueta(const string& nome, const string& prioridade);

    // Define o nome da etiqueta
    void setNome(const string& nome);

    // Retorna o nome da etiqueta
    string getNome() const;

    // Define a prioridade da etiqueta
    void setPrioridade(const string& prioridade);

    // Retorna a prioridade da etiqueta
    string getPrioridade() const;

private:
    string nome;  // Membro de dados para armazenar o nome da etiqueta
    string prioridade;   // Membro de dados para armazenar a prioridade da etiqueta

friend class TEST_CASE;

};

#endif // ETIQUETA_H
