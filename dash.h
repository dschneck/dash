#ifndef DASH

	/* INCLUDES */
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <stdio.h>

	#include <iostream>
	#include <iomanip>
	#include <cstdlib>

	/* STRUCT and ENUMS */
	enum ERROR {
		SUCCESS = 0,
		FILE_DNE,
		PRGM_DNE
	};

	enum PROGRAM {
		MVE2DIR,
		WHREAMI,
		BYEBYE,
		HISTORY,
		REPLAY,
		START,
		BCKGRND,
		DALEK,
		REPEAT,
		DALEKALL,
	};

	/* FUNCTIONS */
	void printError(ERROR code);

	#define DASH
#endif
