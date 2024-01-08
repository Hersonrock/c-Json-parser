#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct node{
        int value;
        struct node *next;
}node_t;

void printList(node_t *head){
        
        node_t *temp = head;

        while( temp !=  NULL){
                printf("%d->", temp->value);
                temp = temp->next;
        }
        printf("\n");
}

node_t *createNewNode(int value){

        node_t *ptr = malloc(sizeof(node_t));
        ptr->value = value;
        ptr->next = NULL;

        return ptr;
}

node_t *createChain(int n){
        node_t *head;
        node_t *step;
        node_t *tmp;

        int i = 0;

        tmp = createNewNode(i);
        head = tmp;
        step = tmp;

        for( i = 1 ; i < n; i++){
                int a = rand() % 100;
                int r = rand_r(&a) % 100 + 1;
                tmp = createNewNode(r);
                step->next = tmp;
                step = tmp;
        }

        return head;
}

char *stringCreate(){
        int n = rand() %10 + 1;
        char *string = (char *)malloc((size_t)n);
        for(int  i = 0 ; i < n; i++){
                char c = (char)(rand() %25 + 66);
                string[i] =  c;
        }
        printf("string: %s\n",string);
        return string;
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
