#ifndef MY_FANCY_LINKED_LIST_H__
#define MY_FANCY_LINKED_LIST_H__

/*
 * We forward declare the opaque list
 * This is possible due to the fact 
 * we only work with the pointer to the struct
 * No direct access to ListNode_t/ListNode attributes possible
 */
typedef struct ListNode ListNode_t;
typedef struct List List_t;

ListNode_t* NewListNode(void);
void FreeListNode(ListNode_t* elem);

List_t* NewList(void);
void FreeList(List_t* list);

int InsertIntoLinkedList(List_t* list, ListNode_t* elem);
int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node /* the node we insert the element into */, ListNode_t* elem);
int RemoveFromList(List_t* list, ListNode_t* elem);
ListNode_t* GetNext(const List_t* list, ListNode_t* elem);

#endif