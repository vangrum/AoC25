#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<long long>> ranges;

long long value1(long long x)
{
    string s = to_string(x);
    int n = s.size();
    if (n % 2 == 0 && s.substr(0, n / 2) == s.substr(n / 2, n / 2))
    {
        return x;
    }
    return 0;
}

long long value2(long long x)
{
    string s = to_string(x);
    int n = s.size();

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            bool repeating = true; //zastavica
            for (int j = i; j < n; j += i)
            {
                if (s.substr(0, i) != s.substr(j, i))
                {
                    repeating = false;
                    break;
                }
            }
            if (repeating)
            {
                return x;
            }
        }
    }

    return 0;
}

long long part1()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    unsigned long long sol = 0;
    string line, range, boundary;
    while (getline(file, line))
    {
        stringstream ss(line);
        while (getline(ss, range, ','))
        {
            stringstream ss2(range);
            vector<long long> boundaries;
            while (getline(ss2, boundary, '-'))
            {
                boundaries.push_back(stoll(boundary));
            }
            ranges.push_back(boundaries);
        }
    }

    for (auto range : ranges)
    {
        long long lower = range[0];
        long long upper = range[1];

        for (long long i = lower; i <= upper; i++)
        {
            sol += value1(i);
            // cout<<i<<' '<<value1(i)<<endl;
        }
    }

    return sol;
}

long long part2()
{
    unsigned long long sol = 0;
    for (auto range : ranges)
    {
        long long lower = range[0];
        long long upper = range[1];

        for (long long i = lower; i <= upper; i++)
        {
            sol += value2(i);
            // cout<<i<<' '<<value2(i)<<endl;
        }
    }

    return sol;
}

int main()
{
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}