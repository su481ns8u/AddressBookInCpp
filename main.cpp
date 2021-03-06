#include "addressBook.h"

int main(int argc, char const *argv[])
{
    int choice;
    Address_Book address_book;
    system("clear");
    cout << "<-- Welcome to address book program -->";
    while (true)
    {
        cout << "\nEnter your choice\n1. Add Person\n"
             << "2. Edit Person\n3. Delete Person\n"
             << "4. Display\n5. Sort By Name\n"
             << "6. View by city AND state\n7. View By city OR state\n"
             << "8. Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("clear");
            string first_name, last_name, address, city, state, zip, phone_number;
            cout << "Enter Information to add\nEnter First Name: ";
            cin >> first_name;
            cout << "Enter Last Name: ";
            cin >> last_name;
            Person person(first_name, last_name);
            cout << "Enter Address: ";
            cin >> address;
            person.set_address(address);
            cout << "Enter City: ";
            cin >> city;
            person.set_city(city);
            cout << "Enter State: ";
            cin >> state;
            person.set_state(state);
            cout << "Enter Zip: ";
            cin >> zip;
            person.set_zip(zip);
            cout << "Enter Phone Number: ";
            cin >> phone_number;
            person.set_phone_number(phone_number);
            address_book.add_person(&person);
            break;
        }
        case 2:
        {
            system("clear");
            string first_name, last_name;
            cout << "Enter Information to Edit\nFirst Name: ";
            cin >> first_name;
            cout << "Last Name: ";
            cin >> last_name;
            address_book.edit_person(first_name, last_name);
            break;
        }
        case 3:
        {
            system("clear");
            string first_name, last_name;
            cout << "Enter Information to Delete\nFirst Name: ";
            cin >> first_name;
            cout << "Last Name: ";
            cin >> last_name;
            address_book.delete_person(first_name, last_name);
        }
        case 4:
            system("clear");
            address_book.display_records();
            break;
        case 5:
        {
            system("clear");
            int sort_param;
            cout << "\n\tEnter sort parameter\n\t1. Name"
                 << "\n\t2. City\n\t3. State"
                 << "\n\t4. Zip\n\tChoice:";
            cin >> sort_param;
            address_book.sort_by_param(sort_param);
            break;
        }
        case 6:
        {
            system("clear");
            string city, state;
            cout << "Enter city: ";
            cin >> city;
            cout << "Enter state: ";
            cin >> state;
            address_book.view_by_city_and_state(city, state);
            break;
        }
        case 7:
        {
            system("clear");
            string param;
            cout << "Enter city or state: ";
            cin >> param;
            address_book.view_by_city_or_state(param);
            break;
        }
        case 8:
            system("clear");
            return 0;
            break;
        default:
            cout << "\nInvalid choice !!!";
            break;
        }
    }
    return 0;
}