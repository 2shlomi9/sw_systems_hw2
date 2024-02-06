#include<stdio.h>
#include<math.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
int matrix[sizeMat][sizeMat];



void scanMatrix(){

    for(int i = 0; i < sizeMat; i++)
    {
        for(int j = 0; j < sizeMat; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int k = 0; k<sizeMat; k++){

            for (int i = 0; i < sizeMat; i++) {
                if(i!=k) {
                    for (int j = 0; j < sizeMat; j++) {
                        if (j != k) {
                            if (matrix[i][k] != 0 && matrix[k][j] != 0 && i != j) {
                                if (matrix[i][j] == 0) {
                                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                                } else {
                                    matrix[i][j] = MIN(matrix[i][j], matrix[i][k] + matrix[k][j]);
                                }
                            }
                        }
                    }
                }
            }
    }


}

void shortestPath(int p1, int p2){
    if (matrix[p1][p2] == 0){
        printf( "-1\n");
    }else printf("%d\n",matrix[p1][p2]);
}

void isExistsPath(int v1, int v2){
    if(matrix[v1][v2]==0){
        printf("False\n");
    }else printf("True\n");
}