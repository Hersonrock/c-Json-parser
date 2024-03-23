#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

union anyNode;

//objectNode(JSON object) will store object keys as well as the pointers to the values
//or the head of new objectNode (Json Object)
struct objectNode{
        char *key;
        union anyNode *step;
        struct objectNode *next;
};

//arrayNodes will store any value 
//strings, doubles, literals and lists.
struct arrayNode{
        union anyNode *step;    
        struct arrayNode *next; 
};

union anyNode{
        struct objectNode *object_u;
        struct arrayNode *array_u;
        char *value;
};
//debug function to create random strings of random lenghts
char *stringCreate(){
        int n = rand() %5 + 2;
        char *string = (char *)malloc((size_t)n);
        for(int  i = 0 ; i < n-1; i++){
                int r = rand() %25 +97;
                string[i] = (char)r ;
        }
        string[n-1] = '\0';
        return string;
}

struct arrayNode *createArrayNode(){

        struct arrayNode *ptr = malloc(sizeof(struct arrayNode));
        ptr->step = malloc(sizeof(union anyNode));

        ptr->step->value = stringCreate(); 
        ptr->next = NULL;

        return ptr;
}

//Returns the head of n-arrayNodes chain.
struct arrayNode *createArrayNodeChain(int n){
        struct arrayNode *head;
        struct arrayNode *step;
        struct arrayNode *tmp;

        int i = 0;

        tmp = createArrayNode();
        head = tmp;
        step = tmp;

        for( i = 1 ; i < n; i++){
                tmp = createArrayNode();
                step->next= tmp;
                step = tmp;
        }

        return head;
}

//Creates IndexNode
struct objectNode *createObjectNode(int n){
        struct objectNode *ptr = malloc(sizeof(struct objectNode));
        ptr->key = stringCreate();
        ptr->step = malloc(sizeof(union anyNode));
        ptr->step->array_u = createArrayNodeChain(n);
        ptr->next = NULL;
        return ptr;
}

struct objectNode *createObjectNodeChain(int n, int n2){
        struct objectNode *head;
        struct objectNode *step;
        struct objectNode *tmp;
        int i = 0;

        tmp = createObjectNode(n);
        head = tmp;
        step = tmp;

        for( i = 1 ; i < n2; i++){
                tmp = createObjectNode(n);
                step->next = tmp;
                step = tmp;
        }

        return head;
}

/* Disabling for the moment, needs updating
void freeMemory(struct arrayNode *head){
        listNode_t *tmp;

        while (head != NULL){
                tmp = head;
                head = head-> next;
                free(tmp->key);
                free(tmp->step);
                free(tmp);
        }
}
*/

void printObjects(struct objectNode *head){

        struct arrayNode *tmp = head->step->array_u;
        
        printf("{\n");
         
        while ( head->next != NULL){
                printf("\"%s\": [", head->key);
                while ( tmp->next != NULL){
                        
                        printf("%s", tmp->step->value);
                        tmp = tmp->next;
                        if ( tmp->next != NULL){
                                printf(",");
                        }
                }
                printf("]\n");
                head = head->next;
                tmp = head->step->array_u;
        }
        printf("}\n");

}

int main(int argc, char *argv[]){
        
        srand(time(NULL));
        struct objectNode *head;

        head = createObjectNodeChain(6, 4);
        printObjects(head);
//        freeMemory(head);

        return 0;
}       
