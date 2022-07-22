#include "operator.hh"

OperatorInfo get_operator_info(Operator op)
{
   switch (op)
   {
   case Operator::ADD_OP:
   case Operator::SUB_OP:
      return OperatorInfo{OperatorAsociativity::LEFT, 0};

   case Operator::MULT_OP:
   case Operator::DIV_OP:
      return OperatorInfo{OperatorAsociativity::LEFT, 1};

   case Operator::POW_OP:
      return OperatorInfo{OperatorAsociativity::LEFT, 2};

   case Operator::POS_OP:
   case Operator::NEG_OP:
      return OperatorInfo{OperatorAsociativity::RIGHT, 3};

   default:
      return OperatorInfo{OperatorAsociativity::RIGHT, -1};
   }
}

Operator get_binary_operator_from_token(token::TokenType tok_type)
{
   switch (tok_type)
   {
   case token::ADD:
      return Operator::ADD_OP;
   case token::SUB:
      return Operator::SUB_OP;
   case token::MULT:
      return Operator::MULT_OP;
   case token::DIV:
      return Operator::DIV_OP;
   case token::POW:
      return Operator::POW_OP;
   }
   return Operator::INVALID_OP;
}

Operator get_unary_operator_from_token(token::TokenType tok_type)
{
   switch (tok_type)
   {
   case token::ADD:
      return Operator::POS_OP;
   case token::SUB:
      return Operator::NEG_OP;
   }
   return Operator::INVALID_OP;
}

std::string operator_to_str(Operator op)
{
   switch (op)
   {
   case Operator::ADD_OP:
      return "+";
   case Operator::SUB_OP:
      return "-";
   case Operator::MULT_OP:
      return "*";
   case Operator::DIV_OP:
      return "/";
   case Operator::POW_OP:
      return "**";
   case Operator::POS_OP:
      return "+";
   case Operator::NEG_OP:
      return "-";
   default:
      return "Unkown operator.";
   }
}
