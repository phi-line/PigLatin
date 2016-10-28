#include <iostream>
#include <cstring>
#include <sstream>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
using Iter = vector<string>::const_iterator;

class IgpayAtinlay{
protected:
   //note 'y' can be either a vowel or a consonant
   array<string, 38> consonants =
      {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m",
       "n", "p", "q", "r", "s", "t", "v", "w", "x", "z",
       "cc", "ch", "gh", "gu", "ph", "qu", "sc", "sh", "th",
       "wh", "kn", "gn", "pn", "ps", "rh", "wr", "tch", "sch"};
   array<string, 36> vowelSounds =
      {"a", "e", "i", "o", "u", "ea", "ee", "ai", "ay", "ei",
       "ey", "ea", "ar", "ie", "uy", "ou", "ow", "or", "aw", "au",
       "al", "wa", "oi", "oy", "oa", "ew", "eu", "ue", "ui", "oo",
       "er", "ur", "ir", "or", "ar", "ear"};
   string CONS_SUFFIX = "ay";
   string VOWEL_SUFFIX = "way";
   string Y_CHAR = "y";
   string FormLatin(string word, string suffix){
      word += suffix;
      return word;
   }
//get numLet in prefix and form substr from the non-inclusive letter
//append the prefix & suffix to back of new substr
   string FormLatin(string word, string prefix, string suffix){
      if (word.length() <= 2){
         return word+=suffix;
      }
      string piggified, appendMe;
      appendMe += prefix + suffix;
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
      //special case for 'y'
      size_t found = word.find_first_of("y");
      if (word[0] == 'y'){
         return FormLatin(word, Y_CHAR, VOWEL_SUFFIX);
      } else if (found != string::npos){
         //get letters before and append it as pre!
         return FormLatin(word, word.substr(0, found), CONS_SUFFIX);
      }
      for (auto pre = consonants.rbegin(); pre != consonants.rend(); ++pre){
         //loops for each letter possibility from largest to smallest (trickle)
         int x;
         string curCompare;
         for (x = 2, curCompare = word.substr(0, x);
              x >= 0; --x, curCompare = word.substr(0, x)){
            if (*pre == curCompare){
               return FormLatin(word, *pre, CONS_SUFFIX);
            }
         }
      }
      for (auto pre = vowelSounds.rbegin(); pre != vowelSounds.rend(); ++pre){
         int x;
         string curCompare;
         for (x = 2, curCompare = word.substr(0, x);
              x >= 0; --x, curCompare = word.substr(0, x)){
            if (*pre == curCompare){
               return FormLatin(word, *pre, VOWEL_SUFFIX);
            }
         }
      }
      return FormLatin(word, VOWEL_SUFFIX);
   }
   string PhraseParser(vector<string> phrase){
      stringstream ss;
      string strOutput, convertMe;
      for (Iter it = phrase.begin(); it != phrase.end(); ++it){
         convertMe = Arsepay(*it);
         strOutput += convertMe + " ";
      }
      return strOutput;
   }
};

IgpayAtinlay PigLatin;
string getString();
vector<string> parseSentence();
const int max_phrase_len = 3;

int main() {
   while(true){
   string word, ordway, rasephay;
//   word = getString();
//   ordway = PigLatin.Arsepay(word);
//   cout << "Your converted word is: " << ordway <<endl;
   rasephay = PigLatin.PhraseParser(parseSentence());
   cout << "Your converted phrase is: " << rasephay << endl;
   }
   return 0;
}

string getString(){
   string strBuffer, strInput;
   while (cout << "Enter word to convert to pig latin >= " <<
          max_phrase_len << ": " && getline(cin, strInput)){
      istringstream(strBuffer) >> strInput;
      if (strlen(strInput.c_str()) >= max_phrase_len){
         transform(strInput.begin(), strInput.end(),
                   strInput.begin(), ::tolower);
         return strInput;
      }
   }
   return strInput;
}

vector<string> parseSentence(){
   string strInput;
   while (cout << "Enter phrase to convert to pig latin >= " <<
          max_phrase_len << ": " && getline(cin, strInput)){
      if (strlen(strInput.c_str()) >= max_phrase_len){
         break;
      }
   }
   transform(strInput.begin(), strInput.end(),
             strInput.begin(), ::tolower);
   stringstream ss(strInput);
   istream_iterator<string> begin(ss);
   istream_iterator<string> end;
   vector<string> words(begin, end);
   return words;
}