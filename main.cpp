#include <iostream>
using namespace std;

int a[100000], f[100000], b[100000];
int n, k;

bool v[100000];
int looplist[100000];
int loopcount;

int main()
{

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        a[i] = i;
    }

    loopcount = 0;

    // 循环 数据的次数
    for (int i=1; i<=n; i++)
    {
        if (v[i] == true) continue;

        int m = i;  int p = i;
        int c = 0;

        while(v[p] != true)
        {
            v[p] = true;
            c++;
            p = f[p];
        }

        cout << "c=" << c << endl;
        loopcount = loopcount + 1;
        looplist[loopcount] = c;
    }

    int isum = looplist[1];

    for (int index=2; index <= loopcount; index++)
    {
        int ia = looplist[index];

        int temp = ia;
        if (temp != 1)
        {
            if (isum % temp == 0)
            {
                isum = isum;
            }else if (temp % isum == 0)
            {
                isum = temp;
            }
            else
            {
                isum = temp * isum;
            }
        }


    }

    cout << "isum=" << isum << endl;

    int countx = k % isum;
    int* src = a;
    int* dest = b;

    for (int i = 1; i <= countx; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dest[f[j]] = src[j];
        }

        int* temp = src;
        src = dest;
        dest = temp;
    }

    // 循环结束，打印 a 数组

    for (int i = 1; i <= n; i++)
    {
        cout << src[i] << " ";
    }
    cout << endl;
    return 0;
}
