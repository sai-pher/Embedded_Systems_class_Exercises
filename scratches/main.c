#include <stdlib.h>
#include <stdio.h>

#define shiftl(x, n) (x << n)

char *reverse(char *arr, int len){

    char *res = calloc(len, sizeof(char));

    for (int i = len-1; i >= 0; i-=1)
    {
        int j = len-1 - i;
        char n = arr[i];
        res[j] = n;
    }

    return res;
}


int main(int argc, char const *argv[])
{
    int arrLen = 10;
    char *arr = "1234567890";

    char *res = reverse(arr, arrLen);

    unsigned int x = 1;
    unsigned int n = 3;

    printf("%s, %d", res, shiftl(x, n));
    return 0;
}
