#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100

// Structure to represent an event
struct Event
{
	int id;
	char description[100];
	char startTime[10]; // Format: HH:MM
};

// Global array to store events
struct Event eventList[MAX_EVENTS];
int numEvents = 0;

// Stack for undo/redo
struct Event undoStack[MAX_EVENTS];
int undoTop = -1;

// Function to add a new event
void addEvent(int id, const char *description, const char *startTime)
{
	if (numEvents >= MAX_EVENTS)
	{
		printf("Event list is full. Cannot add more events.\n");
		return;
	}

	eventList[numEvents].id = id;
	strcpy(eventList[numEvents].description, description);
	strcpy(eventList[numEvents].startTime, startTime);
	numEvents++;
	printf("Event added successfully!\n");
}

// Function to delete an event
void deleteEvent(int id)
{
	for (int i = 0; i < numEvents; i++)
	{
		if (eventList[i].id == id)
		{
			// Shift remaining events to fill the gap
			for (int j = i; j < numEvents - 1; j++)
			{
				eventList[j] = eventList[j + 1];
			}
			numEvents--;
			printf("Event deleted successfully!\n");
			return;
		}
	}
	printf("Event not found.\n");
}

// Function to undo the last action
void undo()
{
	if (undoTop >= 0)
	{
		eventList[numEvents++] = undoStack[undoTop--];
		printf("Undo successful.\n");
	}
	else
	{
		printf("Nothing to undo.\n");
	}
}

int compareStartTime(const void *a, const void *b)
{
	return strcmp(((struct Event *)a)->startTime, ((struct Event *)b)->startTime);
}

// Function to sort events by start time
void sortEvents()
{
	qsort(eventList, numEvents, sizeof(struct Event), compareStartTime);
	printf("Events sorted by start time.\n");
}

int main()
{
	int choice, eventId;
	char eventDesc[100], eventTime[10];

	while (1)
	{
		printf("\nEvent Scheduling System Menu:\n");
		printf("1. Add event\n");
		printf("2. Delete event\n");
		printf("3. Undo\n");
		printf("4. Sort events by start time\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter event ID: ");
			scanf("%d", &eventId);
			printf("Enter event description: ");
			scanf(" %[^\n]", eventDesc);
			printf("Enter event start time (HH:MM): ");
			scanf("%s", eventTime);
			addEvent(eventId, eventDesc, eventTime);
			break;
		case 2:
			printf("Enter event ID to delete: ");
			scanf("%d", &eventId);
			deleteEvent(eventId);
			break;
		case 3:
			undo();
			break;
		case 4:
			sortEvents();
			break;
		case 5:
			printf("Exiting. Have a productive day!\n");
			return 0;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}
