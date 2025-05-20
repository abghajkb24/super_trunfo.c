/*
 * super_trunfo.c
 *
 * Programa para comparar duas cartas do Super Trunfo de cidades brasileiras.
 * Cada carta possui atributos como Estado, Código, Cidade, População, Área, PIB e Número de Pontos Turísticos.
 * O programa calcula Densidade Populacional e PIB per capita, e compara as cartas usando um atributo numérico.
 *
 * Nível básico: A comparação é feita entre duas cartas pré-definidas no código.
 * O atributo de comparação é escolhido diretamente no código (exemplo: População).
 *
 * Autor: [Pedro Henrique Cruz de Oliveira]
 * Data: [18/05/2025/modificação]
 */

#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular Densidade Populacional
float calcular_densidade_populacional(int populacao, float area) {
    if (area <= 0.0f) return 0.0f;
    return populacao / area;
}

// Função para calcular PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    if (populacao <= 0) return 0.0f;
    return pib / populacao;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta, int indice) {
    printf("Carta %d - %s (%s):\n", indice, carta.cidade, carta.estado);
    printf("  Código: %s\n", carta.codigo);
    printf("  População: %d\n", carta.populacao);
    printf("  Área: %.2f km2\n", carta.area);
    printf("  PIB: %.2f bilhões\n", carta.pib);
    printf("  Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    printf("  PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("\n");
}

int main() {
    // Cadastro das duas cartas (pré-definidas para o nível básico)
    Carta carta1 = {
        "SP", "001", "São Paulo", 12300000, 1521.11, 799.34, 15, 0, 0
    };
    Carta carta2 = {
        "RJ", "002", "Rio de Janeiro", 6000000, 1182.30, 364.53, 10, 0, 0
    };

    // Cálculo da densidade populacional e PIB per capita para cada carta
    carta1.densidade_populacional = calcular_densidade_populacional(carta1.populacao, carta1.area);
    carta2.densidade_populacional = calcular_densidade_populacional(carta2.populacao, carta2.area);

    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);

    // Exibição das cartas cadastradas
    printf("=== Cartas cadastradas ===\n\n");
    exibir_carta(carta1, 1);
    exibir_carta(carta2, 2);

    // ATRIBUTO DE COMPARAÇÃO (Escolha direta no código)
    // Altere aqui para comparar outro atributo: "populacao", "area", "pib", "densidade", "pib_per_capita"
    char atributo_comparacao[] = "populacao"; // exemplo: comparar população

    printf("=== Comparação de cartas (Atributo: ");

    // Exibe o nome do atributo na saída
    if (strcmp(atributo_comparacao, "populacao") == 0) printf("População");
    else if (strcmp(atributo_comparacao, "area") == 0) printf("Área");
    else if (strcmp(atributo_comparacao, "pib") == 0) printf("PIB");
    else if (strcmp(atributo_comparacao, "densidade") == 0) printf("Densidade Populacional");
    else if (strcmp(atributo_comparacao, "pib_per_capita") == 0) printf("PIB per capita");
    else printf("Desconhecido");
    printf(") ===\n\n");

    // Lógica de comparação usando if e if-else
    int vencedora = 0; // 1 para carta1, 2 para carta2, 0 para empate

    if (strcmp(atributo_comparacao, "populacao") == 0) {
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao) vencedora = 1;
        else if (carta2.populacao > carta1.populacao) vencedora = 2;
    }
    else if (strcmp(atributo_comparacao, "area") == 0) {
        printf("Carta 1 - %s (%s): %.2f km2\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f km2\n", carta2.cidade, carta2.estado, carta2.area);
        if (carta1.area > carta2.area) vencedora = 1;
        else if (carta2.area > carta1.area) vencedora = 2;
    }
    else if (strcmp(atributo_comparacao, "pib") == 0) {
        printf("Carta 1 - %s (%s): %.2f bilhões\n", carta1.cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f bilhões\n", carta2.cidade, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib) vencedora = 1;
        else if (carta2.pib > carta1.pib) vencedora = 2;
    }
    else if (strcmp(atributo_comparacao, "densidade") == 0) {
        printf("Carta 1 - %s (%s): %.2f hab/km2\n", carta1.cidade, carta1.estado, carta1.densidade_populacional);
        printf("Carta 2 - %s (%s): %.2f hab/km2\n", carta2.cidade, carta2.estado, carta2.densidade_populacional);
        // Para Densidade Populacional, vence quem tiver MENOR valor
        if (carta1.densidade_populacional < carta2.densidade_populacional) vencedora = 1;
        else if (carta2.densidade_populacional < carta1.densidade_populacional) vencedora = 2;
    }
    else if (strcmp(atributo_comparacao, "pib_per_capita") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);
        if (carta1.pib_per_capita > carta2.pib_per_capita) vencedora = 1;
        else if (carta2.pib_per_capita > carta1.pib_per_capita) vencedora = 2;
    }

    // Exibe o resultado da comparação
    printf("\nResultado: ");
    if (vencedora == 1) {
        printf("Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (vencedora == 2) {
        printf("Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Empate!\n");
    }

    return 0;
}

/*
 * Instruções:
 * - Para testar outro atributo de comparação, altere o valor da variável 'atributo_comparacao'.
 * - Compile com: gcc super_trunfo.c -o super_trunfo
 * - Execute com: ./super_trunfo
 */