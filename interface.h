#ifndef INTERFACE_H
#define INTERFACE_H
#include "data_base.h"

class Interface
{
    private:
        Data_base db();
    public:
        int menu();
        void addFirstClass();
        void addSecondClass();
        void removePassager();
        void peselOperations();
        void print();        
};

#endif