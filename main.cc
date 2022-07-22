#include <iostream>

#include "lexer.hh"
#include "token.hh"

int main(){
    std::string test = "58 + 3* 2.4-(5*3-2+8)  ";
    Lexer lexer{test};
    token::Token tok;
    std::cout<<"Lexer started." << "\n";
    while((tok = lexer.advance()).type != token::TOK_EOF){
        std::cout<< token::token_to_str(tok) << "\n";
    }
    std::cout<<"Lexer finished." << "\n";
}