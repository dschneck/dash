#include "codes.h"
#include "History.hpp"
using namespace std;

#ifndef SHELL
	class Shell {
		private:
			char CURRENTDIR[100];
			string USER;
			pid_t PID;
			int count;
			History *history;

		public:
			Shell(string user) {
				getcwd(this->CURRENTDIR, 100);
				this->USER = user;
				this->PID = getpid();

				this->count = 0;
				this->history = new History(new Node(count), NULL);
			}

			Shell(string user, string filename) {
				getcwd(this->CURRENTDIR, 100);
				this->USER = user;

				this->PID = getpid();
				this->count = 0;
				this->history = new History(new Node(count), NULL);
			}

			void setDir(char * dir) {
				//this->CURRENTDIR = dir;
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
