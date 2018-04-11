#include <iostream>

using namespace std;


int main()
{
    char city[5] = {'a', 'b', 'c', 'd',  'e'};
    char *ptrcity[5];
    char **p;

    for (int i = 0; i < 5; i++) {
      ptrcity[i] = &city[i]; // assign the address of integer.
   }

    for (p=ptrcity; p<ptrcity+5; ++p){
        cout << **p << endl;
    }      

    /*output:
    a
    b
    c
    d
    e
    */

    system("PAUSE");
    return 0;
}
