#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// funkcija za določitev kombinacij prirejena iz tega primera: http://rosettacode.org/wiki/Combinations#C.2B.2B
vector<vector<int>> comb(int N, int K)
{
    vector<vector<int>> combs;
    std::string bitmask(K, 1);
    bitmask.resize(N, 0);

    do
    {
        vector<int> cur;
        for (int i = 0; i < N; ++i)
        {
            if (bitmask[i])
                cur.push_back(i);
        }
        combs.push_back(cur);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    return combs;
}

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
    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        vector<string> v;
        while (ss >> word)
        {
            v.push_back(word);
        }

        int n = v.size();

        vector<int> states;
        for (char ch : v[0])
        {
            if (ch == '#')
                states.push_back(1);
            else if (ch == '.')
                states.push_back(0);
        }

        vector<vector<int>> buttons(n - 2, vector<int>{});
        for (int i = 1; i < n - 1; i++)
        {
            for (char ch : v[i])
            {
                int d = ch - '0';
                if (d >= 0 && d <= 9)
                    buttons[i - 1].push_back(d);
            }
        }
        int min_presses = INT_MAX;
        int N = buttons.size();
        for (int K = 1; K <= N; K++)
        {
            if (K < min_presses)
            {
                vector<vector<int>> combinations = comb(N, K);
                for (vector<int> combination : combinations)
                {
                    vector<int> presses(states.size(), 0);
                    bool valid = true;

                    for (int button : combination)
                    {
                        for (int light : buttons[button])
                        {
                            presses[light]++;
                        }
                    }

                    for (int s = 0; s < states.size(); s++)
                    {
                        if (presses[s] % 2 != states[s])
                        {
                            valid = false;
                            break;
                        }
                    }

                    if (valid)
                    {
                        min_presses = K;
                    }
                }
            }
        }
        if (min_presses == INT_MAX)
        {
            cout << N << ' ' << line;
            return -1;
        }
        sol += min_presses;
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
    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        vector<string> v;
        while (ss >> word)
        {
            v.push_back(word);
        }

        int n = v.size();

        vector<vector<int>> buttons(n - 2, vector<int>{});
        for (int i = 1; i < n - 1; i++)
        {
            for (char ch : v[i])
            {
                int d = ch - '0';
                if (d >= 0 && d <= 9)
                    buttons[i - 1].push_back(d);
            }
        }

        vector<int> joltages;
        string string_joltages = v[n - 1];
        stringstream j((string_joltages).substr(1, string_joltages.size() - 2));
        string str;
        while (getline(j, str, ','))
        {
            joltages.push_back(stoi(str));
        }

        set<int, greater<int>> s(joltages.begin(), joltages.end());
    }

    return sol;
}

int main()
{
    cout << "Part 1 solution: " << part1() << "\n";
    //cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}