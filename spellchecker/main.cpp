#include "WordList.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

// This file provides an interactive loop.
// It's much easier to use in conjunction with helper.py.
// See the hints section in the readme for details.


std::vector<Point> read_points(const std::string& line) {
    Point point;
    std::vector<Point> results;
    std::istringstream stream(line);
    while(stream >> point.x) {
        if(!(stream >> point.y)) {
            throw std::runtime_error("Odd number of points.");
        }

        results.push_back(point);
    }

    if(results.size() == 0) {
        throw std::runtime_error("No points given.");
    }

    return results;
}
//int main(){
int main(int argc, char** argv) {
    /*
    size_t num = 8;
    Heap test(num);
    test.push("one", 1);
    test.push("two", 2);
    test.push("three", 3);
    test.push("four", 4);
    const Heap::Entry newTest = test.lookup(4);
    cout << newTest.value << endl;
    */
    //cout << test.count() << " " << test.capacity() << endl;

    
    if(argc != 2) {
        std::cout << "USAGE: " << argv[0] << " [words-file]\n";
        return 1;
    }

    // Change these to test different cases!
    size_t maxcount = 5;
    float  cutoff   = 0;

    // Read in the words file
    WordList* wordlist = nullptr;
    try {
        std::ifstream stream(argv[1]);
        if(stream.fail()) {
            std::cout << "Could not open file: " << argv[1] << '\n';
            return 1;
        }

        wordlist = new WordList(stream);
    }
    catch(const std::exception& e) {
        std::cout << "Error reading words file: " << e.what() << '\n';
        return 1;
    }

    // Set floating point format
    std::cout << std::setprecision(3);
    std::cout << std::fixed;

    // Interactive loop
    std::string line;
    std::cout << "> ";
    while(std::getline(std::cin, line)) {
        try {
            auto points = read_points(line);
            auto heap   = wordlist->correct(points, maxcount, cutoff);

            std::vector<Heap::Entry> entries;
            while(heap.count() > 0) {
                entries.push_back(heap.pop());
            }

            for(auto itr = entries.rbegin(); itr != entries.rend(); ++itr) {
                std::cout << " - " << itr->score << ": " << itr->value << '\n';
            }
            if(entries.size() == 0) {
                std::cout << " (no results)\n";
            }
        }
        catch(const std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }

        std::cout << "> ";
    }

    delete wordlist;
    return 0;
    
}
