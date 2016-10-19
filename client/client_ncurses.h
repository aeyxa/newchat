#ifndef CLIENT_NCURSES_H
#define CLIENT_NCURSES_H

WINDOW *draw_top_border();
WINDOW *draw_top_window();

WINDOW *draw_bot_border();
WINDOW *draw_bot_window();

void top_border_configure(WINDOW *display_top_border);
void top_window_configure(WINDOW *display_top_window);

void bot_border_configure(WINDOW *display_bot_border);
void bot_window_configure(WINDOW *display_bot_window);

void redraw_window(WINDOW *display_top_window, char* buffer);
void redraw_writer(WINDOW *display_bot_window, char* buffer);

#endif
