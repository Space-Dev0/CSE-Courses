#include<stdio.h>
#include<stdlib.h>

void print_board_input(char*chance,char arr[3][3],char player1_char,char player2_char,int d);
void check_board(char arr[3][3],char player1_char,char player2_char);

int main()
{
    int count;
    char arr[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char chance,player1_char,player2_char;
    
    printf("-------------- Welcome to Tic-Tac-Toe ! --------------\n");
    
    enter_symbol1:
    {
        printf("\nEnter Player 1 Symbol: ");
        scanf(" %c",&player1_char);
    }
    if (player1_char != 'x' && player1_char != 'o')
    {
        printf("\n## The player symbol should be x or o ##\n");
        goto enter_symbol1;
    }

    if (player1_char == 'x') player2_char = 'o';
    else player2_char = 'x';

    printf("\nPlayer 1 : %c\n",player1_char);
    printf("Player 2 : %c\n",player2_char);

    who_plays:
    {
        printf("\nWho plays first? Player 1 or Player 2: ");
        scanf(" %c",&chance);
    }
    if (chance != '1' && chance != '2')
    {
        printf("\n## Enter either 1 or 2 ##\n");
        goto who_plays;
    }
    system("clear");
    for ( count = 0; count < 9; count++)
    {
        print_board_input(&chance,arr,player1_char,player2_char,0);
        system("clear");
        if(count>=2)check_board(arr,player1_char,player2_char);
    }
    print_board_input(&chance,arr,player1_char,player2_char,1);
    printf("\n\n------------------- It's a Draw -------------------\n\n");
}

void print_board_input(char*chance,char arr[3][3],char player1_char,char player2_char,int d)
{
    int i,j,row,column;
    char player_char,column_temp;
    switch (*chance)
    {
    case '1':
        player_char = player1_char;
        *chance = '2';
        break;
    
    default:
        player_char = player2_char;
        *chance = '1';
        break;
    }

    printf("Player 1 : %c\n",player1_char);
    printf("Player 2 : %c\n",player2_char);

    printf("\nIts %c's Chance !!\n",player_char);    
    printf("                        A B C\n");
    for ( i = 0; i < 3; i++)
    {
        printf("                     %d ",i+1);
        for ( j = 0; j < 3; j++)
            printf("|%c",arr[i][j]);
        printf("|\n");
    }

    if(d==1) return;
    
    input_cell:
    {   
        printf("\nWhere do you want to place your %c: ",player_char);
        scanf(" %c%d",&column_temp,&row);
    }
    if (column_temp!='A' && column_temp!='B' && column_temp!='C' || row>3 || row<1)
    {
        printf("\n## Enter column in uppercase and row as a number. Example - A1 ##\n");
        goto input_cell;
    }
    row = row - 1;
    switch (column_temp)
    {
    case 'A':
        column = 0;
        break;
    case 'B':
        column = 1;
        break;
    case 'C':
        column = 2;
        break;
    default:
        break;
    }
    if (arr[row][column] != ' ')
    {
        printf("## That box is already filled ##");
        goto input_cell;
    }
    
    arr[row][column] = player_char;
}

void check_board(char arr[3][3],char player1_char,char player2_char)
{
    int i,j;
    char o = '1';
    for ( i = 0,j = 0; i < 3 ; i++,j++)
    {
        if (arr[i][j] == ' ')continue;
        if (arr[i][1] == arr[i][0] && arr[i][1] == arr[i][2])    
        {
            win:
            {
                print_board_input(&o,arr,player1_char,player2_char,1);
                if (arr[i][j] == player1_char)
                {
                    printf("\n\n------------------ Player 1 Won !! -------------------\n\n");
                    exit(0);
                }
                else
                {
                    printf("\n\n------------------ Player 2 Won !! -------------------\n\n");
                    exit(0);
                }
            }
        }
        else if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j])
            goto win;
        if (arr[1][1] == ' ')continue;
        else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]||arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
            {
                print_board_input(&o,arr,player1_char,player2_char,1);
                if (arr[1][1] == player1_char)
                {
                    printf("\n\n------------------ Player 1 Won !! -------------------\n\n");
                    exit(0);
                }
                else
                {
                    printf("\n\n------------------ Player 2 Won !! -------------------\n\n");
                    exit(0);
                }
            }
    }
}