/*

Class : CSIS_223_Object-Oriented_Programming_C++_Programming
Student: Juan Ramon Lepe Manzo
ID: S1448233
Chapter: 9 Records (structs)
Objetive: Exercise 9.7 
1. Declares a struct to store the data of a football player 
2. Declare an array of 10 components to store the data of 10 football players. 
3. input data and a function 
4. Output data. 
5. Search the array to find the index of a specific player, 
6. Update the data of a player. 
7. You may assume that the input data is stored in a file.
8  Before the program terminates, give the user the option to save data in a file. 
9. Menu driven, giving the user various choices



*/

#include <iostream>
#include <string>
#include <fstream>					
#include <iomanip>
# define num_players 10

using namespace std;

// Declare structure for players
struct players 
{
	int index_player;
	string name, position,touchdowns, catches, passingYards, receivingYards, rushingYards;
};

//Flag for file.
int exist_file = 1;


//Declare functions
void menu();
void outData(struct players s[]);
void searchPlayer(struct players s[]);
void updateData(struct players s[]);
void inputData(players s[]);
void saveData(struct players s[]);

int main()
{
	int i=0, choice, notquit = 1;
	ifstream infile;
	string searchName;
	bool found = false;
	int index_player;

	struct players s[num_players]; 

	//Open file and extract data
	infile.open("players.txt");	

	// check whether file exists or not.
	if (!infile)
	{
		cout << "The input file is not found, you will need to input new records. ";
		system("pause");
	}
	else {
		exist_file = 0;
		//Data in array
		while (!infile.eof())
		{
			infile >> s[i].index_player >> s[i].name >> s[i].position >> s[i].touchdowns >> s[i].catches >> s[i].passingYards >>
				s[i].receivingYards >> s[i].rushingYards;
			i++;
		}

	}
	infile.close();

	// Options for menus
	while (notquit)
	{
		//Create menu
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1: // Display
			outData(s);
			system("pause");
			break;
		case 2: // Search
			searchPlayer(s);
			system("pause");
			break;
		case 3: // Update
			updateData(s);
			system("pause");
			break;
		case 4: //Input Data
			inputData(s);
			exist_file = 0;
			system("pause");
			break;
		case 0: //Exit and save
			saveData( s);
			notquit = 0;
			break;
		default:
			cout << "Please try again" << endl;
			system("pause");
		}
	}

	
	system("pause");
	return 0;
}


//Function for menu
void menu()
{
	system("CLS");
	cout << "-----------Menu----------" << endl;
	cout << "\n1. Display Player's Information ";
	cout << "\n2. Search a Player";
	cout << "\n3. Update a Player Information";
	cout << "\n4. Input new Player's";
	cout << "\n0. Exit" << endl;
	cout << "\nSelect your option: ";

}

//Function for outData
void outData(struct players s[])
{
	if (exist_file) return;

	system("CLS");
	for (int i = 1; i < num_players; i++)
	{
		cout << "--------------------------------";
		cout << "\nIndex: " << s[i].index_player;
		cout << "\nName: " << s[i].name;
		cout << "\nPosition: " << s[i].position;
		cout << "\nTouchdowns: " << s[i].touchdowns;
		cout << "\nCatches: " << s[i].catches;
		cout << "\nPassing Yards: " << s[i].passingYards;
		cout << "\nReceiving Yards: " << s[i].receivingYards;
		cout << "\nRunning Yards:  " << s[i].rushingYards;
		cout << "\n------------------------------" << endl;
	}

}

// function for search a player
void searchPlayer(struct players s[])
{

	if (exist_file) return;


	int flag = 0;    
	int searchIndex;

	system("CLS");
	cout << "Enter the index of the player: ";
	cin >> searchIndex;


	for (int i = 1; i < num_players; i++)    
	{
		if (s[i].index_player == searchIndex)   
		{
			flag = 1;   
			cout << "--------------------------------";
			cout << "\nIndex: " << s[i].index_player;
			cout << "\nName: " << s[i].name;
			cout << "\nPosition: " << s[i].position;
			cout << "\nTouchdowns: " << s[i].touchdowns;
			cout << "\nCatches: " << s[i].catches;
			cout << "\nPassing Yards: " << s[i].passingYards;
			cout << "\nReceiving Yards: " << s[i].receivingYards;
			cout << "\nRunning Yards:  " << s[i].rushingYards;
			cout << "\n------------------------------" << endl;
			break;    
		}

	}

	if (flag==0)    
	{
		cout << " I could not find that player." << endl << endl;

	}

}

//funstion for update data
void updateData(struct players s[])
{
	if (exist_file) return;

	int searchIndex;

	cout << "Enter the index of the player to update: ";

	cin >> searchIndex;

	int flag = 0;    

	for (int i = 1; i < num_players; i++)    
	{
		if (s[i].index_player == searchIndex)   
		{
			system("CLS");

			cout << "\n NOTE: DONT USE SPACES\n";

			flag = 1;   
			cout << "--------------------------------";
			cout << "\nName: " << s[i].name << "\n";
			cout << "Position: ";
			cin >> s[i].position;
			cout << "Touch Downs: ";
			cin >> s[i].touchdowns;
			cout << "Catches: ";
			cin >> s[i].catches;
			cout << "Passing Yards: ";
			cin >> s[i].passingYards;
			cout << "Receiving Yards: ";
			cin >> s[i].receivingYards;
			cout << "Rushing Yards: ";
			cin >> s[i].rushingYards;
			cout << "\n------------------------------" << endl;
			break;    
		}

	}

	if (flag == 0)    
	{
		cout << "I could not find that player." << endl << endl;

	}

}

//Function for input data.
void inputData( players s[] )
{

	for (int i = 0; i < num_players; i++)
	{
		system("CLS");

		cout << "\n NOTE: DONT USE SPACES\n";

		s[i].index_player = i+1;
		cout << "\n# Player: " << i+1 << "\n";
		cout << "Name: ";
		cin >> s[i].name;
		cout << "Position: ";
		cin >> s[i].position;
		cout << "Touch Downs: ";
		cin >> s[i].touchdowns;
		cout << "Catches: ";
		cin >> s[i].catches;
		cout << "Passing Yards: ";
		cin >> s[i].passingYards;
		cout << "Receiving Yards: ";
		cin >> s[i].receivingYards;
		cout << "Rushing Yards: ";
		cin >> s[i].rushingYards;

	}

	exist_file = 0;


}

//Function for save data in file
void saveData(struct players s[])

{

	if (exist_file) return;

	string ask_save;
	cout << "Save Data? Y/N ";
	cin >> ask_save;


	if (ask_save == "y" || ask_save == "Y")
	{

		ofstream  outfile;

		outfile.open("players.txt");

		for (int i = 0; i < num_players; i++) {
			outfile << i + 1 << " ";
			outfile << s[i].name << " ";
			outfile << s[i].position << " ";
			outfile << s[i].touchdowns << " ";
			outfile << s[i].catches << " ";
			outfile << s[i].passingYards << " ";
			outfile << s[i].receivingYards << " ";
			outfile << s[i].rushingYards << endl;
		}

		outfile.close();

		cout << "Successful saved." << endl;
	}
}