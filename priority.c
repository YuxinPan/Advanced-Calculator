//
//  priority.c
//  calculator
//
//  Created by Yuxin Pan on 15-8-27.
//  Copyright (c) 2015 Yuxin Pan. All rights reserved.
//

#include "priority.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* The input is the expression in the for mat of string. 
 The output is the position of the operator that has the highest priority.
 The function finds which operation in the expression goes first. */
int priority(const char *str)
{
	char symbl45[5] = {'+', '-', '*', '/', '^'};
    int i=0;
    int j[255];
    int k=0;

    for (i=254;i>=0;i--){
        j[i]=0;
    }
    
    
    /* + - have the same priority, * / have the same priority, ^ has the highest priority. So in an expression, it first finds the operator which has the highest priority in the expression, and if there are several operators that have the same priority, then goes with the first one. () are not considered here. */
    for (i=0;i<=(strlen(str)-1);i++){
    	j[i]=0;
        if ((str[i]==symbl45[1])||(str[i]==symbl45[0])){
            j[i]=1;
        }
        if ((str[i]==symbl45[3])||(str[i]==symbl45[2])){
            j[i]=2;
        }
        if (str[i]==symbl45[4]){
            return i;
        }
        if (i!=0){
            if (j[i]<j[i-1]){
                for (k=i;k>=1;k--){
                    if (j[k]!=0){
                        if (j[k]>j[k-1]){
                            return k;
                        }
                    }
                }
            }
        }

    }
    for (i=254;i>=1;i--){
        if (j[i]!=0){
            if (j[i]>j[i-1]){
                return i;
            }
        }
    }
    return 0;
}
