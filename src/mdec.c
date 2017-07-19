#include "stdio.h"
#include "stdbool.h"
#include "unistd.h"

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

void welcome()
{
  // Clear screen
  system("clear");
  printf("\n\t\tWelcome! \n\n\t"PROGRAM_NAME "\n\t" AUTHOR_NAME COPYRIGHT_LINE "\n\t\t" LICENSE "\n\n");
  // Wait
  sleep(3);
}

void init()
{
  // initialize data structures and pre populate model
  system("clear");
  printf("\tInitialization finished!\n");

}

void finish()
{
  ;
}

int main()
{
  welcome();
  init();

  bool quit = false;  
  char key = ' ';
  
  while(!quit)
  {
    // Update model
    
    // Listen for keypress events
    // Send events to interface function 
    key = getchar();
    if(key = 'q')
    {
      quit = true;
    }

    // Draw view

  }

  finish();


return 0;
}


