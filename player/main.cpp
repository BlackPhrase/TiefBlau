#include <cstdlib>
#include "TiefBlau.hpp"

int main(int argc, char **argv)
{
	if(!IBFInit())
		return EXIT_FAILURE;
	
	IBFShutdown();
	return EXIT_SUCCESS;
};