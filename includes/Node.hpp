#include "codes.h"
#include <string.h>
using namespace std;

#ifndef NODE
	class Node {
		private:
			int index;
			char * command;
			Node * next, * prev;

		public:
			int getIndex() {
				return this->index;
			}

			string getCommand() {
				return this->command;
			}

			Node * getNext() {
				return this->next;
			}

			ERROR setNext(Node * next) {
				this->next = next;
				return SUCCESS;
			}

			Node * getPrev() {
				return this->prev;
			}

			ERROR setPrev(Node * prev) {
				this->prev = prev;
				return SUCCESS;
			}

			ERROR clean() {
				free(command);
				return SUCCESS;
			}

			Node(int index, char * command) {
				this->command = (char*) malloc(sizeof(char) * (strlen(command) + 1));
				this->index = index;
				strcpy(this->command, command);
				this->next = NULL;
				this->prev = NULL;
			}
	};
	#define NODE
#endif
