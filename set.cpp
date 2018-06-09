//set.h
#ifndef SET_H
#define SET_H
#include <iostream>

using namespace std;

template <class T>
class Set
{
    template <class Y>
    friend Set<Y> operator*(const Set<Y> &s1, const Set<Y> &s2);
    template <class Y>
    friend Set<Y> operator+(const Set<Y> &s1, const Set<Y> &s2);
    template <class Y>
    friend Set<Y> operator-(const Set<Y> &s1, const Set<Y> &s2);
    template <class Y>
    friend ostream &operator<<(ostream &os, const Set<Y> &obj);

    public:
        Set(const T arr[], int len);     //constructor
        Set(const Set<T> &obj);         //copy constructor
        Set(){};
        ~Set(){delete []num;}

    private:
        T *num;
        int numcount = 0;
};
#endif // SET_H

template <class T>
Set<T>::Set(const T arr[], int len)
{
    numcount = len;
    num = new T[numcount];
    for(int i=0; i<numcount; ++i){
        num[i] = arr[i];
    }

}
template <class T>
Set<T>::Set(const Set<T> &obj)
{
    numcount = obj.numcount;
    num = new T[numcount];
    for(int i=0; i<numcount; ++i){
        num[i] = obj.num[i];
    }
}

template <class T>
Set<T> operator*(const Set<T> &s1, const Set<T> &s2)    //union
{
    Set<T> temp;
    temp.num = new T[s1.numcount + s2.numcount];
    for(int i=0; i<s1.numcount; ++i){       //copy whole s1 into array
        temp.num[i] = s1.num[i];
        ++temp.numcount;
    }

    bool exist;
    int tempTail = s1.numcount;
    for(int j=0; j<s2.numcount; ++j){
        exist = false;
        for(int k=0; k<s1.numcount; ++k){
            s2.num[j]==s1.num[k] ? exist= true : exist = false;
            if(exist){break;}
        }
        if(!exist){
            temp.num[tempTail] = s2.num[j];
            ++tempTail;
            ++temp.numcount;
        }
    }
    return temp;
}

template <class T>
Set<T> operator+(const Set<T> &s1, const Set<T> &s2)    //intersect
{
    Set<T> temp;
    temp.num = new T[s1.numcount + s2.numcount];
    for(int i=0; i<s1.numcount;++i){
        for(int j=0; j<s2.numcount; ++j){
            if(s1.num[i]==s2.num[j]){
                temp.num[temp.numcount] = s1.num[i];
                ++temp.numcount;
            }
        }
    }

    return temp;
}

template <class T>
Set<T> operator-(const Set<T> &s1, const Set<T> &s2)
{
    Set<T> temp;
    bool exist;
    temp.num = new T[s1.numcount];
    for(int i=0; i<s1.numcount;++i){
            exist = false;
        for(int j=0; j<s2.numcount; ++j){
            if(s1.num[i]==s2.num[j])  exist = true;
        }
        if(!exist){
            temp.num[temp.numcount] = s1.num[i];
            ++temp.numcount;
        }
    }
    return temp;
}

template <class T>
ostream &operator<<(ostream &os, const Set<T> &obj)
{
    if(obj.numcount == 0){os << "Empty Set!" << endl; return os;}
    bool flag = true;
    T temp;
    while(flag){
        flag = false;
        for(int i=0; i<obj.numcount-1; ++i){
            if(obj.num[i] > obj.num[i+1]){
                temp = obj.num[i];
                obj.num[i] = obj.num[i+1];
                obj.num[i+1] = temp;
                flag = true;
            }
        }
    }
    os << obj.num[0];
    for(int i=1; i<obj.numcount;++i){
        os << " " << obj.num[i];
    }

    return os;
}
//main.cpp
#include "set.h"

using namespace std;

int main()
{
    int a[] = {1,2,3,4,10,11};
    int b[] = {4,5,6,7,2};
    int c[] = {4,5,6,7,2};

//    double a[] = {1.1, 2.0, 3.5, 4.1};
//    double b[] = {1.1, 2.1, 3.3, 4.1};
//    double c[] = {1.1, 2.1, 3.3, 4.1};
    int lenA = sizeof(a)/sizeof(a[0]), lenB = sizeof(b)/sizeof(b[0]), lenC = sizeof(c)/sizeof(c[0]) ;
    Set<int> set1(a, lenA);             ////Set<double> set1(a, lenA);
    Set<int> set2(b, lenB);             ////Set<double> set2(b, lenB);
    Set<int> set3(c, lenC);             ////Set<double> set3(c, lenC);

    cout << set1 << endl;
    cout << set2 << endl;
    cout << set3 << endl;

    cout << "set1 * set2 = " << set1 * set2 << endl;    //union
    cout << "set1 + set2 = " << set1 + set2 << endl;    //intersect
    cout << "set1 - set2 = " << set1 - set2 << endl;
    cout << "set2 - set3 = " << set2 - set3 << endl;

    return 0;
}
