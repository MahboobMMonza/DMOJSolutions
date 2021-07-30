#include <bits/stdc++.h>

using namespace std;

char s[100];
int main() {
    scanf("%s", s);
    while ((strcmp(s, "TTYL"))) {
        if (!strcmp(s, "CU")) {
            printf("see you");
        } else if (!strcmp(s, ":-)")) {
            printf("I'm happy");
        } else if (!strcmp(s, ":-(")) {
            printf("I'm unhappy");
        } else if (!strcmp(s, ";-)")) {
            printf("wink");
        } else if (!strcmp(s, ":-P")) {
            printf("stick out my tongue");
        } else if (!strcmp(s, "(~.~)")) {
            printf("sleepy");
        } else if (!strcmp(s, "TA")) {
            printf("totally awesome");
        } else if (!strcmp(s, "CCC")) {
            printf("Canadian Computing Competition");
        } else if (!strcmp(s, "CUZ")) {
            printf("because");
        } else if (!strcmp(s, "TY")) {
            printf("thank-you");
        } else if (!strcmp(s, "YW")) {
            printf("you're welcome");
        } else {
            printf(s);
        }
        printf("\n");
        scanf("%s", s);
    }
    printf("talk to you later");
    return 0;
}