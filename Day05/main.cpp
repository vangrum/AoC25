#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

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

    set<pair<long long, long long>> temp_ranges;

    for (auto a : ranges)
    {
        long long lower = a.first;
        long long upper = a.second;
        for (auto b : ranges)
        {
            if (b.first < lower && b.second > lower)
            {
                lower = b.first;
            }
            else if (b.first < upper && b.second > upper)
            {
                upper = b.second;
            }
            else if (b.first > lower && b.second < upper)
            {
                continue;
            }
        }
        temp_ranges.insert(make_pair(lower, upper));
    }

    set<pair<long long, long long>> new_ranges;

    for (set<pair<long long, long long>>::iterator it1 = temp_ranges.begin(); it1 != temp_ranges.end(); it1++)
    {
        bool valid = true;
        for (set<pair<long long, long long>>::iterator it2 = temp_ranges.begin(); it2 != temp_ranges.end(); it2++)
        {
            if (it1 == it2)
                continue;
            if (it1->first >= it2->first && it1->second <= it2->second)
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            new_ranges.insert(*it1);
        }
    }

    set<long long> seen;
    for (auto [l, u] : new_ranges)
    {
        cout << l << ' ' << u << endl;
        sol += u - l + 1;
        if(seen.count(l)!=0){
            sol--;
        }
        if(seen.count(u)!=0){
            sol--;
        }
        seen.insert(l);
        seen.insert(u);
    }

    return sol;
}

int main()
{
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}