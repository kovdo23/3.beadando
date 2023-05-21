#ifndef TEXTWIDGET_HPP_INCLUDED
#define TEXTWIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using std::string;

class Textwidget: public Widget
{
protected:
    int _fontSize;
    string _text;
    bool _withBackground = false;
public:
    Textwidget(Window * w,int x, int y, int sx, int sy, int fontSize, string text);
    Textwidget(Window * w,int x, int y, int sx, int sy, int fontSize, string text, bool withBackground);
    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
    virtual string getContent();
    virtual void setContent(string text);
};

#endif // TEXTWIDGET_HPP_INCLUDED
