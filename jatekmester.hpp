#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "button.hpp"
#include "window.hpp"
#include "textwidget.hpp"
#include "amoba.hpp"

class Jatekmester: public Window
{
protected:
    Button * btn;
    Textwidget * tb;
    Amoba * br;
    bool _player = false;
    std::vector<string> player_1;
    std::vector<string> player_2;
public:
    Jatekmester(int XX, int YY);
    void winning(std::vector<string>& mostani);
};

#endif // JATEKMESTER_HPP_INCLUDED
