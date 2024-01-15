#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

union anyNode;

//indexNode(JSON object) will store object keys as well as the pointers to the values
//or the head of new indexNode (Json Object)
typedef struct indexNode{
        char *key;
        union anyNode *step;
        struct indexNode *next;
}indexNode_t;

//nodes will store any value 
//strings, doubles, literals and lists.
typedef struct node{
        union anyNode *value;    
        struct node *next; 
}node_t;

union anyNode{
        indexNode_t *index_u;
        node_t *node_u;
        char *value_u;
};
//debug function to create random strings of random lenghts
char *stringCreate(){
        int n = rand() %10 + 1;
        char *string = (char *)malloc((size_t)n);
        for(int  i = 0 ; i < n-1; i++){
                int r = rand() %25 +66;
                string[i] = (char)r ;
        }
        string[n-1] = '\0';
        return string;
}

node_t *createNode(){

        node_t *ptr = malloc(sizeof(node_t));
        ptr->value = malloc(sizeof(union anyNode));

        char *str = stringCreate();
        
        ptr->value->value_u = malloc(sizeof(str));
        strcpy(ptr->value->value_u, str);
        ptr->next = NULL;

        return ptr;
}

//Returns the head of n-nodes chain.
node_t *createNodeChain(int n){
        node_t *head;
        node_t *step;
        node_t *tmp;

        int i = 0;

        tmp = createNode();
        head = tmp;
        step = tmp;

        for( i = 1 ; i < n; i++){
                tmp = createNode();
                step->next = tmp;
                step = tmp;
        }

        return head;
}

//Creates IndexNode
indexNode_t *createIndexNode(int n){
        indexNode_t *ptr = malloc(sizeof(indexNode_t));
        ptr->key = stringCreate();
        ptr->step = malloc(sizeof(union anyNode));
        ptr->step->node_u = createNodeChain(n);
        ptr->next = NULL;
        return ptr;
}

indexNode_t *createIndexNodeChain(int n, int n2){
        indexNode_t *head;
        indexNode_t *step;
        indexNode_t *tmp;
        int i = 0;

        tmp = createIndexNode(n);
        head = tmp;
        step = tmp;

        for( i = 1 ; i < n2; i++){
                tmp = createIndexNode(n);
                step->next = tmp;
                step = tmp;
        }

        return head;
}

/* Disabling for the moment, needs updating
void freeMemory(node_t *head){
        listNode_t *tmp;

        while (head != NULL){
                tmp = head;
                head = head-> next;
                free(tmp->key);
                free(tmp->value);
                free(tmp);
        }
}
*/

void printObjects(indexNode_t *head){

        node_t *tmp = head->step->node_u;
        
        printf("{\n\t");
         
        while ( head->next != NULL){
                printf("\"%s\": [", head->key);
                while( tmp->next != NULL){
                        printf("%s,", head->step->node_u->value->value_u);
                        tmp = tmp->next;
                }
                printf("]\n");
                head = head->next;
        }
        printf("}\n");

}

int main(int argc, char *argv[]){
        
        srand(time(NULL));
        indexNode_t *head;

        head = createIndexNodeChain(6, 4);
        printObjects(head);
//        freeMemory(head);

        return 0;
}       
