#include "mezok.hpp"

using namespace std;
using namespace genv;

Mezok::Mezok(Window * w,int x, int y, int sx, int sy, int fontSize, string text, std::function<string(int x, int y, int sx, int sy, int borderSize)> f)
    : Textwidget(w,x, y, sx, sy, fontSize, text), _f(f)
{

}

void Mezok::rajzol(){
    gout << move_to(a,b) << color(15,50,90) << box(size_a,size_b);
    gout << move_to(a+((size_a-gout.twidth(_text))/2),b-gout.cdescent()/2);
    gout.load_font("LiberationSans-Regular.ttf", _fontSize);
    gout << color(195,235,240);
    gout << text(_text);
}

void Mezok::handle(genv::event ev){
    if (ev.button == btn_left) {
        _text = _f(a,b, size_a,size_b,_border);
    }
}
