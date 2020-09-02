all:
	g++ person.cpp addressBook.cpp main.cpp -o AddressBookApplication.exe
	./AddressBookApplication.exe
	rm AddressBookApplication.exe