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

    // Menu de comparação
    int opcao;
    printf("\n---- Menu de Comparação ----\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per capita\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n---- Resultado da Comparação ----\n");

    switch (opcao) {
        case 1:
            if (populacao1 > populacao2)
                printf("%s venceu com maior população.\n", nomeCidade1);
            else if (populacao2 > populacao1)
                printf("%s venceu com maior população.\n", nomeCidade2);
            else
                printf("Empate: ambas têm a mesma população.\n");
            break;

        case 2:
            if (area1 > area2)
                printf("%s venceu com maior área.\n", nomeCidade1);
            else if (area2 > area1)
                printf("%s venceu com maior área.\n", nomeCidade2);
            else
                printf("Empate: ambas têm a mesma área.\n");
            break;

        case 3:
            if (pib1 > pib2)
                printf("%s venceu com maior PIB.\n", nomeCidade1);
            else if (pib2 > pib1)
                printf("%s venceu com maior PIB.\n", nomeCidade2);
            else
                printf("Empate: ambas têm o mesmo PIB.\n");
            break;

        case 4:
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("%s venceu com mais pontos turísticos.\n", nomeCidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("%s venceu com mais pontos turísticos.\n", nomeCidade2);
            else
                printf("Empate: ambas têm o mesmo número de pontos turísticos.\n");
            break;

        case 5:
            if (densidade1 < densidade2)
                printf("%s venceu com menor densidade populacional.\n", nomeCidade1);
            else if (densidade2 < densidade1)
                printf("%s venceu com menor densidade populacional.\n", nomeCidade2);
            else
                printf("Empate: ambas têm a mesma densidade populacional.\n");
            break;

        case 6:
            if (percap1 > percap2)
                printf("%s venceu com maior PIB per capita.\n", nomeCidade1);
            else if (percap2 > percap1)
                printf("%s venceu com maior PIB per capita.\n", nomeCidade2);
            else
                printf("Empate: ambas têm o mesmo PIB per capita.\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
    }

    return 0;
}
