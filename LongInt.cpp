/* This practice mainly for inheritance purpose. Create a derived class, LongInt which inherit from LongLongInt based class with more function added.

Main function in LongLongInt based class include : add, <<, =
Main function in LongInt derived class include: add, minus, comparison, ++, --, >> , <<, = 
*/


//LongLongInt.h
#ifndef LONGLONGINT_H
#define LONGLONGINT_H
#include <cstring>
#include <iostream>

using namespace std;

class LongLongInt
{
    friend LongLongInt operator+(const LongLongInt &n1,const LongLongInt &n2);
    friend ostream &operator <<(ostream &os, const LongLongInt &n);

    public:
        LongLongInt &operator=(const LongLongInt &right);
        LongLongInt(char *temp);
        LongLongInt();
        LongLongInt(const LongLongInt &c);
        int getCnt()const {return numcount;};                       //const class object can only call const function
        char &getNum(int i=0)const {return *(num+i);};              //return num array
        bool getNeg()const {return isNegative;};                    //return isNegative
        void setNumcount(int x){numcount=x;};                       //return numcount
        void setNegative(bool x){isNegative = x;};                  //modify isNegative
        void setNum(int x){num = new char[x]; num[x-1]='\0';};      //initialize num array
        ~LongLongInt(){delete[]num;}

    private:
        char *num;
        int numcount = 0;
        bool isNegative = false;

};

#endif // LONGLONGINT_H

//LongLongInt.cpp
#include "LongLongInt.h"

LongLongInt::LongLongInt(char *temp)
{
    int x = 0;
    if (temp[0] == '-'){
        isNegative = true;
        x = 1;
        numcount = strlen(temp)-1;
    }
    else{
        numcount = strlen(temp);
    }
    num = new char[numcount+1];                     //extra one for '\0'
    for(int i = 0; i<numcount; i++){
        num[i] = temp[x];
        ++x;
    }
    num[numcount] = '\0';
}

LongLongInt::LongLongInt()
{
    num = new char[2];
}

LongLongInt::LongLongInt(const LongLongInt &c)      //copy constructor
{
    numcount = c.numcount;
    num = new char[numcount+1];                     //extra one for '\0'
    for(int i = 0; i<numcount; ++i){
        num[i]= c.num[i];
    }
    num[numcount] = '\0';
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
LongLongInt operator+(const LongLongInt &n1,const LongLongInt &n2)
{
    LongLongInt temp;
    (n1.numcount>=n2.numcount) ? (temp.numcount= n1.numcount+1): (temp.numcount = n2.numcount+1);
    temp.num = new char[temp.numcount+1];             //extra one for '\0' and num[0] to store number '1' if sum value > 9
    temp.num[temp.numcount] = '\0';
    temp.num[0] = '0';                   //if num[0] = 'x' means the sum of both first digit of the LongLongInt< 10
    int numindex = temp.numcount-1, aindex = n1.numcount-1, bindex = n2.numcount-1;
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

ostream &operator <<(ostream &os, const LongLongInt& n)
{
    for(int i = 0; i<n.numcount; ++i){
        if(n.num[i]=='0' && n.num[i+1]=='0' && i==0 && i+1<n.numcount){
            os << '0';
            break;
        }
        else if(n.num[i]=='0' && n.num[i+1]!='0' && i==0 && i+1<n.numcount){
            continue;
        }
        os << n.num[i];
    }
    return os;
}

//LongInt.h
#ifndef LONGINT_H
#define LONGINT_H
#include "LongLongInt.h"

class LongInt : public LongLongInt
{
    friend LongInt operator-(const LongInt &n1, const LongInt &n2);
    friend LongInt operator-(const LongInt &obj);                        //negative number
    friend LongInt operator+(const LongInt &n1, const LongInt &n2);
    friend ostream &operator <<(ostream &os, const LongInt &obj);
    friend istream &operator >>(istream &is, LongInt &obj);
    friend bool operator <(const LongInt &n1, const LongInt &n2);
    friend bool operator >(const LongInt &n1, const LongInt &n2);
    friend bool operator >=(const LongInt &n1, const LongInt &n2);
    friend bool operator <=(const LongInt &n1, const LongInt &n2);
    friend bool operator !=(const LongInt &n1, const LongInt &n2){return (strcmp(&n1.getNum(),&n2.getNum())!=0);};
    friend bool operator ==(const LongInt &n1, const LongInt &n2){return (strcmp(&n1.getNum(),&n2.getNum())==0);};

    public:
        LongInt(char *temp):LongLongInt(temp),lliNum(temp){}; //num = LongLongInt::getNum() error
        LongInt &operator=(const LongLongInt &right);
        LongInt &operator=(const LongInt &right);
        LongInt();
        LongInt(const LongInt &c);
        LongInt &operator ++();                   //++a
        LongInt operator ++(int);                 //a++
        LongInt &operator --();                   //--a
        LongInt operator --(int);                 //a--
        ~LongInt(){}
    private:
        LongLongInt lliNum;
};

#endif // LONGINT_H

//LongInt.cpp
#include "LongInt.h"

LongInt::LongInt()
{
}

LongInt::LongInt(const LongInt &c)      //copy constructor
{
    this->lliNum = c.lliNum;    //LongLongInt = LongLongInt
    setNumcount(c.getCnt());
    setNum(c.getCnt());
    setNegative(c.getNeg());
    for(int i = 0; i<getCnt(); ++i){
        getNum(i)= c.getNum(i);
    }
}

LongInt operator-(const LongInt &obj)     //convert to -ve number
{
    LongInt temp;
    temp = obj;     //LongInt = LongInt
    temp.setNegative(!temp.getNeg());
    return temp;
}

LongInt operator+(const LongInt &n1,const LongInt &n2)
{
    LongInt temp;
    if(n1.getNeg() && !n2.getNeg()){return (n2-(-n1));}
    else if(!n1.getNeg() && n2.getNeg()){return (n1-(-n2));}
    else if(n1.getNeg() && n2.getNeg()){temp.lliNum.setNegative(true);}
    temp.lliNum = n1.lliNum + n2.lliNum;
    temp = temp.lliNum; //LongInt = LongLongInt
    return temp;
}

LongInt operator-(const LongInt &n1, const LongInt &n2) //minus function
{
    LongInt temp;
    if(n1.getNeg() && !n2.getNeg()){return (n1+(-n2));}
    else if(n1.getNeg() && n2.getNeg()){return(-n2-(-n1));}
    else if(!n1.getNeg() && n2.getNeg()){return(-n2+n1);}
    const LongInt *big; const LongInt *small;
    if(n1.getCnt()>n2.getCnt()||(n1.getCnt()==n2.getCnt()&&strcmp(&n1.getNum(),&n2.getNum())>=0)){
        big=&n1;
        small=&n2;
    }
    else{
        temp.setNegative(true);
        big = &n2;
        small= &n1;
    }
    (n1.getCnt()>=n2.getCnt()) ? temp.setNumcount(n1.getCnt()): temp.setNumcount(n2.getCnt());
    temp.setNum(temp.getCnt()+1);
    int numindex = temp.getCnt()-1, bindex = big->getCnt()-1, sindex=small->getCnt()-1, minusOne = 0;

    while(numindex>=0){
        if(sindex<0){
            temp.getNum(numindex) = big->getNum(bindex) + minusOne;
        }
        else if(big->getNum(bindex)<small->getNum(sindex)){
            temp.getNum(numindex) = (big->getNum(bindex))-(small->getNum(sindex))+10 + '0' + minusOne; //add '0' as num array store ascii code
            minusOne = -1;
            }
        else if(big->getNum(bindex)>=small->getNum(sindex)){
            temp.getNum(numindex) = (big->getNum(bindex))-(small->getNum(sindex))+ '0' + minusOne;
            minusOne = 0;
        }
        --numindex;--bindex;--sindex;
    }

    return temp;
}

LongInt& LongInt::operator=(const LongLongInt &right)       //LongInt = LongLongInt
{
    delete [] &getNum();
    setNum(right.getCnt()+1);
    setNumcount(right.getCnt());
    for(int i=0; i<getCnt(); ++i){
        getNum(i) = right.getNum(i);
    }
    setNegative(right.getNeg());
    return *this;
}

LongInt& LongInt::operator=(const LongInt &right)           //LongInt = LongInt
{
    delete [] &getNum();
    setNum(right.getCnt()+1);
    lliNum.setNum(right.getCnt()+1);
    setNumcount(right.getCnt());
    lliNum.setNumcount(right.getCnt());
    for(int i=0; i<getCnt(); ++i){
        getNum(i) = right.getNum(i);
        lliNum.getNum(i) = right.getNum(i);
    }
    setNegative(right.getNeg());
    return *this;
}

ostream &operator<<(ostream &os, const LongInt &obj)        //cout num array
{
    if(obj.getNeg()){cout << '-';}
    cout << obj.lliNum;

    return os;
}

istream &operator>>(istream &is, LongInt &obj)              //cin num array
{
    char *temp;
    int limit = 20, cnt=0;
    obj.lliNum.setNum(limit);
    for(int index = 0; obj.lliNum.getNum(index-1)!='\n'; ++index){
        obj.lliNum.getNum(index) = is.get();
        if(obj.lliNum.getNum(0)== '-'){             //check if input is negative number
            index = -1;
            obj.lliNum.setNegative(true);
            continue;
        }
        ++cnt;
        if (index==limit-2){                        //should be limit-2 instead of limit-1
            temp = new char[limit];                 //create temp dynamic array
            strcpy(temp,&obj.lliNum.getNum());      //copy num to temp
            limit += 20;                            //increase limit
            delete [] &obj.lliNum.getNum();         //delete num array
            obj.lliNum.setNum(limit);               //create increased size num array
            strcpy(&obj.lliNum.getNum(),temp);      //copy temp to num
            delete[]temp;                           //delete num
        }
    }
    --cnt;
    obj.lliNum.setNumcount(cnt);
    obj = obj.lliNum;   //LongInt = LongLongInt

    return is;
}

bool operator <(const LongInt &n1, const LongInt &n2)
{
    if((n1.getNeg() && !n2.getNeg()) || ((n1.getNeg() && n2.getNeg()||!n1.getNeg() && !n2.getNeg() && strcmp(&n1.getNum(),&n2.getNum())<0)) || (!n1.getNeg() && !n2.getNeg() && n1.getCnt()<n2.getCnt())){
        return true;
    }
    else{
        return false;
    }
}

bool operator >(const LongInt &n1, const LongInt &n2)
{
    if((!n1.getNeg() && n2.getNeg()) || ((n1.getNeg() && n2.getNeg() || !n1.getNeg() && !n2.getNeg()) && strcmp(&n1.getNum(),&n2.getNum())>0) || (!n1.getNeg() && !n2.getNeg() && n1.getCnt()>n2.getCnt())){
        return true;
    }
    else{
        return false;
    }
}

bool operator <=(const LongInt &n1, const LongInt &n2)
{
    if((n1.getNeg() && !n2.getNeg()) || ((n1.getNeg() && n2.getNeg() || !n1.getNeg() && !n2.getNeg()) && strcmp(&n1.getNum(),&n2.getNum())<=0) || (!n1.getNeg() && !n2.getNeg() && n1.getCnt()<=n2.getCnt())){
        return true;
    }
    else{
        return false;
    }
}

bool operator >=(const LongInt &n1, const LongInt &n2)
{
    if((!n1.getNeg() && n2.getNeg()) || ((n1.getNeg() && n2.getNeg() || !n1.getNeg() && !n2.getNeg()) && strcmp(&n1.getNum(),&n2.getNum())>=0) || (!n1.getNeg() && !n2.getNeg() && n1.getCnt()>=n2.getCnt())){
        return true;
    }
    else{
        return false;
    }
}

LongInt &LongInt::operator++()
{
    LongInt one = "1";
    *this = *this + one;
    return *this;
}

LongInt LongInt::operator++(int x)
{
    LongInt temp = *this;
    LongInt one = "1";
    *this = *this + one;
    return temp;
}

LongInt &LongInt::operator--()
{
    LongInt one = "1";
    *this = *this - one;
    return *this;
}

LongInt LongInt::operator--(int x)
{
    LongInt temp = *this;
    LongInt one = "1";
    *this = *this - one;
    return temp;
}


//main.cpp
#include "LongLongInt.h"
#include "LongInt.h"

using namespace std;

int main()
{
    LongInt num1 = "11111111111111113";
    LongInt num2 = "9222222222223";
    LongInt sumIs;

    cout << "num1:" << num1 <<endl;
    cout << "num2:" << num2 <<endl;

    sumIs = num1 + num2;
    cout<<endl;
    cout << "num1 + num2 = " ;
    cout << sumIs<<endl;

    LongInt num3 = num1;
    cout<<endl;
    cout <<"After equal, num3 = num1"<<endl;
    cout << "num1:" << num1 << '\t';
    cout << "num3:" << num3<<endl;

    LongInt num4, num5, subtract;
    cout << endl;
    cout << "Enter number for num4: ";
    cin >> num4;
    cout << "Enter number for num5: ";
    cin >> num5;
    sumIs = num4+num5;
    cout<<endl;
    cout << "num4 + num5 = "<<sumIs<<endl;
    subtract = num4-num5;
    cout << "num4 - num5 = "<<subtract<<endl;
    ++num4; num5++;
    cout << "++num4: " << num4 << endl <<"++num5: "<< num5 <<endl;
    num4--; num5--;
    cout << "num4--: " << num4 << endl <<"num5--: "<< num5 <<endl;
    cout << "num4 >= num5: " << (num4>=num5) << endl;

    return 0;
}

