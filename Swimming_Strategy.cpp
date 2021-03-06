#include <iostream>

/* this question request for the best method for n players from a team to dive from A to B. Max 2 person to share one gas tank.
Input number of players and time taken to swim across the river for each player.
Output the total time needed for the whole team to reach B. 
*/

using namespace std;

void sort(int A[], int n){
    int temp;
    bool flag = true;
    while(flag){                //to sort from smallest to highest

        int count = 0;
        for(int j=0; j < n-1; ++j){
            if (A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                }
            else{count ++;};
        }

        if (count == n-1){
            flag = false;
        }
    } 
}

int initialise(int A[], int B[], int time, int n) //choose the two fastest to go first.
{
    time += A[1];
    B[0] = A[0];
    B[1] = A[1];
    A[0] = 0;
    A[1] = 0;
    return time;
}

int to(int A[], int B[], int time, int n)   //choose the two slowest from A to B.
{   
    for(int i = n-1; i >= 0; i--){
        int prev = i-1;
        if (A[i] != 0) {
            while(A[prev]==0){ prev--; }
            time += A[i];
            B[prev] = A[prev];
            B[i] = A[i];
            A[i] = 0;
            A[prev] = 0;
            break;
        }
    }
    return time;
}

int back(int A[], int B[], int time, int n)     //choose the fastest to back to A.
{
    for(int i = 0; i < n; ++i){
        if (B[i] != 0) {
            time += B[i];
            A[i] = B[i];
            B[i] = 0;
            break;
        }  
    }
    return time;
}

int main()
{
    int n, index = 0, time = 0;
    int A[99] = {0}; 
    int B[99] = {0};
    cout << "Please input n:";
    cin >> n;

    while(cin >> A[index]){     //store data in list.
        index ++;
        if (index == n){break;}
    }

    sort(A,n);      //sort from smallest to greatest.
    time = initialise(A, B, time, n);

    bool allZero = false;
    while(!allZero){            //loop until array A all zero, meaning all at B.

        for(int i = 0; i<n; ++i){
            if (A[i] != 0){
                allZero = false;
                break;
            }
            else{allZero = true;}       //if allZero, break the loop. 
        }
        if(allZero){
            break;
        }
        else{
            time = back(A, B, time, n);

            if (A[0] != 0 && A[1] != 0){                //to decide whether are the two fastest at A, if yes allow the two fastest to go first.
                time = initialise(A, B, time, n);
            }
            else{                               //else, choose the two slowest to go.
                time = to(A, B, time, n);
            }
        }        
    }  
    cout << time << endl;

    system("PAUSE");
    return 0;
}
