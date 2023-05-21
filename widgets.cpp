#include "widgets.hpp"
#include "window.hpp"

using namespace genv;
using namespace std;

Widget::Widget(Window * w,int x, int y, int sx, int sy) : _w(w), a(x), b(y), size_a(sx), size_b(sy)
{
    _w->registerWidget(this);
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    _focused = false;
    return mouse_x>a && mouse_x<a+size_a && mouse_y>b && mouse_y<b+size_b;
}

bool Widget::isSameWidget(int x, int y, int sx, int sy) {
    return x == a && y == b && sx == size_a && sy == size_b;
}

Widget * Widget::getWidget(int x, int y, int sx, int sy) {
    if (isSameWidget(x,y,sx,sy))
        return this;
}

string Widget::getContent() {
    return "";
}
