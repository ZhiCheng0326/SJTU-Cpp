#include <iostream>
#include <cstring>

using namespace std;

void lower(char toLower[], bool keep, char capital[])
//only keep the capital letter of input need to keep
{
    for(int i=0; toLower[i] != '\0'; ++i){
        if (keep && (toLower[i]>= 'A' && toLower[i] <= 'Z')){
            capital[i] = toLower[i];
            toLower[i] = toLower[i]+32;
        }
        else if(!keep && (toLower[i]>= 'A' && toLower[i] <= 'Z')){
            toLower[i] = toLower[i]+32;
        }
    }
}

bool alienInBetween(char input[], char arr[], char punctuation[],int &head, int &tail, bool &senFound)
{
// return true if unknown characters found
    bool alien = true;
    for(int i = head+1; i<=tail-1; ++i){
        for(int j = 0; arr[j]!= '\0'; ++j){
            if (input[i] == arr[j] || (input[i]>='a' && input[i]<='z') || (input[i]>='1' && input[i]<='9') || input[i] == ' '){
                for(int k = 0; punctuation[k] != '\0'; ++k){
                    if(punctuation[k]==input[i]){senFound=false;}
                }
                alien = false;
                break;
            }
        }
        if(alien){return alien;}
    }
    return alien;
}

bool sensitive(char input[], char **p, int &head, int &tail, int senSize)
{
    bool senFound = false;
    for(char **i= p; *i != '\0'; i++){
        bool foundHead = false;
        int init = 0;
        for (char *j = *i;  *j != '\0'; j++){
            for(int k = init; input[k] != '\0'; ++k){
                if (foundHead && *j == input[k]){
                    if(k > tail) {tail = k;}
                    senFound = true;
                    break;
                }
                else if(!foundHead && *j == input[k] ){
                    if(k < head) {
                        head = k;
                        foundHead  = true;
                        init = k+1;
                    }
                    break;
                }
            }
            if(!foundHead) {break;}     //after loop through whole string, continue to find the next head
        }
    }
    if(!senFound) {head = 0; tail = strlen(input)-1;};      // after looping whole sensitive string, if no head and tail found point to it's real head and tail
    return senFound;
}

void printOutput(char input[], char capital[], int &head, int &tail, bool &senFound)
// print from arr[0] until head of sensitive char and from tail of sensitive char to arr[size-1]
{
    cout<< "After filter:";
    if (!senFound){
        for(int x=0; input[x]!= '\0'; ++x){
            if (capital[x]>='A' && capital[x]<='Z'){cout << capital[x];}
            else {cout << input[x];}
        }
        cout << endl << endl;
    }
    else{
        for(int x=0; x<head; ++x) {
            if (capital[x]>='A' && capital[x]<='Z'){cout << capital[x];}
            else {cout << input[x];}
        }
        if (head > 0){
            for(int z=head; z<=tail; ++z){
            cout << " ";
            }
        }
        for(int y=tail+1; input[y] != '\0'; ++y){
            if (capital[y]>='A' && capital[y]<='Z'){cout << capital[y];}
            else {cout << input[y];}
        }
        cout <<endl<<endl;
    }
}

int combine(char arr[], char combineList[], int next)
//combine all the list into one to check if a character is in the list. If not found, it's an unknown character
{
    for(int i = 0; arr[i] != '\0'; ++i){
        combineList[next] = arr[i];
        next++;
    }
    return next;
}

int main()
{
    char *punctuation, **sensitiveChar, *useless, *rawInput, *combineList;
    int next = 0, inputLength, punctuationCount, senCount, uselessCount, i=0;
//    char useless[5] = {'@','#','$', ' '};
//    char sensitiveChar[4][4] = {{'L','4'}, {'F','d'}, {'D','2','6'}};
//    char punctuation[4] = {',','.','"'};

    cout << "Please enter number of useless:";      //open dynamic memory for useless char
    cin >> uselessCount;
    useless = new char [uselessCount+1]{'0'};       //size +1 to store '\0'
    cout << "Please input useless character:";
    cin >> useless;

    cout << "\nPlease enter number of punctuation:";        //open dynamic memory for punctuation
    cin >> punctuationCount;
    punctuation = new char [punctuationCount+1]{'0'};       //size +1 to store '\0'
    cout << "Please input punctuation:";
    cin >> punctuation;

    cout << "\nPlease enter number of sensitive words:";        //open dynamic memory for 2 dimensions sensitive words
    cin >> senCount;
    cout << endl;
    sensitiveChar = new char*[senCount+1];              //size +1 to store '\0'
    for(int x = 0; x < senCount; ++x){
        sensitiveChar[x] = new char[20];
    }
    cout << "Please input sensitiveChar(aa bb cc):";
    while(i < senCount){
        cin >> sensitiveChar[i];
        ++i;
    }
    sensitiveChar[i] = {'\0'};              //as a mark to the end
    //end getting input

    //combine all the list into one
    combineList = new char [20* senCount + uselessCount + punctuationCount+1]{'0'};     //size +1 to store '\0'
    for(int i = 0; i < senCount; ++i){
            lower(sensitiveChar[i],false, NULL);
    }
    for(int j = 0; j < senCount; ++j){
        next = combine(sensitiveChar[j],combineList,next);
    }
    next = combine(useless,combineList,next);
    next = combine(punctuation,combineList,next);
    //end combining

    cout << "Please enter length of input accepted:";       //open dynamic memory for user Input
    cin >> inputLength;
    cin.sync();
    rawInput = new char[inputLength+1]{'0'};        //size +1 to store '\0'

    while(true){
        char *capitalLetter;
        capitalLetter = new char [inputLength+1]{'0'};      //open dynamic memory for capital letter list
        bool senFound;
        cout << "Enter string(Not more than " << inputLength << " characters):" << endl;
        cin.getline(rawInput,inputLength+10);       // add more memory to detect extra input

        lower(rawInput, true, capitalLetter);
        bool alien = false;

        int head=strlen(rawInput)-1, tail= 0;
        senFound = sensitive(rawInput, sensitiveChar, head,tail,senFound);
        alien = alienInBetween(rawInput,combineList, punctuation, head, tail, senFound);

        if (alien ||strlen(rawInput)>inputLength){
            cout << "Input does not meet the requirement.\n\n";
            cin.clear();
        }

        else{
            printOutput(rawInput,capitalLetter, head, tail, senFound);
        }

        delete[] rawInput;
    }

    delete [] useless;
    delete [] punctuation;
    for(int i = 0; i < senCount; ++i){
        delete [] sensitiveChar[i];
    }
    delete [] sensitiveChar;
    delete [] combineList;

    return 0;
    system("PAUSE");
}
