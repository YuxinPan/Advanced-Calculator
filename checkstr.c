//
//  checkstr.c
//  calculator
//
//  Created by Yuxin Pan on 15-8-27.
//  Copyright (c) 2015 Yuxin Pan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkstr.h"
int checkstr(const char *str);
int checkstr3(const char *str);
int checkstr4(const char *str,int a);


/* The input of Checkstr is the string entered by the user (just without the whitespace). The output is 0 or 1. It is used to detect if the input string has syntax error. */
int checkstr(const char *str)
{
    char *symbl2 = "+-*/^qQ1234567890()ehH.";
    int i=0;
    int j=0;
    int k=0;
    int z=0;

    for (i=0;i<(strlen(str));i++){
        k=0;
        if (str[i]==symbl2[22]){if (str[i+1]==symbl2[22]){return 0;}}
        if (str[i]==symbl2[17]){z=z+1;}
        if (str[i]==symbl2[18]){z=z-1;}
        if (z<0){return 0;}
        for (j=0;j<strlen(symbl2);j++){
            if (str[i]==symbl2[j]){
                k=1;
            }
        }
        if (k==0){return 0;}
        
    }
    if (z==0){return 1;}
    else{return 0;}
}


/* The input of Checkstr3 is the string entered by the user (just without the whitespace). The output is the number of pair of (). It is used to find how many loops does it need to eliminate all the () by finding how many '(' are there.*/
int checkstr3(const char *str)
{
    char *symbl4 = "(";
    int i=0,z=0;
    for (i=0;i<(strlen(str));i++){
        if (str[i]==symbl4[0]){z=z+1;}
    }
    return z;

}


/* The input of Checkstr4 is the string entered by the user (just without the whitespace). The output is 0 or 1. It is used to detect if the input string is legal including trailing operator, more than one decimal places and two operators in a row. */
int checkstr4(const char *str,int a)
{
    char *symbl41 = ".*+-/^()e";

    int i=0,j;
    if (a==1){return 0;}
    
    
    // Detect trailing operator
    if ((str[strlen(str)-1]==symbl41[0])||(str[strlen(str)-1]==symbl41[1])||(str[strlen(str)-1]==symbl41[2])||(str[strlen(str)-1]==symbl41[3])||(str[strlen(str)-1]==symbl41[4])||(str[strlen(str)-1]==symbl41[5])){
        return 1;}
    
    
    /*  Start detecting illegal inputs like 1++2 9+ 3..4 except expressions like 1--2 */
    for (i=0;i<(strlen(str)-1);i++){
    	if ((str[i]==symbl41[0])||(str[i]==symbl41[1])||(str[i]==symbl41[2])||(str[i]==symbl41[3])||(str[i]==symbl41[4])){
            for (j=0;j<=5;j++){
            if (str[i+1]==symbl41[j]){
                if (!(str[i+1]==symbl41[3])){
                    return 1;}}}}}
    /*  End detecting illegal inputs like 1++2 9+ 3..4 except expressions like 1--2 */
    
    
    // More than one decimal places and other illegal inputs (e.g. 3.5.+).
    for (i=0;i<(strlen(str)-2);i++){
    	if (str[i]==symbl41[0]){j=i+2;
    if (!((str[j]==symbl41[1])||(str[j]==symbl41[2])||(str[j]==symbl41[6])||(str[j]==symbl41[7])||(str[j]==symbl41[3])||(str[j]==symbl41[4])||(str[j]==symbl41[5])))
    {return 1;}
        }}
    return 0;
}


