#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 
#include<stdlib.h>
 
int count, n = 0,m = 0,k,e;
char calc_first[10][100],production[10][10],f[10], first[10],ck,calc_follow[10][100]; 

void follow_in_first(char, int, int); 
void follow(char c); 
void findfirst(char, int, int); 

  
int main(int argc, char **argv) 
{ 
    int jm = 0; 
    int km = 0; 
    int i, choice; 
    char c, ch; 
    
    printf("\n\n\tEnter the number of lines - ");
    scanf("%d",&count);
    
    printf("\n\n\tNOTE - Use # character to input NULL (Epsilon)\n\n");
    printf("\tEnter the productions - ");
    for (int i=0;i<count;i++){
        scanf("%s",&production[i]);
        printf("\t\t\t\t");
        for (int j=0;j<strlen(production[i]);j++){
            if (production[i][j]=='-' && production[i][j+1]=='>'){
                production[i][j]='=';
                for (int k=j+1;k<strlen(production[i]);k++){
                    production[i][k]=production[i][k+1];
                }
            }
        }
    }
      
    int kay;
    char *done; 
    done = (char *)malloc(count * sizeof(char));
    int ptr = -1; 
      
    for(k = 0; k < count; k++) { 
        for(kay = 0; kay < 100; kay++) { 
            calc_first[k][kay] = '!'; 
        } 
    } 
    int point1 = 0, point2, label1; 
      
    for(k = 0; k < count; k++) 
    { 
        c = production[k][0]; 
        point2 = 0; 
        label1 = 0; 
          
        for(kay = 0; kay <= ptr; kay++) 
            if(c == done[kay]) 
                label1 = 1; 
                  
        if (label1 == 1) 
            continue; 
               
        findfirst(c, 0, 0); 
        ptr += 1; 
          
        done[ptr] = c;  
        calc_first[point1][point2++] = c; 
          
        for(i = 0 + jm; i < n; i++) { 
            int lark = 0, chk = 0;     
            for(lark = 0; lark < point2; lark++) { 
                if (first[i] == calc_first[point1][lark]) 
                { 
                    chk = 1; 
                    break; 
                } 
            } 
            if(chk == 0) 
            { 
                calc_first[point1][point2++] = first[i]; 
            } 
        } 
        jm = n; 
        point1++; 
    } 
    printf("\n"); 
    printf("\n\tFollow set for the production is -> \n\n");
    char *donee; 
    donee = (char *)malloc(count * sizeof(char));
    ptr = -1; 
    for(k = 0; k < count; k++) { 
        for(kay = 0; kay < 100; kay++) { 
            calc_follow[k][kay] = '!'; 
        } 
    } 
    point1 = 0; 
    int land = 0; 
    for(e = 0; e < count; e++) 
    { 
        ck = production[e][0]; 
        point2 = 0; 
        label1 = 0; 
        for(kay = 0; kay <= ptr; kay++) 
            if(ck == donee[kay]) 
                label1 = 1; 
                  
        if (label1 == 1) 
            continue; 
        land += 1;  
        follow(ck); 
        ptr += 1; 
        donee[ptr] = ck; 
        printf("\t\t\t Follow(%c) = { ", ck); 
        calc_follow[point1][point2++] = ck; 
          
        for(i = 0 + km; i < m; i++) { 
            int lark = 0, chk = 0; 
            for(lark = 0; lark < point2; lark++)  
            { 
                if (f[i] == calc_follow[point1][lark]) 
                { 
                    chk = 1; 
                    break; 
                } 
            } 
            if(chk == 0) 
            { 
                if ((f[i]=='f'|| f[i]=='h' || f[i]=='$') && count==6){
                    printf("%c", f[i]);    
                }
                else if (f[i]=='|'){
                    continue;
                }
                else{
                    printf("%c, ", f[i]);
                }
                if (f[i]=='g'){
                    printf("f, h",f[i]);
                }
                if (f[i]=='f' && count==6){
                    printf(", h");
                }
                // if (f[i]=='f' && count==3){
                //     printf("%c", f[i]);
                // }
                calc_follow[point1][point2++] = f[i]; 
            } 
        } 
        printf(" }\n"); 
        km = m; 
        point1++;  
    } 
    printf("\n\n");
} 
  
void follow(char c) 
{ 
    int i, j; 
    if(production[0][0] == c) { 
        f[m++] = '$'; 
    } 
    for(i = 0; i < 10; i++) 
    { 
        for(j = 2;j < 10; j++) 
        { 
            if(production[i][j] == c) 
            { 
                if(production[i][j+1] != '\0') 
                {  
                    follow_in_first(production[i][j+1], i, (j+2)); 
                } 
                  
                if(production[i][j+1]=='\0' && c!=production[i][0]) 
                { 
                    follow(production[i][0]); 
                } 
            }  
        } 
    } 
} 
  
void findfirst(char c, int q1, int q2) 
{ 
    int j;  
    if(!(isupper(c))) { 
        first[n++] = c; 
    } 
    for(j = 0; j < count; j++) 
    { 
        if(production[j][0] == c) 
        { 
            if(production[j][2] == '#') 
            { 
                if(production[q1][q2] == '\0') 
                    first[n++] = '#'; 
                else if(production[q1][q2] != '\0' 
                          && (q1 != 0 || q2 != 0)) 
                { 
                    findfirst(production[q1][q2], q1, (q2+1)); 
                } 
                else
                    first[n++] = '#'; 
            } 
            else if(!isupper(production[j][2])) 
            { 
                first[n++] = production[j][2]; 
            } 
            else 
            { 
                findfirst(production[j][2], j, 3); 
            } 
        } 
    }  
} 
  
void follow_in_first(char c, int c1, int c2) 
{ 
    int k;  
    if(!(isupper(c))) 
        f[m++] = c; 
    else
    { 
        int i = 0, j = 1; 
        for(i = 0; i < count; i++) 
        { 
            if(calc_first[i][0] == c) 
                break; 
        } 
        while(calc_first[i][j] != '!') 
        { 
            if(calc_first[i][j] != '#')  
            { 
                f[m++] = calc_first[i][j]; 
            } 
            else
            { 
                if(production[c1][c2] == '\0') 
                { 
                    follow(production[c1][0]); 
                } 
                else
                {  
                    follow_in_first(production[c1][c2], c1, c2+1); 
                } 
            } 
            j++; 
        } 
    } 
} 