/***********************************************************************
* Program:
*    Project 10, MAD LIB
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
*    Actual:     1.0 hrs
*      writing all the if / switch statements
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
void displayStory(char story[][MAX_WORD_LENGTH], int count);

/**********************************************************************
 * do while loop until user returns playAgain() = false
 * calls readFile , then displays story
 ***********************************************************************/
int main()
{
   //Setup variables
   char fileName[FILENAME_LENGTH];
   char story[MAX_LINES][MAX_WORD_LENGTH];
   int wordCount = 0;

   do
   {
      //call readFile and store wordCount
      wordCount = readFile(story, fileName);

      //display story out
      displayStory(story, wordCount);
      
   } while (playAgain());
   
   return 0;
}

/**********************************************************************
 * Read file into story array
 * returns wordcount
 ***********************************************************************/
int readFile(char story[][MAX_WORD_LENGTH], char fileName[])
{
   //get the filename and verify
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
   // loop through every word and update word count
   while (fin >> story[wordCount])
   {
      //check if special char
      if (story[wordCount][0] == '<' && isalpha(story[wordCount][1]))
      {
         askQuestions(story[wordCount], count);
         count++;
      }

      wordCount++;

   }

   fin.close();

   return wordCount;
}

/**********************************************************************
 * gets filename for story and stores in fileName pointer
 ***********************************************************************/
void getFileName(char fileName[])
{

   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   
   return;
}

/**********************************************************************
 * prompts user to play again
 * returns bool of true or false
 ***********************************************************************/
bool playAgain()
{
   char response;
   cout << "Do you want to play again (y/n)? ";
   cin >> response;

   if (response == 'y')
   {
      return true;
   }

   else if (response == 'n')
   {
      cout << "Thank you for playing.\n";
   }
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
      // convert '_' to space
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
   else if (count > 0)
      cin.getline(word,256);
   return;
}

/**********************************************************************
 * displays story in desired format
 * length is passed to control output
 ***********************************************************************/
void displayStory(char story[][MAX_WORD_LENGTH], int count)
{
   // these vars to check if letters are after quotes or newline
   bool isQuotation = false;
   bool newLine = true;
   cout << endl;

   // loop through every letter in story and apply spacing
   for (int i = 0; i < count; i++)
   {
      // if it is not an alpha it must be a special char
      if (story[i][0] == '<' && !isalpha(story[i][2]))
      {
         switch (story[i][1])
         {
            case '#':
               cout << endl;
               newLine = true;
               break;
            case '{':
               if (newLine)
               {
                  cout << "\"";
                  newLine = false;
               }
               else
               {
                  cout << " \"";
               }
               isQuotation = true;
               break;
            case '}':
               cout << "\"";
               break;
            case '[':
               if (newLine)
               {
                  cout << "\'";
                  newLine = false;
               }
               else
               {
                  cout << " \'";
               }
               isQuotation = true;
               break;
            case ']':
               cout << "\'";
               break;
         }
      }

      else
      {
         switch (story[i][0])
         {
            case '.':
               cout << story[i];
               break;
            case ',':
               cout << story[i];
               break;
            case '!':
               cout << story[i];
               break;
            case '?':
               cout << story[i];
               break;
            case ' ':
               break;
            default:
               if (newLine)
               {
                  cout << story[i];
                  newLine = false;
               }
               else if (isQuotation)
               {
                  cout << story[i];
                  isQuotation = false;
               }
               else
               {
                  cout << " " << story[i];
               }
               
         }
      }
            
   }

   cout << endl;
}
