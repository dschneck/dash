#include "codes.h"
#include <stack>
using namespace std;

class ProcessStack {
	private:
		stack<int> pidStack;
		int count;

		string toString(int pid) {
			cout << "\nIn toString" << endl;
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
				cout << "got em with " << i << endl;
				realRet += ret[i];
			}
			/*
			//TODO: need to reverse string
			int m = n/2;
			cout << "size is " << n << " and m is " << m << endl;
			cout << ret[2] << endl;

			cout << "reversing : " << ret << endl; 
			for (int i = 0; i < m; i++) {
				char tmp = ret[i];
				cout << "bout to vreak: " <<  n-i-1 << endl;
				ret[i] = ret[n-i-1];
				ret[n-i-1] = tmp;
			}
			*/

			//cout << format("Here is the pid string: %s", ret) << endl;
			cout << "returning with: " << realRet << endl;
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
