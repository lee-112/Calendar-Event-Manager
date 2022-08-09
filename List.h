#include "Calendar.h"

// The purpose for this header file is to store the function prototypes
// defined in the class interfaces. The L node and Event list manager
// are responsible for storing and managing the LLL of daily events. The
// D node and Week list are responsible for managing and storing the DLL
// of weekly events.


#ifndef CALENDAR_LIST
#define CALENDAR_LIST


// Linear linked list node to store an Event
class Lnode
{
public:
    // Constructor and Destrucotrs
    Lnode();
    ~Lnode();

    // Member functions
    Lnode *& get_Lnext();
    Event *& get_Ldata();
    Event * Ldata;
private:
    // Data Member
    Lnode * Lnext;
};


// Manage a linear linked list of Events.
class Event_list
{
public:
    // Constructor and Destrucotrs
    Event_list();
    ~Event_list();

    // Member function
    int insert();
    int update();
    int retrieval(char []);
    int display() const;
    int removal(char []);
    int remove_all();

private:
    // Data Member
    Lnode * Lhead;
    // Member function
    int insert(Lnode *&, Event *);
    int update(Lnode *&, char []);
    int retrieval(Lnode *, char []);
    int display(Lnode *) const;
    int removal(Lnode *&, char []);
    int remove_all(Lnode *&);
};


// Double linked list node to store the days of the week
// along with a pointer to a linear linked list of Events.
class Dnode
{
public:
    // Constructor, Copy constructors, and Destrucotrs
    Dnode();
    Dnode(char *);
    Dnode(Dnode &);
    ~Dnode();

    // Member functions
    char *& get_weekday();
    Dnode *& get_Dnext();
    Dnode *& get_Dprev();
    Event_list Ddata;
private:
    // Data Members
    char * weekday;
    Dnode * Dnext;
    Dnode * Dprev;
};


// Manage a doubly linked list of nodes for the days of the week.
class Week_list
{
public:
    // Constructor and Destrucotrs
    Week_list();
    ~Week_list();

    // Member functions
    int insert();
    int update();
    int retrieval();
    int display() const;
    int removal();
    int remove_all();
private:
    // Data Members
    Dnode * Dhead;

    // Member functions
    int insert(Dnode *&, char []);
    int update(Dnode *&, char []);
    int retrieval(Dnode *, char []);
    int display(Dnode *) const;
    int removal(Dnode *&, char []);
    int remove_all(Dnode *&);
};
#endif
