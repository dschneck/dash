#include <dash.h>
using namespace std;

/* CLASSES */
// maybe a different class for different execution types

/* GLOBAL VARIABLES */
 /*
	MVE2DIR,
	BYEBYE,
	HISTORY,
	REPLAY,
	START,
	BCKGRND,
	DALEK,
	REPEAT,
	DALEKALL
*/


//char * __CURRENTDIR = "/home";
//char * __USER = "david";

class Shell {
	private:
		string CURRENTDIR;
		string USER;

	public:
		Shell(string dir, string user) {
			this->CURRENTDIR = dir;
			this->USER = user;
		}
		
		string getUser(){ 
			return this->USER;
		}

		string getDir() {
			return this->CURRENTDIR;
		}
};

class Programs {
	public:
		
		static ERROR whereami(Shell &shell) {
			cout << shell.getDir() << endl;
			return SUCCESS;
		}

		static ERROR callProgram(PROGRAM program, Shell &shell) {
			switch (program) {
				case MVE2DIR:
					break;
				case WHREAMI:
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

		static PROGRAM findMatch(string candidate) {
			return MVE2DIR;
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
};

/* FUNCTIONS */
void loop(Shell &shell);
// functions that determines the system for terminal creation

int main(int argc, char * argv[]) {
	//cout << "got em" << endl;
	if (argc > 1) {
		//cout << "hello there mis lady" << argv[0] << endl;
		Shell shell("/home", "david");
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
	char character;
	string input;

	cout << "\n" << shell.getUser() << "@dash " << shell.getDir() << "# ";

	while (1) {
		cin.get(character);

		while (character != '\n') {
			if (character == ' ') {

				PROGRAM currentProgram = Programs::findMatch(input);
				Programs::callProgram(currentProgram, shell);
				cin.get(character); 
				continue;
			}

			input += character;
			cin.get(character);
		}

		cout << input;
		cout << shell.getUser() << "@dash " << shell.getDir() << "# ";
		input = "";
	}
}

