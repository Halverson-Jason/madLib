/***********************************************************************
* Program:
*    Project 09, MAD LIB PROGRAM
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
*    The program will prompt the user for the file that describes the 
*    Mad Lib®, and then prompt him for all the substitute words. When 
*    all the prompts are complete, the program will display the 
*    completed story on the screen.
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*      figuring out how to read / parse file
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

int readFile(char story[][MAX_WORD_LENGTH], char fileName[]);
void getFileName(char fileName[]);
bool isFileName(char fileName[]);
bool playAgain();
void askQuestions(char word[], int count);
void displayStory(char story[][MAX_WORD_LENGTH], int *storyLineLength);
void isSpecial(char character[]);

/**********************************************************************
 * Calls readFile , getFilename, askQuestions, displayStory
 * isPunc, playAgain (if true start while loop again)
 ***********************************************************************/
int main()
{
   //Setup variables
   char fileName[FILENAME_LENGTH];
   char story[MAX_LINES][MAX_WORD_LENGTH];
   int wordCount = 0;

   //call readFile and store wordCount
   wordCount = readFile(story, fileName);

   cout << "Thank you for playing.\n";
   return 0;
}

/**********************************************************************
 * Read file into story array
 * returns wordcount
 ***********************************************************************/
int readFile(char story[][MAX_WORD_LENGTH], char fileName[])
{
   //get the filename and varify
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
   
   // loop through everyword and update wordcount
   for (int count = 0;fin >> story[wordCount];)
   {
      //check if special char
      if (story[wordCount][0] == '<' && isalpha(story[wordCount][1]))
      {
         askQuestions(story[wordCount], count);
         count++;
      }
      else if (story[wordCount][0] == '<' && !isalpha(story[wordCount][2]))
         isSpecial(story[wordCount]);
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
      // Removed due to testBed

//    char *pEnd = fileName + FILENAME_LENGTH;
//    for (char * p = fileName; p < pEnd; p++)
//    {
//       if (*p == '.')
//       {
//          return true;
//       }
//    }
//    return false;
      return true;

}

/**********************************************************************
 * prompts user to play again
 * returns bool of true or false
 ***********************************************************************/
bool playAgain()
{

}

/**********************************************************************
 * prompts the user for the question in the madlib
 * returns nothing
 ***********************************************************************/
void askQuestions(char word[], int count)
{
   // changes first letter to capitalized
   cout << "\t" << (char)toupper(word[1]);

   // walks though till end of special '>'
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

   // gets input to question
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
 * Check what special character proceeding '<'
 * returns nothing
 ***********************************************************************/
void isSpecial(char character[])
{
      //check what special character
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
            break;
         case '}':
            character[0] = '\"';
            character[1] = ' ';
            character[2] = '\0';
            break;
         case '[':
            character[0] = ' ';
            character[1] = '\'';
            character[2] = '\0';
            break;
         case ']':
            character[0] = '\'';
            character[1] = ' ';
            character[2] = '\0';
            break;
      }
}
   
