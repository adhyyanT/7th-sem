#include <stdio.h>
#include <string.h>

int bottomsUp();
int main()
{
    printf("\n\tGrammar is -\n\tS->aABe \n\tA->Abc|b \n\tB->d\n");
    printf("\n\tEnter the string : ");
    char input[20];
    scanf("%s", input);
    char og[20];
    strcpy(og, input);
    int output = bottomsUp(input);
    if (output == 1)
    {
        printf("\n\n\tYes, \"%s\" can be parsed.\n\n", og);
    }
    else
    {
        printf("\n\n\tNo, \"%s\" cannot be parsed.\n\n", og);
    }
    return 0;
}

int bottomsUp(char input[20])
{
    printf("\n\n\t\tSTACK    |  Handle  |  Reducing Production\n");
    printf("\t--------------------------------------------------\n");
    char *ptr;
    // printf("\t   $%s\t |          |\t         \n", input);
    printf("\t   $%s\t |", input);
    for (int i = 0; input[i] != '\0'; i++)
    {
    start:
        for (int j = 0; j < strlen(input); j++)
        {
            int flag = 0;
            if (input[j] == 'a' && input[j + 1] == 'A' && input[j + 2] == 'B' && input[j + 3] == 'e')
            {
                flag = 2;
                input[j] = 'S';
                int l = j + 1;
                for (int k = j + 4; k < strlen(input); k++)
                {
                    flag = 1;
                    input[l] = input[k];
                    l++;
                }
                if (flag == 2 || flag == 1 || strlen(input) == 4)
                {
                    input[l] = '\0';
                }
                printf("   aAbe   |\t  A->aABe\n");
                printf("\t   $%s\t\t |", input);
                //printf("\t   $%s\t\t |   aABe   |\t  S->aABe\n", input);
            }
        }
        for (int j = 0; j < strlen(input); j++)
        {
            int flag = 0;
            if (input[j] == 'A' && input[j + 1] == 'b' && input[j + 2] == 'c')
            {
                flag = 2;
                input[j] = 'A';
                int l = j + 1;
                for (int k = j + 3; k < strlen(input); k++)
                {
                    flag = 1;
                    input[l] = input[k];
                    l++;
                }
                if (flag == 2 || flag == 1 || strlen(input) == 3)
                {
                    input[l] = '\0';
                    printf("   Abc    |\t  A->Abc\n");
                    printf("\t   $%s\t |", input);
                    //printf("\t   $%s\t |   Abc    |\t  A->Abc\n", input);
                    goto start;
                }
            }
        }
        if (input[i] == 'b')
        {
            input[i] = 'A';
            printf("    b     |\t  A->b\n");
            printf("\t   $%s\t |", input);
            //printf("\t   $%s\t |    A     |\t  A->b\n", input);
            goto start;
        }
        if (input[i] == 'd')
        {
            input[i] = 'B';
            //printf("\t   $%s\t |    d     |\t  B->d\n", input);
            printf("    d     |\t  B->d\n");
            printf("\t   $%s\t |", input);
            goto start;
        }
    }
    printf("          |\t \n");
    if (input[0] == 'S' && strlen(input) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}