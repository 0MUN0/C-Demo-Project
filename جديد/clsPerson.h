#pragma onc
#include <iostream>

using namespace std ;

class clsPerson
{
    private:

    string _FirstName;
    string _LastName;
    string _Email;
    string _phone ;

    public:

    clsPerson(string FirstName,string LastName,string Email,string Phone)
    {
        _FirstName = FirstName ;
        _LastName = LastName ;
        _Email = Email ;
        _phone = Phone;
    }

    string FirstName()
    {
        return _FirstName ;
    }

    void setFirstName(string FirstName)
    {
        _FirstName =FirstName ;
    }


    string LastName()
    {
        return _LastName ;
    }


    void setLastName(string LastName)
    {
        _LastName =LastName ;
    }

    string Email()
    {
        return _Email ;
    }

    void setEmail(string Email)
    {
        _Email =Email ;
    }

    string Phone()
    {
        return _phone ;
    }

    void setPhone(string Phone)
    {
        _phone =Phone ;
    }




} ;
