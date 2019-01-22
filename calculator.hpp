#ifndef CALCULATOR_HPP
#define CALCUALTOR_HPP

#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include "stdlib.h"

std::vector<std::string> split(const std::string& s, char delimiter);
double calculateExpression(const std::string & expr);
bool isOperand(const std::string & operand);
double calculateOperation(double operand1, double operand2, const std::string& operation);

#endif
