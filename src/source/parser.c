#include "calculator.h"

void replace_str(char* str) {
  char tmp[225];
  int k = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == 'c' && str[i + 1] == 'o') {
      tmp[k++] = 'c';
      i += 2;
    } else if (str[i] == 's' && str[i + 1] == 'i') {
      tmp[k++] = 's';
      i += 2;
    } else if (str[i] == 't' && str[i + 1] == 'a') {
      tmp[k++] = 't';
      i += 2;
    } else if (str[i] == 'a' && str[i + 1] == 'c') {
      tmp[k++] = 'a';
      i += 3;
    } else if (str[i] == 'a' && str[i + 1] == 's') {
      tmp[k++] = 'b';
      i += 3;
    } else if (str[i] == 'a' && str[i + 1] == 't') {
      tmp[k++] = 'd';
      i += 3;
    } else if (str[i] == 's' && str[i + 1] == 'q') {
      tmp[k++] = 'q';
      i += 3;
    } else if (str[i] == 'l' && str[i + 1] == 'n') {
      tmp[k++] = 'l';
      i += 2;
    } else if (str[i] == 'l' && str[i + 1] == 'o') {
      tmp[k++] = 'g';
      i += 2;
    } else if (str[i] == 'm' && str[i + 1] == 'o') {
      tmp[k++] = '%';
      i += 2;
    } else if (str[i] == '+' &&
               (i == 0 || str[i - 1] == '(' || is_operator(str[i - 1]))) {
      tmp[k++] = '@';
    } else if (str[i] == '-' &&
               (i == 0 || str[i - 1] == '(' || is_operator(str[i - 1]))) {
      tmp[k++] = '~';
    } else {
      tmp[k++] = str[i];
    }
  }
  tmp[k++] = '\0';
  sprintf(str, "%s", tmp);
}

int is_function(char op) {
  int is_function = 0;
  if (op == 'c' || op == 's' || op == 't' || op == 'a' || op == 'b' ||
      op == 'd' || op == 'q' || op == 'l' || op == 'g') {
    is_function = 1;
  }
  return is_function;
}

int is_operator(char symbol) {
  int is_op = 0;
  if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
      symbol == '^' || symbol == '%' || symbol == '@' || symbol == '~') {
    is_op = 1;
  }
  return is_op;
}

int get_priority(char operator) {
  int priority = -2;
  if (operator== '+' || operator== '-') {
    priority = 0;
  } else if (operator== '*' || operator== '/' || operator== '%') {
    priority = 1;
  } else if (operator== '^') {
    priority = 3;
  } else if (operator== '~' || operator== '@') {
    priority = 2;
  } else if (operator== '(') {
    priority = -1;
  }
  return priority;
}

int count_bracket(char* str) {
  int count_op = 0, count_cl = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == '(') count_op++;
    if (str[i] == ')') count_cl++;
  }
  return count_cl != count_op;
}

int to_postfix(char* str, char* result) {
  int error = 0;
  error = count_bracket(str);
  replace_str(str);
  Stack* st = NULL;
  size_t k = 0;
  size_t len_str = strlen(str);

  for (size_t i = 0; i < len_str && error == 0; i++) {
    if (isdigit(str[i]) || str[i] == 'x' || str[i] == '.') {
      result[k++] = str[i];
      if (i == len_str - 1 || (!isdigit(str[i + 1]) && str[i + 1] != '.'))
        result[k++] = ' ';
    } else if (str[i] == '(' || is_function(str[i])) {
      push(&st, str[i]);
    } else if (is_operator(str[i])) {
      char op = str[i], op2;
      while (!is_empty(st) && (op2 = pop(&st))) {
        if (get_priority(op2) >= get_priority(op)) {
          result[k++] = op2;
          result[k++] = ' ';
        } else {
          push(&st, op2);
          break;
        }
      }
      push(&st, op);
    } else if (str[i] == ')') {
      char top;
      if (str[i - 1] == '(') {
        error = INCORRECT_EXPRESSION;
        break;
      }
      while (!is_empty(st) && (top = pop(&st)) != '(') {
        result[k++] = top;
        result[k++] = ' ';
      }
      if (!is_empty(st)) {
        top = pop(&st);
        if (is_function(top)) {
          result[k++] = top;
          result[k++] = ' ';
        } else {
          push(&st, top);
        }
      }
    }
  }

  while (!is_empty(st) && !error) {
    char op = pop(&st);
    if ((op == '(' || op == ')')) {
      error = INCORRECT_EXPRESSION;
    }
    result[k++] = op;
    result[k++] = ' ';
  }
  result[k] = '\0';

  return error;
}
