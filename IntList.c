// This is the code for transposing and finding cycles as well as
// all of the other stuff for intLists.
// kytmatsu
// Kyle Matsumoto
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "intList.h"
 
const IntList intNil = NULL;

struct IntListNode {
	int node;
	IntList next;
};

int intFirst(IntList oldL) {
	return oldL->node;
}


IntList intRest(IntList oldL) {
	return oldL->next;
}


IntList intCons(int newE, IntList oldL) {
        IntList x = (IntList)calloc(1,sizeof(IntList));
        x->node = newE;
	x->next = oldL;
	return x;
}
// This is the program that transposes any given graph.
// Preconditions: an Intlist to transpose, and an int n for the size of the graph.
// Postconditions: this will return a new graph that is a transpose of the given graph.
IntList * transposeGraph(IntList* origGraph, int n) {

	IntList *tGraph = (IntList*)calloc(n+1,sizeof(IntList)); // make a graph of size n
	int edge;
	for(int x = 1; x <= n; x++) // transpose the graph
	{
		IntList copy = origGraph[x];
		while(copy)
		{
            edge = intFirst(copy);
			tGraph[edge] = intCons(x, tGraph[edge]);
			copy = intRest(copy);
		}
	}
	return tGraph; // return the transposed graph

}
// This is the helper to the program that goes through the graph to see if it has a cycle. It uses recursion.
// Preconditions: We need an Intlist, the arraysize, how far you've gone, and our node.
// Postconditions: This will return either a 0 or 1 based on whether we have found a cycle or not.
int hasCycleLen(IntList* origGraph, int n, int sofar, int v) {
	if(sofar >= n)
	{
        printf("Greater than n.\n");
		return 1;
	}

	int node;
	IntList wrap = origGraph[v];
	int x = 0;

	while((wrap) && (x == 0))
	{
        	node = intFirst(wrap);
        	printf("The current node is: %d\n", node);
        	x = hasCycleLen(origGraph, n, sofar+1, node);
			wrap = intRest(wrap);
	}

	if(x == 1)
		return 1; //Has found a cycle

	return 0; //Has not found a cycle

}
// This is the program that goes through the graph to see if it has a cycle.
// Preconditions: We need an Intlist graph and the max size of that graph.
// Postconditions: It returns either 1 or 0 depending on if we found a cycle or not.
int hasCycle(IntList* origGraph, int n) {
	int x;
	int y = 0;
	for(x = 1; x <= n; x++) { // find the node and then see if it
	//	printf("%d: ", x);    // has a cycle or not
        y = hasCycleLen(origGraph, n, 0, x);
		if(y == 1)
		    return 1; // we found a cycle
	}
	return 0; // we didn't find a cycle
}



