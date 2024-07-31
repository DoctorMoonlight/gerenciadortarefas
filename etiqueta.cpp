#include "etiqueta.h"

// Construtor que aceita um nome e uma prioridade com valor padrão 0
Etiqueta::Etiqueta(const std::string& nome, int prioridade)
    : nome(nome), prioridade(prioridade) {}

// Define o nome da etiqueta
void Etiqueta::setNome(const std::string& nome) {
    this->nome = nome;
}

// Retorna o nome da etiqueta
std::string Etiqueta::getNome() const {
    return nome;
}

// Define a prioridade da etiqueta
void Etiqueta::setPrioridade(int prioridade) {
    this->prioridade = prioridade;
}

// Retorna a prioridade da etiqueta
int Etiqueta::getPrioridade() const {
    return prioridade;
}
