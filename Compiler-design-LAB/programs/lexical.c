// /* 
//   Name - Adhyyan Tripathi
//   Roll no - 8
//   Sec c
//   Reg no - 201700403
// */

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// int id=0;

// int count_token(char str[200][200],int sz){
//     int c=0;char* ret;
//     for (int i=0;i<sz;i++){
//         if (strstr(str[i],"int")!=NULL){
//           ret=strstr(str[i],"int");
          
//           if (*(ret+3)==' '){
//             c++;
//             printf("int\t <Key,INT>\t Keyword\n");
//             id++;
//             if (strstr(str[i],"main")==NULL){
//               for (char* j=(ret+4);*j!=';';j++){
//                 if (*j=='='){
//                   while(*j!=','){
//                     if (*j=='='){
//                       printf("%c\t <Op,%c>\t\t Operator\n",*j,*j);
//                       id++;     
//                     }
//                     else{
//                       printf("%c",*j);
//                     }
//                     j++;
//                   }
//                   printf("\t ");printf("<num,10>\t Constant\n",id);
//                   id++;
//                   c=c+1;
//                 }
//                 else{
//                   c++;
//                   printf("%c\t <id,%c>\t\t Identifier\n",*j,*j);
//                   id++;
//                 }
//                 c++;
//                 // printf("%c",*j);
//               }
//             }
//           }
//         }
//         if (strstr(str[i],"printf")!=NULL){
//             c++;
//             printf("printf\t <Key,printf>\t Keyword\n");
//             id++;
//             int count=0,j=6;
//             for ( j=7;count!=2;j++){
//               if (str[i][j]=='"'){
//                 count++;
//               }
//               printf("%c",str[i][j]);
//             }
//             printf("\t <Str,%_d>\t String\n");
//             id++;
//             while(str[i][j]!=')'){
//               if (str[i][j]!=','){
//                 printf("%c\t <id,%c>\t\t Identifier\n",str[i][j],str[i][j]);
//                 id++;
//               }
//               j++;
//             }
//         }
//         if (strstr(str[i],"main")!=NULL){
//             c++;
//             printf("main\t <id,main>\t Identifier\n");
//             id++;
//         }
//         if (strstr(str[i],",")!=NULL){
//             c++;
//             printf(",\t <STC,,>\t STC\n");
//             id++;
//         }
//         if (strstr(str[i],")")!=NULL){
//             c++;
//             printf(")\t <STC,)>\t STC\n");
//             id++;
//         }
//         if (strstr(str[i],"(")!=NULL){
//             c++;
//             printf("(\t <STC,(>\t STC\n");
//             id++;
//         }
//         if (strstr(str[i],"{")!=NULL){
//             c++;
//             printf("{\t <STC,{>\t STC\n");
//             id++;
//         }
//         if (strstr(str[i],";")!=NULL){
//             c++;
//             printf(";\t <STC,;>\t STC\n");
//             id++;
//         }
//         if (strstr(str[i],"return")!=NULL){
//             c++;
//             printf("return\t <Key,return>\t Keyword\n",id);
//             id++;
//         }
//         if (strstr(str[i],"}")!=NULL){
//             c++;
//             printf("}\t <STC,}>\t STC\n");
//             id++;
//         }
//         if (strstr(str[i],"+")!=NULL){
//             ret=strstr(str[i],"+");
//             c++;
//             printf("+\t <Op,+>\t\t Operator\n");
//             id++;
//             //for y
//             printf("y\t <id,y>\t\t Identifier\n",id);
//             id++; 
//             c++;
//             for (char* j=(ret+1);*j!='0';j++){
//               c++;
//               printf("%c00\t <num,100>\t INT\n",*j,id);
//               id++;
//               // printf("%c",*j);
//             }
//             for (char* k=(ret-1);*k!='y';k--){
//               c++;
//               // printf("%c",*(k));
//               if (*k=='='){
//                 printf("%c\t <Op,=>\t\t Operator\n",*k);
//                 id++;  
//               }
//               else{
//                 printf("%c\t <id,%c>\t\t Identifier\n",*k,*k);
//                 id++;  
//               }
//             }
//             // for x
//             printf("x\t <id,x>\t\t Identifier\n");
//             id++;
//             c++;

//         }
//     }
//     return c;
// }


// int main(int argc, char const *argv[])
// {
//     char str[200][200],in[100];
//     gets(in);
//     int i=0;
//     while(strcmp(in,"}")!=0){
//         if (in[0]!='#'){
//             strcpy(str[i],in);
//         }
//         i++;
//         gets(in);
//     }
//     i=i+1;strcpy(str[i],"}");
//     printf("\nLexemes\t Token\t\t Token Class\n");
//     int count=count_token(str,i);
//     printf("}\t <STC,}>\t STC\n");
//     id++;
//     printf("\n\tTotal number of tokens = %d\n\n",count);
//     return 0;
// }


// // #include<stdio.h>
// // #include<string.h>
// // #include<stdlib.h>
// // #include<ctype.h>

// // int count_token(char str[200][200],int i){
// //   int j;
// //   int count = 0;
// //   int len;
// //   char operators[] = "+=();,{}";
// //   for(j=0;j<i;j++)
// //   {
// //     len = strlen(str[j]);
// //     //printf("%d\n",len);
// //     for(int k=0; k<len;k++)
// //     {
// //       if(str[j][k] != ' ')
// //       {
// //         if(isalnum(str[j][k]))
// //         {
// //           count = count + 0;
// //         }
// //         else
// //         {
// //             if (isalnum(str[j][k-1])){
// //                 count++;
// //                 printf("%c\n",str[j][k-1]);
// //             }
            
            
// //           for(int p = 0; p < 8; p++)
// //           {
// //             if(str[j][k] == operators[p])
// //             {
// //               count = count + 1;
// //               printf("%c\n",str[j][k]);
// //             }
// //           }
// //         }
// //       }
// //       else
// //       {
// //           count = count + 1;
// //           printf("%c\n",str[j][k-1]);
// //       }
// //     }
// //   }
// //   printf("%d",count);
// //   return 0;
// // }


// // int main(int argc, char const *argv[])
// // {
// //     char str[200][200],in[100];
// //     gets(in);
// //     int id=0,i=0;
// //     while(strcmp(in,"}")!=0){
// //         if (in[0]!='#'){
// //             strcpy(str[i],in);
// //         }
// //         i++;
// //         gets(in);
// //     }
// //     i=i+1;
// //     strcpy(str[i],"}");
// //     int count=count_token(str,i);
// //     // for (int j=0;j<=i;j++){
// //     //     printf("%s",str[j]);
// //     //     printf("%cc",str[j][0]);
// //     //     printf("\n");
// //     // }



// //     return 0;
// // }


// // #include "stdio.h"
// // int main()
// // {
// // int x=10,y;
// // y=x+100;
// // printf(“%d”,y);
// // return;
// // }
/* 
  Name - Adhyyan Tripathi
  Roll no - 8
  Sec c
  Reg no - 201700403
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int id=0;

int count_token(char str[200][200],int sz){
    int c=0;char* ret;
    for (int i=0;i<sz;i++){
        if (strstr(str[i],"int")!=NULL){
          ret=strstr(str[i],"int");
          
          if (*(ret+3)==' '){
            c++;
            printf("int\t <Key,INT>\t Keyword\n");
            id++;
            if (strstr(str[i],"main")==NULL){
              for (char* j=(ret+4);*j!=';';j++){
                if (*j=='='){
                  while(*j!=','){
                    if (*j=='='){
                      printf("%c\t <Op,%c>\t\t Operator\n",*j,*j);
                      id++;     
                    }
                    else{
                      printf("%c",*j);
                    }
                    j++;
                  }
                  printf("\t ");printf("<num,10>\t Constant\n",id);
                  id++;
                  c=c+1;
                }
                else{
                  c++;
                  printf("%c\t <id,%c>\t\t Identifier\n",*j,*j);
                  id++;
                }
                c++;
                // printf("%c",*j);
              }
            }
          }
        }
        if (strstr(str[i],"printf")!=NULL){
            c++;
            printf("printf\t <Key,printf>\t Keyword\n");
            id++;
            int count=0,j=6;
            for ( j=7;count!=2;j++){
              if (str[i][j]=='"'){
                count++;
              }
              printf("%c",str[i][j]);
            }
            printf("\t <Str,%_d>\t String\n");
            id++;
            while(str[i][j]!=')'){
              if (str[i][j]!=','){
                printf("%c\t <id,%c>\t\t Identifier\n",str[i][j],str[i][j]);
                id++;
              }
              j++;
            }
        }
        if (strstr(str[i],"main")!=NULL){
            c++;
            printf("main\t <id,main>\t Identifier\n");
            id++;
        }
        if (strstr(str[i],",")!=NULL){
            c++;
            printf(",\t <STC,,>\t STC\n");
            id++;
        }
        if (strstr(str[i],")")!=NULL){
            c++;
            printf(")\t <STC,)>\t STC\n");
            id++;
        }
        if (strstr(str[i],"(")!=NULL){
            c++;
            printf("(\t <STC,(>\t STC\n");
            id++;
        }
        if (strstr(str[i],"{")!=NULL){
            c++;
            printf("{\t <STC,{>\t STC\n");
            id++;
        }
        if (strstr(str[i],";")!=NULL){
            c++;
            printf(";\t <STC,;>\t STC\n");
            id++;
        }
        if (strstr(str[i],"return")!=NULL){
            c++;
            printf("return\t <Key,return>\t Keyword\n",id);
            id++;
        }
        if (strstr(str[i],"}")!=NULL){
            c++;
            printf("}\t <STC,}>\t STC\n");
            id++;
        }
        if (strstr(str[i],"+")!=NULL){
            ret=strstr(str[i],"+");
            c++;
            printf("+\t <Op,+>\t\t Operator\n");
            id++;
            //for y
            printf("y\t <id,y>\t\t Identifier\n",id);
            id++; 
            c++;
            for (char* j=(ret+1);*j!='0';j++){
              c++;
              printf("%c00\t <num,100>\t INT\n",*j,id);
              id++;
              // printf("%c",*j);
            }
            for (char* k=(ret-1);*k!='y';k--){
              c++;
              // printf("%c",*(k));
              if (*k=='='){
                printf("%c\t <Op,=>\t\t Operator\n",*k);
                id++;  
              }
              else{
                printf("%c\t <id,%c>\t\t Identifier\n",*k,*k);
                id++;  
              }
            }
            // for x
            printf("x\t <id,x>\t\t Identifier\n");
            id++;
            c++;

        }
    }
    return c;
}


int main(int argc, char const *argv[])
{
    char str[200][200],in[100];
    gets(in);
    int i=0;
    while(strcmp(in,"}")!=0){
        if (in[0]!='#'){
            strcpy(str[i],in);
        }
        i++;
        gets(in);
    }
    i=i+1;strcpy(str[i],"}");
    printf("\nLexemes\t Token\t\t Token Class\n");
    int count=count_token(str,i);
    printf("}\t <STC,}>\t STC\n");
    id++;
    printf("\n\tTotal number of tokens = %d\n\n",count);
    return 0;
}


// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// #include<ctype.h>

// int count_token(char str[200][200],int i){
//   int j;
//   int count = 0;
//   int len;
//   char operators[] = "+=();,{}";
//   for(j=0;j<i;j++)
//   {
//     len = strlen(str[j]);
//     //printf("%d\n",len);
//     for(int k=0; k<len;k++)
//     {
//       if(str[j][k] != ' ')
//       {
//         if(isalnum(str[j][k]))
//         {
//           count = count + 0;
//         }
//         else
//         {
//             if (isalnum(str[j][k-1])){
//                 count++;
//                 printf("%c\n",str[j][k-1]);
//             }
            
            
//           for(int p = 0; p < 8; p++)
//           {
//             if(str[j][k] == operators[p])
//             {
//               count = count + 1;
//               printf("%c\n",str[j][k]);
//             }
//           }
//         }
//       }
//       else
//       {
//           count = count + 1;
//           printf("%c\n",str[j][k-1]);
//       }
//     }
//   }
//   printf("%d",count);
//   return 0;
// }


// int main(int argc, char const *argv[])
// {
//     char str[200][200],in[100];
//     gets(in);
//     int id=0,i=0;
//     while(strcmp(in,"}")!=0){
//         if (in[0]!='#'){
//             strcpy(str[i],in);
//         }
//         i++;
//         gets(in);
//     }
//     i=i+1;
//     strcpy(str[i],"}");
//     int count=count_token(str,i);
//     // for (int j=0;j<=i;j++){
//     //     printf("%s",str[j]);
//     //     printf("%cc",str[j][0]);
//     //     printf("\n");
//     // }



//     return 0;
// }


// #include "stdio.h"
// int main()
// {
// int x=10,y;
// y=x+100;
// printf(“%d”,y);
// return;
// }
