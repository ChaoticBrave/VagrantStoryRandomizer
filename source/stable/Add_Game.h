#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <random>

#include "Reference_Files.h"

using namespace std;
using std::filesystem::current_path;
using std::filesystem::path;
using std::filesystem::u8path;


class Add_Game
{
private:
	path cp;
	string file_name;
	string w_name;
	std::mt19937 baseGener;


public:
	fstream opener;
	fstream game;

	Add_Game();
	path getPath();
	string getStringPath();
	string getFileName();
	void giveName();
	path getWhole();
	void validate(fstream& aGame, Reference_Files aRef);
	bool guiValidate(fstream& aGame, Reference_Files aRef, string aPath);
	bool guiValidatorUsed;
	void makeGen(string aSeed, string choices);
	void makeGenPlus(string aSeed, int aGivenSeed, string choices);
	std::mt19937 getGen();

};

