#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	long int total = 0;
	string line;
	while (getline(cin, line)) {
		vector<std::string> v;
		string value;

		for (int i = 0; i < line.length(); i++) {
			string digit;

			if (line[i] <= '9' && line[i] >= '0') {
				digit += line[i];
				v.push_back(digit);
			}
		}

		value += v.front();
		value += v.back();
		total += stoi(value);
	}
	cout << "Total: " << total << "\n";
}