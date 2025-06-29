#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "Reference_Files.h"

using namespace std;

Reference_Files::Reference_Files() {
	loadFiles();
}

void Reference_Files::loadFiles() {
	com = "8376858345484948";
	zones = { "ZONE009.ZND", "ZONE011.ZND", "ZONE012.ZND", "ZONE013.ZND", "ZONE014.ZND", "ZONE015.ZND", "ZONE017.ZND", "ZONE022.ZND", "ZONE024.ZND", "ZONE028.ZND", "ZONE030.ZND", "ZONE032.ZND", "ZONE040.ZND", "ZONE048.ZND", "ZONE049.ZND", "ZONE050.ZND", "ZONE051.ZND", "ZONE052.ZND", "ZONE053.ZND", "ZONE055.ZND", "ZONE056.ZND" };
	r_zones = { 9, 11, 12, 13, 14, 15, 16, 17, 22, 23, 24, 25, 28, 29, 30, 31, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56 };
	zones_for_rooms = { "ZONE009.ZND", "ZONE011.ZND", "ZONE012.ZND", "ZONE013.ZND", "ZONE014.ZND", "ZONE015.ZND", "ZONE016.ZND", "ZONE017.ZND", "ZONE022.ZND", "ZONE023.ZND", "ZONE024.ZND", "ZONE025.ZND", "ZONE028.ZND", "ZONE029.ZND", "ZONE030.ZND", "ZONE031.ZND", "ZONE032.ZND", "ZONE034.ZND", "ZONE035.ZND", "ZONE036.ZND", "ZONE037.ZND", "ZONE038.ZND", "ZONE039.ZND", "ZONE040.ZND", "ZONE041.ZND", "ZONE042.ZND", "ZONE043.ZND", "ZONE044.ZND", "ZONE045.ZND", "ZONE046.ZND", "ZONE047.ZND", "ZONE048.ZND", "ZONE049.ZND", "ZONE050.ZND", "ZONE051.ZND", "ZONE052.ZND", "ZONE053.ZND", "ZONE054.ZND", "ZONE055.ZND", "ZONE056.ZND" };
	map_sum = { 19, 1, 2, 18, 1, 13, 1, 1, 10, 6, 16, 5, 19, 7, 6, 2, 24, 1, 1, 1, 1, 1, 1, 26, 3, 1, 1, 1, 1, 1, 1, 27, 13, 24, 29, 8, 32, 5, 23, 26 };
	l1 = { "MAP009.MPD", "MAP010.MPD", "MAP011.MPD", "MAP012.MPD", "MAP013.MPD", "MAP014.MPD", "MAP015.MPD", "MAP016.MPD", "MAP018.MPD", "MAP019.MPD", "MAP020.MPD", "MAP021.MPD", "MAP022.MPD", "MAP024.MPD", "MAP412.MPD" };
	l2 = { "MAP025.MPD" };
	l3 = { "MAP026.MPD", "MAP408.MPD" };
	l4 = { "MAP028.MPD", "MAP029.MPD", "MAP030.MPD", "MAP031.MPD", "MAP032.MPD", "MAP033.MPD", "MAP034.MPD", "MAP036.MPD", "MAP037.MPD", "MAP039.MPD", "MAP040.MPD", "MAP041.MPD", "MAP042.MPD", "MAP043.MPD", "MAP044.MPD", "MAP045.MPD" };
	l5 = { "MAP046.MPD" };
	l6 = { "MAP047.MPD", "MAP048.MPD", "MAP049.MPD", "MAP050.MPD", "MAP051.MPD", "MAP052.MPD", "MAP053.MPD", "MAP054.MPD", "MAP055.MPD", "MAP058.MPD", "MAP059.MPD" };
	l7 = { "MAP061.MPD" };
	l8 = { "MAP063.MPD", "MAP067.MPD", "MAP069.MPD" };
	l9 = { "MAP079.MPD", "MAP080.MPD", "MAP081.MPD", "MAP083.MPD", "MAP084.MPD", "MAP088.MPD", "MAP090.MPD", "MAP094.MPD" };
	l10 = { "MAP106.MPD", "MAP108.MPD", "MAP109.MPD", "MAP111.MPD", "MAP112.MPD", "MAP114.MPD", "MAP115.MPD", "MAP116.MPD", "MAP117.MPD", "MAP118.MPD", "MAP119.MPD", "MAP120.MPD", "MAP121.MPD", "MAP122.MPD", "MAP123.MPD" };
	l11 = { "MAP140.MPD", "MAP142.MPD", "MAP144.MPD" };
	l12 = { "MAP148.MPD", "MAP149.MPD", "MAP150.MPD", "MAP153.MPD", "MAP154.MPD", "MAP157.MPD", "MAP158.MPD", "MAP159.MPD", "MAP160.MPD", "MAP163.MPD", "MAP164.MPD", "MAP165.MPD", "MAP166.MPD" };
	l13 = { "MAP180.MPD", "MAP181.MPD", "MAP182.MPD", "MAP184.MPD", "MAP185.MPD", "MAP188.MPD", "MAP189.MPD", "MAP190.MPD", "MAP192.MPD", "MAP195.MPD", "MAP196.MPD", "MAP197.MPD", "MAP198.MPD", "MAP199.MPD", "MAP201.MPD", "MAP202.MPD", "MAP203.MPD" };
	l14 = { "MAP221.MPD", "MAP222.MPD", "MAP223.MPD", "MAP225.MPD", "MAP227.MPD", "MAP228.MPD", "MAP229.MPD", "MAP230.MPD", "MAP231.MPD", "MAP232.MPD", "MAP233.MPD", "MAP235.MPD", "MAP236.MPD", "MAP237.MPD", "MAP238.MPD", "MAP239.MPD", "MAP240.MPD", "MAP241.MPD", "MAP242.MPD", "MAP244.MPD", "MAP245.MPD", "MAP246.MPD" };
	l15 = { "MAP247.MPD", "MAP248.MPD", "MAP249.MPD", "MAP250.MPD", "MAP251.MPD", "MAP252.MPD", "MAP253.MPD", "MAP254.MPD", "MAP255.MPD", "MAP256.MPD", "MAP257.MPD", "MAP258.MPD", "MAP259.MPD" };
	l16 = { "MAP260.MPD", "MAP261.MPD", "MAP262.MPD", "MAP263.MPD", "MAP264.MPD", "MAP265.MPD", "MAP266.MPD", "MAP267.MPD", "MAP269.MPD", "MAP270.MPD", "MAP272.MPD", "MAP273.MPD", "MAP274.MPD", "MAP275.MPD", "MAP277.MPD", "MAP279.MPD", "MAP281.MPD", "MAP282.MPD" };
	l17 = { "MAP284.MPD", "MAP285.MPD", "MAP286.MPD", "MAP288.MPD", "MAP289.MPD", "MAP290.MPD", "MAP292.MPD", "MAP293.MPD", "MAP294.MPD", "MAP295.MPD", "MAP296.MPD", "MAP297.MPD", "MAP298.MPD", "MAP300.MPD", "MAP302.MPD", "MAP303.MPD", "MAP304.MPD", "MAP305.MPD", "MAP306.MPD", "MAP307.MPD", "MAP308.MPD", "MAP309.MPD", "MAP310.MPD" };
	l18 = { "MAP351.MPD", "MAP352.MPD", "MAP353.MPD", "MAP354.MPD", "MAP355.MPD", "MAP356.MPD", "MAP357.MPD", "MAP358.MPD" };
	l19 = { "MAP312.MPD", "MAP314.MPD", "MAP315.MPD", "MAP316.MPD", "MAP317.MPD", "MAP318.MPD", "MAP319.MPD", "MAP320.MPD", "MAP321.MPD", "MAP322.MPD", "MAP323.MPD", "MAP324.MPD", "MAP325.MPD", "MAP326.MPD", "MAP328.MPD", "MAP329.MPD", "MAP331.MPD", "MAP332.MPD", "MAP333.MPD", "MAP334.MPD", "MAP336.MPD", "MAP337.MPD", "MAP338.MPD", "MAP339.MPD", "MAP340.MPD", "MAP342.MPD" };
	l20 = { "MAP360.MPD", "MAP362.MPD", "MAP365.MPD", "MAP366.MPD", "MAP367.MPD", "MAP368.MPD", "MAP369.MPD", "MAP371.MPD", "MAP373.MPD", "MAP375.MPD", "MAP377.MPD", "MAP378.MPD", "MAP379.MPD", "MAP380.MPD", "MAP381.MPD" };
	l21 = { "MAP382.MPD", "MAP383.MPD", "MAP384.MPD", "MAP385.MPD", "MAP386.MPD", "MAP387.MPD", "MAP388.MPD", "MAP389.MPD", "MAP390.MPD", "MAP391.MPD", "MAP392.MPD", "MAP394.MPD", "MAP395.MPD", "MAP396.MPD", "MAP397.MPD", "MAP398.MPD", "MAP399.MPD", "MAP402.MPD", "MAP403.MPD", "MAP404.MPD", "MAP405.MPD", "MAP407.MPD" };
	map_list = { l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21 };
	warp_maps = { "MAP025.MPD", "MAP283.MPD", "MAP226.MPD", "MAP112.MPD", "MAP239.MPD", "MAP166.MPD", "MAP224.MPD", "MAP171.MPD" };
	ret_maps = { "MAP028.MPD", "MAP152.MPD", "MAP200.MPD", "MAP126.MPD", "MAP287.MPD", "MAP247.MPD", "MAP311.MPD", "MAP087.MPD" };
	warps = { 56540, 47384, 50644, 49588, 50656, 54328, 55092, 53976 };
	ret_warps = { 51152, 54484, 47404, 49652, 47212, 52688, 47384, 41360 };
	zoc = { 13, 32, 40, 29, 51, 49, 53, 24 };
	ret_zoc = { 11, 50, 48, 28, 48, 32, 48, 39 };
	moc = { 0, 5, 21, 2, 3, 0, 0, 8 };
	ret_moc = { 0, 23, 6, 7, 19, 19, 4, 0 };
	coc = { "680008", "690044", "130044", "980016", "670008", "030052", "030052", "420004" };
	ret_coc = { "070088", "030052", "670008", "440008", "030040", "640060", "720008", "970008" };
	has_chest = { "MAP018.MPD", "MAP027.MPD", "MAP409.MPD", "MAP025.MPD", "MAP026.MPD", "MAP408.MPD", "MAP032.MPD", "MAP033.MPD", "MAP037.MPD", "MAP045.MPD", "MAP050.MPD", "MAP079.MPD", "MAP081.MPD", "MAP095.MPD", "MAP124.MPD", "MAP142.MPD", "MAP175.MPD", "MAP176.MPD", "MAP177.MPD", "MAP202.MPD", "MAP203.MPD", "MAP350.MPD", "MAP227.MPD", "MAP241.MPD", "MAP240.MPD", "MAP254.MPD", "MAP255.MPD", "MAP259.MPD", "MAP261.MPD", "MAP270.MPD", "MAP274.MPD", "MAP276.MPD", "MAP289.MPD", "MAP292.MPD", "MAP295.MPD", "MAP306.MPD", "MAP316.MPD", "MAP352.MPD", "MAP358.MPD", "MAP326.MPD", "MAP331.MPD", "MAP333.MPD", "MAP336.MPD", "MAP345.MPD", "MAP347.MPD", "MAP381.MPD", "MAP380.MPD", "MAP379.MPD", "MAP378.MPD", "MAP397.MPD", "MAP399.MPD", "MAP405.MPD", "MAP407.MPD" };
	has_key_or_sig = { "MAP270.MPD", "MAP254.MPD", "MAP255.MPD", "MAP227.MPD", "MAP259.MPD", "MAP142.MPD", "MAP241.MPD", "MAP345.MPD" };
	has_boss = { "MAP025.MPD", "MAP026.MPD", "MAP060.MPD", "MAP061.MPD", "MAP150.MPD", "MAP266.MPD", "MAP277.MPD", "MAP282.MPD", "MAP223.MPD", "MAP201.MPD", "MAP203.MPD", "MAP124.MPD", "MAP286.MPD", "MAP298.MPD", "MAP290.MPD", "MAP248.MPD", "MAP249.MPD", "MAP252.MPD", "MAP366.MPD", "MAP371.MPD", "MAP235.MPD", "MAP312.MPD", "MAP257.MPD", "MAP334.MPD", "MAP340.MPD", "MAP140.MPD", "MAP142.MPD", "MAP145.MPD", "MAP069.MPD", "MAP067.MPD", "MAP063.MPD", "MAP079.MPD", "MAP090.MPD", "MAP083.MPD", "MAP094.MPD", "MAP096.MPD", "MAP350.MPD", "MAP344.MPD", "MAP377.MPD", "MAP383.MPD", "MAP387.MPD", "MAP392.MPD", "MAP396.MPD", "MAP404.MPD", "MAP356.MPD", "MAP408.MPD", "MAP046.MPD", "MAP362.MPD"};
	crashRooms = { "MAP052.MPD", "MAP054.MPD", "MAP115.MPD", "MAP033.MPD", "MAP270.MPD", "MAP058.MPD", "MAP154.MPD", "MAP149.MPD", "MAP157.MPD", "MAP256.MPD", "MAP165.MPD" };
	untitleds = { 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 140, 141, 142, 144, 145, 146, 148, 149, 150, 152, 153, 154, 156, 157, 158, 160, 161, 162, 164, 165, 166, 201 };
	ene_zones = { "ZONE009.ZND", "ZONE011.ZND", "ZONE012.ZND", "ZONE013.ZND", "ZONE014.ZND", "ZONE015.ZND", "ZONE016.ZND", "ZONE017.ZND", "ZONE022.ZND", "ZONE024.ZND", "ZONE025.ZND", "ZONE028.ZND", "ZONE030.ZND", "ZONE031.ZND", "ZONE032.ZND", "ZONE036.ZND", "ZONE040.ZND", "ZONE041.ZND", "ZONE048.ZND", "ZONE049.ZND", "ZONE050.ZND", "ZONE051.ZND", "ZONE052.ZND", "ZONE053.ZND", "ZONE054.ZND", "ZONE055.ZND", "ZONE056.ZND" };
	ene_counts = { 21, 5, 4, 24, 3, 17, 1, 2, 3, 10, 1, 24, 10, 1, 30, 1, 11, 2, 32, 15, 13, 28, 9, 21, 7, 23, 30 };
	ene_offsets = { 188, 44, 52, 180, 44, 140, 44, 44, 116, 164, 76, 188, 84, 52, 228, 44, 244, 60, 252, 140, 228, 268, 100, 292, 76, 220, 244 };
	ene_wep_offsets = { 412, 140, 140, 428, 124, 332, 108, 116, 196, 300, 140, 436, 220, 116, 524, 108, 388, 132, 564, 316, 388, 548, 228, 516, 188, 460, 540 };
	// 0x464 | 1124 is the difference between enemy weapon category sections
}


string Reference_Files::getCom() {
	return com;
}

string Reference_Files::getTool() {
	return tool;
}

vector<vector<string>> Reference_Files::getMapList() {
	return map_list;
}

vector<string> Reference_Files::getIndivZone(vector<string> aZoneList) {
	if (std::find(map_list.begin(), map_list.end(), aZoneList) != map_list.end()) {
		return aZoneList;
	}

	else {
		cout << "This item does not exist!" << endl;
	}

}

list<string> Reference_Files::getZones() {
	return zones;
}

list<string> Reference_Files::getZonesFR() {
	return zones_for_rooms;
}

list<string> Reference_Files::getEneZones() {
	return ene_zones;
}

list<string> Reference_Files::getKSCheck() {
	return has_key_or_sig;
}

vector<int> Reference_Files::getMapSum() {
	return map_sum;
}

vector<int> Reference_Files::getEneOffsets() {
	return ene_offsets;
}

vector<string> Reference_Files::getChestCheck() {
	return has_chest;
}

vector<string> Reference_Files::getBossRooms() {
	return has_boss;
}

vector<int> Reference_Files::getRawZones() {
	return r_zones;
}

vector<string> Reference_Files::getWarpMaps() {
	return warp_maps;

}vector<string> Reference_Files::getRetWarpMaps() {
	return ret_maps;
}

vector<int> Reference_Files::getWarps() {
	return warps;
}

vector<int> Reference_Files::getEneCounts() {
	return ene_counts;
}

vector<int> Reference_Files::getRetWarps() {
	return ret_warps;
}

vector<int> Reference_Files::getZonesOfChoice() {
	return zoc;
}

vector<int> Reference_Files::getEneWepOffs() {
	return ene_wep_offsets;
}

vector<int> Reference_Files::getRetZonesOfChoice() {
	return ret_zoc;
}

vector<int> Reference_Files::getMapsOfChoice() {
	return moc;
}

vector<int> Reference_Files::getRetMapsOfChoice() {
	return ret_moc;
}

vector<int> Reference_Files::getUntitleds() {
	return untitleds;
}

vector<string> Reference_Files::getCoordinatesOfChoice() {
	return coc;
}

vector<string> Reference_Files::getRetCoordinatesOfChoice() {
	return ret_coc;
}

void Reference_Files::delZone(int anIndex) {
	zoc.erase(std::next(zoc.begin(), anIndex));
}

void Reference_Files::delMap(int anIndex) {
	moc.erase(std::next(moc.begin(), anIndex));
}

void Reference_Files::delRetMap(int anIndex) {
	ret_maps.erase(std::next(ret_maps.begin(), anIndex));
}

void Reference_Files::delRetDoor(int anIndex) {
	ret_warps.erase(std::next(ret_warps.begin(), anIndex));
}

void Reference_Files::delCoordinate(int anIndex) {
	coc.erase(std::next(coc.begin(), anIndex));
}

vector<string> Reference_Files::getCrashRooms() {
	return crashRooms;
}