//
// Created by sai-pher on 01/11/2019.
//

#ifndef LAB_5_FXNPROT_H
#define LAB_5_FXNPROT_H

#include <stdio.h>
#include <stdlib.h>
#include "masks.h"

void binary_format(int x) {

    printf("0b");
    for (int i = 16; i >= 0; i -= 1) {
        printf("%d", (x & MASK(i)) >> i );
    }
    printf("\n");
}

void data40operations() {
    short int data = 0b00101000;
    printf("\nData40operations\nData hex: %x\n", data);

    printf("Bit at position 3: %x\n", (data & POS3) >> 3);
    printf("Bit at position 4: %x\n", (data & POS4) >> 4);

    SET(data, 1);

    short int data_c = data;
    printf("Data hex: %x\n", data);

    printf("Reverse Data bin: 0b");
    for (int i = 0; i < 16; i += 1) {
        printf("%d",(data_c & POS0));
        data_c >>= 1;
    }

    printf("\nData Bin: ");
    binary_format(data);
}

void changebits() {
    short int data = 0b00101000;

    printf("\nChangebits\nData %d: ", data);
    binary_format(data);
    short int bit_pos;
    printf("input a bit position to change: ");
    scanf("%hd",&bit_pos);
    SET(data, bit_pos);

    printf("Data %d: ", data);
    binary_format(data);
}

void toggle() {
    short int data = 0b00101000;

    printf("\nToggle\nData %d: ", data);
    binary_format(data);
    short int bit_pos;
    printf("input a bit position to toggle: ");
    scanf("%hd",&bit_pos);
    TOGGLE(data, bit_pos);

    printf("Data %d: ", data);
    binary_format(data);
}

void clear(){
    short int data = 0b00101000;

    printf("\nClear\nData %d: ", data);
    binary_format(data);
    short int bit_pos;
    printf("input a bit position to clear: ");
    scanf("%hd",&bit_pos);
    CLEAR(data, bit_pos);

    printf("Data %d: ", data);
    binary_format(data);
}

void read4positions(int *c0, int *c1, int *c2, int *c3) {
    char C[10]; //just to avoid stack smashing
    printf("\ninput 4 positions: ");
    scanf("%s", C);
    //printf("data is %s\n", C);
    *c0=C[0]-'0';
    *c1=C[1]-'0';
    *c2=C[2]-'0';
    *c3=C[3]-'0';
}

void read4positions_op(int opp) {

    short int data = 40;

    int d0, d1, d2, d3;
    printf("\nTest read4positions_op");
    read4positions(&d0, &d1, &d2, &d3);
    printf("%d %d %d %d\n", d0, d1, d2, d3);
    //checking values read.

    switch (opp){
        case 0: // Clear
            CLEAR(data, d0);
            CLEAR(data, d1);
            CLEAR(data, d2);
            CLEAR(data, d3);

            binary_format(data);
            break;
        case 1: // Set
            SET(data, d0);
            SET(data, d1);
            SET(data, d2);
            SET(data, d3);

            binary_format(data);
            break;
        case 2: // Toggle
            TOGGLE(data, d0);
            TOGGLE(data, d1);
            TOGGLE(data, d2);
            TOGGLE(data, d3);

            binary_format(data);
            break;
        case 3: // Read
            READ(data, d0);
            READ(data, d1);
            READ(data, d2);
            READ(data, d3);

            binary_format(data);
            break;
    }

}

#endif //LAB_5_FXNPROT_H
