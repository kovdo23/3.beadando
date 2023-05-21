#ifndef MEZOK_HPP
#define MEZOK_HPP

#include "textwidget.hpp"
#include "functional"

class Mezok : public Textwidget
{
protected:
    std::function<string(int x, int y, int sx, int sy, int borderSize)> _f;
    string _nextChar = "";
public:
    Mezok(Window * w,int x, int y, int sx, int sy, int fontSize, string content, std::function<string(int x, int y, int sx, int sy, int borderSize)> f);
    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
};

#endif // MEZOK_HPP
