#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    unsigned long populacao1, populacao2;
    int pontosTuristicos1, pontosTuristicos2;
    char estado1, estado2, codigo1[10], codigo2[10], nomeCidade1[100], nomeCidade2[100];
    double densidade1, densidade2,area1, area2, percap1, percap2, superPoder1, superPoder2, pib1, pib2;

    printf("-----------------------Cadastre a primeira carta-----------------------\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    //espaço antes do %[^\n] ignora espaços ou quebras de linha = 
    //%[^\n] significa: leia todos os caracteres até encontrar uma nova linha
    scanf(" %[^\n]", nomeCidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km²): ");
    scanf("%lf", &area1);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);
    
   if (area1 > 0.0) {
        densidade1 = (double)populacao1 / area1;
    } else {
        densidade1 = 0.0;
        printf("Aviso: Área da Carta 1 é zero, densidade populacional não calculada.\n");
    }

    if (populacao1 > 0) {
        percap1 = (pib1 * 1000000000.0) / populacao1;
    } else {
        percap1 = 0.0;
        printf("Aviso: População da Carta 1 é zero, PIB per capita não calculado.\n");
    }

    if (densidade1 > 0.0) {
        superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + (1.0 / densidade1) + percap1 ;
    } else {
        superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + percap1;
        printf("Aviso: Densidade da Carta 1 é zero, inverso não incluído no Super Poder.\n");
    }

    printf("Super Poder da Carta 1: %.2lf\n", superPoder1); 

    // Segunda carta
    printf("-----------------------Cadastre a segunda carta-----------------------\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km²): ");
    scanf("%lf", &area2);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

     if (area2 > 0.0) {
        densidade2 = (double)populacao2 / area2;
    } else {
        densidade2 = 0.0;
        printf("Aviso: Área da Carta 2 é zero, densidade populacional não calculada.\n");
    }

    if (populacao2 > 0) {
        percap2 = (pib2 * 1000000000.0) / populacao2;
    } else {
        percap2 = 0.0;
        printf("Aviso: População da Carta 2 é zero, PIB per capita não calculado.\n");
    }

    if (densidade2 > 0.0) {
        superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + (1.0 / densidade2) + percap2;
    } else {
        superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2  + percap2;
        printf("Aviso: Densidade da Carta 2 é zero, inverso não incluído no Super Poder.\n");
    } 

    printf("Super Poder da Carta 2: %.2lf\n", superPoder2);

    printf("----------------------- Carta 1-----------------------\n"); 
    printf("Estado: %c\n", estado1); 
    printf("Codigo: %s\n", codigo1); 
    printf("Cidade: %s\n", nomeCidade1); 
    printf("Populacao: %lu habitantes\n", populacao1); 
    printf("Area: %.2lf km²\n", area1); 
    printf("PIB: %.2lf bilhoes de reais\n", pib1); 
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2lf hab/km²\n", densidade1);
    printf("PIB per capita: %.2lf por habitante\n", percap1); 
    printf("----------------------- Carta 2 -----------------------\n"); 
    printf("Estado: %c\n", estado2); 
    printf("Codigo: %s\n", codigo2); 
    printf("Nome da Cidade: %s\n", nomeCidade2); 
    printf("Populacao: %lu\n", populacao2); 
    printf("Area: %.2lf km²\n", area2); 
    printf("PIB: %.2lf bilhoes de reais\n", pib2); 
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2lf hab/km²\n", densidade2);
    printf("PIB per capita: %.2lf por habitante\n", percap2);

 printf("\n--------------------- Comparação Final das Cartas ---------------------\n");

    int pontosCarta1 = 0, pontosCarta2 = 0;

    // População
    if (populacao1 > populacao2) {
        printf("%s tem maior população.\n", nomeCidade1);
        pontosCarta1++;
    } else if (populacao2 > populacao1) {
        printf("%s tem maior população.\n", nomeCidade2);
        pontosCarta2++;
    } else {
        printf("As duas cidades têm a mesma população.\n");
    }

    // Área
    if (area1 > area2) {
        printf("%s tem maior área territorial.\n", nomeCidade1);
        pontosCarta1++;
    } else if (area2 > area1) {
        printf("%s tem maior área territorial.\n", nomeCidade2);
        pontosCarta2++;
    } else {
        printf("As duas cidades têm a mesma área territorial.\n");
    }

    // PIB
    if (pib1 > pib2) {
        printf("%s tem PIB mais alto.\n", nomeCidade1);
        pontosCarta1++;
    } else if (pib2 > pib1) {
        printf("%s tem PIB mais alto.\n", nomeCidade2);
        pontosCarta2++;
    } else {
        printf("As duas cidades têm o mesmo PIB.\n");
    }

    // Pontos Turísticos
    if (pontosTuristicos1 > pontosTuristicos2) {
        printf("%s tem mais pontos turísticos.\n", nomeCidade1);
        pontosCarta1++;
    } else if (pontosTuristicos2 > pontosTuristicos1) {
        printf("%s tem mais pontos turísticos.\n", nomeCidade2);
        pontosCarta2++;
    } else {
        printf("As duas cidades têm o mesmo número de pontos turísticos.\n");
    }

    // Densidade Populacional (menor vence)
    if (densidade1 < densidade2) {
        printf("%s tem menor densidade populacional.\n", nomeCidade1);
        pontosCarta1++;
    } else if (densidade2 < densidade1) {
        printf("%s tem menor densidade populacional.\n", nomeCidade2);
        pontosCarta2++;
    } else {
        printf("As duas cidades têm a mesma densidade populacional.\n");
    }

    // PIB per capita
    if (percap1 > percap2) {
        printf("%s tem PIB per capita mais alto.\n", nomeCidade1);
        pontosCarta1++;
    } else if (percap2 > percap1) {
        printf("%s tem PIB per capita mais alto.\n", nomeCidade2);
        pontosCarta2++;
    } else {
        printf("As duas cidades têm o mesmo PIB per capita.\n");
    }

    // Super Poder
    if (superPoder1 > superPoder2) {
        printf("%s tem o Super Poder mais alto.\n", nomeCidade1);
        pontosCarta1++;
    } else if (superPoder2 > superPoder1) {
        printf("%s tem o Super Poder mais alto.\n", nomeCidade2);
        pontosCarta2++;
    } else {
        printf("As duas cidades têm o mesmo Super Poder.\n");
    }

    printf("\n--------------------- Resultado Geral ---------------------\n");
    printf("%s venceu %d atributos.\n", nomeCidade1, pontosCarta1);
    printf("%s venceu %d atributos.\n", nomeCidade2, pontosCarta2);

    if (pontosCarta1 > pontosCarta2) {
        printf("A cidade vencedora é: %s\n", nomeCidade1);
    } else if (pontosCarta2 > pontosCarta1) {
        printf("A cidade vencedora é: %s\n", nomeCidade2);
    } else {
        printf("As cidades empataram na comparação geral.\n");
    }
}
