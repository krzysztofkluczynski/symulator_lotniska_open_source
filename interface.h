#ifndef INTERFACE_H
#define INTERFACE_H
#include "data_base.h"

class Interface
{
    private:
        Data_base db();
    public:
        Interface(
        //Date date, <-- ta data tu bedzie ale do testow jej nie ma
        std::string people_path, 
        std::string workers_path, 
        std::string flights_path);
        int menu();
        void addFirstClass();
        void addSecondClass();
        void removePassager();
        void findByPesel();
        void printDay();
        void nextDay();

};

#endif