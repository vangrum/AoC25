#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int part1()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    int sol = 0;

    vector<vector<int>> grid;

    string line;
    while (getline(file, line))
    {
        grid.push_back(vector<int>());
        int n = grid.size() - 1;
        for (char ch : line)
        {
            grid[n].push_back((ch == '@') ? 1 : 0);
        }
    }

    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int c = 0;
                if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 1)
                    c++;
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                    c++;
                if (i - 1 >= 0 && j + 1 < n && grid[i - 1][j + 1] == 1)
                    c++;
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                    c++;
                if (j + 1 < n && grid[i][j + 1] == 1)
                    c++;
                if (i + 1 < m && j - 1 >= 0 && grid[i + 1][j - 1] == 1)
                    c++;
                if (i + 1 < m && grid[i + 1][j] == 1)
                    c++;
                if (i + 1 < m && j + 1 < n && grid[i + 1][j + 1] == 1)
                    c++;

                if (c < 4)
                {
                    sol++;
                }
            }
        }
    }

    return sol;
}

int part2()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    int sol = 0;

    vector<vector<int>> grid;

    string line;
    while (getline(file, line))
    {
        grid.push_back(vector<int>());
        int n = grid.size() - 1;
        for (char ch : line)
        {
            grid[n].push_back((ch == '@') ? 1 : 0);
        }
    }

    int m = grid.size();
    int n = grid[0].size();
    bool changed = true;

    while (changed)
    {
        changed = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int c = 0;
                    if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 1)
                        c++;
                    if (i - 1 >= 0 && grid[i - 1][j] == 1)
                        c++;
                    if (i - 1 >= 0 && j + 1 < n && grid[i - 1][j + 1] == 1)
                        c++;
                    if (j - 1 >= 0 && grid[i][j - 1] == 1)
                        c++;
                    if (j + 1 < n && grid[i][j + 1] == 1)
                        c++;
                    if (i + 1 < m && j - 1 >= 0 && grid[i + 1][j - 1] == 1)
                        c++;
                    if (i + 1 < m && grid[i + 1][j] == 1)
                        c++;
                    if (i + 1 < m && j + 1 < n && grid[i + 1][j + 1] == 1)
                        c++;

                    if (c < 4)
                    {
                        sol++;
                        grid[i][j]=0;
                        changed = true;
                    }
                }
            }
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