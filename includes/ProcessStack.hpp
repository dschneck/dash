#include "codes.h"
#include <stack>
using namespace std;

class ProcessStack {
	private:
		stack<int> pidStack;
		int count;

		string toString(int pid) {
			int tmp;
			string ret = "";

			while (pid != 0) {
				tmp = pid % 10;
				pid /= 10;
				ret += (tmp + '0');
			}

			string realRet = "";
			int n = ret.size();
			for (int i = n-1; i >= 0; i--) {
				realRet += ret[i];
			}

			return realRet;
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
			if (!pidStack.empty())  {
				pidStack.pop();
				count--;
				return SUCCESS;
			}

			return STACK_EMPTY;
		}

		vector<string> popall() {
			vector<string> ret; 

			cout << "Exterminating " << count << " processes:";
			while (!pidStack.empty()) {
				int pid = pidStack.top();
				pidStack.pop();
				string tmp = toString(pid);
				cout << " " << tmp;
				ret.push_back(tmp);
				count--;
			}

			cout << endl;
			return ret;
		}
};
