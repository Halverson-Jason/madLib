/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
*    Create a calendar for any month of any year from 1753 forward. 
*    This is similar to the cal utility on the Linux system. Prompt 
*    the user for the numeric month and year to be displayed as shown 
*    in the example below. Your calculations to determine the first day 
*    of the month shall start with January 1, 1753 as a Monday. This 
*    will also include leap years.
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*      writing the display function , along with setting up the offset
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define FILENAME_LENGTH 32
#define MAX_LINES 32
#define MAX_WORD_LENGTH 32
#define MAX_CHAR_LENGTH 80

//write the code necessary read the Mad Lib from a file and prompt the user:

int readFile(char story[][MAX_WORD_LENGTH], char fileName[]);
void getFileName(char fileName[]);
bool isFileName(char fileName[]);
bool playAgain();
void askQuestions(char word[], int count);
void displayStory(char story[][MAX_WORD_LENGTH], int *storyLineLength);
bool isPunc(char character[]);

/**********************************************************************
 * Calls readFile , getFilename, askQuestions, displayStory
 * isPunc, playAgain (if true start while loop again)
 ***********************************************************************/
int main()
{
   char fileName[FILENAME_LENGTH];
   char story[MAX_LINES][MAX_WORD_LENGTH];
   int wordCount = 0;
   
   
   wordCount = readFile(story, fileName);


   return 0;
}

/**********************************************************************
 * Read file into story array
 * returns nothing as it uses pointers
 ***********************************************************************/
int readFile(char story[][MAX_WORD_LENGTH], char fileName[])
{
   getFileName(fileName);
   // open the file for reading changed string to c_string
   ifstream fin(fileName);

   // error check  
   if (fin.fail())
   {
      // inform user of the error
      cout << "Unable to open file "
         << fileName
         << endl;
      return false;
   }
   // read data from file and update word count

   int wordCount = 0;
   int count = 0;
   //TODO: change this to for loop
   while (fin >> story[wordCount])
   {
      if (story[wordCount][0] == '<' && isalpha(story[wordCount][1]))
      {
         askQuestions(story[wordCount], count);
         count++;
      }
      else if (story[wordCount][0] == '<' && !isalpha(story[wordCount][2]))
         isPunc(story[wordCount]);
      wordCount++;

   }

   fin.close();

   return wordCount;
}

/**********************************************************************
 * gets filename for story as stores in fileName pointer
 * verifies is a file with isFileName
 ***********************************************************************/
void getFileName(char fileName[])
{
   do
   {
      cout << "Please enter the filename of the Mad Lib: ";
      cin >> fileName;
   } while (!isFileName(fileName));
   
   return;
}

/**********************************************************************
 * varifies a file name has a "."
 ***********************************************************************/
bool isFileName(char fileName[])
{
   char *pEnd = fileName + FILENAME_LENGTH;
   for (char * p = fileName; p < pEnd; p++)
   {
      if (*p == '.')
      {
         return true;
      }
   }
   return false;

}

/**********************************************************************
 * prompts user to play again
 * returns bool of true or false
 ***********************************************************************/
bool playAgain()
{

}

/**********************************************************************
 * 
 ***********************************************************************/
void askQuestions(char word[], int count)
{
   cout << "\t" << (char)toupper(word[1]);

   for (int i = 2; word[i] != '>'; i++)
   {
      if (word[i] == '_')
         cout << " ";
      else
      {
         cout << (char)tolower(word[i]);
      }
   }

   cout << ": ";                                    

   if (count == 0)
   {
      cin.ignore();
      cin.getline(word,256);
   }
   else if(count > 0)
      cin.getline(word,256);
   
   return;
}

/**********************************************************************
 * displays story in desired format
 * length is passed to control output
 ***********************************************************************/
void displayStory(char story[][MAX_WORD_LENGTH], int length)
{

}

/**********************************************************************
 * Sentence-case the text, meaning capitalize the first letter and 
 * convert the rest to lowercase.
 ***********************************************************************/
bool isPunc(char character[])
{
switch (character[1])
{
         case '#':
            character[0] = '\n';
            character[1] = '\0';
            break;
         case '{':
            character[0] = ' ';
            character[1] = '\"';
            character[2] = '\0';
         case '}':
            character[0] = '\"';
            character[1] = ' ';
            character[2] = '\0';
         case '[':
            character[0] = ' ';
            character[1] = '\'';
            character[2] = '\0';
         case ']':
            character[0] = '\'';
            character[1] = ' ';
            character[2] = '\0';
      }
}
   
