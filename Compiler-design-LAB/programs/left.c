#include <stdio.h>
#include <string.h>

void left_factor(char prods[])
{

    // printf("%s", prods);
    // Taking only one character common at once
    char cc = prods[0];
    int tempo = 0;
    while (cc != '>')
    {
        tempo++;
        cc = prods[tempo];
    }
    char common_char = prods[tempo + 1];
    //Stores the new production
    char new_prod[100];
    char ch = prods[0];

    int i = 0;
    while (ch != '-')
    {
        new_prod[i++] = ch;
        ch = prods[i];
    }

    strcat(new_prod, "\'");

    //Stored the modified production
    char modified_prod[100];
    i = 0;
    ch = prods[0];
    while (ch != '-')
    {
        modified_prod[i] = ch;
        i++;
        ch = prods[i];
    }
    // printf("COMMON: %c", common_char);
    char temp2[20] = {'-', '>', common_char};
    strcat(modified_prod, temp2);
    strcat(modified_prod, new_prod);
    strcat(modified_prod, "|");

    char temp[10] = {'-', '>'};
    strcat(new_prod, temp);

    //Stores if common found
    int common_found = 0;
    // printf("\nModified:%s\n", modified_prod);
    // printf("\nNew:%s\n", new_prod);

    ch = prods[0];
    i = 0;
    while (ch != '>')
    {
        i++;
        ch = prods[i];
    }

    int k = strlen(modified_prod);

    int j = 0;
    ch = new_prod[0];
    while (ch != '>')
    {
        j++;
        ch = new_prod[j];
    }
    j = j + 1;
    for (i = i + 1; i < strlen(prods); i++)
    {
        if (common_char == prods[i])
        {
            i = i + 1;
            char c = prods[i];
            while (c != '|' && c != '\0')
            {
                new_prod[j] = c;
                i++;
                j++;
                c = prods[i];
            }
            new_prod[j] = '|';
            j++;
            common_found++;
        }
        else
        {
            char c = prods[i];

            while (c != '|' && c != '\0')
            {
                modified_prod[k++] = c;
                i++;
                c = prods[i];
            }
            modified_prod[j] = '|';
        }
    }

    if (common_found > 1)
    {
        printf("%s\n", modified_prod);
        left_factor(new_prod);
    }
    else
    {
        printf("%s\n", prods);
    }
}

int main()
{
    char prod[100];
    printf("Enter The Production: ");
    scanf("%s", prod);

    printf("THE LEFT FACTORED GRAMMAR WOULD BE:\n");
    left_factor(prod);
}