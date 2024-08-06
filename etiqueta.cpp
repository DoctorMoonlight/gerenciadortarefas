#include "etiqueta.h"

using namespace std;

// Construtor que aceita um nome e uma prioridade 
Etiqueta::Etiqueta(const string& nome, const string& prioridade)
    : nome(nome), prioridade(prioridade) {}

// Define o nome da etiqueta
void Etiqueta::setNome(const string& nome) 
{
    this->nome = nome;
}

// Retorna o nome da etiqueta
string Etiqueta::getNome() const 
{
    return nome;
}

// Define a prioridade da etiqueta
void Etiqueta::setPrioridade(const string& prioridade) 
{
    this->prioridade = prioridade;
}

// Retorna a prioridade da etiqueta
string Etiqueta::getPrioridade() const 
{
    return prioridade;
}

