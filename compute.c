//
//  compute.c
//  calculator
//
//  Created by Yuxin Pan on 15-8-27.
//  2015 Yuxin Pan.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compute.h"
#include <math.h>

/* The inputs are two numbers and one operator. The output is the result of the operation. The function compute is used to simply add, subtract, multiply, divide and find the power of numbers */
double compute(char str,double a,double b){
    
    char *symbl2 = "+-*/^";  // Five operators listed
    
    if (str==symbl2[0]){return (a+b);}
    if (str==symbl2[1]){return (a-b);}
    if (str==symbl2[2]){return (a*b);}
    if (str==symbl2[3]){return (a/b);}
    if (str==symbl2[4]){return pow(a,b);}
    return 0;
    
}
