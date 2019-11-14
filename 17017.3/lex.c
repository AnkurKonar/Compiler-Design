#include "lex.h"
#include<stdio.h>

token_t token;

int is_num(char c)
{
    if( c <= '9' && c >= '0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void getNextToken()
{
    char ch;
    if(scanf("%c", &ch) != EOF)
    {
        if(is_num(ch))
        {
            int num = ch - '0';
            while(scanf("%c", &ch) != EOF && is_num(ch))
            {
                num *= 10;
                num += (ch - '0');
            }
            ungetc(ch, stdin);

            token.tokenClass = NUM;
            token.val = num;
        }
        else if(ch == ' ' || ch == '\n' )
        {
            getNextToken();
        }
        else
        {
            token.tokenClass = ch;
            token.val = ch;
        }
    }
    else
    {
        token.tokenClass = END;
        token.val = -1;
    }
}
