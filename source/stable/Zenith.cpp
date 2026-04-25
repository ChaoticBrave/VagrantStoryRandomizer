#define WIN32_LEAN_AND_MEAN

#include <afxwin.h>
#include <iostream>
#include <list>
#include <filesystem>
#include <string>
#include "Enemies.h"
#include "Reference_Files.h"
#include "Add_Game.h"
#include <sstream>
#include <iomanip>
#include "Zenith.h"
#include <algorithm>

using namespace std;

Zenith::Zenith() {
}

void Zenith::freeTeleport(Add_Game& aGame, Reference_Files aRF) {	

	fstream telmap;

	streampos telloc;

	int telass;

	char* ch_val;


	string zenTel1 = aGame.getStringPath() + "\\MISC\\BATTLE.PRG";
	string zenTel2 = aGame.getStringPath() + "\\ZENITH_QOL\\MENU\\MENU0.PRG";

	telmap.open(zenTel1, ios::in | ios::out | ios::binary | ios::ate);
	telmap.seekg(44764, ios::beg);
	telloc = telmap.tellg();
	telass = telmap.get();
	ch_val = new char(35);
	telmap.seekp(44764, ios::beg);
	telmap.write(ch_val, 1);
	delete ch_val;
	telmap.seekg(44765, ios::beg);
	telloc = telmap.tellg();
	telass = telmap.get();
	ch_val = new char(16);
	telmap.seekp(44765, ios::beg);
	telmap.write(ch_val, 1);
	delete ch_val;
	telmap.seekg(44766, ios::beg);
	telloc = telmap.tellg();
	telass = telmap.get();
	ch_val = new char(128);
	telmap.seekp(44766, ios::beg);
	telmap.write(ch_val, 1);
	delete ch_val;
	telmap.seekg(44767, ios::beg);
	telloc = telmap.tellg();
	telass = telmap.get();
	ch_val = new char(0);
	telmap.seekp(44767, ios::beg);
	telmap.write(ch_val, 1);
	delete ch_val;

	zenBat.open("teleCmd.cmd", std::ios::trunc);
	zenBat << ("cd " + aGame.getStringPath() + " \n");

	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /BATTLE/BATTLE.PRG" + " '" + zenTel1 + "'") << std::endl;
	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MENU/MENU0.PRG" + " '" + zenTel2 + "'") << std::endl;
	zenBat.close();
}

void Zenith::perfectAnalyze(Add_Game& aGame, Reference_Files aRF) {
	string analAcc = aGame.getStringPath() + "\\ZENITH_QOL\\SLUS_010.40";

	fstream analmap;

	streampos analloc;

	int analass;

	char* ch_val;


	analmap.open(analAcc, ios::in | ios::out | ios::binary | ios::ate);
	analmap.seekg(249273, ios::beg);
	analloc = analmap.tellg();
	analass = analmap.get();
	ch_val = new char(65);
	analmap.seekp(249273, ios::beg);
	analmap.write(ch_val, 1);
	delete ch_val;
	analmap.close();
	
	zenBat.open("analCmd.cmd", std::ios::trunc);
	zenBat << ("cd " + aGame.getStringPath() + " \n");


	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /SLUS_010.40" + " '" + analAcc + "'") << std::endl;
	zenBat.close();
}

void Zenith::friendlyManabreaker(Add_Game& aGame, Reference_Files aRF) {

	fstream manmap;

	streampos manloc;

	int manass;

	char* ch_val;


	string zenMan = aGame.getStringPath() + "\\MISC\\BATTLE.PRG";

	manmap.open(zenMan, ios::in | ios::out | ios::binary | ios::ate);
	manmap.seekg(89848, ios::beg);
	manloc = manmap.tellg();
	manass = manmap.get();
	ch_val = new char(51);
	manmap.seekp(89848, ios::beg);
	manmap.write(ch_val, 1);
	delete ch_val;
	manmap.seekg(89849, ios::beg);
	manloc = manmap.tellg();
	manass = manmap.get();
	ch_val = new char(0);
	manmap.seekp(89849, ios::beg);
	manmap.write(ch_val, 1);
	delete ch_val;
	manmap.seekg(89850, ios::beg);
	manloc = manmap.tellg();
	manass = manmap.get();
	ch_val = new char(139);
	manmap.seekp(89850, ios::beg);
	manmap.write(ch_val, 1);
	delete ch_val;
	manmap.seekg(89851, ios::beg);
	manloc = manmap.tellg();
	manass = manmap.get();
	ch_val = new char(144);
	manmap.seekp(89851, ios::beg);
	manmap.write(ch_val, 1);
	delete ch_val;
	manmap.seekg(89860, ios::beg);
	manloc = manmap.tellg();
	manass = manmap.get();
	ch_val = new char(1);
	manmap.seekp(89860, ios::beg);
	manmap.write(ch_val, 1);
	delete ch_val;
	manmap.seekg(89861, ios::beg);
	manloc = manmap.tellg();
	manass = manmap.get();
	ch_val = new char(0);
	manmap.seekp(89861, ios::beg);
	manmap.write(ch_val, 1);
	delete ch_val;
	manmap.seekg(89862, ios::beg);
	manloc = manmap.tellg();
	manass = manmap.get();
	ch_val = new char(104);
	manmap.seekp(89862, ios::beg);
	manmap.write(ch_val, 1);
	delete ch_val;
	manmap.seekg(89863, ios::beg);
	manloc = manmap.tellg();
	manass = manmap.get();
	ch_val = new char(41);
	manmap.seekp(89863, ios::beg);
	manmap.write(ch_val, 1);
	delete ch_val;

	zenBat.open("manaCmd.cmd", std::ios::trunc);
	zenBat << ("cd " + aGame.getStringPath() + " \n");

	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /BATTLE/BATTLE.PRG" + " '" + zenMan + "'") << std::endl;
	zenBat.close();
}

void Zenith::newDrops(Add_Game& aGame, Reference_Files aRF) {
	//string mapCut = aGame.getStringPath() + "\\ZENITH_QOL\\MAP\\MAP000.MPD";
	string batGrow = aGame.getStringPath() + "\\ZENITH_QOL\\BATTLE\\BATTLE.PRG";

	zenBat.open("dropCmd.cmd", std::ios::trunc);
	zenBat << ("cd " + aGame.getStringPath() + " \n");

	//zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/MAP000.MPD" + " '" + mapCut + "'") << std::endl;
	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /BATTLE/BATTLE.PRG" + " '" + batGrow + "'") << std::endl;
	zenBat.close();
}

void Zenith::bossDrops(Add_Game& aGame, Reference_Files aRF) {

	fstream grimmap;

	streampos grimloc;

	int grimass;

	char* ch_val;


	string grimMan1 = aGame.getStringPath() + "\\MAPS\\MAP032.MPD";
	string grimMan2 = aGame.getStringPath() + "\\MAPS\\MAP286.MPD";
	string grimMan3 = aGame.getStringPath() + "\\MAPS\\MAP277.MPD";
	string grimMan4 = aGame.getStringPath() + "\\MAPS\\MAP298.MPD";
	string grimMan5 = aGame.getStringPath() + "\\MAPS\\MAP312.MPD";

	grimmap.open(grimMan1, ios::in | ios::out | ios::binary | ios::ate);
	grimmap.seekg(58726, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(130);
	grimmap.seekp(58726, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(58728, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(68);
	grimmap.seekp(58728, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.close();
	grimmap.open(grimMan2, ios::in | ios::out | ios::binary | ios::ate);
	grimmap.seekg(54346, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(143);
	grimmap.seekp(54346, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(54348, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(131);
	grimmap.seekp(54348, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(54350, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(73);
	grimmap.seekp(54350, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(54351, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(1);
	grimmap.seekp(54351, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.close();
	grimmap.open(grimMan3, ios::in | ios::out | ios::binary | ios::ate);
	grimmap.seekg(55686, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(147);
	grimmap.seekp(55686, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(55688, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(132);
	grimmap.seekp(55688, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(55690, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(93);
	grimmap.seekp(55690, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.close();
	grimmap.open(grimMan4, ios::in | ios::out | ios::binary | ios::ate);
	grimmap.seekg(53706, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(151);
	grimmap.seekp(53706, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(53708, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(133);
	grimmap.seekp(53708, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(53709, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(1);
	grimmap.seekp(53709, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.close();
	grimmap.open(grimMan5, ios::in | ios::out | ios::binary | ios::ate);
	grimmap.seekg(56090, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(155);
	grimmap.seekp(56090, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(56092, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(134);
	grimmap.seekp(56092, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.seekg(56094, ios::beg);
	grimloc = grimmap.tellg();
	grimass = grimmap.get();
	ch_val = new char(91);
	grimmap.seekp(56094, ios::beg);
	grimmap.write(ch_val, 1);
	delete ch_val;
	grimmap.close();

	zenBat.open("bossCmd.cmd", std::ios::trunc);
	zenBat << ("cd " + aGame.getStringPath() + " \n");

	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/MAP032.MPD" + " '" + grimMan1 + "'") << std::endl;
	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/MAP286.MPD" + " '" + grimMan2 + "'") << std::endl;
	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/MAP277.MPD" + " '" + grimMan3 + "'") << std::endl;
	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/MAP298.MPD" + " '" + grimMan4 + "'") << std::endl;
	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/MAP312.MPD" + " '" + grimMan5 + "'") << std::endl;
	zenBat.close();
}

void Zenith::quietEnemies(Add_Game& aGame, Reference_Files aRF) {

	fstream quizon;

	streampos quiloc;

	int quiass;

	char* ch_val;


	string quiZon1 = aGame.getStringPath() + "\\ZONES\\ZONE032.ZND";
	string quiZon2 = aGame.getStringPath() + "\\ZONES\\ZONE053.ZND";
	string quiZon3 = aGame.getStringPath() + "\\ZONES\\ZONE030.ZND";

	quizon.open(quiZon1, ios::in | ios::out | ios::binary | ios::ate);
	quizon.seekg(4612, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(4612, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(5736, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(5736, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(14728, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(14728, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(14732, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(14732, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(15852, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(15852, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(15856, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(15856, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(24844, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(24844, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(24848, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(24848, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(25968, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(25968, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(25972, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(25972, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.close();
	quizon.open(quiZon2, ios::in | ios::out | ios::binary | ios::ate);
	quizon.seekg(12468, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(12468, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(13592, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(13592, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.close();
	quizon.open(quiZon3, ios::in | ios::out | ios::binary | ios::ate);
	quizon.seekg(5428, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(5428, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.seekg(5432, ios::beg);
	quiloc = quizon.tellg();
	quiass = quizon.get();
	ch_val = new char(0);
	quizon.seekp(5432, ios::beg);
	quizon.write(ch_val, 1);
	delete ch_val;
	quizon.close();


	zenBat.open("quietCmd.cmd", std::ios::trunc);
	zenBat << ("cd " + aGame.getStringPath() + " \n");

	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/ZONE032.ZND" + " '" + quiZon1 + "'") << std::endl;
	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/ZONE053.ZND" + " '" + quiZon2 + "'") << std::endl;
	zenBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/ZONE030.ZND" + " '" + quiZon3 + "'") << std::endl;
	zenBat.close();
}