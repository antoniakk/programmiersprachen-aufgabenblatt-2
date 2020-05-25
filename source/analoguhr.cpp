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
  Vec2 seconds{0.0, 300.0};
  Vec2 mins{0.0, 300.0};
  Vec2 hrs{0.0, 300.0};
  Mat2 rotation = make_rotation_mat2(-2*M_PI/60);
  float tmp_sec = 0.0, tmp_mins = 0.0, tmp_hrs = 0.0;

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    clock.draw(win, 6.0);  
    auto time = win.get_time();

    if(time - tmp_sec >= 1) {
    seconds = (rotation*seconds);
    tmp_sec = time; 
    }
    if(time - tmp_mins >= 60) {
    mins = (rotation*mins); 
    tmp_mins = time;
    }
    if(time - tmp_hrs >= 3600) {
    hrs = (rotation*hrs); 
    tmp_hrs = time;
    }
    

    
    win.draw_line(clock.get_origin().x, clock.get_origin().y, clock.get_origin().x + seconds.x, clock.get_origin().x - seconds.y, 0.0, 0.0, 1.0);
    win.draw_line(clock.get_origin().x, clock.get_origin().y, clock.get_origin().x + mins.x, clock.get_origin().x - mins.y, 1.0, 0.0, 1.0);
    win.draw_line(clock.get_origin().x, clock.get_origin().y, clock.get_origin().x + hrs.x, clock.get_origin().x - hrs.y, 0.6, 0.0, 0.5);
    win.draw_text(400.0, 130.0, 50.0, "XII");
    win.draw_text(130.0, 400.0, 50.0, "IX");
    win.draw_text(400.0, 630.0, 50.0, "VI");
    win.draw_text(630.0, 400.0, 50.0, "III");

    
    win.update();
  }

 
  
  return 0;
}
