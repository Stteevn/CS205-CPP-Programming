//====================================================
// http://cpp.sh/
// https://www.onlinegdb.com/
//====================================================

//====================================================
// Program example 1
// twoarg.cpp -- a function with 2 arguments
#include <iostream>
using namespace std;
void n_chars(char, int);
int main() {
    int times;
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    while (ch != 'q')  // q to quit
    {
        cout << "Enter an integer: ";
        cin >> times;
        n_chars(ch, times);  // function with two arguments
        cout << "\nEnter another character or press the"
                " q-key to quit: ";
        cin >> ch;
    }

    cout << "The value of times is " << times << ".\n";
    cout << "Bye\n";

    return 0;
}

void n_chars(char c, int n)  // displays c n times
{
    while (n-- > 0)  // continue until n reaches 0
        cout << c;
}

//====================================================
// Program example 2

// arrfun1.cpp -- functions with an array argument
#include <iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);  // prototype
int main() {
    using namespace std;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    // some systems require preceding int with static to
    // enable array initialization
    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << "\n";

    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total = total + arr[i];

    return total;
}

//====================================================
// Program example 3
// arrfun2.cpp -- functions with an array argument
#include <iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);
// use std:: instead of using directive
int main() {
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    // some systems require preceding int with static to
    // enable array initialization
    std::cout << cookies << " = array address, ";
    // some systems require a type cast: unsigned (cookies)
    std::cout << sizeof cookies << " = sizeof cookies\n";
    int sum = sum_arr(cookies, ArSize);
    std::cout << "Total cookies eaten: " << sum << std::endl;

    sum = sum_arr(cookies, 3);  // a lie
    std::cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, 4);  // another lie
    std::cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}
// return the sum of an integer array
int sum_arr(int arr[], int n) {
    int total = 0;
    std::cout << arr << " = arr, ";
    // some systems require a type cast: unsigned (arr)
    std::cout << sizeof arr << " = sizeof arr\n";
    for (int i = 0; i < n; i++) total = total + arr[i];

    return total;
}

//====================================================
// Program example 4
// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;
// function prototypes
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);  // don't change data
void revalue(double r, double ar[], int n);
int main() {
    using namespace std;
    double properties[Max];
    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0) {
        cout << "Enter revaluation factor: ";
        double factor;

        while (!(cin >> factor))  // bad input
        {
            cin.clear();
            while (cin.get() != '\n') continue;

            cout << "Bad input; Please enter a number: ";
        }

        revalue(factor, properties, size);
        show_array(properties, size);
    }

    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}

int fill_array(double ar[], int limit) {
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)  // bad input
        {
            cin.clear();
            while (cin.get() != '\n') continue;

            cout << "Bad input; input process terminated.\n";
            break;
        } else if (temp < 0)  // signal to terminate
            break;

        ar[i] = temp;
    }

    return i;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], int n) {
    using namespace std;
    for (int i = 0; i < n; i++) {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], int n) {
    for (int i = 0; i < n; i++) ar[i] *= r;
}

//====================================================
// Program example 5
// arrfun4.cpp -- functions with an array range
#include <iostream>
const int ArSize = 8;
int sum_arr(const int *begin, const int *end);
int main() {
    using namespace std;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    // some systems require preceding int with static to
    // enable array initialization
    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr(cookies, cookies + 3);  // first 3 elements
    cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, cookies + 8);  // last 4 elements
    cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}
// return the sum of an integer array
int sum_arr(const int *begin, const int *end) {
    // begin[0] = 99;
    const int *pt;
    int total = 0;
    for (pt = begin; pt != end; pt++) total = total + *pt;

    return total;
}

//====================================================
// Program example 6
// Example program
#include <iostream>
#include <string>

int sum(int (*ar2)[4], int size);
// int sum(int ar2[][4], int size);

int main() {
    int data[3][4] = {{1, 2, 3, 4}, {9, 8, 7, 6}, {2, 4, 6, 8}};
    int total = sum(data, 3);

    std::cout << "The sum of array is: " << total << "!\n";
}

int sum(int ar2[][4], int size) {
    int total = 0;
    for (int r = 0; r < size; r++)
        for (int c = 0; c < 4; c++) total += ar2[r][c];

    return total;
}

//====================================================
// Program example 7
// strgfun.cpp -- functions with a string argument
#include <iostream>
unsigned int c_in_str(const char *str, char ch);
int main() {
    using namespace std;
    char mmm[15] = "minimum";  // string in an array
    // some systems require preceding char with static to
    // enable array initialization

    char *wail = "ululate";  // wail points to string
    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;

    return 0;
}

// this function counts the number of ch characters
// in the string str
unsigned int c_in_str(const char *str, char ch) {
    unsigned int count = 0;
    while (*str)  // quit when *str is '\0'
    {
        if (*str == ch) count++;
        str++;  // move pointer to next char
    }
    return count;
}

//====================================================
// Program example 8
// strgback.cpp -- a function that returns a pointer to char
#include <iostream>
char *buildstr(char c, int n);  // prototype
int main() {
    using namespace std;
    int times;
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete[] ps;             // free memory
    ps = buildstr('+', 20);  // reuse pointer
    cout << ps << "-DONE-" << ps << endl;
    delete[] ps;  // free memory

    return 0;
}

// builds string made of n c characters
char *buildstr(char c, int n) {
    char *pstr = new char[n + 1];
    pstr[n] = '\0';               // terminate string
    while (n-- > 0) pstr[n] = c;  // fill rest of string

    return pstr;
}

//====================================================
// Program example 9
// travel.cpp -- using structures with functions
#include <iostream>
struct travel_time {
    int hours;
    int mins;
};

const int Mins_per_hr = 60;
travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main() {
    using namespace std;
    travel_time day1 = {5, 45};  // 5 hrs, 45 min
    travel_time day2 = {4, 55};  // 4 hrs, 55 min

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);
    travel_time day3 = {4, 32};
    cout << "Three-day total: ";
    show_time(sum(trip, day3));

    return 0;
}

travel_time sum(travel_time t1, travel_time t2) {
    travel_time total;
    total.mins = (t1.mins + t2.mins) % Mins_per_hr;
    total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;

    return total;
}
void show_time(travel_time t) {
    using namespace std;
    cout << t.hours << " hours, " << t.mins << " minutes\n";
}

//====================================================
// Program example 10
// strctptr.cpp -- functions with pointer to structure arguments
#include <cmath>
#include <iostream>
// structure templates
struct polar {
    double distance;  // distance from origin
    double angle;     // direction from origin
};
struct rect {
    double x;  // horizontal distance from origin
    double y;  // vertical distance from origin
};

// prototypes
void rect_to_polar(const rect *pxy, polar *pda);
void show_polar(const polar *pda);

int main() {
    using namespace std;
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y) {
        rect_to_polar(&rplace, &pplace);  // pass addresses
        show_polar(&pplace);              // pass address
        cout << "Next two numbers (q to quit): ";
    }

    cout << "Done.\n";
    return 0;
}

// show polar coordinates, converting angle to degrees
void show_polar(const polar *pda) {
    using namespace std;
    const double Rad_to_deg = 57.29577951;
    cout << "distance = " << pda->distance;
    cout << ", angle = " << pda->angle * Rad_to_deg;
    cout << " degrees\n";
}

// convert rectangular to polar coordinates
void rect_to_polar(const rect *pxy, polar *pda) {
    using namespace std;
    pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);
}

//====================================================
// Program example 11
// M13, Jupiter, sun, earth, moon
// topfive.cpp -- handling an array of string objects
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 5;
void display(const string sa[], int n);
int main() {
    string list[SIZE];  // an array holding 5 string object
    cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }

    cout << "Your list:\n";
    display(list, SIZE);
    return 0;
}

void display(const string sa[], int n) {
    for (int i = 0; i < n; i++) cout << i + 1 << ": " << sa[i] << endl;
}

//====================================================
// Program example 12
// arrobj.cpp -- functions with array objects (C++11)
#include <array>
#include <iostream>
#include <string>
// constant data
const int Seasons = 4;
const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall",
                                                 "Winter"};

// function to modify array object
void fill(std::array<double, Seasons> *pa);
// function that uses array object without modifying it
void show(std::array<double, Seasons> da);

int main() {
    std::array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);

    return 0;
}

void fill(std::array<double, Seasons> *pa) {
    using namespace std;
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da) {
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }

    cout << "Total Expenses: $" << total << endl;
}

//====================================================
// Program example 13
// recur.cpp -- using recursion
#include <iostream>
void countdown(int n);
int main() {
    countdown(4);  // call the recursive function
    return 0;
}

void countdown(int n) {
    using namespace std;
    cout << "Counting down ... " << n << endl;
    if (n > 0) countdown(n - 1);  // function calls itself

    cout << n << ": Kaboom!\n";
}

//====================================================
// Program example 14

// ruler.cpp -- using recursion to subdivide a ruler
#include <iostream>
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);
int main() {
    char ruler[Len];
    int i;
    for (i = 1; i < Len - 2; i++) ruler[i] = ' ';

    ruler[Len - 1] = '\0';
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    std::cout << ruler << std::endl;

    for (i = 1; i <= Divs; i++) {
        subdivide(ruler, min, max, i);
        std::cout << ruler << std::endl;

        for (int j = 1; j < Len - 2; j++)
            ruler[j] = ' ';  // reset to blank ruler
    }

    return 0;
}

void subdivide(char ar[], int low, int high, int level) {
    if (level == 0) return;

    int mid = (high + low) / 2;

    ar[mid] = '|';

    subdivide(ar, low, mid, level - 1);
    subdivide(ar, mid, high, level - 1);
}

//====================================================
// Program example 15

// fun_ptr.cpp -- pointers to functions
#include <iostream>
double betsy(int);
double pam(int);
// second argument is pointer to a type double function that
// takes a type int argument
void estimate(int lines, double (*pf)(int));
int main() {
    using namespace std;
    int code;
    cout << "How many lines of code do you need? ";
    cin >> code;
    cout << "Here's Betsy's estimate:\n";
    estimate(code, betsy);
    cout << "Here's Pam's estimate:\n";
    estimate(code, pam);

    return 0;
}
double betsy(int lns) { return 0.05 * lns; }
double pam(int lns) { return 0.03 * lns + 0.0004 * lns * lns; }

void estimate(int lines, double (*pf)(int)) {
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hour(s)\n";
}

//====================================================
// Program example 16
// arfupt.cpp -- an array of function pointers
#include <iostream>
// various notations, same signatures
const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int);
int main() {
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};

    // pointer to a function
    const double *(*p1)(const double *, int) = f1;

    auto p2 = f2;  // C++11 automatic type deduction

    // pre-C++11 can use the following code instead
    // const double *(*p2)(const double *, int) = f2;

    cout << "Using pointers to functions:\n";
    cout << " Address Value\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

    // pa an array of pointers
    // auto doesn't work with list initialization
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};

    // but it does work for initializing to a single value
    // pb a pointer to first element of pa
    auto pb = pa;
    // pre-C++11 can use the following code instead
    // const double *(**pb)(const double *, int) = pa;

    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address Value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;

    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

    //==================================================================
    // what about a pointer to an array of function pointers
    cout << "\nUsing pointers to an array of pointers:\n";
    cout << " Address Value\n";
    // easy way to declare pc
    auto pc = &pa;
    // pre-C++11 can use the following code instead
    // const double *(*(*pc)[3])(const double *, int) = &pa;

    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    // hard way to declare pd
    const double *(*(*pd)[3])(const double *, int) = &pa;
    // store return value in pdb
    const double *pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    // alternative notation
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;

    // cin.get();
    return 0;
}

// some rather dull functions
const double *f1(const double *ar, int n) { return ar; }
const double *f2(const double ar[], int n) { return ar + 1; }
const double *f3(const double ar[], int n) { return ar + 2; }

//====================================================
/////////////////////////////////////////////////////////////////////////