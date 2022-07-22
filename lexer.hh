#ifndef LEXER_H
#define LEXER_H

#include <deque>

#include "token.hh"

class Lexer
{
public:
   Lexer(std::string str);
   // advances lexer and returns current token.
   token::Token advance();
   // returns current token without advancing the lexer.
   token::Token peek();
   // returns the ith next token without advancing the lexer.
   token::Token peek(int i);
   // puts token back to the front of the token buffer.
   void unget(token::Token tok);

private:
   std::string str;
   int i;
   std::deque<token::Token> token_buffer;
   void scan_token();
   double scan_number();
   token::TokenType scan_operator();
   void advance_whitespaces();
   bool is_whitespace(char c);
   bool is_digit(char c);
};
#endif