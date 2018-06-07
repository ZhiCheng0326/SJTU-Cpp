//set.h
#ifndef SET_H
#define SET_H
#include <iostream>

using namespace std;

template <class T> class Set;
template <class T> ostream &operator<<(ostream &os, const Set<T> &obj);
//template <class T> Set<T> operator*(const Set<T> &s1, const Set<T> &s2);
//template <class T> Set<T> operator+(const Set<T> &s1, const Set<T> &s2);
//template <class T> Set<T> operator-(const Set<T> &s1, const Set<T> &s2);

template <class T>
class Set
{
    friend Set<T> operator*(const Set<T> &s1, const Set<T> &s2);
    friend Set<T> operator+(const Set<T> &s1, const Set<T> &s2);
    friend Set<T> operator-(const Set<T> &s1, const Set<T> &s2);
    friend ostream &operator<<(ostream &os, const Set<T> &obj);

    public:
        Set(const T arr[]);     //constructor
        Set(const Set<T> &obj); //copy constructor
        ~Set(){delete []num;}

    private:
        T *num;
        int numcount;
};

#endif // SET_H

template <class T>
Set<T>::Set(const T arr[])
{
    numcount = sizeof(arr)/sizeof(*arr);
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

//template <class T>
//Set<T> operator*(const Set<T> &s1, const Set<T> &s2)    //union
//{
//    Set<T> temp;
//    temp.numcount = s1.numcount + s2.numcount;
//    temp.num = new T[temp.numcount];
//    for(int i=0; i<s1.numcount; ++i){       //copy whole s1 into array
//        temp.num[i] = s1.num[i];
//    }
//
//    bool exist;
//    int tempTail = s1.numcount;
//    for(int j=0; j<s2.numcount; ++j){
//        exist = false;
//        for(int k=0; k<s1.numcount; ++k){
//            s2.num[j]==s1.num[k] ? exist= true : exist = false;
//            if(exist){break;}
//        }
//        if(!exist){temp.num[tempTail] = s2.num[j];}
//    }
//
//    return temp;
//}
//
//template <class T>
//Set<T> operator+(const Set<T> &s1, const Set<T> &s2)    //intersect
//{
//    Set<T> temp;
//    temp.num = new T[s1.numcount + s2.numcount];
//    for(int i=0; i<s1.numcount;++i){
//        for(int j=0; j<s2.numcount; ++j){
//            if(s1.num[i]==s2.num[j]){
//                temp.num[temp.numcount] = s1.num[i];
//                ++temp.numcount;
//            }
//        }
//    }
//    --temp.numcount;
//
//    return temp;
//}
//
//template <class T>
//Set<T> operator-(const Set<T> &s1, const Set<T> &s2)
//{
//    Set<T> temp;
//    temp.num = new T[s1.numcount + s2.numcount];
//    for(int i=0; i<s1.numcount;++i){
//        for(int j=0; j<s2.numcount; ++j){
//            if(s1.num[i]!=s2.num[j]){
//                temp.num[temp.numcount] = s1.num[i];
//                ++temp.numcount;
//            }
//        }
//    }
//    --temp.numcount;
//
//    return temp;
//}

template <class T>
ostream &operator<<(ostream &os, const Set<T> &obj)
{
    for(int i=0; i<obj.numcount;++i){
        os << obj.num[i];
    }

    return os;
}


//main.cpp
#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
    int a[] = {1,2,3,4};
    int b[] = {4,5,6,7};
    Set<int> set1(a);
    Set<int> set2(b);

    cout << set1;

//    cout << s1 * s2;    //union
//    cout << set1 + set2;    //intersect
//    cout << s1 - s2;

    return 0;
}
