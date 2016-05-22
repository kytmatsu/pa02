// This is the functionality of the program.
// kytmatsu
// Kyle Matsumoto
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "intList.h"

#define maxSIZE 1024


IntList * transposeGraph(IntList *, int);
int hasCycle(IntList *, int);
int hasCycleLen(IntList *, int, int, IntList);



typedef struct {
	int from;
	int to;
	double weight;
} Edge;

//This is a file from the Professor that I modified to check if the
//the the number was greater than the size we were given.
//It combines two of the files we were given.
//PreConditions: A char pointer, and Intlist, and an int that is the size of the array
//PostConditions:It alters the intlist.
void parseEdges(char *line, IntList *aVert, int arrSize) {
	Edge newE;
	int numFields;
	numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
	if (numFields < 2 || numFields >= 3) {
		printf("Bad Edge: %s\n", line);
		exit(1);
	}

	if (newE.from > arrSize) {
		printf("Number exceeds n, Number is too large: %s\n", line);
		newE.from = 0;
		newE.to = 0;
	}

	if (numFields == 2) {
		newE.weight = 0.0;
	}
	aVert[newE.from] = intCons(newE.to, aVert[newE.from]);
}

int main(int argc, char* argv[]) {
	FILE* input;
	if (argc > 1) {
		if(!strcmp(argv[1],"-")) {
			input = stdin;
		}
		else{
			//Open File
			char *myFile = argv[1];
			input = fopen(myFile, "r");
			if (input == NULL) {
				fprintf(stderr, "ERROR: FILE DOES NOT EXIST\n");
				return(0);
			}
		}
	}
	else{
		input = stdin;
	}

	//Get the size of our index from the first line
	char line[maxSIZE];
	int index;
	fgets(line, sizeof(line), input); //Read in first line
	sscanf(line, "%d %*s",  &index); //get the number n of index from first line

	//Create the IntList that will have the linked list data in it at the size of the index
	IntList *adjList = (IntList*)calloc(index+1,sizeof(IntList));
	int start = 1;
	for(start = 1; start <= index; start++) {
		adjList[start] = NULL;
	}
	// variable to count m
	int countIt = 0;
	//Read each line until the end of file and save it
	while (fgets(line, sizeof(line), input)) {
		countIt++;
		parseEdges(line, adjList, index);
	}
	// We've gotten the data now we print it.
	printf("n = %d\n", index);
	printf("m = %d\n", countIt);
	for(int count = 1; count <= index; count++) {
		bool start = true;
		IntList t = adjList[count];
		printf("%d  ", count);
		if(!t) {
			// If theres nothing in the file for that slot print a Null
			printf("Null\n");
		}
		// Start printing out the graph. If more than one entry it
		// will print out a comma to separate them
		while(t) {
			if(start == true) {
				printf("[");
			} else {
				printf(", ");
			}
			printf("%d", intFirst(t));
			t = intRest(t);
			start = false;
		}
		if(start == false) {
			printf("]\n");
		}
	}
	int c;
	c = hasCycle(adjList, index);
	if (c)
		printf("There is a cycle that exists.\n");
	else
		printf("There is no cycle.\n");

	printf("Transposed graph 1 time.\n");

	IntList * tGraph = transposeGraph(adjList, index);
	for(int y = 1; y <= index; y++) {
		start = true;
		IntList t1 = tGraph[y];
		printf("%d  ", y);
		if(!t1){
			printf("Null\n");
		}
		while(t1) {
			if(start == true) {
				printf("[");
			} else {
				printf(", ");
			}
			printf("%d", intFirst(t1));
			t1 = intRest(t1);
			start = false;
		}
		if(start == false) {
			printf("]\n");
		}
	}
	c = hasCycle(tGraph, index);
	if (c)
		printf("There is a cycle that exists.\n");
	else
		printf("There is no cycle.\n");

	printf("Transposed graph 2 times.\n"); // the second transposed graph

	IntList * t2Graph = transposeGraph(tGraph, index);
	for(int y = 1; y <= index; y++) {
		start = true;
		IntList t2 = t2Graph[y];
		printf("%d  ", y);
		if(!t2){
			printf("Null\n");
		}
		while(t2) {
			if(start == true) {
				printf("[");
			} else {
				printf(", ");
			}
			printf("%d", intFirst(t2));
			t2 = intRest(t2);
			start = false;
		}
		if(start == false) {
			printf("]\n");
		}
	}
	c = hasCycle(t2Graph, index);
	if (c)
		printf("There is a cycle that exists.\n");
	else
		printf("There is no cycle.\n");

	printf("Transposed graph 3 times.\n"); // the third transposed graph

	IntList * t3Graph = transposeGraph(t2Graph, index);
	for(int y = 1; y <= index; y++) {
		start = true;
		IntList t3 = t3Graph[y];
		printf("%d  ", y);
		if(!t3){
			printf("Null\n");
		}
		while(t3) {
			if(start == true) {
				printf("[");
			} else {
				printf(", ");
			}
			printf("%d", intFirst(t3));
			t3 = intRest(t3);
			start = false;
		}
		if(start == false) {
			printf("]\n");
		}
	}

	c = hasCycle(t3Graph, index);
	if (c)
		printf("There is a cycle that exists.\n");
	else
		printf("There is no cycle.\n");
	fclose(input);
	return 0;
}
