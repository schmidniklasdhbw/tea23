#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value);

void changeValueByPointer(int* ptr);

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {} in Version {} !\n", tea::PROJECT_NAME , tea::PROJECT_VER);

    for (int i = 0; i < argc; i++){
        fmt::println("argc:  {}, argument {} (Adresse: {})", i,argv[i], fmt::ptr(argv[i]));
    }

    int foo = 10;
    fmt::println("foo = {}", foo);
    int bar = 4711;
    fmt::println("bar = {}\n", bar);
    int * ptr = &foo;  // pointer zeigt auf foo
    fmt::println("Pointer zeigt auf foo -> int * ptr = &foo ");
    fmt::println("ptr von foo: {}", foo);
    fmt::println("Adresse von foo: {}, Pointer Adresse: {} \n",fmt::ptr(&foo), fmt::ptr(ptr) );
    *ptr = 42;     // schreib 42 auf dem der pointer zeigt bei uns auf foo
    fmt::println("schreibt 42 auf dem der Pointer steht -> *ptr = 42 ");
    fmt::println("foo nach Zuweisung: {}", foo); 
    fmt::println("Adresse von foo: {}, Pointer Adresse: {}\n",fmt::ptr(&foo), fmt::ptr(ptr));
    ptr = &bar;  // pointer zeigt auf bar
    fmt::println("pointer zeigt auf bar -> ptr = &bar");
    fmt::println("Adresse von bar: {}, Pointer Adresse: {}\n", fmt::ptr(&bar), fmt::ptr(ptr));  
    *ptr = foo;   // pointer bekommt den wert von foo = 42 -> bar = 42 da der pointer auf bar zeigt &bar
    fmt::println("Pointer bekommt den Wert von foo zugewiesen -> *ptr = foo ") ;
    fmt::println("bar nach Zuweisung: {},Adresse von bar: {},Pointer Adresse: {}", bar,fmt::ptr(&bar), fmt::ptr(ptr));
    fmt::println("Adresse von bar: {} , Pointer Adresse: {}\n\n", fmt::ptr(&bar), fmt::ptr(ptr));

    double* d = (double*)malloc(sizeof(double));  // Speicher reservieren
    *d = 3.141;                                    // Wert zuweisen 
    fmt::println("Wert Double d: {}", *d);           // Ausgabe 
    free(d);                                      // Speicher freigeben

    //double*d = new double(3.141);
    //fmt::println("Wert Double d: {}", *d);
    //delete(d);


    /* INSERT YOUR CODE HERE */
    int a = 10;
    changeValueByParameter(a);
    fmt::println("Der Wert von value nach der Funktion changeValueByParameter: {}", a );
    changeValueByPointer(&a);
    fmt::println("Der Wert des Pointers nach changeValueByPointer: {} ", a);
    

    return 0; /* exit gracefully*/
}

void changeValueByPointer(int* ptr) {
*ptr = 99; 
fmt::println("Der Wert des Pointers changeValueByPointer: {} ", *ptr);
}

void changeValueByParameter(int value){
 value = 55; 
 fmt::println("Der Wert von value in der Funktion changeValueByParameter: {}", value );
}

