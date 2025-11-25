# Hands-on 4: Analizador Léxico

## Integrante
- Ángel Manuel Ramírez Arceo

## Descripción
Analizador léxico simple que reconoce tokens básicos de C

## Instrucciones
1. flex lexer.l
2. gcc lex.yy.c -o lexer -lfl
3. ./lexer input.c