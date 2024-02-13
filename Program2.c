/* CS261- HW1 - Program2.c*/
/* Name: Bernardo Mendes
 * Date: 1/19/24
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* students = (struct student*)malloc(10 * sizeof(struct student));
     /*return the pointer*/
     if (students == NULL) {
	return NULL;
     }
     return students;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
	int i;
	for (i = 0; i < 10; i++) {
		students[i].initials[0] = 'A' + (rand() % 26);
		students[i].initials[1] = 'A' + (rand() % 26);
		students[i].score = rand() % 101;
	}
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
	int i;
	for (i = 0; i < 10; i++){
		printf("\n%d", i + 1);
		printf(". %c", students[i].initials[0]);
	      	printf("%c", students[i].initials[1]);
		printf(" %d", students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int sum = 0;
     int max = students[0].score;
     int min = students[0].score;
     int i;
     for (i = 0; i < 10; i++) {
	sum += students[i].score;
	if (max < students[i].score) {
		max = students[i].score;
	}
	if (min > students[i].score) {
		min = students[i].score;
	}
     }
     printf("\nsum: %d", sum);
     printf("\nmin: %d", min);
     printf("\nmax: %d", max);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if (stud != NULL) {
		free(stud);
	}
}

int main(){
    struct student* stud = NULL;
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	srand(time(NULL));
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	deallocate(stud);
    return 0;
}
