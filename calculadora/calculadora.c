#include <stdio.h>

int main() {

	float num1, num2, resultado;

	char operador;

	printf("Digite o primeiro numero: ");
	scanf("%f", &num1);

	printf("Digite o segundo numero: ");
	scanf("%f", &num2);

	printf("Digite o operador (+, -, *, /): ");
	scanf(" %c", &operador);

	switch(operador) {
		case '+':
			resultado = num1 + num2;
			break;
		case '-':
			resultado = num1 - num2;
			break;
		case '*':
			resultado = num1 * num2;
			break;
		case '/':
			if (num2 != 0) {
				resultado = num1 / num2;
			} else {
				printf("Erro: divisao por zero nao permitida.\n");
				return 1;
			}
			break;
		default:
			printf("Operador invalido!");
			return 1;
	}

	printf("Resultado: %.2f\n", resultado);

	return 0;

}
