#include <iostream>
#include "TreeClass.h"

int main()
{
	int n;
	std::cin >> n;

	Tree* tree = new Tree[n];

	for (int i = 0; i < n; ++i)
	{
		char data, left, right;
		std::cin >> data >> left >> right;

		if (data != '.') tree[(int)data - 'A'].setData(data);
	}
}