#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 12;

    switch (x){
        case 10:
            printf("%d", 10);
            break;
        case 11:
            printf("%d", 11);
            break;
        case 12:
            printf("%d", 12);
            break;
        default:
            printf("%d", 0);
    }

    int a[10];

    a[0] = 1;
    a[2] = 3;

    printf("%d, %d, %d", a[1], a[2], a[20]);

    return 0;
}
