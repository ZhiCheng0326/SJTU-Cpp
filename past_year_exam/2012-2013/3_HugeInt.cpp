/* Create a HugeInt class. Functions include +,<<
Handle only 30 characters. Outherwise, treat it as 0. Output 0 if sum result > 30 characters.

Input:
0000                                    00
00012                                   7
123456789012345678901234567890          999999999999999999999999999999
12345678901234567890123456789099        678

Output:
0
19
0
678
*/ 
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class HugeInt
{
    friend HugeInt operator+(const HugeInt &num1, const HugeInt &num2);
    friend ostream &operator<<(ostream &os, const HugeInt &obj);

    public:
        HugeInt(const char *str);
        HugeInt(const HugeInt &obj);
        HugeInt();
        ~HugeInt(){delete[]num;}

    private:
        char *num;
        int numCount = 0;
};

HugeInt::HugeInt()
{
}

HugeInt::HugeInt(const HugeInt &obj)        //copy constructor
{
    numCount = obj.numCount;
    num = new char[numCount];
    for(int i=0; i<obj.numCount; ++i){
        num[i] = obj.num[i];
    }

}
HugeInt::HugeInt(const char *str)           //constructor
{
    int x = strlen(str);
    num = new char[x];
    bool foundHead = false;
    for(int i=0; i<x; ++i){
        if(str[i] == '0' && !foundHead){continue;}            //convert 00123 to 123
        foundHead = true;
        num[numCount] = str[i];
        ++numCount;
    }
    if(numCount>30 || !foundHead){
        delete []num;
        num = new char[1]{'0'};
        numCount = 1;
    }
}

HugeInt operator+(const HugeInt &num1, const HugeInt &num2)
{
    HugeInt tempObj;
    char *temp1, *temp2, total;
    int length, len1 = num1.numCount, len2 = num2.numCount;
    len1 > len2 ? length = len1+1 : length = len2+1;        //extra space to store Tens if sum > 9
    temp1 = new char[length];
    temp2 = new char[length];
    tempObj.num = new char[length];
    tempObj.numCount = length;

    for(int i=0; i<length; ++i){
        --len1;--len2;
        len1 >= 0 ? temp1[i] = num1.num[len1] : temp1[i] = '0';     //make two num same length,at the same time revert it
        len2 >= 0 ? temp2[i] = num2.num[len2] : temp2[i] = '0';     //eg: 120 + 5 become 0120 + 5000
    }

    for(int j=0; j<length; ++j){
        total = temp1[j] + temp2[j] - '0';
        if (total > '9'){
            total -= 10;
            temp1[j+1] += 1;
        }
        tempObj.num[j] = total;
    }
    if(tempObj.num[tempObj.numCount-1] == '0')--tempObj.numCount;       //reduce word count for case "930"
    delete []temp1;
    delete []temp2;
    return tempObj;

}

ostream &operator<<(ostream &os, const HugeInt &obj)
{
    bool foundHead = false;
    for(int i=obj.numCount-1; i>=0; --i){
        if(obj.numCount-1 > 29){
            os << 0;
            os << endl;
            return os;
        }
        else{
            if(obj.num[i] == '0' && !foundHead ){       //skip if first character is 0
                continue;
            }
            else{
                foundHead = true;
                os << obj.num[i];
            }
        }
    }
    if(!foundHead) os<<0;
    os << endl;
    return os;
}

int main()
{
    ifstream fin("hugeint.in");
    if(!fin){cerr << "infile open error";return -1;}
    ofstream fout("hugeint.out");
    if(!fin){cerr << "outfile open error";return -1;}

    char str1[41], str2[41];
    while(fin>>str1)
    {
        fin>>str2;
        HugeInt op1(str1);
        HugeInt op2(str2);
        fout<< op1 + op2;
    }

    fin.close();
    fout.close();

    return 0;
}

/*Notes:
- Case: 0012 + 7
- Case: 123456789012345678901234567890 + 123456789012345678901234567890
- Case: 123456789012345678901234567890 + 677
- Case: 91 + 12
- Case: 0 + 0
- Case: 000000789012345678901234567890 + 677
- Case: 000000000000000000000000000000 + 0000
*/
