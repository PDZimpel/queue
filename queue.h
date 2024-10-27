#pragma once
#ifndef __queue__

typedef struct _item{
    struct _item * previous;
    struct _item * next;
    const char * command;
} titem;

typedef struct queue{
    titem * last;
    titem * first;
    int size;
} tQ;

tQ * createQueue();
int addItem(tQ * q, const char * command);
const char * getNextCommand(tQ * q);

#endif
