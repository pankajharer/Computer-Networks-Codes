#include <bits/stdc++.h>
#include <ctime>
#define ll long long int
using namespace std;
void transmission(ll &i, ll &N, ll &tf, ll &tt)
{
    while (i <= tf)
    {
        int z = 0;
        for (int k = i; k < i + N && k <= tf; k++)
        {
            cout << "Sending Frame " << k << "..." << endl;
            tt++;
        }
        for (int k = i; k < i + N && k <= tf; k++)
        {
            int f = rand() % 2;
            if (!f)
            {
                cout << "\nAcknowledgment for Frame " << k << "...\n"
                     << endl;
                z++;
            }
            else
            {
                cout << "\nTimeout!!\n--> Frame Number : " << k << " Not Received" << endl;
                cout << "** Retransmitting Window...\n"
                     << endl;
                break;
            }
        }
        cout << "\n";
        i = i + z;
    }
}

int main()
{
    ll tf, N, tt = 0;
    srand(time(NULL));
    cout << "\n\n\t\t ======== GO BACK N ARQ ========\n\n\n";
    cout << "--> Enter the Total number of frames : ";
    cin >> tf;
    cout << "\n --> Enter the Window Size : ";
    cin >> N;
    ll i = 1;
    transmission(i, N, tf, tt);
    cout << "\n\n\t Total number of frames which were sent and resent are : " << tt << endl;
    return 0;
}
