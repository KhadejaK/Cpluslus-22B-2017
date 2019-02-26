/*
Khadeja Khalid
Winter 2017
7 February 2017
Lab 2
Problem 2.2
This program will ask the user specific questions
about their car and print it back out
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Car
{
    public:
        string reportingMark,
               kind,
               destination;
        bool   loaded;
        int    carNumber;

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
    void setReportingMark(string mark);
    void setCarNumber    (int num);
    void setKind         (string make);
    void setLoaded       (bool state);
    void setDestination  (string dest);

    //Accessor member function prototype, NO CHANGE
    string getReportingMark() const
    {
        return reportingMark;
    }
    int    getCarNumber()     const
    {
        return carNumber;
    }
    string getKind()          const
    {
         return kind;
    }
    bool   getLoaded()        const
    {
         return loaded;
    }
    string getDestination()   const
    {
        return destination;
    }

    /* *******************setUpCar**********************
    This function creates an object using a constructor
    that takes the reference parameters pointer to the
    object c1 returned
    ************************************************* */

    Car* setUpCar(string mark, int num, string make,
                bool state, string dest)
    {
        Car *c1 = new Car(mark, num, make, state, dest);
        return c1;
    };

}; //end class car

void getData  (string &mark, int &num, string &make,
            bool &state, string &dest);
void printData(Car *ptr);
/* **********************Main*********************** */
int main()
{

    string mark, make, dest;
    bool state;
    int num;

    getData(mark, num, make, state, dest);

    Car *ptr;
    ptr = ptr -> setUpCar(mark, num, make, state, dest);

    printData(ptr);

    delete ptr;

	return 0;
}

/* ********************getData**************************
This function will get the specific input needed
***************************************************** */
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
       cin.ignore();
       getline (cin, mark);
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

    cin.ignore();
    cout << "Enter the destination or NONE: ";
    getline (cin, dest);
}

/* *******************printData*************************
This function will print the data
***************************************************** */
void printData(Car *ptr)
{
    cout << endl;
    cout << left << setw(20) << "Reporting Mark: ";
    cout << right << setw(15) << ptr-> reportingMark << endl;
    cout << left << setw(20) << "Car Number: ";
    cout << right << setw(15) << ptr->carNumber << endl;
    cout << left << setw(20) << "Kind: ";
    cout << right << setw(15) << ptr->kind << endl;
    cout << left << setw(20) << "Loaded: ";
    cout << right << setw(15) << boolalpha << ptr->loaded << endl;
    cout << left << setw(20) << "Destination: ";
    cout << right << setw(15) << ptr->destination << endl;
    cout << endl;
}
/*
Enter the Reporting Mark: SP
Enter the Car Number: 34567
Enter the kind of car(could be box tank flat or other): box
Is it loaded? (true or false only): true
Enter the destination or NONE: Salt Lake City

Reporting Mark:                  SP
Car Number:                   34567
Kind:                           box
Loaded:                        true
Destination:         Salt Lake City


Process returned 0 (0x0)   execution time : 14.275 s
Press any key to continue.
*/



