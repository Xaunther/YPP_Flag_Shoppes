//Implementation of Write Data function

#include <stdio.h>
#include "Write_Data.h"

size_t Write_Data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}