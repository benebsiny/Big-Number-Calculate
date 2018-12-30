#include <stdio.h>
#include <string.h>

void minus(char*,char*);
void plus(char*,char*);
void reverse(char*);

int main(){

    int count = 0;
    while(scanf("%d",&count)!=EOF){

        char sum[10001];
        memset(sum,'\0',10001);


        while(count--){
            char input[10001];
            memset(input,'\0',10001);

            scanf("%s",input);

            /*******minus******/
            if(input[0]=='-'){

                //-1-1=-2
                if(sum[strlen(sum)-1]=='-' && strlen(sum)!=0){

                    //Let input's negative sign disappeared
                    reverse(input);
                    reverse(input);

                    sum[strlen(sum)-1] = '\0';

                    plus(sum,input);

                    sum[strlen(sum)] = '-';
                }

                else{ //+1-2=-1
                    minus(sum,input);
                }

            }
            /*******plus******/
            else{

                if(sum[strlen(sum)-1]=='-'){ //-10+5 = -5

                    sum[strlen(sum)-1] = '\0';

                    minus(sum,input);

                    if(sum[strlen(sum)-1]=='-' || (!strcmp(sum,"0"))){
                        sum[strlen(sum)-1] = '\0';
                    }
                    else{
                        sum[strlen(sum)] = '-';
                    }

                }

                else{ //+10+10=+20
                    plus(sum,input);
                }
            }
        }
        reverse(sum);
        printf("%s\n",sum);
    }

    return 0;
}

void minus(char *sum,char *input){
    int i;

    reverse(input);

    //find which one's string length is longer
    int strlonger = strlen(sum);
    if(strlen(sum)<strlen(input))strlonger = strlen(input);

    int borrow = 0; //borrow's digit

    for(i=0; i<strlonger; i++){

        if(sum[i]=='\0')sum[i]='0';
        if(input[i]=='\0')input[i]='0';

        //if borrow
        if((sum[i]-48)-(input[i]-48)-borrow<0){
            sum[i] = ((sum[i]-48)-(input[i]-48)-borrow+10)+48;
            borrow = 1;
        }
        //if no borrow
        else{
            sum[i] = ((sum[i]-48)-(input[i]-48)-borrow)+48;
            borrow = 0;
        }
    }
    //if front number is zero
    for(i=strlen(sum)-1;i>=0; i--){
        if(sum[i]=='0' && i!=0){
            sum[i] = '\0';
        }
        else{
            break;
        }
    }

    //if it is a negative number.
    //If the result is 98, create a number 100 to minus 98 = 2, the answer = -2
    if(borrow==1){
        char minusNeg[101];
        memset(minusNeg,'\0',101);

        minusNeg[0] = '1';
        for(i=1; i<=strlen(sum); i++){
            minusNeg[i] = '0';
        }

        //reverse them so that they in minus function again can operate it well
        reverse(minusNeg);
        reverse(sum);

        minus(minusNeg,sum);
        minusNeg[strlen(minusNeg)] = '-';

        strcpy(sum,minusNeg);
    }


}
void plus(char *sum,char *input){
    int i;

    reverse(input);

    //find which one's string length is longer
    int strlonger = strlen(sum);
    if(strlen(sum)<strlen(input))strlonger = strlen(input);

    int carry = 0; //carry's digit

    for(i=0; i<strlonger; i++){

        if(sum[i]=='\0')sum[i]='0';
        if(input[i]=='\0')input[i]='0';

        //if carry
        if((sum[i]-48)+(input[i]-48)+carry>=10){
            sum[i] = ((sum[i]-48)+(input[i]-48)+carry-10)+48;
            carry = 1;
        }
            //if no carry
        else{
            sum[i] = ((sum[i]-48)+(input[i]-48)+carry)+48;
            carry = 0;
        }
    }

    if(carry==1)sum[i] = '1';

}

void reverse(char *input){
    int i,j;
    char temp[101];
    memset(temp,'\0',101);
    strcpy(temp,input);

    /*****negative number*****/
    if(input[0]=='-'){
        for(i=strlen(temp)-2,j=1; i>=0; i--,j++){
            input[i] = temp[j];
        }
        input[strlen(temp)-1] = '\0'; //Let negative sign disappeared
    }

    /*****positive number*****/
    else{
        for(i=strlen(temp)-1,j=0; i>=0; i--,j++){
            input[i] = temp[j];
        }
    }
}