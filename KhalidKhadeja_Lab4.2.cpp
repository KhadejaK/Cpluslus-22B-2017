/**
Khadeja Khalid
CIS 22B
Winter 2017
2 March 2017
Lab 4
Problem 4.2
This program will read the car's data from a separate file,
rather than from user input*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

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
void setReportingMark(string rMark)
    {reportingMark = rMark;}

void setCarNumber (int cNum)
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

Car & operator = (const Car &);

}; //end class car

/************************** printData ***************************
This member function will print the data in a neat order
*****************************************************************/

void Car::printData()
{
    cout << setw(18) << left << "Reporting Mark: "
         << setw(5) << reportingMark << endl;
    cout << setw(18) << left << "Car Number: "
         << setw(5) << carNumber << endl;
    cout << setw(18) << left << "Kind: "
         << setw(5) << kind << endl;
    cout << setw(18) << left << "Loaded: "
         << setw(5) << boolalpha << loaded << endl;
    cout << setw(18) << left << "Destination: "
         << setw(5) << destination << endl << endl;
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
   kind = make;
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


class StringOfCars
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
void push(Car car);

//Removes the car from a string of cars (LIFO)
void pop(Car &car);

}; //End class StringOfCars


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
}

void StringOfCars::push(Car car)
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

void StringOfCars::pop(Car &car)
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

void getData(StringOfCars &);

/**************************** Main ******************************/
int main()
{
    //Test Car operator= function
    cout << "TEST 1" << endl;
    cout << "********************************\n";
    cout << endl;
    Car car1("SP", 34567, "box", true, "Salt Lake City");
    Car car2 = car1;
    car2.printData();

    cout << endl;

    //Test the StringOfCars push function
    StringOfCars string1;
    cout << "TEST 2" << endl;
    cout << "********************************\n";

    getData(string1);
    string1.printData2();

    cout << endl;

    //Test StringOfCars pop function
    cout << "TEST 3" << endl;
    cout << "********************************\n";
    cout << endl;
    Car car3;
    string1.pop(car3);

    cout << "CAR 3" << endl;
    cout << "-----\n";
    car3.printData();

    cout << "STRING 1" << endl;
    cout << "--------\n";
    string1.printData2();

    cout << endl;

	return 0;
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

void getData(StringOfCars &string1)
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
            getline(inputFile, dest);

            Car temp(rMark, cNum, make, state, dest);
            string1.push(temp);
        }

    }

    inputFile.close(); //close file

}
