/* CS261- HW1 - Program3.c*/
/* Name: Bernardo Mendes
 * Date: 1/19/24
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int* number, int n){
     /*Sort the array of integeres of length n*/
	int i;
	int j;
	int current;

	for (i = 1; i < n; i++) {
		current = number[i];
		j = i - 1;

		while (j >= 0 && number[j] > current) {
			number[j + 1] = number[j];
			j = j - 1;
		}
		number[j + 1] = current;
	}	
}

void fill(int* number, int n){
	int i;
        for (i = 0; i < n; i++) {
                number[i] = rand() % 100;
        }
}

void output(int* number, int n){
	int i;
	for (i = 0; i < n; i++) {
                printf("\n%d", i + 1);
                printf(". %d", number[i]);
        }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    /*Al
     * locate memory for an array of n integers using malloc.*/
	int *array = malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
	fill(array, n);	
    /*Print the contents of the array.*/
	printf("\nUnsorted Array");
	output(array, n);
    /*Pass this array along with n to the sort() function of part a.*/
   	sort(array, n); 
    /*Print the contents of the array.*/    
    	printf("\nSorted Array");
	output(array, n);
	free(array);
	return 0;
}
