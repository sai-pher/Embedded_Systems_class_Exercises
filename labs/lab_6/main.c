#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MASK(x) (unsigned long int)(1 << x)
#define SHIFT(x) (long int)(1 << (x - 1))

#define PTB18 MASK(18)
#define PTB19 MASK(19)
//.....the rest

// NB: set field values using SHIFT(10)
struct SIM {
    unsigned long int SCGC5;        // SCGC5 is a 32-bit field.
};
// NB: set field values using PCR[pin-pos] = SHIFT(8)
struct PORTB {
    unsigned long int PCR[32];      // PCR is an array, with each entry being a 32 bit field.
};

// NB: set field values using SHIFT(pin-pos)
struct PTB {
    unsigned long int PDDR;         // PDDR is a 32-bit field defining a pin as digital [1] or analogue [0].
    unsigned long int PSOR;         // PSOR is a 32-bit field defining if a pin is on [1] (0 has no effect).
    unsigned long int PCOR;         // PCOR is a 32-bit field defining if a pin is off [1] (0 has no effect).
};

void bin(unsigned n) {
    /* step 1 */
    if (n > 1)
        bin(n / 2);

    /* step 2 */
    printf("%d", n % 2);
}

int main() {

    // Initialise registers
    struct SIM sim = {0};
    struct PORTB portb = {(unsigned long) calloc(32, sizeof(unsigned long int))};
    struct PTB ptb = {0, 0, 0};

    // Set register values

    // Clock for port B enable
    sim.SCGC5 = SHIFT(10);


    portb.PCR[18] = SHIFT(8);
    portb.PCR[19] = SHIFT(8);

    ptb.PDDR = (SHIFT(19)) | (SHIFT(18));


    // PCOR == OFF
    ptb.PCOR = (SHIFT(19)) | (SHIFT(18));

    // PSOR == ON
    ptb.PSOR = (SHIFT(19)) | (SHIFT(18));

    // Idle loop
    for (long int i = 1; i <= 0x80000 * 10; i += 1) {
        // On-Off feature.
        if (i % 0x80000 == 0) {
            printf("\nCycle: %ld || Counter: %ld ", i / 0x80000, i);
            if (sim.SCGC5 == pow(2, 9)) {
                printf("Clock on: %lx >> %f\n", sim.SCGC5, pow(2, 9));
                if (ptb.PSOR == SHIFT(18)) {

                    // Use the SHIFT macro as the guide and flip the bits before the next iteration.

                    printf("\nPTB18 >> %ld || Status: ON >> %ld \n", PTB18, ptb.PSOR);
                    printf("PTB19 >> %ld || Status: OFF >> %ld \n", PTB19, ptb.PCOR);

                    // Flip values of PSOR and PCOR
                    ptb.PCOR = SHIFT(18);           // Turn off PTB18
                    ptb.PSOR = SHIFT(19);           // Turn on PTB19


                } else {

                    printf("\nPTB18 >> %ld || Status: OFF >> %ld \n", PTB18, ptb.PSOR);
                    printf("PTB19 >> %ld || Status: ON >> %ld \n", PTB19, ptb.PCOR);

                    // Flip values of PSOR and PCOR
                    ptb.PCOR = SHIFT(19);           // Turn off PTB19
                    ptb.PSOR = SHIFT(18);           // Turn on PTB18
                }
            }
        }
    }

    return 0;
}