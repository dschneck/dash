#include "codes.h"
#include <string.h>
using namespace std;

#ifndef NODE
	class Node {
		private:
			int index, programIndex;
			vector<string> command;
			Node * next, * prev;

		public:
			int getIndex() {
				return this->index;
			}

			vector<string> getCommand() {
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
				//free(command);
				return SUCCESS;
			}

			Node(int index, int programIndex, vector<string> command) {
				cout << "I;m in node" << endl;
				this->index = index;
				this->programIndex = programIndex;
				std::copy(command.begin(), command.end(), back_inserter(this->command));
				this->next = NULL;
				this->prev = NULL;
				cout << "I;m leaving node" << endl;
				
				/*
				this->command = (char*) malloc(sizeof(char) * (strlen(command) + 1));
				this->index = index;
				strcpy(this->command, command);
				this->next = NULL;
				this->prev = NULL;
				*/
			}
	};
	#define NODE
#endif
