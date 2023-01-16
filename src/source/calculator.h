#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCORRECT_EXPRESSION 1
#define CALCULATION_ERROR 1

typedef struct stack {
  double data;
  struct stack* next;
} Stack;

int compute(const char* str, char* str_result, double x);

// Функции для стека.
void push(Stack** top, double oper);
double pop(Stack** top);
int is_empty(Stack const* top);

// Функции для парсера.
void replace_str(char* str);
int is_function(char func);
int is_operator(char symbol);
int get_priority(char oper);
int count_bracket(char* str);
int to_postfix(char* str, char* result);

// Результат.
void calculate(char op, double a, double b, double* result);
int get_result(char* str, double* result, double x);

#endif  // CALCULATOR_H
