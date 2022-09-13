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
	vector<string> has_chest;
	list<string> has_key_or_sig;
	vector<vector<string>> map_list;
	string tool = "psxinject.exe ";


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
	vector<string> getIndivZone(vector<string> aZoneList);
	vector<string> getChestCheck();
	list<string> getKSCheck();
};

