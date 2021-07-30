#include <bits/stdc++.h>

using namespace std;

int main() {
    string lines[] = {"*x*", " xx", "* *"}, output;
    int k;
    cin >> k;
    for (auto& current_line : lines) {
    	for (int i = 0; i < k; i++) {
    	    output = "";
    		for (int j = 0; j < 3; j++) { // Each line is 3 characters
    			for (int t = 0; t < k; t++) {
    				output = output + current_line[j];
    			}
    		}
    		cout << output << "\n";
    	}
    }
    return 0;
}