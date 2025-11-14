#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "competencia.h"

// Implementação da função para criar e inicializar uma nova Competencia
Competencia* criar_competencia(const char* nome, int proficiencia, const char* area) {
    // 1. Validação de ponteiros de entrada
    if (nome == NULL || area == NULL) {
        fprintf(stderr, "ERRO: Nome ou área da competência não podem ser NULL.\n");
        return NULL;
    }

    // 2. Validação da proficiência
    if (proficiencia < 1 || proficiencia > 5) {
        fprintf(stderr, "AVISO: Proficiência inválida (%d). Deve estar entre 1 e 5. Usando 1 como padrão.\n", proficiencia);
        proficiencia = 1; // Define um valor padrão seguro
    }

    Competencia* nova_competencia = (Competencia*)malloc(sizeof(Competencia));
    if (nova_competencia == NULL) {
        // 3. Tratamento de erro de alocação de memória
        perror("ERRO de alocação de memória para Competencia");
        return NULL;
    }

    // 4. Uso de snprintf para garantir que a string não exceda o buffer
    snprintf(nova_competencia->nome, MAX_NOME, "%s", nome);
    snprintf(nova_competencia->area, MAX_AREA, "%s", area);

    // Atribui o nível de proficiência (já validado)
    nova_competencia->proficiencia = proficiencia;

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
    if (comp != NULL) {
        free(comp);
    }
}
