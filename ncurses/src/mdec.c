/******************************************************************************/
#include<ncurses.h>
/******************************************************************************/
bool quit;
int max_y, max_x;
int new_y, new_x;
int line = 1;
int col = 1;

char * file[]; /* This is the array that will contain all the lines */
               /* ex: file[106] is line # 106 char array "This is line 106." */
/******************************************************************************/
void init(); // All the start up tasks will happen here
void close(); // Clean up tasks go here
void get_dimensions(); // Get the windows measurments

void draw_hello_world(int y, int x); // Test to draw text to the screen
void draw_options_bar(int y, int x);
WINDOW *get_text_area(char in, int y, int x);
/******************************************************************************/
WINDOW *text_area;

/******************************************************************************/


int main() /* Main */
{
  char got;

  init();

  while(!quit)
  {
    get_dimensions();

    if(max_y != new_y || max_x != new_x) /* If the screen changes reset the */
    {                                    /* max x & y. Then clear the screen. */
      new_y = max_y;
      new_x = max_x;

      clear();

      draw_options_bar(new_y, new_x); /* only drow or redraw this if the */
      refresh();                      /* terminal is resized */
    }

  //  draw_hello_world(new_y, new_x);
      text_area = get_text_area(got, new_y, new_x);


    got = getch(); // Does a window resize event trigger this?
    refresh();

    switch (got)
    {
      case 17: /* ^Q */
        quit = true;
        break;

      case 10: /* ENTER Key */
        line++;
        col = 1;
        break;

      case 127: /* BACKSPACE Key */
        if(col != 1)
        {
          col-= 1;
        }
        else if (line != 1)
        {
          line--;
        }
        break;

      default:
      //  mvwaddch(text_area, line, 1, got);
      //  wrefresh(text_area);
        mvprintw(1, 50, "ncurses char #: %i ", got);
        col++;
        break;
    }
  }


  close();
return 0;
}

//--

void init() /* Init */
{
  quit = false;
  initscr();
  start_color();
  raw();
  noecho();

  get_dimensions();
}

//--

void close() /* Close */
{
  endwin();
}

//--

void get_dimensions() /* Get the dimensions of the screen */
{
  getmaxyx(stdscr, max_y, max_x);
}

//--

void draw_hello_world(int y, int x) /* Draw "Hello World!" */
{
  mvprintw((y / 2) - 1, (x / 2) - 15, "Hello World!");
}

//--

void draw_options_bar(int y, int x) /* Draw the option bar on top of the screen */
{
  attron(A_REVERSE);
  mvwprintw(stdscr, 0, 0 , " File |");

  mvwprintw(stdscr,  0, x - 7 , "| Help \n");

  for(int i = 7; i < x - 7; i++)
  {
    mvwprintw(stdscr, 0, i, " ");
  }

  attroff(A_REVERSE);
}

WINDOW *get_text_area(char in, int y, int x)
{
  WINDOW *TA;

  TA = newwin(y - 6, x - 11, 5, 5);
  wborder(TA, 0, 0, 0, 0, '[', ']', 0, 0);

  if(in == NULL || in == 127)
  {
    in = ' ';
  }

  mvwaddch(TA, line, col, in);
  wrefresh(TA);
return TA;
}
/******************************************************************************/
