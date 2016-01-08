#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

int encode_character(char ch, char braille[]);
string encode_normal(char ch);
string encode_cap(char ch);
string encode_num(char ch);
void encode(const char* plaintext, char* braille);

/*another implementation*/
void encode_text(char sentence[], char braille[]);
char encode_recursive(char sentence[], char braille[], int length, int i, char acc[]);

void print_braille(const char* plaintext, ostream& out);


int main() {

  int size;
  char braille[512];

  braille[0] = '\0';

  cout << "====================== Question 1 ======================" << endl << endl;

  size = encode_character('t', braille);
  cout << "The character 't' encoded in braille is '" << braille << "' (" << size << " characters)" << endl;

  size = encode_character('Z', braille);
  cout << "The character 'Z' encoded in braille is '" << braille << "' (" << size << " characters)" << endl;

  size = encode_character('5', braille);
  cout << "The character '5' encoded in braille is '" << braille << "' (" << size << " characters)" << endl;

  size = encode_character('.', braille);
  cout << "The character '.' encoded in braille is '" << braille << "' (" << size << " characters)" << endl;

  cout << endl;

  braille[0]='\0';

  cout << "====================== Question 2 ======================" << endl << endl;

  encode_text("Hello!", braille);
  cout << "The string 'Hello!' encoded in braille is:" << endl << braille << endl << endl;

  encode("S-Club7?", braille);
  cout << "The string 'S-Club7?' encoded in braille is:" << endl << braille << endl;

  cout << endl;

  cout << "====================== Question 3 ======================" << endl << endl;

  print_braille("Hello!", cout);

  cout << endl;

  print_braille("S-Club7?", cout);

  cout << endl;

  return 0;
}


int encode_character(char ch, char braille[])
{
  string str;
  if(isupper((int)(ch)))
    str = encode_cap(ch);
  else if(isdigit((int)(ch)) && ch != '0')
    str = encode_num(ch);
  else if(isdigit((int)(ch)) && ch == '0')
    str = "..0000.0.00.";
  else
    str = encode_normal(ch);

  strcpy(braille, str.c_str());

  int size = strlen(braille);
  braille[size] = '\0';
  return size;
}

string encode_normal(char ch)
{
  string braille;
  if(ch == 'a')
    braille = "0.....";
  else if(ch == 'b')
    braille = "00....";
  else if(ch == 'c')
    braille = "0..0..";
  else if(ch == 'd')
    braille = "0..00.";
  else if(ch == 'e')
    braille = "0...0.";
  else if(ch == 'f')
    braille = "00.0..";
  else if(ch == 'g')
    braille = "00.00.";
  else if(ch == 'h')
    braille = "00..0.";
  else if(ch == 'i')
    braille = ".0.0..";
  else if(ch == 'j')
    braille = ".0.00.";
  else if(ch == 'k')
    braille = "0.0...";
  else if(ch == 'l')
    braille = "000...";
  else if(ch == 'm')
    braille = "0.00..";
  else if(ch == 'n')
    braille = "0.000.";
  else if(ch == 'o')
    braille = "0.0.0.";
  else if(ch == 'p')
    braille = "0000..";
  else if(ch == 'q')
    braille = "00000.";
  else if(ch == 'r')
    braille = "000.0.";
  else if(ch == 's')
    braille = ".000..";
  else if(ch == 't')
    braille = ".0000.";
  else if(ch == 'u')
    braille = "0.0..0";
  else if(ch == 'v')
    braille = "000..0";
  else if(ch == 'w')
    braille = ".0.000";
  else if(ch == 'x')
    braille = "0.00.0";
  else if(ch == 'y')
    braille = "0.0000";
  else if(ch == 'z')
    braille = "0.0.00";

  else if(ch == '.')
    braille = ".0..00";
  else if(ch == ',')
    braille = ".0....";
  else if(ch == ';')
    braille = ".00...";
  else if(ch == '-')
    braille = "..0..0";
  else if(ch == '!')
    braille = ".00.0.";
  else if(ch == '?')
    braille = ".00..0";
  else if(ch == '(' || ch == ')')
    braille = ".00.00";
  return braille;
}


string encode_cap(char ch)
{
  string str = ".....0";

  char lower_case = tolower(ch);
  string temp = encode_normal(lower_case);

  str.append(temp);

  return str;
}

string encode_num(char ch)
{
  string str = "..0000";

  int ascii = static_cast<int>(ch);
  char eq = static_cast<char>(ascii + 48);
  string temp = encode_normal(eq);

  str.append(temp);

  return str;
}


void encode(const char* plaintext, char braille[])
{
	if (! *plaintext)
     return;
	braille = braille + encode_character(*plaintext, braille);
	plaintext++;
	encode(plaintext, braille);
}

void encode_text(char sentence[], char braille[])
{
  int length = strlen(sentence);
  int i = 0;
  char accumulator[300];
  accumulator[0] = '\0';

  encode_recursive(sentence, braille, length, i, accumulator);
}

char encode_recursive(char sentence[], char braille[], int length, int i, char acc[])
{

  if(sentence[i] == ' ') i++;

  // Set braille when the end of the sentence is reached
  if (length == 0)
  {
    strcpy(braille, acc);                                       //dont need length if i use pointer! then just when hits end of line character
    return 0;
  }

  // Encode a new character into a temporary variable
  char accNew[100];
  encode_character(sentence[i],accNew);

  // Update the accumulator
  strcat(acc, accNew);

  // Pass in the updated accumulator
  encode_recursive(sentence, braille, length-1, ++i, acc);
}

void print_braille(const char* plaintext, ostream& out)
{
	char braille[512];
	char* pb = braille;
	encode(plaintext, pb);
	while (*pb != '\0')
	{
      out << pb[0];
      out << pb[3] << " ";
      pb+=6;
	}

	out << endl;
	pb = braille;

	while (*pb != '\0')
	{
      out << pb[1] << pb[4] << " ";
      pb +=6;
	}

	out << endl;
	pb = braille;

	while (*pb != '\0')
	{
      out << pb[2] << pb[5] << " ";
      pb += 6;
	}

	out << endl;

	for (unsigned int i=0; i<strlen(plaintext);i++)
	{
      if (isupper(plaintext[i])||isdigit(plaintext[i]))
      {
        out << "   ";
      }
		out << plaintext[i] << "  ";
	}

}
