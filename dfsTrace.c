#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfsTrace.h"

/*Scc*/
Stack * dfsSweep(IntList * adjVs, int n) {
        int * color, * disTime, * finTime, * parent;
        int time = 0;

        /*initialize arrays*/
        color = initColor(n);
        disTime = initDiscoverTime(n);
        finTime = initFinishTime(n);
        parent = initParent(n);
        Stack * stack = initStack();
        

        /*recursively call DFS*/
        int i;
        for (i = 1; i <= n; ++i)
                if (color[i] == WHITE)
                        time = dfsTrace(adjVs, i, color, disTime, finTime, parent, stack, time);

        /*print out the results*/
        printArrays(n, disTime, finTime, parent);

        return stack;
}
       
int dfsTrace(IntList * adjVs, int v, int * color, int * disTime, int * finTime, int * parent, Stack * fStack, int time) {
        int w;
        IntList remAdj;

        color[v] = GRAY;
        time++;
        disTime[v] = time;

        remAdj = adjVs[v];
        while(remAdj != intNil) {
                w = intFirst(remAdj);
                if (color[w] == WHITE) {
                        parent[w] = v;
                        time = dfsTrace(adjVs, w, color, disTime, finTime, parent, fStack, time);
                }

                remAdj = intRest(remAdj);
        }

        time++;
        finTime[v] = time;
        color[v] = BLACK;

        /*push vertex v into stack*/
        pushStack(fStack, v);


        return time;
}


int * initColor(int num) {
        int * color = (int *)malloc((num+1)*sizeof(int));
        for(int i = 0; i <= num; ++i)
                color[i] = WHITE;

        return color;
}

int * initFinishTime(int num) {
        int * finTime = (int *)malloc((num+1)*sizeof(int));
        for(int i = 0; i <= num; ++i)
                finTime[i] = 0;

        return finTime;
}

int * initDiscoverTime(int num) {
        int * disTime = (int *)malloc((num+1)*sizeof(int));
        for(int i = 0; i <= num; ++i)
                disTime[i] = 0;
        return disTime;
}



int * initParent(int num) {
        int * parent = (int *)malloc((num+1)*sizeof(int));
        for (int i = 0; i <= num; ++i)
                parent[i] = -1;

        return parent;
}

void printArrays(int n, int * disTime, int * finTime, int * parent) {
        printf("\nArrays\n");
        printf("vertex\t       parent\t       disTime\t       finTime\n");
        for(int i = 1; i <= n; ++i) {
                printf(" %d\t\t  %d\t\t  %d\t\t %d\n", i, disTime[i], finTime[i], parent[i]);
        }
        printf(" ");

}
