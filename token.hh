#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace token{

    //types of tokens
    enum TokenType{
        TOK_EOF,
        TOK_INVALID,
        NUMBER,
        ADD,
        SUB,
        MULT,
        DIV,
        POW,
        LPARENTESIS,
        RPARENTESIS
    };

    struct Token{
        TokenType type;
        double value;
    };

    //returns a string representation of the given type of token.
    std::string token_type_to_str(TokenType type);

    //returns string representation of a token.
    std::string token_to_str(Token token);
   

};



#endif