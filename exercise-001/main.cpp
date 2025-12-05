#include <fmt/chrono.h>
#include <fmt/format.h>
#include "config.h"

int bss = 0;
static int bss1;

int data = 4711;
static  int data1 = 815;

const int rodata = 1234;
static const int rodata1 = 5678;

// const int blub;

void spacer(){
    fmt::println("-------------------------------------------------------------------");
}

void spacer1(){
    fmt::println("###################################################################");
}

void foo2();

void foo() {
    int value = 92;
    fmt::println("void foo()");
    fmt::println("Der Wert von value: {} die Adresse von value: {}", value, fmt::ptr(&value));
    spacer1();
    foo2();
    value = value + 99;
}

void foo2() {
    static int value;
    fmt::println("void foo2()");
    fmt::println("Der Wert von value: {} die Adresse von value: {}", value, fmt::ptr(&value));
    value = value + 99;
}



int main(int argc, char **argv) {
    int stack = 0;
    /*static*/ int stack1 = 23;
    /*static*/ int stack2;

    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    spacer();
    fmt::println("Die Adresse von foo: {}",fmt::ptr(foo));
    fmt::println("Die Adresse von foo: {}",fmt::ptr(foo2));
    spacer();
    fmt::println("Der Wert von rodata: {}, die Adresse von rodata: {}",rodata, fmt::ptr(&rodata));
    fmt::println("Der Wert von rodata1: {}, die Adresse von rodata1: {}",rodata1, fmt::ptr(&rodata1));

    spacer();
    fmt::println("Der Wert von data: {}, die Adresse von data: {}",data, fmt::ptr(&data));
    fmt::println("Der Wert von data1: {}, die Adresse von data1: {}",data1, fmt::ptr(&data1));


    spacer();
    fmt::println("Der Wert von bss: {}, die Adresse von bss: {}",bss, fmt::ptr(&bss));
    fmt::println("Der Wert von bss1: {}, die Adresse von bss1: {}",bss1, fmt::ptr(&bss1));

    spacer();
    int* heap_ = new int();
    int* heap_1 = new int(42);
    fmt::println("Der Wert auf den heap_ zeigt: {}, die Adresse von heap_: {}",*heap_, fmt::ptr(heap_));
    fmt::println("Der Wert auf den heap_1 zeigt: {}, die Adresse von heap_1: {}",*heap_1, fmt::ptr(heap_1));

    spacer();
    fmt::println("Der Wert von stack: {}, die Adresse von stack: {}",stack, fmt::ptr(&stack));
    fmt::println("Der Wert von stack1: {}, die Adresse von stack1: {}",stack1, fmt::ptr(&stack1));
    fmt::println("Der Wert von stack2: {}, die Adresse von stack2: {}",stack2, fmt::ptr(&stack2));

    spacer();
    foo();
    spacer();
    foo2();
    spacer();
    foo2();
    spacer();
    foo();


    return 0; /* exit gracefully*/
}
