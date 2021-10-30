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
			//History *history;
			vector<string> history;
			ProcessStack * pstack;

			Shell(string user) {
				getcwd(this->CURRENTDIR, 100);
				this->USER = user;
				this->PID = getpid();

				this->pstack = new ProcessStack();
				//this->history = new History();
			}

			Shell(string user, string filename) {
				getcwd(this->CURRENTDIR, 100);
				this->USER = user;

				this->PID = getpid();
				this->pstack = new ProcessStack();
				//this->history = new History();
			}

			void setDir(char * dir) {
				strcpy(this->CURRENTDIR, dir);
			}

			void printHistory() {
				int size = history.size();

				for (int i = size-1; i >= 0; i--) {
					cout << size-i-1 << ": " << history[i] << endl;
				}

				cout << endl;
			}

			ERROR clearHistory() {
				return SUCCESS;

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
