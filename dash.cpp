#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>

/* FUNCTIONS */
// functions that determines the system for terminal creation

/* CLASSES */
// maybe a different class for different execution types

/* GLOBAL VARIABLES */

using namespace std;

class driver {
	public:
		void hello() {
			cout << "Hello" << endl;
			return;
		}

	private:
		void priv() {
			std::cout << "sshhh secret..." << endl;
		}
};

int main(int argc, char * argv[]) {
	cout << "got em" << endl;
	if (argc > 1) {
		cout << "hello there mis lady" << argv[0] << endl;
		return 0;
	}

	char *const args[] = {"Hello ", "world!", NULL};

	//char *const *args = (char *const*) malloc(2 * sizeof(char*const));
	//args[0] = (char *) malloc(sizeof(char) * 2);

	cout << "I am in main boi" << endl;
	//system("open -a Terminal");
	int error = execv("./run", args);
	if (error == -1) printf("error");
	//free(*args);
	//free(*args[0]);
	return 0;
}

