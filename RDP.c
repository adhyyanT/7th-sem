#include<stdio.h>
#include<string.h>


//Defining Non-Terminals as Separate Functions
int S(char[], int, int);
int B(char[], int, int);
int C(char[], int, int);

int S(char str[], int pos, int len)
{
    if(str[pos]=='a' && (pos+1)<len)
        return B(str, pos+1, len);

    else if(str[pos]=='a')
        return 1;
    
    else
        return 0;
}

int B(char str[], int pos, int len)
{
    if(str[pos]=='b' && (pos+1)<len)
        return C(str,pos+1, len);

    else
        return 0;
}

int C(char str[], int pos, int len)
{
    if(str[pos]=='c' && (pos+1)<len)
        return C(str, pos+1, len);
    
    else if(str[pos]=='c')
        return 1;
    
    else
        return 0;
}	 	  	  	 	  	  	        	 	

int main(int argc, char const *argv[])
{
    char str[20];
    printf("Enter the String to Check: ");
    scanf("%s", str);
    int len = strlen(str);

    // Passing the string with the initial position to start function
    if(S(str, 0, len))
        printf("\String Accepted!!!\n");
    else
        printf("\String Rejected\n");
    return 0;
}
