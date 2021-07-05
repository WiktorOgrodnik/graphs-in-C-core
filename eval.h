#ifndef EVAL_H
#define EVAL_H

#include "parse.h"

double eval (Expr* expression, double xValue, int* error, char* message);

#endif