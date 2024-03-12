#ifndef _BITMATH_H_
#define _BITMATH_H_

#define SET_BIT(x, n)    x |= (1 << n)

#define CLEAR_BIT(x, n)  x &= ~(1 << n)

#define TOGGLE_BIT(x, n) x ^= (1 << n)
#define GET_BIT(x, n)  (x >> n) & 1
#endif
