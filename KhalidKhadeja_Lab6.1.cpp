/**
Khadeja Khalid
CIS 22B
Winter 2017
27 March 2017
Lab 6
Problem 6.1
This program will change the implementation of the StringOfCars class, but will
keep the public interface. The implementation will use a linked list, rather than
an array or vector to hold the cars.
This function will read from a file, and print it out in a neat format using linked lists
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


/************************************* Car class *******************************************/

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

class StringOfCars;

/**************************************** Node Class ***************************************/

class Node
{
private:
    Node *next;
    Car *data;

    //Default constructor that sets next and data pointers to zero
    Node()
    {
        next = NULL;
        data = NULL;
    }

public:

    //Make StringOfCars a friend class
    friend class StringOfCars;

};

/************************************* StringOfCars Class **********************************/

class StringOfCars : public Car
{
private:
    Node *head;
    Node *tail;

public:
    //Default constructor to set head and tail pointers to zero
    StringOfCars()
    {
        head = 0;
        tail = 0;
    }

    //Adds a Car to the string of cars
    void push(const Car &car)
    {
        Car *currentCarPtr;
        Node *currentNodePtr;

        //Use new to get space in the heap for a Node and save the address of the space in the heap in currentNodePtr
        currentNodePtr = new Node;

        //Use new get space in the heap for a new Car that is a copy of the car parameter of the push
        //function and save the address of the space in the heap in currentCarPtr
        currentCarPtr = new Car(car);

        //Set the data pointer in this new Node object to point to the new Car object
        currentNodePtr->data = currentCarPtr; /** ?? */

        if (head == 0)
        {
            //Set the head and the tail pointer to the value of the currentNodePtr;
            head = currentNodePtr;
            tail = currentNodePtr;
        }
        else
        {
            /**Set the next pointer of the node object pointed to by the tail pointer to the value of currentNodePtr */

            tail->next = currentNodePtr;

            //Set the next pointer to the value of the currentNodePtr
            tail = currentNodePtr;

        }

    }

    //Copy constructor
    StringOfCars(const StringOfCars &obj)
    {

        Node *currentNodePtr;
        head = 0;
        tail = 0;

        if (head != 0)
        {
            while (currentNodePtr != 0)
            {
                //push the Car pointed to by the data pointer in the current Node, which is pointed to by the currentNodePointer.
                push(*(currentNodePtr->data)); /** ?? */

                //currentNodePtr->next=0;

                //set the currentNodePtr to the next pointer in the currentNodePtr so we now make the next Node the current Node
                currentNodePtr = currentNodePtr->next; /** ?? */
            }
        }
    }


    //Prints a heading for each car
    void printData2()
    {
        Node *currentNodePtr;

        if (head = 0)
        {
            cout << "NO cars" << endl;
        }
        else
        {
            currentNodePtr = head;

            while (currentNodePtr != 0)
            {
                //print the car pointed to by the currentNodePtr
                currentNodePtr->data->printData();

                //set the currentNodePtr to the next pointer in the Node pointed to by the currentNodePtr,
                //which now makes the next Node the current Node
                currentNodePtr = currentNodePtr->next;

            }
        }
    }

    //Destructor
    ~StringOfCars()
    {
        delete head;
        delete tail;
    }

}; //End class StringOfCars

/*************************************** FreightCar Class **********************************/

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

/********************************* PassengerCar Class **************************************/

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

/************************************************* Main *************************************************/

int main()
{

    StringOfCars stringOfCars1;

    getData(stringOfCars1);
    stringOfCars1.printData2();

    cout << endl;

	return 0;
}

/************************************** buildCar *********************************************
When called, this function will build an object of type Car by
using the Car constructor that has five parameters
*********************************************************************************************/

void buildCar (Car *carPtr, string &type, string &order, string &rMark, int &cNum, string &make,
               bool &state, string &dest, StringOfCars &stringOfCars1)
{
    carPtr -> setUp(type, order, rMark, cNum, make, state, dest);

    stringOfCars1.push(*carPtr);
}

/************************************** buildFreightCar *************************************
When called, this function will build an object of type FreightCar
by using the FreightCar constructor that has five parameters
********************************************************************************************/

void buildFreightCar (FreightCar *carPtr, string &type, string &order, string &rMark, int &cNum,
                      string &make, bool &state, string &dest, StringOfCars &stringOfCars1)
{
    carPtr -> setUp(type, order, rMark, cNum, make, state, dest);

    stringOfCars1.push(*carPtr);
}

/*************************************** buildPassengerCar **********************************
When called, this function will build an object of type PassengerCar
by using the PassengerCar constructor that has five parameters
********************************************************************************************/

void buildPassengerCar (PassengerCar *carPtr, string &type, string &order, string &rMark,
                        int &cNum, string &make, bool &state, string &dest, StringOfCars &stringOfCars1)
{
    carPtr -> setUp(type, order, rMark, cNum, make, state, dest);

    stringOfCars1.push(*carPtr);
}

/**************************************** printData *****************************************
This member function will print the data in a neat order
********************************************************************************************/

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

/************************************* setUpCar *********************************************
This member function will pass five variables
********************************************************************************************/

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

/*************************************** Car::Operator **************************************
Sets the values in the left hand object to the right hand
********************************************************************************************/

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

/*************************************** Friend Function ************************************
This function will test to see if two objects are equivalent. The two objects are equivalent
if they have the same reportingMark and cNumber (not looking at the kind, loaded, or destination)
********************************************************************************************/

bool operator == (const Car &first, const Car &second)
{
    if (first.reportingMark == second.reportingMark &&
        first.carNumber     == second.carNumber)
        return true;

    else
        return false;
}

/***************************************** getData ******************************************
This function will get the specific information needed about the car from a file.
********************************************************************************************/

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

    inputFile.open("cardata61.txt");

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
