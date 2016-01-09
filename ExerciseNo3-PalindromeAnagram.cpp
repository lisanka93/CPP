#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


void reverse(char one[], char two[]);
char convert(char phrase[], char conv[]);
bool compare(char one[], char two[]);
bool compare2(char one[], char two[], int length);
bool palindrome(char sentence[]);
bool anagram(char sentence[], char sentence2[]);
void sort(char word[]);


int main() {

  /*** QUESTION 1 ***/
  char reversed[20];
  reverse("lairepmi", reversed);
  cout << "'lairepmi' reversed is '" << reversed << "'" << endl;
  reverse("desserts", reversed);
  cout << "'desserts' reversed is '" << reversed << "'" << endl << endl;

  /*** QUESTION 2 ***/
  cout << "The strings 'this, and THAT......' and 'THIS and THAT!!!' are ";
  if (!compare("this, and THAT......", "THIS and THAT!!!"))
    cout << "NOT ";
  cout << "the same" << endl << "  (ignoring punctuation and case)" << endl;

  cout << "The strings 'this, and THAT' and 'THIS, but not that' are ";
  if (!compare("this, and THAT", "THIS, but not that"))
    cout << "NOT ";
  cout << "the same" << endl << "  (ignoring punctuation and case)" << endl << endl;

  /*** QUESTION 3 ***/

  cout << "The string 'rotor' is ";
  if (!palindrome("rotor"))
    cout << "NOT ";
  cout << "a palindrome." << endl;

  cout << "The string 'Madam I'm adam' is ";
  if (!palindrome("Madam I'm adam"))
    cout << "NOT ";
  cout << "a palindrome." << endl;
  cout << "The string 'Madam I'm not adam' is ";
  if (!palindrome("Madam I'm not adam"))
    cout << "NOT ";
  cout << "a palindrome." << endl << endl;

  /*** QUESTION 4 ***/

  cout << "The string 'I am a weakish speller!' is ";
  if (!anagram("I am a weakish speller!", "William Shakespeare"))
    cout << "NOT ";
  cout << "an anagram of 'William Shakespeare'" << endl;

  cout << "The string 'I am a good speller!' is ";
  if (!anagram("I am a good speller!", "William Shakespeare"))
    cout << "NOT ";
  cout << "an anagram of 'William Shakespeare'" << endl;

  return 0;
}


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

char convert(char phrase[], char conv[])
{
  int i, j, k, l;

 //make everything lower case
 for(k = 0, l = 0; k <= strlen(phrase); k++)
 {
    //before that I used (isalpha(phrase[k]) which only IGNORES the characters not erasing them leaving space at the end of the string
  if((phrase[k] != ' ') && (ispunct(phrase[k]) == false))
  {
    conv[l] = tolower(phrase[k]);
    l++;
  }
 }

}

bool compare(char one[], char two[])
{
  char converted[100];
  char converted2[100];
  convert(one, converted);
  convert(two, converted2);

  int length1 = strlen(converted);
  int length2 = strlen(converted2);

  if (length1 != length2)
   return false;

  compare2(converted, converted2, length1);          //need helper function with length to set base case
}

bool compare2(char one[], char two[], int length)
{
  char* ptr = one;
  char* ptr2 = two;

  if(length == 1 && *ptr == *ptr2)
   return true;

  if(*ptr == *ptr2)
  {
   return compare2(++ptr, ++ptr2, length-1);
  }

return false;
}

bool palindrome(char sentence[])
{
  char converted[100];
  char reversed[100];

  convert(sentence, converted);              //convert the sentence into all lower case and remove punctuation
  reverse(converted, reversed);              //reverse the sentence and store it in reversed

  if(compare(converted, reversed))          //compare them, logically if they are the same its a palindrome
  {
    return true;
  }

 return false;
}

void sort(char word[])                     //need sort to check that its an anagram - sort all the letters and compare
{
  char temp;
  int n, i, j;
  n = strlen(word);

  for (i=0; i<n-1; i++)
  {
   for (j=i+1; j<n; j++)
   {
    if (word[i] > word[j])
    {
     temp = word[i];
     word[i] = word[j];
     word[j] = temp;
    }
   }
  }

}


bool anagram (char sentence[], char sentence2[])
{
  char converted[100];
  char converted2[100];

  convert(sentence, converted);
  convert(sentence2, converted2);
  sort(converted);
  sort(converted2);

  if(compare(converted, converted2))
  {
    return true;
  }

 return false;
}
