#include<iostream>
#include <string>
#include <array>
#include <cctype>

using namespace std;
// draw board of the game
void drawBoard(char matrix[3][3])
{   
	
	for (int i = 0; i < 4; i++)
	{
		// for ---
		for (int j = 0; j < 4; j++)

		{
			if (j == 3)
			{
				cout << "----";
			}
			else {
				cout << "---";
			}
			
		}
		cout << endl;
		// for | postion 
		for (int j = 0; j < 4; j++)
		{
			if (j == 3 && i<3)
			{
				cout << "|";
			}
			else if (j<3 && i < 3){
				cout << "| " << matrix[i][j] << " ";
			}
		}
		cout << endl;
	}
}
char checkWinner(char matrix[3][3])
{
	// // Check rows
	if (matrix[0][0] != ' ' && matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
	{
		return matrix[0][0];
	}
	//Secondary Diagonal
	else if (matrix[0][2] != ' ' && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return matrix[0][2];
	}
	else {
		// Check rows
		for (int i = 0; i < 3; i++)
		{
			
			 if (matrix[i][0] != ' ' && matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
			{
				return matrix[i][0];
			}
		}
		// Check columns
		for (int i = 0; i < 3; i++)
		{

			 if (matrix[0][i] != ' ' && matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
			{
				return matrix[0][i];
			}
			
		}
		return ' ';
	}
	
}
array<int,2> FindIndex(char matrix[3][3], int postion)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{	
			// Converts character digits to integer values using ASCII.
			// Subtracting '0' from the character converts it to the integer value by leveraging ASCII values. 
			// example : ascall '1' = 49 as int so i will subtract '0' = 48 as int 49 - 48 = 1

			int number = matrix[i][j] - '0';
			
			if ( number== postion)
			{
				
				return  array<int,2> {i,j};
			}

			
		}
		cout << endl;
	}
}

void main()
{
	char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
	int checkValue[3][3] = {0};
	int gameRounds = 0;
	int postion;
	char whoWinner;
	bool isX = true;
		
	do {
		drawBoard(matrix);
		char XOrO = isX ? 'X' : 'O';
		cout << "Enter postion from just 1 to 9  player "<< XOrO <<" : ";
		cin >> postion;
		//if user enter invalid number 
		while (postion < 1 || postion>9)
		{
			cout << "Invalid Value sir ,Plz Enter postion from just 1 to 9  player " << XOrO << " : ";
			cin >> postion;
		}
		array<int, 2>	arr = FindIndex(matrix, postion);
		
		// Ensure the user cannot place 'X' or 'O' in a cell that's already occupied.
		while (checkValue[arr[0]][arr[1]]!=0)
		{
			cout << "Invalid Value sir ,Plz Enter valid postion from 1 to 9 player " << XOrO << " : ";
			cin >> postion;
			arr = FindIndex(matrix, postion);
		}

		matrix[arr[0]][arr[1]] = XOrO;
		// save 1 to 9 
		checkValue[arr[0]][arr[1]] = matrix[arr[0]][arr[1]];
		//To reduce the number of checkWinner operations from 9 to 6 and avoid unnecessary checks, 
		if (gameRounds > 3)
		{
			whoWinner = checkWinner(matrix);
			if (whoWinner == 'X' || whoWinner == 'O')
			{
				cout << "Winner is " << whoWinner << endl;
				break;
			}
		}
			isX = !isX;
			gameRounds++;
			//clean console
		system("cls");
	} while (gameRounds < 9);
	 
	if (whoWinner != 'X' && whoWinner != 'O')
	{
		cout << "Game Over " << endl;
	}
	
	
	
}