#include "List.h"

// The purpose for this file was to implemtent the function prototypes
// for the defined by the classes in the list header file. The code in
// this file is also responsible for implementing the data structures
// for a LLL of events and DLL of weekly events.


//===============================================================//
// L Node [Event Node]
//===============================================================//

// Constructor
Lnode::Lnode()
: Lnext(NULL) {}

// Destructor
Lnode::~Lnode()
{
    if(Ldata)
	delete Ldata;
    Ldata = NULL;
}

// Return next pointer
Lnode *& Lnode::get_Lnext()
{
    return Lnext;
}


//===============================================================//
// Event List [LLL Manager]
//===============================================================//


// Constructor LLL
Event_list::Event_list()
: Lhead(NULL) {}


// Destructor LLL
Event_list::~Event_list()
{
    remove_all(Lhead);
}


// Add a new event menu wrapper LLL
int Event_list::insert()
{
    bool valid = true;
    int pick = 0;

    while(valid)
    {
	cout << "'Create a Calendar Event'" << endl;
	cout << "-------------------------" << endl;
	cout << "0. Return to Main Menu"    << endl;
	cout << "1. Add an Appointment"	    << endl;
	cout << "2. Add a Reminder"	    << endl;
	cout << "3. Add a Work Assignment"  << endl;
	cout << "-------------------------" << endl;
	cout << "#: ";
	cin >> pick;
	cin.ignore(100, '\n');

	switch(pick)
	{
	    case 0: valid = false;
	    break;
	    case 1:
	    {
		Event * Aptr = NULL;
		Aptr = new Appointment;
		insert(Lhead, Aptr);
	    }break;
	    case 2:
	    {
		Event * Rptr = NULL;
		Rptr = new Reminder;
		insert(Lhead, Rptr);
	    }break;
	    case 3:
	    {
		Event * Wptr = NULL;
		Wptr = new Work;
		insert(Lhead, Wptr);
	    }break;
	    default: cout << endl << "Invalid Number!" << endl << endl;
	}
    }return 1;
}


// Add a new event from the menu wrapper LLL
int Event_list::insert(Lnode *& head, Event * ptr)
{
    ptr->insert();
    if(!head)
    {
	head = new Lnode;
	head->Ldata = ptr;
	return 1;
    }
    Lnode * temp = new Lnode;
    temp->Ldata = ptr;
    temp->get_Lnext() = head;
    head = temp;
    return 1;
}


// Wrapper function for display LLL
int Event_list::display() const
{
    return display(Lhead);
}


// Display each event using dynamic casting LLL
int Event_list::display(Lnode * head) const
{
    if(!head) return 0;

    Appointment * Aptr = dynamic_cast<Appointment *>(head->Ldata);
    if(Aptr)
	Aptr->display();

    Reminder * Rptr = dynamic_cast<Reminder *>(head->Ldata);
    if(Rptr)
	Rptr->display();

    Work * Wptr = dynamic_cast<Work *>(head->Ldata);
    if(Wptr)
	Wptr->display();

    return display(head->get_Lnext()) + 1;
}


// Wrapper to remove an event entry LLL
int Event_list::removal(char del[])
{
    return removal(Lhead, del);
}


// Remove a single event entry LLL
int Event_list::removal(Lnode *& head, char * del)
{
    if(!head) return 0;

    Appointment * Aptr = dynamic_cast<Appointment *>(head->Ldata);
    if(Aptr)
    {
	if(strcmp(del, head->Ldata->get_title())==0)
	{
	    Lnode * temp = head->get_Lnext();
	    delete head;
	    head = temp;
	    return 1;
	}
    }
    Reminder * Rptr = dynamic_cast<Reminder *>(head->Ldata);
    if(Rptr)
    {
	if(strcmp(del, head->Ldata->get_title())==0)
	{
	    Lnode * temp = head->get_Lnext();
	    delete head;
	    head = temp;
	    return 1;
	}
    }
    Work * Wptr = dynamic_cast<Work *>(head->Ldata);
    if(Wptr)
    {
	if(strcmp(del, head->Ldata->get_title())==0)
	{
	    Lnode * temp = head->get_Lnext();
	    delete head;
	    head = temp;
	    return 1;
	}
    }return removal(head->get_Lnext(), del);
}


// Wrapper function to remove all events in LLL
int Event_list::remove_all()
{
    return remove_all(Lhead);
}


// Remove all events in LLL
int Event_list::remove_all(Lnode *& head)
{
    if(!head) return 0;

    Appointment * Aptr = dynamic_cast<Appointment *>(head->Ldata);
    if(Aptr)
    {
	Lnode * temp = head->get_Lnext();
	delete head;
	head = temp;
	return remove_all(head) + 1;
    }
    Reminder * Rptr = dynamic_cast<Reminder *>(head->Ldata);
    if(Rptr)
    {
	Lnode * temp = head->get_Lnext();
	delete head;
	head = temp;
	return remove_all(head) + 1;
    }
    Work * Wptr = dynamic_cast<Work *>(head->Ldata);
    if(Wptr)
    {
	Lnode * temp = head->get_Lnext();
	delete head;
	head = temp;
	return remove_all(head) + 1;
    }return remove_all(head->get_Lnext());
}


// Wrapper to retrieve an event from LLL
int Event_list::retrieval(char find[])
{
    return retrieval(Lhead, find);
}


// Retrieve an event from LLL using dynamic casting
int Event_list::retrieval(Lnode * head, char find[])
{
    if(!head) return 0;

    Appointment * Aptr = dynamic_cast<Appointment *>(head->Ldata);
    Reminder * Rptr = dynamic_cast<Reminder *>(head->Ldata);
    Work * Wptr = dynamic_cast<Work *>(head->Ldata);

    if(Aptr)
    {
	if(strcmp(find, head->Ldata->get_title())==0)
	{
	    Aptr->display();
	    return 1;
	}
    }
    if(Rptr)
    {
	if(strcmp(find, head->Ldata->get_title())==0)
	{
	   Rptr->display();
	    return 1;
	}
    }
    if(Wptr)
    {
	if(strcmp(find, head->Ldata->get_title())==0)
	{
	    Wptr->display();
	    return 1;
	}
    }
    return retrieval(head->get_Lnext(), find);
}


// Wrapper to update an event entry in LLL
int Event_list::update()
{
    char find[20];
    cout << endl << "Which Event would you like to Update?" << endl;
    cout << endl << "[Title]: ";
    cin.get(find, 20);
    cin.ignore(100, '\n');

    return update(Lhead, find);
}


// Up an event entry in LLL using dynamic casting
int Event_list::update(Lnode *& head, char find[])
{
    if(!head)
    {
	cout << "There is 'NO' Event with the Title " << find << "." << endl;
	return 0;
    }
    Appointment * Aptr = dynamic_cast<Appointment *>(head->Ldata);
    Reminder * Rptr = dynamic_cast<Reminder *>(head->Ldata);
    Work * Wptr = dynamic_cast<Work *>(head->Ldata);

    if(Aptr)
    {
	if(strcmp(find, head->Ldata->get_title())==0)
	{
	    Aptr->update();
	    return 1;
	}
    }
    if(Rptr)
    {
	if(strcmp(find, head->Ldata->get_title())==0)
	{
	    Rptr->update();
	    return 1;
	}
    }
    if(Wptr)
    {
	if(strcmp(find, head->Ldata->get_title())==0)
	{
	    Wptr->update();
	    return 1;
	}
    }return update(head->get_Lnext(), find);
}


//===============================================================//
// D Node [Event Node]
//===============================================================//


// Constructor node
Dnode::Dnode()
: weekday(NULL), Dnext(NULL), Dprev(NULL) {}

// Copy Constructor data member
Dnode::Dnode(char * source)
{
    weekday = new char[strlen(source) + 1];
    strcpy(weekday, source);
    Dnext = NULL;
    Dprev = NULL;
}

// Object Copy Constructor
Dnode::Dnode(Dnode & source)
{
    weekday = new char[strlen(source.weekday) + 1];
    strcpy(weekday, source.weekday);
}


// Destructor
Dnode::~Dnode()
{
    if(weekday)
	delete [] weekday;
    weekday = NULL;
}


// Wrapper to return next pointer
Dnode *& Dnode::get_Dnext()
{
    return Dnext;
}


// Wrapper to return previous pointer
Dnode *& Dnode::get_Dprev()
{
    return Dprev;
}


// Wrapper to return the day of the week
char *& Dnode::get_weekday()
{
    return weekday;
}


//===============================================================//
// Week List [DLL Manager]
//===============================================================//


// Constructor DLL
Week_list::Week_list()
: Dhead(NULL) {}


// Destructor DLL
Week_list::~Week_list()
{
    remove_all(Dhead);
}


// Wrapper to remove all days and events in the calendar
int Week_list::remove_all()
{
    return remove_all(Dhead);
}


// Remove all days and events in the calendar DLL
int Week_list::remove_all(Dnode *& head)
{
    if(!head) return 0;

    Dnode * temp = head->get_Dnext();
    delete head;
    head = temp;

    return remove_all(head) + 1;
}


int Week_list::insert()
{
    char day[10];
    cout << "Add a New Weekday Calendar Event For?"<< endl;
    cout << "[Day]: ";
    cin.get(day, 10);
    cin.ignore(100, '\n');

    return insert(Dhead, day);
}


// Add an event and day of the week to the DLL
int Week_list::insert(Dnode *& head, char day[])
{
    if(!day) return 0;

    if(!head)
    {
	head = new Dnode(day);
	head->Ddata.insert();
	return 1;
    }

    if(strcmp(head->get_weekday(), day)==0)
    {
	head->Ddata.insert();
	return 1;
    }

    if(!head->get_Dnext())
    {
	Dnode * temp = new Dnode(day);
	head->get_Dnext() = temp;
	temp->get_Dprev() = head;
	temp->Ddata.insert();
	return 1;
    }return insert(head->get_Dnext(), day);
}


// Wrapper function to update a calendar event in the LLL
int Week_list::update()
{
    char day[10];
    cout << "Update the Calendar Event On?"<< endl;
    cout << "[Day]: ";
    cin.get(day, 10);
    cin.ignore(100, '\n');
    return update(Dhead, day);
}


// Update a calendar event from the LLL
int Week_list::update(Dnode *& head, char day[])
{
    if(!head || !day)
    {
	cout << "These is 'NO' Calendar Events scheduled for " << day << "." << endl;
	return 0;
    }
    if(strcmp(head->get_weekday(), day)==0)
    {
	head->Ddata.update();
	return 1;
    }
    return update(head->get_Dnext(), day);
}


// Wrapper function to remove an Entry from in the LLL
int Week_list::removal()
{
    char del[20];
    cout << "Delete Calendar Event by Title: ";
    cin.get(del, 20);
    cin.ignore(100, '\n');

    return removal(Dhead, del);
}


// Remove an entry from in the LLL
int Week_list::removal(Dnode *& head, char del[])
{
    if(!head || !del)
    {
	cout << "Sorry! There are no Calendar Events matching the title name " << del << "." << endl;
	return 0;
    }
    int value = 0;
    value = head->Ddata.removal(del);

    if(value==1)
    {
	cout << del << ", was removed from your Calender." << endl;
	return 1;
    }return removal(head->get_Dnext(), del);
}


// Wrapper function to retrieve an entry
int Week_list::retrieval()
{
    char find[20];
    cout << endl << "Which Event would you like to find?" << endl;
    cout << endl << "[Title]: ";
    cin.get(find, 20);
    cin.ignore(100, '\n');
    return retrieval(Dhead, find);
}


// Retrieve an entry and the day of the week
int Week_list::retrieval(Dnode * head, char find[])
{
    int value = 0;
    if(!head)
    {
	cout << "Sorry! Unable to find Calendar Event " << find << "." << endl;
	return 0;
    }value = head->Ddata.retrieval(find);

    if(value == 1)
    {
	cout << "Found! " << head->get_weekday() << " ";
	return 1;
    }return retrieval(head->get_Dnext(), find);
}


// Wrapper function to display the DLL and LLL
int Week_list::display() const
{
    return display(Dhead);
}


// Display the events for the days of the week in the DLL & LLL
int Week_list::display(Dnode * head) const
{
    if(!head) return 0;

    cout << endl << head->get_weekday() << " " << endl;
    cout << "----------" << endl;
    head->Ddata.display();

    return display(head->get_Dnext()) + 1;
}
