
//ugly I know
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int encode_character(char ch, char *multitap);
void encode(const char* plaintext, char* multitap);
void encode2(const char* str, char* multitap);

int main() {

  int size;
  char multitap[512];

  multitap[0] = '\0';

  cout << "====================== Question 1 ======================" << endl << endl;

  size = encode_character('a', multitap);
  cout << "The character 'a' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character('A', multitap);
  cout << "The character 'A' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character('c', multitap);
  cout << "The character 'c' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character('C', multitap);
  cout << "The character 'C' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character(',', multitap);
  cout << "The character ',' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character('e', multitap);
  cout << "The character 'e' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character('6', multitap);
  cout << "The character '6' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character('Z', multitap);
  cout << "The character 'Z' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character(' ', multitap);
  cout << "The character ' ' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;

  size = encode_character('Y', multitap);
  cout << "The character 'Y' encoded in multitap is '" << multitap << "' (" << size << " keystrokes)" << endl;
  cout << endl;
  multitap[0] = '\0';

  cout << "====================== Question 2 ======================" << endl << endl;

  encode("Meet", multitap);
  cout << "Meet '" << multitap << "'" << endl;

  encode("Anna", multitap);
  cout << "Anna '" << multitap << "'" << endl;

  encode("at", multitap);
  cout << "at '" << multitap << "'" << endl;

  encode("5pm", multitap);
  cout << "5pm '" << multitap << "'" << endl;

  encode2("Meet Anna at 5pm", multitap);
  cout << "whole string " << multitap << endl;

  cout << endl;
  return 0;
}


int encode_character(char ch, char *multitap)
{
 int flag = 0;
 int keystrokes = 1;

 if(isupper((int)(ch)))
 {
   flag = 1;
   ch = tolower(ch);
   keystrokes++;
 }

 if(isdigit((int)(ch)))
 {  flag  = 2;
    keystrokes++;
 }

 if(ch == 'a' || ch == 'b' || ch == 'c')
   multitap[0] = '2';
 else if (ch == 'd' || ch == 'e' || ch == 'f')
   multitap[0] = '3';
 else if (ch == 'g' || ch == 'h' || ch == 'i')
   multitap[0] = '4';
 else if (ch == 'j' || ch == 'k' || ch == 'l')
   multitap[0] = '5';
 else if (ch == 'm' || ch == 'n' || ch == 'o')
   multitap[0] = '6';
 else if (ch == 'p' || ch == 'q' || ch == 'r' || ch == 's')
   multitap[0] = '7';
 else if (ch == 't' || ch == 'u' || ch == 'v')
   multitap[0] = '8';
 else if (ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z')
   multitap[0] = '9';
 else if (ch == '.' || ch == ',' || ch == '?' || ch == '!')
   multitap[0] = '1';
 else if (ch == '1')
   multitap[0] = '1';
 else if (ch == '2')
   multitap[0] = '2';
 else if (ch == '3')
   multitap[0] = '3';
 else if (ch == '4')
   multitap[0] = '4';
 else if (ch == '5')
   multitap[0] = '5';
 else if (ch == '6')
   multitap[0] = '6';
 else if (ch == '7')
   multitap[0] = '7';
 else if (ch == '8')
   multitap[0] = '8';
 else if (ch == '9')
   multitap[0] = '9';
 else if (ch == '0')
   multitap[0] = '0';
 else if (isspace(ch))
   multitap[0] = '0';

 if(ch == 'b' || ch == 'e' || ch == 'h' || ch == 'k' || ch == 'n' ||
    ch == 'q' || ch == 'u' || ch == 'x' || ch == ',')
 {
  multitap[1] = multitap[0];  //2 times the same number
  keystrokes = keystrokes+1;
 }

 if(ch == 'c' || ch == 'f' || ch == 'i' || ch == 'l' || ch == 'o' ||
    ch == 'r' || ch == 'v' || ch == 'y' || ch == '!')
 {
   multitap[1] = multitap[0];
   multitap[2] = multitap[0];  // 3 times the same number
   keystrokes = keystrokes+2;
 }

 if(ch == 'z' || ch == '?')
 {
   multitap[1] = multitap[0];
   multitap[2] = multitap[0];
   multitap[3] = multitap[0];  // 4 times the same number
   keystrokes = keystrokes+3;
 }


 if(flag == 1)
 {
   multitap[keystrokes-1] = multitap[0];
   multitap[0] = '#';
   multitap[keystrokes] = '\0';

 }

 if(flag == 2)
 {
   multitap[keystrokes-1] = multitap[0];
   multitap[0] = '*';
   multitap[keystrokes] = '\0';
 }

 if(flag == 0)
   multitap[keystrokes] = '\0';

 return keystrokes;

}

/*recursive but doesnt add the fucking |*/
void encode(const char* plaintext, char *multitap)
{
  if(!*plaintext)
    return;

  multitap = multitap + encode_character(*plaintext, multitap);
  plaintext++;
  encode(plaintext,multitap);

}


/*non recursive but adds the | yeay!*/
void encode2(const char* str, char* multitap){

  char encoded[100];
  string result = "";  //need a string because we cant "dynamically" allocate length

  for (int i = 0; str[i]!='\0'; i++)
  {
    encode_character(str[i], encoded);
    string str_encoded(encoded);   //char array to string

    int res_len = result.length();
    if (result[res_len -1] == str_encoded[0])
    {
      result += '|';
    }

    result += str_encoded;

  }

  strcpy(multitap, result.c_str());  //string to char array

}
