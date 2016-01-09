#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>


/* GOOD EXERCISE - SUMS UP ALL OF THE PREVIOUS CRAP*/

using namespace std;
int findFirstVowel(char word[]);
bool isVowel(char letter);
bool isVowelY(char letter);
void translate(char word[], char translated[]);
void translateStream(istream& input, ostream& out);


int main() {

   cout << "====================== Question 1 ======================" << endl;

  int vowel;

  vowel = findFirstVowel("Passionfruit");
  cout << "The first vowel in 'Passionfruit' occurs at position " << vowel << endl;

  vowel = findFirstVowel("prune");
  cout << "The first vowel in 'prune' occurs at position " << vowel << endl;

  vowel = findFirstVowel("my");
  cout << "The first vowel in 'my' occurs at position " << vowel << endl;

  vowel = findFirstVowel("chrysanthemum");
  cout << "The first vowel in 'chrysanthemum' occurs at position " << vowel << endl;
  cout << endl;


  cout << "====================== Question 2 ======================" << endl;

  char translated[100];

  translate("grape", translated);
  cout << "In Pig Latin 'grape' is '" << translated << "'." << endl;
  translate("orange", translated);
  cout << "In Pig Latin 'orange' is '" << translated << "'." << endl;
  translate("Banana", translated);
  cout << "In Pig Latin 'Banana' is '" << translated << "'." << endl;
  translate("Yellow", translated);
  cout << "In Pig Latin 'Yellow' is '" << translated << "'." << endl;
  cout << endl;


  cout << "====================== Question 3 ======================" << endl;

  cout << "The file 'fruit.txt' translated into Pig Latin is:" << endl << endl;
  ifstream input;
  input.open("fruit.txt");
  translateStream(input, cout);
  input.close();
  cout << endl;

  return 0;
}


int findFirstVowel(char word[])
{
  int length = strlen(word);

  char copy[length];
  strcpy(copy, word);           //need copy because want to change first letter in char
  copy[length] = '\0';

  if(isupper(copy[0]))
  {
    copy[0] = (tolower(word[0]));      //otherwise couldnt manipulate it
  }

  if(isVowel(copy[0]))
    return 0;

  for( int i = 1; i < length-1; i++)  //length-1 because I need to use isVowel for length position in array
  {
    if(isVowelY(copy[i]))
      return i;
  }

  if( isVowel(copy[length-1]))         //checking that no Y
    return length-1;

return -1;

}

//helperfunctions
bool isVowel(char letter)
{
  if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
    return true;
  else
    return false;
}

bool isVowelY(char letter)
{
  if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'y')
    return true;
  else
    return false;
}


void translate(char word[], char translated[])
{
  int Uppercase=0;

  if (isupper(word[0]))           //flag for upercase
   Uppercase = 1;

  int length = strlen(word);
  char way[4] = "way";
  way[3] = '\0';

  char ay[3] = "ay";
  ay[2] = '\0';

  char firsthalf[10];
  char secondhalf[20];

  if (isdigit(word[0]))
  {
    strcpy(translated, word);
    translated[length] = '\0';
    return;
  }

  if (!isalpha(word[0]) && !isdigit((word[0])))
  {
    strcpy(translated, word);
    translated[length] = '\0';
    return;
  }

  if (isVowel(word[0]))
  {
    strcpy(translated, word);
    strcat(translated, way);
    translated[length+3] = '\0';
  }

   if (!isVowel(word[0])  )
   {

     int j = findFirstVowel(word);
     int k = 0;

     for( int i = 0; i < j; i++)
     {
       secondhalf[i] = word[i];
     }

     secondhalf[j] = '\0';
     if(isupper(secondhalf[0]))
     {
       secondhalf[0] = (tolower(secondhalf[0]));      //yea kind of stupid solution
     }

     for(k, j; j < length; k++,j++)
     {
       firsthalf[k] = word[j];
     }

     firsthalf[k] = '\0';

     strcat(firsthalf,secondhalf);
     strcpy(translated,firsthalf);
     strcat(translated,ay);
     translated[length+2] = '\0';

   }

if(Uppercase == 1)
translated[0] = toupper(translated[0]);
}


void translateStream(istream& input, ostream& out)
{
  char translated[25];
  char read[20];
  char ch;
  int i = 0;

  if (!input.get(ch))
    return;

  while (isalnum(ch))
  {
    read[i] = ch;
    input.get(ch);
    i++;
  }

  read[i] = '\0';
  translate(read, translated);
  out << translated;
  out << ch;           //whitespace
  translateStream(input, out);
}
