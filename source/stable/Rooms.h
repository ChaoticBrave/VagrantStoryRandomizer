#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <random>

#include "Reference_Files.h"
#include "Add_Game.h"

using namespace std;
using std::filesystem::current_path;
using std::filesystem::path;
using std::filesystem::u8path;

class Rooms
{
private:
	fstream zone;
	fstream arm;

public:
	Rooms();
	void roomIterate(Reference_Files aRF, Add_Game& aGame);
};