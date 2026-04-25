#pragma once

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

class Music
{
private:

public:
	Music();
	void areaMusic(Reference_Files aRF, Add_Game& aGame, std::mt19937 aGen);
	void musicRes(Reference_Files aRF, Add_Game& aGame);
	void bossMusic(Reference_Files aRF, Add_Game& aGame, std::mt19937 aGen, string gPath, bool lChoice);
};