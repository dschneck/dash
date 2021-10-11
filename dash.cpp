#include <dash.h>
using namespace std;

/* CLASSES */

class Shell {
	private:
		char CURRENTDIR[100];
		string USER;
		int PID;

	public:
		Shell(string user) {
			getcwd(this->CURRENTDIR, 100);
			this->USER = user;
			this->PID = getpid();
		}
		
		void setDir(char * dir) {
			//this->CURRENTDIR = dir;
		}

		string getUser(){ 
			return this->USER;
		}

		string getDir() {
			return string(this->CURRENTDIR);
		}

		int getShellPID() {
			return this->PID;
		}
};

class Programs {
	public:
		
		static ERROR whereami(Shell &shell) {
			string path = "";
			path = shell.getDir();

			if (path == "") {
				return NO_PATH_FOUND;
			}

			cout << '\n' << shell.getDir() << endl;

			return SUCCESS;
		}

		static ERROR callProgram(int programIndex, Shell &shell) {
			if (programIndex == -1) return PRGM_DNE;

			PROGRAM program = PROGRAM(programIndex);

			switch (program) {
				case MVE2DIR:
					break;
				case WHREAMI:
					cout << "Calling whereami... "  << endl;
					whereami(shell);
					break;
				case BYEBYE:
					break;
				case HISTORY:
					break;
				case REPLAY:
					break;
				case START:
					break;
				case BCKGRND:
					break;
				case DALEK:
					break;
				case REPEAT:
					break;
				case DALEKALL:
					break;
				default:
					return PRGM_DNE;
			}

			return SUCCESS;
		}

		// This function will return the index of reserved[] that has the match
		// If there is no match, it will return -1
		static int checkIfProgram(string buffer) {
			int ret = -1;
			int length = (sizeof(FUNC_NAMES)/sizeof(*FUNC_NAMES));

			for (int i = 0; i < length; i++) {
				if (buffer == FUNC_NAMES[i]) {
					ret = i;
					break;
				}
			}

			return ret;
		}

	private:
		static const inline string FUNC_NAMES[] = {
			"movetodir",
			"whereami",
			"byebye",
			"history",
			"replay",
			"start",
			"background",
			"dalek",
			"repeat",
			"dalekall"
		};

		/*
		static const inline PROGRAM FUNC_ENUMS[] = {
			MVE2DIR,
			WHREAMI,
			BYEBYE,
			HISTORY,
			REPLAY,
			START,
			BCKGRND,
			DALEK,
			REPEAT,
			DALEKALL
		};
		*/
};

/* FUNCTIONS */
void loop(Shell &shell);
// functions that determines the system for terminal creation

int main(int argc, char * argv[]) {
	//cout << "got em" << endl;
	if (argc > 1) {
		//cout << "hello there mis lady" << argv[0] << endl;
		Shell shell("david");
		loop(shell);
		return 0;
	}

	char *const args[] = {"Hello ", "world!", NULL};

	//char *const *args = (char *const*) malloc(2 * sizeof(char*const));
	//args[0] = (char *) malloc(sizeof(char) * 2);

	//cout << "I am in main boi" << endl;
	//system("open -a Terminal");
	int error = execv("./run.out", args);
	if (error == -1) printf("error");
	//free(*args);
	//free(*args[0]);
	return 0;
}

// Serves as the main loop of the shell
// accepts input, manages state, and runs functions
void loop(Shell &shell) {
	int programIndex;
	char character;
	string input;

	cout << "\n" << shell.getUser() << "@dash " << shell.getDir() << "# ";

	while (1) {
		cin.get(character);

		while (character != '\n') {
			if (character == ' ') {

				programIndex = Programs::checkIfProgram(input);
				cout << "Program index is : " << programIndex << endl;

				Programs::callProgram(programIndex, shell);

				cin.get(character); 
				continue;
			}

			input += character;
			cin.get(character);
		}

		programIndex = Programs::checkIfProgram(input);
		cout << "Program index is : " << programIndex << endl;

		Programs::callProgram(programIndex, shell);


		cout << input << '\n';
		cout << shell.getUser() << "@dash " << shell.getDir() << "# ";
		input = "";
	}
}

