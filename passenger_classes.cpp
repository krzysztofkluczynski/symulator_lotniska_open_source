#include "passenger_classes.h"

using namespace std;


// Passenger::Passenger(std::string name, std::string surname, std::string pasel, const Ticket& p_ticket)
// : Person(name, surname, pesel), ticket(p_ticket) {}


// Passenger::~Passenger() {}

// Ticket Passenger::getTicket() const
// {
//     return ticket;
// }

// void Passenger::setTicket(const Ticket& p_ticket)
// {
//     ticket = p_ticket;
// }

// std::ostream &operator<<(std::ostream& out, const Passenger& passenger)
// {
//     out << "Passenger: " << passenger.getName() << " " << passenger.getSurname() << endl;
//     out << "PESEL: " << passenger.getPesel() << endl;
//     out << "FROM: " << passenger.getTicket().getSource().getName() << endl;
//     out << "TO: " << passenger.getTicket().getDestination().getName() << endl;
//     return out;
// }


//FirstClass::FirstClass(std::string p_name, std::string p_surname, std::string p_pesel, const FirstClassTicket& p_ticket)
//: name(p_name), surname(p_surname), pesel(p_pesel), ticket(p_ticket) {}

FirstClass::FirstClass(std::string name, std::string surname, std::string pesel, const FirstClassTicket& p_ticket)
: Person(name, surname, pesel), ticket(p_ticket) {}

City FirstClass::getSourceCity() const
{
    return ticket.getSource();
}
City FirstClass::getDestinationCity() const
{
    return ticket.getDestination();
}

FirstClassTicket FirstClass::getTicket() const
{
    return ticket;
}

void FirstClass::setTicket(const FirstClassTicket& p_ticket)
{
    ticket = p_ticket;
}

bool FirstClass::isExtraFood() const
{
    return true;
}

bool FirstClass::isExtraArmachair() const
{
    return true;
}

bool FirstClass::isExtraPillows() const
{
    return true;
}
bool FirstClass::isWindowSeat() const
{
    return true;
}

std::ostream &operator<<(std::ostream& out, const FirstClass& passenger)
{
    out << "First class passenger: " << passenger.getName() << " " << passenger.getSurname() << endl;
    out << "PESEL: " << passenger.getPesel() << endl;
    out << "FROM: " << passenger.getTicket().getSource().getName() << endl;
    out << "TO: " << passenger.getTicket().getDestination().getName() << endl;
    return out;
}

SecondClass::SecondClass(std::string name, std::string surname, std::string pasel, const SecondClassTicket& p_ticket)
: Person(name, surname, pesel), ticket(p_ticket) {}

City SecondClass::getSourceCity() const
{
    return ticket.getSource();
}

City SecondClass::getDestinationCity() const
{
    return ticket.getDestination();
}

SecondClassTicket SecondClass::getTicket() const
{
    return ticket;
}

void SecondClass::setTicket(const SecondClassTicket& p_ticket)
{
    ticket = p_ticket;
}
bool SecondClass::isExtraFood() const
{
    return false;
}

bool SecondClass::isExtraArmachair() const
{
    return false;
}

bool SecondClass::isExtraPillows() const
{
    return false;
}
bool SecondClass::isWindowSeat() const
{
    return false;
}

std::ostream &operator<<(std::ostream& out, const SecondClass& passenger)
{
    out << "Second class passenger: " << passenger.getName() << " " << passenger.getSurname() << endl;
    out << "PESEL: " << passenger.getPesel() << endl;
    out << "FROM: " << passenger.getTicket().getSource().getName() << endl;
    out << "TO: " << passenger.getTicket().getDestination().getName() << endl;
    return out;
}