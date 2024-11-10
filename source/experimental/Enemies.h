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

class Enemies
{
private:
	fstream map;
	int hex_1;
	int hex_2;
	int para_2;
	path file;
	path m_file;

public:
	Enemies();
	void mapIterate(Reference_Files aRF, Add_Game& aGame, string aDecision, std::mt19937 aGen, string nextDecision, string mainDecision, string statDecision, string balDecision);
};

