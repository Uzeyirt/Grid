#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include"prj4.h"

using namespace std;

int Players::grid_size = 0;

 int Ships::size;

 int Ships::number_of_hits_to_sunk;

 int Ships::shooting_capacity;

int main() 

{

	

	cout << "************************************" << endl;
	cout << "************************************" << endl;
	cout << "**************WELCOME TO************" << endl;
	cout << "*******THE ULTIMATE BATTLISHIP******" << endl;
	cout << "************************************" << endl;
	cout << "************************************" << endl;
	char namE[30];
	char answer;
	cout << "Please enter a name(player1):";
	cin >> namE;
	Players player1(namE);
	cout << endl;
	cout << "Please enter a name(player2):";
	cin >> namE;
	Players player2(namE);

	do 
	{

		int grd_Size;
		
		cout << "1.Small" << endl;
		cout << "2.Medium" << endl;
		cout << "3.Large" << endl;
		cout << "Please specify grid size:";
		
		cin >> grd_Size;
		

		
		cout << endl;
		
		while ((grd_Size < 1) || (grd_Size > 3)) 
		
		{
		
			cout << "You entered nonvalid number,Please specify grid size again:";
			
			cin >> grd_Size;
			
			cout << endl;
		
		}

		player1.set_size(grd_Size);

		player1.grid_initializer();

		player2.grid_initializer();

		cout << endl << "FOR PLAYER 1:" << endl;

		player1.deployment_for_grid();
		
		cout << endl << "FOR PLAYER 2:" << endl;

		player2.deployment_for_grid();

			while (true)
			{
			
			
				player1.Turn(player2);
			
				if (player2.isLost()) 
				
				{
					cout << "Player 1 has won!" << endl << "Player2 has lost!" << endl;

					break;
				
				}
				
				player2.Turn(player1);

				if (player1.isLost())
				
				{
					cout << "Player 2 has won!" << endl << "Player 1 has lost!" << endl;

					break;
				
				}
				

			}	
		
		








		
		cout << "Do you want to play again(y/n):";
		
		cin >> answer;
		
		cout << endl;


	}while (answer != 'n');

	cout << "************************************" << endl;
	cout << "***********GOOD BYE*****************" << endl;
	cout << "************************************" << endl;
	cout << endl;










	system("pause");
	
	return 0;

}