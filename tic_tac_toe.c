#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

struct myDataType
{

    int i;
    /// ch is the character either X or 0
    char ch;

}inputValue();

///a counts no. of game won by player X
int a;
///b counts no. of game won by player 0
int b;
///c counts no. of game draws between 2 players
int c;

void run();
int check(char sym[9],char ch,int count);
struct myDataType inputValue(char sym[9],int count);
void Display(char sym[9]);

void main()
{
    char reStart;
    again:
	run();
	///If the player want to play the game again he or she can press 1 to continue else press any key
	printf("\n If You Want To Play Again Press 1: \n Else Any:");
	scanf("%s",&reStart);
	if(reStart == '1')
    {
        system("cls");
        goto again;
    }
    else
    {
        a=0;
        b=0;
        c=0;
        exit(0);
    }
}
///This is the main loop which runs the program
void run()
{

    /// count variable counts the no. of inputs done in the game play
    int count = 0;
    struct myDataType info;
    char symbol[9] = {'1','2','3','4','5','6','7','8','9'};
    Display(symbol);
    again:
    info = inputValue(symbol,count);
    symbol[info.i] = info.ch;
    system("cls");
    Display(symbol);
    if(check(symbol,info.ch,count)==1)
    {

    }
    else
    {
        count++;
        goto again;
    }
}

int check(char sym[9],char ch,int count)
{
    int i;
    for(i = 0;i<=6; i+=3)//it's for row
    {
        if(sym[i] == ch && sym[i+1]==ch&&sym[i+2]==ch)
        {
            printf("\nThe Winner is : %c\n",ch);
            ///TO CHECK HOW MANY GAMES ARE WON BY X AND 0
            if(ch=='X')
            {
                a++;
                printf("\nNo. of game won by X = %d\n", a);
                printf("\nNo. of game won by 0 = %d\n", b);
            }
            else
            {
                b++;
                printf("No. of game won by X = %d\n", a);
                printf("No. of game won by 0 = %d\n", b);
            }
            return 1;
        }

    }
    for(i = 0;i<3; i++)///it's for column
    {
        if(sym[i]==ch && sym[i+3]==ch&&sym[i+6]==ch)
        {
            printf("\nThe Winner is : %c\n",ch);
            ///TO CHECK HOW MANY GAMES ARE WON BY X AND 0
            if(ch=='X')
            {
                a++;
                printf("\nNo. of game won by X = %d\n", a);
                printf("\nNo. of game won by 0 = %d\n", b);
            }
            else
            {
                b++;
                printf("No. of game won by X = %d\n", a);
                printf("No. of game won by 0 = %d\n", b);
            }
            return 1;
        }

    }
    ///To check for diagonal match
    if(sym[0]==ch && sym[4]==ch&&sym[8]==ch)
    {
        printf("\nThe Winner is : %c\n",ch);
       / //TO CHECK HOW MANY GAMES ARE WON BY X AND 0
        if(ch=='X')
        {
            a++;
            printf("\nNo. of game won by X = %d\n", a);
            printf("\nNo. of game won by 0 = %d\n", b);
        }
        else
        {
            b++;
            printf("No. of game won by X = %d\n", a);
            printf("No. of game won by 0 = %d\n", b);
        }
        return 1;

    }
    ///To check for diagonal match
    else if(sym[2]==ch && sym[4]==ch && sym[6]==ch)
    {
        printf("\nThe Winner is : %c\n",ch);
        ///TO CHECK HOW MANY GAMES ARE WON BY X AND 0
        if(ch=='X')
        {
            a++;
            printf("\nNo. of game won by X = %d\n", a);
            printf("\nNo. of game won by 0 = %d\n", b);

        }
        else
        {
            b++;
            printf("No. of game won by X = %d\n", a);
            printf("No. of game won by 0 = %d\n", b);

        }
        return 1;
    }
    ///To check for Draw case
    else if(count==8)
    {
        printf("\nThe Game is DRAW\n");
        c++;
        printf("\nNo. of draws between the 2 players are = %d\n", c);
        return 1;
    }
    else
    {
        return 0;
    }
}
/// Enter the position of X and 0 as per choice
struct myDataType inputValue(char sym[9],int count)
{
    char value;
    int i;
    struct myDataType info;
    inputAgain:
    if(count%2 == 0)
    {
        printf("\nEnter Your Choice X:");
    }
    else
    {
        printf("\nEnter Your Choice O:");
    }
    scanf("%s",&value);
    for(i=0;i<9;i++)
    {
        if(value == sym[i])
        {
            info.i = i;
            if(count%2 == 0)
            {
                info.ch = 'X';
            }
            else
            {
                info.ch = 'O';
            }
            break;
        }
        else
        {
            info.i = -1;
            info.ch = ' ';
        }
    }
///To check invalid test cases
    if(info.i == -1)
    {
        printf("\nInput is not Valid");
        goto inputAgain;
    }
    return info;
}
///To Display the Tic Tac Toe table
void Display(char sym[9])
{
	printf("\t\t\t\tT i c	t a c	t o e");
	printf("\nPlayers 1 Symbol: X");
	printf("\nPlayers 2 Symbol: O");
	printf("\n\t\t\t       |       |       ");
	printf("\n\t\t\t   %c   |   %c   |   %c   ",sym[0],sym[1],sym[2]);
	printf("\n\t\t\t-------|-------|-------");
	printf("\n\t\t\t   %c   |   %c   |   %c   ",sym[3],sym[4],sym[5]);
	printf("\n\t\t\t-------|-------|-------");
	printf("\n\t\t\t   %c   |   %c   |   %c   ",sym[6],sym[7],sym[8]);
	printf("\n\t\t\t       |       |       ");
}
