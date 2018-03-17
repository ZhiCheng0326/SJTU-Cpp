#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int B;
    while(B < 2 or B >20){
        cout << "Please enter bit system between 2 to 20: " ;
        cin >> B;
        cout << endl;
    }

    for (int i = 64; i <= 64; ++i){
        int div = i, power = 0, convertedNum = 0;
        while(div != 0){
            convertedNum = convertedNum +((div % 8) * (pow(10,power)));
            cout << convertedNum << endl;
            div = div / B;
            cout << "div" << div <<endl;

            power += 1;
            cout << "power"<<power << endl;

            cout <<endl;
        }
        //cout << convertedNum<< endl;
    }

    return 0;
}
