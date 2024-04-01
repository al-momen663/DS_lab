#include <stdio.h>

#define MAX_STUDENTS 50
#define MAX_GRADES 10

struct Student
{
	char name[50];
	float grades[MAX_GRADES];
	int numGrades;
	float averageGrade;
};

void inputGrades(struct Student *student)
{
	printf("Enter the number of grades for %s: ", student->name);
	scanf("%d", &student->numGrades);

	printf("Enter %d grades for %s:\n", student->numGrades, student->name);
	for (int i = 0; i < student->numGrades; ++i)
	{
		scanf("%f", &student->grades[i]);
	}
}

void calculateAverage(struct Student *student)
{
	float sum = 0.0;
	for (int i = 0; i < student->numGrades; ++i)
	{
		sum += student->grades[i];
	}
	student->averageGrade = sum / student->numGrades;
}

void bubbleSort(struct Student students[], int numStudents)
{
	for (int i = 0; i < numStudents - 1; ++i)
	{
		for (int j = 0; j < numStudents - i - 1; ++j)
		{
			if (students[j].averageGrade < students[j + 1].averageGrade)
			{
				// Swap students
				struct Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int numStudents;
	printf("Enter the number of students: ");
	scanf("%d", &numStudents);

	struct Student students[MAX_STUDENTS];
	for (int i = 0; i < numStudents; ++i)
	{
		printf("Enter name of student %d: ", i + 1);
		scanf("%s", students[i].name);
		inputGrades(&students[i]);
		calculateAverage(&students[i]);
	}
	bubbleSort(students, numStudents);

	printf("\nStudent Rankings (by average grade):\n");
	for (int i = 0; i < numStudents; ++i)
	{
		printf("%d. %s (Average Grade: %.2f)\n", i + 1, students[i].name, students[i].averageGrade);
	}

	return 0;
}
