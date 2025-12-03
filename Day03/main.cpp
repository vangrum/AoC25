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

    string line;
    while (getline(file, line))
    {
        // vrstico spremenimo v vektor int
        char ch;
        vector<int> nums;
        for (char ch : line)
        {
            nums.push_back(ch - '0');
        }

        int left = 0;
        int right = 0;
        int k = 0;
        int n = nums.size();
        int num = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > left)
            {
                left = nums[i];
                right = 0;
                k = i;
            }
            for (int j = k + 1; j < n; j++)
            {
                if (right < nums[j])
                {
                    right = nums[j];
                }
            }
        }

        sol += 10 * left + right;
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
        vector<int> nums;
        for (char ch : line)
            nums.push_back(ch - '0');

        long long n = nums.size();
        vector<int> current;
        
        int prev = 0;
        for(int i=0; i<12; i++){
            int m = 0;
            for(int k=prev; k<=n-12+i; k++){
                if(nums[k]>m){
                    m=nums[k];
                    prev = k+1;
                }
                if(m==9){
                    break;
                }
            }
            current.push_back(m);
        }

        long long num = 0;
        for (int d : current)
            num = num * 10 + d;

        sol += num;
    }

    return sol;
}

int main()
{
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}