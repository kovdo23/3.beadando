#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

using std::string;

class Window;

class Widget {
protected:
    Window* _w;
    int a, b, size_a, size_b, _size;
    bool _focused;
    int _border = 2;
public:
    Widget(Window * w,int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void rajzol() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual bool isSameWidget(int x, int y, int sx, int sy);
    virtual Widget * getWidget(int x, int y, int sx, int sy);
    virtual string getContent();
};

#endif // WIDGETS_HPP_INCLUDED
