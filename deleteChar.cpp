#include <iostream>
#include <cstring>

//delete requested char and cout in descending alphabetical order
/* Input:               Output:
    e                   tongji
    shangejiao          shangjiao
    fudean              shangchai
    teongji             fudan
    shangcai
    @
    
*/
using namespace std;

int main()
{
    char toDelete;
    bool flag = true;
    cin>> toDelete;
    int num = 0,cnt;

    char arr[30][30];
    while(cin>>arr[num]){
        if (arr[num][0]=='@'){break;}
        ++num;
    }

    for(int i=0; arr[i][0]!='@'; ++i){
        for(int j=0; j<30; ++j){
            if(arr[i][j]==toDelete){
                cnt = j;
                while(arr[i][cnt]!='\0'){
                    arr[i][cnt] = arr[i][cnt+1];
                    ++cnt;
                }
                --j;
            }
        }
    }
    char temp[30];
    while(flag){
        flag = false;
        for(int i=0; i<num-1; ++i){
            if(strcmp(arr[i],arr[i+1])<0){
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
                flag = true;
            }
        }
    }

    for(int i=0; i<num; ++i){
        if(i== num-1){cout<< arr[i];}
        else{cout<< arr[i]<<endl;}
    }
    return 0;
}
