#include <iostream>
#include <vector>

using namespace std;

class Person
{
    string first_name;
    string last_name;
    string address;
    string city;
    string state;
    string zip;
    string phone_number;

public:
    Person(string first_name, string last_name,
           string address, string city,
           string state, string zip, string phone_number)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->phone_number = phone_number;
    }

    string to_string()
    {
        return "\nFirst Name: " + this->first_name +
               "\tLast Name: " + this->last_name +
               "\nAddress: " + this->address +
               "\nCity: " + this->city +
               "\tState: " + this->state +
               "\tZip: " + this->zip +
               "\nPhone number: " + this->phone_number + "\n";
    }
};

class Address_Book
{
    vector<Person> address_book;

public:
    void add_person(Person &person)
    {
        address_book.push_back(person);
    }

    void display_records()
    {
        for (Person person : address_book)
            cout << person.to_string();
    }
};

int main(int argc, char const *argv[])
{
    Person person1("Sudhanshu", "Ghinmine", "Keshava", "Selu", "Maha", "431503", "8551973494");
    Person person2("Shashank", "Joshi", "Keshava", "Murtizapur", "Maha", "431225", "9822917991");
    Address_Book address_book;

    cout << "Welcone to address book\n";

    address_book.add_person(person1);
    address_book.add_person(person2);

    address_book.display_records();

    return 0;
}
