#include "token.hh"
namespace token
{

   std::string token_type_to_str(TokenType type)
   {
      std::string ret = "type not recognized.";
      switch (type)
      {
      case NUMBER:
      {
         ret = "num";
         break;
      }
      case ADD:
      {
         ret = "+";
         break;
      }
      case SUB:
      {
         ret = "-";
         break;
      }
      case MULT:
      {
         ret = "*";
         break;
      }
      case DIV:
      {
         ret = "/";
         break;
      }
      case POW:
      {
         ret = "**";
         break;
      }
      case LPARENTESIS:
      {
         ret = "(";
         break;
      }
      case RPARENTESIS:
      {
         ret = ")";
         break;
      }
      }
      return ret;
   }

   std::string token_to_str(Token token)
   {
      if (token.type == NUMBER)
         return "Num: " + std::to_string(token.value);
      else
         return token_type_to_str(token.type);
   }

};