#include "window.hpp"
#include <vector>
#include "jatekmester.hpp"

using namespace std;
using namespace genv;


int main()
{
    Jatekmester j(800,800);


    j.event_loop();
    return 0;
}
