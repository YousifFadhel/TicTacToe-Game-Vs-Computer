#include <stdio.h>

// 2d arrays are arrays where each element is an entire array
// useful if you need a matrix, grid, or table of data

int main()
{
    // int numbers[2][3] = { {1, 2 ,3},
    //                       {4, 5, 6}
    //                     };
    
    
    
     // declaring a 2darray
    // max size of 3 in each
    // second [] is NEEDED, states how many elements in each array , number of columns
    // first [] not need, sets max amount of arrays, number of rows


    int numbers[2][3];

    numbers[0][0] = 1;
    numbers[0][1] = 2;
    numbers[0][2] = 3;
    numbers[1][0] = 4;
    numbers[1][1] = 5;
    numbers[1][2] = 6;

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    // to get the number of rows pass in the entire size of the 2d array and divide it by the size of 1 of ours rows


    int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);
    // to get number of columns take size of the first row / the size of one of the elements found in the first row

    printf("rows: %d\n", rows);
    printf("rows: %d\n", columns);


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", numbers[i][j]);
        }

        printf("\n");

    }


    return 0;
}

// This is the board logic that will be used for the tic tac toe game.