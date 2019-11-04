//
// Created by sai-pher on 30/10/2019.
//

#include "fxnprot.h"

int main(){

    data40operations();

    changebits();

    toggle();

    clear();

    int d0, d1, d2, d3;
    read4positions(&d0, &d1, &d2, &d3);
    printf("%d %d %d %d", d0, d1, d2, d3);
    //checking values read.

    int op = 0;
    printf("\ninput operation to execute:\n0: clear\n1: set\n2: toggle\n3: read\nop: ");
    scanf("%d", &op);
    read4positions_op(op);

    return 0;
}
