/*
  This is a C file for testing funtionality & features
*/

#include<ncurses.h>


#define line_num 25
#define col_len 100

int line = 1, col = 1;
bool quit = false;

void initialize_file();
void handle_ch(char ch);
void addchtofile(char in);
void delchfromfile();
void printfilebuffer();

char file[line_num][col_len];


int main()
{
  initscr();
  noecho();
  raw();
  // initialize_file(); // This is no longer necessary with the addition to the print function.


  while(!quit)
  {
    handle_ch(getch());
    printfilebuffer();

    refresh();
  }


  endwin();
return 0;
}

void initialize_file()
{
  file[1][1] = ' ';
}

void handle_ch(char ch)
{
  switch(ch)
  {
  case 17: /* ^Q */
    quit = true;
    break;

  case 10: /* ENTER Key */
    if(line < line_num - 1)
    {
      line++;
      col = 1;
    }
    break;

  case 127: /* BACKSPACE Key */
  // Add a function: rmchfromfile(void)
  //  handle removing from the array.
  if(!(col - 1) <= 1)
  {
    delchfromfile();
  }
/*
    col--;
    delch();
    refresh();
*/
    break;

  default:
    addchtofile(ch);
    break;
  }
}

void addchtofile(char in)
{
  if(col + 1 > col_len)
  {
    col = 1;
    line++;
  }

  if(line + 1 > line_num)
  {
    line = 1;
    col = 1;
  }

  file[line][col] = in;
  col++;
}

void delchfromfile()
{
  if(col != 1)
  {
    mvdelch(line, col - 1);
    col--;
  }
  else if (line != 1)
  {
    line--;
  }
}

void printfilebuffer()
{
  attron(A_REVERSE);
  mvwprintw(stdscr, LINES - 1, COLS - 11, "L: %i, C: %i", line, col);
  attroff(A_REVERSE);
  move(line + (LINES / 2), (col - 1) + (COLS / 4));


  if(file[line][col] != NULL || file[line][col - 1] != NULL)
  {
    if(col == 1)
    {
      move(line + (LINES / 2), (col - 1) + (COLS / 4));
      // This prints the char
    }
    else if(col > 1)
    {
      mvwaddch(stdscr, line + (LINES  / 2), col + (COLS / 2) - 50, file[line][col - 1]);
    }
    else
    {
      move(line + (LINES / 2), col + (COLS / 4));
      // This moves the cursor one char over if the char to be printed is NULL
    }
  }
}
