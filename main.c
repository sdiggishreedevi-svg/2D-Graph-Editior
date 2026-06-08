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
void addEdgeHorizontal(int row, int col1, int col2)
{
    for(int i = col1; i <= col2; i++)
    {
        canvas[row][i] = '-';
    }
}

int main()
{
    int choice;

    clearCanvas();

    while(1)
    {
       printf("\n--- 2D GRAPH EDITOR ---\n");
printf("1. Add Vertex\n");
printf("2. Add Horizontal Edge\n");
printf("3. Display Graph\n");
printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

       if(choice == 1)
{
    int n;

    printf("Number of Vertices: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        int row,col;

        printf("Vertex %d Row: ", i + 1);
        scanf("%d",&row);

        printf("Vertex %d Column: ", i + 1);
        scanf("%d",&col);

        addVertex(row,col);
    }
} 
    else if(choice == 2)
{
    int row,col1,col2;

    printf("Enter Row: ");
    scanf("%d",&row);

    printf("Enter Start Column: ");
    scanf("%d",&col1);

    printf("Enter End Column: ");
    scanf("%d",&col2);

    addEdge(row,col1,row,col2);
}

else if(choice == 3)
{
    displayCanvas();
}

else if(choice == 4)
{
    break;
}
       
    }

    return 0;
}
