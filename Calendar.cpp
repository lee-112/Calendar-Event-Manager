#include "Calendar.h"

// The purpose of this file is to implement the function prototypes
// defined for the Base and Derived classes. The code in this file
// uses dynamic binding with upcasting to allow for the Base class
// to have access to its Derived class member functions using the
// scope resolution opperator to allow for functionality.


//===============================================================//
// Event [Base Class]
//===============================================================//


// Constructor
Event::Event()
: time(NULL), title(NULL), location(NULL) {}


// Copy Constructor
Event::Event(const Event & source)
{
    time = new char[strlen(source.time) + 1];
    title = new char[strlen(source.title) + 1];
    location = new char[strlen(source.location) + 1];

    strcpy(time, source.time);
    strcpy(title, source.title);
    strcpy(location, source.location);
}


// Destructor
Event::~Event()
{
    if(time)
	delete [] time;
    if(title)
	delete [] title;
    if(location)
	delete [] location;
    time = title = location = NULL;
}


// Return Title
char *& Event::get_title()
{
    return title;
}


// Create a new Event
int Event::insert()
{
    char atime[20];
    char atitle[20];
    char alocation[20];

    cout << endl << "Event Title: ";
    cin.get(atitle, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    cout << "Event Time: ";
    cin.get(atime, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    cout << "Event Location: ";
    cin.get(alocation, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    if(time)
	delete [] time;
    time = NULL;
    time = new char[strlen(atime) + 1];
    strcpy(time, atime);

    if(title)
	delete [] title;
    title = NULL;
    title = new char[strlen(atitle) + 1];
    strcpy(title, atitle);

    if(location)
	delete [] location;
    location = NULL;
    location = new char[strlen(alocation) + 1];
    strcpy(location, alocation);

    return 1;
}

// Update the data members for Event class
int Event::update()
{
    int updated = 0;
    bool valid = true;

    while(valid)
    {
	cout << "'Update Event'"	   << endl;
	cout << "-------------------------"<< endl;
	cout << "0. Return"		   << endl;
	cout << "1. Updated Event Title"   << endl;
	cout << "2. Updated Event Time"	   << endl;
	cout << "3. Updated Event Location"<< endl;
	cout << "-------------------------"<< endl;
	cout << "#: ";
	cin >> updated;
	cin.ignore(100, '\n');

	switch(updated)
	{
	    case 0: valid = false;
	    break;
	    case 1:
	    {
		char a_phone[20];
		cout << endl << "Updated Title: ";
		cin.get(a_phone, 20);
		cin.ignore(100, '\n');

		if(title)
		    delete [] title;
		title = NULL;
		title = new char[strlen(a_phone) + 1];
		strcpy(title, a_phone);
	    }break;
	    case 2:
	    {
		char a_email[20];
		cout << endl << "Updated Time: ";
		cin.get(a_email, 20);
		cin.ignore(100, '\n');

		if(time)
		    delete [] time;
		time = NULL;
		time = new char[strlen(a_email) + 1];
		strcpy(time, a_email);
	    }break;
	    case 3:
	    {
		char a_desc[20];
		cout << endl << "Updated Location." << endl;
		cin.get(a_desc, 20);
		cin.ignore(100, '\n');

		if(location)
		    delete [] location;
		location = NULL;
		location = new char[strlen(a_desc) + 1];
		strcpy(location, a_desc);
	    }break;
	    default: cout << endl << "Invalid Number!" << endl << endl;
	}
    }return 1;
}


// Display the data members
int Event::display() const
{
    if(title)
	cout << endl << title << endl;
    if(time)
	cout << "Event Time: " << time << endl;
    if(location)
	cout << "Event Location: " << location << endl;
    return 1;
}


// Wrapper function to retrieve a data member
int Event::retrieval()
{
    return display();
}


//===============================================================//
// Appointment [Derived Class]
//===============================================================//


// Constructor
Appointment::Appointment()
: phone(NULL), email(NULL), desc(NULL) {}


// Copy Constructor
Appointment::Appointment(const Appointment & source)
: Event(source)
{
    phone = new char[strlen(source.phone) + 1];
    email = new char[strlen(source.email) + 1];
    desc = new char[strlen(source.desc) + 1];

    strcpy(phone, source.phone);
    strcpy(email, source.email);
    strcpy(desc, source.desc);
}


// Constructor with arguments
Appointment::Appointment(char * source_time, char * source_title, char * source_location,
char * source_phone, char * source_email, char * source_desc)
{
    time = new char[strlen(source_time) + 1];
    title = new char[strlen(source_title) + 1];
    location = new char[strlen(source_location) + 1];
    phone = new char[strlen(source_phone) + 1];
    email = new char[strlen(source_email) + 1];
    desc = new char[strlen(source_desc) + 1];

    strcpy(time, source_time);
    strcpy(title, source_title);
    strcpy(location, source_location);
    strcpy(phone, source_phone);
    strcpy(email, source_email);
    strcpy(desc, source_desc);
}


// Destructor
Appointment::~Appointment()
{
    if(phone)
	delete [] phone;
    if(email)
	delete [] email;
    if(desc)
	delete [] desc;

    phone = email = desc = NULL;
}


// Insert Appointment Data
int Appointment::insert()
{
    Event::insert();
    char a_phone[20];
    char a_email[20];
    char a_desc[200];

    cout << "Enter a Phone Number: ";
    cin.get(a_phone, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    cout << "Enter an E-Mail Address: ";
    cin.get(a_email, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    cout << "Description of Appointment." << endl;
    cin.get(a_desc, 200);
    cin.ignore(100, '\n');
    cout << "" << endl;

    if(phone)
	delete [] phone;
    phone = NULL;
    phone = new char[strlen(a_phone) + 1];
    strcpy(phone, a_phone);

    if(email)
	delete [] email;
    email = NULL;
    email = new char[strlen(a_email) + 1];
    strcpy(email, a_email);

    if(desc)
	delete [] desc;
    desc = NULL;
    desc = new char[strlen(a_desc) + 1];
    strcpy(desc, a_desc);

    return 1;
}


// Update Appointment Data
int Appointment::update()
{
    Event::update();
    int updated = 0;
    bool valid = true;

    while(valid)
    {
	cout << "'Update Appointment Event'"	     << endl;
	cout << "----------------------------------"<< endl;
	cout << "0. Return"			    << endl;
	cout << "1. Updated Phone Number"	    << endl;
	cout << "2. Updated E-Mail Address"	    << endl;
	cout << "3. Updated Appointment Description"<< endl;
	cout << "----------------------------------"<< endl;
	cout << "#: ";
	cin >> updated;
	cin.ignore(100, '\n');

	switch(updated)
	{
	    case 0: valid = false;
	    break;
	    case 1:
	    {
		char a_phone[20];
		cout << endl << "Updated Number: ";
		cin.get(a_phone, 20);
		cin.ignore(100, '\n');

		if(phone)
		    delete [] phone;
		phone = NULL;
		phone = new char[strlen(a_phone) + 1];
		strcpy(phone, a_phone);
	    }break;
	    case 2:
	    {
		char a_email[20];
		cout << endl << "Updated E-Mail: ";
		cin.get(a_email, 20);
		cin.ignore(100, '\n');

		if(email)
		    delete [] email;
		email = NULL;
		email = new char[strlen(a_email) + 1];
		strcpy(email, a_email);
	    }break;
	    case 3:
	    {
		char a_desc[200];
		cout << endl << "Updated Description." << endl;
		cin.get(a_desc, 200);
		cin.ignore(100, '\n');

		if(desc)
		    delete [] desc;
		desc = NULL;
		desc = new char[strlen(a_desc) + 1];
		strcpy(desc, a_desc);
	    }break;
	    default: cout << endl << "Invalid Number!" << endl << endl;
	}
    }return 1;
}


// Display Appointment Data
int Appointment::display() const
{
    Event::display();
    if(phone)
	cout << "Phone #: " << phone << endl;
    if(email)
	cout << "E-Mail: " << email << endl;
    if(desc)
    {
	cout << "Description: " << endl;
	cout << desc << endl;
    }return 1;
}

// Wrapper function to retrieve data members
int Appointment::retrieval()
{
    return Event::retrieval();
}


//===============================================================//
// Reminder [Derived Class]
//===============================================================//


// Constructor
Reminder::Reminder()
: end_date(NULL), end_time(NULL), info(NULL) {}


// Copy Constructor
Reminder::Reminder(const Reminder & source)
: Event(source)
{
    end_date = new char[strlen(source.end_date) + 1];
    end_time = new char[strlen(source.end_time) + 1];
    info = new char[strlen(source.info) + 1];

    strcpy(end_date, source.end_date);
    strcpy(end_time, source.end_time);
    strcpy(info, source.info);
}


// Constructor with arguments
Reminder::Reminder(char * source_time, char * source_title, char * source_location,
char * source_enddate, char * source_endtime, char * source_info)
{
    time = new char[strlen(source_time) + 1];
    title = new char[strlen(source_title) + 1];
    location = new char[strlen(source_location) + 1];
    end_date = new char[strlen(source_enddate) + 1];
    end_time = new char[strlen(source_endtime) + 1];
    info = new char[strlen(source_info) + 1];

    strcpy(time, source_time);
    strcpy(title, source_title);
    strcpy(location, source_location);
    strcpy(end_date, source_enddate);
    strcpy(end_time, source_endtime);
    strcpy(info, source_info);
}


// Destructor
Reminder::~Reminder()
{
    if(end_date)
	delete [] end_date;
    if(end_time)
	delete [] end_time;
    if(info)
	delete [] info;
    end_date = end_time = info = NULL;
}


// Insert Reminder Data
int Reminder::insert()
{
    Event::insert();
    char a_date[20];
    char a_time[20];
    char a_info[200];

    cout << "Enter an Due Date: ";
    cin.get(a_date, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    cout << "Enter an End Time: ";
    cin.get(a_time, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    cout << "Reminder Information." << endl;
    cin.get(a_info, 200);
    cin.ignore(100, '\n');
    cout << "" << endl;

    if(end_date)
	delete [] end_date;
    end_date = NULL;
    end_date = new char[strlen(a_date) + 1];
    strcpy(end_date, a_date);

    if(end_time)
	delete [] end_time;
    end_time = NULL;
    end_time = new char[strlen(a_time) + 1];
    strcpy(end_time, a_time);

    if(info)
	delete [] info;
    info = NULL;
    info = new char[strlen(a_info) + 1];
    strcpy(info, a_info);

    return 1;
}


// Update Reminder Data
int Reminder::update()
{
    Event::update();
    int updated = 0;
    bool valid = true;

    while(valid)
    {
	cout << "'Update Reminder Event'"   	<< endl;
	cout << "------------------------------"<< endl;
	cout << "0. Return"			<< endl;
	cout << "1. Updated Due Date"		<< endl;
	cout << "2. Updated End Time"		<< endl;
	cout << "3. Update Reminder Information"<< endl;
	cout << "------------------------------"<< endl;
	cout << "#: ";
	cin >> updated;
	cin.ignore(100, '\n');

	switch(updated)
	{
	    case 0: valid = false;
	    break;
	    case 1:
	    {
		char a_date[20];
		cout << "Updated Due Date: ";
		cin.get(a_date, 20);
		cin.ignore(100, '\n');
		cout << "" << endl;

		if(end_date)
		    delete [] end_date;
		end_date = NULL;
		end_date = new char[strlen(a_date) + 1];
		strcpy(end_date, a_date);
	    }break;
	    case 2:
	    {
		char a_time[20];
		cout << "Updated End Time: ";
		cin.get(a_time, 20);
		cin.ignore(100, '\n');
		cout << "" << endl;

		if(end_time)
		    delete [] end_time;
		end_time = NULL;
		end_time = new char[strlen(a_time) + 1];
		strcpy(end_time, a_time);
	    }break;
	    case 3:
	    {
		char a_info[200];
		cout << "Updated Information." << endl;
		cin.get(a_info, 200);
		cin.ignore(100, '\n');
		cout << "" << endl;

		if(info)
		    delete [] info;
		info = NULL;
		info = new char[strlen(a_info) + 1];
		strcpy(info, a_info);
	    }break;
	    default: cout << endl << "Invalid Number!" << endl << endl;
	}
    }return 1;
}


// Display Reminder Data
int Reminder::display() const
{
    Event::display();
    if(end_date)
	cout << "End Date: " << end_date << endl;
    if(end_time)
	cout << "End Time: " << end_time << endl;
    if(info)
    {
	cout << "Info: " << endl;
	cout << info << endl;
    }return 1;
}


// Wrapper function to retrieve data members
int Reminder::retrieval()
{
    return Event::retrieval();
}


//===============================================================//
// Work [Derived Class]
//===============================================================//


// Constructor
Work::Work()
: ID(NULL), work_phone(NULL), work_email(NULL) {}

// Copy Constructor
Work::Work(const Work & source)
: Event(source)
{
    ID = new char[strlen(source.ID) + 1];
    work_phone = new char[strlen(source.work_phone) + 1];
    work_email = new char[strlen(source.work_email) + 1];

    strcpy(ID, source.ID);
    strcpy(work_phone, source.work_phone);
    strcpy(work_email, source.work_email);
}


// Constructor with arguments
Work::Work(char * source_time, char * source_title, char * source_location,
char * source_ID, char * source_phone, char * source_email)
{
    time = new char[strlen(source_time) + 1];
    title = new char[strlen(source_title) + 1];
    location = new char[strlen(source_location) + 1];
    ID = new char[strlen(source_ID) + 1];
    work_phone = new char[strlen(source_phone) + 1];
    work_email = new char[strlen(source_email) + 1];

    strcpy(time, source_time);
    strcpy(title, source_title);
    strcpy(location, source_location);
    strcpy(ID, source_ID);
    strcpy(work_phone, source_phone);
    strcpy(work_email, source_email);
}


// Destructor
Work::~Work()
{
    if(ID)
	delete [] ID;
    if(work_phone)
	delete [] work_phone;
    if(work_email)
	delete [] work_email;
    ID = work_phone = work_email = NULL;
}


// Insert Work data
int Work::insert()
{
    Event::insert();
    char a_ID[20];
    char a_phone[20];
    char a_email[20];

    cout << "Enter Work ID Number: ";
    cin.get(a_ID, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    cout << "Enter Work Number: ";
    cin.get(a_phone, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    cout << "Enter Work E-mail: ";
    cin.get(a_email, 20);
    cin.ignore(100, '\n');
    cout << "" << endl;

    if(ID)
	delete [] ID;
    ID = NULL;
    ID = new char[strlen(a_ID) + 1];
    strcpy(ID, a_ID);

    if(work_phone)
	delete [] work_phone;
    work_phone = NULL;
    work_phone = new char[strlen(a_phone) + 1];
    strcpy(work_phone, a_phone);

    if(work_email)
	delete [] work_email;
    work_email = NULL;
    work_email = new char[strlen(a_email) + 1];
    strcpy(work_email, a_email);

    return 1;
}


// Update work data
int Work::update()
{
    Event::update();
    int updated = 0;
    bool valid = true;

    while(valid)
    {
	cout << "'Update Work Event'"		<< endl;
	cout << "-----------------------------" << endl;
	cout << "0. Return"			<< endl;
	cout << "1. Updated Work ID Number"	<< endl;
	cout << "2. Updated Work Line Number"	<< endl;
	cout << "3. Updated Work E-Mail Address" << endl;
	cout << "-----------------------------" << endl;
	cout << "#: ";
	cin >> updated;
	cin.ignore(100, '\n');

	switch(updated)
	{
	    case 0: valid = false;
	    break;
	    case 1:
	    {
		char a_ID[20];
		cout << "Updated ID Number: ";
		cin.get(a_ID, 20);
		cin.ignore(100, '\n');
		cout << "" << endl;

		if(ID)
		    delete [] ID;
		ID = NULL;
		ID = new char[strlen(a_ID) + 1];
		strcpy(ID, a_ID);
	    }break;
	    case 2:
	    {
		char a_phone[20];
		cout << "Updated Work Number: ";
		cin.get(a_phone, 20);
		cin.ignore(100, '\n');
		cout << "" << endl;

		if(work_phone)
		    delete [] work_phone;
		work_phone = NULL;
		work_phone = new char[strlen(a_phone) + 1];
		strcpy(work_phone, a_phone);
	    }break;
	    case 3:
	    {
		char a_email[20];
		cout << "Updated Work Email: ";
		cin.get(a_email, 20);
		cin.ignore(100, '\n');
		cout << "" << endl;

		if(work_email)
		    delete [] work_email;
		work_email = NULL;
		work_email = new char[strlen(a_email) + 1];
		strcpy(work_email, a_email);
	    }break;
	    default: cout << endl << "Invalid Number!" << endl << endl;
	}
    }return 1;
}


// Display Work data
int Work::display() const
{
    Event::display();
    if(ID)
	cout << "Work ID #: " << ID << endl;
    if(work_phone)
	cout << "Work Line #: " << work_phone << endl;
    if(work_email)
	cout << "Work E-Mail: " << work_email << endl;
    return 1;
}


// Wrapper function to retrieve data members
int Work::retrieval()
{
    return Event::retrieval();
}
