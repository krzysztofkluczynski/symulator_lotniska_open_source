#ifndef INTERFACE_H
#define INTERFACE_H
#include "data_base.h"

class Interface
{
    private:
        Data_base db;
        Date stop_date;
        Date current_date;
    public:
        Interface(
        Data_base db,
        Date current_date = Date(1, 5, 2022),
        Date stop_date = Date(7, 5, 2020));

        Date getStopDate() const;
        Date getCurrentDate() const;

        int menu();
        void addFirstClass();
        void addSecondClass();
        void printFlights();
        void findByPesel();
        void nextDay();

};

#endif