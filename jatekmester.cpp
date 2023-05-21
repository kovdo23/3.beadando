#include "jatekmester.hpp"

using namespace std;
using namespace genv;

Jatekmester::Jatekmester(int XX, int YY) : Window(XX,YY) {

    player_1.push_back("O");

    player_2.push_back("X");

    const int minSize = 15;


    btn = new Button(this,_XX/2-gout.twidth("Jatek inditasa")/2, _YY/2, gout.twidth("Jatek inditasa"), 60,"Jatek inditasa",[this](){

        br = new Amoba(this,75, 75, 650, 650,15,15, player_1, player_2, [this](int x, int y, int sx, int sy, int borderSize) {
            _player = !_player;
            vector<string> & mostani = _player ? player_1 : player_2;
            int match = 0;
            int l = 1;


            vector<Widget *>pWidgets = widgets;
            for (int i = 0; i < 4 && match != 4; ++i) {
                if (i < 2) match = 0;
                l *= -1;
                int px = x;
                int py = y;
                for (int s = 0; s < 4; ++s) {
                    if (i < 2) px += l*((sx)+(2*borderSize));
                    else py += l*((sy)+(2*borderSize));
                    int i = 0;
                    bool found = false;
                    while (!found && i < pWidgets.size()-1) {
                        if (pWidgets[i]->isSameWidget(px,py,sx,sy))
                            if (pWidgets[i]->getContent() == mostani[0]) {
                                match++;
                                found = true;
                            }
                        i++;

                    }
                }
                if (match == 4) {
                    winning(mostani);
                }
            }
            match = 0;
            for (int diagonals = 0; diagonals < 4 && match != 4; ++diagonals) {
                int lx = 1;
                int ly = 1;
                if (diagonals == 1 || diagonals == 2)
                    lx *= -1;
                if (diagonals == 1 || diagonals == 3)
                    ly *= -1;
                if (lx != ly && diagonals == 2)
                    match = 0;
                int px = x;
                int py = y;
                for (int r = 0; r < 4; ++r) {
                    px += lx*((sx)+(2*borderSize));
                    py += ly*((sy)+(2*borderSize));
                    int i = 0;
                    bool found = false;
                    while (!found && i < pWidgets.size()-1) {
                        if (pWidgets[i]->isSameWidget(px,py,sx,sy))
                            if (pWidgets[i]->getContent() == mostani[0]) {
                                match++;
                                found = true;
                            }
                        i++;

                    }
                }
                if (match == 4) {
                    winning(mostani);
                }
            }
            return mostani[0];
        });
    });
}

void Jatekmester::winning(vector<string>& mostani) {
    for (int i = 0; i < widgets.size(); i++) {
        if (widgets[i] == br) {
            widgets.erase(widgets.begin()+i, widgets.end());
        }
    }
    tb = new Textwidget(this,_XX/2-gout.twidth("Nyertes: "+ mostani[0])/2, _YY/3, gout.twidth("Nyertes: "+ mostani[0]), 40, 40, "Nyertes: "+ mostani[0], true);
}
