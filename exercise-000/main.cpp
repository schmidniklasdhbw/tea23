#include <iostream>
#include <string>
#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

// Forward declaration of the functions
void changeValueByParameter(int value);
void changeValueByPointer(int* ptr);

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {} in version {} !\n", tea::PROJECT_NAME, tea::PROJECT_VER);

    for (int i = 0; i<  argc ; i++) {
        fmt::println("argc: {}, argument {} (Adresse: {})", i, argv[i], fmt::ptr(argv[i]));
    }
    //std::cin.get();

    int foo = 10;
    int* ptr = &foo;
    fmt::println("int foo = 10;");
    fmt::println("int* ptr = &foo;");
    fmt::println("The value of foo: {} the value ptr is pointing to: {} ",foo, *ptr);
    fmt::println("Adresse von foo: {} Adresse im pointer ptr {}) ",fmt::ptr(&foo), fmt::ptr(ptr));
    //std::cin.get();

    *ptr = 42;
    fmt::println("*ptr = 42;");
    fmt::println("The value of foo: {} the value ptr is pointing to: {}",foo, *ptr);
    fmt::println("Adresse von foo: {} Adresse im pointer ptr {}) ",fmt::ptr(&foo), fmt::ptr(ptr));
    //std::cin.get();

    int bar = 4711;
    ptr = &bar;
    fmt::println("int bar = 4711;");
    fmt::println("ptr = &bar;");
    fmt::println("The value of foo: {} the value ptr is pointing to: {}",foo, *ptr);
    fmt::println("The value of bar: {} the value ptr is pointing to: {}",bar, *ptr);
    fmt::println("Adresse von foo: {} Adresse im pointer ptr {}) ",fmt::ptr(&foo), fmt::ptr(ptr));
    fmt::println("Adresse von bar: {} Adresse im pointer ptr {}) ",fmt::ptr(&bar), fmt::ptr(ptr));
    //std::cin.get();

    *ptr = foo;
    fmt::println("*ptr = foo;");
    fmt::println("The value of foo: {} the value ptr is pointing to: {}",foo, *ptr);
    fmt::println("The value of bar: {} the value ptr is pointing to: {}",bar, *ptr);
    fmt::println("Adresse von foo: {} Adresse im pointer ptr {}) ",fmt::ptr(&foo), fmt::ptr(ptr));
    fmt::println("Adresse von bar: {} Adresse im pointer ptr {}) ",fmt::ptr(&bar), fmt::ptr(ptr));
    //std::cin.get();

    fmt::println("------------------- Teil 2: Dynamische Speicherverwaltung -------------------");
    double* d = (double*)malloc(sizeof(double));  // Speicher reservieren
    fmt::println("double* d = (double*)malloc(sizeof(double));");
    fmt::println("Adresse von d: {} wert von d {}) ",fmt::ptr(d), *d);
    *d = 3.1415;                                  // Wert manuell zuweisen
    fmt::println("Adresse von d: {} wert von d {}) ",fmt::ptr(d), *d);
    free(d);                                      // Speicher freigeben
    //std::cin.get();

    fmt::println("Use after free");
    *d = 47.11;
    fmt::println("*d = 47.11;");
    fmt::println("Adresse von d: {} wert von d {}) ",fmt::ptr(d), *d);
    //std::cin.get();
    
    d = (double*)malloc(sizeof(double));  // Speicher reservieren
    fmt::println("d = (double*)malloc(sizeof(double));  // Speicher reservieren");
    fmt::println("Adresse von d: {} wert von d {}) ",fmt::ptr(d), *d);
    //std::cin.get();
    *d = 0.815; 

    fmt::println("*d = 0.815;");
    fmt::println("Adresse von d: {} wert von d {}) ",fmt::ptr(d), *d);
    //std::cin.get();

    fmt::println("Speicherloch produziert....");
    d = new double(3.1415);   // Speicher im Heap reservieren
    fmt::println("d = new double(3.1415);");
    fmt::println("Wert: {}", *d);    // Zugriff über Dereferenzierung  
    fmt::println("Adresse: {}", fmt::ptr(d));
    delete d;                         // Speicher wieder freigeben
    
    fmt::println("------------------- Teil 3: Funktionen mit Zeigern -------------------");
    std::cin.get();
    
    
    fmt::println("changeValueByParameter(foo=={});",foo);
    std::cin.get();
    changeValueByParameter(foo);
    fmt::println("Der Wert von foo nach dem Funktionsaufruf {}",foo);
    std::cin.get();

    fmt::println("Adresse von bar=={}",fmt::ptr(&bar));
    fmt::println("changeValueByPointer(&bar==*({}));",bar);
    changeValueByPointer(&bar);
    std::cin.get();
    fmt::println("Der Wert von bar nach dem Funktionsaufruf {}",bar);
    fmt::println("Adresse von bar=={}",fmt::ptr(&bar));

    return 0; /* exit gracefully*/
}

// Die Implementierung der Funktion
void changeValueByParameter(int value) {
    // Der Wert von value ändert sich nur innerhalb der Funktion
    // Der scope von value ist auf die Funktion `changeValueByParameter` beschränkt
    value = 4711;
    fmt::println("Der wert von value in der Funktion (changeValueByParameter): {} ",value);
}

// Die Implementierung der Funktion
void changeValueByPointer(int* ptr) {
    // Da es sich bei ptr um einen Zeiger handelt wird der Wert auf den der Zeiger zeigt geändert.
    // Damit ändern sie eine Variable ausserhalb der Funktion.
    *ptr = 4711;
    fmt::println("Der wert von *ptr in der Funktion (changeValueByPointer): {} ", *ptr);
    fmt::println("Die Adresse von ptr in der Funktion (changeValueByPointer): {} ",fmt::ptr(ptr));
}

