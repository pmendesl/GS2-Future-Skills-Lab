# GS2-Future-Skills-Lab
Link do vídeo: https://www.youtube.com/watch?v=tFnx3CgwW_E

## 1. O Problema: TAD Competência Profissional

**Tema:** Future Skills Lab - Inteligência Computacional para o Trabalho do Amanhã

**Mini-Desafio Escolhido:** Implementar um Tipo Abstrato de Dados (TAD) para representar e gerenciar uma **Competência Profissional**.

O objetivo é criar uma estrutura de dados fundamental para um sistema de mapeamento de habilidades. Este TAD, chamado `Competencia`, deve armazenar:
1. O nome da competência (ex: "Python").
2. O nível de proficiência (inteiro de 1 a 5).
3. A área de aplicação (ex: "Data Science").

A solução deve demonstrar o uso de **Tipo Abstrato de Dados (TAD)**, um dos conceitos centrais da disciplina de Estrutura de Dados.

## 2. O Prompt para a IA

O seguinte prompt foi utilizado para solicitar o código-fonte em C a uma ferramenta de Inteligência Artificial:

> "Gere o código-fonte completo em C para implementar um Tipo Abstrato de Dados (TAD) chamado 'Competencia'. Este TAD deve ser definido em um arquivo de cabeçalho 'competencia.h' e sua implementação em 'competencia.c'. A estrutura 'Competencia' deve conter:
> 1. Um campo para o nome da competência (string de até 50 caracteres).
> 2. Um campo para o nível de proficiência (inteiro de 1 a 5).
> 3. Um campo para a área de aplicação (string de até 50 caracteres).
> O arquivo 'competencia.h' deve declarar uma função para criar uma nova competência e uma função para exibir os detalhes da competência. O arquivo 'competencia.c' deve conter a implementação dessas funções. Inclua um arquivo 'main.c' para demonstrar o uso do TAD, criando uma instância e exibindo seus dados."

## 3. Código da IA (competencia_ia.c)

O código gerado pela IA para a implementação da função `criar_competencia` foi o seguinte:

```c
// Conteúdo de competencia_ia.c (Trecho relevante)

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
```

## 4. Análise Crítica da Solução da IA

A solução da IA, embora funcional, nos mostrou que ainda precisamos aplicar nosso conhecimento. Ela apresentou falhas significativas em termos de **robustez** e **boas práticas de programação em C**, especialmente no tratamento de erros e validação de dados, o que reforça a importância do nosso raciocínio algorítmico.

| Critério | Avaliação da IA | Falha/Melhoria Necessária |
| :--- | :--- | :--- |
| **Correção** | **Funcional** | O código compila e executa. O uso de `strncpy` é correto para evitar *buffer overflow*. |
| **Eficiência** | **Adequada** | Para um TAD simples, a alocação dinâmica (`malloc`) é o método padrão. Não há ineficiências algorítmicas. |
| **Clareza e Boas Práticas** | **Insuficiente** | **Falta de Validação e Tratamento de Erros:** |
| | | 1. **Validação de Dados:** A IA não validou o campo `proficiencia` (que deve ser de 1 a 5), permitindo valores inválidos (ex: 10 ou -1). |
| | | 2. **Tratamento de Ponteiros NULL:** A IA não verificou se os parâmetros de entrada (`nome` e `area`) eram `NULL` antes de tentar copiá-los, o que causaria uma falha de segmentação (*Segmentation Fault*). |
| | | 3. **Mensagens de Erro:** A mensagem de erro de alocação de memória (`printf("Erro de alocação de memória!\n");`) é genérica. O uso de `perror()` é a prática recomendada para erros de sistema. |

## 5. Solução Refinada: Explicação das Melhorias

O código final (`competencia.c` e `main.c`) foi corrigido e otimizado para incluir as seguintes melhorias, focando em **robustez** e **tratamento de erros**, que são diferenciais do raciocínio humano sobre o código gerado automaticamente:

1.  **Validação de Ponteiros de Entrada:** Adicionada uma verificação no início de `criar_competencia` para garantir que `nome` e `area` não sejam `NULL`. Se forem, a função retorna `NULL` imediatamente, prevenindo *Segmentation Fault*.
2.  **Validação de Proficiência:** Implementada uma lógica para verificar se `proficiencia` está no intervalo [1, 5]. Se estiver fora, um aviso é emitido para o `stderr` e o valor é ajustado para `1` (um valor padrão seguro), garantindo a integridade dos dados.
3.  **Melhoria no Tratamento de Erro de Alocação:** A função `printf` foi substituída por `perror("ERRO de alocação de memória para Competencia")` para reportar erros de alocação de memória de forma mais padronizada e informativa.
4.  **Uso de `snprintf`:** Substituímos o `strncpy` (que pode ser menos intuitivo) por `snprintf` para a cópia de strings. Embora `strncpy` tenha sido usado corretamente pela IA, `snprintf` é frequentemente preferido em C moderno para garantir a terminação nula e evitar *buffer overflow* de forma mais explícita.

Com essas melhorias, conseguimos transformar um código funcional, mas frágil, em uma implementação mais robusta e segura. Isso demonstra, na prática, como a análise crítica humana é essencial para refinar e validar o código gerado por ferramentas de IA.

## Como Compilar e Executar

Para compilar a solução final:

```bash
gcc -o main main.c competencia.c
./main
```

## Integrantes do Grupo

*   Alexandre Bertini - RM: 563346
*   Pedro Mendes - RM: 562242
*   Leonardo Augusto - RM: 565564

**Turma:** 1CCPF
