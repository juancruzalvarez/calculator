#include "lexer.hh"
#include <string>
Lexer::Lexer(std::string str)
{
   this->str = str;
   i = 0;
   token_buffer = std::deque<token::Token>{};
}

// advances lexer and returns current token.
token::Token Lexer::advance()
{
   if (token_buffer.size() == 0)
   {
      scan_token();
   }
   token::Token ret = token_buffer.front();
   token_buffer.pop_front();
   return ret;
}

// returns current token without advancing the lexer.
token::Token Lexer::peek()
{
   if (token_buffer.size() == 0)
   {
      scan_token();
   }
   return token_buffer.front();
}

// returns the ith next token without advancing the lexer.
token::Token Lexer::peek(int i)
{
   while (token_buffer.size() < i)
   {
      scan_token();
   }
   return token_buffer[i];
}

void Lexer::unget(token::Token tok)
{
   token_buffer.push_front(tok);
}

// scans a token and pushes it to the token buffer.
void Lexer::scan_token()
{
   advance_whitespaces();
   if (str.size() <= i)
   {
      token_buffer.push_back(token::Token{token::TOK_EOF, -1});
      return;
   }

   token::Token tok;
   if (is_digit(str[i]))
   {
      tok.value = scan_number();
      tok.type = token::NUMBER;
   }
   else
   {
      tok.value = 0;
      tok.type = scan_operator();
   }
   token_buffer.push_back(tok);
}

double Lexer::scan_number()
{
   std::string aux{};
   while (is_digit(str[i]) || str[i] == '.' || str[i] == 'e')
   {
      aux += str[i++];
   }
   return std::stod(aux);
}

token::TokenType Lexer::scan_operator()
{
   char first = str[i++];
   switch (first)
   {
   case '+':
      return token::ADD;
   case '-':
      return token::SUB;
   case '/':
      return token::DIV;
   case '(':
      return token::LPARENTESIS;
   case ')':
      return token::RPARENTESIS;
   case '*':
   {
      if (str[i] == '*')
      {
         i++;
         return token::POW;
      }
      return token::MULT;
   }
   }
}

void Lexer::advance_whitespaces()
{
   while (is_whitespace(str[i]))
   {
      i++;
   }
}

inline bool Lexer::is_whitespace(char c)
{
   return c == ' ' || c == '\n' || c == '\r' || c == '\v' || c == '\t';
}

inline bool Lexer::is_digit(char c)
{
   return c >= '0' && c <= '9';
}