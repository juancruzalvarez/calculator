#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>

#include "operator.hh"
#include "token.hh"

class Expression
{
public:
   virtual double evaluate() = 0;
   virtual std::string to_str() = 0;
};

class BinaryExpression : public Expression
{
public:
   BinaryExpression(Operator op, Expression *lhs, Expression *rhs);
   double evaluate();
   std::string to_str();

private:
   Operator op;
   Expression *lhs, *rhs;
};

class UnaryExpression : public Expression
{
public:
   UnaryExpression(Operator op, Expression *lhs);
   double evaluate();
   std::string to_str();

private:
   Operator op;
   Expression *lhs;
};

class NumberExpression : public Expression
{
public:
   NumberExpression(double num);
   double evaluate();
   std::string to_str();

private:
   double num;
};

#endif