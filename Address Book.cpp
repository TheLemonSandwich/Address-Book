#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Name
{
	string firstname;
	string lastname;
};

struct DateOfBirth
{
	int date;
	int month;
	int year;
};

struct Address
{
	string street_address;
	string city;
	string province;
	int zip;
};

struct node
{
	Name name;
	Address add;
	string gender;
	string phonenumber;
	DateOfBirth dob;
	string Classify;
};

class AddressBook
{
public:
	AddressBook()
	{
		size = 150;
		counter = 0;
		n = new node[size];
		Filling();
	}
	void Insert();
	void Update(string fname,string lname);
	void Delete(string fname, string lname);
	void Classify(string fname, string lname);
	void Search(string lname);
	void MonthDisplay(int month);
	void DisplayAll();
	void SameGender(string gender);
	void DisplayByStatus(string classify);
	void BetweenDates(int, int, int, int, int, int);
private:
	int size;
	int counter;
	node* n;
	void Filling();
	void SizeIncrease();
};

int main()
{
	ofstream file("Address Book.txt", ios::out | ios::app);
	file.close();
	AddressBook add;
	string firstname,lastname;
	int month;
	int date1, date2;
	int month1, month2;
	int year1, year2;
	string classify;
	string gender;
	char op;
	do
	{
		system("cls");
		cout << "1. Insert an entry\n\n"
			<< "2. Update an entry\n\n"
			<< "3. Delete an entry\n\n"
			<< "4. Classify an entry\n\n"
			<< "5. Search by Last Name\n\n"
			<< "6. Display\n\n"
			<< "Press Any Other Button And Press Enter To Exit\n\n"
			<< "Choose: ";
		cin >> op;
		system("cls");
		switch (op)
		{
		case '1':
			add.Insert();
			break;
		case '2':
			cout << "First Name: ";
			cin >> firstname;
			cout << "Last Name: ";
			cin >> lastname;
			add.Update(firstname, lastname);
			cout << endl;
			system("pause");
			break;
		case '3':
			cout << "First Name: ";
			cin >> firstname;
			cout << "Last Name: ";
			cin >> lastname;
			add.Delete(firstname, lastname);
			cout << endl;
			system("pause");
			break;

		case '4':
			cout << "First Name: ";
			cin >> firstname;
			cout << "Last Name: ";
			cin >> lastname;
			add.Classify(firstname, lastname);
			cout << endl;
			system("pause");
			break;

		case '5':
			cout << "Last Name: ";
			cin >> lastname;
			add.Search(lastname);
			cout << endl;
			system("pause");
			break;

		case '6':
			cout << "1. By Month\n\n"
				<< "2. Between Two Dates\n\n"
				<< "3. By Classification\n\n"
				<< "4. Same Gender\n\n"
				<< "5. Display All\n\n"
				<< "Choose: ";
			cin >> op;
			cout << endl << endl;
			switch (op)
			{
			case '1':
				cout << "Month (Numeric Value): ";
				cin >> month;
				add.MonthDisplay(month);
				system("pause");
				break;
			case '2':
				cout << "Starting Date Of Birth:-\n"
					<< "Date: ";
				cin >> date1;
				cout << "Month: ";
				cin >> month1;
				cout << "Year: ";
				cin >> year1;
				cout << "\nEnding Date Of Birth:-\n"
					<< "Date: ";
				cin >> date2;
				cout << "Month: ";
				cin >> month2;
				cout << "Year: ";
				cin >> year2;
				add.BetweenDates(date1, month1, year1, date2, month2, year2);
				system("pause");
				break;
			case '3':
				cout << "Classification: ";
				cin >> classify;
				add.DisplayByStatus(classify);
				system("pause");
				break;
			case '4':
				cout << "Gender (M/F): ";
				cin >> gender;
				add.SameGender(gender);
				system("pause");
				break;
			case '5':
				cout << "Displaying All:-\n\n";
				add.DisplayAll();
				system("pause");
				break;
			default:
				cout << "Returning Back To Main Menu\n\n";
			}
			cout << endl;
			system("pause");
			break;
		default:
			cout << "Exiting Program\n";
			system("pause");
			exit(1);
		}
	} while (true);
}

void AddressBook::Insert()
{
	if (counter >= 500)
		cout << "You Cannot Enter More Entries\n";
	else
	{
		cout << "First Name: ";
		cin >> (n+counter)->name.firstname;
		cout << "Last Name: ";
		cin >> (n+counter)->name.lastname;
		cout << "Gender (M/F): ";
		cin >> (n+counter)->gender;
		cout << "Date Of Birth:- (Write In Numbers)\n";
		cout << "\nDate: ";
		cin >> (n + counter)->dob.date;
		cout << "Month: ";
		cin >> (n + counter)->dob.month;
		cout << "Year: ";
		cin >> (n + counter)->dob.year;
		cout << "Address:-\n";
		cout << "\nStreet Address (Numeric) : ";
		cin.ignore();
		getline(cin,(n+counter)->add.street_address);
		cout << "City: ";
		cin >> (n+counter)->add.city;
		cout << "Province: ";
		cin >> (n+counter)->add.province;
		cout << "Zip Code: ";
		cin >> (n+counter)->add.zip;
		cout << "Phone Number: ";
		cin >> (n+counter)->phonenumber;
		(n+counter)->Classify = "None";
		
		//		Adding In Address Book

		ofstream Book("Address Book.txt");
		Book << "Entry " << counter + 1 << ":-\n\n";
		Book << "Name:- \n";
		Book << "First Name: " << (n + counter)->name.firstname << endl;
		Book << "Last Name: " << (n + counter)->name.lastname << endl;
		Book << "Gender: " << (n + counter)->gender << endl;
		Book << "Phone Number: " << (n + counter)->phonenumber << endl;
		Book << "Address:-\n";
		Book << "Street Address: " << (n + counter)->add.street_address << endl;
		Book << "City: " << (n + counter)->add.city << endl;
		Book << "Province: " << (n + counter)->add.province << endl;
		Book << "Zip Code: " << (n + counter)->add.zip << endl;
		Book << "Date Of Birth:-\n";
		Book << "Date: " << (n + counter)->dob.date << endl;
		Book << "Month: " << (n + counter)->dob.month << endl;
		Book << "Year: " << (n + counter)->dob.year << endl;
		Book << "Classification: None\n\n";
		Book.close();
		counter++;
		if (counter <= 500)
		{
			if (counter >= size)
				SizeIncrease();
		}
		else
			cout << "You Cannot Enter More Entries\n";
	}
	system("pause");
}

void AddressBook::Filling()
{
	int search, search2;
	string line;
	ifstream Transfer("Address Book.txt");
	getline(Transfer, line);

	if (line == "" || line.length() == 0 || line == "\0")
		return;
	else
	{
		if (search = line.find("Fist Name: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->name.firstname;
		}
	}
	while(!Transfer.eof())
	{
		getline(Transfer, line);
		if (search = line.find("Fist Name: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->name.firstname = line.substr(search,line.length());
		}
		else if (search = line.find("Last Name: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->name.lastname = line.substr(search, line.length());
		}
		else if (search = line.find("Gender: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->gender = line.substr(search, line.length());
		}
		else if (search = line.find("Phone Number: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->phonenumber = line.substr(search, line.length());
		}
		else if (search = line.find("Street Address: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->add.street_address = line.substr(search, line.length());
		}
		else if (search = line.find("City: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->add.city = line.substr(search, line.length());
		}
		else if (search = line.find("Province: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->add.province = line.substr(search, line.length());
		}
		else if (search = line.find("Zip Code: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->add.zip = stoi(line.substr(search, line.length()));
		}
		else if (search = line.find("Date: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->dob.date = stoi(line.substr(search, line.length()));
		}
		else if (search = line.find("Month: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->dob.month = stoi(line.substr(search, line.length()));
		}
		else if (search = line.find("Year: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->dob.year = stoi(line.substr(search, line.length()));
		}
		else if (search = line.find("Classification: ") != string::npos)
		{
			search = line.find(": ");
			search += 2;
			(n + counter)->Classify = line.substr(search, line.length());
			counter++;
		}
	}
	Transfer.close();
}

void AddressBook::SizeIncrease()
{
	node* temp = new node[size * 2];
	for (int i = 0; i < size; i++)
		*(temp + i) = *(n + i);
	n = temp;
	size *= 2;
}

void AddressBook::Update(string fname, string lname)
{
	bool exist = false;
	bool namechange = false;
	bool phonechange = false;
	bool addresschange = false;
	bool dobchange = false;
	string phonenumber;
	int zip;
	string firstname, lastname;
	string street, city, province;
	int date, month, year;
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		char op;
		for (int i = 0; i < counter; i++)
		{
			if((n+i)->name.firstname == fname)
				if ((n+i)->name.lastname == lname)
				{
					exist = true;
					cout << "Choose the Option To Update:-\n\n";
					cout << "1. Name\n"
						<< "2. Address\n"
						<< "3. Phone Number\n"
						<< "4. Date Of Birth\n\n"
						<< "Choose: ";
					cin >> op;
					switch (op)
					{
					case '1':
						namechange = true;
						cout << "Old Name: " << (n + i)->name.firstname << " " << (n + i)->name.lastname << endl;
						cout << "New Name:-\n ";
						cout << "\nFirst Name: ";
						cin >> (n + i)->name.firstname;
						firstname = (n + i)->name.firstname;
						cout << "Last Name: ";
						cin >> (n + i)->name.lastname;
						lastname = (n + i)->name.lastname;
						cout << "Name Updated!\n";
						break;
					case '2':
						addresschange = true;
						cout << "Old Address: " << (n + i)->add.street_address << " " << (n + i)->add.city << "," << (n + i)->add.province
							<< ", " << (n + i)->add.zip << endl;
						cout << "New Address:- \n";
						cout << "\nStreet Address: ";
						cin.ignore();
						getline(cin, (n + i)->add.street_address);
						street = (n + i)->add.street_address;
						cout << "City: ";
						cin >> (n + i)->add.city;
						city = (n + i)->add.city;
						cout << "Province: ";
						cin >> (n + i)->add.province;
						province = (n + i)->add.province;
						cout << "Zip Code: ";
						cin >> (n + i)->add.zip;
						zip = (n + i)->add.zip;
						cout << "Address Updated!\n";
						break;
					case '3':
						phonechange = true;
						cout << "Old Phone Number: " << (n + i)->phonenumber << endl;
						cout << "New Phone Number: ";
						cin >> (n + i)->phonenumber;
						phonenumber = (n + i)->phonenumber;
						break;
					case '4':
						dobchange = true;
						cout << "Old Date Of Birth: " << (n + i)->dob.date << "/" << (n + i)->dob.month << "/" << (n + i)->dob.year << endl;
						cout << "New Date Of Birth: \n";
						cout << "\nDate: ";
						cin >> (n + i)->dob.date;
						date = (n + i)->dob.date;
						cout << "Month: ";
						cin >> (n + i)->dob.month;
						month = (n + i)->dob.month;
						cout << "Year: ";
						cin >> (n + i)->dob.year;
						year = (n + i)->dob.year;
						cout << "Date Of Birth Updated!\n";
						break;

					default:
						cout << "Returning To Main Menu\n";
					}

				}
		}

	}
	if (exist)
	{
		bool done = false;
		string line;
		int search;
		ifstream info("Address Book.txt");
		ofstream temp("temp.txt");
		while (!info.eof())
		{
			getline(info, line);
			if (line == "First Name: " + fname)
			{
				if (namechange && !done)
				{
					getline(info, line);
					temp << "Fist Name: " << firstname << endl;
					temp << "Last Name: " << lastname << endl;
					done = true;
				}
				else
				{
					temp << line << endl;
					getline(info, line);
					temp << line << endl;
				}
				if (phonechange && !done)
				{
					done = true;
					do {
						temp << line << endl;
						getline(info, line);
					} while (search = line.find("Phone Number: ") == string::npos && !info.eof());
					temp << "Phone Number: " << phonechange << endl;
				}
				else if (addresschange && !done)
				{
					done = true;
					do {
						temp << line << endl;
						getline(info, line);
					} while (search = line.find("Street Address: ") == string::npos);
					temp << "Street Address: " << street << endl;
					temp << "City: " << city << endl;
					temp << "Province: " << province << endl;
					temp << "Zip Code: " << zip << endl;
					do getline(info, line); while (search = line.find("Zip Code: ") == string::npos && !info.eof());
				}
				else if (dobchange)
				{
					done = true;
					do {
						temp << line << endl;
						getline(info, line);
					} while (search = line.find("Date: ") == string::npos);
					temp << "Date: " << date << endl;
					temp << "Month: " << month << endl;
					temp << "Year: " << year << endl;
					do getline(info, line); while (search = line.find("Year: ") == string::npos && !info.eof());
				}
			}
			else temp << line << endl;
		}
		remove("Address Book.txt");
		rename("temp.txt", "Address Book.txt");

	}
}

void AddressBook::Delete(string fname, string lname)
{
	bool del = false;
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		char op;
		node* temp = new node[size];
		for (int i = 0; i < counter; i++)
		{
			if ((n+i)->name.firstname == fname)
			{
				if ((n+i)->name.lastname == lname);
				else
				{
					*(temp + i) = *(n + i);
					n = temp;
					counter--;
					del = true;
					break;
				}
			}
			else
			{
				*(temp + i) = *(n + i);
				n = temp;
				counter--;
				del = true;
				break;
			}
		}
		if (del)
			cout << "Entry Deleted!\n";
		else cout << "Couldn't Find Entry\n";

	}
}

void AddressBook::Classify(string fname, string lname)
{
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		char op;
		node* temp = new node[size];
		for (int i = 0; i < counter; i++)
		{
			if ((n+i)->name.firstname == fname)
			{
				if ((n+i)->name.lastname == lname)
				{
					cout << "Choose a Classification:-\n\n"
						<< "1. Family\n"
						<< "2. Friend\n"
						<< "3. Business\n"
						<< "4. Other Classification\n\n"
						<< "Choose: ";
						cin >> op;
						switch (op)
						{
						case '1':
							(n + i)->Classify = "Family";
							break;
						case '2':
							(n + i)->Classify = "Friend";
							break;
						case '3':
							(n + i)->Classify = "Business";
							break;
						case '4':
							cout << "Classification: ";
							cin >> (n + i)->Classify;
							break;
						default:
							cout << "Returning Back To Main Menu\n";
						}
				}
			}
		}
	}
}

void AddressBook::Search(string lname)
{
	bool found = false;
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		for (int i = 0; i < counter; i++)
		{
			if ((n+i)->name.lastname == lname)
			{
				cout << "Name: " << (n + i)->name.firstname << " " << (n + i)->name.lastname << endl;
				cout << "Gender: " << (n + i)->gender << endl;
				cout << "Phone Number: " << (n + i)->phonenumber << endl;
				cout << "Date Of Birth: " << (n + i)->dob.date << "/" << (n + i)->dob.month << "/" << (n + i)->dob.year << endl;
				cout << "Address: " << (n + i)->add.street_address << ", " << (n + i)->add.city << ", " << (n + i)->add.province << ", "
					<< (n + i)->add.zip << endl;
				found = true;
			}

		}
		if (!found)
			cout << "Couldn't Find Specified Entry\n";
	}
}

void AddressBook::MonthDisplay(int month)
{
	bool exist = false;
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		char op;
		for (int i = 0; i < counter; i++)
		{
			if ((n + i)->dob.month == month)
			{
				cout << "Entry " << i + 1 << ":-\n\n";
				cout << "Name: " << (n + i)->name.firstname << " " << (n + i)->name.lastname << endl;
				cout << "Gender: " << (n + i)->gender << endl;
				cout << "Phone Number: " << (n + i)->phonenumber << endl;
				cout << "Date Of Birth: " << (n + i)->dob.date << "/" << (n + i)->dob.month << "/" << (n + i)->dob.year << endl;
				cout << "Address: " << (n + i)->add.street_address << ", " << (n + i)->add.city << ", " << (n + i)->add.province << ", "
					<< (n + i)->add.zip << endl;
				exist = true;
			}
		}
		if (!exist)
			cout << "No Entry With This Month Exists\n\n";
	}

}

void AddressBook::DisplayAll()
{
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		char op;
		for (int i = 0; i < counter; i++)
		{
			cout << "Entry " << i + 1 << ":-\n\n" << endl;
			cout << "Name: " << (n + i)->name.firstname << " " << (n + i)->name.lastname << endl;
			cout << "Gender: " << (n + i)->gender << endl;
			cout << "Phone Number: " << (n + i)->phonenumber << endl;
			cout << "Date Of Birth: " << (n + i)->dob.date << "/" << (n + i)->dob.month << "/" << (n + i)->dob.year << endl;
			cout << "Address: " << (n + i)->add.street_address << ", " << (n + i)->add.city << ", " << (n + i)->add.province << ", "
				<< (n + i)->add.zip << endl;
		}
	}
}

void AddressBook::SameGender(string gender)
{
	bool exist = false;
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		char op;
		for (int i = 0; i < counter; i++)
		{
			if ((n + i)->gender == gender)
			{
				cout << "Entry " << i + 1 << ":-\n\n";
				cout << "Name: " << (n + i)->name.firstname << " " << (n + i)->name.lastname << endl;
				cout << "Gender: " << (n + i)->gender << endl;
				cout << "Phone Number: " << (n + i)->phonenumber << endl;
				cout << "Date Of Birth: " << (n + i)->dob.date << "/" << (n + i)->dob.month << "/" << (n + i)->dob.year << endl;
				cout << "Address: " << (n + i)->add.street_address << ", " << (n + i)->add.city << ", " << (n + i)->add.province << ", "
					<< (n + i)->add.zip << endl;
				exist = true;
			}
		}
		if (!exist)
			cout << "No one with this gender exists\n\n";
	}
}

void AddressBook::DisplayByStatus(string classify)
{
	bool exist = false;
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		char op;
		for (int i = 0; i < counter; i++)
		{
			if ((n + i)->Classify == classify)
			{
				cout << "Entry " << i + 1 << ":-\n\n";
				cout << "Name: " << (n + i)->name.firstname << " " << (n + i)->name.lastname << endl;
				cout << "Gender: " << (n + i)->gender << endl;
				cout << "Phone Number: " << (n + i)->phonenumber << endl;
				cout << "Date Of Birth: " << (n + i)->dob.date << "/" << (n + i)->dob.month << "/" << (n + i)->dob.year << endl;
				cout << "Address: " << (n + i)->add.street_address << ", " << (n + i)->add.city << ", " << (n + i)->add.province << ", "
					<< (n + i)->add.zip << endl;
				exist = true;
			}
		}
		if (!exist)
			cout << "No one with this classification has yet been registered\n\n";
	}
}

void AddressBook::BetweenDates(int d1, int m1, int y1, int d2, int m2, int y2)
{
	bool exist = false;
	if (counter == 0)
		cout << "No Entries Entered Yet\n";
	else
	{
		char op;
		for (int i = 0; i < counter; i++)
		{
			if ((n + i)->dob.year >= y1 && (n + i)->dob.year <= y2)
				if ((n + i)->dob.month >= m1 && (n + i)->dob.month <= m2)
					if ((n + i)->dob.date >= d1 && (n + i)->dob.date <= d2)
					{
						cout << "Entry " << i + 1 << ":-\n\n";
						cout << "Name: " << (n + i)->name.firstname << " " << (n + i)->name.lastname << endl;
						cout << "Gender: " << (n + i)->gender << endl;
						cout << "Phone Number: " << (n + i)->phonenumber << endl;
						cout << "Date Of Birth: " << (n + i)->dob.date << "/" << (n + i)->dob.month << "/" << (n + i)->dob.year << endl;
						cout << "Address: " << (n + i)->add.street_address << ", " << (n + i)->add.city << ", " << (n + i)->add.province << ", "
							<< (n + i)->add.zip << endl;
						exist = true;
					}
		}
		if (!exist)
			cout << "No one between these dates exist\n\n";
	}
}