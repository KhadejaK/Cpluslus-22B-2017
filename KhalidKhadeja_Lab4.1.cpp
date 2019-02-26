/**
Khadeja Khalid
CIS 22B
Winter 2017
2 March 2017
Lab 4
Problem 4.1
This program will read the car's data from a separate file,
rather than from user input*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void getData();

/*************************** Main **************************/
int main()
{
    getData();

	return 0;
}

class Car
{
private:
    //Member functions
    string reportingMark, //A string of five or less upper case characters
           kind,          //Could be a box tank flat or other
           destination;   //A string with a destination or the word "NONE"
    bool   loaded;        //A bool that asks it the car is loaded
    int    carNumber;     //An int that contains the cNumber of the car

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
    Car(const string &rMark, const int &cNum, const string &kind,
                const bool &state, const string &dest)
    {
        setUp(rMark, cNum, kind, state, dest);
    }

    //Destructor that does nothing
    ~Car()
    {}

//Mutator member function prototypes
void setreportingMark(string rMark)
    {reportingMark = rMark;}

void setcarNumber (int cNum)
    {carNumber = cNum;}

void setKind (string make)
    {kind = make;}

void setLoaded (bool state)
    {loaded = state;}

void setDestination (string dest)
    {destination = dest;}

//Accessor member function prototype, NO CHANGE
const string getreportingMark()
    {return reportingMark;}

const int getcarNumber()
    {return carNumber;}

const string getKind()
    {return kind;}

const bool getLoaded()
    {return loaded;}

const string getDestination()
    {return destination;}

//Member functions
void printData(); //print the output
void setUp (const string &rMark, const int &cNum,
            const string &make, const bool &state,
            const string &dest);

//Friend function
friend bool operator == (const Car &first, const Car &second);


}; //end class car

/*********************** printData **************************
This member function will print the data in a neat order
************************************************************/

void Car::printData()
{
    cout << setw(18) << left << "Reporting Mark: "
         << setw(5) << reportingMark << endl;
    cout << setw(18) << left << "Car Number: "
         << setw(5) << carNumber << endl;
    cout << setw(18) << left << "Kind: "
         << setw(5) << kind << endl;
    cout << setw(18) << left << "Loaded: ";
    if (loaded == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout << setw(14) << "Destination: "
         << destination << endl << endl;
}

/************************* setUpCar *************************
This member function will pass five variables
************************************************************/

void Car::setUp(const string &rMark, const int &cNum,
                const string &make, const bool &state,
                const string &dest)
{
   reportingMark = rMark;
   carNumber = cNum;
   kind = make;
   loaded = state;
   destination = dest;
}

/******************** Friend Function ***********************
This function will test to see if two objects are equivalent.
The two objects are equivalent is have the same reportingMark
and cNumber (not looking at the kind, loaded, or destination)
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
about the car from a file.
************************************************************/

void getData()
{
    string type;
    string rMark;
    int cNum;
    string make;
    bool state;
    string dest;

    ifstream inputFile;

    inputFile.open("input.lab4.txt");

    if (inputFile.fail()) //check if valid file
    {
        cerr << "Error opening file." << endl;
        return;
    }
    else
    {
        while(inputFile.peek() != EOF)
        {

            inputFile >> type;
            inputFile >> rMark;
            inputFile >> cNum;
            inputFile >> make;
            inputFile >> boolalpha >> state;

            while(inputFile.peek() == ' ')
            {
                inputFile.get();
                getline(inputFile, dest);
            }

            Car temp(rMark, cNum, make, state, dest);
            temp.printData();
        }

    }

    inputFile.close(); //close file

}

/*
Reporting Mark:   CN
Car Number:       819481
Kind:             maintenance
Loaded:           false
Destination:      NONE

Reporting Mark:   SLSF
Car Number:       46871
Kind:             business
Loaded:           true
Destination:      Memphis

Reporting Mark:   AOK
Car Number:       156
Kind:             tender
Loaded:           true
Destination:      McAlester


Process returned 0 (0x0)   execution time : 0.466 s
Press any key to continue.
*/
