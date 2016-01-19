//
//  calculator.c
//  calculator
//
//  Created by Yuxin Pan on 15-8-27.
//  Copyright (c) 2015 Yuxin Pan. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int checkstr(const char *str);
int priority(const char *str);
double compute(char str,double a,double b);
int checkstr3(const char *str);
int checkstr4(const char *str,int a);
int printerr(int a);
char *enotation(char *message2);

int main(void)

{
    int ii,iii;
    char temp='\0';
    char *symbl = "+-*/^qQ1234567890()ehH .E";  // All the characters that will be used in the future
    char *symbl3 = "1234567890.";
    
    printf("Simple Calculator\n");
    
    
    /* Start the while loop which will end only if q is entered. */
    while(1)
    {
        double result1=0.000000;
        int i4,i5=0,times,marker=0,tt=0,emarker=0,divide_zero=0;
        char message[255],message2[255],message3[255],p[255];

        printf(">>> ");fflush(stdout); // Print the prompt and flush it out (needed on Windows system).
   
        
        /* Start cleaning the string */
        for (ii=0;ii<255;ii++){
            message2[ii]=temp;
            message3[ii]=temp;
            message[ii]=temp;
            p[ii]=temp;
        }
        /* End cleaning the string */

        
        // Read from user using fgets
        fgets(message2, sizeof(message2), stdin);

        
        /* Start deleting whitespace*/
        message2[strlen(message2)-1]=temp;
        for (i4=0;i4<(strlen(message2));i4++){
            if ((message2[i4]!=symbl[22])&&(message2[i4]!=temp)){
                message3[i5]=message2[i4];
                i5=i5+1;
            }
        }
        /* End deleting whitespace*/

        
        /* Start replacing enotation with normal decimal */
        if (strcmp(message3,enotation(message3))){// check if there is e notation
            emarker=1;
        }
        else{
            emarker=0;
        };
        strcpy(message3,enotation(message3));
        /* End replacing enotation with normal decimal */

        
        strcpy(message,message3);
        strcpy(p,message);
        
        
        /* Messages that responding the command q and h */
        if (((p[0]==symbl[6])||(p[0]==symbl[5]))&&(strlen(message)==1)){
            printerr(1);
            exit(0);
        }
        if (((p[0]==symbl[20])||(p[0]==symbl[21]))&&(strlen(message)==1)){
            marker=1;
            printerr(2);
            for (ii=0;ii<255;ii++){
                message2[ii]=temp;
                message[ii]=temp;
                p[ii]=temp;
            }
            continue;
        }

        
        /* Start using functions checkstr and checkstr4 to detect error inputs and print error message */
        if (!checkstr(message)||checkstr4(message,emarker)
            ||((message[0]==symbl[5])||(message[0]==symbl[6]))||(((message[0]==symbl[20])||(message[0]==symbl[21]))&&(marker!=1))){
            printerr(3);
            for (ii=0;ii<255;ii++){    // Clean up the string
                message2[ii]=temp;
                message[ii]=temp;
                p[ii]=temp;
            }
            continue;
        }
        /* End using functions checkstr and checkstr4 to detect error inputs and print error message */

        
        // Find how many loops does it need to eliminate all the ()
        times=checkstr3(message);
    {
    for (iii=0;iii<=times;iii++){
        int i1=0,i2,z=0,z2=0,pos1=0,pos2=-1;
        int j1=0;
        int k=0,k1=0,k2=0;
        double n[255];
        char str3[255],temp1[255],temp2[255],temp3[255];

        tt=0;
        
        
            /* Start finding the inner () pair */
            for (i1=0;i1<(strlen(message));i1++){
                if ((message[i1]==symbl[17])&&(pos2==-1)){pos1=i1;}
                if ((message[i1]==symbl[18])&&(pos2==-1)){pos2=i1;}
            }
            /* End finding the inner () pair */
        
        
            strcpy(temp1,message);
        
        
            /* Start putting the content inside the () to message */
            for (i1=0;i1<255;i1++){   // Clean up the string
                message[i1]=temp;n[i1]=temp;str3[i1]=temp;}
            for (i1=0;i1<=(pos2-pos1-2);i1++)
            {message[i1]=temp1[pos1+i1+1];
            }
            if (iii==times){strcpy(message,temp1);}
            k1=-1;
            k2=-1;
            
            for (i1=0;i1<(strlen(message));i1++){
                k=0;
                for (j1=0;j1<strlen(symbl3);j1++){
                    if (message[i1]==symbl3[j1]){
                        k=1;
                    }
                }
            /* End putting the content inside the () to message */
                
                
            // Start getting the number from the string
            char str2[255];
            if (i1==(strlen(message)-1)){k2=i1; if (k1==-1){k1=k2;}
                for (i2=k1;i2<=k2;i2++){
                    str2[i2-k1]=message[i2];
                }
                sscanf(str2, "%lf", &n[z]);   // Put characters to decimal numbers
                if ((message[0]==symbl[1])&&(tt==0)){
                    tt=1;n[0]=(-1)*n[0];
                }
                z=z+1;
                k=0;
                k1=-1;
                k2=-1;
                for (i2=0;i2<255;i2++){
                    str2[i2]=temp;
                }
                continue;
            }
            if ((k1!=-1)&&(k!=1)){
                k2=i1-1;
                for (i2=k1;i2<=k2;i2++){
                    str2[i2-k1]=message[i2];
                }
                str3[z2]=message[i1];
                z2=z2+1;
                sscanf(str2, "%lf", &n[z]);   // Put characters to decimal numbers
            // End getting the number from the string

             
                // Clear the string and other variables.
                z=z+1;
                k=0;
                k1=-1;
                k2=-1;
                for (i2=0;i2<255;i2++){
                    str2[i2]='\0';
                }
                continue;}
            if ((k==1)&&(k1==-1)){k1=i1;}
        }

            {long int length,i5,i6,count=0;
             int b[255];
                length=strlen(str3);
                
                
                /* Start checking if there is a subtraction operator followed by a negative sign */
                for (i6=0;i6<(strlen(message)-1);i6++){
                    if  (strlen(message)!=0){
                if ((message[i6]==symbl[0])||(message[i6]==symbl[1])||(message[i6]==symbl[2])||(message[i6]==symbl[3])||(message[i6]==symbl[4])){
                	b[count]=0;
                    if ((message[i6]==symbl[1])&&(message[i6+1]==symbl[1])){
                        b[count]=1;
                	}
                    count=count+1;
                }}}
                /* End checking if there is a subtraction operator followed by a negative sign */
                
                
                /* Start computing the value of the expression */
                while (str3[0]!=temp){
                	int pos;
                    
                    pos=priority(str3);  // Find which operation in the expression goes first
                    if (b[pos]==1) {
                    	n[pos+1]=(-1.0)*n[pos+1];
                    }
                    
                    // if divide by zero, the print the error message as below and break
                    if (n[pos+1]==0){
                        printerr(4);
                        fflush(stdout);
                        divide_zero=1;
                        break;
                    }
                    
                    n[pos]=compute(str3[pos],n[pos],n[pos+1]);  // Store the result in n[pos]
                    for (i5=pos+1;i5<length;i5++){
                        n[i5]=n[i5+1];
                    }
                    for (i5=pos;i5<(length-1);i5++){
                        str3[i5]=str3[i5+1];
                    }
                    str3[length-1]=temp;
                    length=length-1;
                }
              /* End computing the value of the expression */
                
                
                if (divide_zero==1){break;}
                result1=n[0];
                snprintf(temp2,255,"%f",n[0]); // Put decimal numbers to string
            }
            
            
            /* Start cleaning up the string and put all the parts back to a string */
            for (i1=0;i1<255;i1++){
                message[i1]=temp;
            }
            for (i1=0;i1<pos1;i1++){
                message[i1]=temp1[i1];
            }
            strcat(message,temp2);
            for (i1=0;i1<((strlen(temp1)-pos2));i1++){
                if ((strlen(temp1)-pos2)!=1){
                    temp3[i1]=temp1[i1+pos2+1];
                }
            }
            temp3[(strlen(temp1)-pos2)]=temp;
            strcat(message,temp3);
            for (i1=0;i1<255;i1++){
                temp3[i1]=temp;
            temp2[i1]=temp;
            }
            /* End cleaning up the string and put all the parts back to a string */

            
            if (divide_zero==1){break;}

        }}
        if (divide_zero==1){continue;}
        
        // Print out the result
        printf("%.6f\n",result1);
        
        // Clear the variables
        for (ii=0;ii<255;ii++){
            message2[ii]=temp;
            message[ii]=temp;
            p[ii]=temp;}
        fflush(stdout);
    }
    /* End of the while loop */
    
    
    return 0;
}
