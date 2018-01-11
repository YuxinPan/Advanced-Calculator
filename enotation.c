//
//  enotation.c
//  calculator2
//
//  Created by Yuxin Pan on 15-9-12.
//  2015 Yuxin Pan. 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enotation.h"
#include <math.h>

/* Function enotation has one input, which is a pointer to the string. The output is a pointer to the string that has decimals stored instead of e notation. The function replaces e notation with decimals and store the decimals in the string. */
char *enotation(char *message2)
{   int back,ia,ib,ii,ic,etime=0,num3,emarker1,emarker2=0;
    char *symbl32 = "+-*/^qQ1234567890()ehH .E";  // All the characters that will be used in the future
    double num2;
    char tempstr[255],tempstr2[255],tempstr3[255],tempstr4[255],message3[255];
    char temp='\0';
    char *pmes;
    
    strcpy(message3,message2);
    if (strlen(message3)>3){
        for (ii=0;ii<(strlen(message3));ii++){
            if ((message3[ii]==symbl32[19])||(message3[ii]==symbl32[24])){
                emarker2=1;
                etime=etime+1;   // Find how many e notations are there.
            }
        }
        for (ib=0;ib<etime;ib++){  // Do the operation etime, and everytime one e notaion is converted into decimal
            
            // Clear the string
            for (ic=0;ic<255;ic++){tempstr[ic]=temp;tempstr2[ic]=temp;tempstr3[ic]=temp;tempstr4[ic]=temp;
            }
            emarker1=0;
            for (ii=0;ii<(strlen(message3)-1);ii++){
                
                // if message3[ii] is e, if statement is true and e notation will be converted to decimals
                if ((message3[ii]==symbl32[19])||(message3[ii]==symbl32[24])){for (back=ii;back>0;back--){
                    if ((message3[back]==symbl32[23])&&(emarker1==0)) {
                        emarker1=1;num2=0;
                        for (ia=0;ia<=(back-2);ia++){
                            tempstr[ia]=message3[ia];
                        }
                        for (ia=(back-1);ia<ii;ia++){
                            tempstr2[ia-(back-1)]=message3[ia];
                        }
                        for (ia=ii+2;ia<strlen(message3);ia++){
                            tempstr3[ia-ii-2]=message3[ia];
                        }
                        sscanf(tempstr2, "%lf", &num2); // Put characters to decimal numbers
                        tempstr4[0]=message3[ii+1];
                        num3=atoi(tempstr4);
                        num2=num2*pow(10,num3);// Calculate 10 to the power if num3
                        snprintf(tempstr2,255,"%f",num2); // Put decimal numbers to string
                    }}}}
            strcpy(message3,tempstr);
            strcat(message3,tempstr2);
            strcat(message3,tempstr3);
        }}
    pmes=message3;
    return pmes;
}
