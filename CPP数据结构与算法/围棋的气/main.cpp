#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct Point
{
	int x;
	int y;
};

// 自定义谓词，用于比较 Point 结构体
struct PointComparator {
	PointComparator(const Point& p) : point(p) {}
	bool operator()(const Point& other) const {
		return point.x == other.x && point.y == other.y;
	}
	Point point;
};

int CalcQ(vector<Point> Points, vector<Point> all) {
	vector<Point> QI;
	int repate = 0;
	for (int i = 0; i < Points.size(); i++)
	{
		//上方点
		Point up;
		up.x = Points[i].x;
		up.y = Points[i].y - 1;
		if (up.y >= 0 && find_if(all.begin(), all.end(), PointComparator(up)) == all.end())
		{
			QI.push_back(up);
		}
		//下方点
		Point down;
		down.x = Points[i].x;
		down.y = Points[i].y + 1;
		if (down.y <= 18 && find_if(all.begin(), all.end(), PointComparator(down)) == all.end())
		{
			QI.push_back(down);
		}
		//左方点
		Point left;
		left.x = Points[i].x - 1;
		left.y = Points[i].y;
		if (left.x >= 0 && find_if(all.begin(), all.end(), PointComparator(left)) == all.end())
		{
			QI.push_back(left);
		}
		//右方点
		Point right;
		right.x = Points[i].x + 1;
		right.y = Points[i].y;
		if (right.x <= 18 && find_if(all.begin(), all.end(), PointComparator(right)) == all.end())
		{
			QI.push_back(right);
		}
	}
	for (int i = 0; i < QI.size() - 1; i++)
	{
		for (int j = i + 1; j < QI.size(); j++)
		{
			if (QI[i].x == QI[j].x && QI[i].y == QI[j].y)
			{
				repate++;
			}
		}
	}
	return QI.size() - repate;
}

vector<Point> operator+ (vector<Point> s1, vector<Point> s2) {
	s1.insert(s1.end(), s2.begin(), s2.end());
	return s1;
}

int main() {
	vector<Point> whites;
	vector<Point> blacks;
	string line;
	getline(cin, line);
	std::stringstream ss1(line);
	int x, y;
	while (ss1 >> x >> y)
	{
		Point point;
		point.x = x;
		point.y = y;
		blacks.push_back(point);
	}

	getline(cin, line);
	stringstream ss2(line);
	while (ss2 >> x >> y)
	{
		Point point;
		point.x = x;
		point.y = y;
		whites.push_back(point);
	}
	vector<Point> all = whites + blacks;
	int QIB = CalcQ(blacks, all);
	int QIW = CalcQ(whites, all);
	cout << QIB << " " << QIW;
	system("pause");
}
