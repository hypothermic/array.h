/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <admin@hypothermic.nl> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * -----------------------------------------------------------------------------
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    intptr_t *array;
    size_t used;
    size_t size;
} Array;

void array_init(Array *a, size_t initialSize)
{
    a->array = (intptr_t *)malloc(initialSize * sizeof(intptr_t));
    a->used = 0;
    a->size = initialSize;
}

void array_append(Array *a, intptr_t element)
{
    if (a->used == a->size)
    {
        a->size++;
        a->array = (intptr_t *)realloc(a->array, a->size * sizeof (intptr_t));
    }
    a->array[a->used++] = element;
}

void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

#endif // ARRAY_H_