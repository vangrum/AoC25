#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

long part1()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    long sol = 0;

    vector<vector<string>> content;
    vector<string> v;
    string line, field;
    while (getline(file, line))
    {
        v.clear();
        stringstream ss(line);
        while (getline(ss, field, '-'))
        {
            v.push_back(field);
        }
        content.push_back(v);
    }

    vector<pair<long long, long long>> ranges;
    vector<long long> ids;

    for (auto &c : content)
    {
        // cout<<c.size()<<endl;
        if (c.size() == 2)
        {
            // cout<<stol(c[0])<<' '<<stol(c[1])<<endl;
            ranges.push_back(make_pair(stoll(c[0]), stoll(c[1])));
        }
        if (c.size() == 0)
        {
            continue;
        }
        if (c.size() == 1)
        {
            // cout << stol(c[0])<<endl;
            ids.push_back(stoll(c[0]));
        }
    }

    for (long long id : ids)
    {
        bool fresh = false;
        for (pair<long long, long long> range : ranges)
        {
            // cout<<id<<' '<<range.first<<' '<<range.second<<endl;
            if (id >= range.first && id <= range.second)
            {
                fresh = true;
                break;
            }
        }
        if (fresh)
        {
            sol++;
        }
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

    vector<vector<string>> content;
    vector<string> v;
    string line, field;
    while (getline(file, line))
    {
        v.clear();
        stringstream ss(line);
        while (getline(ss, field, '-'))
        {
            v.push_back(field);
        }
        content.push_back(v);
    }

    vector<pair<long long, long long>> ranges;

    for (auto &c : content)
    {
        if (c.size() == 2)
        {
            ranges.push_back(make_pair(stoll(c[0]), stoll(c[1])));
        }
        if (c.size() == 0)
        {
            continue;
        }
        if (c.size() == 1)
        {
            continue;
        }
    }

    sort(ranges.begin(), ranges.end());

    vector<pair<long long, long long>> new_ranges;

    for(int i = 1; i<ranges.size(); i++){
        auto &a = ranges[i-1];
        auto &b = ranges[i];

        if(b.first<=a.second)
        {
            b.first = a.first;
            b.second = max(a.second, b.second);
        }
        else
        {
            new_ranges.push_back(a);
        }
        if(i==ranges.size()-1){
            new_ranges.push_back(b);
        }
    }

    for(auto [l, u] : new_ranges)
    {
        cout<<l<<' '<<u<<endl;
        sol+=u-l+1;
    }
    
    return sol;
}

int main()
{
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}