#ifndef TICKET_H
#define TICKET_H

#include "city.h"
#include "price.h"
#include "date.h"

class Ticket   // <-- jakies male samoloty moga nie miec podzialu na pierwsza i druga klase dla pasazerow
{
protected:
    unsigned int number;
    City source;
    City destination; 
    Date date;
    Price base_price;  // <-- to by bylo wyliczane na podstawie kilometrow miedzy miastammi, a ta metoda nizej moglaby to wlasnie liczyc
    void calculateBasePrice(); 
public:
    Ticket(City source, City Destination, Date date);  // <-- ceny nie przyjmujemy w konstruktorze bo ja policzymy
    
    unsigned int getNumber() const;
    void setNumber(unsigned int);

    City getSource() const;
    void setSource(const City& city);

    City getDestination() const;
    void setDestination(const City& city);

    City getDate() const;
    void setDate(const City& city);

    virtual Price getRealPrice() const; 
};



class FirstClassTicket: public Ticket
{
public:
    FirstClassTicket(City source, City Destination, Date date);

    Price getRealPrice() const override; 
};




class SecondClassTicket: public Ticket
{
public:
    SecondClassTicket(City source, City Destination, Date date);

    Price getRealPrice() const override; 
};

#endif