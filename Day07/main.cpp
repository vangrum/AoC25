#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

long long part1()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    long long sol = 0;

    string line;
    string prev;
    bool first = true;
    while (getline(file, line))
    {
        int n = line.size();
        if (first)
        {
            first = false;
            for (int i = 0; i < n; i++)
            {
                char ch = line[i];
                if (ch == 'S')
                {
                    line[i] = '|';
                }
            }
        }

        else
        {
            for (int i = 0; i < n; i++)
            {
                if (prev[i] == '|')
                {
                    if (line[i] == '^')
                    {
                        sol++;
                        if (i > 0)
                            line[i - 1] = '|';
                        if (i < n - 1)
                            line[i + 1] = '|';
                    }
                    else
                    {
                        line[i] = '|';
                    }
                }
            }
        }

        prev = line;
    }

    return sol;
}

long long part2()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    long long sol = 0;

    string line;
    vector<long long> prev;
    bool first = true;
    while (getline(file, line))
    {
        int n = line.size();
        vector<long long> cur(n, 0);
        if (first)
        {
            first = false;
            for (int i = 0; i < n; i++)
            {
                if (line[i] == 'S')
                {
                    cur[i] = 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (prev[i] != 0)
                {
                    if (line[i] == '^')
                    {
                        if (i > 0)
                            cur[i - 1] += prev[i];
                        if (i < n - 1)
                            cur[i + 1] += prev[i];
                    }
                    else
                    {
                        cur[i]+=prev[i];
                    }
                }
            }
        }
        prev = cur;
    }

    for (long long n : prev)
    {
        sol += n;
    }

    return sol;
}

int main()
{
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}