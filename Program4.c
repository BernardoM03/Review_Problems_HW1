/* CS261- HW1 - Program4.c*/
/* Name: Bernardo Mendes
 * Date: 1/19/24
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct student{
	char initials[2];
	int score;
};

int compare(const char* init1, const char* init2){
	return strcmp(init1, init2);
}

void sort(struct student* students, int n){
     /*Sort n students based on their initials*/
	int i;
	int j;
	struct student current;
	for (i = 1; i < n; i++) {
		current = students[i];
		j = i - 1;

		while (j >= 0 && compare(students[j].initials, current.initials) > 0) {
			students[j + 1] = students[j];
			j = j - 1;	
		}	
		students[j + 1] = current;		
	}
}

void generate(struct student* students, int n){
	int i;
	for (i = 0; i < n; i++) {
		students[i].initials[0] = 'A' + (rand() % 26);
		students[i].initials[1] = 'A' + (rand() % 26);
		students[i].score = rand() % 101;
	} 
}

void output(struct student* students, int n){
	int i;
	for (i = 0; i < n; i++){
		printf("\n%d", i + 1);
		printf(". %c", students[i].initials[0]);
	      	printf("%c", students[i].initials[1]);
		printf(" %d", students[i].score);
	}
}

void deallocate(struct student* students) {
	if (students != NULL){
		free(students);
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10;
    /*Allocate memory for n students using malloc.*/
	struct student* students = (struct student*)malloc(n * sizeof(struct student));
    /*Generate random initials and scores for the n students, using rand().*/
	srand(time(0));
	generate(students, n);
    /*Print the contents of the array of n students.*/
	printf("\nUnsorted Students");
	output(students, n);
    /*Pass this array along with n to the sort() function*/
	sort(students, n);
    /*Print the contents of the array of n students.*/
	printf("\nSorted Students");
	output(students, n);
	deallocate(students);
	return 0;
}
