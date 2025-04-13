#include <bits/stdc++.h>
using namespace std;

bool phoneNumberCheck(string str) {
    if (str.length() != 10) return false;
    for (int i = 0; i < str.length(); i++)
        if (str[i] < '0' || str[i] > '9') return false;
    return true;
}

int timeCalc(string start, string end) {
    int time1 = 3600 * ((start[0] - '0') * 10 + start[1] - '0') 
                + 60 * ((start[3] - '0') * 10 + start[4] - '0')
                + ((start[6] - '0') * 10 + start[7] - '0');
    int time2 = 3600 * ((end[0] - '0') * 10 + end[1] - '0') 
                + 60 * ((end[3] - '0') * 10 + end[4] - '0')
                + ((end[6] - '0') * 10 + end[7] - '0');
    return time2 - time1;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    // cout.tie(NULL);
    map <string, int> callCount, callTime;
    string input;
    int totalCount = 0;
    int incorrectNumber = 0;
    while (1) {
        cin >> input;
        if (input == "#") break;
        totalCount++;
        string caller, called, start, end, date;
        cin >> caller >> called >> date >> start >> end;
        if (!phoneNumberCheck(caller) || !phoneNumberCheck(called)) incorrectNumber++;
        callCount[caller]++;
        callTime[caller] += timeCalc(start, end);
    }
    while (1) {
        cin >> input;
        if (input == "#") break;
        if (input == "?check_phone_number") {
            if (incorrectNumber == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (input == "?number_calls_from") {
            string number;
            cin >> number;
            cout << callCount[number] << endl;
        }
        else if (input == "?count_time_calls_from") {
            string number;
            cin >> number;
            cout << callTime[number] << endl;
        }
        else if (input == "?number_total_calls") cout << totalCount << endl;
    }
    return 0;
}