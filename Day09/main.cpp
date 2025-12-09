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

                int p_min_x = min(p1.x, p2.x);
                int p_max_x = max(p1.x, p2.x);
                int p_min_y = min(p1.y, p2.y);
                int p_max_y = max(p1.y, p2.y);

                for (int i = 0; i < n; i++)
                {
                    Point v1 = points[i];
                    Point v2 = points[(i + 1) % n];

                    int v_min_x = min(v1.x, v2.x);
                    int v_max_x = max(v1.x, v2.x);
                    int v_min_y = min(v1.y, v2.y);
                    int v_max_y = max(v1.y, v2.y);

                    if (v_min_x == v_max_x)
                    {
                        if (p_min_x < v_max_x && v_max_x < p_max_x)
                        {
                            if (!(v_max_y <= p_min_y || v_min_y >= p_max_y))
                            {
                                valid = false;
                                break;
                            }
                        }
                    }
                    else if (v_min_y == v_max_y)
                    {
                        if (p_min_y < v_max_y && v_max_y < p_max_y)
                        {
                            if (!(v_max_x <= p_min_x || v_min_x >= p_max_x))
                            {
                                valid = false;
                                break;
                            }
                        }
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
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}