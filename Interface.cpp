#include "Interface.h"

// The purpose of this file is to give functionality to the menu
// function prototypes defined in the interface header file. This
// file contains to functions for reading out the menu options
// avalible to the user and collect the users choice.


// Main Menu option for the user
void user_menu(Week_list & obj)
{
    bool valid = true;
    int menu = 0;

    while(valid)
    {
	cout << endl << "-----------------------------"	<< endl;
	cout << "Main Menu"			<< endl;
	cout << "-----------------------------"	<< endl;
	cout << "0. EXIT"			<< endl;
	cout << "1. Add a new Calendar Event"	<< endl;
	cout << "2. Update a Calendar Event"	<< endl;
	cout << "3. Find a Calendar Event"	<< endl;
	cout << "4. Display Calendar Events"	<< endl;
	cout << "5. Remove a Calendar Event"	<< endl;
	cout << "6. Remove All Calendar Events" << endl;
	cout << "-----------------------------" << endl;
	cout << "#: ";
	cin >> menu;
	cin.ignore(100, '\n');

	if(user_pick(obj, menu)==0)
	    valid = false;
    }
}

// Main Menu user selection
int user_pick(Week_list & obj, int menu)
{
    switch(menu)
    {
	case 0:
	    return 0;
	break;
	case 1:
	    system("clear");
	    obj.insert();
	break;
	case 2:
	    system("clear");
	    obj.update();
	break;
	case 3:
	    system("clear");
	    obj.retrieval();
	break;
	case 4:
	    system("clear");
	    obj.display();
	break;
	case 5:
	    system("clear");
	    obj.removal();
	break;
	case 6:
	    system("clear");
	    obj.remove_all();
	break;
	default: cout << endl << "Invalid Number!" << endl << endl;
    }
    return 1;
}
