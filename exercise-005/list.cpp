#include "list.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <fmt/format.h>

typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;

typedef struct List {
    ListNode_t* pHead;
    ListNode_t* pTail;
    unsigned int size;
} List_t;

ListNode_t* NewListNode(unsigned int data) {
    fmt::println("in \"{}\" sizeof ListNode_t: {}",__func__,sizeof(ListNode_t));
    ListNode_t* pTemp = (ListNode_t*) malloc(sizeof(ListNode_t));
    if(pTemp != NULL) {
        pTemp->pNext = NULL;
        pTemp->data = data;
    }
    return pTemp;
}

void FreeListNode(ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    if(elem != NULL) {
        free(elem);
        elem=NULL;
    }
}

List_t* NewList(void) {
    fmt::println("in \"{}\"",__func__);
    List_t* pTempList = (List_t*) malloc(sizeof(List_t));
    if(pTempList != NULL) {
        pTempList->pHead = NULL;
        pTempList->pTail = NULL;
        pTempList->size = 0;
    }
    return pTempList;
}

void FreeList(List_t* list) {
    fmt::println("in \"{}\"",__func__);
    if(list != NULL) {
        // Walk through the list and delete each element
        ListNode_t *pNode = NULL;
        do{
            pNode = GetNext(list,list->pHead);
            FreeListNode(list->pHead);
            list->pHead = pNode;
            if(list->size >= 1) {
                list->size -= 1;
            }
        }while(pNode != NULL);

        list->pTail = NULL;
        list->pHead = NULL;

        // free the remaining part
        free(list);
        list = NULL;
    }
}

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);

    if(list == NULL || elem == NULL ) {
        return EXIT_FAILURE;
    }

    elem->pNext = NULL;
    if(list->size == 0) {
        list->pHead = elem;
        list->pTail = elem;
        list->size = 1;
    } else {
        if(list->pTail == NULL) {
            return EXIT_FAILURE;
        }
        list->pTail->pNext = elem;
        list->size += 1;
        list->pTail = elem;
    }

    return EXIT_SUCCESS;
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node /* the node we insert the element into */, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    if (list != NULL && node != NULL && elem != NULL)
    {
        list->size += 1;
        ListNode_t* pTemp = node;
        elem->pNext = node->pNext;
        node->pNext = elem;
        if(node == list->pTail) {
            list->pTail = elem;
        }
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
int RemoveFromList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    if (list != NULL && elem != NULL)
    {
        // Walk through the list
        ListNode_t* pNode = NULL;
        pNode = elem->pNext;
        if (elem == list->pHead)
        {
            list->pHead = pNode;
            list->size -= 1;
            if (list->pHead == list->pTail)
            {
                list->size = 0;
            }
        }
        else
        {
            ListNode_t* pPrev = list->pHead;
            do
            {
                if((pPrev != NULL) && (elem != NULL) && (pPrev->pNext == elem)) {
                        // remove element from the linked list
                        pPrev->pNext = elem->pNext;
                        list->size -= 1;
                        if(list->pTail == elem) {
                            list->pTail = pPrev;
                        }
                }
                pPrev = GetNext(list,pPrev);
            } while (pPrev != NULL);
        }
        FreeListNode(elem);
    }
    return EXIT_SUCCESS;
}
ListNode_t* GetNext(const List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    if((list != NULL) && elem == NULL) {
        return list->pHead;
    } else if((list != NULL) && (list->size > 0) ) {
        return elem->pNext;
    }
    fmt::println("Something went wrong, list: {}, elem: {}",fmt::ptr(list), fmt::ptr(elem));
    return NULL;
}

int GetData(ListNode_t* node, unsigned int* data) {
    int ret = EXIT_FAILURE;
    if(node != NULL && data != NULL) {
        *data = node->data;
        ret = EXIT_SUCCESS;
    }
    return ret;
}