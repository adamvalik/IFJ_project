/**
 * @file scanner.h
 * 
 * IFJ23 compiler
 * 
 * @brief Lexical analysis for IFJ23 compiler
 *
 * @author Dominik Horut <xhorut01>
 * @author Samuel Hejnicek <xhejni00>
 */
#ifndef IFJ_SCANNER_H
#define IFJ_SCANNER_H
#include "error.h"
//#include "token.h"

typedef enum token_types {
    TOKEN_WHITESPACE,
    TOKEN_TAB,
    TOKEN_EOL,
    TOKEN_EOF,
    TOKEN_MINUS,
    TOKEN_PLUS,
    TOKEN_MULTIPLY,
    TOKEN_LESS,
    TOKEN_LESS_EQ,
    TOKEN_GREAT,
    TOKEN_GREAT_EQ,
    TOKEN_LPAR,
    TOKEN_RPAR,
    TOKEN_EQ,
    TOKEN_EQEQ,
    TOKEN_EXCLAM,
    TOKEN_EXCLAMEQ,
    TOKEN_COMMA,
    TOKEN_COLON,
    TOKEN_DOUBLE_QM,
    TOKEN_RET_TYPE, //->
    TOKEN_ID,
    TOKEN_KEYWORD_QM, //ID?
    TOKEN_NUM,
    TOKEN_EXP,
    TOKEN_DEC,
    TOKEN_STRING,
    TOKEN_ML_STRING,
    TOKEN_KEYWORD,
    TOKEN_UNDERSCORE,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET,
    TOKEN_DIVIDE
} token_type_t;

typedef enum state{

    S_START,
    S_COLON,    // id type declaration
    S_COMMA,
    S_QM,
    S_DOUBLE_QM,    // ?? operator
    S_GTR,
    S_GTR_EQ,
    S_LESS,
    S_LESS_EQ,
    S_EQ,
    S_EQEQ,        
    S_EXCLAM,
    S_EXCLAMEQ,
    S_MULTIPLY,
    S_PLUS,
    S_MINUS,
    S_RET_TYPE,     // -> returned type
    S_LPAR,
    S_RPAR,
    S_UNDERSCORE,
    S_ID, 
    S_ID_QM,      // String?
    S_NUM,
    S_NUM_DOT,
    S_NUM_E,
    S_NUM_E_SIGN,
    S_DEC, 
    S_EXP,

    S_START_QUOTES, //"
    S_END_QUOTES,    //"
    S_START_ESC_SENTENCE, // /
    S_START_HEX, // u
    S_LEFT_BRACKET, // {
    S_FIRST_HEX, //0-Z

    S_THREE_QUOTES, // """
    S_START_MULTILINE, //EOL

    S_SL_COM,
    S_NESTED_COM,
    S_NESTED_END

}automat_state_t;

typedef enum keyword{

    KW_DOUBLE,  // Double
    KW_INT,     // Int
    KW_STRING,  // String
    KW_ELSE,    // else 
    KW_FUNC,    // func
    KW_IF,      // if
    KW_LET,     // let
    KW_NIL,     // nil
    KW_RETURN,  // return
    KW_VAR,     // var
    KW_WHILE,   // while
    //TODO dopsat funkce jako write, double

    // In built functions

    KW_RD_STR,   // readString()
    KW_RD_INT,   // readInt()
    KW_RD_DBL,   // readDouble()
    KW_WRT,      // write()
    KW_INT_2_DBL,// Int2Double()
    KW_DBL_2_INT,// Double2Int()
    KW_LENGHT,   // lenght()
    KW_SUBSTR,   // substring()
    KW_ORD,      // ord()
    KW_CHR,      // chr()


}keyword_t;

typedef struct token_value
{
    int integer;
    double type_double;
    keyword_t keyword;
    vector* vector;
} value_type_t;


typedef struct token {
    value_type_t value;
    token_type_t type;
    int line;
    bool question_mark;
} token_t;

token_t* get_me_token();

#endif