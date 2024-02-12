#include<stdio.h>
#include<math.h>
#define MAX_WEIGHET 20
#define MAX_ITEM 5
#define MAX(a,b) (((a)>(b))?(a):(b))


int knapSack(int weights[],int values[],int selected_bool[]){

    int values_matrix[MAX_ITEM+1][MAX_WEIGHET+1];
    for(int i = 0; i<=MAX_ITEM; i++) {
       for(int j = 0; j<=MAX_WEIGHET; j++) {
          if(i == 0 || j == 0) {
                values_matrix[i][j] = 0;
          } else if(weights[i-1] <= j) {
                values_matrix[i][j] = MAX(values[i-1] + values_matrix[i-1][j-weights[i-1]], values_matrix[i-1][j]);

                
          } else {
                values_matrix[i][j] = values_matrix[i-1][j];
                
          }
       }
    }

    int res = values_matrix[MAX_ITEM][MAX_WEIGHET];
    int w = MAX_WEIGHET;
    for(int i=MAX_ITEM; i>0 && res>0; i--){
        if (res == values_matrix[i-1][w])
        {
            continue;
        }
        else{    
            res = res - values[i-1];
            w = w - weights[i-1];
            selected_bool[i-1]=1;            
        }        
    } 

    return values_matrix[MAX_ITEM][MAX_WEIGHET];
}


int main() {
    char result[MAX_ITEM];
    int weights[MAX_ITEM];
    int values[MAX_ITEM];
    int selected_bool[MAX_ITEM] = {0}; 

    char item;
    int weight, value;
    for (int i = 0; i < MAX_ITEM; i++) {
        scanf(" %c %d %d", &item, &value, &weight);
        result[i] = item;
        weights[i] = weight;
        values[i] = value;
    }

    int maxProfit = knapSack(weights, values, selected_bool);
    int counter = 0;
    for (int i = 0; i < MAX_ITEM; i++) {
        if (selected_bool[i] == 1) {
            counter ++;
        }
    }
    
    

    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items: ");
    for (int i = 0; i < MAX_ITEM; i++) {
        if (selected_bool[i] == 1 && counter != 1) {
            printf("%c ", result[i]); 
            counter --;
        }
        else if(selected_bool[i] == 1 && counter == 1){
            printf("%c", result[i]); 

        }
    }
   //printf("\n");

    return 0;
}


