#include "codes.h"
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

			static ERROR start(Shell &shell, string args[], int argc) {
				struct stat st;
				char *path = (char *) malloc((args[0].size() + 1) * sizeof(char));
				
				if (stat(path, &st) != 0 && S_ISREG(st.st_mode)) {
					free(path);
					return PATH_DNE;
				}
					/* DO STUFF */
					free(path);
					return SUCCESS;

			}

			static ERROR repeat(Shell &shell, string args[], int argc) {
				return SUCCESS;

			}

			static ERROR callProgram(int programIndex, Shell &shell, string args[], int argc) {
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


