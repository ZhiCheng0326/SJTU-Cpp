//simple vector class with add function

#include <iostream>
#include <fstream>

using namespace std;

class Vector
{
    friend ostream &operator<<(ostream &os, const Vector &obj);
    friend istream &operator>>(istream &is, const Vector &obj);
    friend Vector operator +(const Vector &v1, const Vector &v2);

    public:
        Vector(int sz);
        Vector(){};
        Vector(const Vector &obj);
        ~Vector(){delete[]num;}

    private:
        int *num;
        int numcount;

};

Vector::Vector(int sz)
{
    numcount = sz;
    num = new int[numcount];
}

Vector::Vector(const Vector &obj)
{
    numcount = obj.numcount;
    num = new int[numcount];
    for(int i=0; i<numcount; ++i){
        num[i] = obj.num[i];
    }
}

Vector operator+(const Vector &v1, const Vector &v2)
{
    Vector temp;
    temp.numcount = v1.numcount;
    temp.num = new int[temp.numcount];
    for(int i=0; i<temp.numcount; ++i){
        temp.num[i] = v1.num[i]+v2.num[i];
    }
    return temp;
}
ostream &operator<<(ostream &os, const Vector &obj)
{
    bool flag = false;
    for(int i=0; i<obj.numcount; ++i){
        if(flag){os << ',';}
        os << obj.num[i];
        flag = true;
    }
    return os;
}

istream &operator>>(istream &is, const Vector &obj)
{
    for(int i=0; i<obj.numcount; ++i){
        is>>obj.num[i];
    }
    return is;
}
int main()
{
    ifstream fin("vector.in");
    ofstream fout("vector.out");

    if(!fin){
        cerr << "Cannot open the input file";
        return -1;
    }
    if(!fout){
        cerr << "Cannot open the output file";
        return -1;
    }

    int n;
    fin >> n;

    Vector op1(n), op2(n);
    fin >> op1;
    fin >> op2;
    fout << op1+op2 <<endl;

    fin.close();
    fout.close();

    return 0;
}
