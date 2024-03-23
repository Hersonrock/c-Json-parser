#include<stdlib.h>
#include<string.h>

const char key[] = "test_key";
const char value[] = "test_value";

struct objectNode{
        char *key;
        union anyNode *step;
        struct objectNode *next;
};

struct arrayNode{
        union anyNode *step;    
        struct arrayNode *next; 
};

union anyNode{
        struct objectNode *object_u;
        struct arrayNode *array_u;
        char *value;
};

char *stringCreate(const char *input){
        char *string = (char *)malloc(sizeof(input));
        strcpy(string, input);
        return string;
}

struct arrayNode *createArrayNode(){
        struct arrayNode *ptr = malloc(sizeof(struct arrayNode));
        ptr->step = malloc(sizeof(union anyNode));

        ptr->step->value = stringCreate(value); 
        ptr->next = NULL;

        return ptr;
}

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

struct objectNode *createObjectNode(int n){
        struct objectNode *ptr = malloc(sizeof(struct objectNode));
        ptr->key = stringCreate(key);
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
