#include "../leet.h"

class Solution {
public:
  std::string numberToWords(int num) {
    std::unordered_map<int, std::string> thousands = {
        {0, ""}, {1, "Thousand"}, {2, "Million"}, {3, "Billion"}};
    std::unordered_map<char, std::string> tens = {
        {'2', "Twenty"}, {'3', "Thirty"},  {'4', "Forty"},  {'5', "Fifty"},
        {'6', "Sixty"},  {'7', "Seventy"}, {'8', "Eighty"}, {'9', "Ninety"}};
    std::unordered_map<std::string, std::string> u_twenty = {
        {"10", "Ten"},      {"11", "Eleven"},    {"12", "Twelve"},
        {"13", "Thirteen"}, {"14", "Fourteen"},  {"15", "Fifteen"},
        {"16", "Sixteen"},  {"17", "Seventeen"}, {"18", "Eighteen"},
        {"19", "Nineteen"}};
    std::unordered_map<char, std::string> digits = {
        {'1', "One"},   {'2', "Two"},   {'3', "Three"},
        {'4', "Four"},  {'5', "Five"},  {'6', "Six"},
        {'7', "Seven"}, {'8', "Eight"}, {'9', "Nine"}};
    std::vector<std::string> commas;
    if (num == 0)
      return "Zero";
    while (num != 0) {
      commas.push_back(std::to_string(num % 1000));
      num /= 1000;
    }
    std::string result = "";
    for (int i = commas.size() - 1; i >= 0; i--) {
      std::string curr = "";
      std::string num = commas[i];
      int hundreds_ix = -1;
      int tens_ix = -1;
      int ones_ix = -1;
      if (commas[i].size() == 3) {
        hundreds_ix = 0;
        tens_ix = 1;
        ones_ix = 2;
      } else if (commas[i].size() == 2) {
        tens_ix = 0;
        ones_ix = 1;
      } else {
        ones_ix = 0;
      }
      if (hundreds_ix != -1) {
        curr += digits[commas[i][0]] + " Hundred ";
      }
      if (tens_ix != -1) {
        if (commas[i][tens_ix] == '1') {
          curr += u_twenty[commas[i].substr(tens_ix, 2)] + " ";
        } else if (commas[i][tens_ix] != '0') {
          curr += tens[commas[i][tens_ix]] + " ";
        }
      }
      if (commas[i][ones_ix] != '0') {

        if (tens_ix != -1 && commas[i][tens_ix] != '1') {
          curr += digits[commas[i][ones_ix]] + " ";
        } else if (tens_ix == -1) {
          curr += digits[commas[i][ones_ix]] + " ";
        }
      }
      if (i != 0) {
        curr += thousands[i] + " ";
      }
      result += curr;
    }
    while (result.back() == ' ') {
      result.pop_back();
    }
    return result;
  }
};
