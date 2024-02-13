/* CS261- HW1 - Program1.c*/
/* Name: Bernardo Mendes
 * Date: 1/19/24
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /* Increment a */
	(*a)++;
    /* Decrement b */
	(*b)--;
    /* Assign a-b to c */
    	c = (*a) - (*b);
    /* Return c */
	return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	int x = rand() % 11;
	int y = rand() % 11;
	int z = rand() % 11;
    /* Print the values of x, y and z */
	printf("pre-foo()");
	printf("\nx value: %d", x);
	printf("\ny value: %d", y);
	printf("\nz value: %d", z);
    /* Call foo() appropriately, passing x,y,z as parameters */
	printf("\n\nreturned value: %d", foo(&x, &y, z));	
    /* Print the values of x, y and z */
	printf("\n\npost-foo()");
	printf("\nx value: %d", x);
	printf("\ny value: %d", y);
	printf("\nz value: %d", z);	
    /* Print the value returned by foo */
 	/* printf("\n\nreturned value: %d", foo(&x, &y, z)); */
    /* Is the return value different than the value of z?  Why? */
	return 0;
}
    
    
