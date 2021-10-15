#include "Node.hpp"
#include "codes.h"
using namespace std;

#ifndef c_HISTORY
	class History {
		private:
			Node * head, * tail;
			int count;

		public:
			History(Node * head, Node  * tail) {
				this->head = head;
				this->head = tail;
				this->count = 1;
			}

			History(string filename) {
				//TODO: fix this
				this->head = NULL;
				this->tail = NULL;
			}

			ERROR addToEnd(Node * node) {
				tail->next = node;
				node->prev = tail;
				node->next = head;
				this->tail = node;
				this->head->prev = node;

				return SUCCESS;
			}

			ERROR saveToFile() {
				return SUCCESS;
			}

			ERROR loadFromFile(string filename) {
				return SUCCESS;
			}
	};

	#define c_HISTORY
#endif
