#include <stdio.h>
#include <string.h>

#define QTD_CARTAS 3
#define QTD_ATRIBUTOS 5

typedef struct {
    char nome[30];
    int populacao;         // milhões
    int area;              // mil km²
    int pib;               // bilhões USD
    int idh;               // 0-1000 (IDH*1000)
    int densidade;         // hab/km²
} Carta;

// Função para mostrar os atributos disponíveis
void mostrarAtributos(int ocultar) {
    printf("\nEscolha o atributo:\n");
    if (ocultar != 1) printf("1. População\n");
    if (ocultar != 2) printf("2. Área\n");
    if (ocultar != 3) printf("3. PIB\n");
    if (ocultar != 4) printf("4. IDH\n");
    if (ocultar != 5) printf("5. Densidade Demográfica\n");
}

// Função para obter o valor do atributo da carta
int obterAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.idh;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Função para mostrar o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População (milhões)";
        case 2: return "Área (mil km²)";
        case 3: return "PIB (bi USD)";
        case 4: return "IDH (x1000)";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Pré-cadastro de cartas
    Carta cartas[QTD_CARTAS] = {
        {"Brasil", 214, 8516, 1868, 765, 25},
        {"Alemanha", 83, 357, 3845, 942, 232},
        {"Austrália", 26, 7692, 1393, 944, 3}
    };

    int idx1, idx2;
    int atributo1 = 0, atributo2 = 0;
    int soma1, soma2;
    int valor1_att1, valor2_att1, valor1_att2, valor2_att2;

    printf("=== SUPER TRUNFO DE PAISES ===\n\n");

    // Escolha das cartas
    printf("Cartas disponíveis:\n");
    for (int i = 0; i < QTD_CARTAS; i++) {
        printf("%d. %s\n", i+1, cartas[i].nome);
    }

    // Escolha da primeira carta
    do {
        printf("\nEscolha o número da primeira carta: ");
        if (scanf("%d", &idx1) != 1) {
            while(getchar()!='\n'); // limpa buffer
            idx1 = 0;
        }
        if (idx1 < 1 || idx1 > QTD_CARTAS)
            printf("Opção inválida.\n");
    } while (idx1 < 1 || idx1 > QTD_CARTAS);

    // Escolha da segunda carta
    do {
        printf("Escolha o número da segunda carta: ");
        if (scanf("%d", &idx2) != 1) {
            while(getchar()!='\n'); // limpa buffer
            idx2 = 0;
        }
        if (idx2 < 1 || idx2 > QTD_CARTAS || idx2 == idx1)
            printf("Opção inválida ou igual à primeira carta.\n");
    } while (idx2 < 1 || idx2 > QTD_CARTAS || idx2 == idx1);

    // Escolha dos dois atributos
    do {
        mostrarAtributos(0);
        printf("Selecione o primeiro atributo (1-5): ");
        if (scanf("%d", &atributo1) != 1) {
            while(getchar()!='\n');
            atributo1 = 0;
        }
        if (atributo1 < 1 || atributo1 > QTD_ATRIBUTOS)
            printf("Atributo inválido.\n");
    } while (atributo1 < 1 || atributo1 > QTD_ATRIBUTOS);

    do {
        mostrarAtributos(atributo1);
        printf("Selecione o segundo atributo (1-5), diferente do primeiro: ");
        if (scanf("%d", &atributo2) != 1) {
            while(getchar()!='\n');
            atributo2 = 0;
        }
        if (atributo2 < 1 || atributo2 > QTD_ATRIBUTOS || atributo2 == atributo1)
            printf("Atributo inválido ou repetido.\n");
    } while (atributo2 < 1 || atributo2 > QTD_ATRIBUTOS || atributo2 == atributo1);

    // Comparação dos atributos
    valor1_att1 = obterAtributo(cartas[idx1-1], atributo1);
    valor2_att1 = obterAtributo(cartas[idx2-1], atributo1);

    valor1_att2 = obterAtributo(cartas[idx1-1], atributo2);
    valor2_att2 = obterAtributo(cartas[idx2-1], atributo2);

    // Exibir atributos e valores
    printf("\n--- Comparação ---\n");
    printf("Carta 1: %s\n", cartas[idx1-1].nome);
    printf("Carta 2: %s\n", cartas[idx2-1].nome);

    printf("\n%-25s | %-10s | %-10s\n", "Atributo", cartas[idx1-1].nome, cartas[idx2-1].nome);
    printf("%-25s | %-10d | %-10d\n", nomeAtributo(atributo1), valor1_att1, valor2_att1);
    printf("%-25s | %-10d | %-10d\n", nomeAtributo(atributo2), valor1_att2, valor2_att2);

    // Critério de vitória por atributo
    int vitoria_att1 = (atributo1 == 5) ? // Densidade: menor vence
        (valor1_att1 < valor2_att1 ? 1 : (valor1_att1 > valor2_att1 ? 2 : 0)) :
        (valor1_att1 > valor2_att1 ? 1 : (valor1_att1 < valor2_att1 ? 2 : 0));

    int vitoria_att2 = (atributo2 == 5) ? // Densidade: menor vence
        (valor1_att2 < valor2_att2 ? 1 : (valor1_att2 > valor2_att2 ? 2 : 0)) :
        (valor1_att2 > valor2_att2 ? 1 : (valor1_att2 < valor2_att2 ? 2 : 0));

    printf("\nResultado por atributo:\n");
    printf("%s: %s\n", nomeAtributo(atributo1), vitoria_att1==1 ? cartas[idx1-1].nome : (vitoria_att1==2 ? cartas[idx2-1].nome : "Empate"));
    printf("%s: %s\n", nomeAtributo(atributo2), vitoria_att2==1 ? cartas[idx1-1].nome : (vitoria_att2==2 ? cartas[idx2-1].nome : "Empate"));

    // Soma dos atributos
    soma1 = valor1_att1 + valor1_att2;
    soma2 = valor2_att1 + valor2_att2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %d\n", cartas[idx1-1].nome, soma1);
    printf("%s: %d\n", cartas[idx2-1].nome, soma2);

    printf("\n*** Resultado final: ");
    if (soma1 > soma2)
        printf("%s venceu a rodada! ***\n", cartas[idx1-1].nome);
    else if (soma2 > soma1)
        printf("%s venceu a rodada! ***\n", cartas[idx2-1].nome);
    else
        printf("Empate! ***\n");

    printf("\nObrigado por jogar Super Trunfo dos Países!\n");

    return 0;
}