#include <stdio.h>
#include <string.h>

void minus(char*, char*);
void plus(char*, char*);
void multiply(char*, char*);
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
                if(sum[strlen(sum)-1]=='-'){

                    //Let sum's negative sign disappeared
                    sum[strlen(sum)-1] = '\0';

                    plus(sum,input);

                    sum[strlen(sum)] = '-';
                }

                else{ //+1-2=-1
                    minus(sum,input);
                }

            }
            /*******plus******/
            else if (48 <= input[0] && input[0] <= 57){

                //-10+5 = -5
                if(sum[strlen(sum)-1]=='-'){

                    //Let sum's negative sign disappeared
                    sum[strlen(sum)-1] = '\0';

                    minus(sum,input);

                    //If the result is negative, make it positive
                    if(sum[strlen(sum)-1]=='-'){
                        sum[strlen(sum)-1] = '\0';
                    }

                    //If 0, don't add negative sign
                    else if(!strcmp(sum,"0")){
                        sum[strlen(sum)-1] = '0';
                    }

                    //If positive, make it negative
                    else{
                        sum[strlen(sum)] = '-';
                    }

                }
                //+10+10=+20
                else{
                    plus(sum,input);
                }
            }
            /*******multiply******/
            if (input[0]=='*'){
                if (input[1] == '-'){

                    //-2 * -3 = 6
                    if (sum[strlen(sum)-1] == '-'){
                        sum[strlen(sum)-1] = '\0';
                        multiply(sum,input);
                    }
                    // 2 * -3 = -6
                    else{
                        multiply(sum,input);
                        sum[strlen(sum)] = '-';
                    }

                }
                else{
                    //-2 * 3 = -6
                    if (sum[strlen(sum)-1] == '-'){
                        sum[strlen(sum)-1] = '\0';
                        multiply(sum,input);
                        sum[strlen(sum)] = '-';
                    }
                    //2 * 3 = 6
                    else {
                        multiply(sum,input);
                    }
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

    if(carry == 1)sum[i] = '1';

}

void multiply(char *sum, char* input){
    int i,j,k;

    reverse(input);

    char temp[10001];
    memset(temp,'\0',10001);

    //Set temp's front number as 0
    for (k = 0; k < strlen(sum)+strlen(input); k++) {
        temp[k] = '0';
    }

    //Many temps to add
    for (i = 0; i < strlen(input); i++) {

        int multiply_carry = 0;
        int add_carry = 0;

        //Run every digit from left to right
        for (j = 0; j < strlen(sum); j++){

            temp[i+j] += ((sum[j]-48)*(input[i]-48) + multiply_carry + add_carry)%10;

            //Carry while multiplying
            multiply_carry = ((sum[j]-48)*(input[i]-48)+multiply_carry + add_carry)/10;

            //Carry while adding
            if (temp[i+j] > '9'){
                temp[i+j] = temp[i+j]-10;
                add_carry = 1;
            }
            else if ('0' <= temp[i+j] && temp[i+j] <= '9'){
                add_carry = 0;
            }
        }

        /*If the front digit still carries,
        *add the digit that is carried at the front
        */
        if (multiply_carry != 0) {
            temp[i+j] = multiply_carry + 48;
        }
        if (add_carry != 0){
            temp[i+j] += 1;
        }
    }

    //Let the front 0 disappeared
    if (temp[strlen(temp)-1] == '0'){
        temp[strlen(temp)-1] = '\0';
    }

    strcpy(sum, temp);

}


void reverse(char *input){
    int i,j;
    char temp[10001];
    memset(temp,'\0',10001);
    strcpy(temp,input);

    /**********negative number**********/
    if(input[0]=='-'){
        for(i=strlen(temp)-2,j=1; i>=0; i--,j++){
            input[i] = temp[j];
        }

        //Let negative sign disappeared
        input[strlen(temp)-1] = '\0';
    }

    /**********positive number**********/
    else if('0' <= input[0] && input[0]<='9'){
        for(i=strlen(temp)-1,j=0; i>=0; i--,j++){
            input[i] = temp[j];
        }
    }

    /**********multiplication sign**********/

    /**multiply positive number**/
    else if(input[0]=='*' && input[1]!='-'){
        for(i=strlen(temp)-2,j=1; i>=0; i--,j++){
            input[i] = temp[j];
        }

        //Let multiply sign disappeared
        input[strlen(temp)-1] = '\0';
    }

    /**multiply negative number**/
    else if (input[0]=='*' && input[1]=='-'){
        for(i=strlen(temp)-3,j=2; i>=0; i--,j++){
            input[i] = temp[j];
        }

        //Let multiply sign disappeared
        input[strlen(temp)-1] = '\0';
        input[strlen(temp)-2] = '\0';
    }
}