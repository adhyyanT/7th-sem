/* 
  Name - Adhyyan Tripathi
  Roll no - 8
  Sec c
  Reg no - 201700403
  Question no - 1

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int inVar(char c, int size, char var[10], char blank[100]);

int main(int argc, char const *argv[])
{
    char input[100], blank[100], lhs;
    int c = 0, d = 0, prod = 0;
    printf("\n\nEnter the number of Productions- ");
    scanf("%d", &prod);
    if (prod > 1)
    {
        char input2[100];
        printf("\n\nEnter the CFG -\t");
        // fgets(input2, 100, stdin);
        // fgets(input, 100, stdin);
        scanf("%s",input2);printf("\t\t");
        scanf("%s",input);printf("\n\n");
        while (input[c] != '\0')
        {
            if (input[c] != ' ')
            {
                blank[d++] = input[c];
            }
            c++;
        }
        blank[d] = '\0';
        lhs = blank[0];
        c = 0, d = 0;
        int rule_C = 0, size = 0;
        for (int i = 3; blank[i] != '\0'; i++)
        {
            size++;
        }
        size--;
        char var[10], ter[10];
        

        char rule[10][10];
        for (int i = 3; i < size + 3; i++)
        {
            if (blank[i] == '|')
            {
                rule[rule_C][d] = '\0';
                rule_C++;
                d = 0;
            }
            else
            {
                rule[rule_C][d] = blank[i];
                d++;
            }
        }
        rule[rule_C][d] = '\0';
        //printf("\n%s",rule[0]);
        printf("Eliminating Left Recursion -\n\n");
        printf("\t%s\n",input2);
        printf("\t%c -> ", lhs);
        for (int i = 0; i <= rule_C; i++)
        {
            if (lhs != rule[i][0])
            {
                printf("%s%c'", rule[i], lhs);
            }
        }
        printf("\n\t%c' -> ", lhs);
        for (int i = 0; i <= rule_C; i++)
        {
            if (lhs == rule[i][0])
            {
                for (int j = 1; rule[i][j] != '\0'; j++)
                {
                    printf("%c", rule[i][j]);
                }
                printf("%c'", lhs);
                printf("|");
            }
            if (i == rule_C)
            {
                printf(" NULL\n\n");
            }
        }
        strcat(blank,input2);
        for (int i = 0; i < size + 3+8; i++)
        {
            if (blank[i] >= 65 && blank[i] <= 90 && inVar(blank[i], size, var, blank) == false)
            {
                var[c] = blank[i];
                c++;
            }
        }
        var[c] = '\0';
        c = 0;
        for (int i = 0; i < size + 3+9; i++)
        {
            if ((blank[i] >= 65 && blank[i] <= 90) || (blank[i] == '-' || blank[i] == '>' || blank[i] == '|'))
            {
                continue;
            }
            else
            {
                if (inVar(blank[i], size, ter, blank) == false)
                {
                    ter[c] = blank[i];
                    c++;
                }
            }
        }
        ter[c] = '\0';
        printf("\n");
        c = 0, d = 0;
        printf("\t|-----------------------|\n");
        printf("\t| Variables | Terminals |\n");
        printf("\t|-----------------------|\n");
        for (int i = 0; i < strlen(ter); i++)
        {

            if (i > strlen(var))
            {
                printf("\t|           |     %c     |\n", ter[i]);
            }
            else if (i == strlen(var))
            {
                printf("\t|           |     %c     |\n", ter[i]);
            }
            else
            {
                printf("\t|     %c     |     %c     |\n", var[i], ter[i]);
            }
        }
        printf("\t|-----------------------|\n\n");
    }
    else
    {
        printf("\n\nEnter the CFG -\t");
        //fgets(input, 100, stdin);
        scanf("%s",input);
        while (input[c] != '\0')
        {
            if (input[c] != ' ')
            {
                blank[d++] = input[c];
            }
            c++;
        }
        blank[d] = '\0';
        lhs = blank[0];
        c = 0, d = 0;
        int rule_C = 0, size = 0;
        for (int i = 3; blank[i] != '\0'; i++)
        {
            size++;
        }
        size--;
        char var[10], ter[10];
        for (int i = 0; i < size + 3; i++)
        {
            if (blank[i] >= 65 && blank[i] <= 90 && inVar(blank[i], size, var, blank) == false)
            {
                var[c] = blank[i];
                c++;
            }
        }
        var[c] = '\0';
        c = 0;
        for (int i = 0; i < size + 3; i++)
        {
            if ((blank[i] >= 65 && blank[i] <= 90) || (blank[i] == '-' || blank[i] == '>' || blank[i] == '|'))
            {
                continue;
            }
            else
            {
                if (inVar(blank[i], size, ter, blank) == false)
                {
                    ter[c] = blank[i];
                    c++;
                }
            }
        }
        ter[c] = '\0';
        printf("\n");
        c = 0, d = 0;
        printf("\t|-----------------------|\n");
        printf("\t| Variables | Terminals |\n");
        printf("\t|-----------------------|\n");
        for (int i = 0; i < strlen(ter); i++)
        {

            if (i > strlen(var))
            {
                printf("\t|           |     %c     |\n", ter[i]);
            }
            else if (i == strlen(var))
            {
                printf("\t|           |     %c     |\n", ter[i]);
            }
            else
            {
                printf("\t|     %c     |     %c     |\n", var[i], ter[i]);
            }
        }
        printf("\t|-----------------------|\n\n");

        char rule[10][10];
        for (int i = 3; i < size + 3; i++)
        {
            if (blank[i] == '|')
            {
                rule[rule_C][d] = '\0';
                rule_C++;
                d = 0;
            }
            else
            {
                rule[rule_C][d] = blank[i];
                d++;
            }
        }
        rule[rule_C][d] = '\0';
        //printf("\n%s",rule[0]);
        printf("Eliminating Left Recursion -\n\n");
        printf("\t%c -> ", lhs);
        for (int i = 0; i <= rule_C; i++)
        {
            if (lhs != rule[i][0])
            {
                printf("%s%c'", rule[i], lhs);
            }
        }
        printf("\n\t%c' -> ", lhs);
        for (int i = 0; i <= rule_C; i++)
        {
            if (lhs == rule[i][0])
            {
                for (int j = 1; rule[i][j] != '\0'; j++)
                {
                    printf("%c", rule[i][j]);
                }
                printf("%c'", lhs);
                printf("|");
            }
            if (i == rule_C)
            {
                printf(" NULL\n\n");
            }
        }
    }
    return 0;
}
int inVar(char c, int size, char var[10], char blank[100])
{
    for (int i = 0; i < strlen(var); i++)
    {
        if (var[i] == c)
        {
            return true;
        }
    }
    return false;
}