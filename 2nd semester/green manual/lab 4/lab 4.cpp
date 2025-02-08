//variant 17
#include <iostream>
using namespace std;
int main() {
    //1
    int ring[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int k;
    cout << "      1st task:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << ring[i] << " ";
    }
    cout << endl;
    cout << "enter k: ";
    cin >> k;
    //2
    cout << "      2nd task:" << endl;
    cout << "print to left from " << k << endl;
    for (int i = k; i >= 0; i = i--)
    {
        cout << ring[i] << " ";
        if (i == 0)
        {
            for (int ii = 9; ii >= k; ii--)
            {
                cout << ring[ii] << " ";
            }
        }
    }
    cout << endl;
    //3
    cout << "      3rd task:" << endl;
    cout << "idk" << endl;
    //4
    cout << "      4th task" << endl;
    for (int i = k; i < 10; i++)
    {
        cout << ring[i] << " ";
        if (i == 9)
        {
            for (int ii = 0; ii <= k; ii++)
            {
                cout << ring[ii] << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
