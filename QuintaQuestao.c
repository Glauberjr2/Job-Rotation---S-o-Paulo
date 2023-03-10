#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

int main() {
  FILE *f = fopen("faturamento.json", "r");
  if (!f) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  char buffer[1024];
  struct json_object *json;
  fread(buffer, sizeof(char), 1024, f);
  fclose(f);

  json = json_tokener_parse(buffer);

  struct json_object *faturamento_diario;
  json_object_object_get_ex(json, "faturamento_diario", &faturamento_diario);

  double menor = 0, maior = 0;
  int i, n = json_object_array_length(faturamento_diario);
  for (i = 0; i < n; i++) {
    struct json_object *item = json_object_array_get_idx(faturamento_diario, i);
    struct json_object *valor_json;
    json_object_object_get_ex(item, "valor", &valor_json);
    double valor = json_object_get_double(valor_json);
    if (i == 0 || valor < menor) menor = valor;
    if (i == 0 || valor > maior) maior = valor;
  }
  printf("Menor valor de faturamento diário: %.2f\n", menor);
  printf("Maior valor de faturamento diário: %.2f\n", maior);

  double soma = 0;
  int count = 0;
  for (i = 0; i < n; i++) {
    struct json_object *item = json_object_array_get_idx(faturamento_diario, i);
    struct json_object *valor_json;
    json_object_object_get_ex(item, "valor", &valor_json);
    double valor = json_object_get_double(valor_json);
    if (valor > 0) {
      soma += valor;
      count++;
    }
  }
  double media = soma / count;

  int acima_da_media = 0;
  for (i = 0; i < n; i++) {
    struct json_object *item = json_object_array_get_idx(faturamento_diario, i);
    struct json_object *valor_json;
    json_object_object_get_ex(item, "valor", &valor_json);
    double valor = json_object_get_double(valor_json);
    if (valor > media) acima_da_media++;
  }
  printf("Dias com faturamento diário acima da média mensal: %d\n", acima_da_media);

  return 0;
}
