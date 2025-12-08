#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

long long part1()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    vector<vector<int>> content;

    string line;
    while (getline(file, line))
    {
        vector<int> v;
        stringstream ss(line);
        string num;
        while (getline(ss, num, ','))
        {
            v.push_back(stoi(num));
        }
        content.push_back(v);
    }

    multimap<long long, pair<vector<int>, vector<int>>> mm;

    int n = content.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long x = content[i][0] - content[j][0];
            long long y = content[i][1] - content[j][1];
            long long z = content[i][2] - content[j][2];
            mm.insert({x * x + y * y + z * z, make_pair(content[i], content[j])});
        }
    }

    vector<set<vector<int>>> graphs;
    int c = 0;
    for (auto [d, p] : mm)
    {
        if (c == 1000)
            break;

        graphs.push_back(set<vector<int>>({p.first, p.second}));
        int s = graphs.size();
        int i = 0;
        while (i < s)
        {
            for (int j = i + 1; j < s; j++)
            {
                bool merge = false;
                set<vector<int>> &g1 = graphs[i], &g2 = graphs[j];
                for (auto p1 : g1)
                {
                    if (g2.count(p1) == 1)
                    {
                        merge = true;
                        break;
                    }
                }
                if (merge)
                {
                    for (auto p1 : g1)
                    {
                        if (g2.count(p1) == 0)
                        {
                            g2.insert(p1);
                        }
                    }
                    graphs.erase(graphs.begin() + i);
                    i--;
                }
            }
            i++;
        }

        c++;
    }

    vector<int> sizes;

    for (auto graph : graphs)
    {
        sizes.push_back(graph.size());
    }

    sort(sizes.begin(), sizes.end(), greater<int>());

    return sizes[0] * sizes[1] * sizes[2];
}

map<vector<int>, vector<vector<int>>> edges;
set<vector<int>> visited;

void dfs(vector<int> point)
{
    visited.insert(point);
    for (auto neighbor : edges[point])
    {
        if (visited.count(neighbor) == 0)
        {
            dfs(neighbor);
        }
    }
}

long long part2()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening file.\n";
        return -1;
    }

    vector<vector<int>> content;

    string line;
    while (getline(file, line))
    {
        vector<int> v;
        stringstream ss(line);
        string num;
        while (getline(ss, num, ','))
        {
            v.push_back(stoi(num));
        }
        content.push_back(v);
    }

    multimap<long long, pair<vector<int>, vector<int>>> distances;

    int n = content.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long x = content[i][0] - content[j][0];
            long long y = content[i][1] - content[j][1];
            long long z = content[i][2] - content[j][2];
            distances.insert({x * x + y * y + z * z, make_pair(content[i], content[j])});
        }
    }

    for (auto [distance, points] : distances)
    {
        edges[points.first].push_back(points.second);
        edges[points.second].push_back(points.first);
        visited.clear();

        dfs(points.first);

        if (visited.size() == n)
        {
            return (points.first[0] * points.second[0]);
        }
    }

    return -1;
}

int main()
{
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}
