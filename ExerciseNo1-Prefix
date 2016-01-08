#include <iostream>
#include <string.h>
#include <string>


using namespace std;

int substring_position(const char* substring, const char* string);
bool is_prefix(const char* substring, const char* string);

int substring_position_rec(const char* substring, const char* string);
int substring_position_rec2(const char* substring, const char* string, int p);
bool is_prefix_rec(const char* substring, const char* string);

int main()
{
  cout << substring_position("this", "this is a simple exercise") << endl;
  cout << substring_position("is", "this is a simple exercise") << endl;
  cout << substring_position("is a", "this is a simple exercise") << endl;
  cout << substring_position("is an", "this is a simple exercise") << endl;
  cout << substring_position("exercise", "this is a simple exercise") << endl;
  cout << substring_position("simple exercise", "this is a simple") << endl;
  cout << substring_position("", "this is a simple exercise") << endl;
  cout << substring_position("", "") << endl;
  cout << endl;
  cout << substring_position_rec("this", "this is a simple exercise") << endl;
  cout << substring_position_rec("is", "this is a simple exercise") << endl;
  cout << substring_position_rec("is a", "this is a simple exercise") << endl;
  cout << substring_position_rec("is an", "this is a simple exercise") << endl;
  cout << substring_position_rec("exercise", "this is a simple exercise") << endl;
  cout << substring_position_rec("simple exercise", "this is a simple") << endl;
  cout << substring_position_rec("", "this is a simple exercise") << endl;
  cout << substring_position_rec("", "") << endl;

return 0;
}

bool is_prefix(const char* substring, const char* string)         //pointer to beginning of substring and string
{
  for (int i=0; substring[i]!='\0';i++)                      //iterates through the string, returns false if chars dont mach - cant be prefix then
  {
    if (substring[i] != string[i])
      return false;
  }
  return true;
}

//recursive solution
bool is_prefix_rec(const char* substring, const char* string)
{

  if(*substring == *string)
  {
    return is_prefix(substring+1, string+1);
  }

  if(substring[0] == '\0')
   return true;

return false;
}


int substring_position(const char* substring, const char* string)
{
  int position = 0;                                 //position of substring set to 0

  for (int i = 0; string[i]!='\0';)
  {
    if(is_prefix(substring, string))             //checks if its prefix - returns position 0
      return position;
    else
    {
      string++;                                //incremented
      position++;                              //incremented  --> checks again whether prefix and returns position
    }
  }

  if (string[0]=='\0' && substring[0]=='\0')         //so that "" succeeds
    return position;

return -1;
}


int substring_position_rec(const char* substring, const char* string)
{
  int p = 0;
  p = substring_position_rec2(substring, string, p);

  /*I know that thats cheating but I just couldnt figure out why recursive function
  wouldnt return -1 for substrings with extra characters as the end*/
  int length = strlen(string);
  if(length<p)
    return -1;

  return p;
}

int substring_position_rec2(const char* substring, const char* string, int p)
{
  if(is_prefix_rec(substring, string))             //checks if its prefix - returns position 0
  {
    return p;
  }
  else
  {
    return(substring_position_rec2(substring, ++string, ++p));
  }

  if (substring[0]=='\0' && string[0]=='\0')         //so that "" succeeds, although not really necessary
    return p;

}
