#include <iostream>
#include <cstring>

using namespace std;

// this programs are required to get user input and sort the city names according to the alphabetical order.

int main()
{
    int i = 0; char *left, *right;
    char name[30];
    cout << "Please input the names of cities, 1 city per line(@--end):" << endl;
    char *cityList[30];
    cin >> name;

    while (name[0]!= '@'){ 
        cityList[i] = new char[strlen(name)+1];   //create dynamic array for the 1st dimension
        strcpy(cityList[i++], name);              //copy city name into the 1st dimension list
        cin >> name;
    }

    bool flag = true;
    while(flag){
        flag = false;
        for(int x= 0; x<i-1; ++x){
            if (strcmp(cityList[x], cityList[x+1])>0){
                left = cityList[x];             //left is a pointer to store the address of the 1st dimention array at the left
                right = cityList[x+1];          //right is a pointer to store the address of the 1st dimension array at the right
                cityList[x] = right;
                cityList[x+1] = left;
                flag = true;
            }
        }
    }

    for(int j = 0; j<i; j++){
        cout<< cityList[j] << endl;
        delete [] cityList[j];          
    }
    
    system("PAUSE");
    return 0;
}

/* error: 
char temp[30];
temp = cityList[x];             //should use a pointer but not array

or 

strcpy(temp,cityList[j]);       //using copy function not suitable for different size array
*/
