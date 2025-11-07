#include "Distribution.h"
#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::string;
using std::rand;
using std::stringstream;


void Distribution::fill_distribution_k(int k_curr) {
  //prepend end of string_input to the beginning
  string prefix;
  prefix.assign( string_input.substr(string_input.length()-k_curr, k_curr) );
  string prepended_input;
  //only prepend if k != 1
  prepended_input.assign(string_input);
  prepended_input.insert(0, prefix);
  //testing
  //cout << prepended_input << endl;
  char_distribution.clear();
  for (size_t i = 0; i < prepended_input.length()-k_curr; i++) {
    string buffer(prepended_input.substr(i, k_curr));
    string c(prepended_input.substr(i+k_curr,1));
    (char_distribution[buffer])[c]++;
  }
}
void Distribution::fill_distribution(void) {
  char_distribution.clear();
  //prepend end of string_input to the beginning
  string prefix;
  prefix.assign( string_input.substr(string_input.length()-k, k) );
  string prepended_input;
  //only prepend if k != 1
  prepended_input.assign(string_input);
  if (k != 1) {
    prepended_input.insert(0, prefix);
  }
  //testing
  //cout << prepended_input << endl;
  for (size_t i = 0; i < prepended_input.length()-k; i++) {
    string buffer(prepended_input.substr(i, k));
    string c(prepended_input.substr(i+k,1));
    (char_distribution[buffer])[c]++;
  }
}
void Distribution::print_distribution(void) {
  for (map<string, map<string,int>>::iterator it = char_distribution.begin(); it != char_distribution.end(); it++) {
    cout << it->first << ":" << endl;
    for (map<string, int>::iterator it1 = (it->second).begin(); it1 != (it->second).end(); it1++) {
      if (it1->second > 0) {
        cout << "   " << it1->first << ": " << it1->second << endl;
      }
    }
  }
}  
void Distribution::print_JSON(void) {
  cout << "{" << endl;
  bool before = false;
  for (map<string, map<string,int>>::iterator it = char_distribution.begin(); it != char_distribution.end();) {

    cout << "  \"" << it->first << "\": {" << endl;

    for (map<string, int>::iterator it1 = (it->second).begin(); it1 != (it->second).end(); it1++) {

      if (it1->second > 0) {
        if (before) {
          cout << "," << endl << "      \"" << it1->first << "\": " << it1->second;
        }
        else {
          cout <<"      \"" << it1->first << "\": " << it1->second;
        }
        before = true;
      }
    }
    before = false;
    it++;
    if (it != char_distribution.end()) {
      cout << endl << "   }," << endl;
    }
    else {
      cout << endl << "   }" << endl;
    }
  }
  cout << "}" << endl;
}
//returns the probability map for a histogram map of one k length of characters
map<string, double> Distribution::ret_probability(map<string, int> histo) { 
  map<string, double> probabilities;
  double sum = (histo_sum(histo));
  if (sum <= 0.0) {
    return probabilities;  // return empty map if sum is 0
  }
  for (map<string, int>::iterator it = histo.begin(); it != histo.end(); it++) {
    if (it->second > 0) {
      probabilities[it->first] = static_cast<double>(it->second) / sum;
    }
  }
  return probabilities;
}
void Distribution::print_probabilities(void) {
  for (map<string, map<string,double>>::iterator it = char_total_probs.begin(); it != char_total_probs.end(); it++) {
    cout << it->first << ":" << endl;
    for (map<string, double>::iterator it1 = (it->second).begin(); it1 != (it->second).end(); it1++) {
      if (it1->second > 0) {
        cout << "   " << it1->first << ": " << it1->second << endl;
      }
    }
  }
}  
string Distribution::next_char_from_k(std::string k_string) {
  probs = char_total_probs[k_string];
  double cumulative = 0.0;
  double rando = (double)rand()/(double)RAND_MAX;
  for (map<string, double>::iterator it = probs.begin(); it != probs.end(); it++) {
    cumulative = cumulative + it->second;
    if (rando < cumulative) {
      return it->first;
    }
  }
  return " ";
}
void Distribution::print_k_analysis(string k_starter, int n) {
  std::stringstream ss;
  string k_string(k_starter);
  ss << k_string;
  fill_distribution_k(k_string.length());
  for (std::map<std::string, std::map<std::string,int>>::iterator it = char_distribution.begin(); it != char_distribution.end(); it++) {
    char_total_probs[it->first] = ret_probability(it->second);
  }
  for (int i = 1; i <= n-(int)k_starter.length(); i++) {
    ss << next_char_from_k(k_string);
    string next_string(ss.str().substr(i,k_starter.length()));
    k_string.assign(next_string);
  }
  //formatting
  cout << "Level " << k_starter.length() << ": " << endl <<ss.str() << endl;
}
string Distribution::get_k_starter(int k) {
  return string_input.substr(0,k); //get the starting k letters for your sequence
}
void Distribution::print_full_analysis(int n) {
  int k_max = k;
  for (int i = 1; i <= k_max; i++) {
    k = i;
    print_k_analysis( get_k_starter(k), n );
    if (k != k_max) {
      cout << "~~~" << endl;
    }
  }
}