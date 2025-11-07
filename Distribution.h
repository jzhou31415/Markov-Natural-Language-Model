#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

class Distribution {
  public:
    //default constructor
    Distribution(): k(1)  {}
    //main constructor
    Distribution(int k_in, std::string string_in) {
      k = k_in;
      string_input.assign(string_in);
      fill_distribution_k(k);
      //fills the probability table with the values for k
      for (std::map<std::string, std::map<std::string,int>>::iterator it = char_distribution.begin(); it != char_distribution.end(); it++) {
        char_total_probs[it->first] = ret_probability(it->second);
      }
    }
    //public get functions
    int get_k(void) {
      return k;
    }  
    std::map<std::string, std::map<std::string,int>> get_char_dist(void) {
      return char_distribution;
    }
    //returns the total amount of characters that precede a certain character in histogram
    int histo_sum_after_x(std::string x) {
      int sum = 0;
      std::map<std::string, int> histo = char_distribution[x];
      for (std::map<std::string, int>::iterator it = histo.begin(); it != histo.end(); it++) {
        if ( (it->second) > 0 ) {
          sum+= it->second;
        }
      }
      return sum;
    }
    //return sum of characters in histo
    int histo_sum(std::map<std::string, int> histo) {
      int sum = 0;
      for (std::map<std::string, int>::iterator it = histo.begin(); it != histo.end(); it++) {
        if ( (it->second) > 0 ) {
          sum+= it->second;
        }
      }
      return sum;
    }
    //fill the char_distribution map like a histogram
    void fill_distribution(void);
    void print_distribution(void);
    void print_JSON(void);
    void fill_distribution_k(int k_curr);
    void print_probabilities(void);
    void print_output(int k_curr, int num_chars);
    std::map<std::string, double> ret_probability(std::map<std::string, int>);
    std::string next_char_from_k(std::string k_string);
    void print_k_analysis(std::string k_starter, int n);
    void print_full_analysis(int n);
    std::string get_k_starter(int k);
  private:
    std::string string_input;
    int k;
    std::map<std::string,int> histogram;
    std::map<std::string, std::map<std::string,int>> char_distribution;
    std::map<std::string, double> probs;
    std::map<std::string, std::map<std::string,double>> char_total_probs;
};
//map of maps map<"string", map<each possible following char, number of times appeared>>

#endif
