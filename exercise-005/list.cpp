#include "list.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <fmt/format.h>

ListNode_t* NewListNode(void) {
    fmt::println("in \"{}\"",__func__);
    return NULL;
}

void FreeListNode(ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    
}

List_t* NewList(void) {
    fmt::println("in \"{}\"",__func__);
    return NULL;
}

void FreeList(List_t* list) {
    fmt::println("in \"{}\"",__func__);
}

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    return EXIT_SUCCESS;
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node /* the node we insert the element into */, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    return EXIT_SUCCESS;
}
int RemoveFromList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    return EXIT_SUCCESS;
}
ListNode_t* GetNext(const List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"",__func__);
    return NULL;
}