 //File:LongLongInt.h
#ifndef LONGLONGINT_H
#define LONGLONGINT_H
#include <cstring>
#include <iostream>

using namespace std;

class LongLongInt
{
    friend LongLongInt operator+(const LongLongInt &n1,const LongLongInt &n2);
    friend ostream &operator <<(ostream &os, const LongLongInt& n);
    public:
        LongLongInt &operator=(const LongLongInt &right);
        LongLongInt(char *temp);
        LongLongInt();
        LongLongInt(const LongLongInt &c);
        ~LongLongInt(){delete[]num;}

    private:
        char *num;
        int numcount = 0;

};

#endif // LONGLONGINT_H
_________________________________________________________________________________________________________________________________________
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

LongLongInt operator+(const LongLongInt &n1,const LongLongInt &n2)
{
    LongLongInt temp;
    (n1.numcount>=n2.numcount) ? (temp.numcount= n1.numcount+1): (temp.numcount = n2.numcount+1);
    temp.num = new char[temp.numcount+2];             //extra one for '\0' and num[0] to store number '1' if sum value > 9
    temp.num[temp.numcount+1] = '\0';
    temp.num[0] = 'x';                   //if num[0] = 'x' means the sum of both first digit of the LongLongInt< 10
    int numindex = temp.numcount-1;
    int aindex = n1.numcount-1;
    int bindex = n2.numcount-1;
    char total;
    int addTens = 0;
    while(numindex>=1){             //begin adding from the back
        if(aindex < 0){
            total = n2.num[bindex]+addTens;
        }
        else if(bindex <0){
            total = n1.num[aindex]+addTens;
        }
        else{
            total = n1.num[aindex] + n2.num[bindex] - '0' + addTens;
        }
        if(total>'9'){
            temp.num[numindex] = total - 10;      //back to remainder
            addTens = 1;
            if(aindex-1 < 0 && bindex-1 < 0){
                temp.num[0] = '1';
            }
        }
        else{
            temp.num[numindex] = total;
            addTens = 0;
        }
        numindex--;aindex--;bindex--;
    }
    return temp;
}

LongLongInt& LongLongInt::operator=(const LongLongInt &right)
{
    delete []num;
    num = new char [right.numcount+1];
    numcount = right.numcount;
    num[numcount]='\0';
    for(int i=0; i<right.numcount; ++i){
        num[i] = right.num[i];
    }
    return *this;
}

ostream &operator <<(ostream &os, const LongLongInt& n)
{
    if (n.num[0] != 'x'){
            os << n.num;
    }
    else{
        for(int i = 1; i<= n.numcount; ++i){          // num[0] = 'x', thus start printing from num[1]
            os << n.num[i];
        }
    }
    return os;
}
_______________________________________________________________________________________________________________________________________________
 //File:main.cpp
#include "LongLongInt.h"

using namespace std;

int main()
{
    LongLongInt a = "11111111111111113";
    LongLongInt b = "9222222222222223";
    LongLongInt sumIs;

    cout << "a:" << a <<endl;
    cout << "b:" << b <<endl;

    sumIs = a+b;
    cout<<endl;
    cout << "a + b = " ;
    cout << sumIs << endl;

    LongLongInt c = a;

    cout<<endl;
    cout << "After equal, c = a" << endl;
    cout << "a:" << a << '\t';
    cout << "c:" << c << endl;

    sumIs = a;
    cout << endl;
    cout << "After equal, sumIs = a" << endl;
    cout << "sumIs:" << sumIs << '\t';
    cout << "a: " << a << endl;

    sumIs = a+c;
    cout << endl;
    cout << "a + c = "<< sumIs << endl;

    return 0;
}
