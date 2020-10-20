#include <stdio.h>

int main(int argc, char const *argv[])
{
    char E[6][3], X[6][3], T[6][3], Y[6][3];
    // printf("  int  *  +  (  )  $\n");
    // printf("E ");
    printf("\n\tUse ! for empty cell-\n\n");
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("Enter (E,int):");
            scanf("%s", E[i]);
            break;
        case 1:
            printf("Enter (E,*):");
            scanf("%s", E[i]);
            break;
        case 2:
            printf("Enter (E,+):");
            scanf("%s", E[i]);
            break;
        case 3:
            printf("Enter (E,()):");
            scanf("%s", E[i]);
            break;
        case 4:
            printf("Enter (E,)):");
            scanf("%s", E[i]);
            break;
        case 5:
            printf("Enter (E,$):");
            scanf("%s", E[i]);
            break;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("Enter (X,int):");
            scanf("%s", X[i]);
            break;
        case 1:
            printf("Enter (X,*):");
            scanf("%s", X[i]);
            break;
        case 2:
            printf("Enter (X,+):");
            scanf("%s", X[i]);
            break;
        case 3:
            printf("Enter (X,()):");
            scanf("%s", X[i]);
            break;
        case 4:
            printf("Enter (X,)):");
            scanf("%s", X[i]);
            break;
        case 5:
            printf("Enter (X,$):");
            scanf("%s", X[i]);
            break;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("Enter (T,int):");
            scanf("%s", T[i]);
            break;
        case 1:
            printf("Enter (T,*):");
            scanf("%s", T[i]);
            break;
        case 2:
            printf("Enter (T,+):");
            scanf("%s", T[i]);
            break;
        case 3:
            printf("Enter (T,()):");
            scanf("%s", T[i]);
            break;
        case 4:
            printf("Enter (T,)):");
            scanf("%s", T[i]);
            break;
        case 5:
            printf("Enter (T,$):");
            scanf("%s", T[i]);
            break;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("Enter (Y,int):");
            scanf("%s", Y[i]);
            break;
        case 1:
            printf("Enter (Y,*):");
            scanf("%s", Y[i]);
            break;
        case 2:
            printf("Enter (Y,+):");
            scanf("%s", Y[i]);
            break;
        case 3:
            printf("Enter (Y,()):");
            scanf("%s", Y[i]);
            break;
        case 4:
            printf("Enter (Y,)):");
            scanf("%s", Y[i]);
            break;
        case 5:
            printf("Enter (Y,$):");
            scanf("%s", Y[i]);
            break;
        }
    }

    
    return 0;
}
