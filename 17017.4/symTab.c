#include "symTab.h"
#include<stdio.h>
symRec symTab[SIZE];

void initSymTab(){
    int i=0;
    for(i=0;i<60;i++)
    {
        symTab[i].def='0';
    }
}

void updateSymTab(int index, int val){
    symTab[index].def='1';
    symTab[index].val=val;
}

int getVal(int index, int *vP){
    if(index>=0 && index<60)
    {
        if(symTab[index].def=='1')
        {
            *vP = symTab[index].val;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
    
}