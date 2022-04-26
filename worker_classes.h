#ifndef WORKER_CLASSES_H
#define WORKER_CLASSES_H

#include "person.h"
#include "price.h"

class Worker: public Person
{
    protected:
        Price salary;
    public:
        Worker(std::string name, std::string surname, std::string pesel, const Price& salary = Price(3000, 0)); //domyslna wyplata 
        ~Worker();

        Price getPrice() const;
        void setPrice(const Price& price);

        virtual Price calculatePrice() const;   // <-- to pewnie do wyrzucenia, w tej klasie i pochodnych tez

        virtual unsigned int passengersPerWorker() = 0;
};

class Stewardess: public Worker
{
    private:

    public:
        Stewardess(std::string name, std::string surname, std::string pesel, const Price& salary = Price(4000, 0));

        virtual Price calculatePrice() const override;

        virtual unsigned int passengersPerWorker() override;
};

class Pilot: public Worker
{
    private:

    public:
        Pilot(std::string name, std::string surname, std::string pesel, const Price& salary = Price(6000, 0));

        virtual Price calculatePrice() const override;

        virtual unsigned int passengersPerWorker() override;

};

class LuggageMan: public Worker
{
    private:

    public:
        LuggageMan(std::string name, std::string surname, std::string pesel, const Price& salary = Price(3500, 0));

        virtual Price calculatePrice() const override;

        virtual unsigned int passengersPerWorker() override;

};

class Other: public Worker
{
    private:

    public:
        Other(std::string name, std::string surname, std::string pesel, const Price& salary = Price(3000, 0));

        virtual Price calculatePrice() const override;

        virtual unsigned int passengersPerWorker() override;

};


#endif