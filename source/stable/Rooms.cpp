#include <iostream>
#include <list>
#include <filesystem>
#include <string>
#include "Reference_Files.h"
#include "Add_Game.h"
#include <sstream>
#include <iomanip>
#include "Rooms.h"
#include <vector>

using namespace std;

Rooms::Rooms() {
}

void Rooms::roomIterate(Reference_Files aRF, Add_Game& aGame) {
    list<string> z = aRF.getZones();
    list<string>::iterator zp = z.begin();
	
	string z_file;
	string a_file;
	string cur_zone;
	string cur_map;
	string to_convert;
	string m_file;
	string m_file_d;
	string coor_point;
	string coor1;
	string coor2;
	string concoor;

	int door_g;
	int new_min = 0;
	int zone_point;
	int zone_point_r;
	int map_point;
	int door;
	int i_concoor;

	vector<string> moc;

	vector<string> imv;
	vector<string> bc = aRF.getBossRooms();
	vector<string> wm = aRF.getWarpMaps();
	vector<string>::iterator wmp = wm.begin();
	string ivwm = *wmp;
	string::iterator ivwmp = ivwm.begin();
	vector<int> visited;

	std::random_device ran;

	std::mt19937 gener(ran());

	fstream acmap;
	fstream acmap_d;

	streampos zone_loc;
	streampos arm_loc;
	streampos door_loc;

	stringstream z_val_ss;

	char* ch_val;

	std::uniform_int_distribution<> dist;

    for (int i = 0; i < aRF.getWarpMaps().size() - 1; i++) {
		if (i != 5 && i != 6) {
			dist = std::uniform_int_distribution<>(0, aRF.getZonesOfChoice().size() - 1);
			m_file = aGame.getStringPath() + "\\MAPS\\" + *wmp;
			cur_map = *wmp;
			acmap.open(m_file, ios::in | ios::out | ios::binary | ios::ate);
			zone_point_r = dist(gener);
			if ((aRF.getZonesOfChoice().at(zone_point_r) == 32 && aRF.getMapsOfChoice().at(zone_point_r) == 5) && (cur_map == aGame.getStringPath() + "\\MAPS\\" + "MAP025.MPD" || cur_map == aGame.getStringPath() + "\\MAPS\\" + "MAP239.MPD" || cur_map == aGame.getStringPath() + "\\MAPS\\" + "MAP342.MPD" || cur_map == aGame.getStringPath() + "\\MAPS\\" + "MAP112.MPD")) {
				map_point = 7;
				coor_point = "100044";
			}
			if (aRF.getZonesOfChoice().at(zone_point_r) == 24 && (cur_map == aGame.getStringPath() + "\\MAPS\\" + "MAP226.MPD" || cur_map == aGame.getStringPath() + "\\MAPS\\" + "MAP283.MPD")) {
				zone_point = 27;
				map_point = 0;
				coor_point = "410004";
			}
			if (aRF.getZonesOfChoice().at(zone_point_r) == 29 && (cur_map == aGame.getStringPath() + "\\MAPS\\" + "MAP226.MPD" || cur_map == aGame.getStringPath() + "\\MAPS\\" + "MAP283.MPD")) {
				zone_point = 37;
				map_point = 0;
				coor_point = "030022";
			}
			else {
				zone_point = aRF.getZonesOfChoice().at(zone_point_r);
				map_point = aRF.getMapsOfChoice().at(zone_point_r);
				coor_point = aRF.getCoordinatesOfChoice().at(zone_point_r);
			}
			door = aRF.getWarps().at(i);
			acmap.seekg(door, ios::beg);
			door_loc = acmap.tellg();
			door_g = acmap.get();
			ch_val = new char(zone_point);
			acmap.seekp(door, ios::beg);
			acmap.write(ch_val, 1);
			if (m_file == aGame.getStringPath() + "\\MAPS\\" + "MAP025.MPD") {
				acmap.seekg(door + 12, ios::beg);
				door_loc = acmap.tellg();
				door_g = acmap.get();
				acmap.seekp(door + 12, ios::beg);
				acmap.write(ch_val, 1);
			}
			delete ch_val;
			door += 1;
			acmap.seekg(door, ios::beg);
			door_loc = acmap.tellg();
			door_g = acmap.get();
			ch_val = new char(map_point);
			acmap.seekp(door, ios::beg);
			acmap.write(ch_val, 1);
			if (m_file == aGame.getStringPath() + "\\MAPS\\" + "MAP025.MPD") {
				acmap.seekg(door + 12, ios::beg);
				door_loc = acmap.tellg();
				door_g = acmap.get();
				acmap.seekp(door + 12, ios::beg);
				acmap.write(ch_val, 1);
			}
			delete ch_val;
			door += 4;
			acmap.seekg(door, ios::beg);
			door_loc = acmap.tellg();
			door_g = acmap.get();
			coor1 = coor_point.at(0);
			coor2 = coor_point.at(1);
			concoor = coor1 + coor2;
			i_concoor = stoi(concoor);
			ch_val = new char(i_concoor);
			acmap.seekp(door, ios::beg);
			acmap.write(ch_val, 1);
			if (m_file == aGame.getStringPath() + "\\MAPS\\" + "MAP025.MPD") {
				acmap.seekg(door + 12, ios::beg);
				door_loc = acmap.tellg();
				door_g = acmap.get();
				acmap.seekp(door + 12, ios::beg);
				acmap.write(ch_val, 1);
			}
			delete ch_val;
			door += 1;
			acmap.seekg(door, ios::beg);
			door_loc = acmap.tellg();
			door_g = acmap.get();
			coor1 = coor_point.at(2);
			coor2 = coor_point.at(3);
			concoor = coor1 + coor2;
			i_concoor = stoi(concoor);
			ch_val = new char(i_concoor);
			acmap.seekp(door, ios::beg);
			acmap.write(ch_val, 1);
			if (m_file == aGame.getStringPath() + "\\MAPS\\" + "MAP025.MPD") {
				acmap.seekg(door + 12, ios::beg);
				door_loc = acmap.tellg();
				door_g = acmap.get();
				acmap.seekp(door + 12, ios::beg);
				acmap.write(ch_val, 1);
			}
			delete ch_val;
			door += 1;
			acmap.seekg(door, ios::beg);
			door_loc = acmap.tellg();
			door_g = acmap.get();
			coor1 = coor_point.at(4);
			coor2 = coor_point.at(5);
			concoor = coor1 + coor2;
			i_concoor = stoi(concoor);
			ch_val = new char(i_concoor);
			acmap.seekp(door, ios::beg);
			acmap.write(ch_val, 1);
			if (m_file == aGame.getStringPath() + "\\MAPS\\" + "MAP025.MPD") {
				acmap.seekg(door + 12, ios::beg);
				door_loc = acmap.tellg();
				door_g = acmap.get();
				acmap.seekp(door + 12, ios::beg);
				acmap.write(ch_val, 1);
			}
			delete ch_val;
			system((aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'").c_str());
			acmap.close();
			visited.push_back(zone_point);
			aRF.delZone(zone_point_r);
			aRF.delMap(zone_point_r);
			aRF.delCoordinate(zone_point_r);
		}
		std::advance(wmp, 1);
    }
}