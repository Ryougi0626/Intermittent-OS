#include <msp430.h>


char img_table[320][180] = {0};
char temp[9] = {0};


void meanvalue_filter(){
    //318 178
    //106 60
    int i, j, k, l;
    int count = 0;

    for(i = 1; i < 319; i++){
        for(j = 1; j < 179; j++){
            for(k = 0; k < 3; k++){
                for(l = 0; l < 3; l++){
                    temp[3*k+l] = img_table[i-1+k][j-1+l];
                    img_table[i][j] = sort(temp);
                }
            }
        }
    }
}

char sort(char *arr){
    char temp;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr[4];
}












