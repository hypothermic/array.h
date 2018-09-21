# array.h

Simple but easy-to-use tool to create arrays.  
Any allocated object can be appended to the array.

## Example

```c
#include "array.h"

int main(int argc, char **argv)
{
    Array *array;

    // Initialize the array.
    array_init(array, 0);

    // Add an object to the array.
    // Make sure the object is allocated!
    char* text = "Hello world!";
    array_append(array, (intptr_t) text);

    // Once you're done, free the array.
    array_free(array);
}
```