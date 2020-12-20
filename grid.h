#ifndef prj4_H
#define prj4_H

#include <iostream>

using namespace std;



enum StatuS 

{

	sunk=0,

	operative=1

};

class Ships 

{

public:
	
	static int size;
	
	static int number_of_hits_to_sunk;

	static int shooting_capacity;
	
	int hitpoint;

	StatuS status=operative;

	friend static int int_to_int(char*);
	
	friend static int str_to_int(char*);

	bool isSunk() 
	{
	
		if (hitpoint > 0) 
		{
		
			return false;
		
		}
		else 
		{
		
			return true;
		
		}

	}


	
	void deploy_ship(int x_1, int y_1, int x_2, int y_2, char** &dep_grid,int x)
	{
		int c = 0;

		x_1 -= 1;
		x_2 -= 1;
		y_1 -= 1;
		y_2 -= 1;
		char a = '0' + x;

		if ((x_1 == x_2) && (y_1 == y_2)) 
		{		
		
			dep_grid[x_1][y_1] = a;

		}


		else if (x_1 == x_2)
		{

			for (c = y_1; c <= y_2; c++)
			{

				dep_grid[x_1][c]= a;

			}

		}
		else if (y_1 == y_2)
		{

			for (c = x_1; c <= x_2; c++)
			{

				dep_grid[c][y_1]= a;

			}

		}

		else
		{
			
			if (y_1 > y_2) 
			{			
				int c2 = y_1;
				for (c = x_1; c <= x_2; c++) 
				{				
				
					dep_grid[c][c2] = a;
					c2--;
				}
				

			}
			else {
				int c2 = y_1;
				for (c = x_1; c <= x_2; c++)
				{

					dep_grid[c][c2] = a;
					c2++;
				}


			}

		}

	}
};

class Aircraft_Carrier :public Ships
{


public:

	Aircraft_Carrier()  
	
	{
		Aircraft_Carrier::size = 5;

		Aircraft_Carrier::number_of_hits_to_sunk = 4;

		Aircraft_Carrier::shooting_capacity = 3;
		
		hitpoint = Aircraft_Carrier::number_of_hits_to_sunk;
	}

	void Shoot_Function(Players Opponent) 
	{
	

		char* first_coordinate;

		char* second_coordinate;

		first_coordinate = new char[10];

		second_coordinate = new char[10];

		int fc, sc;
		
		int count = 0;
		
		for (count = 0; count < shooting_capacity; count++) 
		
		{
		
			cout << "Where do you want to shoot:";

			cin >> first_coordinate >> second_coordinate ;

			fc = str_to_int(first_coordinate);

			sc = int_to_int(second_coordinate);

			if (Opponent.deployment_grid[fc][sc] == '0') 
			{
			
				Shooting_grid[fc][sc] = '0';
			}

			cout << endl;

		}
	
	}



};

class Battleship :public Ships
{


public:

	Battleship()

	{
		Battleship::size = 4;

		Battleship::number_of_hits_to_sunk = 3;

		Battleship::shooting_capacity = 5;

		hitpoint = Battleship::number_of_hits_to_sunk;

	}

	//void Shoot_Function() {}


};

class Submarine :public Ships
{


public:

	Submarine()

	{
		Submarine::size = 3;

		Submarine::number_of_hits_to_sunk = 2;

		Submarine::shooting_capacity = 2;

		hitpoint = Submarine::number_of_hits_to_sunk;

	}

	//void Shoot_Function() {}


};

class Patrol_Boat:public Ships
{


public:

	Patrol_Boat()

	{
		Patrol_Boat::size = 1;

		Patrol_Boat::number_of_hits_to_sunk = 1;

		Patrol_Boat::shooting_capacity = 1;

		hitpoint = Patrol_Boat::number_of_hits_to_sunk;
	
	}

	//void Shoot_Function() {}


};

class Players
{

public:

	char* name;

	static int grid_size;
	
	Ships* Ship_List;

	char** deployment_grid;//i need two, one is for deployment registration,other for shooting (and i need a function for them to initializing them,i implement it below)

	char** shooting_grid;

	Players() 
	{
	
		grid_size=0;
	
	}

	Players(char NaMe[]) 
	
	{
	
		name = new char[30];
		
		strcpy(name,NaMe);

		grid_size = 0;
			
	}

	
	
	void set_size(int size) 
	{
	
		grid_size = size;
	
	}
	
	void grid_initializer() //i need this extra function to keep my main function code clean
	{

		int a, b;
		int x = 0, y = 0;
		if (grid_size == 1) { a = 5; b = 8; }
		if (grid_size == 2) { a = 8; b = 10; }
		if (grid_size == 3) { a = 10; b = 12; }

		shooting_grid = new char*[a];
		for (x = 0; x < a; x++)
		{

			shooting_grid[x] = new char[b];

		}

		deployment_grid = new char*[a];
		for (x = 0; x < a; x++)
		{

			deployment_grid[x] = new char[b];

		}
		for (x = 0; x < a; x++)
		{

			for (y = 0; y < b; y++)
			{

				shooting_grid[x][y] = '*';
				deployment_grid[x][y] = '*';
			}

		}
	}
		void print_shoting_grid()
		{
			int a, b;
			if (grid_size == 1) { a = 5; b = 8; }
			if (grid_size == 2) { a = 8; b = 10; }
			if (grid_size == 3) { a = 10; b = 12; }
			int x = 0, y = 0 ;
			for (x = 0; x < a; x++)
			{

				for (y = 0; y < b; y++)
				{

					cout << shooting_grid[x][y];

				}
				cout << endl;
			}
		
		}
		void print_deployment_grid()
		{
			int a, b;
			if (grid_size == 1) { a = 5; b = 8; }
			if (grid_size == 2) { a = 8; b = 10; }
			if (grid_size == 3) { a = 10; b = 12; }
			int x = 0, y = 0;
			for (x = 0; x < a; x++)
			{

				for (y = 0; y < b; y++)
				{

					cout << deployment_grid[x][y];

				}
				cout << endl;
			}

		}
	
		void deployment_for_grid() 
		{

			if (grid_size == 1) 
			{
				Ship_List = new Ships[5];
				int x = 0;
				
				take_aircraft_carrier(x);
				
				print_deployment_grid();
				
				take_battleship(x + 1);
				
				print_deployment_grid();
				
				take_submarine(x + 2);
				
				print_deployment_grid();
				
				take_Patrol_boat(x + 3);
				
				print_deployment_grid();
				
				take_Patrol_boat(x + 4);

				print_deployment_grid();


			
			
			}
			if (grid_size == 2)
			{
				Ship_List = new Ships[10];
				int x = 0;

				take_aircraft_carrier(x);
				print_deployment_grid();
				take_aircraft_carrier(x + 1);
				print_deployment_grid();
				take_battleship(x + 2);
				print_deployment_grid();
				take_battleship(x + 3);
				print_deployment_grid();
				take_submarine(x + 4);
				print_deployment_grid();
				take_submarine(x + 5);
				print_deployment_grid();
				take_Patrol_boat(x + 6);
				print_deployment_grid();
				take_Patrol_boat(x + 7);
				print_deployment_grid();
				take_Patrol_boat(x + 8);
				print_deployment_grid();
				take_Patrol_boat(x + 9);
				print_deployment_grid();



			}
			if (grid_size == 3) 
			{

				Ship_List = new Ships[13];
				int x = 0;

				take_aircraft_carrier(x);
				print_deployment_grid();
				take_aircraft_carrier(x + 1);
				print_deployment_grid();
				take_aircraft_carrier(x + 2);
				print_deployment_grid();
				take_aircraft_carrier(x + 3);
				print_deployment_grid();
				take_battleship(x + 4);
				print_deployment_grid();
				take_battleship(x + 5);
				print_deployment_grid();
				take_battleship(x + 6);
				print_deployment_grid(); 
				take_submarine(x + 7);
				print_deployment_grid();
				take_submarine(x + 8);
				print_deployment_grid();
				take_Patrol_boat(x + 9);
				print_deployment_grid();
				take_Patrol_boat(x + 10);
				print_deployment_grid();
				take_Patrol_boat(x + 11);
				print_deployment_grid();
				take_Patrol_boat(x + 12);
				print_deployment_grid();



			}

			


		
		}
		void take_aircraft_carrier(int x) 
		{
	
			char* first_coordinate;

			char* second_coordinate;

			char* first_coordinate2;

			char* second_coordinate2;

			first_coordinate = new char[10];

			second_coordinate = new char[10];

			first_coordinate2 = new char[10];

			second_coordinate2 = new char[10];

			cout << "Coordinates of aircraft carrier(less x coordinate should be first):";
			
			cin >> first_coordinate >> second_coordinate >> first_coordinate2 >> second_coordinate2;

			Ships *Aircraft = new Aircraft_Carrier();
		
			Ship_List[x] = *Aircraft;

			insert_on_grid(*Aircraft, first_coordinate, second_coordinate, first_coordinate2, second_coordinate2,x);

		}
		void take_battleship(int x)
		{

			char* first_coordinate;

			char* second_coordinate;

			char* first_coordinate2;

			char* second_coordinate2;

			first_coordinate = new char[10];

			second_coordinate = new char[10];

			first_coordinate2 = new char[10];

			second_coordinate2 = new char[10];

			cout << "Coordinates of battleship(less x coordinate should be first):";

			cin >> first_coordinate >> second_coordinate >> first_coordinate2 >> second_coordinate2;

			cout << endl;

			Ships *battleship = new Battleship();

			Ship_List[x] = *battleship;

			insert_on_grid(*battleship, first_coordinate, second_coordinate, first_coordinate2, second_coordinate2,x);

		}

		void take_submarine(int x)
		{

			char* first_coordinate;

			char* second_coordinate;

			char* first_coordinate2;

			char* second_coordinate2;

			first_coordinate = new char[10];

			second_coordinate = new char[10];

			first_coordinate2 = new char[10];

			second_coordinate2 = new char[10];

			cout << "Coordinates of submarine(less x coordinate should be first):";
			
			cin >> first_coordinate >> second_coordinate >> first_coordinate2 >> second_coordinate2;

			cout << endl;

			Ships *submarine = new Submarine();

			Ship_List[x] = *submarine;

			insert_on_grid(*submarine, first_coordinate, second_coordinate, first_coordinate2, second_coordinate2,x);

		}
		void take_Patrol_boat(int x)
		{
			char* first_coordinate;

			char* second_coordinate;

			char* first_coordinate2;

			char* second_coordinate2;

			first_coordinate = new char[10];

			second_coordinate = new char[10];

			first_coordinate2 = new char[10];

			second_coordinate2 = new char[10];

			cout << "Coordinates of Patrol_boat:";

			cin >> first_coordinate >> second_coordinate >> first_coordinate2 >> second_coordinate2 ;

			cout << endl;

			Ships *Patrol_boat = new Patrol_Boat();

			Ship_List[x] = *Patrol_boat;

			insert_on_grid(*Patrol_boat, first_coordinate, second_coordinate, first_coordinate2, second_coordinate2,x);

		}
		void insert_on_grid(Ships shipp, char fc[], char sc[], char fc2[], char sc2[],int x)
		{
			
			int number_x_1, number_y_1, number_x_2, number_y_2;
			
			number_x_1 = str_to_int(fc);
			
			number_x_2 = str_to_int(fc2);
			
			number_y_1 = int_to_int(sc);
			
			number_y_2 = int_to_int(sc2);

			

			shipp.deploy_ship(number_x_1, number_y_1, number_x_2, number_y_2,deployment_grid,x);
		
		
		}
		



		static int str_to_int(char str[])
		{

			if (grid_size == 1)
			{
				if (!strcmp(str, "a"))
				{
					return 1;
				}
				else if (!strcmp(str, "b"))
				{
					return 2;
				}
				else if (!strcmp(str, "c"))
				{
					return 3;
				}
				else if (!strcmp(str, "d"))
				{
					return 4;
				}
				else
				{
					return 5;
				}



			}
			else if (grid_size == 2)
			{
				if (!strcmp(str, "a"))
				{
					return 1;
				}
				else if (!strcmp(str, "b"))
				{
					return 2;
				}
				else if (!strcmp(str, "c"))
				{
					return 3;
				}
				else if (!strcmp(str, "d"))
				{
					return 4;
				}
				else if (!strcmp(str, "e"))
				{
					return 5;
				}
				else if (!strcmp(str, "f"))
				{
					return 6;
				}
				else if (!strcmp(str, "g"))
				{
					return 7;
				}
				else
				{
					return 8;
				}
			}
			else
			{
				if (!strcmp(str, "a"))
				{
					return 1;
				}
				else if (!strcmp(str, "b"))
				{
					return 2;
				}
				else if (!strcmp(str, "c"))
				{

					return 3;
				}
				else if (!strcmp(str, "d"))
				{
					return 4;
				}
				else if (!strcmp(str, "e"))
				{
					return 5;
				}
				else if (!strcmp(str, "f"))
				{
					return 6;
				}
				else if (!strcmp(str, "g"))
				{
					return 7;
				}
				else if (!strcmp(str, "h"))
				{
					return 8;
				}
				else if (!strcmp(str, "i"))
				{
					return 9;
				}
				else
				{
					return 10;
				}


			}
		}
		static int int_to_int(char str[])
		{

			if (grid_size == 1)
			{
				if (!strcmp(str, "1"))
				{
					return 1;
				}
				else if (!strcmp(str, "2"))
				{
					return 2;
				}
				else if (!strcmp(str, "3"))
				{
					return 3;
				}
				else if (!strcmp(str, "4"))
				{
					return 4;
				}
				else if (!strcmp(str, "5"))
				{
					return 5;
				}
				else if (!strcmp(str, "6"))
				{
					return 6;
				}
				else if (!strcmp(str, "7"))
				{
					return 7;
				}
				else
				{
					return 8;
				}



			}
			else if (grid_size == 2)
			{
				if (!strcmp(str, "1"))
				{
					return 1;
				}
				if (!strcmp(str, "2"))
				{
					return 2;
				}
				if (!strcmp(str, "3"))
				{
					return 3;
				}
				if (!strcmp(str, "4"))
				{
					return 4;
				}
				if (!strcmp(str, "5"))
				{
					return 5;
				}
				if (!strcmp(str, "6"))
				{
					return 6;
				}
				if (!strcmp(str, "7"))
				{
					return 7;
				}
				if (!strcmp(str, "8"))
				{
					return 8;
				}
				if (!strcmp(str, "9"))
				{
					return 9;
				}
				else
				{
					return 10;
				}
			}
			else
			{
				if (!strcmp(str, "1"))
				{
					return 1;
				}
				if (!strcmp(str, "2"))
				{
					return 2;
				}
				if (!strcmp(str, "3"))
				{
					return 3;
				}
				if (!strcmp(str, "4"))
				{

					return 4;
				}
				if (!strcmp(str, "5"))
				{
					return 5;
				}
				if (!strcmp(str, "6"))
				{
					return 6;
				}
				if (!strcmp(str, "7"))
				{
					return 7;
				}
				if (!strcmp(str, "8"))
				{
					return 8;
				}
				if (!strcmp(str, "9"))
				{
					return 9;
				}
				if (!strcmp(str, "10"))
				{
					return 10;
				}
				if (!strcmp(str, "11"))
				{
					return 11;
				}
				else
				{
					return 12;
				}
			}
		bool isLost() 
		{
		
			int x = 0;
			int y = 0;
			if (grid_size == 1) { y = 5; }
			if (grid_size == 2) { y = 10; }
			if (grid_size == 3) { y = 13; }

			for (x = 0; x < y; x++) 
			{
			
				if (Ship_List[x].status == operative) { return false; }
							
			}
			
			return true;

		}
		void Turn(Players Opponent) 
		
		{
			int c=0;
			while (Ship_List[c].status != operative) 
			{
			
				c++;
			
			}
			Ship_List[c].Shoot_Function(Opponent);
		
		}
		


};










#endif