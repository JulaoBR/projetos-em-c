#include <stdio.h>
#include <string.h>

#define MAX_HISTORICO 100

int main() {

	float num1, num2, resultado;
	int opcao;

	char historico[MAX_HISTORICO][100];
	int totalHistorico = 0;

	do {

		printf("\n==== CALCULADORA ====\n");
		printf("1 - Adição\n");
		printf("2 - Subtração\n");
		printf("3 - Multiplicação\n");
		printf("4 - Divisão\n");
		printf("5 - Ver historico\n");
		printf("0 - Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);

		if (opcao == 0) {
			printf("Saindo...\n");
			break;
		}

		if (opcao == 5) {
			printf("\n--- Historico de Cálculos ---\n");
			if (totalHistorico == 0) {
				printf("Nenhum cálculo realizado ainda.\n");
			} else {
				for (int i = 0; i < totalHistorico; i++) {
					printf("%s\n", historico[i]);
				}
			}
			continue;
		}

		printf("Digite o primeiro numero: ");
		scanf("%f", &num1);

		printf("Digite o segundo numero: ");
		scanf("%f", &num2);

		char linha[100];

		switch(opcao) {
			case 1:
				resultado = num1 + num2;
				snprintf(linha, sizeof(linha), "%.2f + %.2f = %.2f", num1, num2, resultado);
				break;
			case 2:
				resultado = num1 - num2;
				snprintf(linha, sizeof(linha), "%.2f - %.2f = %.2f", num1, num2, resultado);
				break;
			case 3:
				resultado = num1 * num2;
				snprintf(linha, sizeof(linha), "%.2f * %.2f = %.2f", num1, num2, resultado);
				break;
			case 4:
				if (num2 != 0) {
					resultado = num1 / num2;
					snprintf(linha, sizeof(linha), "%.2f / %.2f = %.2f", num1, num2, resultado);
				} else {
					printf("Erro: divisao por zero nao permitida.\n");
					snprintf(linha, sizeof(linha), "%.2f / %.2f = ERRO (divisao por zero)", num1, num2);
				}
				break;
			default:
				printf("Operador invalido!\n");
		}

		if (totalHistorico < MAX_HISTORICO) {
			strcpy(historico[totalHistorico], linha);
			totalHistorico++;
		}

		if (resultado > 0) {
			printf("Resultado: %.2f\n", resultado);
		}

	} while (1);

	return 0;
}
