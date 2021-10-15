#include "codes.h"
#include <stack>
using namespace std;

class ProcessStack {
	private:
		stack<int> pidStack;
		int count;

		string toString(int pid) {
			cout << "\nIn toString" << endl;
			int tmp, i = 1;
			string ret = "";

			cout  << "Going  into  the while loop with pid " << pid << endl;
			while ((pid % i) != 0) {
				cout << "got inside the loop" << endl;
				tmp  = pid % i;
				cout << "tmp is : " << tmp << endl;
				ret += (tmp + '0');
				cout << "ret is " << ret << endl;
				i *= 10;
			}

			//TODO: need to reverse string
			int n = ret.size();

			cout << "reversing : " << ret << endl; 
			for (int i = 0; i < i/2; i++) {
				ret[i] = ret[n-i-1];
			}

			//cout << format("Here is the pid string: %s", ret) << endl;
			return ret;
		}

	public:
		ProcessStack() {
			this->count = 0;
		}

		int getCount() {
			return count;
		}

		ERROR push(pid_t pid)  {
			pidStack.push(pid);
			count++;
			return SUCCESS;
		}

		ERROR pop()  {
			if (pidStack.top() != NULL)  {
				pidStack.pop();
				count--;
				return SUCCESS;
			}

			return STACK_EMPTY;
		}

		vector<string> popall() {
			vector<string> ret; 

			cout << "Exterminating " << count << " processes:";
			while (pidStack.top() != NULL) {
				int pid = pidStack.top();
				pidStack.pop();
				string tmp = toString(pid);
				cout << " " << tmp;
				ret.push_back(tmp);
				count--;
			}

			cout << endl;
		}
};
