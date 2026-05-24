#include <stdio.h>

int main(void) {
    
    int adultos;
    int idosos;
    int criancas_e_adolecentes;
    int criancas_menores;

    // Pontos de alimentacao
    float pontos_adultos = 1.5;
    float pontos_idosos = 1.0;
    float pontos_criancas_e_adolecentes = 0.8;
    float pontos_criancas_menores = 0.3;

    int diabetico;
    int celiaco;
    
    float pontos_familia;
    
    int latas_leite = 0;
    
    // Cotas pre-calculadas no inicio do dia
    // Cada ponto da direito a 2kg de arroz e 1kg de feijao
    float cota_arroz = 2.0; 
    float cota_feijao = 1.0;

    float total_arroz;
    float total_feijao;

    printf("=== Sistema Cesta Justa - Centro Comunitario ===\n\n");

    printf("--- Composicao da Familia ---\n");
    printf("-- Adultos\n-- Idosos\n-- Crianças e/ou adolecentes\n-- Crianças menores que 2 anos\n\n");

    printf("Numero de adultos: ");
    scanf("%d", &adultos);

    printf("Numero de idosos: ");
    scanf("%d", &idosos);

    printf("Numero de criancas e/ou adolecentes: ");
    scanf("%d", &criancas_e_adolecentes);

    printf("Numero de criancas menores de 2 anos: ");
    scanf("%d", &criancas_menores);

    printf("\n--- Restricoes Alimentares ---\n");

    printf("Alguem possui Diabetes? (1-Sim / 0-Nao): ");
    scanf("%d", &diabetico);

    printf("Alguem possui Doenca Celiaca? (1-Sim / 0-Nao): ");
    scanf("%d", &celiaco);

    // Processamento - Calculo dos pontos de alimentacao
    pontos_familia =
            (adultos * pontos_adultos) 
        +   (idosos * pontos_idosos)
        +   (criancas_menores * pontos_criancas_menores)
        +   (criancas_e_adolecentes * pontos_criancas_e_adolecentes);

    // Processamento - Calculo dos alimentos basicos
    total_arroz = pontos_familia * cota_arroz;
    total_feijao = pontos_familia * cota_feijao;

    // Condicional - Regra de prioridade do leite, 1 lata por crianca
    if (criancas_menores > 0) {
        latas_leite = criancas_menores * 1;
    }

    // Saida - Resultados e Montagem da Cesta
    printf("\n=== RESUMO DA DISTRIBUICAO ===\n");
    printf("Pontos totais da familia: %.2f\n", pontos_familia);
    printf("-> Arroz: %.2f kg\n", total_arroz);
    printf("-> Feijao: %.2f kg\n", total_feijao);
    
    if (latas_leite > 0) {
        printf("-> Leite em po: %d lata(s) (Prioridade infantil garantida)\n", latas_leite);
    } else {
        printf("-> Leite em po: 0 lata(s)\n");
    }

    // Condicional - Alertas para troca de itens devido a saude
    if (diabetico == 1) {
        printf("\n[ALERTA DE SAUDE] Substituir doces/acucar por itens DIET/ZERO.\n");
    }
    
    if (celiaco == 1) {
        printf("[ALERTA DE SAUDE] Substituir massas comuns por macarrao SEM GLUTEN.\n");
    }

    printf("\nDistribuicao calculada com sucesso!\n");

    return 0;
}