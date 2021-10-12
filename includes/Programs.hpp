#include "codes.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

using namespace std;

#ifndef PROGRAMS
	class Programs {
		public:
			
			static ERROR whereami(Shell &shell) {
				string path = "";
				path = shell.getDir();

				if (path == "") {
					return NO_PATH_FOUND;
				}

				cout << shell.getDir() << endl;

				return SUCCESS;
			}

			static ERROR start(Shell &shell, vector<string> args, int argc) {
				cout << "calling start" << endl;
				struct stat st;
				char *path = (char *) malloc((args[0].size() + 1) * sizeof(char));
				
				if (stat(path, &st) != 0 && S_ISREG(st.st_mode)) {
					free(path);
					cout << "error in finding path" << endl;
					return PATH_DNE;
				}
					/* DO STUFF */
					args.erase(args.begin());
					int size = args.size();

					char ** new_args = (char **) malloc(sizeof(char *) * size);

					int i = 0;
					for (string arg: args) {
						new_args[i] =(char *) malloc((args[i].size() + 1) * sizeof(char));
						printf("Arg %d is %s\n", i, new_args[i]);
						i++;
					}

					int pid = fork();

					if (!pid) {
						cout << "bout to call it" << endl;
						int err = execv(path, new_args);
						if (err == -1) {
							printf( "The error generated was %d\n", errno );
    						printf( "That means: %s\n", strerror( errno ) );
						}
						exit(0);
					}

					else wait(NULL);

					free(path);
					// delete individual arrays
					for (int i = 0; i < size; i++) {
						free(new_args[i]);
					}

					free(new_args);
					return SUCCESS;

			}

			static ERROR repeat(Shell &shell, vector<string> args, int argc) {
				return SUCCESS;

			}

			static ERROR callProgram(int programIndex, Shell &shell, vector<string> args, int argc) {
				if (programIndex == -1) return PRGM_DNE;

				PROGRAM program = PROGRAM(programIndex);

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
						start(shell, args, argc);
						break;
					case BCKGRND:
						break;
					case DALEK:
						break;
					case REPEAT:
						repeat(shell, args, argc);
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
	};

	#define PROGRAMS
#endif


