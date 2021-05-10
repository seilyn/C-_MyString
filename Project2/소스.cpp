#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) : x_(x), y_(y) {}
	Point& operator++()
	{
		x_++;
		y_++;
		return (*this);
	}
	void Print() { std::cout << "(" }

private:
	int x_;
	int y_;
};

int main()
{	
	Point pt1(1, 1);
	Point pt2 = ++pt1;
	
	return 0;
}