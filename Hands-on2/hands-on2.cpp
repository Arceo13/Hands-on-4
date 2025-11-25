#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Función para validar que un valor sea alfanumérico y empiece con letra
int validarCadena(const char *s) {
    if (!isalpha(s[0])) return 0; 
    for (int i = 1; s[i]; i++) {
        if (!isalnum(s[i])) return 0;
    }
    return 1;
}

// DFA simplificado para validar un objeto JSON tipo {"firstName":"X","lastName":"Y"}
int validarObjeto(const char *s) {
    char first[50], last[50];
    if (sscanf(s, "{\"firstName\":\"%49[^\"]\",\"lastName\":\"%49[^\"]\"}", first, last) == 2) {
        return validarCadena(first) && validarCadena(last);
    }
    return 0;
}

// DFA general para validar el JSON de employees
int validarJSON(const char *json) {
    // El formato esperado es {"employees":[ {...}, {...}, ... ]}
    const char *ptr = json;

    // Validar comienzo {"employees":
    if (strncmp(ptr, "{\"employees\":[", 13) != 0) return 0;
    ptr += 13;

    // Iterar sobre objetos dentro del array
    while (*ptr) {
        char objeto[200];
        int n = 0;

        if (*ptr == ']') break; // fin del array
        if (*ptr == ',') ptr++; // separador entre objetos

        // Copiar objeto { ... }
        if (*ptr != '{') return 0;
        while (*ptr && *ptr != '}') objeto[n++] = *ptr++;
        if (*ptr == '}') objeto[n++] = *ptr++;
        objeto[n] = '\0';

        if (!validarObjeto(objeto)) return 0;
    }

    // Validar cierre final ]}
    if (strncmp(ptr, "]}", 2) == 0) return 1;
    return 0;
}

int main() {
    const char *json = "{\"employees\":["
                       "{\"firstName\":\"John\",\"lastName\":\"Doe\"},"
                       "{\"firstName\":\"Anna\",\"lastName\":\"Smith\"},"
                       "{\"firstName\":\"Peter\",\"lastName\":\"Jones\"}"
                       "]}";

    if (validarJSON(json)) {
        printf("JSON valido\n");
    } else {
        printf("JSON invalido\n");
    }
    return 0;
}
