#include "dash.h"
using namespace std;

/* FUNCTIONS */
void loop(Shell &shell);
// functions that determines the system for terminal creation

int main(int argc, char * argv[]) {
	//cout << "got em" << endl;
	/*
	if (argc > 1) {
		//cout << "hello there mis lady" << argv[0] << endl;
		Shell shell("david");
		loop(shell);
		return 0;
	}
	*/

	//char *const args[] = {"Hello ", "world!", NULL};

	//char *const *args = (char *const*) malloc(2 * sizeof(char*const));
	//args[0] = (char *) malloc(sizeof(char) * 2);

	//cout << "I am in main boi" << endl;
	//system("open -a Terminal");
	//int error = execv("./run.out", args);
	//cout << "hellO boi" << endl;
	//if (error == -1) printf("error");
	//free(*args);
	//free(*args[0]);
	Shell shell("david");
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
		//cout << "Program index is : " << programIndex << endl;
		input = input.substr(pos+1, len-1);

		while ((len = input.size()) != 0) {
			pos = input.find(' ');
			pargv.push_back(input.substr(0, pos));
			input = input.substr(pos+1, len-1);

			if (pos == string::npos) break;
		} 

		pargv.push_back("\0");

		Programs::callProgram(programIndex, shell, pargv, pargv.size());

		pargv.clear();
		cout << shell.getUser() << "@dash " << shell.getDir() << " # ";
	}
}

