#ifndef COMPETENCIA_H
#define COMPETENCIA_H

// Constantes para o tamanho máximo das strings
#define MAX_NOME 50
#define MAX_AREA 50

// Definição do Tipo Abstrato de Dados (TAD) Competencia
typedef struct {
    char nome[MAX_NOME];
    int proficiencia; // Nível de 1 a 5
    char area[MAX_AREA];
} Competencia;

// Função para criar e inicializar uma nova Competencia
Competencia* criar_competencia(const char* nome, int proficiencia, const char* area);

// Função para exibir os detalhes de uma Competencia
void exibir_competencia(const Competencia* comp);

// Função para liberar a memória alocada para a Competencia
void liberar_competencia(Competencia* comp);

#endif // COMPETENCIA_H
