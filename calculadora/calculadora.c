#include <stdio.h>

int main() {

	float num1, num2, resultado;
	int opcao;

	do {

		printf("\n==== CALCULADORA ====\n");
		printf("1 - Adição\n");
		printf("2 - Subtração\n");
		printf("3 - Multiplicação\n");
		printf("4 - Divisão\n");
		printf("0 - Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);

		if (opcao == 0) {
			printf("Saindo...\n");
			break;
		}

		printf("Digite o primeiro numero: ");
		scanf("%f", &num1);

		printf("Digite o segundo numero: ");
		scanf("%f", &num2);

		switch(opcao) {
			case 1:
				resultado = num1 + num2;
				break;
			case 2:
				resultado = num1 - num2;
				break;
			case 3:
				resultado = num1 * num2;
				break;
			case 4:
				if (num2 != 0) {
					resultado = num1 / num2;
				} else {
					printf("Erro: divisao por zero nao permitida.\n");
				}
				break;
			default:
				printf("Operador invalido!\n");
		}

		if (resultado > 0) {
			printf("Resultado: %.2f\n", resultado);
		}

	} while (1);

	return 0;
}
