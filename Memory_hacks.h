#include <stdlib.h>

// TODO: #define safeFree(p) saferFree((void**)&(p))
void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}