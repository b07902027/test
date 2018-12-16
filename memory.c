#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "memory.h"

void initMemory(Memory *memory, int length){
    memory->head = (NODE *)malloc(sizeof(NODE));
    assert(memory->head != NULL);
    memory->head->pos = 0;
    memory->head->length = length;
    memory->head->next = NULL;
}

void printMemory(Memory *memory){
    NODE *ptr = memory->head;
    if (ptr == NULL) return;
    printf("==========\n");
    while(ptr->next != NULL){
        printf("start %d, length %d\n", ptr->pos, ptr->length);
        ptr = ptr->next;
    }
    printf("start %d, length %d\n", ptr->pos, ptr->length);
}

void allocateMemory(Memory *memory, int start, int length){
    NODE *ptr = memory->head, *last = memory->head;
    if (ptr == NULL) return;
    while(1){
        if (ptr->pos <= start && start + length <= ptr->pos + ptr->length){
            break;
        }
        last = ptr;
        ptr = ptr->next;
    }
    NODE *current = (NODE *)malloc(sizeof(NODE));
    assert(current != NULL);
    current->length = ptr->pos + ptr->length - start - length;
    current->pos = start + length;
    ptr->length = start - ptr->pos;
    current->next = ptr->next;
    ptr->next = current;
}
