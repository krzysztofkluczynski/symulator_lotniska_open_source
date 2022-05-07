#include "ticket.h"

using namespace std;

Ticket::Ticket(City p_source, City p_destination, Date p_date, unsigned int p_num)
: source(p_source), destination(p_destination), date(p_date), number(p_num)
{
    base_price = Price(50,0);    //TO ROBOCZA WERSJA DO ZMIANY Z TA CENA
                        //tutaj trzeba doliczyc ta odleglosc i podac cos do pola ceny
                        // numer jest po to zeby potem sprawdzac czy nie ma takich samych biletow, ale to bedzie sprawdzane gdzies wyzej
}

Ticket::~Ticket() {}


unsigned int Ticket::getNumber() const
{
    return number;
}

void Ticket::setNumber(unsigned int p_num)
{
    number = p_num;
}

City Ticket::getSource() const
{
    return source;
}
void Ticket::setSource(const City& p_city)
{
    source = p_city;
}

City Ticket::getDestination() const
{
    return destination;
}
void Ticket::setDestination(const City& p_city)
{
    destination = p_city;
}


Date Ticket::getDate() const
{
    return date;
}

void Ticket::setDate(const Date& p_date)
{
    date = p_date;
}

Price Ticket::getBasePrice() const
{
    return base_price;
}

FirstClassTicket::FirstClassTicket(City source, City destination, Date date, unsigned int num)
: Ticket(source, destination, date, num) {}

Price FirstClassTicket::getRealPrice() const
{

    return base_price * 1.5f;  //to tez trzeba bedzie zaokraglic zeby wychodzily w miare okej liczby
}

SecondClassTicket::SecondClassTicket(City source, City destination, Date date, unsigned int num)
: Ticket(source, destination, date, num) {}


Price SecondClassTicket::getRealPrice() const
{
    return base_price * 0.8f;       //to tak samo do zaaokraglenia
}

