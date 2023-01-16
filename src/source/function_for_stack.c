#include "calculator.h"

void push(Stack** top, double oper) {
  if (top != NULL) {
    Stack* up = malloc(sizeof(Stack));
    if (up != NULL) {
      up->data = oper;
      up->next = *top;
      *top = up;
    } else {
      printf("Error malloc");
    }
  }
}

double pop(Stack** top) {
  Stack* temp = *top;
  double operator=(*top)->data;
  *top = (*top)->next;
  free(temp);

  return operator;
}

int is_empty(Stack const* top) { return top == NULL; }
