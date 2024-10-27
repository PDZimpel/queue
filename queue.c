#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

tQ * createQueue(){
    tQ * q = (tQ*) malloc(sizeof(tQ));
    if(!q){
        perror("Unable to start queue");
        exit(1);
    }
    q->last = NULL;
    q->first = NULL;
    q->size = 0;
    return q;
}

int addItem(tQ* q, const char * command){
    titem * t = (titem*) malloc(sizeof(titem));
    if(!t){
        return -1;
    }

    t->command = command;
    t->previous = NULL;

    if(q->last == NULL){
        t->next = NULL;
        q->first = t;
        q->last = t;
    } else {
        t->next = q->last;
        q->last->previous = t;
        q->last = t;
    }

    q->size++;
    return 1;
}

const char * getNextCommand(tQ * q){
    if (q->first == NULL) {
        return NULL;
    }

    const char * command = q->first->command;
    titem * prev = q->first->previous;
    free(q->first);
    q->first = prev;

    if (q->first == NULL) {
        q->last = NULL; 
    }

    q->size--;
    return command;
}

