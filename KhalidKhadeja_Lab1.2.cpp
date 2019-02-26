/*
Khadeja Khalid
Winter 2017
19 January 2017
Lab 1
Problem 1.1
This program will test the various string functions
*/

#include <iostream>
#include <string>
using namespace std;


int main()
{
    //Exercise 1.2.1
    string string1;
    cout << "Please enter string1: ";
    getline(cin, string1);
    cout << "Exercise 1" << endl;
    cout << string1 << endl << endl;

    //Exercise 1.2.2
    string string2;
    cout << "Please enter string2: ";
    getline(cin, string2);
    cout << "Exercise 2" << endl;
    cout << string1 << " " << string2 << endl;

    //Exercise 1.2.3
    string string3("bellow cello fellow hello mellow Novello Othello pillow Rollo solo yellow");
    int location1 = string3.find('h');
    cout << endl << "Exercise 3" << endl;
    cout << location1 << endl;

    //Exercise 1.2.4
    string string4;
    string4.assign(string3);
    string4.replace(location1, 1, "J");
    cout << endl << "Exercise 4" << endl;
    cout << string4 << endl;

    //Exercise 1.2.5
    string string5;
    string5.assign(string3);
    int location2 = string5.find_last_of('l');
    cout << endl << "Exercise 5" << endl;
    cout << location2 - 1 << endl;

    //Exercise 1.2.6
    string string6;
    string6.assign(string3);
    string6.erase(location2);
    cout << endl << "Exercise 6" << endl;
    cout << string6 << endl;

    cout << endl;
    return 0;
}

/*
Please enter string1: Good morning
Exercise 1
Good morning

Please enter string2: sleepy heads
Exercise 2
Good morning sleepy heads

Exercise 3
20

Exercise 4
bellow cello fellow Jello mellow Novello Othello pillow Rollo solo yellow

Exercise 5
69

Exercise 6
bellow cello fellow hello mellow Novello Othello pillow Rollo solo yel


Process returned 0 (0x0)   execution time : 9.891 s
Press any key to continue.
*/

