/**
Khadeja Khalid
Winter 2017
16 February 2017
Lab 3
Problem 3.1
This program will ask the user specific questions
about their car and print it back out */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Car
{
private:
    string reportingMark, //A string of five or less upper case characters
            kind,         //Could be a box tank flat or other
            destination;  //A string with a destination or the word "NONE"
    bool   loaded;        //A bool that asks it the car is loaded
    int    carNumber;     //An int that contains the number of the car

public:
    //Constructor
    Car()
    {
        reportingMark = "None";
        carNumber = 0;
        kind = "None";
        loaded = false;
        destination = "None";

    }
    Car(string mark, int num, string make,
        bool state, string dest)
    {
        reportingMark = mark;
        carNumber = num;
        kind = make;
        loaded = state;
        destination = dest;
    }
    //Destructor (default)
    ~Car()
    {};

//Mutator member function prototypes
void setReportingMark(string mark)
    {reportingMark = mark;}

void setCarNumber (int num)
    {carNumber = num;}

void setKind (string make)
    {kind = make;}

void setLoaded (bool state)
    {loaded = state;}

void setDestination (string dest)
    {destination = dest;}

//Accessor member function prototype, NO CHANGE
const string getReportingMark()
    {return reportingMark;}

const int getCarNumber()
    {return carNumber;}

const string getKind()
    {return kind;}

const bool getLoaded()
    {return loaded;}

const string getDestination()
    {return destination;}

void printData();
void setUp (const string &mark, const int &num,
            const string &make, const bool &state,
            const string &dest);

}; //end class car

void getData(string &mark, int &num, string &make,
             bool &state, string &dest);

/************************** Main ***************************/
int main()
{

    string mark, make, dest;
    bool state;
    int num;

    //Call function to obtain data
    getData(mark, num, make, state, dest);

    Car car1; //Create an object car1

    //Call function to pass variables
    car1.setUp(mark, num, make, state, dest);

    cout << "Contents of car1: " << endl;

    car1.printData();

	return 0;
}

/********************** printData ***************************
This member function will print the data in a neat order
************************************************************/

void Car::printData()
{
    cout << endl;
    cout << left << setw(20) << "Reporting Mark: ";
    cout << right << setw(15) << reportingMark << endl;
    cout << left << setw(20) << "Car Number: ";
    cout << right << setw(15) << carNumber << endl;
    cout << left << setw(20) << "Kind: ";
    cout << right << setw(15) << kind << endl;
    cout << left << setw(20) << "Loaded: ";
    if (loaded)
        cout << right << setw(15) << "true";
    else
        cout << right << setw(15) << "false";
    cout << endl;
    cout << left << setw(20) << "Destination: ";
    cout << right << setw(15) << destination << endl;
    cout << endl;
}

/************************ setUpCar **************************
This member function will pass five variables
************************************************************/

void Car::setUp(const string &mark, const int &num,
                const string &make, const bool &state,
                const string &dest)
{
   reportingMark = mark;
   carNumber = num;
   kind = make;
   loaded = state;
   destination = dest;
}

/*********************** getData ****************************
This function will get the specific information needed
about the car
************************************************************/
void getData(string &mark, int &num, string &make,
             bool &state, string &dest)
{
    int length;
    cout << "Enter the Reporting Mark: ";
    getline (cin, mark);
    length = mark.length();

    while (length > 5)
    {
       cout << "Invalid! Must be less than 5 characters: ";
       cin >> mark;
       length = mark.length();
    }
    for (int i=0; i < int (mark.length()); i++)
        mark[i] = toupper(mark[i]);

    cout << "Enter the Car Number: ";
    cin >> num;

    cout << "Enter the kind of car"
            "(could be box tank flat or other): ";
    cin >> make;

    cout << "Is it loaded? (true or false only): ";
    cin >> boolalpha >> state;

    if(state)
    {
    cin.ignore();
    cout << "Enter the destination: ";
    getline (cin, dest);
    }
    else
        dest = "NONE";
}

/*
Enter the Reporting Mark: SP
Enter the Car Number: 34567
Enter the kind of car(could be box tank flat or other): box
Is it loaded? (true or false only): true
Enter the destination: Salt Lake City
Contents of car1:

Reporting Mark:                  SP
Car Number:                   34567
Kind:                           box
Loaded:                        true
Destination:         Salt Lake City


Process returned 0 (0x0)   execution time : 12.891 s
Press any key to continue.
*/




