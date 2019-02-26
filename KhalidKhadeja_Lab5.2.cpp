/**
Khadeja Khalid
CIS 22B
Winter 2017
16 March 2017
Lab 5
Problem 5.2
This program will change the StringOfCars class so it has an array of pointers to
objects, rather than an array of objects themselves
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

enum Kind {business, maintenance, tender, other, box, tank, flat,
           hopper, otherFreight, chair, sleeper, otherPassenger, combine};
const int NUMKIND = 10;
const int temp = 13;

const string KIND_ARRAY[temp] = {"business", "maintenance", "tender", "other",
                                    "box", "tank", "flat", "hopper", "otherFreight",
                                    "chair", "sleeper", "otherPassenger", "combine"};

class Car
{
protected:
    //Member functions
    string c_type;
    string c_order;
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
        c_type = "";
        c_order = "";
        reportingMark = "";
        carNumber = 0;
        kind = other;
        loaded = false;
        destination = "NONE";
    }
    //Copy Constructor, will copy the variables
    Car(const Car &obj)
    {
        c_type        = obj.c_type;
        c_order       = obj.c_order;
        reportingMark = obj.reportingMark;
        carNumber     = obj.carNumber;
        kind          = obj.kind;
        loaded        = obj.loaded;
        destination   = obj.destination;
    }

    //A constructor that calls the set up function to pass variables
    Car(const string &type, const string &order, const string &rMark, const int &cNum,
        const string &make, const bool &state, const string &dest)
    {
        setUp(type, order, rMark, cNum, make, state, dest);
    }

    //Destructor that does nothing
    virtual ~Car() {}

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

    void setC_type (string type)
        {c_type = type;}

    void setC_order (string order)
        {c_order = order;}

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

    const string getC_type()
        {return c_type;}

    const string getC_order()
        {return c_order;}



    //Member functions
    void printData(); //print the output
    void setUp (const string &type, const string &order,
                const string &rMark, const int &cNum,
                const string &make, const bool &state,
                const string &dest);

    //Friend function
    friend bool operator == (const Car &first, const Car &second);

    Car & operator = (const Car &);

    virtual void setKind(const string &knd )
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

/*********************** StringOfCars Class ********************/

class StringOfCars : public Car
{
private:
    //Member Functions
    Car **carPtr; //points to an array of Car objects in the heap
    int size;     //current number of cars in the array

public:
    //Default constructor
    StringOfCars()
    {
        carPtr = new Car*[NUMKIND];
        size = 0;
    }

    //Copy constructor
    StringOfCars(const StringOfCars &obj)
    {
        carPtr = new Car*[NUMKIND];
        for (int index=0; index < NUMKIND; index++)
            *carPtr[index] = *obj.carPtr[index];
        size = obj.size;
    }

    //Destructor
    ~StringOfCars()
    {
       for (int x = 0; x < NUMKIND; x++)
            {delete carPtr[x];}

       delete [] carPtr;
    }

    //Prints a heading for each car
    void printData2();

    //Adds a Car to the string of cars
    void push(const Car &car)
    {
        if (size >= NUMKIND)
        {
            cout << "Array too large.\n";
            return;
        }

        else
        {
            Car *cptr = new Car(car);

            carPtr[size] = cptr;
            size++;
        }

    }

}; //End class StringOfCars


/************************ FreightCar Class *********************/

class FreightCar : public Car
{
public:
    //Default
    FreightCar() : Car() {};

    //Copy
    FreightCar(const FreightCar &obj2)
   {
        c_type        = obj2.c_type;
        c_order       = obj2.c_order;
        reportingMark = obj2.reportingMark;
        carNumber     = obj2.carNumber;
        kind          = obj2.kind;
        loaded        = obj2.loaded;
        destination   = obj2.destination;
    }

    //Constructor with five parameters
    FreightCar(string type, string order, string rMark, int cNum, string make,
               bool state, string dest)
    : Car (type, order, rMark, cNum, make, state, dest)
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
        c_type        = obj3.c_type;
        c_order       = obj3.c_order;
        reportingMark = obj3.reportingMark;
        carNumber     = obj3.carNumber;
        kind          = obj3.kind;
        loaded        = obj3.loaded;
        destination   = obj3.destination;
    }
    //Constructor with four parameters
    PassengerCar(string type, string order, string rMark, int cNum, string make,
                 bool state, string dest)
    : Car (type, order, rMark, cNum, make, state, dest)
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

void getData(StringOfCars &obj);
void buildCar         (Car&,          string&, string&, string&, int&, string&, bool&, string&);
void buildFreightCar  (FreightCar&,   string&, string&, string&, int&, string&, bool&, string&);
void buildPassengerCar(PassengerCar&, string&, string&, string&, int&, string&, bool&, string&);

/**************************** Main ******************************/
int main()
{

    StringOfCars stringOfCars1;

    //StringOfCars stringOfCars2 = stringOfCars1;
    //stringOfCars2.printData();

    getData(stringOfCars1);
    stringOfCars1.printData2();

    cout << endl;

	return 0;
}

/************************** buildCar ****************************
When called, this function will build an object of type Car by
using the Car constructor that has five parameters
****************************************************************/
void buildCar (Car *carPtr, string &type, string &order, string &rMark, int &cNum, string &make,
               bool &state, string &dest, StringOfCars &stringOfCars1)
{
    carPtr -> setUp(type, order, rMark, cNum, make, state, dest);

    stringOfCars1.push(*carPtr);
}

/*********************** buildFreightCar *************************
When called, this function will build an object of type FreightCar
by using the FreightCar constructor that has five parameters
*****************************************************************/
void buildFreightCar (FreightCar *carPtr, string &type, string &order, string &rMark, int &cNum, string &make,
                      bool &state, string &dest, StringOfCars &stringOfCars1)
{
    carPtr -> setUp(type, order, rMark, cNum, make, state, dest);

    stringOfCars1.push(*carPtr);
}

/********************* buildPassengerCar *************************
When called, this function will build an object of type PassengerCar
by using the PassengerCar constructor that has five parameters
*****************************************************************/
void buildPassengerCar (PassengerCar *carPtr, string &type, string &order, string &rMark, int &cNum, string &make,
                        bool &state, string &dest, StringOfCars &stringOfCars1)
{
    carPtr -> setUp(type, order, rMark, cNum, make, state, dest);

    stringOfCars1.push(*carPtr);
}

/************************** printData ***************************
This member function will print the data in a neat order
*****************************************************************/

void Car::printData()
{
    static int x = 1;
    string KIND_ARRAY[temp] = {"business", "maintenance", "tender", "other",
                                  "box", "tank", "flat", "hopper", "otherFreight",
                                  "chair", "sleeper", "otherPassenger", "combine"};
    cout <<"--------------------------------" << endl;
    cout <<"Car Number: "<< x << endl;
    cout <<"--------------------------------" << endl;
    cout << left << setw(20) << "Type:"
        << setw(20) << c_type << endl;
    cout << left << setw(20) << "Order:"
        << setw(20) << c_order << endl;
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

void StringOfCars::printData2()
{
    if (size == 0)
    {
        cout << "NO cars" << endl;
    }
    else
    {
        for (int i = 0; i < NUMKIND ; i++)
        {
            carPtr[i] -> printData();
        }

    }
}

/*************************** setUpCar ****************************
This member function will pass five variables
*****************************************************************/

void Car::setUp(const string &type,  const string &order,
                const string &rMark, const int &cNum,
                const string &make,  const bool &state,
                const string &dest)
{
   c_type        = type;
   c_order       = order;
   reportingMark = rMark;
   carNumber     = cNum;
   setKind        (make);
   loaded        = state;
   destination   = dest;
}

/*********************** Car::Operator ***************************
Sets the values in the left hand object to the right hand
*****************************************************************/
Car & Car::operator=(const Car &CarB)
{
    c_type        = CarB.c_type;
    c_order       = CarB.c_order;
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
        first.carNumber     == second.carNumber)
        return true;

    else
        return false;
}

/**************************** getData ***************************
This function will get the specific information needed
about the car from a file.
*****************************************************************/

void getData(StringOfCars &stringOfCars1)
{

    string type;
    string order;
    string rMark;
    int    cNum;
    string make;
    bool   state;
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
            {
                Car *carPtr = new Car();
                buildCar(carPtr, type, order, rMark, cNum, make, state, dest, stringOfCars1);
            }


            else if (type == "FreightCar")
            {
                FreightCar *carPtr = new FreightCar();
                buildFreightCar(carPtr, type, order, rMark, cNum, make, state, dest, stringOfCars1);
            }


            else
            {
                PassengerCar *carPtr = new PassengerCar();
                buildPassengerCar(carPtr, type, order, rMark, cNum, make, state, dest, stringOfCars1);
            }

        }

    }

    inputFile.close(); //close file

}
/**
--------------------------------
Car Number: 1
--------------------------------
Type:               Car
Order:              car1
ARR:                SP
Number:             819480
Kind:               maintenance
Loaded:             false
Destination:        NONE

--------------------------------
Car Number: 2
--------------------------------
Type:               Car
Order:              car2
ARR:                SLSF
Number:             46870
Kind:               business
Loaded:             true
Destination:        Memphis

--------------------------------
Car Number: 3
--------------------------------
Type:               Car
Order:              car3
ARR:                AOK
Number:             150
Kind:               tender
Loaded:             true
Destination:        McAlester

--------------------------------
Car Number: 4
--------------------------------
Type:               FreightCar
Order:              car4
ARR:                MKT
Number:             123450
Kind:               tank
Loaded:             false
Destination:        Fort Worth

--------------------------------
Car Number: 5
--------------------------------
Type:               FreightCar
Order:              car5
ARR:                MP
Number:             98760
Kind:               box
Loaded:             true
Destination:        Saint Louis

--------------------------------
Car Number: 6
--------------------------------
Type:               FreightCar
Order:              car6
ARR:                SP
Number:             567890
Kind:               flat
Loaded:             true
Destination:        Chicago

--------------------------------
Car Number: 7
--------------------------------
Type:               FreightCar
Order:              car7
ARR:                GMO
Number:             7870
Kind:               hopper
Loaded:             true
Destination:        Mobile

--------------------------------
Car Number: 8
--------------------------------
Type:               PassengerCar
Order:              car8
ARR:                KCS
Number:             7890
Kind:               chair
Loaded:             true
Destination:        Kansas City

--------------------------------
Car Number: 9
--------------------------------
Type:               PassengerCar
Order:              car9
ARR:                PAPX
Number:             140
Kind:               sleeper
Loaded:             true
Destination:        Tucson

--------------------------------
Car Number: 10
--------------------------------
Type:               PassengerCar
Order:              car10
ARR:                B&O
Number:             740
Kind:               combine
Loaded:             false
Destination:        NONE



Process returned 0 (0x0)   execution time : 9.413 s
Press any key to continue.
*/

