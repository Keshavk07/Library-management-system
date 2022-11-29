      //Semester 4th OOP Project
	//Library Management System

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Intro Function
void Intro()
{
	cout << endl;
	cout << string(66, '*') << endl;
	cout << "\t\tSPRING 2020 OOP Project" << endl;
	cout << "\tWelcome to Library Management System v1.0.0" << endl;
	cout << string(66, '*') << endl;
	cout << endl;
}

//Date Struct
struct Date { int Day = 0, Month = 0, Year = 0; };

//Class :: Library
class Library
{
protected:
	int LibraryID;
	string LibraryName;
public:
	//No Argument
	Library() :LibraryID(0), LibraryName("\0") {};
	//2 Argument
	Library(int NewID, string NewName) :LibraryID(NewID), LibraryName(NewName) {};
	//Destructor
	~Library() {};

	//Input/Getter Function
	void getLibraryID()
	{
		cout << "Enter Library ID : ";
		cin >> LibraryID;
	}
	string getLibraryName()
	{
		if (LibraryID == 1)
		{
			LibraryName = "Main Campus Library";
		}
		else if (LibraryID == 2)
		{
			LibraryName = "CS Library";
		}
		else if (LibraryID == 3)
		{
			LibraryName = "Engineering Library";
		}
		else
		{
			cout << "\n**Invalid Library ID**" << endl;
		}
		return LibraryName;
	}

	//Print Function
	void LibraryOption()
	{
		cout << endl;
		cout << "**Library Options**" << endl;
		cout << "1. Main Campus Library" << endl;
		cout << "2. CS Library" << endl;
		cout << "3. Engineering Library" << endl;
		cout << endl;
	}

	//File Handling
	void WriteLibrary()
	{
		ofstream FileL;
		FileL.open("Library.txt");

		FileL << LibraryID << "\t" << LibraryName << endl;
		cout << "**Library Added Successfully**" << endl;
		cout << endl;

		FileL.close();
	}
	void ReadLibrary()
	{
		int ID;
		string Name;
		ifstream FileL;
		FileL.open("Library.txt");

		FileL >> ID;
		getline(FileL, Name);

		cout << "Library ID" << "\t" << "Library Name" << endl;
		cout << ID << ".\t" << Name << endl;
		cout << endl;

		FileL.close();
	}
};

//Class :: Subscriber
class Subscriber
{
protected:
	int SubscriberID, Type;
	string SubscriberType, SubscriberName, SubscriberAddress, SubscriberPhone, SubscriberEmail;
public:
	//No Argument
	Subscriber()
	{
		SubscriberID = 1;
		SubscriberType = "Regular";
		SubscriberName = "ALI";
		SubscriberAddress = "N/A";
		SubscriberPhone = "N/A";
		SubscriberEmail = "N/A";
	};
	//6 Argument
	Subscriber(int ID, string Type, string Name, string Address, string Phone, string Email)
	{
		SubscriberID = ID;
		SubscriberType = Type;
		SubscriberName = Name;
		SubscriberAddress = Address;
		SubscriberPhone = Phone;
		SubscriberEmail = Email;
	};
	//Destructor
	~Subscriber() {};

	//Input/Getter Function
	void ReadType()
	{
		cout << "\n**Subscriber Types**\n";
		cout << "1. Regular Subscriber\n";
		cout << "2. Golden Subscriber\n";
		cout << endl;
		cout << "Enter Subscriber Type : ";
		cin >> Type;
	}
	string getType()
	{
		if (Type == 1)
		{
			SubscriberType = "Regular";
		}
		else if (Type == 2)
		{
			SubscriberType = "Golden";
		}
		else
		{
			cout << "\n**Invalid Subscriber Type**";
			cout << endl;
		}
		return SubscriberType;
	}
	void getSubscriber()
	{
		cout << "Enter Subscriber ID : "; cin >> SubscriberID;
		cout << "Enter Subscriber Name : "; cin >> SubscriberName;
		cout << "Enter Subscriber Address : "; cin >> SubscriberAddress;
		cout << "Enter Subscriber Phone # : "; cin >> SubscriberPhone;
		cout << "Enter Subscriber Email Address : "; cin >> SubscriberEmail;
	}

	//File Handling
	void WriteSubscriber()
	{
		ofstream Sub;
		Sub.open("Subscriber.txt");

		Sub << SubscriberID << "\t" << getType() << "\t" << SubscriberName << "\t" << SubscriberAddress << "\t";
		Sub << SubscriberPhone << "\t" << SubscriberEmail << endl;
		cout << "\n**Subscriber Added Successfully**" << endl;

		Sub.close();
	}
	void ReadSubscriber()
	{
		int ID;
		string Type, Name, Address, Phone, Email;
		ifstream Sub;
		Sub.open("Subscriber.txt");

		Sub >> ID >> Type;
		getline(Sub, Name);
		getline(Sub, Address);
		Sub >> Phone >> Email;

		cout << endl;
		cout << ID << "\t" << Type << "\t" << Name << "\t" << Address << "\t" << Phone << "\t" << Email << endl;

		Sub.close();
	}
};

//Class :: Borrowing Records
class BorrowingRecord
{
protected:
	Date BorrowDate, ReturnDate;
	int SubscriberID, ContentID, Fee;
public:
	//No Argument
	BorrowingRecord()
	{
		SubscriberID = 0;
		BorrowDate;
		ContentID = 0;
		ReturnDate;
		Fee = 0;
	};
	//5 Argument
	BorrowingRecord(int NewSubID, Date NewBorrowDate, int NewConID, Date NewReturnDate, int NewFee)
	{
		SubscriberID = NewSubID;
		BorrowDate = NewBorrowDate;
		ContentID = NewConID;
		ReturnDate = NewReturnDate;
		Fee = NewFee;
	};
	//Destructor
	~BorrowingRecord() {};

	//Input/Getter Function
	void getRecord()
	{
		cout << "Enter Subscriber ID : "; cin >> SubscriberID;
		cout << "Enetr Borrow Date (DD MM YYYY) : ";
		cin >> BorrowDate.Day >> BorrowDate.Month >> BorrowDate.Year;
		cout << "Enter Content ID : "; cin >> ContentID;
		cout << "Enter Return Date (DD MM YYYY) : ";
		cin >> ReturnDate.Day >> ReturnDate.Month >> ReturnDate.Year;
		cout << "Enter Fee : "; cin >> Fee;
	}

	//File Handling
	void WriteRecord()
	{
		ofstream Borrowing;
		Borrowing.open("Borrowing.txt");

		Borrowing << SubscriberID << "\t" << BorrowDate.Day << " " << BorrowDate.Month << " " << BorrowDate.Year << "\t";
		Borrowing << ContentID << "\t" << ReturnDate.Day << " " << ReturnDate.Month << " " << ReturnDate.Year << "\t" << Fee << "-/Rs." << endl;

		cout << "\n**Record Added Successfully**" << endl;
		cout << endl;

		Borrowing.close();
	}
	void ReadRecord()
	{
		int SubID, ConID;
		Date Borrow, Return;
		ifstream Borrowing;
		Borrowing.open("Borrowing.txt");

		Borrowing >> SubID >> Borrow.Day >> Borrow.Month >> Borrow.Year;
		Borrowing >> ConID >> Return.Day >> Return.Month >> Return.Month >> Fee;

		cout << "Subscriber ID" << "\t" << "Borrow Date" << "\t" << "Content ID" << "\t" << "Return Date" << "\t" << "Fee" << endl;
		cout << SubID << "\t" << "\t" << Borrow.Day << "/" << Borrow.Month << "/" << Borrow.Year << "\t";
		cout << ConID << "\t" << "\t" << Return.Day << "/" << Return.Month << "/" << Return.Year << "\t" << Fee << endl;

		Borrowing.close();
	}
};

//Main Body
int main()
{
	//Intro Section
	Intro();

	//Data Members
	Library ObjL;
	Subscriber ObjS;
	BorrowingRecord ObjR;

	//Library Section
	ObjL.LibraryOption();
	ObjL.getLibraryID();
	cout << "Your Selection = " << ObjL.getLibraryName() << endl;
	cout << endl;
	//File Handling Section for Library
	ObjL.WriteLibrary();
	ObjL.ReadLibrary();

	//Subscriber Section
	ObjS.ReadType();
	cout << "Your Selection = " << ObjS.getType() << endl;
	cout << endl;
	ObjS.getSubscriber();
	//File Handling Section for Subscriber
	ObjS.WriteSubscriber();
	ObjS.ReadSubscriber();

	//Borrowing Record Section
	cout << "\n**For Borrowing Record**" << endl;
	ObjR.getRecord();
	//File Handling Section for Borrowing Record
	ObjR.WriteRecord();
	ObjR.ReadRecord();
}