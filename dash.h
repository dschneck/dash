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
		FILE_DNE	
	};

	enum PROGRAM {
		MVE2DIR,
		BYEBYE,
		HISTORY,
		REPLAY,
		START,
		BCKGRND,
		DALEKPID,
		REPEAT,
		DALEKALL
	};

	/* FUNCTIONS */
	void printError(ERROR code);

	#define DASH
#endif
