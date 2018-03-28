#include <iostream>

/* This program converts integer into alphabet for encryption purpose.
The encryption rule is:
    add the integer with 13 then convert into corresponding alphabet.
 */

using namespace std;

int main()
{
    int input;
    cout << "Please enter a 4 digit number: ";
    cin >> input;
    cout << endl;

    int i,j,k,l;

    l = input % 10;     //store ones
    input = (input-l) / 10;
    k = input % 10;     //store tens
    input = (input-k)/10;
    j = input % 10;     //store hundreds
    input = (input-j)/10;
    i = input;          //store thousands

    i+=13+64; //64 is the ascii before "A"
    j+=13+64;
    k+=13+64;
    l+=13+64;

    char a = static_cast <char> (i);      //convert integer into ascii
    char b = static_cast <char> (j);
    char c = static_cast <char> (k);
    char d = static_cast <char> (l);

    cout << "Guess yourself xD: " << a << b << c << d;

    return 0;
}
