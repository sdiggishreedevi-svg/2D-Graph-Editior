#include <stdio.h>
#include<stdlib.h>
#include<math.h>

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
void addVerticalEdge(int col, int row1, int row2)
{
    for(int i = row1; i <= row2; i++)
    {
        canvas[i][col] = '|';
    }
}
void drawLine(int row1, int col1, int row2, int col2)
{
    int dx = col2 - col1;
    int dy = row2 - row1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = col1;
    float y = row1;

    for(int i = 0; i <= steps; i++)
    {
        if((int)y >= 0 && (int)y < ROWS &&
           (int)x >= 0 && (int)x < COLS)
        {
            canvas[(int)y][(int)x] = '*';
        }

        x += xInc;
        y += yInc;
    }
}

void drawRectangle(int row1, int col1, int row2, int col2)
{
    addEdgeHorizontal(row1, col1, col2);

    addEdgeHorizontal(row2, col1, col2);

    addVerticalEdge(col1, row1, row2);

    addVerticalEdge(col2, row1, row2);
}
void drawTriangle(int row1, int col1,
                  int row2, int col2,
                  int row3, int col3)
{
    drawLine(row1, col1, row2, col2);

    drawLine(row2, col2, row3, col3);

    drawLine(row3, col3, row1, col1);
}
void drawCircle(int centerRow, int centerCol, int radius)
{
    for(int angle = 0; angle < 360; angle++)
    {
        double rad = angle * 3.14159 / 180.0;

        int row = centerRow + (int)(radius * sin(rad));
        int col = centerCol + (int)(radius * cos(rad));

        if(row >= 0 && row < ROWS &&
           col >= 0 && col < COLS)
        {
            canvas[row][col] = '*';
        }
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
printf("3. Add Vertical Edge\n");
printf("4. Draw Rectangle\n");
printf("5. Draw Triangle\n");
printf("6. Draw Circle\n");
printf("7. Display Graph\n");
printf("8. Exit\n");

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
    int col,row1,row2;

    printf("Enter Column: ");
    scanf("%d",&col);

    printf("Enter Start Row: ");
    scanf("%d",&row1);

    printf("Enter End Row: ");
    scanf("%d",&row2);

    addVerticalEdge(col,row1,row2);
}

else if(choice == 4)
{
    int row1,col1,row2,col2;

    printf("Enter Top Row: ");
    scanf("%d",&row1);

    printf("Enter Left Column: ");
    scanf("%d",&col1);

    printf("Enter Bottom Row: ");
    scanf("%d",&row2);

    printf("Enter Right Column: ");
    scanf("%d",&col2);

    drawRectangle(row1,col1,row2,col2);
}

else if(choice == 5)
{
    int row1,col1,row2,col2,row3,col3;

    printf("Enter Row1 Column1: ");
    scanf("%d %d",&row1,&col1);

    printf("Enter Row2 Column2: ");
    scanf("%d %d",&row2,&col2);

    printf("Enter Row3 Column3: ");
    scanf("%d %d",&row3,&col3);

    drawTriangle(row1,col1,row2,col2,row3,col3);
}

else if(choice == 6)
{
    int row,col,radius;

    printf("Enter Center Row: ");
    scanf("%d",&row);

    printf("Enter Center Column: ");
    scanf("%d",&col);

    printf("Enter Radius: ");
    scanf("%d",&radius);

    drawCircle(row,col,radius);
}

else if(choice == 7)
{
    displayCanvas();
}

else if(choice == 8)
{
    break;
}
       
    }

    return 0;
}
