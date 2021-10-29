#include "dash.h"
using namespace std;

/* FUNCTIONS */
void loop(Shell &shell);

int main() {
	Shell shell("user");
	loop(shell);

	return 0;
}

// Serves as the main loop of the shell
// accepts input, manages state, and runs functions
void loop(Shell &shell) {
	int programIndex;
	string input;
	vector<string> pargv;

	system("clear");
	system("date");
	cout << '\n' << shell.getUser() << "@dash " << shell.getDir() << " # ";

	while (1) {
		getline(cin, input);
		int len = input.size();
		int pos = input.find(' ');

		programIndex = Programs::checkIfProgram(input.substr(0, pos));
		//cout << "\ninput is" << len << endl;

		input = input.substr(pos+1, len-1);

		while ((len = input.size()) != 0) {
			pos = input.find(' ');
			pargv.push_back(input.substr(0, pos));
			input = input.substr(pos+1, len-1);

			if ((size_t) pos == string::npos) break;
		} 

		if (programIndex != -1) {
			cout << "what the fuck" << endl;
			shell.history->addToEnd(programIndex, pargv);
		}

		Programs::callProgram(programIndex, shell, pargv, pargv.size());
		pargv.clear();
		cout << shell.getUser() << "@dash " << shell.getDir() << " # ";
	}
}

