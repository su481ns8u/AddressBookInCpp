#include "addressBook.h"

Address_Book address_book;
void add_person()
{
    system("clear");
    string first_name, last_name, address, city, state, zip, phone_number;
    cout << "Enter Information to add\nEnter First Name: ";
    cin >> first_name;
    cout << "Enter Last Name: ";
    Person person(first_name, last_name);
    if (!address_book.check_present(&person))
    {
        cin >> last_name;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter City: ";
        cin >> city;
        cout << "Enter State: ";
        cin >> state;
        cout << "Enter Zip: ";
        cin >> zip;
        cout << "Enter Phone Number: ";
        cin >> phone_number;
        person.set_address_and_phone(address, phone_number);
        person.set_location(city, state, zip);
        address_book.add_person(&person);
    }
    else
    {
        cout << "Person already exists !!!";
    }
}

void edit_person()
{
    system("clear");
    string first_name, last_name;
    cout << "Enter Information to Edit\nFirst Name: ";
    cin >> first_name;
    cout << "Last Name: ";
    cin >> last_name;
    address_book.edit_person(first_name, last_name);
}

void delete_person() {
    system("clear");
    string first_name, last_name;
    cout << "Enter Information to Delete\nFirst Name: ";
    cin >> first_name;
    cout << "Last Name: ";
    cin >> last_name;
    address_book.delete_person(first_name, last_name);
}

void sort_records() {
    system("clear");
    int sort_param;
    cout << "\n\tEnter sort parameter\n\t1. Name"
         << "\n\t2. City\n\t3. State"
         << "\n\t4. Zip\n\tChoice:";
    cin >> sort_param;
    address_book.sort_by_param(sort_param);
}

void view_by_city_and_state() {
    system("clear");
    string city, state;
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter state: ";
    cin >> state;
    address_book.view_by_city_and_state(city, state);
}

void view_by_city_or_state() {
    system("clear");
    string param;
    cout << "Enter city or state: ";
    cin >> param;
    address_book.view_by_city_or_state(param);
}

int main(int argc, char const *argv[])
{
    int choice;
    while (true)
    {
        cout << "\nEnter your choice\n1. Add Person\n"
             << "2. Edit Person\n3. Delete Person\n"
             << "4. Display\n5. Sort By Parameter\n"
             << "6. View by city AND state\n7. View By city OR state\n"
             << "8. Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_person();
            break;
        case 2:
            edit_person();
            break;
        case 3:
            delete_person();
            break;
        case 4:
            system("clear");
            address_book.display_records();
            break;
        case 5:
            sort_records();
            break;
        case 6:
            view_by_city_and_state();
            break;
        case 7:
        {
            view_by_city_or_state();
            break;
        }
        case 8:
            system("clear");
            exit(0);
            break;
        default:
            cout << "\nInvalid choice !!!";
            break;
        }
    }
    return 0;
}