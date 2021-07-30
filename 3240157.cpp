#include <bits/stdc++.h>

using namespace std;

int sMax(string a, string b);

string sAbs(string a);

string sAdd(string a, string b);

string sSub(string a, string b, bool negA, bool negB);

char sa[100001], sb[100001];
int main() {
    int n;
    string res;
    bool negA, negB;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%s", sa, sb);
        negA = sa[0] == '-';
        negB = sb[0] == '-';
        if (negA == negB) {
            res = sAdd(sAbs(sa), sAbs(sb));
            negB ? printf("-%s\n", res.c_str()) : printf("%s\n", res.c_str());
        } else {
            printf("%s\n", sSub(sAbs(sa), sAbs(sb), negA, negB).c_str());
        }
    }
    return 0;
}

string sAbs(string a) {
    if (a[0] == '-') {
        a[0] = '0';
        return a;
    }
    return "0" + a;
}

int sMax(string a, string b) {
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    if (a == b) return 0;
    if (a > b) return 1;
    return -1;
}

string sAdd(string a, string b) {
    int ma = sMax(a, b), ml = b.length();
    if (ma == -1) {
        ml = a.length();
    }
    string s;
    if (ma == 1) s = a;
    else s = b;
    int sum, carry = 0, retin = -1;
    for (int i = 0; i < ml; i++) {
        sum = (a[a.length() - 1 - i] - '0') + (b[b.length() - 1 - i] - '0') + carry;
        s[s.length() - 1 - i] = '0' + (sum % 10);
        if (sum % 10 > 0) {
            retin = i;
        }
        carry = sum / 10;
    }
    if (ma == 1) {
        for (int i = a.length() - ml - 1; i >= 0; i--) {
            sum = (a[i] - '0') + carry;
            s[i] = '0' + (sum % 10);
            carry = sum / 10;
        }
    } else if (ma == -1) {
        for (int i = b.length() - ml - 1; i >= 0; i--) {
            sum = (b[i] - '0') + carry;
            s[i] = '0' + (sum % 10);
            carry = sum / 10;
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') {
            retin = i;
            break;
        }
    }
    return s.substr(retin);
}

string sSub(string a, string b, bool negA, bool negB) {
    int ma = sMax(a, b), diff, retin = -1;
    string s;
    if (ma == 0) {
        return "0";
    } else if (ma == 1) {
        s = a;
        for (int i = 0; i < b.length(); i++) {
            if (a[a.length() - 1 - i] < b[b.length() - 1 - i]) {
                a[a.length() - 1 - i] += 10;
                a[a.length() - 2 - i]--;
            }
            diff = (a[a.length() - 1 - i] - '0') - (b[b.length() - 1 - i] - '0');
            s[s.length() - 1 - i] = '0' + diff;
        }
        s = a.substr(0, a.length() - b.length()) + s.substr(a.length() - b.length());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '0') { retin = i; break;}
        }
        return (negA) ? "-" + s.substr(retin) : s.substr(retin);
    }
    s = b;
    for (int i = 0; i < a.length(); i++) {
        if (b[b.length() - 1 - i] < a[a.length() - 1 - i]) {
            b[b.length() - 1 - i] += 10;
            b[b.length() - 2 - i]--;
        }
        diff = (b[b.length() - 1 - i] - '0') - (a[a.length() - 1 - i] - '0');
        s[s.length() - 1 - i] = '0' + diff;
    }
    s = b.substr(0, b.length() - a.length()) + s.substr(b.length() - a.length());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') { retin = i; break;}
    }
    return (negB) ? "-" + s.substr(retin) : s.substr(retin);
}