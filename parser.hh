#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "lexer.hh"
#include "expression.hh"


class Parser{
public:
    Parser(Lexer lexer);
    Expression* parse();
private:
    Lexer lexer;
    Expression* parse_expression(int current_precedence);
    Expression* parse_literal();
    bool match(std::vector<token::TokenType> types, token::Token &tok){


};


#endif