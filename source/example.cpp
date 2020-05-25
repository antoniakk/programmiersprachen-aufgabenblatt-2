#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include "circle.hpp"
#include "rectangle.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};
  Rectangle rec1{{122,244}, {366,422}, {0.7, 0.3, 0.8}};
  Rectangle rec2{{10,115}, {60,300}, {0.2, 0.4, 0.6}};
  Rectangle rec3{{100,200}, {300,400}, {0.2, 0.3, 0.0}};
  Rectangle rec4{{166,30}, {366,40}, {0.3, 0.0, 0.8}};
  Rectangle rec5{{400,200}, {700,389}, {0.4, 0.2, 0.1}};
  Rectangle rec6{{179,600}, {309,699}, {0.634, 0.124, 0.328}};
  Circle c1{40, {299, 299}, {0.7, 0.5, 0.1}};
  Circle c2{70, {100, 100}, {0.244, 0.535, 0.025}};
  Circle c3{100, {400, 400}, {0.0, 0.99, 0.135}};
  Circle c4{150, {305, 100}, {0.732, 0.63, 0.0034}};
  Circle c5{333, {207, 399}, {0.07, 0.666, 0.333}};
  Circle c6{399, {499, 599}, {0.442, 0.236, 0.0}};
  std::vector<Circle> circles;
  circles.push_back(c1);
  circles.push_back(c2);
  circles.push_back(c3);
  circles.push_back(c4);
  circles.push_back(c5);
  circles.push_back(c6);
  std::vector<Rectangle> rectangles;
  rectangles.push_back(rec1);
  rectangles.push_back(rec2);
  rectangles.push_back(rec3);
  rectangles.push_back(rec4);
  rectangles.push_back(rec5);
  rectangles.push_back(rec6);

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);
    
    
  
    // If the mouse position is inside the a shape, make its outline thicker
    Vec2 mouse_posit{mouse_position.first, mouse_position.second};

    for (unsigned int i = 0; i < circles.size(); ++i) {
      if(circles[i].is_inside(mouse_posit)) {
        circles[i].draw(win, 2.0);
      }
      else {
        circles[i].draw(win);
      }
    }


    for (unsigned int i = 0; i < rectangles.size(); ++i) {
      if(rectangles[i].is_inside(mouse_posit)) {
        rectangles[i].draw(win, 2.0);
      }
      else {
        rectangles[i].draw(win);
      }
    }
    
    win.update();
  }

 
  
  return 0;
}
