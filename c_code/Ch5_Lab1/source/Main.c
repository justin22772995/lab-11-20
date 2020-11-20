#include <stdio.h>
#include <stdlib.h>

#define students	3
#define exams		4

void minimum(int [][exams], int, int);
void maximum(int [][exams], int, int);
void average(int [][exams], int, int);
void printArray(int [][exams], int, int);
void printMenu();

void printMenu() {
	printf("\n\tThe choice¡G\n");
	printf("\t0 Find the minimum grade\n");
	printf("\t1 Find the maximum grade\n");
	printf("\t2 Print the average on all texts for each student\n");
	printf("\t3 Print the array of grades\n");
	printf("\t4 End program\n");
	printf("Enter your choice¡G");
}

void minimum(int grades[][exams], int pupils, int tests) {
	int lowest = 101;

	for (int i = 0; i < pupils; i++) {
		for (int j = 0; j < tests; j++) {
			if (grades[i][j] < lowest) {
				lowest = grades[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is ¡G %d\n", lowest);
}

void maximum(int grades[][exams], int pupils, int tests) {
	int highest = -1;

	for (int i = 0; i < pupils; i++) {
		for (int j = 0; j < tests; j++) {
			if (grades[i][j] > highest) {
				highest = grades[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is ¡G %d\n", highest);
}

void average(int grades[][exams], int pupils, int tests) {
	int total = 0;

	for (int i = 0; i < pupils; i++) {
		total = 0;
		for (int j = 0; j < tests; j++) {
			total = total + grades[i][j];
		}
		printf("\n\tThe average grade for student %d is ¡G%.1f", i+1, (double)total / tests);
	}
	printf("\n");
}

void printArray(int grades[][exams], int pupils, int tests) {
	printf("\n\t\t\t [0]    [1]    [2]    [3]");
	for (int i = 0; i < pupils; i++) {
		printf("\n\tStudent %d grade¡G", i);
		for (int j = 0; j < tests; j++) {
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}

int main(void) {
	int studentgrades[students][exams] = {	{77,68,86,73},
											{96,87,89,78},
											{70,90,86,81} };

	void (*gradecalculat[4])(int[students][exams], int, int) = {	minimum,		// 0	
																	maximum,		// 1	
																	average,		// 2
																	printArray };	// 3

	int choice = 0;

	while (choice != 4) {
		do{
			printMenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice > 4);

		if (choice != 4) {
			(*gradecalculat[choice])(studentgrades, students, exams);
		}else {
			printf("\tProgram Ended.\n");
		}
	}

	system("pause");
	return 0;
}