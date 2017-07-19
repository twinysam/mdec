#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
/*
  MDEC
  (Pronounced ehm * dehk)
  This is a clone of the old MS-DOS editor "Edit".

---

ncurses may be a good option to get and use key press events as they come
rather than having to press enter each time. The problem is, as far as I know, there is no good way to port that to windows. Maybe a fully GUI version for windows? Try to find some good alternatives if possible.


*/

#define PROGRAM_NAME "MDEC - MS-DOS Edit Clone"
#define AUTHOR_NAME "David Cramer"
#define COPYRIGHT_SYM "\302\251"
#define COPYRIGHT_YEAR "2016-2017"
#define COPYRIGHT_LINE COPYRIGHT_SYM " " COPYRIGHT_YEAR
#define LICENSE "MIT License"

//---

void drawMenu();
char getSelection();
bool validate(char);
enum ACTION getAction(char);

//---

enum ACTION
{
  NEWFILE = 0,
  OPENFILE,
  NOACTION
  
};

//---

void welcome()
{
  // Clear screen
  system("clear");
  printf("\n\t\tWelcome! \n\n\t"PROGRAM_NAME "\n\t" AUTHOR_NAME " " COPYRIGHT_LINE "\n\t\t" LICENSE "\n\n");
  // Wait
  sleep(3);
}

//---

void init()
{
  // initialize data structures and pre populate model
  system("clear");
  printf("\tInitialization finished!\n");
  
  bool done = false;
  bool valid = false;
  char selection = ' ';
  enum ACTION doThis = NOACTION; 
 
  while(!done)
  {
    drawMenu();
    selection = getSelection();
    printf("%c\n", selection);
    valid = validate(selection);
    if(valid && selection != ' ')
    {
      getAction(selection);
      done = true;
    }
  } 

  printf("Left init.");
}

//---

void finish()
{
  ;
}

//---

int main(int args, char* argv[])
{
  welcome();
  init();

  bool quit = false;  
  char key = ' ';
  
  while(!quit)
  {
    printf("In main loop");
    printf("%i", quit);
   
    // Update model
    
    // Listen for keypress events
    // Send events to interface function 
    key = getchar();
    
    switch(key)
    {
    case 'q':
    case 'Q':
      quit = true;
      break;
    
    }

    // Draw view

  }

  finish();

return 0;
}

//---

void drawMenu()
{
//  printf

}

//---

char getSelection()
{
  char string[128];
  fgets(string, 128, stdin);
  
  char selected = string[0];

return selected;
}

//---

bool validate(char checkMe)
{
  bool valid = false;

  switch(checkMe)
  {
  case 0:
    // open new, blank file
    break;
  case 1:
    // prompt to open a specific file.
    break;
  case 3:
    // quit
    exit(0);
    break;
  }
  
return valid;
}

//---

enum ACTION getAction(char checked)
{

}

