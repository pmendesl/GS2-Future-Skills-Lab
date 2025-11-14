#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "competencia.h"

// Implementação da função para criar e inicializar uma nova Competencia
Competencia* criar_competencia(const char* nome, int proficiencia, const char* area) {
    Competencia* nova_competencia = (Competencia*)malloc(sizeof(Competencia));
    if (nova_competencia == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }

    // Copia o nome da competência
    strncpy(nova_competencia->nome, nome, MAX_NOME - 1);
    nova_competencia->nome[MAX_NOME - 1] = '\0'; // Garante terminação nula

    // Atribui o nível de proficiência, sem validação
    nova_competencia->proficiencia = proficiencia;

    // Copia a área de aplicação
    strncpy(nova_competencia->area, area, MAX_AREA - 1);
    nova_competencia->area[MAX_AREA - 1] = '\0'; // Garante terminação nula

    return nova_competencia;
}

// Implementação da função para exibir os detalhes de uma Competencia
void exibir_competencia(const Competencia* comp) {
    if (comp == NULL) {
        printf("Competência inválida (NULL).\n");
        return;
    }
    printf("--- Detalhes da Competência ---\n");
    printf("Nome: %s\n", comp->nome);
    printf("Proficiência: %d/5\n", comp->proficiencia);
    printf("Área: %s\n", comp->area);
    printf("-------------------------------\n");
}

// Implementação da função para liberar a memória alocada para a Competencia
void liberar_competencia(Competencia* comp) {
    free(comp);
}
