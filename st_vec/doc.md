# st_vec
dynami array libray

## features
* for any types like regular { int, char} and custom structs
* automatic growing and shrinkig

## use 

```c
#include "st_lib/st_vec/st_vec.h"
```

* create a st_vec 
    ```c 
    st_vec *st_vec_create(size_t items_size)

    //exampe
    st_vec *vec = st_vec_create(sizeof(int));
    ```
* get element
    ```c
    void st_vec_get(st_vec *vec, size_t index, void *output)

    //example
    int n1;
    st_vec_get(vec, 0, &n1);
    ```

* append element
    ```c
    void st_vec_append(st_vec *vec, const void *input)

    //example
    int n1 = 666;
    st_vec_append(vec, &n1)
    ```

* insert element
    ```c
    void st_vec_insert(st_vec *vec, const void *input, size_t index)

    //example
    int n1 = 666;
    st_vec_insert(vec, &n1, 0);
    ```

* pop element (delete last element)
    ```c
    st_vec_pop(st_vec *vec)

    //example
    st_vec_pop(vec)
    ```

* delete element
    ```c
    void st_vec_delete(st_vec *vec, size_t index)

    //example
    int n1 = 666;
    st_vec_delete(vec, 1)
    ```

* dispose st_vec (free st_vec from memory)
    ```c
    void st_vec_dispose(st_vec *vec)

    //example
    st_vec_dispose(vec)
    ```