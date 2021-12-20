#include "OGLE.h"
#define LOG(message) std::cout << (message) << '\n'

using namespace OGLE;
int main()
{
	OGLEGame game("WorldE", 1280, 720);
	game.Run();
	return 0;
}
