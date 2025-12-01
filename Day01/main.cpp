#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int part1() {
    ifstream file("input.txt");
    if (!file)
        cerr << "Error opening file.\n";
        return -1;

    int current = 50;
    int sol = 0;

    string line;
    while (getline(file, line))
    {
        int rotate = stoi(line.substr(1)) % 100;

        if (line[0] == 'L')
            current -= rotate;
        else
            current += rotate;

        if (current < 0)
            current += 100;
        else if (current >= 100)
            current -= 100;

        if (current == 0)
            sol++;
    }

    return sol;
}

int part2() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error opening file.\n";
        return -1;
    }

    int current = 50;
    int sol = 0;

    string line;
    while (getline(file, line))
    {   
        int previous = current;
        int rotate = stoi(line.substr(1));
        sol += rotate / 100;
        rotate = rotate % 100;

        if (line[0] == 'L')
            current -= rotate;
        else
            current += rotate;

        if (current < 0)
        {
            current += 100;
            if (previous != 0) sol++;
        }
        else if (current == 0)
            sol++;
        else if (current == 100)
        {
            current -= 100;
            sol++;
        }
        else if (current > 100)
        {
            current -= 100;
            sol++;
        }
    }

    return sol;
}

int main() {
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";
    return 0;
}
