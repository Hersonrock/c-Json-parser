#include <stdio.h>


typedef struct node{
        int value;
        struct node *next;
}node_t;

void printlist(node_t *head){
        
        node_t *temp = head;

        while( temp !=  NULL){
                printf("%d->", temp->value);
                temp = temp->next;
        }
        printf("\n");
}
int main(int argc, char *argv[]){

        node_t a1, b1, c1;
        node_t *head;        

        a1.value = 3;
        b1.value = 7;
        c1.value = 15;

        //linkage

        head = &a1;
        a1.next = &b1;
        b1.next = &c1;
        c1.next = NULL;
        
        printlist(head);
        return 0;
}
