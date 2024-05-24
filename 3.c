#include <stdio.h>
#include <string.h>

struct Student
{
	int roll;
	char firstName[50];
	float marks;
};

int main()
{
	struct Student students[100];
	int numStudents = 0;
	students[numStudents].roll = 1;
	strcpy(students[numStudents].firstName, "Momen");
	students[numStudents].marks = 85.5;
	numStudents++;

	students[numStudents].roll = 2;
	strcpy(students[numStudents].firstName, "Shad");
	students[numStudents].marks = 78.0;
	numStudents++;
	students[numStudents].roll = 3;
	strcpy(students[numStudents].firstName, "Shad");
	students[numStudents].marks = 78.0;
	numStudents++;
	students[numStudents].roll = 4;
	strcpy(students[numStudents].firstName, "Shad");
	students[numStudents].marks = 78.0;

	printf("Initial student records:\n");
	for (int i = 0; i < numStudents; ++i)
	{
		printf("Roll number %d: %s (Marks: %.1f)\n", students[i].roll, students[i].firstName, students[i].marks);
	}

	int rollToDelete;
	printf("\nEnter the roll number of the student to delete: ");
	scanf("%d", &rollToDelete);

	int found = 0;
	for (int i = 0; i < numStudents; ++i)
	{
		if (students[i].roll == rollToDelete)
		{
			for (int j = i; j < numStudents - 1; ++j)
			{
				students[j] = students[j + 1];
			}
			numStudents--;
			found = 1;
			break;
		}
	}

	if (found)
	{
		printf("Student with roll number %d deleted successfully.\n", rollToDelete);
	}
	else
	{
		printf("Student with roll number %d not found.\n", rollToDelete);
	}

	printf("\nUpdated student records:\n");
	for (int i = 0; i < numStudents; ++i)
	{
		printf("Roll number %d: %s (Marks: %.1f)\n", students[i].roll, students[i].firstName, students[i].marks);
	}

	return 0;
}
