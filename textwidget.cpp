#include "textwidget.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;


Textwidget::Textwidget(Window * w,int x, int y, int sx, int sy, int fontSize, string text)
    : Widget(w,x, y, sx, sy), _fontSize(fontSize),_text(text) {}


Textwidget::Textwidget(Window * w,int x, int y, int sx, int sy, int fontSize, string text, bool withBackground)
    : Widget(w,x, y, sx, sy), _fontSize(fontSize),_text(text), _withBackground(withBackground) {}


void Textwidget::rajzol() {
    if (_withBackground) gout << move_to(a, b) << color(100,155,160) << box(size_a, size_b);
    gout << move_to(a, b);
    gout.load_font("LiberationSans-Regular.ttf", _fontSize);
    gout << color(15,50,50);
    gout << text(_text);
}

void Textwidget::setContent(string text) {
    _text = text;
}

void Textwidget::handle(event ev)
{

}

string Textwidget::getContent() {
    return _text;
}
