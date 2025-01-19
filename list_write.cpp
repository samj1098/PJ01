#include "list_read.h"
#include "list_write.h"
#include <stdio.h>
#include <stdlib.h>

void listRelease(LIST *pLIST){
    if (pLIST == NULL) {
	fprintf(stderr, "Error: NULL lost\n");
	return;
    }

    NODE *current = pLIST->head;
    NODE *next;
    while (current != NULL) {
	next = current->next;
	free(current);
	current = next;
    }

    pLIST->head = NULL;
    pLIST->tail = NULL;
    pLIST->length = 0;
}


NODE * listInsert(LIST *pLIST, double key){
    NODE *pNODE;
    pNODE = NULL;
    if (pLIST == NULL) {
	fprintf(stderr, "Error: NULL\n");
    return NULL;
    }

    pNODE = (NODE*)malloc(sizeof(NODE));
    if (pNODE == NULL) {
	fprintf(stderr, "Error mem alloc failed\n");
   	return NULL;
    }

    pNODE->key = key;
    pNODE->next = pLIST->head;
    
    pLIST->head = pNODE;

    if (pLIST->tail == NULL) {
	pLIST->tail = pNODE;
    } 

    pLIST->length++;

    return pNODE;
}


NODE * listAppend(LIST *pLIST, double key){
    NODE *pNODE;
    pNODE = NULL;
    
    if (pLIST == NULL) {
	fprintf(stderr, "Error: List NULL can't append\n");
	return NULL;
    }

    pNODE = (NODE *)malloc(sizeof(NODE));
    if (pNODE == NULL) {
	fprintf(stderr, "Error: mem alloc failed\n");
    }


    pNODE->key = key;
    pNODE->next = NULL;

    if (pLIST->head  == NULL) {
	pLIST->head = pNODE;
	pLIST->tail = pNODE;
    } else {
	pLIST->tail->next = pNODE;
	pLIST->tail = pNODE;
    }	    

    pLIST->length++;

    return pNODE;
}


NODE * listDelete(LIST *pLIST, double key){
    NODE *pNODE;
    pNODE = NULL;
    
    if(pLIST == NULL) {
	fprintf(stderr, "Error: NULL, can't delete\n");
	return NULL;
    }

    NODE *current = pLIST->head;
    NODE *previous = NULL;

    while (current != NULL) {
	if (current->key == key) {
		if (current == pLIST->head) {
			pLIST->head = current->next;
			if (pLIST->head == NULL) {
				pLIST->tail = NULL;
			}
		} else {
			previous->next = current->next;
			if (current == pLIST->tail) {
				pLIST->tail = previous;
			}
		}
	pLIST->length--;
	
	pNODE = current;
	return pNODE;
	}
	previous = current;
	current = current->next;
    }
    return pNODE;

}

