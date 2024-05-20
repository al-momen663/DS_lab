// A C Program to demonstrate adjacency list
// representation of graphs
// Detail https://www.geeksforgeeks.org/graph-and-its-representations/
#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode
{
	int dest; // Use int instead of char for indexing
	struct AdjListNode *next;
};

// A structure to represent an adjacency list
struct AdjList
{
	struct AdjListNode *head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
	int V;
	struct AdjList *array;
};

// A utility function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest)
{
	struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph *createGraph(int V)
{
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->V = V;

	// Create an array of adjacency lists. Size of array will be V
	graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

	// Initialize each adjacency list as empty by making head as NULL
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Converts a character vertex to an index (0-based)
int charToIndex(char c)
{
	return c - 'a';
}

// Adds an edge to an undirected graph
void addEdge(struct Graph *graph, char src, char dest)
{
	int srcIndex = charToIndex(src);
	int destIndex = charToIndex(dest);

	// Add an edge from src to dest. A new node is
	// added to the adjacency list of src. The node
	// is added at the beginning
	struct AdjListNode *newNode = newAdjListNode(destIndex);
	newNode->next = graph->array[srcIndex].head;
	graph->array[srcIndex].head = newNode;

	// Since graph is undirected, add an edge from dest to src also
	newNode = newAdjListNode(srcIndex);
	newNode->next = graph->array[destIndex].head;
	graph->array[destIndex].head = newNode;
}

// A utility function to print the adjacency list representation of graph
void printGraph(struct Graph *graph)
{
	for (int v = 0; v < graph->V; ++v)
	{
		struct AdjListNode *pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %c\n head ", v + 'a');
		while (pCrawl)
		{
			printf("-> %c", pCrawl->dest + 'a');
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

// Driver program to test above functions
int main()
{
	// create the graph given in above figure
	int V = 5; // Total no of vertices
	struct Graph *graph = createGraph(V);
	addEdge(graph, 'a', 'b');
	addEdge(graph, 'a', 'e');
	addEdge(graph, 'b', 'c');
	addEdge(graph, 'b', 'd');
	addEdge(graph, 'b', 'e');
	addEdge(graph, 'c', 'd');
	addEdge(graph, 'd', 'e');

	// print the adjacency list representation of the above graph
	printGraph(graph);

	return 0;
}
