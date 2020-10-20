#include <stdio.h>
#include <string.h>
char stack[20] = {'$'};
char input[4];
void append_stack(int i, int j, char arr[4][23])
{
  int len;
  int k = 2;

  do
  {
    if (arr[i][j + k] != '_' && arr[i][j + k] != '#')
    {
      len = strlen(stack);
      stack[len] = arr[i][j + k];
    }
    k = k - 1;
  } while (k >= 0);
}
void E(char arr[4][23], int top)
{
  char input_char;
  input_char = input[top];
  if (input_char == 'i')
  {
    append_stack(0, 0, arr);
  }
  else if (input_char == '(')
  {
    append_stack(0, 12, arr);
  }
}

void X(char arr[4][23], int top)
{
  char input_char;
  input_char = input[top];
  if (input_char == '+')
  {
    append_stack(1, 8, arr);
  }
  else if (input_char == ')')
  {
    append_stack(0, 16, arr);
  }
}

void T(char arr[4][23], int top)
{
  char input_char;
  input_char = input[top];
  if (input_char == 'i')
  {
    append_stack(2, 0, arr);
  }
  else if (input_char == '(')
  {
    append_stack(2, 12, arr);
  }
}

void Y(char arr[4][23], int top)
{
  char input_char;
  input_char = input[top];
  if (input_char == '*')
  {
    append_stack(3, 4, arr);
  }
  else if (input_char == '+')
  {
    append_stack(3, 8, arr);
  }
  else if (input_char == ')')
  {
    append_stack(3, 16, arr);
  }
  else if (input_char == '$')
  {
    append_stack(3, 20, arr);
  }
}

int main()
{
  char arr[4][23] = {
      {'T', 'X', '_', '#', '_', '_', '_', '#', '_', '_', '_', '#', 'T', 'X', '_', '#', '_', '_', '_', '#', '_', '_', '_'},
      {'_', '_', '_', '#', '_', '_', '_', '#', '+', 'E', '_', '#', '_', '_', '_', '#', 'n', '_', '_', '#', 'n', '_', '_'},
      {'i', 'Y', '_', '#', '_', '_', '_', '#', '_', '_', '_', '#', '(', 'E', ')', '#', '_', '_', '_', '#', '_', '_', '_'},
      {'_', '_', '_', '#', '*', 'T', '_', '#', 'n', '_', '_', '#', '_', '_', '_', '#', 'n', '_', '_', '#', 'n', '_', '_'}};
  int no;
  char c;
  printf("Enter the input string: ");
  int i = 0;
  char inputo[20];
  fgets(inputo, 20, stdin);
  int j = 0;
  while (i < strlen(inputo))
  {
    //printf("%c",input[i]);
    if (inputo[i] == 'i')
    {
      input[j] = 'i';
      j = j + 1;
      i = i + 3;
    }
    else
    {
      input[j] = inputo[i];
      j = j + 1;
      i = i + 1;
    }
  }
  //printf("\n");
  int le;
  le = strlen(input);
  //printf("\nLL %d\n",le);
  input[le - 1] = '$';
  char non[4] = {'E', 'X', 'T', 'Y'};
  int top = 0;
  int stack_top;
  E(arr, 0);
  int count = 0;
  printf("\n\n----------- The STACK Operations -----------\n");
  do
  {
    if (stack[strlen(stack) - 1] == input[top])
    {
      printf("\n");
      printf("->");
      printf("\t\t");
      for (int p = 0; p < strlen(stack); p++)
      {
        printf("%c", stack[p]);
      }
      stack[strlen(stack) - 1] = '\0';
      printf("\n");printf("->");
      printf("\t\t");
      for (int p = 0; p < strlen(stack); p++)
      {
        printf("%c", stack[p]);
      }
      // printf("\n 1st2nd: \n");
      // for(int t = top; t<strlen(input); t++)
      // {
      //   printf("%c", input[t]);
      // }
      top = top + 1;
      // printf("\n 1st3rd: \n");
      // for(int t = top; t<strlen(input); t++)
      // {
      //   printf("%c", input[t]);
      //}
    }
    else if (stack[strlen(stack) - 1] == 'X')
    {
      printf("\n");printf("->");
      printf("\t\t");
      for (int p = 0; p < strlen(stack); p++)
      {
        printf("%c", stack[p]);
      }
      stack[strlen(stack) - 1] = '\0';
      printf("\n");printf("->");
      printf("\t\t");
      for (int p = 0; p < strlen(stack); p++)
      {
        printf("%c", stack[p]);
      }

      X(arr, top);
    }
    else if (stack[strlen(stack) - 1] == 'T')
    {
      printf("\n");printf("->");
      printf("\t\t");
      for (int p = 0; p < strlen(stack); p++)
      {
        printf("%c", stack[p]);
      }
      stack[strlen(stack) - 1] = '\0';
      printf("\n");printf("->");
      printf("\t\t");
      int len;
      len = strlen(stack);
      for (int p = 0; p < strlen(stack); p++)
      {
        printf("%c", stack[p]);
      }

      T(arr, top);
    }
    else if (stack[strlen(stack) - 1] == 'Y')
    {
      printf("\n");printf("->");
      printf("\t\t");
      for (int p = 0; p < strlen(stack); p++)
      {
        printf("%c", stack[p]);
      }
      stack[strlen(stack) - 1] = '\0';
      printf("\n");printf("->");
      printf("\t\t");
      for (int p = 0; p < strlen(stack); p++)
      {
        printf("%c", stack[p]);
      }
      Y(arr, top);
    }
    count = count + 1;
    if (count == 30)
    {
      break;
    }
  } while (input[top] != '$');

  printf("\n");printf("->");
  if (input[top] == '$')
  {
    for (int p = 0; p < 1; p++)
    {
      printf("\t\t%c", stack[p]);
    }
    printf("\n\n\tString Accepted\n\n\n");
  }
  else
  {
    printf("\n\n\tString Not Accepted\n\n\n");
  }
}
