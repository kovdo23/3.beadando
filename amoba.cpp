#include "amoba.hpp"
#include "mezok.hpp"

using namespace genv;
using namespace std;

Amoba::Amoba(Window * w,int x, int y, int sx, int sy, int sor, int oszlop,
             std::vector<string> player_1, std::vector<string> player_2,std::function<string(int x, int y, int sx, int sy, int borderSize)> f)
    : Widget(w,x,y,sx,sy), _sor(sor), _oszlop(oszlop), _f(f), _player_1(player_1), _player_2(player_2), _nev(_player_1[0])
{

    int border = 0;
    int meret = (size_a/_sor);
    while (border < 2 && (((meret-border)*sor + border*((_sor+1))) <= size_a)) {
        if ((((meret-border)*_sor + border*(_sor+1)) > size_a))
        {
            meret--;
        }
        else border++;
    }
    _border = border+2;
    for (int r = 0; r < _sor; ++r) {
        int jelensor = a+(meret*r);
        for (int c = 0; c < _oszlop; ++c) {

            int plusSizeX = border+2;
            int plusSizeY = border+2;


            int jelenoszlop = b+(meret*c);
            new Mezok(_w,jelensor+border+3, jelenoszlop+border+3,meret-plusSizeX+0, meret-plusSizeY+0,size_b/_oszlop,"",_f);
        }

    }
}

void Amoba::rajzol(){
    gout << move_to(0,0) << color(100,155,160) << box(_w->getWindowX(),_w->getWindowY());
    gout << move_to(a,b) << color(55,130,190) << box(size_a, size_b);
}

void Amoba::handle(genv::event ev){}

void Amoba::setPlayerName(string name) {
    _nev = name;
}
