#include <stdio.h>
#include "my_mat.h"


int main()
{
    char chose;
    int stop = 1;
    do {
        scanf("%c" , &chose );
        if(chose == 'A'){
            scanMatrix();
        }else if(chose == 'B') {
            int p1, p2;
            scanf("%d%d", &p1 ,&p2);
            isExistsPath(p1, p2);
        }else if (chose == 'C') {
            int V1, V2;
            scanf("%d%d", &V1 ,&V2);
            shortestPath(V1, V2);
        }else if (chose == 'D') {
            stop = 0;
        }
    }while(stop != 0);
    return 0;
}
