#include "button.hpp"

using namespace genv;
using namespace std;

const int shadow = 3;

Button::Button(Window * w,int x, int y, int sx, int sy, string text, std::function<void()> f) : Widget(w,x,y,sx,sy), _text(text), _f(f)
{
}

void Button::rajzol() {
    gout.load_font("LiberationSans-Regular.ttf", 30);
    gout << move_to(a+shadow, b+shadow) << color(15,50,50) << box(size_a, size_b);
    gout << move_to(a+shadow*_pressed, b+shadow*_pressed) << color(15,50,90) << box(size_a, size_b);

    gout << move_to(a+2+shadow*_pressed, b+2+shadow*_pressed) << color(55,130,190) << box(size_a-4, size_b-4);
    gout << move_to(((a+size_a/2)-gout.twidth(_text)/2), b+size_b/2-gout.cascent()+gout.cdescent()+2) << color(15,50,50) << text(_text);


}


void Button::handle(event ev)
{
    if (ev.button == btn_left) {
        _pressed = true;
    }
    else if (_pressed && ev.button == -btn_left) {
        _f();
        _pressed = false;
    }
    _focused = true;
}
