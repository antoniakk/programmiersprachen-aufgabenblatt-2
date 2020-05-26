#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include "circle.hpp"
#include "mat2.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};
  Circle clock{300.0, {400.0, 400.0}, {1.0, 1.0, 1.0}};
  Vec2 seconds{0.0, 280.0};
  Vec2 mins{0.0, 250.0};
  Vec2 hrs{0.0, 200.0};
  Mat2 rotation = make_rotation_mat2(-M_PI/30);
  float tmp_sec = 0.0;
  unsigned int count_sec = 0, count_min = 0;

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    clock.draw(win, 6.0);  
    auto time = win.get_time();

    if(time - tmp_sec >= 1) {
      seconds = rotation*seconds;
      tmp_sec = time; 
      ++count_sec;
    }
    if(count_sec == 60) {
      mins = rotation*mins;
      count_sec = 0;
      ++count_min;
    }
    if (count_min == 60) {
      hrs = rotation*hrs;
      count_min = 0;
    }
    
    win.draw_line(clock.get_center().x, clock.get_center().y, clock.get_center().x + seconds.x, clock.get_center().y - seconds.y, 0.0, 0.0, 2.0);
    win.draw_line(clock.get_center().x, clock.get_center().y, clock.get_center().x + mins.x, clock.get_center().y - mins.y, 1.0, 0.0, 1.0, 3.0);
    win.draw_line(clock.get_center().x, clock.get_center().y, clock.get_center().x + hrs.x, clock.get_center().y - hrs.y, 0.6, 0.0, 0.5, 4.0);
    win.draw_text(375.0, 130.0, 50.0, "XII");
    win.draw_text(130.0, 375.0, 50.0, "IX");
    win.draw_text(375.0, 630.0, 50.0, "VI");
    win.draw_text(630.0, 375.0, 50.0, "III");

    
    win.update();
  }

 
  
  return 0;
}
