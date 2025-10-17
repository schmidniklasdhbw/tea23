#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;

int ass = 0;
int ass1;

static int a = 0;
static int b;

const int c = 0;
const int d = 10;

int* heapVar1 = new int(3);


int main(int argc, char **argv) {


int* heapVar = new int(3);

int lokalVar = 1;
int q = 0;
int w;

static int y = 0;
static int x;

const int v = 0;
const int s = 10;

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    //fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    fmt::print("int globalVar: {}, Adresse: {}\n", globalVar, fmt::ptr(&globalVar));
    fmt::print("int localVar: {}, Adresse: {}\n\n", lokalVar, fmt::ptr(&lokalVar));

    fmt::print("int global Wert 0: {}, Adresse: {}\n", ass, fmt::ptr(&ass));
    fmt::print("int kein global Wert: {}, Adresse: {}\n", ass1, fmt::ptr(&ass1));
    fmt::print("int local Wert 0: {}, Adresse: {}\n", q, fmt::ptr(&q));
    fmt::print("int kein local Wert: {}, Adresse: {}\n\n", w, fmt::ptr(&w));

    fmt::print("static int global Wert 0: {}, Adresse: {}\n", a, fmt::ptr(&a));
    fmt::print("static int global kein Wert: {}, Adresse: {}\n", b, fmt::ptr(&b));
    fmt::print("static int local Wert 0: {}, Adresse: {}\n", y, fmt::ptr(&y));
    fmt::print("static int local kein Wert: {}, Adresse: {}\n\n", x, fmt::ptr(&x));

    fmt::print("const int global Wert 0: {}, Adresse: {}\n", c, fmt::ptr(&c));
    fmt::print("const int global Wert 10: {}, Adresse: {}\n", d, fmt::ptr(&d));
    fmt::print("const int local Wert 0: {}, Adresse: {}\n", v, fmt::ptr(&v));
    fmt::print("const int local Wert 10: {}, Adresse: {}\n\n", s, fmt::ptr(&s));

    fmt::print("Reservierter Speicher Global: {}, Adresse: {}\n", *heapVar1, fmt::ptr(heapVar1));
    delete heapVar1;
    fmt::println("Reservierter Speicher Lokal: {}, Adresse: {}\n", *heapVar, fmt::ptr(heapVar));
    delete heapVar;


   

    

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}

