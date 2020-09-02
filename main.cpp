#include "addressBook.h"

// int main()
// {
//     Person person1("Sudhanshu", "Ghinmine", "Keshava", "Selu", "Maha", "431503", "8551973494");
//     Person person2("Shashank", "Joshi", "Keshava", "Murtizapur", "Maha", "431225", "9822917991");
//     Person person3("Shashank", "Joshi", "Kokan", "Mahabal", "Maha", "431005", "9175927280");
//     Address_Book address_book;

//     cout << "Welcone to address book\n";

//     address_book.add_person(&person1);
//     address_book.add_person(&person2);
//     address_book.display_records();

//     address_book.edit_person("Sudhanshu", "Ghinmine");
//     address_book.display_records();

//     address_book.delete_person("Sudhanshu", "Ghinmine");
//     address_book.display_records();

//     address_book.edit_person("Sudhanshu", "Ghinmine");
//     address_book.add_person(&person3);

//     return 0;
// }

int main(int argc, char const *argv[])
{
    int choice;
    Address_Book address_book;
    while (true)
    {
        cout << "\nEnter your choice\n1. Add Person\n"
             << "2. Edit Person\n3. Delete Person\n4. Display\n"
             << "5. Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            // string first_name, last_name, address, city, state, zip, phone_number;
            // cout << "Enter Information to add\nEnter First Name: ";
            // cin >> first_name;
            // cout << "Enter Last Name: ";
            // cin >> last_name;
            // cout << "Enter Address: ";
            // cin >> address;
            // cout << "Enter City: ";
            // cin >> city;
            // cout << "Enter State: ";
            // cin >> state;
            // cout << "Enter Zip: ";
            // cin >> zip;
            // cout << "Enter Phone Number: ";
            // cin >> phone_number;
            // address_book.add_person(new Person(first_name, last_name,
            //                                    address, city,
            //                                    state, zip,
            //                                    phone_number));
            Person person1("Sudhanshu", "Ghinmine", "Keshava", "Selu", "Maha", "431503", "8551973494");
            Person person2("Shashank", "Joshi", "Keshava", "Murtizapur", "Maha", "431225", "9822917991");
            address_book.add_person(&person1);
            address_book.add_person(&person2);
            break;
        }
        case 2:
        {
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
            string first_name, last_name;
            cout << "Enter Information to Delete\nFirst Name: ";
            cin >> first_name;
            cout << "Last Name: ";
            cin >> last_name;
            address_book.delete_person(first_name, last_name);
        }
        case 4:
            address_book.display_records();
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
