#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

//
// The purpose for this header file is to store the function prototypes
// defined in the Base and Derived classes. The Event class contains the
// virtual functions for its derived classes identical member functions
// The derived classes contain their own data members along with access
// to their Event base classes data members. This method allows for the
// derived class constructors to set and preform a deep copy of the Event
// base classes data members.


#ifndef CALENDAR_EVENTS
#define CALENDAR_EVENTS


// Base class
class Event
{
public:
    // Constructor, Copy constructor, Virtual deconstructor
    Event();
    Event(const Event &);
    virtual ~Event();

    // Virtual Member functions
    char *& get_title();
    virtual int insert();
    virtual int update();
    virtual int display() const;
    virtual int retrieval();

protected:
    // Data members
    char * time;
    char * title;
    char * location;
};


// Derived Class
class Appointment : public Event
{
public:
    // Constructor, Copy constructor, Deconstructor
    Appointment();
    Appointment(const Appointment &);
    Appointment(char *, char *, char *, char *, char *, char *);
    ~Appointment();

    // Member functions
    int insert();
    int retrieval();
    int update();
    int display() const;

protected:
    // Data Members
    char * phone;
    char * email;
    char * desc;
};


// Derived Class
class Reminder : public Event
{
public:
    // Constructor, Copy constructor, Deconstructor
    Reminder();
    Reminder(const Reminder &);
    Reminder(char *, char *, char *, char *, char *, char *);
    ~Reminder();

    // Member functions
    int insert();
    int retrieval();
    int update();
    int display() const;

protected:
    // Data Members
    char * end_date;
    char * end_time;
    char * info;
};


// Derived Class
class Work : public Event
{
public:
    // Constructor, Copy constructor, Deconstructor
    Work();
    Work(const Work &);
    Work(char *, char *, char *, char *, char *, char *);
    ~Work();

    // Member functions
    int insert();
    int retrieval();
    int update();
    int display() const;

protected:
    // Data Members
    char * ID;
    char * work_phone;
    char * work_email;
};
#endif
