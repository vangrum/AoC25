#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int part1(){
    ifstream file("input.txt");
    if (!file)
        {
            cerr << "Error opening file.\n";
            return -1;
        }

    int sol;

    string line;
    while (getline(file, line)){

    }


    return sol;
}

int part2(){
    ifstream file("input.txt");
    if (!file)
        {
            cerr << "Error opening file.\n";
            return -1;
        }

    int sol;

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