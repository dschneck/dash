#include "Node.hpp"
#include "codes.h"
using namespace std;

#ifndef c_HISTORY
	class History {
		private:
			Node * head, * tail;
			int count;

		public:
			History() {
				this->head = NULL;
				this->head = NULL;
				this->count = 0;
			}

			History(string filename) {
				//TODO: fix this
				this->head = NULL;
				this->tail = NULL;
			}

			ERROR clearHistory() {
				return SUCCESS;
			}

			void printHistory() {
				if (tail == NULL || head == NULL) {
					cout << "History is empty." << endl;
					return;
				}

				Node * node = tail;

				while (node != head) {
					cout << node->getIndex() << ": " << node->getCommand() << endl;
					node = node->getPrev();
				}

				cout << node->getIndex() << ": " << node->getCommand() << endl;

			}

			void freeNodeCommands() {
				Node * node  = head;

				while (node != tail) {
					node->clean();
					node = node->getNext();

				}

				node->clean();
			}

			ERROR addToEnd(char * command) {
				printf("got em");
				Node * node = new Node(count++, command);
				printf("A");
				if (head == NULL) {
				printf("H");
					if (tail == NULL) {
				printf("E");
						// both null
						tail = node;

					}

					else {
						// head null
				printf("L");
						head = tail;
						head->setNext(node);
						head->setPrev(node);

						node->setNext(head);
						node->setPrev(head);
						tail = node;

					}

				}

				printf("L");
				// general case
				tail->setNext(node);
				head->setPrev(node);
				node->setPrev(tail);
				node->setNext(head);
				tail = node;
				printf("O");
				/*
				case where both null
				case where head null
				general case

				head: x1
				tail: x4
				
				x1->x2->x3->x4

				if (head == NULL) {
					head = node;
					tail = node;
					head->setPrev(tail);
				}

				tail->setNext(node);
				node->setPrev(tail);
				node->setNext(head);
				tail = node;
				head->setPrev(node);
				*/

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
