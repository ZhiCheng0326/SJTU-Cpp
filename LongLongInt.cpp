 //File:LongLongInt.h
#ifndef LONGLONGINT_H
#define LONGLONGINT_H
#include <cstring>
#include <iostream>

using namespace std;

class LongLongInt
{
    public:
        LongLongInt(char *temp);
        LongLongInt();
        LongLongInt(const LongLongInt &c);
        void add(const LongLongInt &a, const LongLongInt &b);
        void display();
        ~LongLongInt(){delete[]num;}

    private:
        char *num;
        int numcount = 0;

};

#endif // LONGLONGINT_H
__________________________________________________________________________________________________________________________________________
 //File:LongLongInt.cpp
 #include "LongLongInt.h"

LongLongInt::LongLongInt(char *temp)
{
    numcount = strlen(temp);
    num = new char[numcount+1]; //extra one for '\0'
    for(int i = 0; i<numcount; i++){
        num[i] = temp[i];
    }
    num[numcount] = '\0';
}

LongLongInt::LongLongInt()
{
}

LongLongInt::LongLongInt(const LongLongInt &c)      //copy constructor
{
    numcount = c.numcount;
    num = new char[numcount+1];         //extra one for '\0'
    for(int i = 0; i<numcount; ++i){
        num[i]= c.num[i];
    }
    num[numcount] = '\0';
}

void LongLongInt::add(const LongLongInt &a, const LongLongInt &b)
{
    delete []num;
    (a.numcount>=b.numcount) ? (numcount= a.numcount): (numcount = b.numcount);
    num = new char[numcount+2];             //extra one for '\0' and num[0] to store number '1' if sum value > 9
    num[numcount+1] = '\0';
    int numindex = numcount;
    int aindex = a.numcount-1;
    int bindex = b.numcount-1;
    char total;
    num[0] = 'x';                   //if num[0] = 'x' means the sum of both first digit of the LongLongInt< 10
    int addTens = 0;
    while(numindex>=1){             //begin adding from the back
        if(aindex < 0){
            total = b.num[bindex]+addTens;
        }
        else if(bindex <0){
            total = a.num[aindex]+addTens;
        }
        else{
            total = a.num[aindex] + b.num[bindex] - '0' + addTens;
        }

        if(total>'9'){
            num[numindex] = total - 10;      //back to remainder
            addTens = 1;
            if(aindex-1 < 0 && bindex-1 < 0){
                num[0] = '1';
            }
        }
        else{
            num[numindex] = total;
            addTens = 0;
        }
        numindex--;aindex--;bindex--;
    }
}

void LongLongInt::display()
{
    if (num[0] != 'x'){
            cout << num;
    }
    else{
        for(int i = 1; i<= numcount; ++i){          // num[0] = 'x', thus start printing from num[1]
            cout << num[i];
        }
    }
    cout << endl;
    cout << endl;
}
_______________________________________________________________________________________________________________________________________________
 //File:main.cpp
 #include "LongLongInt.h"

using namespace std;

int main()
{
    LongLongInt a = "933333333333880";
    LongLongInt b = "99999999999999";
    LongLongInt sumIs;

    cout << "A:";
    a.display();
    cout << "B:";
    b.display();

    sumIs.add(a,b);
    cout << "After adding A & B:" ;
    sumIs.display();

    LongLongInt c = a;

    cout <<"After equal"<<endl;
    cout << "A:";
    a.display();
    cout << "C:";
    c.display();

    sumIs.add(a,b);
    cout << "After adding A & B:" ;
    sumIs.display();

    sumIs.add(a,c);
    cout << "After adding A & C:" ;
    sumIs.display();

    return 0;
}
