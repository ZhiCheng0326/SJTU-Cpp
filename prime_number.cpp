#include <iostream>
#include <cstring>

using namespace std;

/*
Input:        Output:
case1    90              2 3 3 5
case2    1024            2 2 2 2 2 2 2 2 2 2
case3    2               2
*/
int main()
{
    int N, k = 0;
    bool prime = true, flag = false;
    cin>>N;

    while(N%2 == 0){
        if (flag){
            cout << ' ' << 2;
        }
        else{
            cout << 2;
        }
        N/=2;
        ++k;
        flag = true;
    }
    for(int i=3; i<=N; ++i){
        prime = true;
        for(int j= 2; j<i; ++j){
            if(i%j ==0){
                prime = false;
            }
            if(prime){
                while( N%i == 0){
                    if(flag){
                        cout << ' ' << i;
                    }
                    else{
                        cout << i;
                    }
                    N/=i;
                    ++k;
                }
            }
        }
    }
    return 0;
}
