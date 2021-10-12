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

			/*
That means: Bad address
run.out(69546,0x10edcfe00) malloc: *** error for object 0x5000000000000000: pointer being freed was not allocated
run.out(69546,0x10edcfe00) malloc: *** set a breakpoint in malloc_error_break to debug
			*/
			static ERROR start(Shell &shell, vector<string> args, int argc) {
				struct stat st;
				//char *path = (char *) malloc((args[0].size() + 1) * sizeof(char));
				//for (int i = 0; i < args[0].size(); i++) {
					//path[i] = args[0][i];

				//}
				//path[args[0].size()] = '\0';
				char * path;
				cpyString(&path, args[0]);

				if (stat(path, &st) != 0 && S_ISREG(st.st_mode)) {
					free(path);
					return PATH_DNE;
				}
					/* DO STUFF */
					args.erase(args.begin());
					int size = args.size();

					char ** new_args = (char **) malloc(sizeof(char *) * size);

					for (int i = 0; i < size; i++) {
						cpyString(&new_args[i], args[i]);
						//new_args[i] =(char *) malloc((args[i].size() + 1) * sizeof(char));
						//printf("Arg %d is %s\n", i, new_args[i]);
					}

					int pid = fork();

					if (!pid) {
						int err = execv(path, new_args);
						if (err == -1) {
							//printf( "The error generated was %d\n", errno );
    						printf( "ERROR: %s\n", strerror(errno));
						}

						exit(0);
					}

					else {
						wait(NULL);
					}

					free(path);
					// free individual arrays
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
			static void cpyString(char ** buff, string str) {
				*buff = (char *) calloc((str.size() + 1) , sizeof(char));
				strcpy(*buff, str.c_str());
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


