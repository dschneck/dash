#include "codes.h"
#include "History.hpp"
#include "ProcessStack.hpp"
#include <string.h>
using namespace std;

#ifndef SHELL
	class Shell {
		private:
			char CURRENTDIR[100];
			string USER;
			pid_t PID;

		public:
			History *history;
			ProcessStack * pstack;

			Shell(string user) {
				getcwd(this->CURRENTDIR, 100);
				this->USER = user;
				this->PID = getpid();

				this->pstack = new ProcessStack();
				this->history = new History(new Node(0), NULL);
			}

			Shell(string user, string filename) {
				getcwd(this->CURRENTDIR, 100);
				this->USER = user;

				this->PID = getpid();
				this->history = new History(new Node(0), NULL);
			}

			void setDir(char * dir) {
				strcpy(this->CURRENTDIR, dir);
			}

			string getUser() {
				return this->USER;
			}

			string getDir() {
				return string(this->CURRENTDIR);
			}

			pid_t getShellPID() {
				return this->PID;
			}
	};
	#define SHELL
#endif
