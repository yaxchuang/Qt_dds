#include "rsa_tools.h"


/* 
 * @brief Extended Euclidean Algorithm using recursion
 * @param a,b two numbers to find greatest common divisor
 * @param x satisfies ax+by=d=gcd(a,b). x is inverse of a mod b, if gcd(a,b)=1
 * @param y satisfies ax+by=d=gcd(a,b). y is inverse of b mod a, if gcd(a,b)=1
 * @return d=gcd(a,b), greatest common divisor of a and b
 */
smallnum gcdEx_smallnum_recursive(smallnum a, smallnum b, smallnum *x, smallnum *y) 
{
    if(b == 0) {
        *x = 1,*y = 0;
        return a;
    }
    else {
        long long r = gcdEx_smallnum_recursive(b, a%b, x, y); /* r = GCD(a, b) = GCD(b, a%b) */
        smallnum t = *x;
        *x = *y;
        *y = t - a/b * *y;
        return r;
    }
}


/* 
 * @brief Extended Euclidean Algorithm using iteration
 * @param a,b two numbers to find greatest common divisor
 * @param x satisfies ax+by=d=gcd(a,b). x is inverse of a mod b, if gcd(a,b)=1
 * @param y satisfies ax+by=d=gcd(a,b). y is inverse of b mod a, if gcd(a,b)=1
 * @return d=gcd(a,b), greatest common divisor of a and b
 */
smallnum gcdEx_smallnum_iterative(smallnum a, smallnum b, smallnum * const x, smallnum * const y){
    
    smallnum r0 = MAX(a,b), r1 = MIN(a,b);
    smallnum q, r;
    smallnum x0 = 1, x1 = 0;
    smallnum y0 = 0, y1 = 1;

    // if b == 0, gcd(a,b)=a
	if (r1 == 0)
		goto end;

	while(r1 > 0) {
		// calculate q_n, r_n
        q = r0 / r1; // q_n = floor( r_{n-2} / r_{n-1} )
		r = r0 - q * r1; // r_n = r_{n-2} mod r_{n-1} )
		
		// calculate x_n, y_n
		*x = x0 - q * x1; // x_n = x_{n-2} - q_n * x_{n-1}
		*y = y0 - q * y1; // y_n = y_{n-2} - q_n * y_{n-1}

        // update x_{n-1}, x_{n-2}
		x0 = x1;
		x1 = *x;
		y0 = y1;
		y1 = *y;

        // update r_{n-1}, r_{n-2}
		r0 = r1; 
		r1 = r;
	}

end:
    // x = x_n, y = y_n
	*x = x0;
	*y = y0;

    // return d=gcd(a,b)=r_n
	return r0;
}


/* 
 * @brief Compute a^(-1) mod n by Extended Euclidian method
 * @return a^(-1) mod n
 */
smallnum find_inverse_smallnum(smallnum a, smallnum n) 
{
#ifndef MINE
	smallnum b = n;
	smallnum x = 0, y = 1, x0 = 1, y0 = 0, q, temp;
	while(b != 0) {
		q = a / b;
		temp = a % b;
		a = b;
		b = temp;
		temp = x; x = x0 - q * x; x0 = temp;
		temp = y; y = y0 - q * y; y0 = temp;
	}
	if(x0 < 0) x0 += n;
	return x0;
#else
    smallnum a1 = MAX(a,n), b1 = MIN(a,n);
    smallnum x, y;
    gcdEx_smallnum_iterative(a1, b1, &x, &y);
    
    while(y < 0) {
        y += a1;
    }

    return y;
#endif
}



/* 
 * @brief Modular exponentiation, compute base^exponent mod modulus
 * @return base^exponent mod modulus
 */
smallnum mod_power_smallnum(smallnum base, smallnum exponent, smallnum modulus)
{
	smallnum res = 1;
	while (exponent > 0) {
		if (exponent & 1) res = (res * base) % modulus;
		base = (base * base) % modulus;
		exponent >>= 1;
	}
	return res;
}


