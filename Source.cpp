#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<windowsx.h>
#include<mmsystem.h>
#define ROWS 6
#define COLUMNS 8
struct player
{
	char name[15];
	char letter;
};
void getter()
{
	char x;
	scanf_s(" %c", &x);
}

int checkwin(char str[][8])
{
	//diagonal
	for (int i = 0; i < ROWS - 3; i++)

		for (int j = 0; j < COLUMNS - 3; j++)
		{
			if (str[i][j] == str[i + 1][j + 1] && str[i][j] == str[i + 2][j + 2] && str[i][j] == str[i + 3][j + 3] && str[i][j] != ' ')
			{
				return 1;
			}
		}
	//reverse diagonal
	for (int i = 0; i < ROWS - 2; i++)

		for (int j = 6; j > 2; j--)
		{
			if (str[i][j] == str[i + 1][j - 1] && str[i][j] == str[i + 2][j - 2] && str[i][j] == str[i + 3][j - 3] && str[i][j] != ' ')
			{
				return 1;
			}
		}
	//horizontal
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS - 3; j++)
		{
			if (str[i][j] == str[i][j + 1] && str[i][j] == str[i][j + 2] && str[i][j] == str[i][j + 3] && str[i][j] != ' ')
			{
				return 1;
			}
		}
	//vertical
	for (int i = 0; i < ROWS - 3; i++)
		for (int j = 0; j < COLUMNS; j++)
		{
			if (str[i][j] == str[i + 1][j] && str[i][j] == str[i + 2][j] && str[i][j] == str[i + 3][j] && str[i][j] != ' ')
			{
				return 1;
			}
		}
	return 0;
}
int mainmenu()
{
	system("COLOR 4");
	system("CLS");
	char x;
	printf("\tCONNECT FOUR\n\n\n");
	printf("To Start Game Enter     (1)\n");
	printf("To Quit The Game Enter  (2)\n");
	printf("\n\nYour Choice : ");
	scanf_s(" %c", &x);
	if (x == '1')
		return 0;
	else if (x == '2')
	{
		return 1;
	}
	else
	{
		printf("unavailble,press any key to try again");
		mainmenu();
	}
}

void printboard(char str[][8])
{
	system("CLS");
	bool menusound=PlaySound("menu.wav",NULL,SND_ASYNC);
	int i;
	int y;
	for (i = 0; i < 6; i++)
	{
		printf("+---+---+---+---+---+---+---+---+\n");
		printf("|");
		for (y = 0; y < 8; y++)
		{
			if (str[i][(y)] == 'X')
			{
				//blue
				printf("\x1b[34m 0 ");
				//red
				printf("\x1b[31m|");
			}
			else if (str[i][(y)] == 'O')
			{
				//green
				printf("\x1b[32m 0 ");
				//red
				printf("\x1b[31m|");
			}
			else
				printf("   |");
		}
		printf("  \n");
	}
	printf("+---+---+---+---+---+---+---+---+\n");
	printf("  1   2   3   4   5   6   7   8\n\n");
}
int player_move(char str[][8], int col, char letter)
{
	int y, choiice = 0;


	for (int i = 5; i > -1; i--)
	{
		if (str[0][col] != ' ')
		{
			
			
			return 0;
		}
		else if (str[i][col] == ' ')
		{
			str[i][col] = letter;
			printboard(str);
			break;
		}
	}
}
void resetandprintboard()
{
	system("COLOR 4");
	system("CLS");
	for (int i = 0; i < ROWS; i++)
	{
		printf("+");
		for (int y = 0; y < COLUMNS; y++)
		{
			printf("---+");
		}
		printf("\n|");
		for (int x = 0; x < COLUMNS; x++)
			printf("   |");
		printf("\n");

	}
	printf("+---+---+---+---+---+---+---+---+\n");
	printf("  1   2   3   4   5   6   7   8\n\n");
	printf("\tCONNECT FOUR\n\n");
}
int main(void)
{
	PlaySound(NULL, 0, 0);
	//bool background = PlaySound("background.wav", NULL, SND_ALIAS| SND_LOOP | SND_ASYNC);
	struct player player1;
	struct player player2;
	//bn3rf el letters lel player
	player1.letter = 'X';
	player2.letter = 'O';
	int col1;
	int choice;
	int checker = 0;
	
	while (mainmenu() == 0)
	{
		system("CLS");
		printf("\n\n\n");
		char nth[9];
		fgets(nth,sizeof nth,stdin);
		printf("Player 1 kindly Enter your Name :");
		fgets(player1.name,sizeof player1.name,stdin);
		printf("\n");
		printf("Player 2 kindly Enter your Name :");
		fgets(player2.name, sizeof player2.name, stdin);
		//el background 2d array el hy4t8l parallel
		char str[][8] = { { ' ',' ',' ',' ',' ',' ',' ',' ' },
						  { ' ',' ',' ',' ',' ',' ',' ',' ' },
						  { ' ',' ',' ',' ',' ',' ',' ',' ' },
						  { ' ',' ',' ',' ',' ',' ',' ',' ' },
						  { ' ',' ',' ',' ',' ',' ',' ',' ' },
						  { ' ',' ',' ',' ',' ',' ',' ',' ' } };

		resetandprintboard();
		for (int i = 0; i < 24; i++)
		{

			printf("player 1 select column:");

			//bna5od el column 3a4an yfdl sabet fl function
			scanf_s("%d", &choice);
			while (choice<'1' || choice>'8')
			{
				printf("wrong input\n");
				printf("enter new column :");
				scanf_s("%d", &choice);
			}
			
			while (choice>8||choice<1)
			{
				printf("wrong input\n");
				printf("enter new column :");
				scanf_s("%d", &choice);	
				
			}
			while (str[0][choice-1] != ' ')
			{
				bool errorsound = PlaySound("error.wav", GetModuleHandle(NULL),SND_NOSTOP|SND_ALIAS |SND_SYNC);
				printf("The column is full!\nEnter another column : ");
				scanf_s("%d", &choice);
				
				
			}
			player_move(str, choice-1, player1.letter);
			if (checkwin(str) == 1)
			{
				printf("\t\t%s", player1.name);
				printf("\t  IS THE WINNER !!!!\n\n\n\n\n\n");
				printf("Enter any key to go back to main menu.");
				getter();
				break;
			}
			//bna5od el column 3a4an yfdl sabet fl function
			printf("player 2 select column:");
			scanf_s("%d", &choice);
			
			
			while (choice<1||choice>8)
			{
				printf("wrong input\n");
				printf("enter new column :");
				scanf_s("%d", &choice);
				
			}
			
			while (str[0][choice-1] != ' ')
			{
				bool errorsound = PlaySound("error.wav", GetModuleHandle(NULL),SND_NOSTOP |SND_ALIAS| SND_SYNC);
				printf("The column is full!\nEnter another column : ");
				scanf_s("%d", &choice);
				
				
			}
			player_move(str, choice-1, player2.letter);
			if (checkwin(str) == 1)
			{
				printf("\t\t%s" , player2.name);
				printf("\t  IS THE WINNER !!!!\n\n\n\n\n\n");
				printf("Enter any key to go back to main menu.\n");
				getter();
				break;
			}
		}
	}
	return 0;
}

