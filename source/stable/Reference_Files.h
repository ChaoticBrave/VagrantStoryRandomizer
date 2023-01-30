#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;


class Reference_Files
{
private:
	void loadFiles();

	string com;
	list<string> zones;
	vector<int> r_zones;
	list<string> zones_for_rooms;
	vector<int> map_sum;
	vector<string> has_chest;
	list<string> has_key_or_sig;
	vector<string> has_boss;
	vector<string> warp_maps;
	vector<vector<string>> map_list;
	vector<int> warps;
	vector<int> zoc;
	vector<int> moc;
	vector<string> coc;
	string tool = "psinject\\psxinject.exe ";
	vector<string> crashRooms;
	vector<string> l1;
	vector<string> l2;
	vector<string> l3;
	vector<string> l4;
	vector<string> l5;
	vector<string> l6;
	vector<string> l7;
	vector<string> l8;
	vector<string> l9;
	vector<string> l10;
	vector<string> l11;
	vector<string> l12;
	vector<string> l13;
	vector<string> l14;
	vector<string> l15;
	vector<string> l16;
	vector<string> l17;
	vector<string> l18;
	vector<string> l19;
	vector<string> l20;
	vector<string> l21;


public:
	Reference_Files();
	string getCom();
	string getTool();
	vector<vector<string>> getMapList();
	list<string> getZones();
	list<string> getZonesFR();
	list<string> getKSCheck();
	vector<int> getMapSum();
	vector<string> getWarpMaps();
	vector<int> getWarps();
	vector<int> getZonesOfChoice();
	vector<int> getMapsOfChoice();
	vector<string> getCoordinatesOfChoice();
	vector<string> getIndivZone(vector<string> aZoneList);
	vector<string> getChestCheck();
	vector<string> getBossRooms();
	vector<int> getRawZones();
	void delZone(int anIndex);
	void delMap(int anIndex);
	void delCoordinate(int anIndex);
	vector<string> getCrashRooms();
};

