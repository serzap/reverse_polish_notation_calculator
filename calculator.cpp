#include "calculator.hpp"

std::vector<std::string> parse(const std::string& s, char delimiter)
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

Result calculateExpression(const std::string & expr)
{
    if(true == expr.empty())
    {
        return Result{0.0, Error::EmptyString};
    }

    auto tokens = parse(expr, ' ');
    std::string operation = "";
    double operand1 = 0.0;
    double operand2 = 0.0;
    Result res = {0.0, Error::NoError};
    StackState state = StackState::WaitingFirstOperand;

    for (auto token = tokens.begin(); token != tokens.end(); ++token)
    {
        if(Error::NoError == res.error)
        {
            if(StackState::WaitingFirstOperand == state)
            {
                operand1 = std::stod(*token);
                state = StackState::WaitingSecondOperand;
            }
            else if (StackState::WaitingSecondOperand == state)
            {
                operand2 = std::stod(*token);
                state = StackState::WaitingOperation;
            }
            else if (StackState::WaitingOperation)
            {
                if(true == isOperation(*token))
                {
                    operation = *token;
                    res = calculateOperation(operand1, operand2, operation);
                    operand1 = res.value;
                    operand2 = 0.0;
                    state = StackState::WaitingSecondOperand;
                }
                else
                {
                    return {0.0, Error::WrongOperation};
                }
            }
        }
        else
        {
            return res;
        }
    }
    return res;
}

bool isOperation(const std::string & operation)
{
    return ("+" == operation || "-" == operation || "*" == operation || "/" == operation);
}

Result calculateOperation(double operand1, double operand2, const std::string& operation)
{
    Result res = {0.0, Error::NoError};
    if ("+" == operation)
    {
        res.value = operand1 + operand2;
    }
    else if("-" == operation)
    {
        res.value = operand1 - operand2;
    }
    else if("*" == operation)
    {
        res.value = operand1 * operand2;
    }
    else if("/" == operation)
    {
        if(0.0 == operand2)
        {
            return {0.0, Error::DivideByZero};
        }
        else
        {
            res.value = operand1 / operand2;
        }
    }
    return res;
}

