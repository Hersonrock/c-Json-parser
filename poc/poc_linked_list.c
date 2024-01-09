#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct node{
        char *key;      //8bytes
        void *value;    //8bytes
        struct node *next;  //8bytes
}node_t;

void printList(node_t *head){
        
        node_t *temp = head;

        while( temp !=  NULL){
                printf("[%s]:", temp->key);
                printf("[%s]\n", temp->value);
                temp = temp->next;
        }
}

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

node_t *createNewNode(){

        node_t *ptr = malloc(sizeof(node_t));
        ptr->key = stringCreate() ;
        ptr->value = stringCreate();
        ptr->next = NULL;

        return ptr;
}

node_t *createChain(int n){
        node_t *head;
        node_t *step;
        node_t *tmp;

        int i = 0;

        tmp = createNewNode();
        head = tmp;
        step = tmp;

        for( i = 1 ; i < n; i++){
                tmp = createNewNode();
                step->next = tmp;
                step = tmp;
        }

        return head;
}



void freeMemory(node_t *head){
        node_t *tmp;

        while (head != NULL){
                tmp = head;
                head = head-> next;
                free(tmp);
        }
}

int main(int argc, char *argv[]){
        
        srand(time(NULL));
        node_t *head;

        head = createChain(20);
        printList(head);
        freeMemory(head);

        return 0;
}       
