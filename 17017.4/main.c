#include "lex.h"
#include "parser.h"
#include "backend.h"
#include "symTab.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{

	ASTnode_t* ast = (ASTnode_t*)malloc(sizeof(ASTnode_t));
    initSymTab();
	if(parser(ast))
    {
        int val=backend(ast);
        if(val!=-1)
            printf("Value: %d\n", val);
        else
            printf("Unable to evaluate expression!\n");
    }
    else
        printf("Unable to form parse tree!\n");

}
