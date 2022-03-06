#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void test1()
{
    char data[6] = {'a', 'b', 'c', 'd', 'e','f'};
    const char arr[] = "/home/jim/test1/213.txt";
    int size;
    size = sizeof(arr);
    printf("data: %s\n", data);
    printf("size: %d\n", size);
    printf("4:%c, 5:%c\n", data[4], data[5]);
    const char *data1;
    const char* slash = strrchr(arr, '/'); // builtin function
    printf("stash: %s\n", slash);
    if (slash)
    {
        data1 = slash + 1;
        size -= static_cast<int>(arr - data1);
        printf("size: %d\n", size);
    }
}

int main()
{
    test1();
}