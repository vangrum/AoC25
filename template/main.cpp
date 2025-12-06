#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long part1(){
    ifstream file("input.txt");
    if (!file)
        {
            cerr << "Error opening file.\n";
            return -1;
        }

    long long sol = 0;

    string line;
    while (getline(file, line)){

    }


    return sol;
}

long long part2(){
    ifstream file("input.txt");
    if (!file)
        {
            cerr << "Error opening file.\n";
            return -1;
        }

    long long sol = 0;

    string line;
    while (getline(file, line)){

    }


    return sol;
}

int main(){
    cout << "Part 1 solution: " << part1() << "\n";
    cout << "Part 2 solution: " << part2() << "\n";

    return 0;
}