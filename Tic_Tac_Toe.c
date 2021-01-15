#include<stdio.h>

void InitializeBoard(int x1, int x2, char board[][x2]);

void PrintBoard(int x1, int x2, char board[][x2]);

void CreateBoard( int x1, int x2, char board[][x2]);

int IsValidBoard( int x1, int x2, char board[][x2]);

void ListWinningCells( int x1, int x2, char board[][x2]);

char WhoIsTheWinner( int x1, int x2, char board[][x2]);

char Checker(char array[],int size);

/**/

void InitializeBoard(int x1, int x2, char board[][x2])
{
    int c = 1;
    for(int i = 0; i < x1; i++){
        for(int j = 0; j< x2; j++){
            board[i][j] = c + '0';
            c++;
        }
    }
}
void PrintBoard(int x1, int x2, char board[][x2])
{
    for(int i = 0;i< x1;i++)
    {
        for(int j= 0;j < x2;j++)
        {
            printf("         ");
            if(j < x2-1)
                printf("|");
            else
                printf("\n");
        }
        for(int j = 0;j < x2;j++)
        {
            printf("    %c    ",board[i][j]);
            if( j < (x2-1))
            {
                printf("|");
            }
            else
            {
                printf("\n");
            }
        }

        if( i< (x1-1))
        {
            for(int j = 0;j < x2;j++)
            {
                printf("_________");
                if(j < x2-1)
                    printf("|");
                else
                    printf("\n");
            }
        }
        else{
            for(int j= 0;j < x2;j++)
            {
                printf("         ");
                if(j < x2-1)
                    printf("|");
                else
                    printf("\n");
            }
        }
    }
}


void CreateBoard ( int x1, int x2, char board[][x2]){

    int cell = 0;
    do{
        int TotalCells = x1 * x2;
        char value ='\0';
        do{
            printf("Enter the number of the cell where you want to insert X or O or enter -1 to exit\n");
            scanf("%d", &cell);
            if((cell > TotalCells || cell <= 0) && (cell != -1))
                PrintBoard(x1,x2, board);
        }while((cell > TotalCells || cell <= 0) && (cell != -1));

        if(cell != -1)
        {
            while(value != 'X' && value != 'O')
            {
                printf("Type X or O\n");
                scanf(" %c", &value);
                if((value != 'X' && value != 'O'))
                    PrintBoard(x1,x2, board);
            }
            for(int i = 0 ;i < x1;i++)
            {
                for(int j = 0;j < x2;j++)
                {
                    if(board[i][j] == (cell + '0'))
                    {
                        board[i][j] = value;
                    }
                }
            }

            PrintBoard( x1, x2, board);
        }
    }while(cell != -1);
}

int IsValidBoard( int x1, int x2, char board[][x2])
{
    int x = 0, o = 0;
    for(int i = 0;i < x1;i++)
    {
        for(int j = 0;j < x2;j++)
        {
            if(board[i][j] == 'X')
                x++;
            if(board[i][j] == 'O')
                o++;
        }
    }

    if((x-o) == 0 || (x - o) == 1 || (o - x) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ListWinningCells( int x1, int x2, char board[][x2])
{
    int counter = 0;
    char x = 'X';
    char o = 'O';
    if(IsValidBoard(x1,x2,board))
    {
        for(int i = 0;i < x1;i++)
        {
            char HorXwin = '0', VerXwin = '0', HorOwin = '0', VerOwin = '0';
            int HorXcount = 0, VerXcount = 0;
            int HorOcount = 0, VerOcount = 0;
            int HorVacant = 0, VerVacant = 0;
            for(int j = 0;j < x2;j++)
            {
                if(board[i][j] == x)
                {
                    HorXcount++;
                }
                if(board[j][i] == x)
                {
                    VerXcount++;
                }
                if(board[i][j] == o)
                {
                    HorOcount++;
                }
                if(board[j][i] == o)
                {
                    VerOcount++;
                }
                if(board[i][j] != x && board[i][j] != o)
                {
                    HorXwin = board[i][j];
                    HorOwin = board[i][j];
                    HorVacant++;
                }
                if(board[j][i] != x && board[j][i] != o)
                {
                    VerXwin = board[j][i];
                    VerOwin = board[j][i];
                    VerVacant++;
                }
            }

            if(HorXcount == 2 && HorVacant == 1)
            {
                printf("Cell # %c is a winning cell for player X\n", HorXwin);
                counter++;
            }
            if(VerXcount == 2  && VerVacant == 1)
            {
                printf("Cell # %c is a winning cell for player X\n", VerXwin);
                counter++;
            }
            if(HorOcount == 2 && HorVacant == 1)
            {
                printf("Cell # %c is a winning cell for player O\n", HorOwin);
                counter++;
            }
            if(VerOcount == 2 && VerVacant == 1)
            {
                printf("Cell # %c is a winning cell for player O\n", VerOwin);
                counter++;
            }
        }

        if(board[0][0] == board[1][1] && board[2][2] != x && board[2][2] != o)
        {
            printf("Cell # %c is a winning cell for Player %c\n", board[2][2], board[0][0]);
            counter++;
        }
        if(board[0][0] == board[2][2] && board[1][1] != x && board[1][1] != o)
        {
            printf("Cell # %c is a winning cell for Player %c\n", board[1][1], board[0][0]);
            counter++;
        }
        if(board[0][2] == board[1][1] && board[2][0] != x && board[2][0] != o)
        {
            printf("Cell # %c is a winning cell for Player %c\n", board[2][0], board[0][2]);
            counter++;
        }
        if(board[0][2] == board[2][0] && board[1][1] != x && board[1][1] != o)
        {
            printf("Cell # %c is a winning cell for Player %c\n", board[1][1], board[0][2]);
            counter++;
        }
        if(board[1][1] == board[2][2] && board[0][0] != x && board[0][0] != o)
        {
            printf("Cell # %c is a winning cell for Player %c\n", board[0][0], board[1][1]);
            counter++;
        }
        if(board[1][1] == board[2][0] && board[0][2] != x && board[0][2] != o)
        {
            printf("Cell # %c is a winning cell for Player %c\n", board[0][2], board[1][1]);
            counter++;
        }

    }
    if(counter == 0)
    {
        printf("No winning cells for player X or O\n");
    }
}



char WhoIsTheWinner( int x1, int x2, char board[][x2])
{
    char b;
    char a[3];

    a[0] = board[0][0], a[1] = board[0][1], a[2] = board[0][2];
    b = Checker(a, x2);

    if(b == 'D'){
        a[0] = board[1][0], a[1] = board[1][1], a[2] = board[1][2];
        b = Checker(a,3);
    }

    if(b == 'D')
    {
        a[0] = board[2][0], a[1] = board[2][1], a[2] = board[2][2];
        b = Checker(a,3);
    }
    if(b == 'D')
    {
        a[0] = board[0][0], a[1] = board[1][0], a[2] = board[2][0];
        b = Checker(a, 3);
    }

    if(b == 'D')
    {
        a[0] = board[0][1], a[1] = board[1][1], a[2] = board[2][1];
        b = Checker(a, 3);
    }

    if(b == 'D')
    {
        a[0] = board[0][2], a[1] = board[1][2], a[2] = board[2][2];
        b = Checker(a, 3);
    }

    if(b == 'D')
    {
        a[0] = board[0][0], a[1] = board[1][1], a[2] = board[2][2];
        b = Checker(a, 3);
    }

    if(b == 'D')
    {
        a[0] = board[2][0], a[1] = board[1][1], a[2] = board[0][2];
        b = Checker(a, 3);
    }

    return b;
}

char Checker(char array[],int size)
{
    if(array[size - 2] == array[size - 1])
    {
        if(size == 2)
        {
            return array[0];
        }
        else
        {
            return Checker(array, size - 1);
        }
    }
    else
    {
        return 'D';
    }
}

int main(void)
{
    int a = 3,b = 3;
    char board[a][b];
    char menu;
    char winner;
    int checker;
    InitializeBoard(a, b, board);
    do{
        printf("1. to print the tic-tac-toe board\n");
        printf("2. to create the tic-tac-toe board with some X and O cells\n");
        printf("3. to test if a tic-tac-toe board is valid or invalid board\n");
        printf("4. to predict winning cell for player X or O\n");
        printf("5. to check winner\n");
        printf("6. to Exit\n");

        scanf(" %c",&menu);


        switch(menu){
            case '1':

                PrintBoard(a, b, board);
                printf("\n");
                break;

            case '2':

                PrintBoard(a, b, board);
                CreateBoard(a, b, board);
                break;

            case '3':

                checker = IsValidBoard(a, b, board);
                PrintBoard(a, b, board);
                if(checker == 1){
                    printf("Valid Board\n");
                } else {
                    printf("Invalid Board\n");
                }
                break;

                
            case '4':
                
                ListWinningCells( a, b, board);
                break;
                

            case '5':
                
                winner = WhoIsTheWinner(a,b,board);
                if(winner == 'D'){
                    printf("It's a draw\n");
                }
                else{
                    printf(" %c is the winner\n", winner);
                }
                break;


            case '6':
                

                return 0;

                
            default:

                printf("Wrong input\n");
                break;
        }

    }while(menu != '6');
}
