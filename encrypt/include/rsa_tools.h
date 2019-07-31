#ifndef RSA_TOOLS_H
#define RSA_TOOLS_H

#include <stdint.h>

#define smallnum int64_t
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))



/* functions for smallnum */
smallnum gcdEx_smallnum_recursive(smallnum a, smallnum b, smallnum *x, smallnum *y);
smallnum gcdEx_smallnum_iterative(smallnum a, smallnum b, smallnum * const x, smallnum * const y);
smallnum find_inverse_smallnum(smallnum a, smallnum n);
smallnum mod_power_smallnum(smallnum a, smallnum k, smallnum n);


#define word uint64_t
typedef struct _bignum {
	int length;
	word* data;
} bignum;

#endif // RSA_TOOLS_H