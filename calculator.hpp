#ifndef CALCULATOR_HPP
#define CALCUALTOR_HPP

#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <regex>
#include "stdlib.h"

enum StackState{WaitingFirstOperand, WaitingSecondOperand, WaitingOperation, ReadyToCalculate, Invalid};
enum Error{NoError, DivideByZero, EmptyString, WrongOperand, WrongOperation};
typedef struct{double value; Error error;} Result;

std::vector<std::string> parse(const std::string& s, char delimiter);

Result calculateExpression(const std::string & expr);
Result calculateOperation(double operand1, double operand2, const std::string& operation);

bool isValidOperation(const std::string & operation);
bool isValidOperand(const std::string & operand);

#endif
