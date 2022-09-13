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


using namespace std;

Enemies::Enemies() {
            
}

void Enemies::mapIterate(Reference_Files aRF, Add_Game& aGame, string aDecision) {
    list<string> z = aRF.getZones();
    list<string>::iterator zp = z.begin();
    vector<vector<string>> ml = aRF.getMapList();
    vector<vector<string>>::iterator mlp = ml.begin();
    vector<string> ivm = *mlp;
    vector<string>::iterator ivmp = ivm.begin();
    vector<string> cc = aRF.getChestCheck();
    vector<string>::iterator ccb = cc.begin();
    vector<string>::iterator cce = cc.end();

    fstream acmap;
    streampos map_fin;
    streampos map_loc;
    streampos ene_at;
    streampos dr_at;
    streampos odds_at;

    int size;
    int parnum;
    int quo_numer;
    int quo_numer_plus;
    int ene;
    int ene_loc;
    int dr_loc;
    int ind_item;
    int odds;
    int odds_loc;

    char * ch_val;
    char hhex_1[20];
    char hhex_2[20];

    std::stringstream sti;
    std::stringstream hquo_numer;
    std::stringstream hparnum;
    std::random_device ran;
    std::mt19937 gener(ran());
    std::uniform_int_distribution<> ene_dist;
    std::uniform_int_distribution<> item_dist;
    std::uniform_int_distribution<> odds_dist;
    std::stringstream h1;
    std::stringstream h2;
    
    string sh1;
    string sh2;
    string shc;
    string sqn;
    string m_file;
    string file;
    string cur_map;
    

    for (int i = 0; i < aRF.getMapList().size(); i++) {
        file = aGame.getStringPath() + "\\ZONES\\" + *zp;
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
        hparnum.clear();
        std::advance(zp, 1);
        for (int mi = 0; mi < aRF.getIndivZone(*mlp).size(); mi++) {
            m_file = aGame.getStringPath() + "\\MAPS\\" + *ivmp;
            cur_map = *ivmp;
            acmap.open(m_file, ios::in | ios::out | ios::binary | ios::ate);
            size = acmap.tellg();          
            if (find(begin(cc), end(cc), *ivmp) != end(cc)) {
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
                ene_dist = std::uniform_int_distribution<>(0, (para_2 - 1));
                ene = ene_dist(gener);
                acmap.seekg(b, ios::beg);
                ene_at = acmap.tellg();
                ene_loc = acmap.get();
                if (ene == ene_loc) {
                    while (ene == ene_loc) {
                        ene_dist = std::uniform_int_distribution<>(0, (para_2 - 1));
                        ene = ene_dist(gener);
                    }
                }
                ch_val = new char(ene);
                acmap.seekp(b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            if (aDecision == "Y") {
                for (int b = size - 9; b > ((size - (38 * round(quo_numer / 40))) - 40); b -= 40) {
                    item_dist = std::uniform_int_distribution<>(0, 511);
                    ind_item = item_dist(gener);
                    if (ind_item > 255) {
                        acmap.seekp(b + 1, ios::beg);
                        ch_val = new char(1);
                        acmap.write(ch_val, 1);
                        ind_item -= 256;
                        delete ch_val;
                    }
                    ch_val = new char(ind_item);
                    acmap.seekp(b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = size - 5; b > ((size - (38 * round(quo_numer / 40))) - 40); b -= 40) {
                    odds_dist = std::uniform_int_distribution<>(1, 100);
                    odds = odds_dist(gener);
                    ch_val = new char(odds);
                    acmap.seekp(b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
            }
            system((aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'").c_str());
            acmap.close();
            std::advance(ivmp, 1);
        }
        std::advance(mlp, 1);
        if (i != (aRF.getMapList().size()) - 1) {
            ivm = *mlp;
            ivmp = ivm.begin();
        }
    }
}
