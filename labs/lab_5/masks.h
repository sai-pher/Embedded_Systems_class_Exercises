//
// Created by sai-pher on 01/11/2019.
//

#ifndef LAB_5_MASKS_H
#define LAB_5_MASKS_H

#define MASK(x) (unsigned short int)(1 << x)
#define SHIFTL(x, y) (long int)(x << y)
#define SHIFTR(x, y) (long int)(x >> y)

#define SET(d, pos) (d |= MASK(pos))
#define TOGGLE(d, pos) (d ^= MASK(pos))
#define CLEAR(d, pos) (d &= ~MASK(pos))
#define READ(d, pos) ((d & MASK(pos)) >> pos)

#define POS0 MASK(0)
#define POS1 MASK(1)
#define POS2 MASK(2)
#define POS3 MASK(3)
#define POS4 MASK(4)
#define POS5 MASK(5)
#define POS6 MASK(6)
#define POS7 MASK(7)
#define POS8 MASK(8)
#define POS9 MASK(9)
#define POS10 MASK(10)
#define POS11 MASK(11)
#define POS12 MASK(912
#define POS13 MASK(13)
#define POS14 MASK(14)
#define POS15 MASK(15)
#define POS16 MASK(16)

#endif //LAB_5_MASKS_H
