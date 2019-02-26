/*
Khadeja Khalid
Winter 2017
19 January 2017
Lab 1
Problem 1.1
This program asks the user how many strings they want,
and has them input their string values, then prints
their requested strings line by line
*/

#include <iostream>
#include <string>

using namespace std;

void getSize  (int &inputSize);
void getSpace (int inputSize, string *&heap);
void inputData(int inputSize, string *data);
void printData(int inputSize, string *data);
void Destroy  (string *data);

int main()
{
   int inputSize;
   string *spaceSize;

   getSize(inputSize);
   getSpace(inputSize, spaceSize);
   inputData(inputSize, spaceSize);
   printData(inputSize, spaceSize);
   Destroy(spaceSize);

   return 0;
}

/* ******************getSize*************************
Asks the user the number of strings the they want.
Saves number into reference parameter
************************************************** */

void getSize(int &inputSize)
{
    cout << "How many strings do you want?: ";
    cin >> inputSize;
}

/* *******************getSpace*************************
Gets an array in the heap of the size requested
**************************************************** */

void getSpace(int inputSize, string *&str)
{
    str = new string[inputSize];
}

/* *******************inputData************************
Asks the user to input strings and stores into array
**************************************************** */

void inputData(int inputSize, string *data)
{

    for (int count = 0; count < inputSize; count++)
    {
        cout << "Enter string #" << count+1 <<": ";
        cin >> data[count];
    }

}

/* *********************printData**********************
Prints all the strings, one line per string
**************************************************** */

void printData(int inputSize, string *data)
{
    for (int index = 0; index < inputSize; index++)
    {
        cout << data[index] << endl;
    }
}

/* **********************destroy***********************
Returns all the space to the heap
**************************************************** */
void Destroy(string *data)
{
    delete [] data;
}

/*
How many strings do you want?: 2
Enter string #1: hot
Enter string #2: dog
hot
dog

Process returned 0 (0x0)   execution time : 16.024 s
Press any key to continue.
*/
