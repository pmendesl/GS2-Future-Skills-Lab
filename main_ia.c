#include <stdio.h>
#include "competencia.h"

int main() {
    // Demonstração do uso do TAD Competencia
    Competencia* comp1 = criar_competencia("Python", 4, "Data Science");

    if (comp1 != NULL) {
        exibir_competencia(comp1);
        liberar_competencia(comp1);
    }

    // Exemplo de uso com dados que podem causar problemas (proficiência fora do range)
    Competencia* comp2 = criar_competencia("C", 10, "Sistemas Embarcados");
    if (comp2 != NULL) {
        exibir_competencia(comp2);
        liberar_competencia(comp2);
    }

    return 0;
}
