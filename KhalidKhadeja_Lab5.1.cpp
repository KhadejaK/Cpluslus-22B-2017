/**
Khadeja Khalid
CIS 22B
Winter 2017
16 March 2017
Lab 5
Problem 5.1
This function will use inheritance to create two new classes, both of which
will inherit from the class Car */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

enum Kind {business, maintenance, tender, other, box, tank, flat,
           hopper, otherFreight, chair, sleeper, otherPassenger, combine};
const int NUMKIND = 13;

const string KIND_ARRAY[NUMKIND] = {"business", "maintenance", "tender", "other",
                                    "box", "tank", "flat", "hopper", "otherFreight",
                                    "chair", "sleeper", "otherPassenger", "combine"};

class Car
{
protected:
    //Member functions
    string reportingMark; //A string of five or less upper case characters
    Kind   kind;          //Could be a box tank flat or other
    string destination;   //A string with a destination or the word "NONE"
    bool   loaded;        //A bool that asks it the car is loaded
    int    carNumber;     //An int that contains the cNumber of the car

public:
    //Constructor
    //Default constructor
    Car()
    {
        reportingMark = "";
        carNumber = 0;
        kind = other;
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
    Car(const string &rMark, const int &cNum, const string &make,
                const bool &state, const string &dest)
    {
        setUp(rMark, cNum, make, state, dest);
    }

    //Destructor that does nothing
    ~Car()
    {}

//Mutator member function prototypes
void setReportingMark(string rMark)
    {reportingMark = rMark;}

void setCarNumber (int cNum)
    {carNumber = cNum;}

void setKind (Kind make)
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

const Kind getKind()
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

Car & operator = (const Car &);

void setKind(const string &knd )
{
    if(knd == "business")
        kind = business;

    else if(knd == "maintenance")
        kind = maintenance;

    else if (knd == "tender")
        kind = tender;

    else
        kind = other;
}

}; //end class Car

/************************** FreightCar Class *******************/

class FreightCar : public Car
{
public:
    //Default
    FreightCar() : Car() {};

    //Copy
    FreightCar(const FreightCar &obj2)
   {
        reportingMark = obj2.reportingMark;
        carNumber = obj2.carNumber;
        kind = obj2.kind;
        loaded = obj2.loaded;
        destination = obj2.destination;
    }

    //Constructor with five parameters
    FreightCar(string rMark, int cNum, string make,
               bool state, string dest)
    : Car (rMark, cNum, make, state, dest)
    {
        setKind (make);
    }

    void setKind(const string &knd)
    {
        if (knd == "box")
            kind = box;

        else if (knd == "tank")
            kind = tank;

        else if (knd == "flat")
            kind = flat;

        else if (knd == "hopper")
            kind = hopper;

        else
            kind = otherFreight;
    }
}; //end of Class FreightCar

/*********************** PassengerCar Class ********************/

class PassengerCar : public Car
{
public:
    //Default
    PassengerCar() : Car() {};

    //Copy
    PassengerCar (const PassengerCar &obj3)
    {
        reportingMark = obj3.reportingMark;
        carNumber = obj3.carNumber;
        kind = obj3.kind;
        loaded = obj3.loaded;
        destination = obj3.destination;
    }
    //Constructor with four parameters
    PassengerCar(string rMark, int cNum, string make,
                 bool state, string dest)
    : Car (rMark, cNum, make, state, dest)
    {
        setKind (make);
    }

    void setKind(const string &knd)
    {
    if (knd == "chair")
        kind = chair;

    else if (knd == "sleeper")
        kind = sleeper;

    else if (knd == "combine")
        kind = combine;

    else
        kind = otherPassenger;
    }
}; //end of class PassengerCar

void getData();
void buildCar(string&, int&, string&, bool&, string&);
void buildFreightCar(string&, int&, string&, bool&, string&);
void buildPassengerCar(string&, int&, string&, bool&, string&);

/**************************** Main ******************************/
int main()
{

    getData();
    cout << endl;

	return 0;
}

/************************** buildCar ****************************
When called, this function will build an object of type Car by
using the Car constructor that has five parameters
****************************************************************/
void buildCar (string &rMark, int &cNum, string &make,
               bool &state, string &dest)

{
    Car temp(rMark, cNum, make, state, dest);
    temp.printData();
}

/*********************** buildFreightCar *************************
When called, this function will build an object of type FreightCar
by using the FreightCar constructor that has five parameters
*****************************************************************/
void buildFreightCar (string &rMark, int &cNum, string &make,
                       bool &state, string &dest)
{
    FreightCar temp(rMark, cNum, make, state, dest);
    temp.printData();
}

/********************* buildPassengerCar *************************
When called, this function will build an object of type PassengerCar
by using the PassengerCar constructor that has five parameters
*****************************************************************/
void buildPassengerCar (string &rMark, int &cNum, string &make,
                        bool &state, string &dest)
{
    PassengerCar temp(rMark, cNum, make, state, dest);
    temp.printData();
}

/************************** printData ***************************
This member function will print the data in a neat order
*****************************************************************/

void Car::printData()
{
    static int x = 1;
    string KIND_ARRAY[NUMKIND] = {"business", "maintenance", "tender", "other",
                                  "box", "tank", "flat", "hopper", "otherFreight",
                                  "chair", "sleeper", "otherPassenger", "combine"};
    cout <<"--------------------------------" << endl;
    cout <<"Car Number: "<< x << endl;
    cout <<"--------------------------------" << endl;
    cout << left << setw(20) << "ARR:"
        << setw(20) << reportingMark << endl;
    cout << left << setw(20) << "Number:"
        << setw(20) << carNumber << endl;
    cout << left << setw(20) << "Kind:"
        << setw(20)  << KIND_ARRAY[kind] << endl;
    cout << left << setw(20) << boolalpha << "Loaded:"
        << setw(20) << loaded << endl;
    cout << left << setw(20) << "Destination:"
        << setw(20) << destination << endl;
    cout <<endl;
    x++;
}

/*************************** setUpCar ****************************
This member function will pass five variables
*****************************************************************/

void Car::setUp(const string &rMark, const int &cNum,
                const string &make, const bool &state,
                const string &dest)
{
   reportingMark = rMark;
   carNumber = cNum;
   setKind (make);
   loaded = state;
   destination = dest;
}

/*********************** Car::Operator ***************************
Sets the values in the left hand object to the right hand
*****************************************************************/
Car & Car::operator=(const Car &CarB)
{
    reportingMark = CarB.reportingMark;
    carNumber     = CarB.carNumber;
    kind          = CarB.kind;
    loaded        = CarB.loaded;
    destination   = CarB.destination;

    return * this;
}

/************************ Friend Function ************************
This function will test to see if two objects are equivalent.
The two objects are equivalent is have the same reportingMark
and cNumber (not looking at the kind, loaded, or destination)
*****************************************************************/

bool operator == (const Car &first, const Car &second)
{
    if (first.reportingMark == second.reportingMark &&
        first.carNumber == second.carNumber)
        return true;
    else
        return false;
}

/**************************** getData ***************************
This function will get the specific information needed
about the car from a file.
*****************************************************************/

void getData()
{
    string type;
    string order;
    string rMark;
    int cNum;
    string make;
    bool state;
    string dest;

    ifstream inputFile;

    inputFile.open("cardata-51.txt");

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
            inputFile >> order;
            inputFile >> rMark;
            inputFile >> cNum;
            inputFile >> make;
            inputFile >> boolalpha >> state;
            while (inputFile.peek() == ' ')
                inputFile.get();
            getline(inputFile, dest);

            if (type == "Car")
                buildCar(rMark, cNum, make, state, dest);

            else if (type == "FreightCar")
                buildFreightCar(rMark, cNum, make, state, dest);

            else
                buildPassengerCar(rMark, cNum, make, state, dest);
        }

    }

    inputFile.close(); //close file

}

/**

--------------------------------
Car Number: 1
--------------------------------
ARR:                SP
Number:             819480
Kind:               maintenance
Loaded:             false
Destination:        NONE

--------------------------------
Car Number: 2
--------------------------------
ARR:                SLSF
Number:             46870
Kind:               business
Loaded:             true
Destination:        Memphis

--------------------------------
Car Number: 3
--------------------------------
ARR:                AOK
Number:             150
Kind:               tender
Loaded:             true
Destination:        McAlester

--------------------------------
Car Number: 4
--------------------------------
ARR:                MKT
Number:             123450
Kind:               tank
Loaded:             false
Destination:        Fort Worth

--------------------------------
Car Number: 5
--------------------------------
ARR:                MP
Number:             98760
Kind:               box
Loaded:             true
Destination:        Saint Louis

--------------------------------
Car Number: 6
--------------------------------
ARR:                SP
Number:             567890
Kind:               flat
Loaded:             true
Destination:        Chicago

--------------------------------
Car Number: 7
--------------------------------
ARR:                GMO
Number:             7870
Kind:               other
Loaded:             true
Destination:        Mobile

--------------------------------
Car Number: 8
--------------------------------
ARR:                KCS
Number:             7890
Kind:               chair
Loaded:             true
Destination:        Kansas City

--------------------------------
Car Number: 9
--------------------------------
ARR:                PAPX
Number:             140
Kind:               sleeper
Loaded:             true
Destination:        Tucson

--------------------------------
Car Number: 10
--------------------------------
ARR:                B&O
Number:             740
Kind:               combine
Loaded:             false
Destination:        NONE



Process returned 0 (0x0)   execution time : 0.774 s
Press any key to continue.

 */

/* class StringOfCars
{
private:

    Car *carPtr; //points to an array of Car objects in the heap
    static const int ARRAY_MAX_SIZE = 10;
    int size; //current number of cars in the array

public:
    //Default constructor
    StringOfCars()
    {
        carPtr = new Car[ARRAY_MAX_SIZE];
        size = 0;
    }
    //Copy constructor
    StringOfCars(const StringOfCars &obj)
    {
        carPtr = new Car[ARRAY_MAX_SIZE];
        //size = obj.size;
        for (int index=0; index < size; index++)
            carPtr[index] = obj.carPtr[index];

    }
    //Destructor
    ~StringOfCars()
    {
         delete [] carPtr;
    }

//Prints a heading for each car
void printData2();

//Adds a car to the string of cars
void push(Car car)
{
    if (size >= 10)
    {
        cout << "Array too large.\n";
        return;
    }
    else
    {
        carPtr[size] = car;
        size++;
    }

}

//Removes the car from a string of cars (LIFO)
void pop(Car &car)
{
    if (size < 0)
    {
        return;
    }
    else
    {
        car = carPtr[size - 1];
        size--;
    }

}

}; //End class StringOfCars */

/*
void StringOfCars::printData2()
{
    if (size == 0)
    {
        cout << "NO cars" << endl;
    }
    else
    {
        for (int i = 0; i < size ; i++)
        {
            cout << endl << "Car Number " << i+1 << endl;
            carPtr[i].printData();
        }

    }
}*/
