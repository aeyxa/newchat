#include "../common/common.h"

WINDOW *draw_top_window()
{
  int maxx, maxy, topy, topx;

  initscr(); refresh(); start_color();

  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);

  getmaxyx(stdscr,maxy,maxx);

  topy = maxy - 6; topx = maxx -4;

  return newwin(topy,topx,2,2);
}

WINDOW *draw_top_border()
{
  int maxx, maxy, topy, topx;

  initscr(); refresh();

  getmaxyx(stdscr, maxy, maxx);

  topy = maxy - 3;
  topx = maxx;

  return newwin(topy,topx,0,0);
}

WINDOW *draw_bot_window()
{
  int maxx, maxy, boty, botx;

  initscr(); refresh();

  getmaxyx(stdscr,maxy,maxx);

  boty = maxy - 2; botx = maxx - 2;

  return newwin(1,botx,boty,1);
}

WINDOW *draw_bot_border()
{
  int maxx, maxy, boty, botx;

  initscr(); refresh();

  getmaxyx(stdscr, maxy, maxx);

  boty = maxy - 3;
  botx = maxx;

  return newwin(0,botx,boty,0);
}

void top_border_configure(WINDOW *display_top_border)
{
  box(display_top_border,0,0);
  wrefresh(display_top_border);
}

void top_window_configure(WINDOW *display_top_window)
{
  bool check_for_scroll = TRUE;
  scrollok(display_top_window, check_for_scroll);
  curs_set(0); wrefresh(display_top_window);
}

void bot_border_configure(WINDOW *display_bot_border)
{
  box(display_bot_border,0,0);
  wrefresh(display_bot_border);
}

void bot_window_configure(WINDOW *display_bot_window)
{
  bool check_for_scroll = TRUE;
  scrollok(display_bot_window, check_for_scroll);
}

void redraw_window(WINDOW *display_top_window, char* buffer)
{
  std::string msg = buffer;

  if(msg.at(0) == '1')
  {
    wattron(display_top_window,COLOR_PAIR(1));

    msg.replace(0,1,"< ");

    wprintw(display_top_window,"%s\n",msg.c_str());
  }
  if(msg.at(0) == '2')
  {
    wattron(display_top_window,COLOR_PAIR(2));

    msg.replace(0,1,"> ");

    wprintw(display_top_window,"%s\n",msg.c_str());
  }

  wrefresh(display_top_window);
  curs_set(0);
}

void redraw_writer(WINDOW *display_bot_window, char* buffer)
{
  mvwaddstr(display_bot_window,0,0,"You: ");
  wrefresh(display_bot_window);
}
