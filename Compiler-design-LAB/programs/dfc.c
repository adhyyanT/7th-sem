/* 
    Name- Adhyyan Tripathi
    Roll no -8
    Section -C
    Reg no - 201700403
*/     

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int final=0;

void q0(int input[],int i,int table[4][2]);
void q1(int input[],int i,int table[4][2]);
void q2(int input[],int i,int table[4][2]);
void q3(int input[],int i,int table[4][2]);

int main(){
    int n;
    int input[100];
    
    char ch_input[100];
    printf("\nEnter the String. Example - 010101. To enter Empty String type NULL\n");
    scanf("%s",ch_input);
    if (strcmp(ch_input,"NULL")==0){
        strcpy(ch_input,"");
    }
    n=strlen(ch_input);
    for (int i=0;i<strlen(ch_input);i++){
        input[i]=ch_input[i]-'0';
    }
    for (int i=n;i<100;i++){
        input[i]=2;
    }
    int table[4][2];
    table[0][0]=3;table[0][1]=1;
    table[1][0]=2;table[1][1]=0;
    table[2][0]=1;table[2][1]=3;
    table[3][0]=0;table[3][1]=2;
    printf("\nInitial state = Q0\n");
    printf("Final state = Q3\n");
    printf("\n\n");
    printf("S|I \t 0 \t 1 \t\n");
    for (int i=0;i<4;i++){
        printf("Q%d \t",i);
        for (int j=0;j<2;j++){
            printf("Q%d \t",table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int i=0;
    printf("Sequence of the input transition = Q0");
    q0(input,i,table);
    printf("\n\n");
    if (final==3){
        for (int i=0;i<n;i++){
            printf("%d ",input[i]);
        }
        printf(" -- ACCEPTED\n\n");
    }
    else{
        for (int i=0;i<n;i++){
            printf("%d ",input[i]);
        }
        printf(" -- REJECTED\n\n");
    }

    


    // char *ptr = (char*) malloc(n * sizeof(char));
    // for (int i=0;i<n;i++){
    //     scanf("%c",(ptr+i));
    // }
    // for (int i=0;i<n;i++){
    //     printf("%c",(ptr+i));
    // }printf("%d-Q0",input[i]);
    



    return 0;

}

void q1(int input[],int i,int table[4][2]){
    if (input[i]==0){
        printf("-%d-Q2",input[i]);
        i++;
        final=2;
        
        q2(input,i,table);
    }
    else if (input[i]==1){
        printf("-%d-Q0",input[i]);
        i++;
        final=0;
        
        q0(input,i,table);
    }
}


void q2(int input[],int i,int table[4][2]){
    if (input[i]==0){
        printf("-%d-Q1",input[i]);
        i++;
        final=1;
        
        q1(input,i,table);
    }
    else if (input[i]==1){
        printf("-%d-Q3",input[i]);
        i++;
        final=3;
        
        q3(input,i,table);
    }
}


void q3(int input[],int i,int table[4][2]){
    if (input[i]==0){
        printf("-%d-Q0",input[i]);
        i++;
        final=0;
        
        q0(input,i,table);
    }
    else if (input[i]==1){
        printf("-%d-Q2",input[i]);
        i++;
        final=2;
        
        q2(input,i,table);
    }
}



void q0(int input[],int i,int table[4][2]){
    if (input[i]==0){
        printf("-%d-Q3",input[i]);
        i++;
        final=3;
        
        q3(input,i,table);
    }
    else if (input[i]==1){
        printf("-%d-Q1",input[i]);
        i++;
        final=1;
        
        q1(input,i,table);
    }
}