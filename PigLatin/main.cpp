//
//  main.cpp
//  PigLatin
//
//  Created by admin on 10/26/16.
//  Copyright © 2016 admin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <array>
#include <iterator>

using namespace std;

class IgpayAtinlay{
protected:
   //note 'y' can be either a vowel or a consonant
   array<string, 38> consonants =
      {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m",
       "n", "p", "q", "r", "s", "t", "v", "w", "x", "z",
       "cc", "ch", "gh", "gu", "ph", "qu", "sc", "sh", "th",
       "wh", "kn", "gn", "pn", "ps", "rh", "wr", "tch", "sch"};
   array<string, 37> vowelSounds =
      {"a", "e", "i", "o", "u", "ea", "ee", "y", "ai", "ay", "ei",
       "ey", "ea", "ar", "ie", "uy", "ou", "ow", "or", "aw", "au",
       "al", "wa", "oi", "oy", "oa", "ew", "eu", "ue", "ui", "oo",
       "er", "ur", "ir", "or", "ar", "ear"};
   string consSuffix = "ay";
   string vowelSuffix = "way";
   string FormLatin(string word, string prefix, string suffix){
      //get numLet in prefix and form substr from the non-inclusive letter
      //append the prefix & suffix to back of new substr
      string piggified, appendMe;
      appendMe += prefix; appendMe += suffix;
      //cout << "Prefix: " << prefix << "| Suffix:" << suffix;
      //cout << "| Appended:" << appendMe << endl;
      int wordIndex = (int)std::strlen(word.c_str() - 1);
      int prefixIndex = (int)std::strlen(prefix.c_str() + 1);
      piggified = word.substr(++prefixIndex, wordIndex);
      piggified += appendMe;
      return piggified;
   }
public:
   //parses the string and returns the word
   //needs to append prefix to back and append suffix
   string Arsepay(string word){
      string output;
      string curCompare;
      for (auto pre = consonants.rbegin(); pre != consonants.rend(); ++pre){
         //loops for each letter possibility from largest to smallest
         int x;
         for (x = 2, curCompare = word.substr(0, x);
              x >= 0; --x, curCompare = word.substr(0, x)){
            if (*pre == curCompare){
               return FormLatin(word, *pre, consSuffix);
            }
         }
      }
      for (auto pre = vowelSounds.rbegin(); pre != vowelSounds.rend(); ++pre){
         int y;
         for (y = 2, curCompare = word.substr(0, y);
              y >= 0; --y, curCompare = word.substr(0, y)){
            if (*pre == curCompare){
               return FormLatin(word, *pre, vowelSuffix);
            }
         }
      }
      return output;
   }
};

IgpayAtinlay PigLatin;
string getString();
const int max_phrase_len = 4;

int main() {
   while(true){
      string word, rasephay;
      word = getString();
      rasephay = PigLatin.Arsepay(word);
      cout << "Your converted phrase is: " << rasephay <<endl;
   }
   return 0;
}

string getString(){
   string strBuffer, strInput;
   while (cout << "Enter phrase to convert to pig latin >= " <<
          max_phrase_len << ": " && getline(cin, strInput)){
      istringstream(strBuffer) >> strInput;
      if (strlen(strInput.c_str()) >= max_phrase_len){
         return strInput;
      }
   }
   return strInput;
}