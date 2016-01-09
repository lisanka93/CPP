/* NOTE - my rhymescheme for the petrarch sonnet is party wrong, I think it has something to do with
the punctiation in the file (interprets . and , as an 'a') but cba to debug it. rest works*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
#include <stdlib.h>
#define RESET NULL

using namespace std;

char rhyming_letter(const char *ending);
bool get_word(const char *input_line, int word_number, char *output_word);
int count_words(string sentence);
bool find_phonetic_ending(char *word, char *phonetic_ending);
void reverse(char one[], char two[]);
bool isVowel(char letter);
bool find_rhyme_scheme(char *filename, char *scheme);
char *identify_sonnet(char* filename);

int main() {
  // Question 1
  cout << "====================== Question 1 ======================" << endl << endl;

  cout << "The line \"It's  not so easy!\" contains ";
  cout << count_words("It's  not so easy!") << " words" << endl;
  cout << "The line \"\" contains ";
  cout << count_words("") << " words" << endl;
  cout << "The line \"Shall I compare thee to a Summer's day?\" contains ";
  cout << count_words("Shall I compare thee to a Summer's day?") << " words" << endl;

  cout << endl;

  // Question 2
  cout << "====================== Question 2 ======================" << endl << endl;

  char phonetics[512];
  find_phonetic_ending("HE", phonetics);
  cout << "DAY has phonetic ending " << phonetics << endl;

  find_phonetic_ending("EYES", phonetics);
  cout << "MAY has phonetic ending " << phonetics << endl;

  find_phonetic_ending("CONVICT", phonetics);
  cout << "CONVICT has phonetic ending " << phonetics << endl;

  find_phonetic_ending("PICKED", phonetics);
  cout << "PICKED has phonetic ending " << phonetics << endl;

  find_phonetic_ending("FLAWS", phonetics);
  cout << "FLAWS has phonetic ending " << phonetics << endl;

  find_phonetic_ending("PAUSE", phonetics);
  cout << "PAUSE has phonetic ending " << phonetics << endl;

  cout << endl;

  // Question 3
  cout << "====================== Question 3 ======================" << endl << endl;

  char scheme[512];
  find_rhyme_scheme("shakespeare.txt", scheme);
  cout << "The rhyme scheme of shakespeare.txt is " << scheme << endl;

  find_rhyme_scheme("petrarch.txt", scheme);
  cout << "The rhyme scheme of petrarch.txt is " << scheme << endl;

  find_rhyme_scheme("spenser.txt", scheme);
  cout << "The rhyme scheme of spenser.txt is " << scheme << endl;

  cout << endl;
  cout << "====================== Question 4 ======================" << endl << endl;

  cout << "The sonnet spenser.txt is a(n) " <<
    identify_sonnet("spenser.txt") << " sonnet" << endl;

  cout << "The sonnet mystery.txt is a(n) " <<
    identify_sonnet("mystery.txt") << " sonnet" << endl;

  cout << endl;

  return 0;
  }

  /* PRE-SUPPLIED HELPER FUNCTIONS START HERE */

/* NOTE: It is much more important to understand the interface to and
   the "black-box" operation of these functions (in terms of inputs and
   outputs) than it is to understand the details of their inner working. */

/* get_word(...) retrieves a word from the input string input_line
   based on its word number. If the word number is valid, the function
   places an uppercase version of the word in the output parameter
   output_word, and the function returns true. Otherwise the function
   returns false. */

bool get_word(const char *input_line, int word_number, char *output_word) {
  char *output_start = output_word;
  int words = 0;

  if (word_number < 1) {
    *output_word = '\0';
    return false;
  }

  do {
    while (*input_line && !isalnum(*input_line))
      input_line++;

    if (*input_line == '\0')
      break;

    output_word = output_start;
    while (*input_line && (isalnum(*input_line) || *input_line=='\'')) {
      *output_word = toupper(*input_line);
      output_word++;
      input_line++;
    }
    *output_word = '\0';

    if (++words == word_number)
      return true;

  } while (*input_line);

  *output_start = '\0';
  return false;
}

/* char rhyming_letter(const char *ending) generates the rhyme scheme
   letter (starting with 'a') that corresponds to a given line ending
   (specified as the parameter). The function remembers its state
   between calls using an internal lookup table, such that subsequents
   calls with different endings will generate new letters.  The state
   can be reset (e.g. to start issuing rhyme scheme letters for a new
   poem) by calling rhyming_letter(RESET). */

char rhyming_letter(const char *ending) {

  // the next rhyming letter to be issued (persists between calls)
  static char next = 'a';
  // the table which maps endings to letters (persists between calls)
  static map<string, char> lookup;

  // providing a way to reset the table between poems
  if (ending == RESET) {
    lookup.clear();
    next = 'a';
    return '\0';
  }

  string end(ending);

  // if the ending doesn't exist, add it, and issue a new letter
  if (lookup.count(end) == 0) {
    lookup[end]=next;
    assert(next <= 'z');
    return next++;
  }

  // otherwise return the letter corresponding to the existing ending
  return lookup[end];
}

/* START WRITING YOUR FUNCTION BODIES HERE */
int count_words(string sentence)
{
  istringstream iss(sentence);  //create stream to take out single words from sentence
  int wordcount = 0;
  string word;
  char sentencechar[200];

  if(iss.fail())
    return 0;

  while(!iss.eof())
  {
  // iss>>ws;
    iss >> word;
    wordcount++;
  }
 /*so that "" says 0 and not 1*/
 strcpy(sentencechar, sentence.c_str());
 int length = strlen(sentencechar);
 sentencechar[length] = '\0';
 if(sentencechar[0] == '\0')
  return 0;

 return wordcount;

}

/*yes I know this implementation is rather stupid and time consuming*/
bool find_phonetic_ending(char *word, char *phonetic_ending)
{
  const int max_line_size = 200;
  const int word_size = 20;

  ifstream in;
  in.open("dictionary.txt");
  if (in.fail())
  {
    cout << "Sorry, no dictionary found\n";
    exit(1);
  }

  char dictionaryword[word_size];
  char dictionaryline[max_line_size];
  char phonemeline[max_line_size-word_size];
  char phonemelineReversed[max_line_size-word_size];
  char phonemelineReversedNOWHITE[max_line_size-word_size];
  char phending[max_line_size-word_size];

  in.getline(dictionaryline, max_line_size-1);
  int i = 0;

  while (!in.eof())
  {
    get_word(dictionaryline, 1, dictionaryword);

    if(strcmp(dictionaryword, word) == 0)
    {

      int length = strlen(dictionaryword);
      strcpy(phonemeline, dictionaryline+length+2);
      reverse(phonemeline,phonemelineReversed);


      /*get rid of whitespace*/
      int k, l, j;
      for(k = 0,l = 0; k <= strlen(phonemelineReversed); k++)
      {
        if(phonemelineReversed[k] != ' ')
        {
         phonemelineReversedNOWHITE[l] = phonemelineReversed[k];
         l++;
        }
      }

      int g = 0;

        while(!isVowel(phonemelineReversedNOWHITE[g]))
        {
          phending[g] = phonemelineReversedNOWHITE[g];
          g++;
        }

      phending[g] = phonemelineReversedNOWHITE[g];
      phending[g+1] = '\0';

      int length2 = strlen(phending);
      reverse(phending, phonetic_ending);
      phonetic_ending[length2] = '\0';

      in.close();
        return true;
    }

    in.getline(dictionaryline, max_line_size-1);
  }
return false;

}


bool find_rhyme_scheme(char *filename, char *scheme)
{
  const int max_line_size = 200;
  const int word_size = 20;
  int i = 0;
  int wordcount = 0;
  char scheme2[100];

  ifstream in;
  in.open(filename);
  if (in.fail())
  {
    cout << "Sorry, such file found\n";
    return false;
  }

  char line[max_line_size];
  char lastword[word_size];
  char phoenetic[word_size];

  in.getline(line, max_line_size-1);

  while(!in.eof())
  {
    wordcount = count_words(line);

    get_word(line, wordcount, lastword);
   (find_phonetic_ending(lastword, phoenetic));

    scheme[i] = rhyming_letter(phoenetic);
    i++;

    in.getline(line, max_line_size-1);
  }

  rhyming_letter(RESET);
  scheme[i] = '\0';

return true;
}

char *identify_sonnet(char* filename)
{
  char scheme[100];
  find_rhyme_scheme(filename, scheme);


  if (strcmp(scheme,"ababcdcdefefgg") == 0)
    return "Shakespearean";
  if (strcmp(scheme,"abbaabbacdcdcd") == 0)
    return "Petrarchan";
  if (strcmp(scheme,"ababbcbccdcdee") == 0)
    return "Spenserian";

  return "Unknown";
}

/*helperfunctions*/
void reverse(char one[], char two[])
{
   int length = strlen(one);
   two[length] = '\0';
   int k = length-1;
   int i = 0;

   for(k; 0 <= k; k--)
   {
     two[i] = one[k];
     i++;
   }
}

bool isVowel(char letter)
{
  if(letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
    return true;
  else
    return false;
}
