//
// Created by sai-pher on 29/10/2019.
//

/**Static	variables
 * Declare	a	variable	v	as	an	integer
 * Initialize	it	to	100
 * Print it	out	as	oct,	dec,	hex.
 * Print out	the	address	of	v	(consider	using	%x,	a	%p	for	void	pointers	also	exists)
 * Ask	the	user	to	enter	a	number
 * Print it	out
 * Pass	your	data	to	a	function	by	value
 * In	the	function, compute the data BITWISE AND	0x17.	Consider	using	v=v&2	in	the	function
 * Print the	data
 * There is	no	return	type.
 * In	the	main,	print	the	new(?)	value	of	v
 * Pass	your	data	to	a	function	by	reference
 * In	the	function,	the	data	BITWISE	OR	0x17.
 * Print	the	data
 * There is	no	return	type.
 * In	the	main,	print	the	new	value	of	v
 * Pass	your	data	to	a	function	that	returns		the	data	BITWISE	XOR	0x17.
 * Print	the		data	(result	of	the	operation)	within	the	function
 * In	the	main,	print	the	retuned	value	of	the	operation		and	the	current	value	of	data
**/

#include <stdio.h>
#include <stdlib.h>

int bit_and_17(int x){
    return x & 2;
}

int main(){

    int v = 100;
    int n;
    printf("Octal: %o, Decimal: %d, Hexadecimal: %x\n", v, v, v);

    printf("Address of v: %p\n", &v);

    printf("Input a number: ");
    scanf("%d", &n);
    printf("n: %d\n", n);
    printf("%x", bit_and_17(n));

    return 0;
}
