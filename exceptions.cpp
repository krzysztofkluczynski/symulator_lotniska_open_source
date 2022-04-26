#include "exceptions.h"

InvalidInput::InvalidInput():
std::invalid_argument("invalid input"){}

PassagerNotFound::PassagerNotFound():
std::invalid_argument("Passager not found"){}

PeselException::PeselException(std::string p_pesel):
std::invalid_argument("Invalid pesel input: " + p_pesel) {}

NegativePriceException::NegativePriceException():
std::invalid_argument("Negative value of the base price"){}
