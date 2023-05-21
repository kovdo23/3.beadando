#ifndef BUTTON_H
#define BUTTON_H

#include "widgets.hpp"
#include "graphics.hpp"
#include <functional>

using std::string;

class Button : public Widget
{
protected:
    bool _pressed = false;
    string _text;
    std::function<void()> _f;
public:
    Button(Window * w,int x, int y, int sx, int sy, string text, std::function<void()> f);
    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
};

#endif // BUTTON_H
