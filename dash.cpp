#include <dash.h>
using namespace std;

/* CLASSES */
// maybe a different class for different execution types

/* GLOBAL VARIABLES */
//char * __CURRENTDIR = "/home";
//char * __USER = "david";


class Shell {
	private:
		string CURRENTDIR;
		string USER;

	public:
		Shell(string dir, string user) {
			cout << "I'm making a shell" << endl;
			this->CURRENTDIR = dir;
			this->USER = user;
		}
		
		string getDir(){ 
			return this->USER;

		}

		string getUser() {
			return this->CURRENTDIR;
		}
};
/* FUNCTIONS */
void loop(Shell &shell);
void whereami(Shell &shell);
// functions that determines the system for terminal creation

int main(int argc, char * argv[]) {
	cout << "got em" << endl;
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
			cin.get(character);
			input += character;
		}

		cout << input;
		cout << shell.getUser() << "@dash " << shell.getDir() << "# ";
		input = "";
	}
}

void whereami(Shell &shell) {
	cout << shell.getDir() << endl;
}
