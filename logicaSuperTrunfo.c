#include <stdio.h>

int main() {
    // Dados das cartas
    unsigned long populacao1, populacao2;
    int pontosTuristicos1, pontosTuristicos2;
    char estado1, estado2, codigo1[10], codigo2[10], nomeCidade1[100], nomeCidade2[100];
    double densidade1, densidade2, area1, area2, percap1, percap2, pib1, pib2;

    // Cadastro da Carta 1
    printf("---- Cadastro da Carta 1 ----\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta: ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%lf", &area1);
    printf("PIB (em bilhões): ");
    scanf("%lf", &pib1);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    densidade1 = area1 > 0 ? populacao1 / area1 : 0;
    percap1 = populacao1 > 0 ? (pib1 * 1e9) / populacao1 : 0;

    // Cadastro da Carta 2
    printf("\n---- Cadastro da Carta 2 ----\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta: ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%lf", &area2);
    printf("PIB (em bilhões): ");
    scanf("%lf", &pib2);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade2 = area2 > 0 ? populacao2 / area2 : 0;
    percap2 = populacao2 > 0 ? (pib2 * 1e9) / populacao2 : 0;

    // Menu dinâmico
    int atributo1, atributo2;
    printf("\n---- Menu de Atributos ----\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional (menor vence)\n6 - PIB per capita\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    int pontos1 = 0, pontos2 = 0;

    // Função de comparação
    for (int i = 0; i < 2; i++) {
        int escolha = (i == 0) ? atributo1 : atributo2;
        switch (escolha) {
            case 1:
                pontos1 += (populacao1 > populacao2) ? 1 : 0;
                pontos2 += (populacao2 > populacao1) ? 1 : 0;
                printf("População: %s\n", (populacao1 == populacao2) ? "Empate" : (populacao1 > populacao2 ? nomeCidade1 : nomeCidade2));
                break;
            case 2:
                pontos1 += (area1 > area2) ? 1 : 0;
                pontos2 += (area2 > area1) ? 1 : 0;
                printf("Área: %s\n", (area1 == area2) ? "Empate" : (area1 > area2 ? nomeCidade1 : nomeCidade2));
                break;
            case 3:
                pontos1 += (pib1 > pib2) ? 1 : 0;
                pontos2 += (pib2 > pib1) ? 1 : 0;
                printf("PIB: %s\n", (pib1 == pib2) ? "Empate" : (pib1 > pib2 ? nomeCidade1 : nomeCidade2));
                break;
            case 4:
                pontos1 += (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0;
                pontos2 += (pontosTuristicos2 > pontosTuristicos1) ? 1 : 0;
                printf("Pontos Turísticos: %s\n", (pontosTuristicos1 == pontosTuristicos2) ? "Empate" : (pontosTuristicos1 > pontosTuristicos2 ? nomeCidade1 : nomeCidade2));
                break;
            case 5:
                pontos1 += (densidade1 < densidade2) ? 1 : 0;
                pontos2 += (densidade2 < densidade1) ? 1 : 0;
                printf("Densidade Populacional: %s\n", (densidade1 == densidade2) ? "Empate" : (densidade1 < densidade2 ? nomeCidade1 : nomeCidade2));
                break;
            case 6:
                pontos1 += (percap1 > percap2) ? 1 : 0;
                pontos2 += (percap2 > percap1) ? 1 : 0;
                printf("PIB per capita: %s\n", (percap1 == percap2) ? "Empate" : (percap1 > percap2 ? nomeCidade1 : nomeCidade2));
                break;
            default:
                printf("Atributo inválido.\n");
        }
    }

    // Resultado final
    printf("\n---- Resultado Final ----\n");
    if (pontos1 > pontos2)
        printf("Vencedora: %s\n", nomeCidade1);
    else if (pontos2 > pontos1)
        printf("Vencedora: %s\n", nomeCidade2);
    else
        printf("Empate geral entre as cidades.\n");

    return 0;
}
