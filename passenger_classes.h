#ifndef PASSENGER_CLASSES_H
#define PASSENGER_CLASSES_H
#include "person.h"
#include "price.h"
#include "date.h"
#include "ticket.h"

class Passenger: public Person
{
    private:   // <-- private bo nie chcemy zeby inne klasy to oddziedziczyly
        Ticket ticket;    
    public:
        Passenger(std::string name, std::string surname, std::string pasel, const Ticket& ticket);
        virtual ~Passenger();

        Price getTicket() const;
        void setTicket(const Ticket& ticket);   

        virtual bool isExtraFood() const;        
        virtual bool isExtraArmachair() const;
        virtual bool isExtraPillows() const;
        virtual bool isWindowSeat() const;

        friend std::ostream &operator<<(std::ostream& out, const Passenger& Passenger);
};


class FirstClass: public Passenger
{
private:
    FirstClassTicket ticket;
public:
    FirstClass(std::string name, std::string surname, std::string pasel,const FirstClassTicket& ticket);
    
    


    bool isExtraFood() const override;
    bool isExtraArmachair() const override;
    bool isExtraPillows() const override;
    bool isWindowSeat() const override;
    
    friend std::ostream &operator<<(std::ostream& out, const FirstClass& passager);

};


class SecondClass: public Passenger
{
private:
    SecondClassTicket ticket;
public:
    SecondClass(const Person& p_person,const SecondClassTicket& ticket);

    bool isExtraFood() const override;
    bool isExtraArmachair() const override;
    bool isExtraPillows() const override;
    bool isWindowSeat() const override;

    friend std::ostream &operator<<(std::ostream& out, const SecondClass& passager);
};

#endif