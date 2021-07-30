#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> out; out.emplace_back("Ready\n");
    char str[2];
    while (true) {
        scanf("%c%c%*c", &str[0], &str[1]);
        if (str[0] == ' ' && str[1] == ' ') {
            break;
        }
        char temp;
        if (str[0] > str[1]) {
            temp = str[0];
            str[0] = str[1];
            str[1] = temp;
        }
        ((str[0] == 'p' && str[1] == 'q') || (str[0] == 'b' && str[1] == 'd')) ? out.emplace_back("Mirrored pair\n") : out.emplace_back("Ordinary pair\n");
    }
    for (const auto& s : out) {
        printf("%s", s.c_str());
    }
    return 0;
}