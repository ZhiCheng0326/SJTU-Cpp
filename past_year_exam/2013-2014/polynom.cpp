#include <iostream>
#include <fstream>

using namespace std;

class Polynom
{
    friend istream &operator>>(istream &is, Polynom &obj);
    friend ostream &operator<<(ostream &os, const Polynom &obj);
    friend Polynom operator+(const Polynom &o1, const Polynom &o2);

    public:
        Polynom(){};
        Polynom(const Polynom &obj);
        ~Polynom(){delete []arr;}

    private:
        int cnt = 0;
        int *arr;
};

Polynom::Polynom(const Polynom &obj)
{
    cnt = obj.cnt;
    arr = new int[cnt];
    for(int i=0; i<cnt; ++i){
        arr[i] = obj.arr[i];
    }
}

istream &operator>>(istream &is, Polynom &obj)
{
    is >> obj.cnt;
    obj.arr = new int[obj.cnt];
    for(int i=0; i<obj.cnt; ++i){
        is>>obj.arr[i];
    }

    return is;
}

ostream &operator<<(ostream &os, const Polynom &obj)
{
    bool flag = false;
    for(int i=0; i<obj.cnt; ++i){
        if(flag) os << '+';
        switch(obj.arr[i]){
            case ' ':
                break;

            case 0:
                os << 1;
                flag = true;
                break;

            case 1:
                os << 'x';
                flag = true;
                break;

            default:
                os << 'x' << '^' << obj.arr[i];
                flag = true;
                break;
        }
    }
    if(!flag){os << 0;}

    return os;
}

Polynom operator+(const Polynom &o1, const Polynom &o2)
{
    Polynom temp;
    bool found, flag = true;
    int z;
    temp.arr = new int [o1.cnt+o2.cnt];
    for(int i=0; i<o1.cnt; ++i){         //fill temp with o1 array elements
        temp.arr[i] = o1.arr[i];
        ++temp.cnt;                     //add count for every element added
    }
    for(int x=0; x<o2.cnt; ++x){                        //fill the temp array if elements in o2 not exists in temp array.
        found = false;
        for(int y=0; y<o1.cnt; ++y){
            o2.arr[x]==temp.arr[y] ? found = true: found = false;
            if(found){temp.arr[y] = ' '; break;}        //if exists, the temp array element become blank
        }
        temp.arr[temp.cnt] = found ? ' ' : o2.arr[x];
        ++temp.cnt;                                     //add count for every element added
    }

    while(flag){                            //sort from high to low
        flag = false;
        for(int i=0; i<temp.cnt-1; ++i){
            if(temp.arr[i]<temp.arr[i+1]){
                flag = true;
                z = temp.arr[i];
                temp.arr[i] = temp.arr[i+1];
                temp.arr[i+1] = z;
            }
        }
    }

    return temp;
}

int main()
{
    ifstream fin("polynom.in");
    if(!fin){
        cerr << "Cannot open the input file!";
        return -1;
    }
    ofstream fout("polynom.out");
    if(!fout){
        cerr << "Cannot open the output file!";
        return -1;
    }

    Polynom op1, op2;

    fin >> op1;
    fin >> op2;

    fout << op1 + op2 << endl;

    fin.close();
    fout.close();

    return 0;
}
/*Notes:
-rearrange from high to low
-do not revert the array and fill with blanks before adding
-change the origin temp array to blank (line87)
*/
