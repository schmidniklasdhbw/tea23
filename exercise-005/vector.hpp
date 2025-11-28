#ifndef MY_FANCY_VECTOR_H__
#define MY_FANCY_VECTOR_H__

#include <stdio.h> // for size_t

/*
 * We forward declare the opaque list
 * This is possible due to the fact 
 * we only work with the pointer to the struct
 * No direct access to Vector_t/Vector attributes possible
 */
typedef struct Vector Vector_t;

Vector_t* NewVector(void);

void vector_init(Vector_t* vec);
void vector_clear(Vector_t* vec);

int vector_push_back(Vector_t* vec, unsigned int value);
int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue);
void vector_print(const Vector_t* vec);

#endif // MY_FANCY_VECTOR_H__