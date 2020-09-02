all:
	g++ person.cpp address_book.cpp main.cpp -o Address_Book_Application.exe
	./Address_Book_Application.exe
	rm Address_Book_Application.exe