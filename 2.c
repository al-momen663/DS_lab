/*Imagine you are developing a simple music playlist application. Implement a C program using bubble sort to organize a playlist of songs
 based on their duration. Also, the application must be able to find out a song based on the duration.*/
#include <stdio.h>

void swap(int *song, int i, int j)
{
	int temp = song[i];
	song[i] = song[j];
	song[j] = temp;
}

void SongSort(int song[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (song[j] > song[j + 1])
			{
				swap(song, j, j + 1);
			}
		}
	}
}

void printSong(int song[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", song[i]);
	}
	printf("\n");
}
int main()
{
	int song[] = {2, 3, 5, 8, 9, 10};
	int size = sizeof(song) / sizeof(song[0]);
	SongSort(song, size);
	printf("Sorted playlist (duration in seconds): ");
	printSong(song, size);

	int Duration;

	printf("Enter duration size to search: ");
	scanf("%d", &Duration);
	int found = 0;
	for (int i = 0; i < size; i++)
	{
		if (song[i] == Duration)
		{
			printf("Found a song with duration %d seconds.\n", Duration);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		printf("No song found with duration %d seconds.\n", Duration);
	}
}