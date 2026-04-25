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
#include "Music.h"
#include <algorithm>

using namespace std;

Music::Music() {
	
}

void Music::areaMusic(Reference_Files aRF, Add_Game& aGame, std::mt19937 aGen) {
	list<string> z = aRF.getPlayZones();
	list<string>::iterator zp = z.begin();

	string z_file;
	string cur_zone;

	int res;

	int track_g;
	int song;

	fstream acmap;

	streampos zone_loc;
	streampos mus_loc;

	char* ch_val;

	std::uniform_int_distribution<> dist1 = std::uniform_int_distribution<>(1, 8);
	std::uniform_int_distribution<> dist2 = std::uniform_int_distribution<>(22, 23);
	std::uniform_int_distribution<> dist3 = std::uniform_int_distribution<>(29, 30);
	std::uniform_int_distribution<> dist4 = std::uniform_int_distribution<>(40, 44);
	std::uniform_int_distribution<> dist5 = std::uniform_int_distribution<>(118, 121);
	std::uniform_int_distribution<> dist6 = std::uniform_int_distribution<>(125, 126);
	std::uniform_int_distribution<> dist7 = std::uniform_int_distribution<>(129, 130);


	std::ofstream arMuBat;
	arMuBat.open("arMuCmd.cmd", std::ios::trunc);
	arMuBat << ("cd " + aGame.getStringPath() + " \n");

	for (int i = 0; i < aRF.getPlayZones().size(); i++) {
		z_file = aGame.getStringPath() + "\\ZONES\\" + *zp;
		cur_zone = *zp;
		acmap.open(z_file, ios::in | ios::out | ios::binary | ios::ate);
		res = dist1(aGen);
		if (res == 1) {
			song = 6;
		}
		else if (res == 2) {
			song = 9;
		}
		else if (res == 3) {
			song = dist2(aGen);
		}
		else if (res == 4) {
			song = dist3(aGen);
		}
		else if (res == 5) {
			song = dist4(aGen);
		}
		else if (res == 6) {
			song = dist5(aGen);
		}
		else if (res == 7) {
			song = dist6(aGen);
		}
		else if (res == 8) {
			song = dist7(aGen);
		}
		acmap.seekg(24, ios::beg);
		mus_loc = acmap.tellg();
		track_g = acmap.get();
		ch_val = new char(song);
		acmap.seekp(24, ios::beg);
		acmap.write(ch_val, 1);
		delete ch_val;
		arMuBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_zone + " '" + z_file + "'") << std::endl;
		acmap.close();
		std::advance(zp, 1);
	}
	arMuBat.close();
}

void Music::musicRes(Reference_Files aRF, Add_Game& aGame) {
	string z_file;
	string cur_zone;

	int track_g;

	fstream acmap;

	streampos zone_loc;
	streampos mus_loc;

	char* ch_val;


	std::ofstream lizBat;
	std::ofstream cutMuBat;
	lizBat.open("lizCmd.cmd", std::ios::trunc);
	lizBat << ("cd " + aGame.getStringPath() + " \n");
	lizBat << "copy \"" + aGame.getWhole().string() + "\" \"Backup Game.bin\" \n" << std::endl;
	lizBat << ("Patches\\xdelta3-3.1.0-i686.exe -d  -f -s \"Backup Game.bin\" Patches\\Lizardman.xdelta \"" + aGame.getWhole().string() + "\" \n") << std::endl;
	lizBat.close();
	cutMuBat.open("cutMuCmd.cmd", std::ios::trunc);
	cutMuBat << ("cd " + aGame.getStringPath() + " \n");
	z_file = aGame.getStringPath() + "\\ZONES\\ZONE032.ZND";
	cur_zone = "ZONE032.ZND";
	acmap.open(z_file, ios::in | ios::out | ios::binary | ios::ate);
	acmap.seekg(24, ios::beg);
	mus_loc = acmap.tellg();
	track_g = acmap.get();
	ch_val = new char(6);
	acmap.seekp(24, ios::beg);
	acmap.write(ch_val, 1);
	delete ch_val;
	cutMuBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_zone + " '" + z_file + "'") << std::endl;
	acmap.close();
	z_file = aGame.getStringPath() + "\\ZONES\\ZONE028.ZND";
	cur_zone = "ZONE028.ZND";
	acmap.open(z_file, ios::in | ios::out | ios::binary | ios::ate);
	acmap.seekg(24, ios::beg);
	mus_loc = acmap.tellg();
    track_g = acmap.get();
	ch_val = new char(9);
	acmap.seekp(24, ios::beg);
	acmap.write(ch_val, 1);
	delete ch_val;
	cutMuBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_zone + " '" + z_file + "'") << std::endl;
	acmap.close();
}

void Music::bossMusic(Reference_Files aRF, Add_Game& aGame, std::mt19937 aGen, string gPath, bool lChoice) {
	vector<string> m = aRF.getBossMusicRooms();
	vector<string>::iterator mp = m.begin();
	vector<int> ml = aRF.getBossMusicLoc();
	vector<int>::iterator mlp = ml.begin();

	string m_file;
	string cur_map;

	int res;
	int track_g;
	int song;
	int cur_loc;

	fstream acmap_mpd;
	fstream acmap_bin;

	streampos zone_loc;
	streampos mus_loc;

	char* ch_val;

	std::uniform_int_distribution<> dist1 = std::uniform_int_distribution<>(1, 5);
	std::uniform_int_distribution<> dist2 = std::uniform_int_distribution<>(31, 39);
	std::uniform_int_distribution<> dist3 = std::uniform_int_distribution<>(45, 49);
	std::uniform_int_distribution<> dist4 = std::uniform_int_distribution<>(156, 157);
	std::uniform_int_distribution<> dist5 = std::uniform_int_distribution<>(118, 121);
	std::uniform_int_distribution<> dist6 = std::uniform_int_distribution<>(125, 126);
	std::uniform_int_distribution<> dist7 = std::uniform_int_distribution<>(129, 130);


	std::ofstream boMuBat;
	boMuBat.open("boMuCmd.cmd", std::ios::trunc);
	boMuBat << ("cd " + aGame.getStringPath() + " \n");

	for (int i = 0; i < aRF.getBossMusicRooms().size(); i++) {
		m_file = aGame.getStringPath() + "\\MAPS\\" + *mp;
		cur_map = *mp;
		cur_loc = *mlp;
		if (cur_map == "MAP046.MPD" && lChoice == true) {
			m_file = aGame.getStringPath() + "\\MAPS\\PATCHED\\" + *mp;
		}
		res = dist1(aGen);
		if (res == 1) {
			song = 7;
		}
		else if (res == 2) {
			song = dist2(aGen);
		}
		else if (res == 3) {
			song = dist3(aGen);
		}
		else if (res == 4) {
			song = dist4(aGen);
		}
		else {
			song = 183;
		}
		if (cur_map == "MAP025.MPD" || cur_map == "MAP060.MPD" || cur_map == "MAP277.MPD" || cur_map == "MAP249.MPD" || cur_map == "MAP235.MPD" || cur_map == "MAP099.MPD" || cur_map == "MAP124.MPD") {
			acmap_bin.open(gPath, ios::in | ios::out | ios::binary | ios::ate);
			if (cur_map == "MAP025.MPD") {
				acmap_bin.seekg(258798096, ios::beg);
				mus_loc = acmap_bin.tellg();
				track_g = acmap_bin.get();
				ch_val = new char(song);
				acmap_bin.seekp(258798096, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(258798099, ios::beg);
			}
			else if (cur_map == "MAP060.MPD") {
				acmap_bin.seekg(258784337, ios::beg);
				mus_loc = acmap_bin.tellg();
				track_g = acmap_bin.get();
				ch_val = new char(song);
				acmap_bin.seekp(258784337, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(258784340, ios::beg);
			}
			else if (cur_map == "MAP277.MPD") {
				acmap_bin.seekg(259164576, ios::beg);
				mus_loc = acmap_bin.tellg();
				track_g = acmap_bin.get();
				ch_val = new char(song);
				acmap_bin.seekp(259164576, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(259164579, ios::beg);
			}
			else if (cur_map == "MAP249.MPD") {
				acmap_bin.seekg(259312761, ios::beg);
				mus_loc = acmap_bin.tellg();
				track_g = acmap_bin.get();
				ch_val = new char(song);
				acmap_bin.seekp(259312761, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(259312764, ios::beg);
			}
			else if (cur_map == "MAP235.MPD") {
				acmap_bin.seekg(259319803, ios::beg);
				mus_loc = acmap_bin.tellg();
				track_g = acmap_bin.get();
				ch_val = new char(song);
				acmap_bin.seekp(259319803, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(259319806, ios::beg);
			}
			else if (cur_map == "MAP124.MPD") {
				acmap_bin.seekg(259066021, ios::beg);
				mus_loc = acmap_bin.tellg();
				track_g = acmap_bin.get();
				ch_val = new char(song);
				acmap_bin.seekp(259066021, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(259066024, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(259067146, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(259067149, ios::beg);
			}
			else {
				acmap_bin.seekg(21916973, ios::beg);
				mus_loc = acmap_bin.tellg();
				track_g = acmap_bin.get();
				ch_val = new char(song);
				acmap_bin.seekp(21916973, ios::beg);
				acmap_bin.write(ch_val, 1);
				acmap_bin.seekp(21916976, ios::beg);
			}
			acmap_bin.write(ch_val, 1);
			delete ch_val;
			acmap_bin.close();
			std::advance(mp, 1);
			std::advance(mlp, 1);
		}
		else if ((cur_map == "MAP046.MPD" && lChoice == false)) {
			std::advance(mp, 1);
			std::advance(mlp, 1);
		}
		else {
			acmap_mpd.open(m_file, ios::in | ios::out | ios::binary | ios::ate);
			acmap_mpd.seekg(cur_loc, ios::beg);
			mus_loc = acmap_mpd.tellg();
			track_g = acmap_mpd.get();
			ch_val = new char(song);
			acmap_mpd.seekp(cur_loc, ios::beg);
			acmap_mpd.write(ch_val, 1);
			if (cur_map != "MAP223.MPD" && cur_map != "MAP290.MPD" && cur_map != "MAP312.MPD" && cur_map != "MAP257.MPD" && cur_map != "MAP067.MPD" && cur_map != "MAP102.MPD") {
				acmap_mpd.seekp(cur_loc + 3, ios::beg);
			}
			else {
				if (cur_map == "MAP223.MPD") {
					acmap_mpd.seekp(57210, ios::beg);
				}
				else if (cur_map == "MAP312.MPD") {
					acmap_mpd.seekp(54943, ios::beg);
				}
				else if (cur_map == "MAP257.MPD") {
					acmap_mpd.seekp(57035, ios::beg);
					acmap_mpd.write(ch_val, 1);
					acmap_mpd.seekp(57730, ios::beg);
					acmap_mpd.write(ch_val, 1);
					acmap_mpd.seekp(57727, ios::beg);
				}
				else if (cur_map == "MAP067.MPD") {
					acmap_mpd.seekp(55456, ios::beg);
				}
				else if (cur_map == "MAP102.MPD") {
					acmap_mpd.seekp(43044, ios::beg);
				}
				else {
					acmap_mpd.seekp(cur_loc + 2, ios::beg);
				}
			}
			acmap_mpd.write(ch_val, 1);
			if (cur_map == "MAP026.MPD") {
				acmap_mpd.seekp(61712, ios::beg);
				acmap_mpd.write(ch_val, 1);
				acmap_mpd.seekp(62227, ios::beg);
				acmap_mpd.write(ch_val, 1);
			}
			else if (cur_map == "MAP061.MPD") {
				acmap_mpd.seekp(54985, ios::beg);
				acmap_mpd.write(ch_val, 1);
				acmap_mpd.seekp(55245, ios::beg);
				acmap_mpd.write(ch_val, 1);
			}
			else if (cur_map == "MAP201.MPD") {
				acmap_mpd.seekp(50704, ios::beg);
				acmap_mpd.write(ch_val, 1);
				acmap_mpd.seekp(50707, ios::beg);
				acmap_mpd.write(ch_val, 1);
			}
			else if (cur_map == "MAP286.MPD") {
				acmap_mpd.seekp(52391, ios::beg);
				acmap_mpd.write(ch_val, 1);
				acmap_mpd.seekp(52391, ios::beg);
				acmap_mpd.write(ch_val, 1);
			}
			else if (cur_map == "MAP340.MPD") {
				acmap_mpd.seekp(55268, ios::beg);
				acmap_mpd.write(ch_val, 1);
				acmap_mpd.seekp(55271, ios::beg);
				acmap_mpd.write(ch_val, 1);
			}
			else if (cur_map == "MAP350.MPD") {
				acmap_mpd.seekp(51170, ios::beg);
				acmap_mpd.write(ch_val, 1);
				acmap_mpd.seekp(51173, ios::beg);
				acmap_mpd.write(ch_val, 1);
			}
			else if (cur_map == "MAP344.MPD") {
				acmap_mpd.seekp(54787, ios::beg);
				acmap_mpd.write(ch_val, 1);
				acmap_mpd.seekp(54790, ios::beg);
				acmap_mpd.write(ch_val, 1);
			}
			else if (cur_map == "MAP404.MPD") {
				acmap_mpd.seekp(54457, ios::beg);
				acmap_mpd.write(ch_val, 1);
				acmap_mpd.seekp(54460, ios::beg);
				acmap_mpd.write(ch_val, 1);
			}
			delete ch_val;
			boMuBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
			acmap_mpd.close();
			std::advance(mp, 1);
			std::advance(mlp, 1);
		}
	}
	boMuBat.close();
}