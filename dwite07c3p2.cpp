#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    string line, out;
    for (int z = 0; z < 5; z++) {
        getline(cin, line);
        out = "";
        bool cl, sl, il, cm, pt = cl = sl = il = cm = 0;
        for (int i = 0; i < line.length(); i++) {
            if (cm || cl || il || sl) {
                if (sl && line[i] == '\"') {
                    out += " ";
                    sl = 0;
                } else if (cl && line[i] == '\'') {
                    out += " ";
                    cl = 0;
                } else if (il && line[i] == '*' && line[i + 1] == '/') {
                    il = 0;
                    out += " ";
                    i++;
                } else {
                    out += line[i];
                }
                continue;
            }
            if (line[i] == '/' && !cl && !sl) {
                if (!pt) {
                    pt = 1;
                } else {
                    cm = 1;
                    pt = 0;
                }
            } else if (line[i] == '*' && pt) {
                il = 1;
                pt = 0;
            } else if (line[i] == '\"' && !sl) {
                sl = 1;
            } else if (line[i] == '\'') {
                cl = 1;
            }
        }
        out = out.erase(0, out.find_first_not_of(" "));
        out = out.erase((out.find_last_not_of(" ")) + 1);
        cout << out << "\n";
    }
    return 0;
}