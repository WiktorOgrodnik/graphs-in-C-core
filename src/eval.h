#ifndef EVAL_CORE_H
#define EVAL_CORE_H

#include "parse.h"

// Evaluate expression in point xValue
double eval(Expr* expression, double xValue, int* error, char* message);

#endif