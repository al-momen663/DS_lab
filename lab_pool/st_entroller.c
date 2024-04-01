#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 5

// Structure to represent a student
struct Student
{
	int id;
	char name[50];
	int enrolledCourses[MAX_COURSES];
	int numCourses;
};

// Global array to store student records
struct Student studentList[MAX_STUDENTS];
int numStudents = 0;

// Function to enroll a student in a course
void enrollStudent(int studentId, int courseId)
{
	if (numStudents >= MAX_STUDENTS)
	{
		printf("Student database is full. Cannot enroll more students.\n");
		return;
	}

	// Check if student already exists
	for (int i = 0; i < numStudents; i++)
	{
		if (studentList[i].id == studentId)
		{
			// Enroll the student in the course
			if (studentList[i].numCourses < MAX_COURSES)
			{
				studentList[i].enrolledCourses[studentList[i].numCourses] = courseId;
				studentList[i].numCourses++;
				printf("Student enrolled in course %d successfully!\n", courseId);
			}
			else
			{
				printf("Student has reached the maximum course limit.\n");
			}
			return;
		}
	}

	// If student doesn't exist, add a new student
	studentList[numStudents].id = studentId;
	printf("Enter student name: ");
	scanf("%s", studentList[numStudents].name);
	studentList[numStudents].enrolledCourses[0] = courseId;
	studentList[numStudents].numCourses = 1;
	numStudents++;
	printf("New student enrolled in course %d successfully!\n", courseId);
}

// Function to drop a student from a course
void dropStudent(int studentId, int courseId)
{
	for (int i = 0; i < numStudents; i++)
	{
		if (studentList[i].id == studentId)
		{
			// Find the course and remove it
			for (int j = 0; j < studentList[i].numCourses; j++)
			{
				if (studentList[i].enrolledCourses[j] == courseId)
				{
					// Shift remaining courses to fill the gap
					for (int k = j; k < studentList[i].numCourses - 1; k++)
					{
						studentList[i].enrolledCourses[k] = studentList[i].enrolledCourses[k + 1];
					}
					studentList[i].numCourses--;
					printf("Student dropped from course %d successfully!\n", courseId);
					return;
				}
			}
			printf("Student is not enrolled in course %d.\n", courseId);
			return;
		}
	}
	printf("Student not found.\n");
}

// Function to search for a student by ID
void searchStudent(int studentId)
{
	for (int i = 0; i < numStudents; i++)
	{
		if (studentList[i].id == studentId)
		{
			printf("Student found! Name: %s\n", studentList[i].name);
			printf("Enrolled courses:");
			for (int j = 0; j < studentList[i].numCourses; j++)
			{
				printf(" %d", studentList[i].enrolledCourses[j]);
			}
			printf("\n");
			return;
		}
	}
	printf("Student not found.\n");
}

int main()
{
	int choice, studentId, courseId;

	while (1)
	{
		printf("\nStudent Enrollment System Menu:\n");
		printf("1. Enroll student in a course\n");
		printf("2. Drop student from a course\n");
		printf("3. Search student by ID\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter student ID: ");
			scanf("%d", &studentId);
			printf("Enter course ID: ");
			scanf("%d", &courseId);
			enrollStudent(studentId, courseId);
			break;
		case 2:
			printf("Enter student ID: ");
			scanf("%d", &studentId);
			printf("Enter course ID: ");
			scanf("%d", &courseId);
			dropStudent(studentId, courseId);
			break;
		case 3:
			printf("Enter student ID to search: ");
			scanf("%d", &studentId);
			searchStudent(studentId);
			break;
		case 4:
			printf("Exiting. Have a great day!\n");
			return 0;
		default:
			printf("\n");
		}
	}
}