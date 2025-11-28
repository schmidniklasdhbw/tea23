#include "vector.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <fmt/format.h>

Vector_t* NewVextor(void) {
    fmt::println("in \"{}\"",__func__);
    return NULL;
}

void vector_init(Vector_t* vec){
    fmt::println("in \"{}\"",__func__);
}

void vector_clear(Vector_t* vec) {
    fmt::println("in \"{}\"",__func__);
}

int vector_push_back(Vector_t* vec, unsigned int value) {
    fmt::println("in \"{}\"",__func__);
    return EXIT_FAILURE;
}

int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue) {
    fmt::println("in \"{}\"",__func__);
    return EXIT_FAILURE;
}

void vector_print(const Vector_t* vec) {
    fmt::println("in \"{}\"",__func__);
}