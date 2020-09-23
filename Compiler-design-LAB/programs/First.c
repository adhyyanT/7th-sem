#include<stdio.h>
#include<string.h>
// #include<stdbool.h>

char first[10][10];
int isPresent(char c,char rep[10]){
    for (int i=0;i<10;i++){
        if (c==rep[i]){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    printf("\n\n\tEnter the number of lines- ");
    int l;
    char productions[10][15];
    scanf("%d",&l);
    printf("\n\n\tNOTE - Use $ character to input NULL (Epsilon)");
    printf("\n\n\tEnter the productions - ");
    for (int i=0;i<l;i++){
        scanf("%s",productions[i]);
        printf("\t\t\t\t");
    }
    printf("\n");
    char lhs[10];
    for (int i=0;i<l;i++){
        lhs[i]='#';
    }
    l--;
    // for (int i=0;i<l;i++){
    //     puts(productions[i]);
    // }
    int k=0,m=0;
    for (int i=l;i>=0;i--){
        k=0;m=0;
        while(k<strlen(productions[i])){
            if (productions[i][k]=='-'){
                lhs[i]=productions[i][k-1];
                //printf("lhs-%c\n",lhs[i]);
            }
            if (productions[i][k]=='>'||productions[i][k]=='|'){
                if ((productions[i][k+1]>=97 && productions[i][k+1]<=122) || (productions[i][k+1]>=48 && productions[i][k+1]<=57)||(productions[i][k+1]=='$')){
                    first[i][m]=productions[i][k+1];m++;
                    //printf("%c\n",first[i][m]);
                }
                else{
                    for (int j=0;j<strlen(lhs);j++){
                        if (lhs[j]==productions[i][k+1]){
                            for (int z=0;first[j][z]!=0;z++){
                                first[i][m]=first[j][z];m++;
                            }
                            //printf("%s\n",first[i]);
                        }
                    }
                }
            }           
            k++;
        }
        first[i][m]=0;
    }
    char rep[10][10];
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            rep[i][j]=0;
        }
    }int j=0;
    for (int i=0;i<=l;i++){
        //printf("%c=%s\n",lhs[i],first[i]);
        // for (int j=0;j<strlen(first[i]);j++){
        //     printf("%c",first[i][j]);
        // }
        // printf("\n");
        // printf("%d\n",strlen(first[i]));
        for (j=0;j<strlen(first[i]);j++){
            if (isPresent(first[i][j],rep[i])==0){
                rep[i][j]=first[i][j];
            }
        }
        rep[i][j]=0;
    }
    printf("\t\tFirst sets ->\n");
    for (int i=0;i<=l;i++){
        printf("\t\t\t\tFIRST(%c) = { ",lhs[i]);
        for (int y=0;rep[i][y]!=0;y++){
            if (y==0){
                printf("%c",rep[i][y]);    
            }
            else{
                printf(",%c",rep[i][y]);
            }
        }
        printf(" }");
        printf("\n");
    }
    printf("\n\n\n");
    return 0;
}
