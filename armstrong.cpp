#include <iostream>
#include <cstring>

using namespace std;

bool armstrong(int l, int r)
{
    int rem, total, temp, answer;
    bool flag = false;
    for(int i=l; i<=r; ++i){
        temp = i;
        total = 0;

        while(temp!=0){
            rem = temp%10;
            total += rem * rem * rem;
            temp=(temp-rem)/10;
        }
        if (total==i && flag){
            cout << endl << i;
        }
        else if(total == i && !flag){
            cout<< i;
            flag = true;
        }
    }
    return flag;
}

int main()
{
    int left, right;
    cin >> left >> right;

    if (left < 0 || right < 0){cout << "error";}
    else if (left > right){cout << "error";}
    else if(!armstrong(left, right)){cout<< "no";}
    
    system ("PAUSE");
    return 0;
}
