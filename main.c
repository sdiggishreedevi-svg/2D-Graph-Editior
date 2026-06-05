#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void clearCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void addVertex(int row, int col)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        canvas[row][col] = 'O';
    }
}
void addEdge(int row1, int col1, int row2, int col2)
{
    if(row1 == row2)
    {
        for(int i = col1; i <= col2; i++)
            canvas[row1][i] = '-';
    }
}


int main()
{
    int row, col;

    clearCanvas();

    printf("Enter row (0-19): ");
    scanf("%d", &row);

    printf("Enter column (0-39): ");
    scanf("%d", &col);

    addVertex(row, col);
    addEdge(5,10,5,20);

    displayCanvas();

    return 0;
}