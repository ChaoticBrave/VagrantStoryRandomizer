#include <iostream>
#include <list>
#include <filesystem>
#include <string>
#include "Reference_Files.h"
#include "Add_Game.h"
#include <sstream>
#include <iomanip>
#include "Rooms.h"

using namespace std;

Rooms::Rooms() {
}

void Rooms::roomIterate(Reference_Files aRF, Add_Game& aGame) {
	list<string> z = aRF.getZonesFR();
	list<string>::iterator zp = z.begin();
	
	string z_file;
	string cur_zone;
	string to_convert;


	std::uniform_int_distribution<> dist = std::uniform_int_distribution<>(0, aRF.getIdList().size() - 3);

	int map_ind;
	int mbt;
	int zone_g;
	int z_val;
	int bt;

	vector<string> moc;

	vector<vector<string>> idl = aRF.getIdList();
	vector<vector<string>>::iterator moci = idl.begin();
	vector<string> imv;


	std::random_device ran;

	std::mt19937 gener(ran());

	streampos zone_loc;

	stringstream z_val_ss;

	char* ch_val;

	for (int i = 0; i < aRF.getZonesFR().size(); i++) {
		z_file = aGame.getStringPath() + "\\ZONES\\" + *zp;
		cur_zone = *zp;
		zone.open(z_file, ios::in | ios::out | ios::binary | ios::ate);
		bt = 30;
		map_ind = dist(gener);
		advance(moci, map_ind);
		imv = *moci;
		mbt = 0;
		if (z_file == aGame.getStringPath() + "\\ZONES\\ZONE009.ZND") {
			bt += 8;
		}
		while (bt <= (8 * aRF.getMapSum().at(i))) {
			zone.seekg(bt, ios::beg);
			zone_loc = zone.tellg();
			zone_g = zone.get();
			to_convert = imv.at(mbt);
			z_val_ss << std::hex << to_convert;
			z_val_ss >> z_val;
			z_val_ss.clear();
			ch_val = new char(z_val);
			zone.seekp(bt, ios::beg);
			zone.write(ch_val, 1);
			delete ch_val;
			bt += 1;
			mbt += 1;
			if (mbt > 7) {
				moci = idl.begin();
				map_ind = dist(gener);
				advance(moci, map_ind);
				imv = *moci;
				mbt = 0;
			}
		}
		system((aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_zone + " '" + z_file + "'").c_str());
		zone.close();
		std::advance(zp, 1);
		moci = idl.begin();
	}
}