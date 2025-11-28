#include <fmt/chrono.h>
#include <fmt/format.h>

#include "list.hpp"
#include "vector.hpp"

int bss;
int bss2;

auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {} bss: {}, bss2: {}!\n", argv[0], bss, bss2);

    ListNode_t* dum_node = NewListNode(0);
    ListNode_t* elem = NewListNode(0);
    FreeListNode(dum_node);

    List_t* dum_list =  NewList();
    FreeList(dum_list);

    /* restart */
    List_t* list =  NewList();
    ListNode_t* node = NewListNode(0);
    int ret = EXIT_FAILURE;
    ret = InsertIntoLinkedList(list, node);
    fmt::println("Return value of: {}",ret);

    ret = InsertIntoLinkedListAfterNode(list, node, elem);
    fmt::println("Return value of InsertIntoLinkedListAfterNode: {}",ret);
    ret = RemoveFromList(list, elem);
    fmt::println("Return value of RemoveFromList: {}",ret);

    fmt::println("Fill the linked list...");

    for(unsigned int i = 2; i< 12; i++) {
        InsertIntoLinkedList(list,NewListNode(i));
    }

    fmt::println("Print the linked list...");
    for (ListNode_t* n = GetNext(list, NULL); n != NULL; n = GetNext(list, n)) {
        unsigned int data = 0;
        if(EXIT_SUCCESS == GetData(n, &data)) {
            fmt::println("The value: {} ", data);
        } else {
            fmt::print("INVALID Node");
        }
    }
    fmt::println("Free the list...");
    FreeList(list);


    /* ---------------- VECTOR ---------------- */

    Vector_t* vec = NewVector();
    if (vec != NULL) {
        vector_init(vec);
        vector_clear(vec);

        unsigned int result = 0;
        ret = vector_push_back(vec, 10);
        fmt::println("Return value of vector_push_back: {}",ret);
        ret =  vector_get(vec, 0, &result);
        fmt::println("Return value of vector_get: {}",ret);

        vector_print(vec);

        // TODO: Add vector_free() function to properly deallocate vector memory
        // free(vec);  // Placeholder for future implementation
    }

    return 0; /* exit gracefully*/
}
