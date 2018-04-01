#include <iostream>

/*Search for longest palindrome in a long text. Output includes it's length and the sentence. */

using namespace std;

bool isAlphabet(char character){
    if (character <'A' || (character >'Z' && character < 'a') || character >'z'){
        return false;
    }
    else{
        return true;
    }      
}

void skipNonAlphabet(int &left, int &right, int length, char input[])
{
    while (!isAlphabet(input[left]) && left >= 0){left--;}
    while (!isAlphabet(input[right]) && right < length){right++;}
}

void checkPalindrome(int prev, int next, int length, char input[], int &thisHead, int &thisTail, int &thisSum,bool odd)
{
    if (input[prev]==input[next]){

                while(input[prev] == input[next] && prev >= 0 && next < length){
                    thisSum += 2;
                    prev--;
                    next++;
                    skipNonAlphabet(prev, next, length,input);
                }
            thisHead = prev + 1;
            thisTail = next -1;
            skipNonAlphabet(thisTail, thisHead, length,input);
            }
    if (odd) {thisSum +=1 ;}
}

void printOutput(int lastHead, int lastTail,char temp[],char input[])
{
    for(int j = lastHead; j <= lastTail; ++j){

        if (temp[j] >= 'A' && temp[j]<='Z'){
            cout << temp[j];
        }
        else{
            cout << input[j];
        }   
    }
    cout << endl; //output --> Madam,I'm Adam.
}

void lowerCase(int &length, char temp[], char input[])
{
    for (int k = 0; input[k] != '\0'; ++k){
        length++;
        if (input[k]>='A' && input[k]<='Z'){
            temp[k]=input[k];
            input[k]=input[k]+32;
        }
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
    bool odd = true;

    lowerCase(length, temp, input);

    for(int i = 1; i < length; ++i){

        if (!isAlphabet(input[i])) {continue;}

            prev = i-1;
            next = i+1;
            skipNonAlphabet(prev, next, length, input);
            checkPalindrome(prev, next, length, input, thisHead, thisTail, thisSum,odd);
   
            prev = i;
            next = i+1;
            skipNonAlphabet(prev, next, length,input);
            checkPalindrome(prev, next, length, input, thisHead, thisTail, thisSum,!odd);

        if (thisSum > lastSum){
                lastSum = thisSum;
                thisSum = 0;
                lastHead = thisHead;
                lastTail = thisTail;
            }
            else{
                thisSum = 0;
            }
    }
    cout << lastSum << endl;
    printOutput(lastHead,lastTail,temp,input);

    system("PAUSE");
    return 0;
    }
