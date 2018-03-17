#include <iostream>
#include <cmath>

using namespace std;

int bin(int n, int base)
{
    int result = 0, power = 0;
    while (n > 0) {
        result += (n % base) * round(pow(10, power)); // you have to round it because pow(10, bring in value from var = 2) gives 99.999
        n /= base;
        power++;
    }

    return result;
}

int main()
{
    int base, n;

    cout << "insert number: ";
    cin >> n; cout << endl;

    do {
        cout << "Please enter bit system between 2 to 20: ";
        cin >> base;
        cout << endl;
    } while (base < 2 && base > 20);

    int result = bin(n, base);
    cout << result << endl;
    system("pause");

    return 0;
}
