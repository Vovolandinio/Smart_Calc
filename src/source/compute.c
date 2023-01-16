#include "calculator.h"

int compute(const char* str_const, char* str_result, double x) {
  char str[225];
  sprintf(str, "%s", str_const);
  char reverse_order[100];
  int error = 0;

  if ((error = to_postfix(str, reverse_order)) == INCORRECT_EXPRESSION) {
    sprintf(str_result, "%s", "Incorrect expression");
  } else {
    double result;
    if ((error = get_result(reverse_order, &result, x)) == CALCULATION_ERROR) {
      sprintf(str_result, "%s", "Incorrect expression");
    } else {
      sprintf(str_result, "%0.7f", result);
    }
  }

  return error;
}
