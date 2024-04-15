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
    
   // #pragma omp parallel shared(way)
    WayState wayState = {.weight = 0, .i = i, .j = edges[i][j]};
    way[0] = wayState;
   //#pragma omp for
    for(int iEdge = 1; iEdge < nEdges; iEdge++) {
        y = edges[i][j];
        x = 0;
        for(int index = 0; index < 4; index++) {
            if(edges[y][index] == y) {
                x = index;
            }
        }
        
        if(x >= 3) {
            i = y;
            j = x;
            printf("%d", edges[i][j]);
            WayState wayState = {.weight = 0, .i = i, .j = edges[i][j]};
            way[i] = wayState;
        } else {
            i = y;
            
            x = x + 1;
            j = x;

            printf("%d", edges[i][j]);
            WayState wayState = {.weight = 0, .i = i, .j = edges[i][j]};
            
            way[i] = wayState;
        }
    }
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