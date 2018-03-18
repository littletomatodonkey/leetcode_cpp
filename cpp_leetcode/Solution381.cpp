#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool ret = (maps.count(val) == 0);
		nums.push_back(val);
		maps[val].insert(nums.size() - 1);
		return ret;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		bool ret = false;
		if (maps.count(val) == 1)
		{
			auto it = maps[val].end();
			it--;
			int tmp = *it;
			maps[val].erase(it);
			if (tmp != nums.size() - 1)
			{
				nums[tmp] = nums.back();
				it = maps[nums.back()].end();
				it--;
				maps[nums.back()].erase(it);
				maps[nums.back()].insert(tmp);
				//[maps[nums.back()].size() - 1] = tmp;
			}
			nums.pop_back();
			if (maps[val].empty())
				maps.erase( val );
			ret = true;
		}
		return ret;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return nums[ rand() % nums.size() ];
	}

private:
	vector<int> nums;
	unordered_map<int, set<int>> maps;
};


int main()
{
	vector<int> nums = { 1, 1, 0, 0, 0, 1, 1, 1, 1 };
	RandomizedCollection coll;
	coll.insert(10);
	coll.insert(10);
	coll.insert(20);
	coll.insert(20);
	coll.insert(30);
	coll.insert(30);

	coll.remove( 10 );
	coll.remove(10);
	coll.remove(30);
	coll.remove(30);
	//vector<int> ret;
	cout << endl;
	system("pause");
	return 0;
}