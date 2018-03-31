#include <iostream>

using namespace std;

bool isAlphabet(char character){
    if (character <'A' || (character >'Z' && character < 'a') || character >'z'){
        return false;
    }
    else{
        return true;
    }      
}

int main()
{
    char input[80];
    char temp[80];
    cout << "Please enter: ";           // Input is --> Confucius say:Madam,I'm Adam.
    cin.getline(input,80,'\n');
    
    int lastSum = 0,thisSum = 0,prev = 0,next =0,length = 0;
    int lastHead,lastTail,thisHead,thisTail;

    for (int k = 0; input[k] != '\0'; ++k){
        length++;
        if (input[k]>='A' && input[k]<='Z'){
            temp[k]=input[k];
            input[k]=input[k]+32;
        }
        else if (!isAlphabet(input[k])){
            temp[k]=input[k]; 
            int index = k;
            do{
                input[index]=input[index+1];
                index++;
            }
            while(input[index] != '\0');
            k--;                            //to go back to original k  
        }
    }
    // cout << input <<endl;
    // cout << temp << endl;

    for(int i = 1; i< length; ++i){

        if (!isAlphabet(input[i])){
            continue;
        }

            // prev = i-1;
            // next = i+1;
            // while (!isAlphabet(input[prev]) && prev >= 0){prev--;}
            // while (!isAlphabet(input[next]) && next < length){next++;}

            if (input[i-1]==input[i+1]){
                prev = i-1;
                next = i+1;
                while(input[prev] == input[next] && prev >= 0 && next < length){
                    thisSum++;
                    prev--;
                    next++;
                    // while (!isAlphabet(input[prev]) && prev >= 0){prev--;}
                    // while (!isAlphabet(input[next]) && next < length){next++;}
                }
            thisHead = prev + 1;
            thisTail = next -1;
            }         

            // prev = i;
            // next = i+1;
            // while (!isAlphabet(input[prev]) && prev >= 0){prev--;}
            // while (!isAlphabet(input[next]) && next < length){next++;}

            if (input[prev]==input[next]){
                prev = i;
                next = i+1;
                while(input[prev] == input[next] && prev >= 0 && next < length){
                    thisSum++;
                    prev--;
                    next++;
                    // while (!isAlphabet(input[prev]) && prev >= 0){prev--;}
                    // while (!isAlphabet(input[next]) && next < length){next++;}
                }
            thisHead = prev + 1;
            thisTail = next -1; 
            }  

        if (thisSum >= lastSum){
                lastSum = thisSum;
                thisSum = 0;
                lastHead = thisHead;
                lastTail = thisTail;
            }
            else{
                thisSum = 0;
            }
    }
    
    for(int j = lastHead; j <= lastTail; ++j){

        if (temp[j] <= 'a' && temp[j]>='z'){
            cout << temp[j];
        }
        else{
            cout << input[j];
        }   
    }
    cout << endl;

    system("PAUSE");
    return 0;
}
