#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>


class PeselException : public std::invalid_argument
{
    public:
        PeselException(std::string p_pesel);
};


class PassagerNotFound : public std::invalid_argument
{
    public: 
        PassagerNotFound();
};

class InvalidInput : public std::invalid_argument
{
    public: 
        InvalidInput();
};

class NegativePriceException : public std::invalid_argument
{
    public: 
        NegativePriceException();
};


#endif