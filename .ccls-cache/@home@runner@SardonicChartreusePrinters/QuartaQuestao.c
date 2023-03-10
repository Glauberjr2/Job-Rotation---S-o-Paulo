#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int i, j, tamanho;
    char t;

    printf("Digite uma string: ");
    scanf("%s", string);

    tamanho = strlen(string);

    for (i = 0, j = tamanho - 1; i < j; i++, j--)
    {
        t = string[i];
        string[i] = string[j];
        string[j] = t;
    }

    printf("A string invertida eh: %s", string);

    return 0;
}
