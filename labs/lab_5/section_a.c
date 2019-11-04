#include <stdio.h>
#include <stdlib.h>

void print_array(int * arr, int len){

    for (int i = 0; i < len; i += 1) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse_string_inplce(char * word, int len){

    for (int i = len - 1; i > len/2 - 1; i -= 1) {

        char temp = word[i];
        word[i] = word[len - 1 - i];
        word[len -1 - i] = temp;
    }

}

void delay1unit(){
    for (int i = 0; i < 1000000; i+=1);
}

void delay(int t){
    for (int i = 0; i < t; i += 1) {
        delay1unit();
    }
}

int main() {

    int test_arr[] = {1, 2, 5, 6, 2};
    char test_word[] = "raoryaora";

    print_array(test_arr, 5);

    printf("%s -> ", test_word);
    reverse_string_inplce(test_word, 9);
    printf("%s\n", test_word);

    delay1unit();
    printf("delayed one unit\n");

    int test_t = 2000;
    delay(test_t);
    printf("delayed %d units\n", test_t);

    return 0;
}