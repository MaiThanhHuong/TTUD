#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool checkPhoneNumber(const string &sdt)
{
    return sdt.length() == 10;
}

int main()
{
    string call;
    cin >> call;
    map<string, ll> call_from;
    map<string, ll> call_time;
    int count = 0;
    bool ok = true;
    while (call != "#")
    {
        if (call == "call")
        {
            char number1[15], number2[15], yyyy, mm, dd;
            int fh, fm, fs, endh, endm, ends;
            scanf("%s %s %d-%d-%d %d:%d:%d %d:%d:%d", &number1, &number2, &yyyy, &mm, &dd, &fh, &fm, &fs, &endh, &endm, &ends);

            string from_number(number1), to_number(number2);
            if (!checkPhoneNumber(from_number) || !checkPhoneNumber(to_number))
            {
                ok = false;
            }
            count++;
            call_from[from_number]++;
            call_time[from_number] += (endh - fh) * 3600 + (endm - fm) * 60 + (ends - fs);
        }
        cin >> call;
    }
    string q;
    cin >> q;
    while (q != "#")
    {
        if (q == "?check_phone_number")
        {
            cout << (ok ? "1" : "-1") << "\n";
        }
        else if (q == "?number_calls_from")
        {
            string s;
            cin >> s;
            cout << call_from[s] << "\n";
        }
        else if (q == "?number_total_calls")
        {
            cout << count << "\n";
        }
        else if (q == "?count_time_calls_from")
        {
            string s;
            cin >> s;
            cout << call_time[s] << "\n";
        }
        cin >> q;
    }

    return 0;
}
