#include <stdio.h>

int main() {
    int n, i, num;
    int fib[100]; // array para armazenar os números da sequência

    // solicita a quantidade de termos da sequência
    printf("Digite o número de termos da sequência de Fibonacci: ");
    scanf("%d", &n);

    // verifica se o número de termos é válido
    if (n < 1 || n > 100) {
        printf("Número inválido de termos.");
        return 1;
    }

    // gera os termos da sequência
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // solicita o número ao usuário
    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    // verifica se o número está presente na sequência de Fibonacci
    for (i = 0; i < n; i++) {
        if (fib[i] == num) {
            printf("%d faz parte da sequência de Fibonacci.", num);
            return 0;
        }
    }

    // se o número não estiver presente na sequência
    printf("%d não faz parte da sequência de Fibonacci.", num);

    return 0;
}


  