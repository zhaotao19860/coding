#include <stdio.h>
#include <string.h>

void *my_memcpy_1(void *src, void *dst, int n)
{
    if (!src || !dst || n <= 0)
    {
        return NULL;
    }

    char *src_c = (char *)src;
    char *dst_c = (char *)dst;
    while (n > 0)
    {
        *dst_c = *src_c;
        dst_c++;
        src_c++;
        n--;
    }
    return dst;
}

void *my_memcpy_2(void *src, void *dst, size_t n)
{
    if (!src || !dst || n <= 0)
    {
        return NULL;
    }

    char *src_c = (char *)src;
    char *dst_c = (char *)dst;
    while (n > 0)
    {
        *dst_c = *src_c;
        dst_c++;
        src_c++;
        n--;
    }
    return dst;
}

int main(void)
{
    char src[] = {"I am zhaotao."};
    char dst[100];

    memset(dst, 0, sizeof(dst));

    if (my_memcpy_1(src, dst, strlen(src)))
        printf("dst string is [%s].\n", dst);
    else
        printf("memcpy failed.\n");

    return 0;
}