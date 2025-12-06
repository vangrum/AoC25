#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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

    vector<string> lines;
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    char operation;
    vector<char> operations;
    stringstream ss(lines[lines.size() - 1]);
    while (ss >> operation)
    {
        operations.push_back(operation);
    }

    lines.pop_back();

    vector<vector<long long>> nums;

    for (string line : lines)
    {
        vector<long long> n;
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            n.push_back(stoll(word));
        }
        nums.push_back(n);
    }

    for (int i = 0; i < operations.size(); i++)
    {
        char c = operations[i];
        long long cur = (c == '*') ? 1 : 0;
        for (auto n : nums)
        {
            if (c == '*')
            {
                cur *= n[i];
            }
            else
            {
                cur += n[i];
            }
        }
        sol += cur;
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

    vector<string> lines;
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    int f = lines.size() - 1;
    long long current = 0;
    char op;
    for (int i = 0; i < lines[0].size(); i++)
    {
        char operations_column = lines[f][i];
        if (operations_column != ' ')
        {
            sol += current;
            op = operations_column;
            current = (op == '*') ? 1 : 0;
        }

        int num = 0;
        for (int d = 0; d < f; d++)
        {
            if (lines[d][i] == ' ') continue;

            num*=10;
            num+=(int)(lines[d][i] - '0');
        }
        if (num != 0)
        {
            if (op == '*')
                current *= num;
            else
                current += num;
        }
    }

    sol += current;

    return sol;
}

int main()
{
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";
    return 0;
}