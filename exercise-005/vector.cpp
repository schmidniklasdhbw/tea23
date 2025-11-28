#include "vector.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <fmt/format.h>

typedef struct Vector {
    unsigned int* data;
    unsigned int size;
    unsigned int capacity;
} Vector_t;

// File-scope constants for initial allocation and growth policy
static const unsigned int INITIAL_CAPACITY = 10;
static const unsigned int GROWTH_FACTOR = 2;

/**
 * @brief Ensures the vector has at least `min_capacity` capacity.
 *
 * Uses `realloc` to grow the internal storage. Returns `EXIT_SUCCESS`
 * on success or `EXIT_FAILURE` if allocation fails.
 */
int vector_reserve(Vector_t* vec, unsigned int min_capacity) {
    if (vec == NULL) {
        return EXIT_FAILURE;
    }
    if (vec->capacity >= min_capacity) {
        return EXIT_SUCCESS;
    }

    unsigned int new_capacity = (vec->capacity == 0) ? INITIAL_CAPACITY : vec->capacity;
    while (new_capacity < min_capacity) {
        new_capacity = (new_capacity == 0) ? INITIAL_CAPACITY : new_capacity * GROWTH_FACTOR;
    }

    unsigned int* new_data = (unsigned int*) realloc(vec->data, new_capacity * sizeof(unsigned int));
    if (new_data == NULL) {
        return EXIT_FAILURE;
    }
    vec->data = new_data;
    vec->capacity = new_capacity;
    return EXIT_SUCCESS;
}


Vector_t* NewVector(void) {
    fmt::println("in \"{}\"",__func__);
    Vector_t* pVec = (Vector_t*) malloc(sizeof(Vector_t));
    if(pVec != NULL) {
        pVec->data = NULL;
        pVec->size = 0;
        pVec->capacity = 0;
    }
    return pVec;
}

void vector_init(Vector_t* vec){
    fmt::println("in \"{}\"",__func__);
    if(vec != NULL) {
        vec->data = NULL;
        vec->size = 0;
        vec->capacity = 0;
        // Pre-allocate default capacity to avoid repeated reallocations
        if (vector_reserve(vec, INITIAL_CAPACITY) != EXIT_SUCCESS) {
            fmt::println("Warning: vector_reserve failed during init");
        }
    }
}

void vector_clear(Vector_t* vec) {
    fmt::println("in \"{}\"",__func__);
    if(vec != NULL) {
        // Keep the allocated buffer and capacity to allow fast reuse.
        // Only reset the logical size to zero so the vector appears empty.
        vec->size = 0;
    }
}

void vector_free(Vector_t* vec) {
    fmt::println("in \"{}\"",__func__);
    if (vec != NULL) {
        if (vec->data != NULL) {
            free(vec->data);
            vec->data = NULL;
        }
        free(vec);
    }
}

int vector_push_back(Vector_t* vec, unsigned int value) {
    fmt::println("in \"{}\"",__func__);
    if(vec == NULL) {
        return EXIT_FAILURE;
    }

    // Ensure space for the new element. Use vector_reserve to centralize
    // reallocation logic and avoid duplication.
    // See: https://en.cppreference.com/w/c/memory/realloc
    if (vec->size >= vec->capacity) {
        if (vector_reserve(vec, vec->size + 1) != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
    }

    vec->data[vec->size] = value;
    vec->size += 1;
    return EXIT_SUCCESS;
}

int vector_get(const Vector_t* vec, unsigned int index, unsigned int* outValue) {
    fmt::println("in \"{}\"",__func__);
    if(vec == NULL || outValue == NULL) {
        return EXIT_FAILURE;
    }

    if(index >= vec->size) {
        fmt::println("Index out of bounds: {}", index);
        return EXIT_FAILURE;
    }

    *outValue = vec->data[index];
    return EXIT_SUCCESS;
}

void vector_print(const Vector_t* vec) {
    fmt::println("in \"{}\"",__func__);
    if(vec != NULL) {
        fmt::println("Vector size: {}, capacity: {}", vec->size, vec->capacity);
        for(unsigned int i = 0; i < vec->size; i++) {
            fmt::print("{} ", vec->data[i]);
        }
        fmt::println("");
    }
}