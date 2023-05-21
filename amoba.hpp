#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED

#include "window.hpp"
#include "widgets.hpp"
#include <functional>

class Amoba : public Widget
{
protected:
    int _sor, _oszlop;
    std::function<string(int x, int y, int sx, int sy, int borderSize)> _f;
    std::vector<string> _player_1;
    std::vector<string> _player_2;
    std::string _nev = "";
public:
    Amoba(Window * w,int x, int y, int sx, int sy, int sor, int oszlop,
          std::vector<string> player_1,std::vector<string> player_2,std::function<string(int x, int y, int sx, int sy, int borderSize)> f);
    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
    void setPlayerName(std::string name);
};



#endif // AMOBA_HPP_INCLUDED
