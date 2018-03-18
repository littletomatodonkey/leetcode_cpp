#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std; 

class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (m.count(val) == 1)
			return false;
		nums.push_back( val );
		m[val] = nums.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (m.count(val) == 0)
			return false;
		int vlast = nums.back();
		m[vlast] = m[val];
		nums[m[val]] = vlast;
		nums.pop_back();
		m.erase( val );
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}

private:
	// vecotor可以实现在O(1)内的随机获取
	vector<int> nums;
	// 哈希表可以实现O(1)的插入与删除
	unordered_map<int, int> m;
};


int main()
{
	vector<int> nums = { 1, 3, 6, 5, 4, 3 };
	RandomizedSet rs;
	//vector<int> ret;
	cout << endl;
	system("pause");
	return 0;
}