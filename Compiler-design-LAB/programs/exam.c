#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i=0;char str[10];
char str[10],curr[10];
int x=0;
void G();void B();void E();void N();void L();
struct node  
{
    char data; 
    struct node *left_node; 
    struct node *right_node;
    struct node *middle_node; 
}*root_node; 

struct node* newNode(char data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node));      
    node->data = data; 
    node->left_node = NULL; 
    node->right_node = NULL; 
    node->middle_node = NULL;
    return(node); 
} 
void G(){
    
    root_node=newNode('G');    
    root_node->left_node=newNode('c');
    curr[i++]=root_node->left_node->data;
    root_node->right_node=newNode('d');
    root_node->middle_node= newNode('A');
    printf("\nGrammar after removing left recursion - \n\n");
    
    
    B();
}
void B(){
    root_node->middle_node->middle_node=newNode('a');
    curr[i++]=root_node->middle_node->middle_node->data;
    curr[i++]=root_node->right_node->data;
    printf("\tG->G'|NULL\n");
    if (strcmp(curr,str)==0){
        x++;
    }
    else{
        root_node->middle_node->middle_node=NULL;
        free(root_node->middle_node->middle_node);
        i-=2;

    }
    printf("\tG->BG'|NG'|NULL\n");
    root_node->middle_node->middle_node=newNode('b');
    curr[i++]=root_node->middle_node->middle_node->data;

    if (strcmp(curr,str)==0){
        x++;
    }
    else{
        root_node->middle_node->middle_node=NULL;
        free(root_node->middle_node->middle_node); 
        i--;
    }
    printf("\tB->(E)\n");
    root_node->middle_node->left_node=newNode('a');
    root_node->middle_node->right_node=newNode('b');
    curr[i++]=root_node->middle_node->left_node->data;
    curr[i++]=root_node->middle_node->right_node->data;
    curr[i++]=root_node->right_node->data;
    if (strcmp(curr,str)==0){
        x++;
        return;
    }
    
        E();
        
}
void E(){
    root_node->middle_node->middle_node=newNode('a');
    curr[i++]=root_node->middle_node->middle_node->data;
    curr[i++]=root_node->right_node->data;
    printf("\tE->E'\n");
    if (strcmp(curr,str)==0){
        x++;
    }
    else{
        root_node->middle_node->middle_node=NULL;
        free(root_node->middle_node->middle_node);
        i-=2;

    }
    printf("\tE'->(E)E'|NULL\n");
    root_node->middle_node->middle_node=newNode('b');
    curr[i++]=root_node->middle_node->middle_node->data;

    if (strcmp(curr,str)==0){
        x++;
    }
    else{
        root_node->middle_node->middle_node=NULL;
        free(root_node->middle_node->middle_node); 
        i--;
    }
    printf("\tN->(N]\n");
    root_node->middle_node->left_node=newNode('a');
    root_node->middle_node->right_node=newNode('b');
    curr[i++]=root_node->middle_node->left_node->data;
    curr[i++]=root_node->middle_node->right_node->data;
    curr[i++]=root_node->right_node->data;
    if (strcmp(curr,str)==0){
        x++;
        return;
    }
    
        N();
        
}

void N(){
    root_node->middle_node->middle_node=newNode('a');
    curr[i++]=root_node->middle_node->middle_node->data;
    curr[i++]=root_node->right_node->data;
    printf("\tL->L'\n");
    if (strcmp(curr,str)==0){
        x++;
    }
    else{
        root_node->middle_node->middle_node=NULL;
        free(root_node->middle_node->middle_node);
        i-=2;

    }
    printf("\tL'->EL'|(EL'|NULL\n");
    root_node->middle_node->middle_node=newNode('b');
    curr[i++]=root_node->middle_node->middle_node->data;

    if (strcmp(curr,str)==0){
        x++;
    }
    else{
        root_node->middle_node->middle_node=NULL;
        free(root_node->middle_node->middle_node); 
        i--;
    }
    
    root_node->middle_node->left_node=newNode('a');
    root_node->middle_node->right_node=newNode('b');
    curr[i++]=root_node->middle_node->left_node->data;
    curr[i++]=root_node->middle_node->right_node->data;
    curr[i++]=root_node->right_node->data;
    if (strcmp(curr,str)==0){
        x++;
        return;
    }
        
}
void L(){
    root_node->middle_node->middle_node=newNode('a');
    curr[i++]=root_node->middle_node->middle_node->data;
    curr[i++]=root_node->right_node->data;
    
    if (strcmp(curr,str)==0){
        x++;
    }
    else{
        root_node->middle_node->middle_node=NULL;
        free(root_node->middle_node->middle_node);
        i-=2;

    }
    if (strcmp(str,"((]()")==0){
        printf("\tString is accepted\n");
    }
    else{
        printf("\tString not accepted\n");
    }
    root_node->middle_node->middle_node=newNode('b');
    curr[i++]=root_node->middle_node->middle_node->data;
    if (strcmp(curr,str)==0){
        x++;
    }
    else{
        root_node->middle_node->middle_node=NULL;
        free(root_node->middle_node->middle_node); 
        i--;
    }
    
    root_node->middle_node->left_node=newNode('a');
    root_node->middle_node->right_node=newNode('b');
    curr[i++]=root_node->middle_node->left_node->data;
    curr[i++]=root_node->middle_node->right_node->data;
    curr[i++]=root_node->right_node->data;
    if (strcmp(curr,str)==0){
        x++;
        return;
    }   
}

int main(int argc, char const *argv[])
{
    G();
    
    
    
    printf("\n\tEnter the string: ");
    scanf("%s",str);
    L();

    return 0;
}
