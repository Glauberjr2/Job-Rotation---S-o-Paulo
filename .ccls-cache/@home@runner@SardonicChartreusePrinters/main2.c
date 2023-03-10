#include <stdio.h>

int main()
{
    float sp = 67836.43;
    float rj = 36678.66;
    float mg = 29229.88;
    float es = 27165.48;
    float outros = 19849.53;
    float total = sp + rj + mg + es + outros;

    printf("Percentual por estado:\n");
    printf("SP: %.2f%%\n", (sp / total) * 100);
    printf("RJ: %.2f%%\n", (rj / total) * 100);
    printf("MG: %.2f%%\n", (mg / total) * 100);
    printf("ES: %.2f%%\n", (es / total) * 100);
    printf("Outros: %.2f%%\n", (outros / total) * 100);

    return 0;
}