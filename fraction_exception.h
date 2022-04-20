
#ifndef FRACTION_FRACTION_EXCEPTION_H
#define FRACTION_FRACTION_EXCEPTION_H

#include <exception>
class FractionException:std::exception
{
public:
    const char* what() const throw(){
        return "ZeroDivisionError";

    }
};

#endif //FRACTION_FRACTION_EXCEPTION_H


