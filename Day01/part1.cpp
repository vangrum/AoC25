#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("input.txt");

    if (!file)
        cerr << "Error opening file.\n";

    int current = 50;
    int sol = 0;

    string line;
    while (getline(file, line))
    {
        int rotate = stoi(line.substr(1))%100;

        if (line[0] == 'L')
        {
            current -= rotate;
        }
        else
        {
            current += rotate;
        }
        if (current < 0)
        {
            current += 100;
        }
        else if (current >= 100)
        {
            current -= 100;
        }
        if (current == 0)
            sol++;
    }

    cout << "Part 1 solution: "<< sol;

    return 0;
}