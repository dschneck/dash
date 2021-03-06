#include "codes.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

#ifndef PROGRAMS
	class Programs {
		public:

			static ERROR replay(Shell &shell, vector<string> args) {
				cout << "got here boi" << endl;
				if (args.size() < 1) {
					cout << "Missing argument, need index from the output of the history command" << endl;
					return MISSING_ARG;
				}

				int index = toInt(args[0]);
				string input = shell.history[index + shell.history.size()-1];
				cout << input << endl;
				int len = input.size();
				int pos = input.find(' ');
				vector<string> pargv;

				int programIndex = Programs::checkIfProgram(input.substr(0, pos));

				input = input.substr(pos+1, len-1);

				while ((len = input.size()) != 0) {
					pos = input.find(' ');
					pargv.push_back(input.substr(0, pos));
					input = input.substr(pos+1, len-1);

					if ((size_t) pos == string::npos) break;
				} 

				Programs::callProgram(programIndex, shell, pargv, pargv.size());
				pargv.clear();

				return SUCCESS;
			}

			static void byebye(Shell &shell) {
				// Free all dynamically allocated memory
				// Save History to file
				/*
				ofstream output_file("./history.txt");
    			ostream_iterator<string> output_iterator(output_file, "\n");
    			copy(shell.history.begin(), shell.history.end(), output_iterator);
				*/

				shell.history.pop_back();
				cout << "Exiting and writing history to history.txt" << endl;
				ofstream file;
				file.open("history.txt");

				int size = shell.history.size();
				for (int i  =0; i < size; i++){
					file << shell.history[i] << endl;
				}

				file.close();
				exit(0);
			}

			static ERROR history(Shell &shell, vector<string> args) {

				if (args.size() >= 1 && args[0] == "-c") {
					shell.clearHistory();
					return SUCCESS;
				}
				
				shell.printHistory();
				
				return SUCCESS;
			}

			static ERROR repeat(Shell &shell, vector<string> args, int argc) {
				if (args.size() < 2) return NO_PRGM;
				int n = toInt(args[0]);

				args.erase(args.begin(), args.begin()+1);
				argc = args.size();

				for (int i = 0; i < n; i++) {
					background(shell, args, argc);
				}	

				cout << endl;
				return SUCCESS;
			}

			static ERROR movetodir(Shell &shell, vector<string> args) {
				struct stat stats;
				char * path;

				cpyString(&path, args[0]);
    			stat(path, &stats);

    			// Check for file existence
    			if (!S_ISDIR(stats.st_mode)) {
					cout << path << " didn't exist" << endl;
					free(path);
					return PATH_DNE;
				}

				shell.setDir(path);
				free(path);
				return SUCCESS;
			}

			static ERROR whereami(Shell &shell) {
				string path = "";
				path = shell.getDir();

				if (path == "") {
					return NO_PATH_FOUND;
				}

				cout << shell.getDir() << endl;

				return SUCCESS;
			}

			static ERROR dalek(Shell &shell, string PID) {
				const char * tmp = {"kill -s KILL "};
				int len = strlen(tmp);
				int size = PID.size();

				char * command = (char *) malloc(sizeof(char) * len + size + 1); 

				for (int i = 0; i < len; i++) {
					command[i] = tmp[i];
				}

				for (int i = 0; i < size; i++) { 
					command[len + i] = PID[i];  
				}

				command[len + size] = '\0';

				shell.pstack->pop();
				system(command);
				return SUCCESS;

			}

			static ERROR dalekall(Shell &shell) {
				int size = shell.pstack->getCount();
				vector<string> pids = shell.pstack->popall();

				for (int i = 0; i < size; i++) {
					dalek(shell, pids[i]);
				}

				return SUCCESS;
			}

			static ERROR background(Shell &shell, vector<string> args, int argc) {
				struct stat stats;
				char * path;

				cpyString(&path, args[0]);
				stat(path, &stats);

				args.erase(args.begin());

				char ** new_args = (char **) calloc(sizeof(char *) , argc+1);

				for (int i = 0; i < argc; i++) {
					cpyString(&new_args[i], args[i]);
				}

				int pid = fork();

				if (!pid) {

					int err = execvp(path, new_args);
					if (err == -1) {
						//printf( "The error generated was %d\n", errno );
						printf( "ERROR: %s\n", strerror(errno));
					}

					exit(0);
				}

				else {
					cout << "PID: " << pid << endl;
					shell.pstack->push(pid);
				}

				// free memory
				free(path);

				for (int i = 0; i < argc; i++) {
					free(new_args[i]);
				}

				free(new_args);

				return SUCCESS;

			}

			static ERROR start(vector<string> args, int argc) {
				struct stat st;
				char * path;

				cpyString(&path, args[0]);

				if (stat(path, &st) != 0 && S_ISREG(st.st_mode)) {
					free(path);
					return PATH_DNE;
				}

				args.erase(args.begin());

				char ** new_args = (char **) calloc(sizeof(char *) , argc+1);

				for (int i = 0; i < argc; i++) {
					cpyString(&new_args[i], args[i]);
				}

				int pid = fork();

				if (!pid) {
					int err = execvp(path, new_args);
					if (err == -1) {
						//printf( "The error generated was %d\n", errno );
						printf( "ERROR: %s\n", strerror(errno));
					}

					exit(0);
				}

				else {
					wait(NULL);
				}

				// free memory
				free(path);

				for (int i = 0; i < argc; i++) {
					free(new_args[i]);
				}

				free(new_args);

				return SUCCESS;
			}

			static ERROR callProgram(int programIndex, Shell &shell, vector<string> args, int argc) {
				if (programIndex == -1) return PRGM_DNE;

				PROGRAM program = PROGRAM(programIndex);

				switch (program) {
					case MVE2DIR:
						movetodir(shell, args);
						break;
					case WHREAMI:
						whereami(shell);
						break;
					case BYEBYE:
						byebye(shell);
						break;
					case HISTORY:
						history(shell, args);
						break;
					case REPLAY:
						replay(shell, args);
						break;
					case START:
						start(args, argc);
						break;
					case BCKGRND:
						background(shell, args, argc);
						break;
					case DALEK:
						dalek(shell, args[0]);
						break;
					case REPEAT:
						repeat(shell, args, argc);
						break;
					case DALEKALL:
						dalekall(shell);
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
			static void cpyString(char ** buff, string str) {
				*buff = (char *) calloc((str.size() + 1) , sizeof(char));
				strcpy(*buff, str.c_str());
			}

			static int toInt(string n) {
				int size = n.size();
				int ret = 0;

				for (int i = 0; i < size; i++) {
					ret *= 10;
					ret += (n[i] - '0');
				}

				return ret;
			}

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

	#define PROGRAMS
#endif


