//notes regarding the difference between the location of 'constant'

#include<iostream>

using namespace std;

void f( const int  *ptr ) 
{
    	     *ptr=3;   //ERROR
            ptr++;  //OK
}

void f( int * const  ptr ) 
{
            *ptr=3;  //OK
            ptr++;   //ERROR
}

void f( const int * const ptr ) 
{
    	        *ptr=3; //ERROR
               ptr++;   //ERROR
};
