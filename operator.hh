#ifndef OPERATOR_H
#define OPERATOR_H

#include "token.hh"

enum class Operator
{
   INVALID_OP,
   POS_OP,  // +val
   NEG_OP,  // -val
   ADD_OP,  // val+val
   SUB_OP,  // val-val
   MULT_OP, // val*val
   DIV_OP,  // val/val
   POW_OP   // val**val
};

enum class OperatorAsociativity
{
   RIGHT,
   LEFT
};

struct OperatorInfo
{
   OperatorAsociativity asociativity;
   int precedence;
};

// returns for a given operator its precedence and asociativity.
OperatorInfo get_operator_info(Operator op);
// given a token type returns its corresponding binary operator.
Operator get_binary_operator_from_token(token::TokenType tok_type);
// given a token type returns its corresponding unary operator.
Operator get_unary_operator_from_token(token::TokenType tok_type);
// returns the string representation of the operator
std::string operator_to_str(Operator op);

#endif