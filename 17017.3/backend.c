#include "backend.h"

int backend(ASTnode_t *tpp)
{
	if(tpp!=NULL)
	{
      if(tpp->type=='R')
      {
          int n;
          printf("\n:");
          scanf("%d", &n);
          return n;
      }
      if(tpp->type=='D')
      {
         return tpp->val;
      }

		int x = backend(tpp->left);
		int y = backend(tpp->right);
		if(x==-1 || y==-1)
      {
         return -1;
      }

      if(tpp->op == '+')
      {
         return x+y;
      }
      else if(tpp->op == '*')
      {
         return x*y;
      }
      else
      {
         return -1;
      }
	}
	else
        return -1;
}
