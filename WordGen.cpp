#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Distribution.h"
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::string;
using std::stringstream;
using std::cerr;

// You are not required to use any of the next three functions, but might find
// them useful.  Modify them if it seems appropriate to do so, or delete them.
// They may prove useful for trimming the contents of the file that you read.

/* Removes whitespace from the left end of a string */
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

/* Removes whitespace from the right end of a string */
void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

/* Removes whitespace from both ends of a string */
void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

int main(int argc, char * argv[]){

    // seed the RNG
    std::srand( ( unsigned int ) std::time( nullptr ) );
    bool print_JSON = false;
    // read command-line arguments
    // arg1: filename
    // arg2: max value of K
    // arg3: num characters to generate (or -m)
    if (4 != argc){
        cout << "ERROR: Wrong number of command-line arguments (expected 3, received " << (argc-1) << ")" << endl;
        return -1;
    }
    ifstream in_file(argv[1]);
    if (!in_file.is_open()) {
        std::cerr << "Failed to open input file" << endl;
        return 1;
    }

    int k = 0;
    if (atoi(argv[2]) < 1) {
        std::cerr << "Invalid k value (Has to be between 1 and n inclusive)" << endl;
        return 1;
    }
    else {
        k = atoi(argv[2]);
    }

    int n = 0;
    if ((atoi(argv[3]) < 0 || atoi(argv[3]) < k) && (((string)argv[3]).compare("-m") != 0)) {
        std::cerr << "Invalid n value (Has to be greater than or equal to k)" << endl;
        return 1;
    }
    else {
        if (((string)argv[3]).compare("-m") == 0) {
            print_JSON = true;
        }
        else {
            n = atoi(argv[3]);
        }
    }

    //call constructor for Distribution
    stringstream ss;
    ss << in_file.rdbuf();
    //ss.str("abcdabcbaa afdjasdlkf asdflkjasdlkf akdfjlajsdf vawbuuwv viuabrvaklsdv voianvskjasdv flkajsdn fiahdsvb v wowv weuwuv  fh a ouwru ihj oa  oiuf akkjb h afua uohjfkhdf  fjkdf jkadf a fvkjdaf j dfjkkjdf"); // testing
    if ( (ss.str().length()) <= (size_t)k) {
        cerr << "Error: k value is too large, k cannot be greater than or equal to the length of text file" << endl;
        return 1;
    }
    Distribution dist(k, ss.str());
    dist.fill_distribution_k(k);
    //testing print_JSON
    
    if (print_JSON) {
        dist.print_JSON();
        return 0;
    }
    
    //testing comments
    //dist.print_probabilities();
    //cout << dist.histo_sum_after_x("b") << endl;
    //cout << dist.next_char_from_k("a") << endl;
    // other error checking, rest of your main code to go here :)
    //dist.print_k_analysis(dist.get_k_starter(k), n);
    dist.print_k_analysis(dist.get_k_starter(k), n);
    return 0;

}