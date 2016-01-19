//
//  main.c
//  calculator
//
//  Created by Yuxin Pan on 15-8-27.
//  Copyright (c) 2015年 Yuxin Pan. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int * numbers(const char *str);
int checkstr(const char *str);
int priority(const char *str);
int compute(char str,int a,int b);
int checkstr2(const char *str);
int checkstr3(const char *str);

int main(void)

{
    int ii,iii;
    char temp='\0';
    char *symbl = "+-*/^qQ1234567890()ehH .";
    char *symbl3 = "1234567890";

    
    printf("Simple Calculator\n");
    while(1)
    {
        double result1=0.000000;
        int i4,i5=0,times;
        long int z33=0;
        char message[255];
        char message2[255];
        char num[255];
        char p[255];
       // int *p2;    // for future numbers function use
        //   int length;
        printf(">>> ");fflush(stdout);
       for (ii=0;ii<=255;ii++){
            message2[ii]=temp;
            message[ii]=temp;
            num[ii]=temp;
            p[ii]=temp;}
        fgets(message2, sizeof(message2), stdin);
        /* start deleting whitespace*/
        message2[strlen(message2)-1]=temp;
        printf("M2 %s stelen %d\n",message2,strlen(message2));fflush(stdout);
        for (i4=0;i4<(strlen(message2));i4++){ printf("%d ",i4);  // -1??
            if ((message2[i4]!=symbl[22])&&(message2[i4]!=temp)){
                message[i5]=message2[i4];
                printf("%c\n",message[i5]);
                i5=i5+1;
            }
        }
        //message2[strlen()]=temp;
        /* end deleting whitespace*/

        printf("M %s strlen M %d\n",message,strlen(message));fflush(stdout);
        strcpy(p,message);

        if (((p[0]==symbl[6])||(p[0]==symbl[5]))&&(strlen(message)==1)){printf("Goodbye!\n");exit(0);}  //\n needed?
        if (((p[0]==symbl[20])||(p[0]==symbl[21]))&&(strlen(message)==1)){printf("Simple Calculator understands the following arithmetic operations:\n^ exponentiation\n+ addition\n- subtraction\n* multiplication\n/ division\n");for (ii=0;ii<=255;ii++){
            message2[ii]=temp;
            message[ii]=temp;
            num[ii]=temp;
            p[ii]=temp;}continue;}  //\n needed?
        if (!checkstr(message)){printf("Error: Illegal input!\n");for (ii=0;ii<=255;ii++){
            message2[ii]=temp;
            message[ii]=temp;
            num[ii]=temp;
            p[ii]=temp;}continue;}    // \n needed?
        times=checkstr3(message);                                                             // length=strlen(message);
        { for (iii=0;iii<=times+1;iii++){
        int i1=0,i2,z=0,z2=0,pos1=0,pos2=-1;
        int j1=0;
        int k=0,k1=0,k2=0;
        int n[255];
        char str3[255];
        char temp1[255];
        char temp2[255];
        char temp3[255];

        
            for (i1=0;i1<(strlen(message));i1++){
                if ((message[i1]==symbl[17])&&(pos2=-1)){pos1=i1;}// -1?? printf("leng%d\n",strlen(message));
                if ((message[i1]==symbl[18])&&(pos2=-1)){pos2=i1;}
                
            }
            strcpy(temp1,message);
            for (i1=0;i1<=255;i1++){
                message[i1]=temp;}
            for (i1=0;i1<=(pos2-pos1-2);i1++)
            {message[i1]=temp1[pos1+i1+1];
            }
            if (iii==times){strcpy(message,temp1);}

        // printf("temp %s message %s\n",temp1,message);
        k1=-1;
        k2=-1;
        for (i1=0;i1<(strlen(message));i1++){  // strlen(message)-1 ??
            k=0;                     //printf("%d %d %d\n",i,j,k);
            for (j1=0;j1<strlen(symbl3);j1++){   //-1 or not depends on what is inside the strlen
                if (message[i1]==symbl3[j1]){
                k=1;
                }
            }
           // printf("%d %d %d\n",i1,k,k1);
            char str2[255];
            if (i1==(strlen(message)-1)){k2=i1; if (k1==-1){k1=k2;}//printf("k2 %d k1 %d\n",k2,k1);           //i1 or i1-1? strlen(message)-2 ??
                for (i2=k1;i2<=k2;i2++){
                    str2[i2-k1]=message[i2];
                }
                n[z]=atoi(str2);        // printf("%c\n",str2[0]);
              //  printf("%d\n",n[z]);
                z=z+1;
                k=0;
                k1=-1;
                k2=-1;
                for (i2=0;i2<=255;i2++){
                    str2[i2]=temp;
                }
                continue;
            }
            
           // printf("i1 %d k %d \n",i1,k);

            if ((k1!=-1)&&(k!=1)){k2=i1-1;    // printf("here1\n");       // i1 or i1-1?
                for (i2=k1;i2<=k2;i2++){
                    str2[i2-k1]=message[i2];
                }
                str3[z2]=message[i1];
                z2=z2+1;
                n[z]=atoi(str2);
              //  printf("%d %c\n",n[z],str3[z2-1]);
                z=z+1;
                k=0;
                k1=-1;
                k2=-1;
                for (i2=0;i2<=255;i2++){
                    str2[i2]=temp;
                }
                continue;}                      //atoi need to be replaced by atof
            if ((k==1)&&(k1==-1)){k1=i1;}
                                                 //printf("k1 %d\n",k1);
                                                //  if ((k1!=-1)&&(k==1)){}
        }

            {long int length,i5;
             double result;
                length=strlen(str3);

              //  printf("length %d",length);
                while (str3[0]!=temp){int pos;
                printf("This point 1\n");fflush(stdout);

                    pos=priority(str3);
                    printf("This point 3\n");fflush(stdout);

                    //printf("pri %d\n",pos);
                    n[pos]=compute(str3[pos],n[pos],n[pos+1]);
                    if (n[pos]==2315793) {z33=2315793;}                         // incorrect!
             //       printf("n[pos] %d\n",n[pos]);
                    for (i5=pos+1;i5<length;i5++){
                        n[i5]=n[i5+1];
                    }
                    for (i5=pos;i5<(length-1);i5++){
                        str3[i5]=str3[i5+1];
                    }
                    str3[length-1]=temp;
                    length=length-1;
          //          printf("z33 %d\n",z33);

                }result1=n[0];result=n[0];//z33=z3;
                //if (z3!=2315793){printf("result1 %d\n",n[0]);}
                sprintf(temp2,"%d",n[0]);// incorrect!  fcvt!!
            }
            for (i1=0;i1<=255;i1++){
                message[i1]=temp;}
            /*for (i1=0;i1<=(strlen(temp1)+strlen(temp2)-1-(pos2-pos1));i1++){//printf("i1 %d\n",i1);
                if (i1<pos1){message[i1]=temp1[i1];}
                if (((i1+1)>pos1)&&((i1+1)<(pos1+strlen(temp2)))){message[i1]=temp2[i1-pos1];}
                if ((i1+1)>=(pos1+strlen(temp2))){message[i1]=temp1[pos2+1-((i1+1)-(pos1+strlen(temp2)))];}
            }*/
            for (i1=0;i1<pos1;i1++){
                message[i1]=temp1[i1];
            }
            strcat(message,temp2);
            for (i1=0;i1<(strlen(temp1)-pos2);i1++)
            {temp3[i1]=temp1[i1+pos2+1];}
            strcat(message,temp3);
       //     printf("%s\n",message);
            for (i1=0;i1<=255;i1++){
                temp3[i1]=temp;
            temp2[i1]=temp;}
        }
        }if (z33!=2315793){printf("%.6f\n",result1);}z33=0;
       /*
        int i=0;
        int j=0;
        while ((p[i]!=symbl[0])&&(p[i]!=symbl[1])&&(p[i]!=symbl[2])&&(p[i]!=symbl[3]))
            {num[i]=message[i];i=i+1;}
    
        //num[i-1]=temp;
        for (j=0;j<i;j++){
           // printf("%c",num[j]);
        }   //%.6f
        printf("\n");*/
        for (ii=0;ii<=255;ii++){
            message2[ii]=temp;
            message[ii]=temp;
            num[ii]=temp;
            p[ii]=temp;}fflush(stdout);
    

    }    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_atoi(const char *str);

int main(void){
    
    char word[256];
    char *p;
    
    printf("simple calculator\n");
    while(1){
        fgets(word,sizeof(word), stdin);
        
        p=word;
     //   printf("%s\n",p);
        my_atoi(p);
        return 0;
    }
}
int my_atoi(const char *str)
{
    int i = 0, result = 0, sign = 1;
    if (str[2]=="a"){
        printf("%c",str[2]);}return 0;
}

*/



/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *dest, const char *src, unsigned int num);
int my_atoi(const char *str);
int main() {
    int i;
    char word[256];
    char dst[256];
    char *p;
    char *q;
    int val;
    char str[20];
    printf("Simple Calculator\n");
    
    while(1){
        fgets(word, sizeof(word), stdin);//prompt?
        val = my_atoi(word);
        printf("String value = %s, Int value = %d\n", word, val);
        // p=word;
        // p+=3;
        // *(p++)='\0';
        // p-=1;
        // q=dst;
        // *(q++)=*(p++);
        // printf("%s\n",q);
        // printf("%s\n",p);
        
        if (strlwr(word)=='q'){
         printf("Goodbye!\n");
         exit(0);
         }
    }
    
    
    
    
    
    
}




#define SIZE    100

//Convert string to integer example
void convert_ex(void)
{
    int val;
    char str[20];
    
    //my_strcpy(str, "  -09899sdf 3489 ", SIZE);
    //   val = atoi(str);
    val = my_atoi(str);
    printf("String value = %s, Int value = %d\n", str, val);
    
    //my_strcpy(str, "lab04 task 2", SIZE);
    //   val = atoi(str);
    val = my_atoi(str);
    printf("String value = %s, Int value = %d\n", str, val);
}


int my_atoi(const char *str)
// Parse str interpreting its content as integers, return as an int value
{
    int i = 0, result = 0, sign = 1;
    
    // First discard whitespace
    while (str[i++] != '\0') {
        if (str[i] != ' ') break;
    }
    
    // Interpret contents
    --i;
    while (str[i++] != '\0') {
        // Ignore further whitespace
        if (str[i] == ' ') break;
        
        // Handle negative sign
        else if (str[i] == '-')
            sign = 0;
        else {
            // Check char is in number
            int j = 0;
            char *number = "00123456789";    // initial 0 added for j++ in while loop
            int isnum = 0;
            
            while (number[j++] != '\0') {//printf("%c\n",str[i]);
                if (str[i] == number[j]) {
                    
                    // Manual arithmetic
                    result = result * 10 + (str[i] - '0');
                    
                    // Bit shift
                    //                    result = result << (str[i] - '0');
                    
                    isnum = 1;
                    break;
                }
            }
            // str[i] is not a number
            if (isnum == 0) break;
        }
    }
    
    // check sign
    if (sign == 1)
        return result;
    return -result;
}

*/
