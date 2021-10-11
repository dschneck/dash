#include "codes.h"
using namespace std;

#ifndef NODE
	class Node {
		private:
			int val;
			Node * next, * prev;

		public:
			int getVal() {
				return this->val;
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

			Node(int val) {
				this->val = val;
				this->next = NULL;
			}
	};
	#define NODE
#endif
