#include "dash.h"
using namespace std;

/* FUNCTIONS */
void loop(Shell &shell);

int main(int argc, char * argv[]) {
	Shell shell("david");
	loop(shell);

	return 0;
}

// Serves as the main loop of the shell
// accepts input, manages state, and runs functions
void loop(Shell &shell) {
	int programIndex;
	string input;
	//string space_delimiter = " ";
	vector<string> pargv;

	system("clear");
	system("date");
	cout << '\n' << shell.getUser() << "@dash " << shell.getDir() << " # ";

	while (1) {
		getline(cin, input);

		/*
		size_t pos = 0;

		while ((pos = input.find(space_delimiter)) != string::npos) {
			cout << "got here with: " << input.substr(0, pos) << endl;
			pargv.push_back(input.substr(0, pos));
			input.erase(0, pos + space_delimiter.length());
		}

		programIndex = Programs::checkIfProgram(pargv[0]);
		pargv.erase(pargv.begin());

		for (string str : pargv) {
			cout << str << endl;
		}

		*/
		int len = input.size();
		int pos = input.find(' ');

		programIndex = Programs::checkIfProgram(input.substr(0, pos));
		input = input.substr(pos+1, len-1);

		while ((len = input.size()) != 0) {
			pos = input.find(' ');
			pargv.push_back(input.substr(0, pos));
			input = input.substr(pos+1, len-1);

			if (pos == string::npos) break;
		} 

		Programs::callProgram(programIndex, shell, pargv, pargv.size());

		pargv.clear();
		cout << shell.getUser() << "@dash " << shell.getDir() << " # ";
	}
}

