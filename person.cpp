#include "addressBook.h"

Person::Person(string first_name, string last_name)
{
    this->first_name = first_name;
    this->last_name = last_name;
}

string Person::get_first_name()
{
    return this->first_name;
}

string Person::get_last_name()
{
    return this->last_name;
}

string Person::get_address()
{
    return this->address;
}

string Person::get_city()
{
    return this->city;
}

string Person::get_state()
{
    return this->state;
}

string Person::get_zip()
{
    return this->zip;
}

string Person::get_phone_number()
{
    return this->phone_number;
}

void Person::set_address(string address)
{
    this->address = address;
}

void Person::set_city(string city)
{
    this->city = city;
}

void Person::set_state(string state)
{
    this->state = state;
}
void Person::set_zip(string zip)
{
    this->zip = zip;
}
void Person::set_phone_number(string phone_number)
{
    this->phone_number = phone_number;
}

string Person::to_string()
{
    return "\nFirst Name: " + this->first_name +
           "\tLast Name: " + this->last_name +
           "\nAddress: " + this->address +
           "\nCity: " + this->city +
           "\tState: " + this->state +
           "\tZip: " + this->zip +
           "\nPhone number: " + this->phone_number + "\n";
}
