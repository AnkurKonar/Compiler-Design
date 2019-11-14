#include "parser.h"
#include<stdlib.h>

int parser(ASTnode_t *node)
{
	getNextToken();
    if((char)token.tokenClass == 'r')
    {
        node->type = 'R';
        node->val = -1;
        node->op =  ' ';
        return 1;
    }	
    else if(token.tokenClass == NUM)
    {
    	node->type = 'D';
    	node->val = token.val;
    	node->op = ' ';
        return 1;
    }
    else if(token.tokenClass == ID)
    {
    	node->type = 'C';
    	node->val = token.val;
    	node->op = (char)token.val;
        return 1;
    }
    else if(token.tokenClass == '(')
    {
    	node->left = (ASTnode_t*)malloc(sizeof(ASTnode_t));
		node->left->left = NULL;
		node->left->right = NULL;		
		if(!parser(node->left))
            return 0;
		
    	getNextToken();
    	if(token.tokenClass==END)
        	return 0;
    	node->op = token.tokenClass;
    	node->type = 'I';
        node->val = token.tokenClass;
		
        node->right = (ASTnode_t*)malloc(sizeof(ASTnode_t));
		node->right->left = NULL;
		node->right->right = NULL;
		if(!parser(node->right))
            return 0;
		
		getNextToken();
        if(token.tokenClass!=')')
        	return 0;

        return 1;
    }    

    return 0;
}
