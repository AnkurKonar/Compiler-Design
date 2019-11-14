#include "backend.h"
#include "symTab.h"
#include <stdlib.h>
#include <stdio.h>


//Funtion to get the values of the left and right branch of a node
void get_nums(int*,int*, ASTnode_t*, ASTnode_t*);


int backend(ASTnode_t *tpp)
{
   if(tpp==NULL){
      return 0;
   }
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
      if(tpp->type=='C')
      {
         return tpp->val;
      }

      int x=backend(tpp->left);
      int y=backend(tpp->right);

      int *l_num=&x;
      int *r_num=&y;

		if(x==-1 || y==-1)
      {
         return -1;
      }

      if(tpp->op != '=')
      {
         get_nums(l_num, r_num, tpp->left,tpp->right);
      }
      
      if(tpp->op == '+')
      {
         return ((*l_num)+(*r_num));
      }
      if(tpp->op == '*')
      {
         return ((*l_num)*(*r_num));
      }
      if(tpp->op==',')
      {
         return *r_num;
      }
      if(tpp->op == '=')
      {
         updateSymTab(*l_num,*r_num);
         return *r_num;
      }
	}
	else
      return -1;
}



void get_nums(int *left_num, int *right_num, ASTnode_t *l, ASTnode_t *r)
{
   int *vp=(int *)malloc(sizeof(int));
   if(l->type=='C'){
      if(getVal(l->val, vp)!=0)
      {
         printf("Error: Value of %c not defined",(l->val+65));
         exit(1);
      }
      else{
         *left_num = *vp;
      }
   }
   if(r->type=='C'){
      if(getVal(r->val, vp)!=0)
      {
         printf("Error: Value of %c not defined",(r->val+65));
         exit(1);
      }
      else{
         *right_num = *vp;
      }
   }
}

