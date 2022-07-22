#include "parser.hh"
#include "operator.hh"
Parser::Parser(Lexer lexer): lexer(lexer) {};

Expression* Parser::parse() {
    return parse_expression(-1);
}

Expression* Parser::parse_expression(int min_precedence) {
    Expression* lhs = parse_literal();
    token::Token tok;
    while(match({token::ADD, token::SUB, token::DIV, token::MULT, token::POW}, tok)) {
        Operator op = get_binary_operator_from_token(tok.type);
        OperatorInfo op_info = get_operator_info(op);
        if(op_info.precedence < min_precedence){
            lexer.unget(tok);
            break;
        }
        int next_min_precedence = op_info.asociativity == OperatorAsociativity::RIGHT ? op_info.precedence : op_info.precedence + 1;
        Expression* rhs = parse_expression(next_min_precedence);
        lhs = new BinaryExpression{op, lhs, rhs};
    }
    return lhs;
}

Expression* Parser::parse_literal(){
    token::Token tok = lexer.peek();
    switch (tok.type)
    {
        case token::NUMBER: {
            lexer.advance();
            return new NumberExpression{tok.value};
        }
        case token::LPARENTESIS:{
            Expression* exp;
            lexer.advance();
            exp = parse_expression(-1);
            lexer.advance();
            return exp;
        }
        
        case token::SUB:
        case token::ADD: {
            return new UnaryExpression{get_unary_operator_from_token(tok.type), parse_expression(-1)};
        }
    }
}

bool Parser::match(std::vector<token::TokenType> types, token::Token &tok){
    tok = lexer.peek();    
    for(const auto& type : types){
        if(type == tok.type){
            lexer.advance();
            return true;
        }
    }
    return false;
} 