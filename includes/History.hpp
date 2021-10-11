#include "Node.hpp"
#include "codes.h"
using namespace std;

#ifndef HISTORY
	class History {
		private:
			Node * head, * tail;

		public:
			History(Node * head, Node  * tail) {
				this->head = head;
				this->head = tail;
			}

			History(string filename) {
				//TODO: fix this
				this->head = NULL;
				this->tail = NULL;
			}

			ERROR saveToFile() {
				return SUCCESS;
			}

			ERROR loadFromFile(string filename) {
				return SUCCESS;
			}
	};

	#define HISTORY
#endif
