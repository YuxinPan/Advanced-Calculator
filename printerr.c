//
//  printerr.c
//  calculator2
//
//  Created by 潘宇忻 on 15-9-10.
//  Copyright (c) 2015年 Yuxin Pan. All rights reserved.
//

#include <stdio.h>
#include "printerr.h"

/* The input is a number which decides the error message to be printed.
 No output needed as it directly print out the message.
 The function simply prints out the specified error message.*/
int printerr(int a){
    
    if (a==1){printf("Goodbye!\n");}
    if (a==2){printf("Simple Calculator understands the following arithmetic operations:\n^ exponentiation\n+ addition\n- subtraction\n* multiplication\n/ division\n");}
    if (a==3){printf("Error: Illegal input!\n");}
    if (a==4){printf("Error: Divide by zero!\n");}
    return 0;
}
