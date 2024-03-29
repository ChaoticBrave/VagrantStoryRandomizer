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
#include <algorithm>
//#include <windows.h>


using namespace std;

Enemies::Enemies() {
            
}

void Enemies::mapIterate(Reference_Files aRF, Add_Game& aGame, string aDecision, std::mt19937 aGen) {
    list<string> z = aRF.getZones();
    list<string>::iterator zp = z.begin();
    vector<vector<string>> ml = aRF.getMapList();
    vector<vector<string>>::iterator mlp = ml.begin();
    vector<string> ivm = *mlp;
    vector<string>::iterator ivmp = ivm.begin();
    vector<string> cc = aRF.getChestCheck();
    vector<string> bc = aRF.getBossRooms();
    vector<string> ccr = aRF.getCrashRooms();
    vector<string>::iterator ccb = cc.begin();
    vector<string>::iterator cce = cc.end();
    vector<int> unt = aRF.getUntitleds();
    vector<string> finishedMaps;

    string sh1;
    string sh2;
    string shc;
    string sqn;
    string m_file;
    string file;
    string cur_map;
    string cur_zone;
    string sCmdPath;
    string tool = aRF.getTool();

    //wstring wToolPath = wstring(tool.begin(), tool.end());
    //wstring wCmdPath;

    //LPCWSTR toolPath = wToolPath.c_str();

    //LPWSTR cmdPath;

    fstream acmap;
    streampos map_fin;
    streampos map_loc;
    streampos ene_at;
    streampos dr_at;
    streampos odds_at;


    int size;
    int parnum;
    int quo_numer;
    int ene;
    int ene_loc;
    int ind_item;
    int odds;
    int choice;

    char * ch_val;
    char hhex_1[20];
    char hhex_2[20];

    //wchar_t wCmd[20];

    std::stringstream sti;
    std::stringstream hquo_numer;
    std::stringstream hparnum;
    //std::random_device ran;
    //std::mt19937 gener(ran());
    std::uniform_int_distribution<> ene_dist;
    std::uniform_int_distribution<> item_dist;
    std::uniform_int_distribution<> odds_dist;
    std::uniform_int_distribution<> picker;
    std::stringstream h1;
    std::stringstream h2;

    //std::ofstream mapoutput;
    //mapoutput.open("rooms.txt", std::ios_base::app);

    //STARTUPINFO info = { sizeof(info) };
    //PROCESS_INFORMATION processInfo;
    
    std::ofstream eneBat;
    eneBat.open("eneCmd.cmd", std::ios::trunc);
    eneBat << ("cd " + aGame.getStringPath() + " \n");
        

    for (int i = 0; i < aRF.getMapList().size(); i++) {
        file = aGame.getStringPath() + "\\ZONES\\" + *zp;
        cur_zone = *zp;
        map.open(file, ios::in | ios::out | ios::binary | ios::ate);
        map.seekg(13, ios::beg);
        map.tellg();
        hex_1 = map.get();
        sprintf_s(hhex_1, "%X", hex_1);
        h1 << hhex_1;
        h1 >> sh1;
        h1.clear();
        map.seekg(12, ios::beg);
        map.tellg();
        hex_2 = map.get();
        sprintf_s(hhex_2, "%X", hex_2);
        h2 << hhex_2;
        h2 >> sh2;
        h2.clear();
        map.close();
        shc = sh1 + sh2;
        hparnum << std::hex << shc;
        hparnum >> parnum;
        para_2 = parnum / 1132;
        if (cur_zone == "ZONE009.ZND") {
            para_2 -= 2;
        }
        if (cur_zone == "ZONE013.ZND" || cur_zone == "ZONE028.ZND" || cur_zone == "ZONE050.ZND") {
            para_2 -= 1;
        }
        hparnum.clear();
        std::advance(zp, 1);
        for (int mi = 0; mi < aRF.getIndivZone(*mlp).size(); mi++) {
            m_file = aGame.getStringPath() + "\\MAPS\\" + *ivmp;
            cur_map = *ivmp;
            if (find(begin(ccr), end(ccr), cur_map) == end(ccr)) {
                if (find(begin(bc), end(bc), cur_map) == end(bc)) {
                    acmap.open(m_file, ios::in | ios::out | ios::binary | ios::ate);
                    size = acmap.tellg();
                    if (find(begin(cc), end(cc), cur_map) != end(cc)) {
                        size = round((size - 544) - 1);
                    }
                    else {
                        size -= 1;
                    }
                    acmap.seekg(36, ios::beg);
                    map_loc = acmap.tellg();
                    quo_numer = acmap.get();
                    acmap.seekg(37, ios::beg);
                    map_loc = acmap.tellg();
                    if (acmap.get() > 0) {
                        quo_numer += 256;
                    }
                    for (int b = size - 35; b > (size - (38 * round(quo_numer / 40)) - 40); b -= 40) {
                        acmap.seekg(b, ios::beg);
                        ene_at = acmap.tellg();
                        ene_loc = acmap.get();
                        ene_dist = std::uniform_int_distribution<>(0, (para_2 - 1));
                        if ((ene_loc > (para_2 - 1)) == false && (cur_zone == "ZONE013.ZND" && (ene_loc == 0 || ene_loc == 1 || ene_loc == 2 || ene_loc == 3 || ene_loc == 4)) == false && (cur_zone == "ZONE015.ZND" && (ene_loc == 0)) == false) {
                            ene = ene_dist(aGen);
                            if (cur_zone == "ZONE013.ZND" && ene <= 4) {
                                ene_dist = std::uniform_int_distribution<>(5, (para_2 - 1));
                                ene = ene_dist(aGen);
                            }
                            if (cur_zone == "ZONE015.ZND" && ene == 0) {
                                ene_dist = std::uniform_int_distribution<>(1, (para_2 - 1));
                                ene = ene_dist(aGen);
                            }
                            if (cur_zone == "ZONE028.ZND" && ene == 15) {
                                picker = std::uniform_int_distribution<>(1, 2);
                                choice = picker(aGen);
                                if (choice == 1) {
                                    ene_dist = std::uniform_int_distribution<>(0, 14);
                                    ene = ene_dist(aGen);
                                }
                                else {
                                    ene_dist = std::uniform_int_distribution<>(16, (para_2 - 1));
                                    ene = ene_dist(aGen);
                                }
                            }
                            if (cur_zone == "ZONE040.ZND" && (ene == 4 || ene == 5)) {
                                picker = std::uniform_int_distribution<>(1, 2);
                                choice = picker(aGen);
                                if (choice == 1) {
                                    ene_dist = std::uniform_int_distribution<>(0, 3);
                                    ene = ene_dist(aGen);
                                }
                                else {
                                    ene_dist = std::uniform_int_distribution<>(6, (para_2 - 1));
                                    ene = ene_dist(aGen);
                                }
                            }
                            if (cur_zone == "ZONE053.ZND" && ene == 4) {
                                picker = std::uniform_int_distribution<>(1, 2);
                                choice = picker(aGen);
                                if (choice == 1) {
                                    ene_dist = std::uniform_int_distribution<>(0, 3);
                                    ene = ene_dist(aGen);
                                }
                                else {
                                    ene_dist = std::uniform_int_distribution<>(5, (para_2 - 1));
                                    ene = ene_dist(aGen);
                                }
                            }
                            if (cur_zone == "ZONE049.ZND" && ene == 6) {
                                picker = std::uniform_int_distribution<>(1, 2);
                                choice = picker(aGen);
                                if (choice == 1) {
                                    ene_dist = std::uniform_int_distribution<>(0, 5);
                                    ene = ene_dist(aGen);
                                }
                                else {
                                    ene_dist = std::uniform_int_distribution<>(7, (para_2 - 1));
                                    ene = ene_dist(aGen);
                                }
                            }
                            if (cur_zone == "ZONE054.ZND" && ene == 1) {
                                picker = std::uniform_int_distribution<>(1, 2);
                                choice = picker(aGen);
                                if (choice == 1) {
                                    ene = 0;
                                }
                                else {
                                    ene_dist = std::uniform_int_distribution<>(2, (para_2 - 1));
                                    ene = ene_dist(aGen);
                                }
                            }
                            if (cur_zone == "ZONE056.ZND" && (ene == 8 || ene == 7 || ene == 9)) {
                                picker = std::uniform_int_distribution<>(1, 2);
                                choice = picker(aGen);
                                if (choice == 1) {
                                    ene_dist = std::uniform_int_distribution<>(0, 6);
                                    ene = ene_dist(aGen);
                                }
                                else {
                                    ene_dist = std::uniform_int_distribution<>(10, (para_2 - 1));
                                    ene = ene_dist(aGen);
                                }
                            }
                            if (ene == ene_loc) {
                                if (ene_loc == 0) {
                                    ene_dist = std::uniform_int_distribution<>(1, (para_2 - 1));
                                    ene = ene_dist(aGen);
                                }
                                else if (ene_loc == (para_2 - 1)) {
                                    ene_dist = std::uniform_int_distribution<>(0, (para_2 - 2));
                                    ene = ene_dist(aGen);
                                }
                                else {
                                    picker = std::uniform_int_distribution<>(1, 2);
                                    choice = picker(aGen);
                                    if (ene_loc == 1) {
                                        if (choice == 1) {
                                            ene = 0;
                                        }
                                        else {
                                            ene_dist = std::uniform_int_distribution<>(2, (para_2 - 1));
                                            ene = ene_dist(aGen);
                                        }
                                    }
                                    else if (ene_loc == (para_2 - 2)) {
                                        if (choice == 1) {
                                            ene_dist = std::uniform_int_distribution<>(0, (para_2 - 3));
                                        }
                                        else {
                                            ene = (para_2 - 1);
                                        }
                                    }
                                    else {
                                        if (choice == 1) {
                                            ene_dist = std::uniform_int_distribution<>(0, (ene_loc - 1));
                                            ene = ene_dist(aGen);
                                        }
                                        else {
                                            ene_dist = std::uniform_int_distribution<>((ene_loc + 1), (para_2 - 1));
                                            ene = ene_dist(aGen);
                                        }
                                    }
                                }
                            }
                            ch_val = new char(ene);
                            acmap.seekp(b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                    }
                    if (aDecision == "Y") {
                        item_dist = std::uniform_int_distribution<>(323, 489);
                        for (int b = size - 9; b > ((size - (38 * round(quo_numer / 40))) - 40); b -= 40) {
                            ind_item = item_dist(aGen) - 256;
                            if (std::find(unt.begin(), unt.end(), ind_item) != unt.end()) {
                                while (std::find(unt.begin(), unt.end(), ind_item) != unt.end()) {
                                    ind_item = item_dist(aGen) - 256;
                                }
                            }
                            acmap.seekp(b + 1, ios::beg);
                            ch_val = new char(1);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            ch_val = new char(ind_item);
                            acmap.seekp(b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                        for (int b = size - 5; b > ((size - (38 * round(quo_numer / 40))) - 40); b -= 40) {
                            odds_dist = std::uniform_int_distribution<>(1, 100);
                            odds = odds_dist(aGen);
                            ch_val = new char(odds);
                            acmap.seekp(b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                    }
                    eneBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
                    acmap.close();
                }
            }
            std::advance(ivmp, 1);
        }
        std::advance(mlp, 1);
        if (i != (aRF.getMapList().size()) - 1) {
            ivm = *mlp;
            ivmp = ivm.begin();
        }
    }
    eneBat.close();
}
