#include <iostream>
#include "parser.hh"
#include "lexer.hh"
#include "token.hh"

int main(int argc, char **argv)
{
   std::string test = argv[1];
   Lexer lexer{test};
   Parser parser{lexer};
   Expression *parsed = parser.parse();
   std::cout << "Result:" << parsed->evaluate() << "\n";
}