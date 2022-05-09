#ifndef PASSENGER_CLASSES_H
#define PASSENGER_CLASSES_H
#include "person.h"
#include "price.h"
#include "date.h"
#include "ticket.h"
#include "city.h"

// class Passenger: public Person          //to jako klasa czysto wirtualna? zeby pasazerowie mogli byc tylko pierwszej/drugiej klasy a nie tylko pasazerowie
// {
//     private:   // <-- private bo nie chcemy zeby inne klasy to oddziedziczyly
//         Ticket ticket;    
//     public:
//         Passenger(std::string name, std::string surname, std::string pasel, const Ticket& ticket);
//         virtual ~Passenger();

//         Ticket getTicket() const;
//         void setTicket(const Ticket& ticket);   

//         virtual bool isExtraFood() const = 0;        
//         virtual bool isExtraArmachair() const = 0;
//         virtual bool isExtraPillows() const = 0;
//         virtual bool isWindowSeat() const = 0;

//         friend std::ostream &operator<<(std::ostream& out, const Passenger& Passenger);
// };


class FirstClass: public Person
{
private:
    FirstClassTicket ticket;
public:
    FirstClass(std::string name, std::string surname, std::string pasel,const FirstClassTicket& ticket);

    City getSourceCity() const;
    City getDestinationCity() const;

    FirstClassTicket getTicket() const;
    void setTicket(const FirstClassTicket& ticket);  
    
    bool isExtraFood() const;
    bool isExtraArmachair() const;
    bool isExtraPillows() const;
    bool isWindowSeat() const;

    friend std::ostream &operator<<(std::ostream& out, const FirstClass& Passenger);
    
    friend std::ostream &operator<<(std::ostream& out, const FirstClass& passager);

};


class SecondClass: public Person
{
private:
    SecondClassTicket ticket;
public:
    SecondClass(std::string name, std::string surname, std::string pasel,const SecondClassTicket& ticket);

    City getSourceCity() const;
    City getDestinationCity() const;

    SecondClassTicket getTicket() const;
    void setTicket(const SecondClassTicket& ticket);

    bool isExtraFood() const;
    bool isExtraArmachair() const;
    bool isExtraPillows() const;
    bool isWindowSeat() const;

    friend std::ostream &operator<<(std::ostream& out, const SecondClass& passager);
};

#endif