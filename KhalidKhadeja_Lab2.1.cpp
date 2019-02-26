/*
Khadeja Khalid
Winter 2017
7 February 2017
Lab 2
Problem 2.1
This program will ask the user specific questions
about their car and print it back out
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Car
{
    string reportingMark;
    string kind;
    string destination;
    bool   loaded;
    int    carNumber;


};

void getData(Car &);
void printData(Car);

int main()
{
    Car data;
    Car *ptr;

    getData(data);
    printData(data);

    //Obtain space and deletes it
    ptr = new Car;
    delete ptr;
    ptr=0;

    return 0;
}

/* *************************getData***************************************
This function will get the specific input needed from the user
*********************************************************************** */
void getData(Car &input)
{
    int length;
    cout << "Enter the Reporting Mark: ";
    getline(cin, input.reportingMark);
    length = input.reportingMark.length();

    while (length > 5)
    {
        cout << "Invalid! Must be less than 5 characters: ";
        cin.ignore();
        getline(cin, input.reportingMark);
        length = input.reportingMark.length();
    }
    for (int i=0; i < int (input.reportingMark.length()); i++)
        input.reportingMark[i] = toupper(input.reportingMark[i]);

    cout << "Enter the Car Number: ";
    cin >> input.carNumber;

    cout << "Enter the kind of car (could be box tank flat or other): ";
    cin >> input.kind;

    cout << "Is it loaded? (true or false only): ";
    cin >> boolalpha >> input.loaded;

    cin.ignore();
    cout << "Enter the destination or NONE: ";
    getline (cin, input.destination);

}

/* ************************printData**************************************
This function will print the data
*********************************************************************** */
void printData(Car input)
{
    cout << endl;
    cout << left << setw(20) << "Reporting Mark: ";
    cout << right << setw(15) << input.reportingMark << endl;
    cout << left << setw(20) << "Car Number: ";
    cout << right << setw(15) << input.carNumber << endl;
    cout << left << setw(20) << "Kind: ";
    cout << right << setw(15) << input.kind << endl;
    cout << left << setw(20) << "Loaded: ";
    cout << right << setw(15) << boolalpha << input.loaded << endl;
    cout << left << setw(20) << "Destination: ";
    cout << right << setw(15) << input.destination << endl;

}
/*
Enter the Reporting Mark: SP
Enter the Car Number: 34567
Enter the kind of car (could be box tank flat or other): box
Is it loaded? (true or false only): true
Enter the destination or NONE: Salt Lake City

Reporting Mark:                  SP
Car Number:                   34567
Kind:                           box
Loaded:                        true
Destination:         Salt Lake City

Process returned 0 (0x0)   execution time : 14.072 s
Press any key to continue.

*/
