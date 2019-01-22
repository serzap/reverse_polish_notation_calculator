#include "calculator.hpp"

enum StackState{Empty, OneOperandEntered, TwoOperandsEntered, OperationEntered, Invalid};

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::stringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

double calculateExpression(const std::string & expr)
{
    auto tokens = split(expr, ' ');
    std::string operation = "";
    double operand1 = 0.0;
    double operand2 = 0.0;
    double res = 0.0;
    StackState state = StackState::Empty;

    for (auto token = tokens.begin(); token != tokens.end(); ++token)
    {
        if(true == isOperand(*token))
        {
            operation = *token;
            state = StackState::OperationEntered;
        }

        if(StackState::Empty == state)
        {
            operand1 = std::stod(*token);
            state = StackState::OneOperandEntered;
        }
        else if (StackState::OneOperandEntered == state)
        {
            operand2 = std::stod(*token);
            state = StackState::TwoOperandsEntered;
        }
        else if (StackState::OperationEntered)
        {
            res = calculateOperation(operand1, operand2, operation);
            operand1 = res;
            operand2 = 0.0;
            state = StackState::OneOperandEntered;
        }
    }
    return res;
}

bool isOperand(const std::string & operand)
{
    return ("+" == operand || "-" == operand || "*" == operand || "/" == operand);
}

double calculateOperation(double operand1, double operand2, const std::string& operation)
{
    double res = 0.0;
    if ("+" == operation)
    {
        res = operand1 + operand2;
    }
    else if("-" == operation)
    {
        res = operand1 - operand2;
    }
    else if("*" == operation)
    {
        res = operand1 * operand2;
    }
    else if("/" == operation)
    {
        res = operand1 / operand2;
    }
}

