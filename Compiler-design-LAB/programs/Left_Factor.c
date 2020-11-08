// #include <stdio.h>
// #include <string.h>

// void left_factor(char prods[])
// {

//     // printf("%s", prods);
//     // Taking only one character common at once
//     char cc = prods[0];
//     int tempo = 0;
//     while (cc != '>')
//     {
//         tempo++;
//         cc = prods[tempo];
//     }
//     char common_char = prods[tempo + 1];
//     //Stores the new production
//     char new_prod[100];
//     char ch = prods[0];

//     int i = 0;
//     while (ch != '-')
//     {
//         new_prod[i++] = ch;
//         ch = prods[i];
//     }

//     strcat(new_prod, "\'");

//     //Stored the modified production
//     char modified_prod[100];
//     i = 0;
//     ch = prods[0];
//     while (ch != '-')
//     {
//         modified_prod[i] = ch;
//         i++;
//         ch = prods[i];
//     }
//     // printf("COMMON: %c", common_char);
//     char temp2[20] = {'-', '>', common_char};
//     strcat(modified_prod, temp2);
//     strcat(modified_prod, new_prod);
//     strcat(modified_prod, "|");

//     char temp[10] = {'-', '>'};
//     strcat(new_prod, temp);

//     //Stores if common found
//     int common_found = 0;
//     // printf("\nModified:%s\n", modified_prod);
//     // printf("\nNew:%s\n", new_prod);

//     ch = prods[0];
//     i = 0;
//     while (ch != '>')
//     {
//         i++;
//         ch = prods[i];
//     }

//     int k = strlen(modified_prod);

//     int j = 0;
//     ch = new_prod[0];
//     while (ch != '>')
//     {
//         j++;
//         ch = new_prod[j];
//     }
//     j = j + 1;
//     for (i = i + 1; i < strlen(prods); i++)
//     {
//         if (common_char == prods[i])
//         {
//             i = i + 1;
//             char c = prods[i];
//             while (c != '|' && c != '\0')
//             {
//                 new_prod[j] = c;
//                 i++;
//                 j++;
//                 c = prods[i];
//             }
//             new_prod[j] = '|';
//             j++;
//             common_found++;
//         }
//         else
//         {
//             char c = prods[i];

//             while (c != '|' && c != '\0')
//             {
//                 modified_prod[k++] = c;
//                 i++;
//                 c = prods[i];
//             }
//             modified_prod[j] = '|';
//         }
//     }

//     if (common_found > 1)
//     {
//         printf("%s\n", modified_prod);
//         left_factor(new_prod);
//     }
//     else
//     {
//         printf("%s\n", prods);
//     }
// }

// int main()
// {
//     char prod[100];
//     printf("Enter The Production: ");
//     scanf("%s", prod);

//     printf("THE LEFT FACTORED GRAMMAR WOULD BE:\n");
//     left_factor(prod);
// }
#include<stdio.h>  
#include<string.h>  
int main()  
{  
     char gram[20],part1[20],part2[20],modifiedGram[20],newGram[20],tempGram[20];  
     int i,j=0,k=0,l=0,pos;  
     printf("Enter Production : A->");  
     fgets(gram,20,stdin);  
     for(i=0;gram[i]!='|';i++,j++)  
           part1[j]=gram[i];  
      part1[j]='\0';  
      for(j=++i,i=0;gram[j]!='\0';j++,i++)  
           part2[i]=gram[j];  
      part2[i]='\0';  
      for(i=0;i<strlen(part1)||i<strlen(part2);i++)  
      {  
           if(part1[i]==part2[i])  
           {  
                modifiedGram[k]=part1[i];  
                k++;  
                pos=i+1;  
           }  
      }  
      for(i=pos,j=0;part1[i]!='\0';i++,j++){  
           newGram[j]=part1[i];  
      }  
      newGram[j++]='|';  
      for(i=pos;part2[i]!='\0';i++,j++){  
           newGram[j]=part2[i];  
      }
      newGram[6]=' ';
      modifiedGram[k]='X';  
      modifiedGram[++k]='\0';  
      newGram[j]='\0';  
      printf("\t\n Left Factored Grammar -\n");
      printf("\n\t A->%s",modifiedGram);  
       printf("\n\t X-> %s\n\n\n",newGram);  
  }  