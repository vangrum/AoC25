#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Point
{
    long long x, y;
    Point() : x(0), y(0) {}
    Point(long long x, long long y) : x(x), y(y) {}
};

long long part1()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    vector<Point> points;
    string line;
    bool first = true;
    while (getline(file, line))
    {
        Point cur;
        sscanf(line.c_str(), "%lld,%lld", &cur.x, &cur.y);
        points.push_back(cur);
    }

    long long max_area = 0;
    for (Point p1 : points)
    {
        for (Point p2 : points)
        {
            max_area = max(abs((abs(p2.y - p1.y) + 1) * (abs(p2.x - p1.x) + 1)), max_area);
        }
    }

    return max_area;
}

long long part2()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    vector<Point> points;
    string line;
    while (getline(file, line))
    {
        Point cur;
        sscanf(line.c_str(), "%lld,%lld", &cur.x, &cur.y);
        points.push_back(cur);
    }

    long long max_area = 0;
    int n = points.size();
    for (Point p1 : points)
    {
        for (Point p2 : points)
        {
            long long new_area = abs((abs(p2.y - p1.y) + 1) * (abs(p2.x - p1.x) + 1));
            if (new_area > max_area)
            {
                bool valid = true;

                int min_x = min(p1.x, p2.x);
                int max_x = max(p1.x, p2.x);
                int min_y = min(p1.y, p2.y);
                int max_y = max(p1.y, p2.y);

                for (int y = min_y + 1; y < max_y; y++)
                {
                    for (int x = min_x + 1; x < max_x; x++)
                    {
                        int crossings = 0;

                        for (int i = 0; i < n; i++)
                        {
                            Point v1 = points[i];
                            Point v2 = points[(i + 1) % n];

                            if (v1.x == v2.x)
                            {
                                if ((y > min(v1.y, v2.y)) && (y <= max(v1.y, v2.y)))
                                {
                                    if (v1.x <= x)
                                    {
                                        crossings++;
                                    }
                                }
                            }
                        }

                        if (crossings % 2 == 0)
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        break;
                    }
                }

                if (valid)
                {
                    max_area = new_area;
                }
            }
        }
    }

    return max_area;
}

int main()
{
    // cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}