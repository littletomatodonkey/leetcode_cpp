#include <vector>
#include <iostream>
using namespace std;

class Solution074 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		int row = matrix.size(), col = matrix[0].size();
		int l = 0, r = col * row-1;
		int middle;
		int ri, ci;
		while (l <= r)
		{
			middle = (l + r)/2;
			ri = middle / col;
			ci = middle % col;
			if (matrix[ri][ci] == target)
				return true;
			else if (matrix[ri][ci] < target)
				l = middle + 1;
			else
				r = middle - 1;
		}
		return false;
	}
};


int main()
{
	vector<vector<int>> matrix = { { 1 } }; // { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
	Solution074 s;
	cout << s.searchMatrix(matrix, 2) << endl;;
	system("pause");
	return 0;
}