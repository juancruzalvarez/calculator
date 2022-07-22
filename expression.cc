#include <math.h>

#include "expression.hh"

BinaryExpression::BinaryExpression(Operator op, Expression *lhs, Expression *rhs) : op(op), lhs(lhs), rhs(rhs) {}

double BinaryExpression::evaluate()
{
   switch (op)
   {
   case Operator::ADD_OP:
      return lhs->evaluate() + rhs->evaluate();
   case Operator::SUB_OP:
      return lhs->evaluate() - rhs->evaluate();
   case Operator::MULT_OP:
      return lhs->evaluate() * rhs->evaluate();
   case Operator::DIV_OP:
      return lhs->evaluate() / rhs->evaluate();
   case Operator::POW_OP:
      return pow(lhs->evaluate(), rhs->evaluate());
   }
   return lhs->evaluate();
}

std::string BinaryExpression::to_str()
{
   return "(" + lhs->to_str() + operator_to_str(op) + rhs->to_str() + ")";
}

UnaryExpression::UnaryExpression(Operator op, Expression *lhs) : op(op), lhs(lhs) {}

double UnaryExpression::evaluate()
{
   switch (op)
   {
   case Operator::POS_OP:
      return +lhs->evaluate();
   case Operator::NEG_OP:
      return -lhs->evaluate();
   }
   return lhs->evaluate();
}

std::string UnaryExpression::to_str()
{
   return "(" + operator_to_str(op) + lhs->to_str() + ")";
}

NumberExpression::NumberExpression(double num) : num(num) {}

double NumberExpression::evaluate()
{
   return num;
}

std::string NumberExpression::to_str()
{
   return std::to_string(num);
}
