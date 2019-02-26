/**
Khadeja Khalid
Winter 2017
16 February 2017
Lab 3
Problem 3.3
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
    //Default constructor
    Car()
    {
        reportingMark = "";
        carNumber = 0;
        kind = "other";
        loaded = false;
        destination = "NONE";
    }
    //Copy Constructor, will copy the variables
    Car(const Car &obj)
    {
        reportingMark = obj.reportingMark;
        carNumber = obj.carNumber;
        kind = obj.kind;
        loaded = obj.loaded;
        destination = obj.destination;
    }

    //A constructor that calls the set up function to pass variables
    Car(const string &mark, const int &num, const string &kind,
                const bool &state, const string &dest)
    {
        setUp(mark, num, kind, state, dest);
    }

    //Destructor that does nothing
    ~Car()
    {}

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

//Member functions
void printData(); //print the output
void setUp (const string &mark, const int &num,
            const string &make, const bool &state,
            const string &dest);

//Friend function
friend bool operator == (const Car &first, const Car &second);

}; //end class car


void getData(string &mark, int &num, string &make,
             bool &state, string &dest);

/*************************** Main **************************/
int main()
{

    string mark, make, dest;
    bool state;
    int num;

    //Call function to obtain data
    getData(mark, num, make, state, dest);

    Car car1(mark, num, make, state, dest);
    Car car2(car1);
    Car car3;

    cout << "Contents of car1: " << endl;
    car1.printData();

    cout << "Contents of car2: " << endl;
    car2.printData();

    cout << "Contents of Car3: " << endl;
    car3.printData();

    if (car1 == car2)
        cout << "car1 is the same as car2" << endl;
    else
        cout << "car1 is not the same as car2" << endl;

    if (car2 == car3)
        cout << "car2 is the same as car3" << endl;
    else
        cout << "car 2 is not the same as car3" << endl;

	return 0;
}

/*********************** printData **************************
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

/************************* setUpCar *************************
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

/******************** Friend Function ***********************
This function will test to see if two objects are equivalent.
The two objects are equivalent is have the same reportingMark
and number (not looking at the kind, loaded, or destination)
************************************************************/

bool operator == (const Car &first, const Car &second)
{
    if (first.reportingMark == second.reportingMark &&
        first.carNumber == second.carNumber)
        return true;
    else
        return false;
}

/************************ getData ***************************
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

    cout << endl;
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

Contents of car2:

Reporting Mark:                  SP
Car Number:                   34567
Kind:                           box
Loaded:                        true
Destination:         Salt Lake City

Contents of Car3:

Reporting Mark:
Car Number:                       0
Kind:                         other
Loaded:                       false
Destination:                   NONE

car1 is the same as car2
car 2 is not the same as car3

Process returned 0 (0x0)   execution time : 17.654 s
Press any key to continue.
*/

