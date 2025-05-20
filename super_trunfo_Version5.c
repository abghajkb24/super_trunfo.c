#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} CartaPais;

// Função para imprimir informações de uma carta
void exibirCarta(CartaPais c) {
    printf("País: %s\n", c.nome);
    printf("- População: %d\n", c.populacao);
    printf("- Área: %.2f km2\n", c.area);
    printf("- PIB: %.2f bilhões USD\n", c.pib);
    printf("- Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("- Densidade demográfica: %.2f hab/km2\n", c.densidade);
}

// Função para comparar dois países conforme o atributo do menu
void compararCartas(CartaPais a, CartaPais b, int opcao) {
    printf("\nComparando %s e %s\n", a.nome, b.nome);

    switch (opcao) {
        case 1:
            printf("Você escolheu: População\n");
            printf("%s: %d habitantes\n", a.nome, a.populacao);
            printf("%s: %d habitantes\n", b.nome, b.populacao);
            if (a.populacao > b.populacao)
                printf("Vencedor: %s!\n", a.nome);
            else if (a.populacao < b.populacao)
                printf("Vencedor: %s!\n", b.nome);
            else
                printf("Empate!\n");
            break;
        case 2:
            printf("Você escolheu: Área\n");
            printf("%s: %.2f km2\n", a.nome, a.area);
            printf("%s: %.2f km2\n", b.nome, b.area);
            if (a.area > b.area)
                printf("Vencedor: %s!\n", a.nome);
            else if (a.area < b.area)
                printf("Vencedor: %s!\n", b.nome);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("Você escolheu: PIB\n");
            printf("%s: %.2f bilhões USD\n", a.nome, a.pib);
            printf("%s: %.2f bilhões USD\n", b.nome, b.pib);
            if (a.pib > b.pib)
                printf("Vencedor: %s!\n", a.nome);
            else if (a.pib < b.pib)
                printf("Vencedor: %s!\n", b.nome);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("Você escolheu: Pontos Turísticos\n");
            printf("%s: %d pontos\n", a.nome, a.pontos_turisticos);
            printf("%s: %d pontos\n", b.nome, b.pontos_turisticos);
            if (a.pontos_turisticos > b.pontos_turisticos)
                printf("Vencedor: %s!\n", a.nome);
            else if (a.pontos_turisticos < b.pontos_turisticos)
                printf("Vencedor: %s!\n", b.nome);
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("Você escolheu: Densidade Demográfica (vence o menor)\n");
            printf("%s: %.2f hab/km2\n", a.nome, a.densidade);
            printf("%s: %.2f hab/km2\n", b.nome, b.densidade);
            if (a.densidade < b.densidade) {
                printf("Vencedor: %s!\n", a.nome);
            } else if (a.densidade > b.densidade) {
                printf("Vencedor: %s!\n", b.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Opção inválida! Por favor, escolha um número válido do menu.\n");
    }
}

int main() {
    // Exemplo de cadastro de cartas (poderia vir de um arquivo ou cadastro anterior)
    CartaPais carta1 = {"Brasil", 213000000, 8515767.0, 2055.0, 25, 25.0};
    CartaPais carta2 = {"Portugal", 10300000, 92212.0, 238.0, 12, 112.0};

    int opcao;

    printf("=== SUPER TRUNFO DE PAÍSES ===\n");
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("\nCarta 2:\n");
    exibirCarta(carta2);
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Sua opção: ");
    scanf("%d", &opcao);

    compararCartas(carta1, carta2, opcao);

    printf("\nObrigado por jogar!\n");
    return 0;
}