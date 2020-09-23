#include<stdio.h>
#include<string.h>
int main()
{
  char non_terminal;
  char production[10][30];
  int num;
  int j;
  int index;
  char terminal[10][20];
  char terminal_first[10][20];
  int p=-1;
  int ptwo = -1;
  printf("Enter the number of production : ");
  scanf("%d",&num);
  printf("Enter the grammar: \n");
  for(int i=0;i<num;i++){
       scanf("%s",production[i]);
  }
  index = 3;
  for(int i=0;i<num;i++)
  {
    non_terminal = production[i][0];
    j = index;
    while(j<strlen(production[i]))
    {
      if(production[i][j] == non_terminal)
      {
        j = j+1;
        p = p+1;
        int t = 0;
        while(production[i][j] != '|')
        {
          if(t == 0)
          {
            terminal[p][0] = production[i][j];
          }
          else
          {
            terminal[p][t] = production[i][j];
            terminal[p][t+1] = '\0';
          }
          t = t+1;
          j = j+1;
          if(j == strlen(production[i]))
          {
            break;
          }
        }
        j = j+1;
      }
      else
      {
        ptwo = ptwo+1;
        int ttwo = 0;
        while(production[i][j] != '|')
        {
          if(ttwo == 0)
          {
            terminal_first[ptwo][0] = production[i][j];
            terminal_first[ptwo][1] = '\0';
          }
          else
          {
            terminal_first[ptwo][ttwo] = production[i][j];
            terminal_first[ptwo][ttwo+1] = '\0';
          }
          ttwo = ttwo+1;
          j = j+1;
          if(j == strlen(production[i]))
          {
            break;
          }
        }
        j = j+1;
      }
    }
  }
  printf("The required grammar is: \n");
  printf("%c",non_terminal);
  printf("->");
  for(int i=0;i<=ptwo;i++)
  {
    if(i>0)
    {
      printf("|");
    }
    for(int j=0; terminal_first[i][j] != '\0'; j++)
    {
        printf("%c",terminal_first[i][j]);
    }
    printf("%c",non_terminal);
    printf("1");
  }
  printf("\n");
  printf("%c",non_terminal);
  printf("1->");
  for(int i=0;i<=p;i++)
  {
    if(i>0)
    {
      printf("|");
    }
    for(int j=0; terminal[i][j] != '\0'; j++)
    {
        printf("%c",terminal[i][j]);
    }
    printf("%c1",non_terminal);
  }
  printf("|null");
}
