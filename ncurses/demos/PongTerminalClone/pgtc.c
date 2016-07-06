// Pong Terminal Clone

#include<ncurses.h>
#include<unistd.h>

#define DELAY  30000



void draw_borders(WINDOW *screen) 
{ 
  int x, y, i; 
  getmaxyx(screen, y, x); 

  // 4 corners 
  mvwprintw(screen, 0, 0, "+"); 
  mvwprintw(screen, y - 1, 0, "+"); 
  mvwprintw(screen, 0, x - 1, "+"); 
  mvwprintw(screen, y - 1, x - 1, "+"); 

  // sides 
  for (i = 1; i < (y - 1); i++) 
  { 
    mvwprintw(screen, i, 0, "|");
    mvwprintw(screen, i, x - 1, "|");
  } 

  // top and bottom 
  for (i = 1; i < (x - 1); i++) 
  { 
    mvwprintw(screen, 0, i, "-"); 
    mvwprintw(screen, y - 1, i, "-");
  }
 
}

int
main(int argc, char* argv[])
{
  int parent_x, parent_y, new_x, new_y;
  int score_size = 10;

  initscr();
  noecho();
  curs_set(FALSE);

  getmaxyx(stdscr, parent_y, parent_x);

  WINDOW *field = newwin(parent_y - score_size, parent_x, 0, 0);
  WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);


  draw_borders(field);
  draw_borders(score);


  while(1)
  {
    getmaxyx(stdscr, new_y, new_x);
    
    if(new_y != parent_y || new_x != parent_x)
    {
      parent_x = new_x;
      parent_y = new_y;
      
      wresize(field, new_y - score_size, new_x);
      wresize(score, score_size, new_x);
      
      mvwin(score, new_y - score_size, 0);

      wclear(stdscr);
      wclear(field);
      wclear(score);

      draw_borders(field);
      draw_borders(score);
    }
    
    mvwprintw(field, 1, 1, "Field");
    mvwprintw(score, 1, 1, "Score");
   
    wrefresh(field);
    wrefresh(score);  
  }


  delwin(field);
  delwin(score);  

  endwin();
return 0;
}

