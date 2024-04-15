#include <stdio.h>
#include <omp.h>

typedef struct WayState {
    int weight;
    int i;
    int j;
} WayState;

int calculateEulerWay(int edges[7][4], WayState  way[], int nEdges) {
    int i = 0;
    int j = 0;

    int y = 0;
    int x = 0;

    WayState wayState = {.weight = 0, .i = i, .j = edges[i][j]};
    way[0] = wayState;
    
    #pragma omp parallel shared(way)
    #pragma omp for
        for(int iEdge = 1; iEdge < nEdges; iEdge++) {
            y = edges[i][j];
            x = 0;
            for(int index = 0; index < 4; index++) {
                if(edges[y][index] == i) {
                    x = index;
                }
            }
            
            if(edges[y][x + 1] == -1) {
                if(y + 1 < 7) {
                    i = y + 1;
                    j = 0;

                    WayState newWayState = {.weight = 0, .i = i, .j = edges[i][j]};
                    way[iEdge] = newWayState;
                } else {
                    i = y;
                    j = x;
                    WayState wayState = {.weight = 0, .i = i, .j = edges[i][j]};
                    way[iEdge] = wayState;
                }
            } else if(x >= 3) {
                i = y;
                j = x;
                WayState wayState = {.weight = 0, .i = i, .j = edges[i][j]};
                way[iEdge] = wayState;
            } else {
                i = y;
                j = x + 1;

                WayState wayState = {.weight = 0, .i = i, .j = edges[i][j]};
                
                way[iEdge] = wayState;
            }
        }

    return 0;
}


int main() {
    int nEdges = 12;
    int edges[7][4] = {
        {3, -1, -1, -1}, 
        {3, -1, -1, -1}, 
        {5, -1, -1, -1}, 
        {0, 1, 5, -1}, 
        {5, -1, -1, -1}, 
        {2, 3, 4, 6},
        {5, -1, -1, -1}
    }; 
    
    WayState way[12];

    calculateEulerWay(edges, way, nEdges);
    
    for(int i = 0; i < nEdges; i++) {
        printf("(%d, %d)\n", way[i].i, way[i].j);
    }


    return 0;
}