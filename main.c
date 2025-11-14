#include <stdio.h>
#include "competencia.h"

int main() {
    // 1. Demonstração do uso correto do TAD Competencia
    Competencia* comp1 = criar_competencia("Python", 4, "Data Science");

    if (comp1 != NULL) {
        exibir_competencia(comp1);
        liberar_competencia(comp1);
    }

    printf("\n");

    // 2. Teste de validação de proficiência (deve emitir um aviso e usar 1)
    Competencia* comp2 = criar_competencia("C", 10, "Sistemas Embarcados");
    if (comp2 != NULL) {
        exibir_competencia(comp2);
        liberar_competencia(comp2);
    }

    printf("\n");

    // 3. Teste de tratamento de erro (passando NULL para o nome)
    Competencia* comp3 = criar_competencia(NULL, 3, "Gestão de Projetos");
    if (comp3 == NULL) {
        printf("Teste de erro (NULL) bem-sucedido: Competência não foi criada.\n");
    }

    return 0;
}
