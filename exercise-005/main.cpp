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

    ListNode_t* node = NewListNode();
    ListNode_t* elem = NewListNode();
    FreeListNode(node);

    List_t* list =  NewList();
    FreeList(list);

    int ret = EXIT_FAILURE;
    ret = InsertIntoLinkedList(list, node);
    fmt::println("Return value of: {}",ret);

    ret = InsertIntoLinkedListAfterNode(list, node, elem);
    fmt::println("Return value of: {}",ret);
    ret = RemoveFromList(list, elem);
    fmt::println("Return value of: {}",ret);
    ListNode_t* node2 =  GetNext(list, elem);


    Vector_t* vec = NewVector();
    vector_init(vec);
    vector_clear(vec);

    unsigned int result = 0;
    ret = vector_push_back(vec, 10);
    fmt::println("Return value of vector_push_back: {}",ret);
    ret =  vector_get(vec, 0, &result);
    fmt::println("Return value of vector_get: {}",ret);

    vector_print(vec);

    return 0; /* exit gracefully*/
}
