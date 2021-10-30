#include "dash.h"
using namespace std;

/* FUNCTIONS */ void loop(Shell &shell);

int main(int argc, const char * argv[]) {
	if (argc < 1) {
		Shell shell("user", argv[1]);
		loop(shell);
	}

	else {
		Shell shell("user");
		loop(shell);
	}

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

		if (programIndex != -1) {
			shell.history.push_back(input);
		}

		input = input.substr(pos+1, len-1);

		while ((len = input.size()) != 0) {
			pos = input.find(' ');
			pargv.push_back(input.substr(0, pos));
			input = input.substr(pos+1, len-1);

			if ((size_t) pos == string::npos) break;
		} 


		Programs::callProgram(programIndex, shell, pargv, pargv.size());
		pargv.clear();
		cout << shell.getUser() << "@dash " << shell.getDir() << " # ";
	}
}

