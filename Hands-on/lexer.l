%{
#include <stdio.h>
%}

%%

"int"       { printf("PALABRA_RESERVADA: int\n"); }
"return"    { printf("PALABRA_RESERVADA: return\n"); }
"include"   { printf("PALABRA_RESERVADA: include\n"); }
"define"    { printf("PALABRA_RESERVADA: define\n"); }

[a-zA-Z][a-zA-Z0-9]* { printf("IDENTIFICADOR: %s\n", yytext); }
[0-9]+      { printf("NUMERO: %s\n", yytext); }

"+"         { printf("OPERADOR: +\n"); }
"-"         { printf("OPERADOR: -\n"); }
"*"         { printf("OPERADOR: *\n"); }
"="         { printf("OPERADOR: =\n"); }

"("         { printf("DELIMITADOR: (\n"); }
")"         { printf("DELIMITADOR: )\n"); }
"{"         { printf("DELIMITADOR: {\n"); }
"}"         { printf("DELIMITADOR: }\n"); }
";"         { printf("DELIMITADOR: ;\n"); }

[ \t\n]     ; /* ignorar espacios */
.           { printf("DESCONOCIDO: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}