#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i=0;char str[10];
char str[10],curr[10];
void S();
void A();
struct node  
{ 
    char data; 
    struct node *left; 
    struct node *right;
    struct node *middle; 
}*root; 
struct node* newNode(char data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node));      
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    node->middle = NULL;
    return(node); 
} 

int main(int argc, char const *argv[])
{
    
    printf("\n\tEnter the string: ");
    scanf("%s",str);
    S();
    return 0;
}
void S(){
    printf("\n");
    for (int i=0;i<7;i++){
        printf(" ");
    }
    printf("S\n");

    root=newNode('S');    
    root->left=newNode('c');
    curr[i++]=root->left->data;
    root->right=newNode('d');
    root->middle= newNode('A');
    for (int i=0;i<5;i++){
        printf(" ");
    }printf("/ ");
    printf("| ");
    printf("\\\n");
    for (int i=0;i<4;i++){
        printf(" ");
    }printf("c ");printf(" A ");printf(" d\n");
    A();
    return;
}
void A(){
    root->middle->middle=newNode('a');
    curr[i++]=root->middle->middle->data;
    curr[i++]=root->right->data;
 
    if (strcmp(curr,str)==0){
        for (int i=0;i<7;i++){
            printf(" ");
        }printf("|\n");
        for (int i=0;i<7;i++){
            printf(" ");
        }printf("%c\n",root->middle->middle->data);
        printf("\n");
        printf(" String is derived \n");
        return;
    }
    else{
        root->middle->middle=NULL;
        free(root->middle->middle);
        i-=2;

    }
        
    root->middle->middle=newNode('b');
    curr[i++]=root->middle->middle->data;

    if (strcmp(curr,str)==0){
        for (int i=0;i<7;i++){
            printf(" ");
        }printf("|\n");
        for (int i=0;i<7;i++){
            printf(" ");
        }printf("%c\n",root->middle->middle->data);
        printf("\n");
        printf(" String is derived \n");
        return;
    }
    else{
        root->middle->middle=NULL;
        free(root->middle->middle); 
        i--;
    }
        
    root->middle->left=newNode('a');
    root->middle->right=newNode('b');
    curr[i++]=root->middle->left->data;
    curr[i++]=root->middle->right->data;
    curr[i++]=root->right->data;
    if (strcmp(curr,str)==0){
        for (int i=0;i<6;i++){
            printf(" ");
        }printf("/ ");printf("\\\n");

        for (int i=0;i<5;i++){
            printf(" ");
        }printf("%c ",root->middle->left->data);printf("  %c\n",root->middle->right->data);
        printf("\n");
        printf("  String is derived \n");
        return;
    }
    else
        
        if (strlen(str)>=4){
            for (int i=0;i<6;i++){
                printf(" ");
            }printf("/ ");printf("\\\n");

        for (int i=0;i<5;i++){
                printf(" ");
            }printf("%c ",root->middle->left->data);printf("  %c\n",root->middle->right->data);
        }
        printf("\nGiven string cannot be derived, printed closest possible tree.\n");
        printf("\n");
        
}