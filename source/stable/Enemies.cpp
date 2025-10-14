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

void Enemies::mapIterate(Reference_Files aRF, Add_Game& aGame, string aDecision, std::mt19937 aGen, string nextDecision, string mainDecision, string statDecision, string balDecision) {
    list<string> z = aRF.getZones();
    list<string> ez = aRF.getEneZones();
    list<string>::iterator zp = z.begin();
    list<string>::iterator ezp = ez.begin();
    list<string>::iterator ezp_sl;
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
    vector<int> ec = aRF.getEneCounts();
    vector<int> eo = aRF.getEneOffsets();
    vector<int> ewo = aRF.getEneWepOffs();
    vector<int>::iterator ecp = ec.begin();
    vector<int>::iterator eop = eo.begin();
    vector<int>::iterator ewop = ewo.begin();
    vector<int>::iterator eop_sl;
    vector<int>::iterator ewop_sl;
    vector<int>::iterator ecp_sl;
    vector<string> finishedMaps;

    string sh1;
    string sh2;
    string shc;
    string sqn;
    string m_file;
    string file;
    string sla_file;
    string cur_map;
    string cur_zone;
    string cur_slave;
    string sCmdPath;
    string tool = aRF.getTool();
    string s_rand_hp;
    string s_rand_dpm;
    string s_rand_dpm_1;
    string s_rand_dpm_2;
    string s_rand_dp;
    string s_rand_dp_1;
    string s_rand_dp_2;
    string s_rand_hp1;
    string s_rand_hp2;
    string s_rand_mp;
    string s_rand_mp1;
    string s_rand_mp2;
    string s1;
    string s2;
    string s3;
    string s4;

    //wstring wToolPath = wstring(tool.begin(), tool.end());
    //wstring wCmdPath;

    //LPCWSTR toolPath = wToolPath.c_str();

    //LPWSTR cmdPath;

    fstream acmap;
    fstream enzon;
    fstream sla_enzon;
    fstream encnt;
    streampos map_fin;
    streampos map_loc;
    streampos stat_loc;
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
    int ene_count;
    int cho_zone;
    int wep_pos;
    int wep_pos_sl;
    int master_wep;
    int slave_wep;
    int slave_eff;
    int slave_pos;
    int eiz_sl;
    int slave_ene;
    int ene_off;
    int coin;
    int to_ass;
    int to_ass2;
    int stat;
    int int_rand_hp;
    int int_rand_mp;
    int int_rand_dpm;
    int ppm;
    int pp;
    int gem_count;
    int ene_hp_stat;
    int loop_diff;
    int start_point;

    char * ch_val;
    char hhex_1[20];
    char hhex_2[20];
    char rand_hp[20];
    char rand_mp[20];
    char rand_dpm[20];
    char rand_dp[20];

    bool wep_match;

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
    std::uniform_int_distribution<> ene_zone_dist;
    std::uniform_int_distribution<> eiz_dist;
    std::uniform_int_distribution<> dist_1;
    std::uniform_int_distribution<> dist_2;
    std::uniform_int_distribution<> dist_3;
    std::uniform_int_distribution<> dist_4;
    std::uniform_int_distribution<> dist_5;
    std::uniform_int_distribution<> dist_6;
    std::uniform_int_distribution<> dist_7;
    std::uniform_int_distribution<> dist_8;
    std::uniform_int_distribution<> dist_9;
    std::uniform_int_distribution<> dist_10;
    std::uniform_int_distribution<> dist_11;
    std::uniform_int_distribution<> dist_12;
    std::uniform_int_distribution<> dist_13;
    std::uniform_int_distribution<> dist_14;
    std::uniform_int_distribution<> dist_15;
    std::uniform_int_distribution<> dist_16;
    std::uniform_int_distribution<> dist_17;
    std::uniform_int_distribution<> dist_18;
    std::uniform_int_distribution<> dist_19;
    std::uniform_int_distribution<> dist_20;
    std::uniform_int_distribution<> dist_21;
    std::uniform_int_distribution<> dist_22;
    std::uniform_int_distribution<> dist_23;
    std::uniform_int_distribution<> dist_24;
    std::uniform_int_distribution<> dist_25;
    std::uniform_int_distribution<> dist_26;
    std::uniform_int_distribution<> dist_27;
    std::uniform_int_distribution<> dist_28;
    std::uniform_int_distribution<> dist_29;
    std::uniform_int_distribution<> dist_30;
    std::uniform_int_distribution<> dist_31;
    std::uniform_int_distribution<> dist_32;
    std::uniform_int_distribution<> dist_33;
    std::uniform_int_distribution<> dist_34;
    std::uniform_int_distribution<> dist_35;
    std::uniform_int_distribution<> dist_36;
    std::uniform_int_distribution<> dist_37;
    std::uniform_int_distribution<> dist_38;
    std::uniform_int_distribution<> dist_39;
    std::uniform_int_distribution<> dist_40;
    std::uniform_int_distribution<> dist_41;
    std::uniform_int_distribution<> dist_42;
    std::uniform_int_distribution<> dist_43;
    std::uniform_int_distribution<> dist_44;
    std::uniform_int_distribution<> dist_45;
    std::uniform_int_distribution<> dist_46;
    std::uniform_int_distribution<> dist_47;
    std::uniform_int_distribution<> dist_48;
    std::uniform_int_distribution<> dist_49;
    std::uniform_int_distribution<> dist_50;
    std::uniform_int_distribution<> dist_51;
    std::uniform_int_distribution<> dist_52;
    std::uniform_int_distribution<> dist_53;
    std::uniform_int_distribution<> dist_54;
    std::uniform_int_distribution<> dist_55;
    std::uniform_int_distribution<> dist_56;
    std::uniform_int_distribution<> dist_57;
    std::uniform_int_distribution<> dist_58;
    std::uniform_int_distribution<> dist_59;
    std::uniform_int_distribution<> dist_60;
    std::uniform_int_distribution<> dist_61;
    std::uniform_int_distribution<> dist_62;
    std::uniform_int_distribution<> dist_63;
    std::uniform_int_distribution<> dist_64;
    std::uniform_int_distribution<> dist_65;
    std::uniform_int_distribution<> dist_66;
    std::uniform_int_distribution<> dist_67;
    std::uniform_int_distribution<> dist_68;
    std::uniform_int_distribution<> dist_69;
    std::uniform_int_distribution<> dist_70;
    std::uniform_int_distribution<> dist_71;
    std::uniform_int_distribution<> dist_72;
    std::uniform_int_distribution<> dist_73;
    std::uniform_int_distribution<> dist_74;
    std::uniform_int_distribution<> dist_75;
    std::uniform_int_distribution<> dist_76;
    std::uniform_int_distribution<> dist_77;
    std::uniform_int_distribution<> dist_78;
    std::uniform_int_distribution<> dist_79;
    std::uniform_int_distribution<> dist_80;
    std::uniform_int_distribution<> dist_81;
    std::uniform_int_distribution<> dist_82;
    std::uniform_int_distribution<> dist_83;
    std::uniform_int_distribution<> dist_84;
    std::uniform_int_distribution<> dist_85;
    std::uniform_int_distribution<> dist_86;
    std::uniform_int_distribution<> dist_87;
    std::uniform_int_distribution<> dist_88;
    std::uniform_int_distribution<> dist_89;
    std::uniform_int_distribution<> dist_90;
    std::uniform_int_distribution<> dist_91;
    std::uniform_int_distribution<> dist_92;
    std::uniform_int_distribution<> dist_93;
    std::uniform_int_distribution<> dist_94;
    std::uniform_int_distribution<> dist_95;
    std::uniform_int_distribution<> dist_96;
    std::uniform_int_distribution<> dist_97;
    std::uniform_int_distribution<> dist_98;
    std::uniform_int_distribution<> dist_99;
    std::uniform_int_distribution<> dist_100;
    std::uniform_int_distribution<> dist_101;
    std::uniform_int_distribution<> dist_102;
    std::uniform_int_distribution<> dist_103;
    std::uniform_int_distribution<> dist_104;
    std::uniform_int_distribution<> dist_105;
    std::uniform_int_distribution<> dist_106;
    std::uniform_int_distribution<> dist_107;
    std::uniform_int_distribution<> dist_108;
    std::uniform_int_distribution<> dist_109;
    std::uniform_int_distribution<> dist_110;
    std::uniform_int_distribution<> dist_111;
    std::uniform_int_distribution<> dist_112;
    std::uniform_int_distribution<> dist_113;
    std::uniform_int_distribution<> dist_114;
    std::uniform_int_distribution<> dist_115;
    std::uniform_int_distribution<> dist_116;
    std::uniform_int_distribution<> dist_117;
    std::uniform_int_distribution<> dist_118;
    std::uniform_int_distribution<> dist_119;
    std::uniform_int_distribution<> dist_120;
    std::uniform_int_distribution<> dist_121;
    std::uniform_int_distribution<> dist_122;
    std::uniform_int_distribution<> dist_123;
    std::uniform_int_distribution<> dist_124;
    std::uniform_int_distribution<> dist_125;
    std::uniform_int_distribution<> dist_126;
    std::uniform_int_distribution<> dist_127;
    std::uniform_int_distribution<> dist_128;
    std::uniform_int_distribution<> dist_129;
    std::uniform_int_distribution<> dist_130;
    std::uniform_int_distribution<> dist_131;
    std::uniform_int_distribution<> dist_132;
    std::uniform_int_distribution<> dist_133;
    std::uniform_int_distribution<> dist_134;
    std::uniform_int_distribution<> dist_135;
    std::uniform_int_distribution<> dist_136;
    std::uniform_int_distribution<> dist_137;
    std::uniform_int_distribution<> dist_138;
    std::uniform_int_distribution<> dist_139;
    std::uniform_int_distribution<> dist_140;
    std::uniform_int_distribution<> dist_141;
    std::uniform_int_distribution<> dist_142;
    std::uniform_int_distribution<> dist_143;
    std::uniform_int_distribution<> dist_144;
    std::uniform_int_distribution<> dist_145;
    std::uniform_int_distribution<> dist_146;
    std::uniform_int_distribution<> dist_147;
    std::uniform_int_distribution<> dist_148;
    std::uniform_int_distribution<> dist_149;
    std::uniform_int_distribution<> dist_150;
    std::uniform_int_distribution<> dist_151;
    std::uniform_int_distribution<> dist_152;
    std::uniform_int_distribution<> dist_153;
    std::uniform_int_distribution<> dist_154;
    std::uniform_int_distribution<> dist_155;
    std::uniform_int_distribution<> dist_156;
    std::stringstream h1;
    std::stringstream h2;
    std::stringstream ss_rand_hp;
    std::stringstream ss_rand_mp;
    std::stringstream ss_rand_dpm;
    std::stringstream ss_rand_dp;
    std::stringstream hs_rand_hp;
    std::stringstream hs_rand_mp;
    std::stringstream hs_rand_dpm;
    std::stringstream hs_rand_dp;
    std::stringstream fin_rand_hp;
    std::stringstream fin_rand_mp;
    std::stringstream rand_dpm_fin;
    std::stringstream rand_dp_fin;


    //std::ofstream mapoutput;
    //mapoutput.open("rooms.txt", std::ios_base::app);

    //STARTUPINFO info = { sizeof(info) };
    //PROCESS_INFORMATION processInfo;
    
    std::ofstream eneBat;
    eneBat.open("eneCmd.cmd", std::ios::trunc);
    eneBat << ("cd " + aGame.getStringPath() + " \n");
        
    if (mainDecision == "Y" || aDecision == "Y") {
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
                        if (mainDecision == "Y") {
                            for (int b = size - 35; b > (size - (38 * round(quo_numer / 40)) - 40); b -= 40) {
                                acmap.seekg(b, ios::beg);
                                ene_at = acmap.tellg();
                                ene_loc = acmap.get();
                                ene_dist = std::uniform_int_distribution<>(0, (para_2 - 1));
                                if ((ene_loc > (para_2 - 1)) == false && (cur_zone == "ZONE013.ZND" && (ene_loc < 5)) == false && (cur_zone == "ZONE015.ZND" && (ene_loc == 0)) == false && (cur_zone == "ZONE051.ZND" && (ene_loc > 2 && ene_loc < 21)) == false) {
                                    ene = ene_loc;
                                    while (ene == ene_loc) {
                                        ene = ene_dist(aGen);
                                        if (cur_map == "MAP016.MPD" && (ene == 14 || ene == 15 || ene == 3)) {
                                            picker = std::uniform_int_distribution<>(1, 3);
                                            choice = picker(aGen);
                                            if (choice == 1) {
                                                ene_dist = std::uniform_int_distribution<>(0, 2);
                                                ene = ene_dist(aGen);
                                            }
                                            else if (choice == 2) {
                                                ene_dist = std::uniform_int_distribution<>(4, 13);
                                                ene = ene_dist(aGen);
                                            }
                                            else {
                                                ene_dist = std::uniform_int_distribution<>(16, (para_2 - 1));
                                                ene = ene_dist(aGen);
                                            }
                                        }
                                        else if (cur_map == "MAP117.MPD" && (ene >= 9 || ene <= 13)) {
                                            picker = std::uniform_int_distribution<>(1, 2);
                                            choice = picker(aGen);
                                            if (choice == 1) {
                                                ene_dist = std::uniform_int_distribution<>(0, 8);
                                                ene = ene_dist(aGen);
                                            }
                                            else {
                                                ene_dist = std::uniform_int_distribution<>(14, (para_2 - 1));
                                                ene = ene_dist(aGen);
                                            }
                                        }
                                        else if (cur_map == "MAP166.MPD" && ene == 24) {
                                            picker = std::uniform_int_distribution<>(1, 2);
                                            choice = picker(aGen);
                                            if (choice == 1) {
                                                ene_dist = std::uniform_int_distribution<>(0, 12);
                                                ene = ene_dist(aGen);
                                            }
                                            else {
                                                ene_dist = std::uniform_int_distribution<>(14, (para_2 - 1));
                                                ene = ene_dist(aGen);
                                            }
                                        }
                                        else if ((cur_map == "MAP031.MPD" || cur_map == "MAP036.MPD") && (ene >= 5 && ene <= 11)) {
                                            ene_dist = std::uniform_int_distribution<>(12, (para_2 - 1));
                                            ene = ene_dist(aGen);
                                        }
                                        /*else if (cur_map == "MAP267.MPD" && ene == 0) {
                                            ene_dist = std::uniform_int_distribution<>(1, (para_2 - 1));
                                            ene = ene_dist(aGen);
                                        }*/
                                        if (cur_zone == "ZONE013.ZND" && ene <= 4) {
                                            ene_dist = std::uniform_int_distribution<>(5, (para_2 - 1));
                                            ene = ene_dist(aGen);
                                        }
                                        else if (cur_zone == "ZONE015.ZND" && ene == 0) {
                                            ene_dist = std::uniform_int_distribution<>(1, (para_2 - 1));
                                            ene = ene_dist(aGen);
                                        }
                                        else if (cur_zone == "ZONE051.ZND" && (ene > 2 && ene < 21)) {
                                            picker = std::uniform_int_distribution<>(1, 2);
                                            choice = picker(aGen);
                                            if (choice == 1) {
                                                ene_dist = std::uniform_int_distribution<>(0, 2);
                                            }
                                            else {
                                                ene_dist = std::uniform_int_distribution<>(21, (para_2 - 1));
                                            }
                                            ene = ene_dist(aGen);
                                        }
                                        else if (cur_zone == "ZONE028.ZND" && ene == 15) {
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
                                        else if (cur_zone == "ZONE040.ZND" && (ene == 4 || ene == 5)) {
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
                                        else if (cur_zone == "ZONE053.ZND" && ene == 4) {
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
                                        else if (cur_zone == "ZONE049.ZND" && ene == 6) {
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
                                        else if (cur_zone == "ZONE054.ZND" && ene == 1) {
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
                                        else if (cur_zone == "ZONE056.ZND" && (ene == 8 || ene == 7 || ene == 9)) {
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
                                        ch_val = new char(ene);
                                        acmap.seekp(b, ios::beg);
                                        acmap.write(ch_val, 1);
                                        delete ch_val;
                                    }
                                }
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
    }
    if (nextDecision == "Y") {
        for (int i = 0; i < aRF.getEneZones().size(); i++) {
            file = aGame.getStringPath() + "\\ZONES\\" + *ezp;
            cur_zone = *ezp;
            enzon.open(file, ios::in | ios::out | ios::binary | ios::ate);
            ene_count = *ecp;
            ene_off = *eop;
            wep_pos = *ewop;
            if (cur_zone == "ZONE011.ZND" || cur_zone == "ZONE012.ZND" || cur_zone == "ZONE013.ZND" || cur_zone == "ZONE017.ZND" || cur_zone == "ZONE040.ZND" || cur_zone == "ZONE055.ZND") {
                start_point = 1;
            }
            else if (cur_zone == "ZONE014.ZND" || cur_zone == "ZONE048.ZND" || cur_zone == "ZONE054.ZND") {
                start_point = 2;
            }
            else if (cur_zone == "ZONE051.ZND" || cur_zone == "ZONE053.ZND") {
                start_point = 3;
            }
            wep_pos += (1124 * start_point);
            ene_off += (8 * start_point);
            for (int e = start_point; e < ene_count; e++) {
                if (cur_zone != "ZONE031.ZND" && cur_zone != "ZONE025.ZND" && cur_zone != "ZONE016.ZND" && cur_zone != "ZONE022.ZND" && cur_zone != "ZONE041.ZND") {
                    if (cur_zone == "ZONE009.ZND" && (e == 6 || e == 8)) {
                        e += 1;
                        wep_pos += 1124;
                        ene_off += 8;
                    }
                    else if (cur_zone == "ZONE015.ZND" && e == 11) {
                        e = 12;
                        wep_pos += 1124;
                        ene_off += 8;
                    }
                    else if (cur_zone == "ZONE028.ZND" && (e == 4 || e == 5 || e == 11 || e == 12 || e == 14 || e == 16 || e == 17 || e == 19 || e == 20 || e == 21 || e == 24)) {
                        if ((e == 4 || e == 16 || e == 19 || e == 20)) {
                            e += 2;
                            wep_pos += (1124 * 2);
                            ene_off += 16;
                        }
                        else {
                            e += 1;
                            wep_pos += 1124;
                            ene_off += 8;
                        }
                    }
                    else if (cur_zone == "ZONE050.ZND" && (e == 0 || e == 3 || e == 5 || e == 6 || e == 9)) {
                        if (e == 5) {
                            e += 2;
                            wep_pos += (1124 * 2);
                            ene_off += 16;
                        }
                        else {
                            e += 1;
                            wep_pos += 1124;
                            ene_off += 8;
                        }
                    }
                    else if (cur_zone == "ZONE032.ZND" && (e == 5 || e == 6 || e == 7 || e == 25 || e == 16 || e == 12 || e == 17 || e == 24 || e == 28)) {
                        if (e == 5) {
                            e += 3;
                            wep_pos += (1124 * 3);
                            ene_off += 24;
                        }
                        else if (e == 16 || e == 24) {
                            e += 2;
                            wep_pos += (1124 * 2);
                            ene_off += 16;
                        }
                        else {
                            e += 1;
                            wep_pos += 1124;
                            ene_off += 8;
                        }
                    }
                    else if ((cur_zone == "ZONE048.ZND" && (e == 3 || e == 5 || e == 23)) || (cur_zone == "ZONE056.ZND" && (e == 0 || e == 9))) {
                        e += 1;
                        wep_pos += 1124;
                        ene_off += 8;
                    }
                    else if (cur_zone == "ZONE049.ZND" && (e == 0 || e == 1 || e == 4 || e == 5 || e == 6 || e == 10 || e == 11 || e == 12)) {
                        if (e == 1 || e == 5 || e == 11) {
                            e += 2;
                            wep_pos += (1124 * 2);
                            ene_off += 16;
                        }
                        else if (e == 10 || e == 4 || e == 0) {
                            e += 3;
                            wep_pos += (1124 * 3);
                            ene_off += 24;
                        }
                        else {
                            e = 1;
                            wep_pos += 1124;
                            ene_off += 8;
                        }
                    }
                    else if (cur_zone == "ZONE024.ZND" && (e == 0 || e == 1 || e == 4 || e == 6 || e == 8)) {
                        if (e == 0) {
                            e += 2;
                            wep_pos += (1124 * 2);
                            ene_off += 16;
                        }
                        else if (e == 8) {
                            ene_count = 9;
                        }
                        else {
                            e += 1;
                            wep_pos += 1124;
                            ene_off += 8;
                        }
                    }
                    enzon.seekg(wep_pos, ios::beg);
                    enzon.tellg();
                    master_wep = enzon.get();
                    wep_match = false;
                    while (wep_match == false) {
                        sla_enzon.close();
                        ezp_sl = ez.begin();
                        ewop_sl = ewo.begin();
                        ene_zone_dist = std::uniform_int_distribution<>(0, ez.size() - 1);
                        cho_zone = ene_zone_dist(aGen);
                        std::advance(ezp_sl, cho_zone);
                        std::advance(ewop_sl, cho_zone);
                        sla_file = aGame.getStringPath() + "\\BACKUP\\" + *ezp_sl;
                        cur_slave = *ezp_sl;
                        sla_enzon.open(sla_file, ios::in | ios::out | ios::binary | ios::ate);
                        ecp_sl = ec.begin();
                        std::advance(ecp_sl, cho_zone);
                        if (cur_slave == "ZONE013.ZND") {
                            eiz_dist = std::uniform_int_distribution<>(1, *ecp_sl - 1);
                        }
                        else if (cur_slave == "ZONE011.ZND") {
                            eiz_dist = std::uniform_int_distribution<>(1, *ecp_sl - 2);
                        }
                        else if (cur_slave == "ZONE030.ZND") {
                            eiz_dist = std::uniform_int_distribution<>(1, 2);
                            coin = eiz_dist(aGen);
                            if (coin == 1) {
                                eiz_dist = std::uniform_int_distribution<>(0, 0);
                            }
                            else {
                                eiz_dist = std::uniform_int_distribution<>(2, *ecp_sl - 1);
                            }
                        }
                        else if (cur_slave == "ZONE054.ZND") {
                            eiz_dist = std::uniform_int_distribution<>(1, 2);
                            coin = eiz_dist(aGen);
                            if (coin == 1) {
                                eiz_dist = std::uniform_int_distribution<>(0, 1);
                            }
                            else {
                                eiz_dist = std::uniform_int_distribution<>(4, *ecp_sl - 1);
                            }
                        }
                        else if (cur_slave == "ZONE050.ZND" && cur_zone == "ZONE032.ZND") {
                            eiz_dist = std::uniform_int_distribution<>(1, 2);
                            coin = eiz_dist(aGen);
                            if (coin == 1) {
                                eiz_dist = std::uniform_int_distribution<>(0, 2);
                            }
                            else {
                                eiz_dist = std::uniform_int_distribution<>(4, *ecp_sl - 1);
                            }
                        }
                        else if (cur_slave == "ZONE048.ZND") {
                            eiz_dist = std::uniform_int_distribution<>(0, *ecp_sl - 2);
                        }
                        else {
                            eiz_dist = std::uniform_int_distribution<>(0, *ecp_sl - 1);
                        }
                        eiz_sl = eiz_dist(aGen);
                        if (cur_slave == "ZONE012.ZND") {
                            eiz_sl = 0;
                        }
                        wep_pos_sl = *ewop_sl + (1124 * eiz_sl);
                        sla_enzon.seekg(wep_pos_sl, ios::beg);
                        sla_enzon.tellg();
                        slave_wep = sla_enzon.get();
                        if (slave_wep == master_wep) {
                            wep_match = true;
                        }
                    }
                    sla_enzon.seekg(wep_pos_sl - 54, ios::beg);
                    sla_enzon.tellg();
                    slave_eff = sla_enzon.get();
                    ch_val = new char(slave_eff);
                    enzon.seekp(wep_pos - 54, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    eop_sl = eo.begin();
                    std::advance(eop_sl, cho_zone);
                    slave_pos = *eop_sl + (8 * eiz_sl);
                    for (int off = 0; off < 8; off++) {
                        sla_enzon.seekg(slave_pos, ios::beg);
                        sla_enzon.tellg();
                        slave_ene = sla_enzon.get();
                        ch_val = new char(slave_ene);
                        enzon.seekp(ene_off, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        slave_pos += 1;
                        ene_off += 1;
                    }
                    sla_enzon.close();
                    wep_pos += 1124;
                }
            }
            enzon.close();
            std::advance(ecp, 1);
            std::advance(eop, 1);
            std::advance(ewop, 1);
            std::advance(ezp, 1);
            eneBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_zone + " '" + file + "'") << std::endl;
        }
    }
    if (statDecision == "Y") {
        ecp = ec.begin();
        ezp = ez.begin();
        ewop = ewo.begin();
        if (balDecision == "N") {
            dist_1 = std::uniform_int_distribution<>(1, 999);
            dist_2 = std::uniform_int_distribution<>(1, 999);
            dist_3 = std::uniform_int_distribution<>(1, 255);
            dist_4 = std::uniform_int_distribution<>(1, 255);
            dist_5 = std::uniform_int_distribution<>(1, 255);
            dist_6 = std::uniform_int_distribution<>(1, 255);
            dist_7 = std::uniform_int_distribution<>(1, 255);
            dist_9 = std::uniform_int_distribution<>(1, 255);
            dist_10 = std::uniform_int_distribution<>(1, 255);
            dist_11 = std::uniform_int_distribution<>(1, 255);
            dist_12 = std::uniform_int_distribution<>(1, 255);
            dist_13 = std::uniform_int_distribution<>(41, 327);
            dist_15 = std::uniform_int_distribution<>(100, 250);
            dist_17 = std::uniform_int_distribution<>(1, 255);
            dist_18 = std::uniform_int_distribution<>(1, 3);
            dist_19 = std::uniform_int_distribution<>(1, 4);
            dist_21 = std::uniform_int_distribution<>(1, 255);
            dist_22 = std::uniform_int_distribution<>(1, 255);
            dist_23 = std::uniform_int_distribution<>(1, 255);
            dist_24 = std::uniform_int_distribution<>(0, 255);
            dist_25 = std::uniform_int_distribution<>(0, 255);
            dist_26 = std::uniform_int_distribution<>(0, 255);
            dist_27 = std::uniform_int_distribution<>(0, 255);
            dist_28 = std::uniform_int_distribution<>(0, 255);
            dist_29 = std::uniform_int_distribution<>(0, 255);
            dist_30 = std::uniform_int_distribution<>(0, 255);
            dist_31 = std::uniform_int_distribution<>(0, 255);
            dist_32 = std::uniform_int_distribution<>(0, 255);
            dist_33 = std::uniform_int_distribution<>(0, 255);
            dist_34 = std::uniform_int_distribution<>(0, 255);
            dist_35 = std::uniform_int_distribution<>(0, 255);
            dist_36 = std::uniform_int_distribution<>(0, 255);
            dist_38 = std::uniform_int_distribution<>(0, 255);
            dist_39 = std::uniform_int_distribution<>(0, 255);
            dist_40 = std::uniform_int_distribution<>(0, 255);
            dist_41 = std::uniform_int_distribution<>(0, 255);
            dist_42 = std::uniform_int_distribution<>(0, 255);
            dist_43 = std::uniform_int_distribution<>(0, 255);
            dist_44 = std::uniform_int_distribution<>(5, 51);
            dist_45 = std::uniform_int_distribution<>(0, 255);
            dist_46 = std::uniform_int_distribution<>(0, 255);
            dist_47 = std::uniform_int_distribution<>(0, 255);
            dist_48 = std::uniform_int_distribution<>(0, 255);
            dist_49 = std::uniform_int_distribution<>(0, 255);
            dist_50 = std::uniform_int_distribution<>(0, 255);
            dist_51 = std::uniform_int_distribution<>(0, 255);
            dist_52 = std::uniform_int_distribution<>(0, 255);
            dist_53 = std::uniform_int_distribution<>(0, 255);
            dist_54 = std::uniform_int_distribution<>(0, 255);
            dist_55 = std::uniform_int_distribution<>(0, 255);
            dist_56 = std::uniform_int_distribution<>(0, 255);
            dist_57 = std::uniform_int_distribution<>(0, 255);
            dist_58 = std::uniform_int_distribution<>(0, 255);
            dist_59 = std::uniform_int_distribution<>(0, 255);
            dist_60 = std::uniform_int_distribution<>(0, 255);
            dist_61 = std::uniform_int_distribution<>(3, 7);
            dist_62 = std::uniform_int_distribution<>(0, 255);
            dist_63 = std::uniform_int_distribution<>(127, 142);
            dist_64 = std::uniform_int_distribution<>(0, 255);
            dist_65 = std::uniform_int_distribution<>(0, 255);
            dist_66 = std::uniform_int_distribution<>(0, 255);
            dist_67 = std::uniform_int_distribution<>(41, 327);
            dist_69 = std::uniform_int_distribution<>(100, 250);
            dist_71 = std::uniform_int_distribution<>(0, 255);
            dist_72 = std::uniform_int_distribution<>(0, 255);
            dist_73 = std::uniform_int_distribution<>(0, 255);
            dist_74 = std::uniform_int_distribution<>(0, 255);
            dist_75 = std::uniform_int_distribution<>(0, 255);
            dist_76 = std::uniform_int_distribution<>(0, 255);
            dist_77 = std::uniform_int_distribution<>(0, 255);
            dist_78 = std::uniform_int_distribution<>(0, 255);
            dist_79 = std::uniform_int_distribution<>(0, 255);
            dist_80 = std::uniform_int_distribution<>(0, 255);
            dist_81 = std::uniform_int_distribution<>(1, 7);
            dist_82 = std::uniform_int_distribution<>(0, 255);
            dist_83 = std::uniform_int_distribution<>(223, 253);
            dist_84 = std::uniform_int_distribution<>(0, 255);
            dist_85 = std::uniform_int_distribution<>(0, 255);
            dist_86 = std::uniform_int_distribution<>(0, 255);
            dist_87 = std::uniform_int_distribution<>(0, 255);
            dist_88 = std::uniform_int_distribution<>(0, 255);
            dist_89 = std::uniform_int_distribution<>(0, 255);
            dist_90 = std::uniform_int_distribution<>(0, 255);
            dist_91 = std::uniform_int_distribution<>(0, 255);
            dist_92 = std::uniform_int_distribution<>(0, 255);
            dist_93 = std::uniform_int_distribution<>(0, 255);
            dist_94 = std::uniform_int_distribution<>(0, 255);
            dist_95 = std::uniform_int_distribution<>(0, 255);
            dist_96 = std::uniform_int_distribution<>(0, 255);
            dist_97 = std::uniform_int_distribution<>(0, 255);
            dist_98 = std::uniform_int_distribution<>(0, 255);
            dist_99 = std::uniform_int_distribution<>(0, 255);
            dist_100 = std::uniform_int_distribution<>(0, 255);
            dist_101 = std::uniform_int_distribution<>(0, 255);
            dist_102 = std::uniform_int_distribution<>(0, 255);
            dist_103 = std::uniform_int_distribution<>(0, 255);
            dist_105 = std::uniform_int_distribution<>(0, 255);
            dist_106 = std::uniform_int_distribution<>(0, 255);
            dist_107 = std::uniform_int_distribution<>(0, 255);
            dist_108 = std::uniform_int_distribution<>(0, 255);
            dist_109 = std::uniform_int_distribution<>(0, 255);
            dist_110 = std::uniform_int_distribution<>(0, 255);
            dist_111 = std::uniform_int_distribution<>(0, 255);
            dist_112 = std::uniform_int_distribution<>(0, 255);
            dist_113 = std::uniform_int_distribution<>(0, 255);
            dist_114 = std::uniform_int_distribution<>(0, 255);
            dist_115 = std::uniform_int_distribution<>(0, 255);
            dist_116 = std::uniform_int_distribution<>(0, 255);
            dist_117 = std::uniform_int_distribution<>(191, 206);
            dist_118 = std::uniform_int_distribution<>(0, 255);
            dist_119 = std::uniform_int_distribution<>(0, 255);
            dist_120 = std::uniform_int_distribution<>(0, 255);
            dist_121 = std::uniform_int_distribution<>(0, 255);
            dist_122 = std::uniform_int_distribution<>(0, 255);
            dist_123 = std::uniform_int_distribution<>(0, 255);
            dist_124 = std::uniform_int_distribution<>(0, 255);
            dist_125 = std::uniform_int_distribution<>(0, 255);
            dist_126 = std::uniform_int_distribution<>(0, 255);
            dist_127 = std::uniform_int_distribution<>(0, 255);
            dist_128 = std::uniform_int_distribution<>(0, 255);
            dist_129 = std::uniform_int_distribution<>(0, 255);
            dist_130 = std::uniform_int_distribution<>(0, 255);
            dist_131 = std::uniform_int_distribution<>(0, 255);
            dist_132 = std::uniform_int_distribution<>(0, 255);
            dist_133 = std::uniform_int_distribution<>(0, 255);
            dist_134 = std::uniform_int_distribution<>(0, 255);
            dist_134 = std::uniform_int_distribution<>(0, 255);
            dist_135 = std::uniform_int_distribution<>(0, 255);
            dist_136 = std::uniform_int_distribution<>(0, 255);
            dist_137 = std::uniform_int_distribution<>(143, 158);
            dist_138 = std::uniform_int_distribution<>(159, 174);
            dist_139 = std::uniform_int_distribution<>(175, 190);
            dist_140 = std::uniform_int_distribution<>(0, 255);
            dist_141 = std::uniform_int_distribution<>(0, 255);
            dist_142 = std::uniform_int_distribution<>(0, 255);
            dist_143 = std::uniform_int_distribution<>(0, 255);
            dist_144 = std::uniform_int_distribution<>(0, 255);
            dist_145 = std::uniform_int_distribution<>(0, 255);
            dist_146 = std::uniform_int_distribution<>(0, 255);
            dist_147 = std::uniform_int_distribution<>(0, 255);
        }
        for (int i = 0; i < aRF.getEneZones().size(); i++) {
            file = aGame.getStringPath() + "\\ZONES\\" + *ezp;
            cur_zone = *ezp;
            enzon.open(file, ios::in | ios::out | ios::binary | ios::ate);
            ene_count = *ecp;
            wep_pos = *ewop;
            if (balDecision == "Y") {
                //bla agl
                dist_11 = std::uniform_int_distribution<>(1, 2);
                //bla dp
                dist_13 = std::uniform_int_distribution<>(41, 327);
                //bla pp
                dist_15 = std::uniform_int_distribution<>(100, 250);
                //bla cost
                dist_17 = std::uniform_int_distribution<>(1, 255);
                //bla dmg type
                dist_18 = std::uniform_int_distribution<>(1, 3);
                //dmg stat
                dist_19 = std::uniform_int_distribution<>(1, 4);
                //wep gem name
                dist_44 = std::uniform_int_distribution<>(5, 51);
                //chance
                dist_62 = std::uniform_int_distribution<>(0, 255);
                //shi name
                dist_63 = std::uniform_int_distribution<>(127, 142);
                //shi dp
                dist_67 = std::uniform_int_distribution<>(41, 327);
                //shi pp
                dist_69 = std::uniform_int_distribution<>(100, 250);
                //armour cha
                dist_82 = std::uniform_int_distribution<>(0, 255);
                //acc name
                dist_83 = std::uniform_int_distribution<>(223, 253);
                //acc cha
                dist_103 = std::uniform_int_distribution<>(0, 255);
                //arms
                dist_117 = std::uniform_int_distribution<>(191, 206);
                //head
                dist_137 = std::uniform_int_distribution<>(143, 158);
                //body
                dist_138 = std::uniform_int_distribution<>(159, 174);
                //legs
                dist_139 = std::uniform_int_distribution<>(175, 190);
                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                    //hp
                    dist_1 = std::uniform_int_distribution<>(1, 480);
                    //mp
                    dist_2 = std::uniform_int_distribution<>(1, 130);
                    //str
                    dist_3 = std::uniform_int_distribution<>(1, 112);
                    //int
                    dist_4 = std::uniform_int_distribution<>(1, 127);
                    //agl
                    dist_5 = std::uniform_int_distribution<>(1, 132);
                    //carry
                    dist_6 = std::uniform_int_distribution<>(1, 14);
                    //run
                    dist_7 = std::uniform_int_distribution<>(1, 28);
                    //bla str
                    dist_9 = std::uniform_int_distribution<>(1, 14);
                    //bla int
                    dist_10 = std::uniform_int_distribution<>(1, 4);
                    
                    //gri str and int
                    dist_38 = std::uniform_int_distribution<>(0, 12);
                    dist_39 = std::uniform_int_distribution<>(0, 12);
                    //gri agi
                    dist_40 = std::uniform_int_distribution<>(253, 255);

                    //gri bl/ed/pi
                    dist_41 = std::uniform_int_distribution<>(0, 13);
                    dist_42 = std::uniform_int_distribution<>(0, 13);
                    dist_43 = std::uniform_int_distribution<>(0, 13);

                    //gem str/int/agi
                    dist_45 = std::uniform_int_distribution<>(0, 5);
                    dist_46 = std::uniform_int_distribution<>(0, 5);
                    dist_47 = std::uniform_int_distribution<>(0, 5);

                    //material             
                    dist_61 = std::uniform_int_distribution<>(3, 4);
                    
                    //shi str
                    dist_64 = std::uniform_int_distribution<>(4, 9);
                    //shi int
                    dist_65 = std::uniform_int_distribution<>(4, 9);
                    //shi agi
                    dist_66 = std::uniform_int_distribution<>(253, 255);

                    //shi blu                   
                    dist_71 = std::uniform_int_distribution<>(0, 10);
                    //shi edg
                    dist_72 = std::uniform_int_distribution<>(0, 10);
                    //shi pie
                    dist_73 = std::uniform_int_distribution<>(0, 10);

                    //armour mat
                    dist_81 = std::uniform_int_distribution<>(1, 4);

                    //acc str/int/agi
                    dist_84 = std::uniform_int_distribution<>(1, 3);
                    dist_85 = std::uniform_int_distribution<>(1, 3);
                    dist_86 = std::uniform_int_distribution<>(1, 3);

                    //body agl
                    dist_105 = std::uniform_int_distribution<>(0, 251);
                    //body evd
                    dist_106 = std::uniform_int_distribution<>(0, 255);

                    
                    //body arm str and int
                    dist_118 = std::uniform_int_distribution<>(1, 13);
                    dist_119 = std::uniform_int_distribution<>(1, 13);

                    //arm blu edg pie
                    dist_121 = std::uniform_int_distribution<>(0, 5);
                    dist_122 = std::uniform_int_distribution<>(0, 5);
                    dist_123 = std::uniform_int_distribution<>(0, 5);

                    //other arm str and int
                    dist_140 = std::uniform_int_distribution<>(1, 13);
                    dist_141 = std::uniform_int_distribution<>(1, 13);

                    //shi class
                    dist_142 = std::uniform_int_distribution<>(251, 255);
                    dist_143 = std::uniform_int_distribution<>(251, 255);
                    dist_144 = std::uniform_int_distribution<>(251, 255);
                    dist_145 = std::uniform_int_distribution<>(251, 255);
                    dist_146 = std::uniform_int_distribution<>(251, 255);
                    dist_147 = std::uniform_int_distribution<>(251, 255);
                }
                else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                    //hp
                    dist_1 = std::uniform_int_distribution<>(1, 510);
                    //mp
                    dist_2 = std::uniform_int_distribution<>(1, 500);
                    //str
                    dist_3 = std::uniform_int_distribution<>(1, 150);
                    //int
                    dist_4 = std::uniform_int_distribution<>(1, 145);
                    //agl
                    dist_5 = std::uniform_int_distribution<>(1, 145);
                    //carry
                    dist_6 = std::uniform_int_distribution<>(1, 14);
                    //run
                    dist_7 = std::uniform_int_distribution<>(1, 28);
                    //bla str
                    dist_9 = std::uniform_int_distribution<>(1, 31);
                    //bla int
                    dist_10 = std::uniform_int_distribution<>(1, 26);

                    //gri str and int
                    dist_38 = std::uniform_int_distribution<>(0, 12);
                    dist_39 = std::uniform_int_distribution<>(0, 12);
                    //gri agi
                    dist_40 = std::uniform_int_distribution<>(252, 255);

                    //gri bl/ed/pi
                    dist_41 = std::uniform_int_distribution<>(0, 21);
                    dist_42 = std::uniform_int_distribution<>(0, 21);
                    dist_43 = std::uniform_int_distribution<>(0, 21);

                    //gem str/int/agi
                    dist_45 = std::uniform_int_distribution<>(0, 6);
                    dist_46 = std::uniform_int_distribution<>(0, 6);
                    dist_47 = std::uniform_int_distribution<>(0, 6);

                    //material             
                    dist_61 = std::uniform_int_distribution<>(3, 6);

                    //shi str
                    dist_64 = std::uniform_int_distribution<>(4, 20);
                    //shi int
                    dist_65 = std::uniform_int_distribution<>(4, 20);
                    //shi agi
                    dist_66 = std::uniform_int_distribution<>(252, 255);

                    //shi blu                   
                    dist_71 = std::uniform_int_distribution<>(0, 20);
                    //shi edg
                    dist_72 = std::uniform_int_distribution<>(0, 20);
                    //shi pie
                    dist_73 = std::uniform_int_distribution<>(0, 20);

                    //armour mat
                    dist_81 = std::uniform_int_distribution<>(1, 7);

                    //acc str/int/agi
                    dist_84 = std::uniform_int_distribution<>(1, 5);
                    dist_85 = std::uniform_int_distribution<>(1, 5);
                    dist_86 = std::uniform_int_distribution<>(1, 5);

                    //body agl
                    dist_105 = std::uniform_int_distribution<>(0, 251);
                    //body evd
                    dist_106 = std::uniform_int_distribution<>(0, 251);


                    //body arm str and int
                    dist_118 = std::uniform_int_distribution<>(1, 25);
                    dist_119 = std::uniform_int_distribution<>(1, 25);

                    //arm blu edg pie
                    dist_121 = std::uniform_int_distribution<>(0, 12);
                    dist_122 = std::uniform_int_distribution<>(0, 12);
                    dist_123 = std::uniform_int_distribution<>(0, 12);

                    //other arm str and int
                    dist_140 = std::uniform_int_distribution<>(1, 17);
                    dist_141 = std::uniform_int_distribution<>(1, 17);

                    //shi class neg
                    dist_142 = std::uniform_int_distribution<>(251, 255);
                    dist_143 = std::uniform_int_distribution<>(251, 255);
                    dist_144 = std::uniform_int_distribution<>(251, 255);
                    dist_145 = std::uniform_int_distribution<>(251, 255);
                    dist_146 = std::uniform_int_distribution<>(251, 255);
                    dist_147 = std::uniform_int_distribution<>(251, 255);

                    //shi class pos
                    dist_148 = std::uniform_int_distribution<>(0, 10);
                }
                else if (*ezp == "ZONE051.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE053.ZND") {
                    //hp
                    dist_1 = std::uniform_int_distribution<>(1, 720);
                    //mp
                    dist_2 = std::uniform_int_distribution<>(1, 500);
                    //str
                    dist_3 = std::uniform_int_distribution<>(1, 150);
                    //int
                    dist_4 = std::uniform_int_distribution<>(1, 145);
                    //agl
                    dist_5 = std::uniform_int_distribution<>(1, 145);
                    //carry
                    dist_6 = std::uniform_int_distribution<>(1, 14);
                    //run
                    dist_7 = std::uniform_int_distribution<>(1, 28);
                    //bla str
                    dist_9 = std::uniform_int_distribution<>(1, 33);
                    //bla int
                    dist_10 = std::uniform_int_distribution<>(1, 26);

                    //gri str and int
                    dist_38 = std::uniform_int_distribution<>(0, 12);
                    dist_39 = std::uniform_int_distribution<>(0, 12);
                    //gri agi
                    dist_40 = std::uniform_int_distribution<>(252, 255);

                    //gri bl/ed/pi
                    dist_41 = std::uniform_int_distribution<>(0, 21);
                    dist_42 = std::uniform_int_distribution<>(0, 21);
                    dist_43 = std::uniform_int_distribution<>(0, 21);

                    //gem str/int/agi
                    dist_45 = std::uniform_int_distribution<>(0, 6);
                    dist_46 = std::uniform_int_distribution<>(0, 6);
                    dist_47 = std::uniform_int_distribution<>(0, 6);

                    //material             
                    dist_61 = std::uniform_int_distribution<>(3, 6);

                    //shi str
                    dist_64 = std::uniform_int_distribution<>(4, 20);
                    //shi int
                    dist_65 = std::uniform_int_distribution<>(4, 20);
                    //shi agi
                    dist_66 = std::uniform_int_distribution<>(252, 255);

                    //shi blu                   
                    dist_71 = std::uniform_int_distribution<>(0, 20);
                    //shi edg
                    dist_72 = std::uniform_int_distribution<>(0, 20);
                    //shi pie
                    dist_73 = std::uniform_int_distribution<>(0, 20);

                    //armour mat
                    dist_81 = std::uniform_int_distribution<>(1, 7);

                    //acc str/int/agi
                    dist_84 = std::uniform_int_distribution<>(1, 5);
                    dist_85 = std::uniform_int_distribution<>(1, 5);
                    dist_86 = std::uniform_int_distribution<>(1, 5);

                    //part agl
                    dist_105 = std::uniform_int_distribution<>(0, 251);
                    //part evd
                    dist_106 = std::uniform_int_distribution<>(0, 255);


                    //body arm str and int
                    dist_118 = std::uniform_int_distribution<>(1, 25);
                    dist_119 = std::uniform_int_distribution<>(1, 25);

                    //arm blu edg pie
                    dist_121 = std::uniform_int_distribution<>(0, 12);
                    dist_122 = std::uniform_int_distribution<>(0, 12);
                    dist_123 = std::uniform_int_distribution<>(0, 12);

                    //other arm str and int
                    dist_140 = std::uniform_int_distribution<>(1, 17);
                    dist_141 = std::uniform_int_distribution<>(1, 17);

                    //shi class neg
                    dist_142 = std::uniform_int_distribution<>(251, 255);
                    dist_143 = std::uniform_int_distribution<>(251, 255);
                    dist_144 = std::uniform_int_distribution<>(251, 255);
                    dist_145 = std::uniform_int_distribution<>(251, 255);
                    dist_146 = std::uniform_int_distribution<>(251, 255);
                    dist_147 = std::uniform_int_distribution<>(251, 255);

                    //shi class pos
                    dist_148 = std::uniform_int_distribution<>(0, 10);
                }
                else if (*ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND") {
                    //hp
                    dist_1 = std::uniform_int_distribution<>(1, 790);
                    //mp
                    dist_2 = std::uniform_int_distribution<>(1, 666);
                    //str
                    dist_3 = std::uniform_int_distribution<>(1, 150);
                    //int
                    dist_4 = std::uniform_int_distribution<>(1, 170);
                    //agl
                    dist_5 = std::uniform_int_distribution<>(1, 155);
                    //carry
                    dist_6 = std::uniform_int_distribution<>(1, 14);
                    //run
                    dist_7 = std::uniform_int_distribution<>(1, 28);
                    //bla str
                    dist_9 = std::uniform_int_distribution<>(1, 43);
                    //bla int
                    dist_10 = std::uniform_int_distribution<>(1, 26);

                    //gri str and int
                    dist_38 = std::uniform_int_distribution<>(0, 12);
                    dist_39 = std::uniform_int_distribution<>(0, 12);
                    //gri agi
                    dist_40 = std::uniform_int_distribution<>(252, 255);

                    //gri bl/ed/pi
                    dist_41 = std::uniform_int_distribution<>(0, 21);
                    dist_42 = std::uniform_int_distribution<>(0, 21);
                    dist_43 = std::uniform_int_distribution<>(0, 21);

                    //gem str/int/agi
                    dist_45 = std::uniform_int_distribution<>(0, 12);
                    dist_46 = std::uniform_int_distribution<>(0, 12);
                    dist_47 = std::uniform_int_distribution<>(0, 12);

                    //material             
                    dist_61 = std::uniform_int_distribution<>(3, 7);

                    //shi str
                    dist_64 = std::uniform_int_distribution<>(4, 22);
                    //shi int
                    dist_65 = std::uniform_int_distribution<>(4, 22);
                    //shi agi
                    dist_66 = std::uniform_int_distribution<>(252, 255);

                    //shi blu                   
                    dist_71 = std::uniform_int_distribution<>(0, 25);
                    //shi edg
                    dist_72 = std::uniform_int_distribution<>(0, 25);
                    //shi pie
                    dist_73 = std::uniform_int_distribution<>(0, 25);

                    //armour mat
                    dist_81 = std::uniform_int_distribution<>(1, 7);

                    //acc str/int/agi
                    dist_84 = std::uniform_int_distribution<>(1, 5);
                    dist_85 = std::uniform_int_distribution<>(1, 5);
                    dist_86 = std::uniform_int_distribution<>(1, 5);

                    //part agl
                    dist_105 = std::uniform_int_distribution<>(0, 251);
                    //part evd
                    dist_106 = std::uniform_int_distribution<>(0, 255);


                    //body arm str and int
                    dist_118 = std::uniform_int_distribution<>(1, 25);
                    dist_119 = std::uniform_int_distribution<>(1, 25);

                    //arm blu edg pie
                    dist_121 = std::uniform_int_distribution<>(0, 12);
                    dist_122 = std::uniform_int_distribution<>(0, 12);
                    dist_123 = std::uniform_int_distribution<>(0, 12);

                    //other arm str and int
                    dist_140 = std::uniform_int_distribution<>(1, 17);
                    dist_141 = std::uniform_int_distribution<>(1, 17);

                    //shi class neg
                    dist_142 = std::uniform_int_distribution<>(251, 255);
                    dist_143 = std::uniform_int_distribution<>(251, 255);
                    dist_144 = std::uniform_int_distribution<>(251, 255);
                    dist_145 = std::uniform_int_distribution<>(251, 255);
                    dist_146 = std::uniform_int_distribution<>(251, 255);
                    dist_147 = std::uniform_int_distribution<>(251, 255);

                    //shi class pos
                    dist_148 = std::uniform_int_distribution<>(0, 14);
                }
                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                    //hp
                    dist_1 = std::uniform_int_distribution<>(1, 999);
                    //mp
                    dist_2 = std::uniform_int_distribution<>(1, 999);
                    //str
                    dist_3 = std::uniform_int_distribution<>(1, 150);
                    //int
                    dist_4 = std::uniform_int_distribution<>(1, 220);
                    //agl
                    dist_5 = std::uniform_int_distribution<>(1, 200);
                    //carry
                    dist_6 = std::uniform_int_distribution<>(1, 14);
                    //run
                    dist_7 = std::uniform_int_distribution<>(1, 28);
                    //bla str
                    dist_9 = std::uniform_int_distribution<>(1, 43);
                    //bla int
                    dist_10 = std::uniform_int_distribution<>(1, 28);

                    //gri str and int
                    dist_38 = std::uniform_int_distribution<>(0, 12);
                    dist_39 = std::uniform_int_distribution<>(0, 12);
                    //gri agi
                    dist_40 = std::uniform_int_distribution<>(252, 255);

                    //gri bl/ed/pi
                    dist_41 = std::uniform_int_distribution<>(0, 21);
                    dist_42 = std::uniform_int_distribution<>(0, 21);
                    dist_43 = std::uniform_int_distribution<>(0, 21);

                    //gem str/int/agi
                    dist_45 = std::uniform_int_distribution<>(0, 15);
                    dist_46 = std::uniform_int_distribution<>(0, 15);
                    dist_47 = std::uniform_int_distribution<>(0, 15);

                    //material             
                    dist_61 = std::uniform_int_distribution<>(3, 7);

                    //shi str
                    dist_64 = std::uniform_int_distribution<>(4, 24);
                    //shi int
                    dist_65 = std::uniform_int_distribution<>(4, 24);
                    //shi agi
                    dist_66 = std::uniform_int_distribution<>(252, 255);

                    //shi blu                   
                    dist_71 = std::uniform_int_distribution<>(0, 25);
                    //shi edg
                    dist_72 = std::uniform_int_distribution<>(0, 25);
                    //shi pie
                    dist_73 = std::uniform_int_distribution<>(0, 25);

                    //armour mat
                    dist_81 = std::uniform_int_distribution<>(1, 7);

                    //acc str/int/agi
                    dist_84 = std::uniform_int_distribution<>(1, 25);
                    dist_85 = std::uniform_int_distribution<>(1, 25);
                    dist_86 = std::uniform_int_distribution<>(1, 25);

                    //part agl
                    dist_105 = std::uniform_int_distribution<>(0, 251);
                    //part evd
                    dist_106 = std::uniform_int_distribution<>(0, 255);


                    //body arm str and int
                    dist_118 = std::uniform_int_distribution<>(1, 25);
                    dist_119 = std::uniform_int_distribution<>(1, 25);

                    //arm blu edg pie
                    dist_121 = std::uniform_int_distribution<>(0, 12);
                    dist_122 = std::uniform_int_distribution<>(0, 12);
                    dist_123 = std::uniform_int_distribution<>(0, 12);

                    //other arm str and int
                    dist_140 = std::uniform_int_distribution<>(1, 17);
                    dist_141 = std::uniform_int_distribution<>(1, 17);

                    //shi class neg
                    dist_142 = std::uniform_int_distribution<>(251, 255);
                    dist_143 = std::uniform_int_distribution<>(251, 255);
                    dist_144 = std::uniform_int_distribution<>(251, 255);
                    dist_145 = std::uniform_int_distribution<>(251, 255);
                    dist_146 = std::uniform_int_distribution<>(251, 255);
                    dist_147 = std::uniform_int_distribution<>(251, 255);

                    //shi class pos
                    dist_148 = std::uniform_int_distribution<>(0, 15);
                }
            }
            for (int e = 0; e < ene_count; e++) {
                stat = dist_1(aGen);
                ene_hp_stat = stat;
                sprintf_s(rand_hp, "%X", stat);
                ss_rand_hp << rand_hp;
                ss_rand_hp >> s_rand_hp;
                ss_rand_hp.clear();
                hs_rand_hp << std::hex << s_rand_hp;
                hs_rand_hp >> int_rand_hp;
                hs_rand_hp.clear();
                s1 = "0";
                if (stat > 255) {
                    s2 = s_rand_hp.at(0);
                    s3 = s_rand_hp.at(1);
                    s4 = s_rand_hp.at(2);
                }
                else if (stat > 16) {
                    s2 = "0";
                    s3 = s_rand_hp.at(0);
                    s4 = s_rand_hp.at(1);
                }
                else {
                    s2 = "0";
                    s3 = "0";
                    s4 = s_rand_hp.at(0);
                }
                s_rand_hp2 = s1 + s2;
                s_rand_hp1 = s3 + s4;
                fin_rand_hp << std::hex << s_rand_hp1;
                fin_rand_hp >> stat;
                fin_rand_hp.clear();
                enzon.seekg(wep_pos - 28, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 28, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                fin_rand_hp << std::hex << s_rand_hp2;
                fin_rand_hp >> stat;
                fin_rand_hp.clear();
                enzon.seekg(wep_pos - 27, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 27, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                stat = dist_2(aGen);
                sprintf_s(rand_mp, "%X", stat);
                ss_rand_mp << rand_mp;
                ss_rand_mp >> s_rand_mp;
                ss_rand_mp.clear();
                hs_rand_mp << std::hex << s_rand_mp;
                hs_rand_mp >> int_rand_mp;
                hs_rand_mp.clear();
                s1 = "0";
                if (stat > 255) {
                    s2 = s_rand_mp.at(0);
                    s3 = s_rand_mp.at(1);
                    s4 = s_rand_mp.at(2);
                }
                else if (stat > 16) {
                    s2 = "0";
                    s3 = s_rand_mp.at(0);
                    s4 = s_rand_mp.at(1);
                }
                else {
                    s2 = "0";
                    s3 = "0";
                    s4 = s_rand_mp.at(0);
                }
                s_rand_mp2 = s1 + s2;
                s_rand_mp1 = s3 + s4;
                fin_rand_mp << std::hex << s_rand_mp1;
                fin_rand_mp >> stat;
                fin_rand_mp.clear();
                enzon.seekg(wep_pos - 26, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 26, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                fin_rand_mp << std::hex << s_rand_mp2;
                fin_rand_mp >> stat;
                fin_rand_mp.clear();
                enzon.seekg(wep_pos - 25, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 25, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                stat = dist_3(aGen);
                enzon.seekg(wep_pos - 24, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 24, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                stat = dist_4(aGen);
                enzon.seekg(wep_pos - 23, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 23, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                stat = dist_5(aGen);
                enzon.seekg(wep_pos - 22, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 22, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                stat = dist_6(aGen);
                enzon.seekg(wep_pos - 19, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 19, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                stat = dist_7(aGen);
                enzon.seekg(wep_pos - 17, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                ch_val = new char(stat);
                enzon.seekp(wep_pos - 17, ios::beg);
                enzon.write(ch_val, 1);
                delete ch_val;
                enzon.seekg(wep_pos, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                if (to_ass > 0) {
                    if (to_ass == 1) {
                        dist_8 = std::uniform_int_distribution<>(1, 12);
                    }
                    else if (to_ass == 2) {
                        dist_8 = std::uniform_int_distribution<>(13, 24);
                    }
                    else if (to_ass == 3) {
                        dist_8 = std::uniform_int_distribution<>(25, 34);
                    }
                    else if (to_ass == 4) {
                        dist_8 = std::uniform_int_distribution<>(35, 50);
                    }
                    else if (to_ass == 5) {
                        dist_8 = std::uniform_int_distribution<>(51, 56);
                    }
                    else if (to_ass == 6) {
                        dist_8 = std::uniform_int_distribution<>(57, 62);
                    }
                    else if (to_ass == 7) {
                        dist_8 = std::uniform_int_distribution<>(63, 69);
                    }
                    else if (to_ass == 8) {
                        dist_8 = std::uniform_int_distribution<>(70, 82);
                    }
                    else if (to_ass == 9) {
                        dist_8 = std::uniform_int_distribution<>(83, 90);
                    }
                    stat = dist_8(aGen);
                    enzon.seekg(wep_pos - 4, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos - 4, ios::beg);
                    enzon.write(ch_val, 1);
                    enzon.seekg(wep_pos - 2, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    enzon.seekp(wep_pos - 2, ios::beg);
                    enzon.write(ch_val, 1);
                    enzon.seekg(wep_pos - 1, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    enzon.seekp(wep_pos - 1, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_9(aGen);
                    enzon.seekg(wep_pos + 1, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 1, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_10(aGen);
                    enzon.seekg(wep_pos + 2, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 2, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_12(aGen);
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            stat = 0;
                        }
                        else {
                            if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_12 = std::uniform_int_distribution<>(248, 255);
                            }
                            else {
                                dist_12 = std::uniform_int_distribution<>(249, 255);
                            }
                            stat = dist_12(aGen);
                        }
                    }
                    else {
                        stat = dist_12(aGen);
                    }
                    enzon.seekg(wep_pos + 3, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 3, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_13(aGen) * 100;
                    sprintf_s(rand_dpm, "%X", stat);
                    ss_rand_dpm << rand_dpm;
                    ss_rand_dpm >> s_rand_dpm;
                    ss_rand_dpm.clear();
                    hs_rand_dpm << std::hex << s_rand_dpm;
                    hs_rand_dpm >> int_rand_dpm;
                    hs_rand_dpm.clear();
                    dist_14 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
                    stat = dist_14(aGen) * 100;
                    sprintf_s(rand_dp, "%X", stat);
                    ss_rand_dp << rand_dp;
                    ss_rand_dp >> s_rand_dp;
                    ss_rand_dp.clear();
                    s1 = s_rand_dpm.at(0);
                    s2 = s_rand_dpm.at(1);
                    s3 = s_rand_dpm.at(2);
                    s4 = s_rand_dpm.at(3);
                    s_rand_dpm_1 = s1 + s2;
                    s_rand_dpm_2 = s3 + s4;
                    s1 = s_rand_dp.at(0);
                    s2 = s_rand_dp.at(1);
                    s3 = s_rand_dp.at(2);
                    s4 = s_rand_dp.at(3);
                    s_rand_dp_1 = s1 + s2;
                    s_rand_dp_2 = s3 + s4;
                    rand_dpm_fin << std::hex << s_rand_dpm_1;
                    rand_dpm_fin >> stat;
                    rand_dpm_fin.clear();
                    enzon.seekg(wep_pos + 7, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 7, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    rand_dpm_fin << std::hex << s_rand_dpm_2;
                    rand_dpm_fin >> stat;
                    rand_dpm_fin.clear();
                    enzon.seekg(wep_pos + 6, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 6, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    ppm = dist_15(aGen);
                    enzon.seekg(wep_pos + 10, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(ppm);
                    enzon.seekp(wep_pos + 10, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    rand_dpm_fin << std::hex << s_rand_dp_1;
                    rand_dpm_fin >> stat;
                    rand_dpm_fin.clear();
                    enzon.seekg(wep_pos + 5, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 5, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    rand_dpm_fin << std::hex << s_rand_dp_2;
                    rand_dpm_fin >> stat;
                    rand_dpm_fin.clear();
                    enzon.seekg(wep_pos + 4, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 4, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    dist_16 = std::uniform_int_distribution<>(1, ppm);
                    pp = dist_16(aGen);
                    enzon.seekg(wep_pos + 8, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(pp);
                    enzon.seekp(wep_pos + 8, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_18(aGen);
                    enzon.seekg(wep_pos + 12, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 12, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_19(aGen);
                    enzon.seekg(wep_pos + 13, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 13, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_17(aGen);
                    enzon.seekg(wep_pos + 14, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 14, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    //bla classes
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(236, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_21(aGen);
                        enzon.seekg(wep_pos + 20, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 20, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_22(aGen);
                        enzon.seekg(wep_pos + 21, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 21, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_23(aGen);
                        enzon.seekg(wep_pos + 22, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 22, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_24(aGen);
                    }
                    enzon.seekg(wep_pos + 28, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 28, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(236, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_25(aGen);
                    }
                    enzon.seekg(wep_pos + 29, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 29, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(236, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_26(aGen);
                    }
                    enzon.seekg(wep_pos + 30, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 30, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(236, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_27(aGen);
                    }
                    enzon.seekg(wep_pos + 31, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 31, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(236, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_28(aGen);
                    }
                    enzon.seekg(wep_pos + 32, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 32, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(236, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_29(aGen);
                    }
                    enzon.seekg(wep_pos + 33, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 33, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    //bla affinities
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                            else if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || * ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_30(aGen);
                    }
                    enzon.seekg(wep_pos + 36, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 36, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                            else if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_31(aGen);
                    }
                    enzon.seekg(wep_pos + 37, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 37, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                            else if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_32(aGen);
                    }
                    enzon.seekg(wep_pos + 38, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 38, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                            else if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_33(aGen);
                    }
                    enzon.seekg(wep_pos + 39, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 39, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                            else if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_34(aGen);
                    }
                    enzon.seekg(wep_pos + 40, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 40, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                            else if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_35(aGen);
                    }
                    enzon.seekg(wep_pos + 41, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 41, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                            }
                            else if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_36(aGen);
                    }
                    enzon.seekg(wep_pos + 42, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 42, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    enzon.seekg(wep_pos + 48, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    if (to_ass == 1) {
                        dist_37 = std::uniform_int_distribution<>(96, 104);
                    }
                    else if (to_ass == 2) {
                        dist_37 = std::uniform_int_distribution<>(105, 114);
                    }
                    else if (to_ass == 3) {
                        dist_37 = std::uniform_int_distribution<>(115, 120);
                    }
                    else if (to_ass == 4) {
                        dist_37 = std::uniform_int_distribution<>(121, 126);
                    }
                    stat = dist_37(aGen);
                    enzon.seekg(wep_pos + 44, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 44, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat -= 95;
                    enzon.seekg(wep_pos + 46, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 46, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_38(aGen);
                    enzon.seekg(wep_pos + 49, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 49, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_39(aGen);
                    enzon.seekg(wep_pos + 50, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 50, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_40(aGen);
                    enzon.seekg(wep_pos + 51, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 51, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    enzon.seekg(wep_pos + 65, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    gem_count = to_ass;
                    stat = dist_41(aGen);
                    enzon.seekg(wep_pos + 73, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 73, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_42(aGen);
                    enzon.seekg(wep_pos + 74, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 74, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_43(aGen);
                    enzon.seekg(wep_pos + 75, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 75, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (gem_count > 0) {
                        stat = dist_44(aGen);
                        enzon.seekg(wep_pos + 92, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 92, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        enzon.seekg(wep_pos + 93, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(1);
                        enzon.seekp(wep_pos + 93, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat -= 4;
                        enzon.seekg(wep_pos + 94, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 94, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_45(aGen);
                            }
                        }
                        else {
                            stat = dist_45(aGen);
                        }
                        enzon.seekg(wep_pos + 97, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 97, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_46(aGen);
                            }
                        }
                        else {
                            stat = dist_46(aGen);
                        }
                        enzon.seekg(wep_pos + 98, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 98, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_47(aGen);
                            }
                        }
                        else {
                            stat = dist_47(aGen);
                        }
                        enzon.seekg(wep_pos + 99, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 99, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_48(aGen);
                        }
                        enzon.seekg(wep_pos + 124, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 124, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_49(aGen);
                        }
                        enzon.seekg(wep_pos + 125, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 125, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_50(aGen);
                        }
                        enzon.seekg(wep_pos + 126, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 126, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_51(aGen);
                        }
                        enzon.seekg(wep_pos + 127, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 127, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_52(aGen);
                        }
                        enzon.seekg(wep_pos + 128, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 128, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_53(aGen);
                        }
                        enzon.seekg(wep_pos + 129, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 129, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_54(aGen);
                        }
                        enzon.seekg(wep_pos + 132, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 132, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_55(aGen);
                        }
                        enzon.seekg(wep_pos + 133, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 133, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_56(aGen);
                        }
                        enzon.seekg(wep_pos + 134, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 134, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_57(aGen);
                        }
                        enzon.seekg(wep_pos + 135, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 135, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_58(aGen);
                        }
                        enzon.seekg(wep_pos + 136, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 136, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_59(aGen);
                        }
                        enzon.seekg(wep_pos + 137, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 137, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_60(aGen);
                        }
                        enzon.seekg(wep_pos + 138, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 138, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (gem_count > 1) {
                            stat = dist_44(aGen);
                            enzon.seekg(wep_pos + 140, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 140, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            enzon.seekg(wep_pos + 141, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(1);
                            enzon.seekp(wep_pos + 141, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            stat -= 4;
                            enzon.seekg(wep_pos + 142, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 142, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_45(aGen);
                                }
                            }
                            else {
                                stat = dist_45(aGen);
                            }
                            enzon.seekg(wep_pos + 145, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 145, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_46(aGen);
                                }
                            }
                            else {
                                stat = dist_46(aGen);
                            }
                            enzon.seekg(wep_pos + 146, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 146, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_47(aGen);
                                }
                            }
                            else {
                                stat = dist_47(aGen);
                            }
                            enzon.seekg(wep_pos + 147, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 147, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_48(aGen);
                            }
                            enzon.seekg(wep_pos + 172, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 172, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_49(aGen);
                            }
                            enzon.seekg(wep_pos + 173, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 173, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_50(aGen);
                            }
                            enzon.seekg(wep_pos + 174, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 174, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_51(aGen);
                            }
                            enzon.seekg(wep_pos + 175, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 175, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_52(aGen);
                            }
                            enzon.seekg(wep_pos + 176, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 176, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_53(aGen);
                            }
                            enzon.seekg(wep_pos + 177, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 177, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_54(aGen);
                            }
                            enzon.seekg(wep_pos + 180, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 180, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_55(aGen);
                            }
                            enzon.seekg(wep_pos + 181, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 181, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_56(aGen);
                            }
                            enzon.seekg(wep_pos + 182, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 182, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_57(aGen);
                            }
                            enzon.seekg(wep_pos + 183, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 183, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_58(aGen);
                            }
                            enzon.seekg(wep_pos + 184, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 184, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_59(aGen);
                            }
                            enzon.seekg(wep_pos + 185, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 185, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_60(aGen);
                            }
                            enzon.seekg(wep_pos + 186, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 186, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (gem_count > 2) {
                                stat = dist_44(aGen);
                                enzon.seekg(wep_pos + 188, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 188, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                enzon.seekg(wep_pos + 189, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(1);
                                enzon.seekp(wep_pos + 189, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                stat -= 4;
                                enzon.seekg(wep_pos + 190, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 190, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                        stat = dist_20(aGen);
                                    }
                                    else {
                                        stat = dist_45(aGen);
                                    }
                                }
                                else {
                                    stat = dist_45(aGen);
                                }
                                enzon.seekg(wep_pos + 193, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 193, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                        stat = dist_20(aGen);
                                    }
                                    else {
                                        stat = dist_46(aGen);
                                    }
                                }
                                else {
                                    stat = dist_46(aGen);
                                }
                                enzon.seekg(wep_pos + 194, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 194, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                        stat = dist_20(aGen);
                                    }
                                    else {
                                        stat = dist_47(aGen);
                                    }
                                }
                                else {
                                    stat = dist_47(aGen);
                                }
                                enzon.seekg(wep_pos + 195, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 195, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_48(aGen);
                                }
                                enzon.seekg(wep_pos + 220, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 220, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_49(aGen);
                                }
                                enzon.seekg(wep_pos + 221, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 221, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_50(aGen);
                                }
                                enzon.seekg(wep_pos + 222, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 222, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_51(aGen);
                                }
                                enzon.seekg(wep_pos + 223, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 223, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_52(aGen);
                                }
                                enzon.seekg(wep_pos + 224, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 224, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_53(aGen);
                                }
                                enzon.seekg(wep_pos + 225, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 225, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_54(aGen);
                                }
                                enzon.seekg(wep_pos + 228, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 228, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_55(aGen);
                                }
                                enzon.seekg(wep_pos + 229, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 229, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_56(aGen);
                                }
                                enzon.seekg(wep_pos + 230, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 230, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_57(aGen);
                                }
                                enzon.seekg(wep_pos + 231, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 231, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_58(aGen);
                                }
                                enzon.seekg(wep_pos + 232, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 232, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_59(aGen);
                                }
                                enzon.seekg(wep_pos + 233, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 233, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_60(aGen);
                                }
                                enzon.seekg(wep_pos + 234, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 234, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                            }
                        }
                    }
                    stat = dist_61(aGen);
                    enzon.seekg(wep_pos + 236, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 236, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_62(aGen);
                    enzon.seekg(wep_pos + 237, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 237, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;

                } 
                enzon.seekg(wep_pos + 264, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                if (to_ass > 0) {
                    stat = dist_63(aGen);
                    enzon.seekg(wep_pos + 264, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 264, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat -= 126;
                    enzon.seekg(wep_pos + 266, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 266, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat += 95;
                    enzon.seekg(wep_pos + 267, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 267, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_64(aGen);
                    enzon.seekg(wep_pos + 269, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 269, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_65(aGen);
                    enzon.seekg(wep_pos + 270, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 270, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_66(aGen);
                    enzon.seekg(wep_pos + 271, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 271, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_67(aGen) * 100;
                    sprintf_s(rand_dpm, "%X", stat);
                    ss_rand_dpm << rand_dpm;
                    ss_rand_dpm >> s_rand_dpm;
                    ss_rand_dpm.clear();
                    hs_rand_dpm << std::hex << s_rand_dpm;
                    hs_rand_dpm >> int_rand_dpm;
                    hs_rand_dpm.clear();
                    dist_68 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
                    stat = dist_68(aGen) * 100;
                    sprintf_s(rand_dp, "%X", stat);
                    ss_rand_dp << rand_dp;
                    ss_rand_dp >> s_rand_dp;
                    ss_rand_dp.clear();
                    s1 = s_rand_dpm.at(0);
                    s2 = s_rand_dpm.at(1);
                    s3 = s_rand_dpm.at(2);
                    s4 = s_rand_dpm.at(3);
                    s_rand_dpm_1 = s1 + s2;
                    s_rand_dpm_2 = s3 + s4;
                    s1 = s_rand_dp.at(0);
                    s2 = s_rand_dp.at(1);
                    s3 = s_rand_dp.at(2);
                    s4 = s_rand_dp.at(3);
                    s_rand_dp_1 = s1 + s2;
                    s_rand_dp_2 = s3 + s4;
                    rand_dpm_fin << std::hex << s_rand_dpm_1;
                    rand_dpm_fin >> stat;
                    rand_dpm_fin.clear();
                    enzon.seekg(wep_pos + 275, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 275, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    rand_dpm_fin << std::hex << s_rand_dpm_2;
                    rand_dpm_fin >> stat;
                    rand_dpm_fin.clear();
                    enzon.seekg(wep_pos + 274, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 274, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    ppm = dist_69(aGen);
                    enzon.seekg(wep_pos + 278, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(ppm);
                    enzon.seekp(wep_pos + 278, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    rand_dpm_fin << std::hex << s_rand_dp_1;
                    rand_dpm_fin >> stat;
                    rand_dpm_fin.clear();
                    enzon.seekg(wep_pos + 273, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 273, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    rand_dpm_fin << std::hex << s_rand_dp_2;
                    rand_dpm_fin >> stat;
                    rand_dpm_fin.clear();
                    enzon.seekg(wep_pos + 272, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 272, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    dist_70 = std::uniform_int_distribution<>(1, ppm);
                    pp = dist_70(aGen);
                    enzon.seekg(wep_pos + 276, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(pp);
                    enzon.seekp(wep_pos + 276, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    enzon.seekg(wep_pos + 285, ios::beg);
                    map_loc = enzon.tellg();
                    to_ass = enzon.get();
                    gem_count = to_ass;
                    stat = dist_71(aGen);
                    enzon.seekg(wep_pos + 293, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 293, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_72(aGen);
                    enzon.seekg(wep_pos + 294, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 294, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_73(aGen);
                    enzon.seekg(wep_pos + 295, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 295, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = dist_142(aGen);
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                stat = dist_148(aGen);
                            }
                            else {
                                stat = dist_142(aGen);
                            }
                        }
                    }
                    else {
                        stat = dist_142(aGen);
                    }
                    enzon.seekg(wep_pos + 296, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 296, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = dist_142(aGen);
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                stat = dist_148(aGen);
                            }
                            else {
                                stat = dist_142(aGen);
                            }
                        }
                    }
                    else {
                        stat = dist_143(aGen);
                    }
                    enzon.seekg(wep_pos + 297, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 297, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = dist_142(aGen);
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                stat = dist_148(aGen);
                            }
                            else {
                                stat = dist_142(aGen);
                            }
                        }
                    }
                    else {
                        stat = dist_144(aGen);
                    }
                    enzon.seekg(wep_pos + 298, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 298, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = dist_142(aGen);
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                stat = dist_148(aGen);
                            }
                            else {
                                stat = dist_142(aGen);
                            }
                        }
                    }
                    else {
                        stat = dist_145(aGen);
                    }
                    enzon.seekg(wep_pos + 299, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 299, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = dist_142(aGen);
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                stat = dist_148(aGen);
                            }
                            else {
                                stat = dist_142(aGen);
                            }
                        }
                    }
                    else {
                        stat = dist_146(aGen);
                    }
                    enzon.seekg(wep_pos + 300, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 300, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = dist_142(aGen);
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                stat = dist_148(aGen);
                            }
                            else {
                                stat = dist_142(aGen);
                            }
                        }
                    }
                    else {
                        stat = dist_147(aGen);
                    }
                    enzon.seekg(wep_pos + 301, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 301, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 8);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else if (*ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 19);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(250, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_74(aGen);
                    }
                    enzon.seekg(wep_pos + 304, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 304, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 8);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else if (*ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 19);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(250, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_75(aGen);
                    }
                    enzon.seekg(wep_pos + 305, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 305, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 8);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else if (*ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 19);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(250, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_76(aGen);
                    }
                    enzon.seekg(wep_pos + 306, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 306, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 8);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else if (*ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 19);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(250, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_77(aGen);
                    }
                    enzon.seekg(wep_pos + 307, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 307, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 8);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else if (*ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 19);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(250, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_78(aGen);
                    }
                    enzon.seekg(wep_pos + 308, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 308, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 8);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else if (*ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 19);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(250, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_79(aGen);
                    }
                    enzon.seekg(wep_pos + 309, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 309, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 8);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 14);
                            }
                            else if (*ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 19);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(250, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_80(aGen);
                    }
                    enzon.seekg(wep_pos + 310, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 310, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (gem_count > 0) {
                        stat = dist_44(aGen);
                        enzon.seekg(wep_pos + 312, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 312, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        enzon.seekg(wep_pos + 313, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(1);
                        enzon.seekp(wep_pos + 313, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat -= 4;
                        enzon.seekg(wep_pos + 314, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 314, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_45(aGen);
                            }
                        }
                        else {
                            stat = dist_45(aGen);
                        }
                        enzon.seekg(wep_pos + 317, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 317, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_46(aGen);
                            }
                        }
                        else {
                            stat = dist_46(aGen);
                        }
                        enzon.seekg(wep_pos + 318, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 318, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(253, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_47(aGen);
                            }
                        }
                        else {
                            stat = dist_47(aGen);
                        }
                        enzon.seekg(wep_pos + 319, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 319, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_48(aGen);
                        }
                        enzon.seekg(wep_pos + 344, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 344, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_49(aGen);
                        }
                        enzon.seekg(wep_pos + 345, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 345, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_50(aGen);
                        }
                        enzon.seekg(wep_pos + 346, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 346, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_51(aGen);
                        }
                        enzon.seekg(wep_pos + 347, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 347, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_52(aGen);
                        }
                        enzon.seekg(wep_pos + 348, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 348, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 15);
                                }
                            }
                            else {
                                if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(250, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_53(aGen);
                        }
                        enzon.seekg(wep_pos + 349, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 349, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_54(aGen);
                        }
                        enzon.seekg(wep_pos + 352, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 352, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_55(aGen);
                        }
                        enzon.seekg(wep_pos + 353, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 353, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_56(aGen);
                        }
                        enzon.seekg(wep_pos + 354, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 354, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_57(aGen);
                        }
                        enzon.seekg(wep_pos + 355, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 355, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_58(aGen);
                        }
                        enzon.seekg(wep_pos + 356, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 356, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_59(aGen);
                        }
                        enzon.seekg(wep_pos + 357, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 357, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                stat = 0;
                            }
                            else {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(0, 30);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(241, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_60(aGen);
                        }
                        enzon.seekg(wep_pos + 358, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + 358, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (gem_count > 1) {
                            stat = dist_44(aGen);
                            enzon.seekg(wep_pos + 360, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 360, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            enzon.seekg(wep_pos + 361, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(1);
                            enzon.seekp(wep_pos + 361, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            stat -= 4;
                            enzon.seekg(wep_pos + 362, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 362, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_45(aGen);
                                }
                            }
                            else {
                                stat = dist_45(aGen);
                            }
                            enzon.seekg(wep_pos + 365, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 365, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_46(aGen);
                                }
                            }
                            else {
                                stat = dist_46(aGen);
                            }
                            enzon.seekg(wep_pos + 366, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 366, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_47(aGen);
                                }
                            }
                            else {
                                stat = dist_47(aGen);
                            }
                            enzon.seekg(wep_pos + 367, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 367, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_48(aGen);
                            }
                            enzon.seekg(wep_pos + 392, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 392, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_49(aGen);
                            }
                            enzon.seekg(wep_pos + 393, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 393, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_50(aGen);
                            }
                            enzon.seekg(wep_pos + 394, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 394, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_51(aGen);
                            }
                            enzon.seekg(wep_pos + 395, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 395, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_52(aGen);
                            }
                            enzon.seekg(wep_pos + 396, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 396, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                stat = dist_11(aGen);
                                if (stat == 1) {
                                    if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(0, 15);
                                    }
                                }
                                else {
                                    if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(251, 255);
                                    }
                                    else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                        dist_20 = std::uniform_int_distribution<>(250, 255);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                    }
                                }
                                stat = dist_20(aGen);
                            }
                            else {
                                stat = dist_53(aGen);
                            }
                            enzon.seekg(wep_pos + 397, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 397, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_54(aGen);
                            }
                            enzon.seekg(wep_pos + 400, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 400, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_55(aGen);
                            }
                            enzon.seekg(wep_pos + 401, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 401, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_56(aGen);
                            }
                            enzon.seekg(wep_pos + 402, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 402, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_57(aGen);
                            }
                            enzon.seekg(wep_pos + 403, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 403, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_58(aGen);
                            }
                            enzon.seekg(wep_pos + 404, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 404, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_59(aGen);
                            }
                            enzon.seekg(wep_pos + 405, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 405, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (balDecision == "Y") {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    stat = 0;
                                }
                                else {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(0, 30);
                                    }
                                    else {
                                        dist_20 = std::uniform_int_distribution<>(241, 255);
                                    }
                                    stat = dist_20(aGen);
                                }
                            }
                            else {
                                stat = dist_60(aGen);
                            }
                            enzon.seekg(wep_pos + 406, ios::beg);
                            map_loc = enzon.tellg();
                            to_ass = enzon.get();
                            ch_val = new char(stat);
                            enzon.seekp(wep_pos + 406, ios::beg);
                            enzon.write(ch_val, 1);
                            delete ch_val;
                            if (gem_count > 2) {
                                stat = dist_44(aGen);
                                enzon.seekg(wep_pos + 408, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 408, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                enzon.seekg(wep_pos + 409, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(1);
                                enzon.seekp(wep_pos + 409, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                stat -= 4;
                                enzon.seekg(wep_pos + 410, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 410, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                        stat = dist_20(aGen);
                                    }
                                    else {
                                        stat = dist_45(aGen);
                                    }
                                }
                                else {
                                    stat = dist_45(aGen);
                                }
                                enzon.seekg(wep_pos + 413, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 413, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                        stat = dist_20(aGen);
                                    }
                                    else {
                                        stat = dist_46(aGen);
                                    }
                                }
                                else {
                                    stat = dist_46(aGen);
                                }
                                enzon.seekg(wep_pos + 414, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 414, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y" && *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND" || *ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        dist_20 = std::uniform_int_distribution<>(253, 255);
                                        stat = dist_20(aGen);
                                    }
                                    else {
                                        stat = dist_47(aGen);
                                    }
                                }
                                else {
                                    stat = dist_47(aGen);
                                }
                                enzon.seekg(wep_pos + 415, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 415, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_48(aGen);
                                }
                                enzon.seekg(wep_pos + 440, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 440, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_49(aGen);
                                }
                                enzon.seekg(wep_pos + 441, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 441, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_50(aGen);
                                }
                                enzon.seekg(wep_pos + 442, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 442, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_51(aGen);
                                }
                                enzon.seekg(wep_pos + 443, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 443, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_52(aGen);
                                }
                                enzon.seekg(wep_pos + 444, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 444, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    stat = dist_11(aGen);
                                    if (stat == 1) {
                                        if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(0, 15);
                                        }
                                    }
                                    else {
                                        if (*ezp == "ZONE022.ZND" || *ezp == "ZONE024.ZND" || *ezp == "ZONE025.ZND" || *ezp == "ZONE030.ZND" || *ezp == "ZONE031.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(251, 255);
                                        }
                                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                            dist_20 = std::uniform_int_distribution<>(250, 255);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(253, 255);
                                        }
                                    }
                                    stat = dist_20(aGen);
                                }
                                else {
                                    stat = dist_53(aGen);
                                }
                                enzon.seekg(wep_pos + 445, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 445, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_54(aGen);
                                }
                                enzon.seekg(wep_pos + 448, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 448, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_55(aGen);
                                }
                                enzon.seekg(wep_pos + 449, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 449, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_56(aGen);
                                }
                                enzon.seekg(wep_pos + 450, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 450, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_57(aGen);
                                }
                                enzon.seekg(wep_pos + 451, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 451, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_58(aGen);
                                }
                                enzon.seekg(wep_pos + 452, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 452, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_59(aGen);
                                }
                                enzon.seekg(wep_pos + 453, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 453, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                                if (balDecision == "Y") {
                                    if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                        stat = 0;
                                    }
                                    else {
                                        stat = dist_11(aGen);
                                        if (stat == 1) {
                                            dist_20 = std::uniform_int_distribution<>(0, 30);
                                        }
                                        else {
                                            dist_20 = std::uniform_int_distribution<>(241, 255);
                                        }
                                        stat = dist_20(aGen);
                                    }
                                }
                                else {
                                    stat = dist_60(aGen);
                                }
                                enzon.seekg(wep_pos + 454, ios::beg);
                                map_loc = enzon.tellg();
                                to_ass = enzon.get();
                                ch_val = new char(stat);
                                enzon.seekp(wep_pos + 454, ios::beg);
                                enzon.write(ch_val, 1);
                                delete ch_val;
                            }
                        }
                    }
                    stat = dist_81(aGen);
                    enzon.seekg(wep_pos + 456, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 456, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_82(aGen);
                    enzon.seekg(wep_pos + 457, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 457, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                }
                enzon.seekg(wep_pos + 460, ios::beg);
                stat_loc = enzon.tellg();
                to_ass = enzon.get();
                if (to_ass > 0) {
                    stat = dist_83(aGen);
                    enzon.seekg(wep_pos + 460, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 460, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat -= 222;
                    enzon.seekg(wep_pos + 462, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 462, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_84(aGen);
                    enzon.seekg(wep_pos + 465, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 465, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_85(aGen);
                    enzon.seekg(wep_pos + 466, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 466, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_86(aGen);
                    enzon.seekg(wep_pos + 467, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 467, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = 0;
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            dist_20 = std::uniform_int_distribution<>(0, 15);
                            stat = dist_20(aGen);
                        }
                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(236, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(0, 20);
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_87(aGen);
                    }
                    enzon.seekg(wep_pos + 489, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 489, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = 0;
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            dist_20 = std::uniform_int_distribution<>(0, 15);
                            stat = dist_20(aGen);
                        }
                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(236, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(0, 20);
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_88(aGen);
                    }
                    enzon.seekg(wep_pos + 490, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 490, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                            stat = 0;
                        }
                        else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                            dist_20 = std::uniform_int_distribution<>(0, 15);
                            stat = dist_20(aGen);
                        }
                        else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                dist_20 = std::uniform_int_distribution<>(236, 255);
                                stat = dist_20(aGen);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 20);
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(0, 20);
                            stat = dist_20(aGen);
                        }
                    }
                    else {
                        stat = dist_89(aGen);
                    }
                    enzon.seekg(wep_pos + 491, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 491, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND" || *ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(244, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_90(aGen);
                    }
                    enzon.seekg(wep_pos + 492, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 492, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND" || *ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(244, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_91(aGen);
                    }
                    enzon.seekg(wep_pos + 493, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 493, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND" || *ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(244, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_92(aGen);
                    }
                    enzon.seekg(wep_pos + 494, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 494, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND" || *ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(244, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_93(aGen);
                    }
                    enzon.seekg(wep_pos + 495, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 495, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND" || *ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(244, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_94(aGen);
                    }
                    enzon.seekg(wep_pos + 496, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 496, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 15);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND" || *ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(244, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_95(aGen);
                    }
                    enzon.seekg(wep_pos + 497, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 497, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(231, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_96(aGen);
                    }
                    enzon.seekg(wep_pos + 500, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 500, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(231, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_97(aGen);
                    }
                    enzon.seekg(wep_pos + 501, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 501, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(231, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_98(aGen);
                    }
                    enzon.seekg(wep_pos + 502, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 502, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(231, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_99(aGen);
                    }
                    enzon.seekg(wep_pos + 503, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 503, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(231, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_100(aGen);
                    }
                    enzon.seekg(wep_pos + 504, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 504, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(231, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_101(aGen);
                    }
                    enzon.seekg(wep_pos + 505, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 505, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 10);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 30);
                            }
                        }
                        else {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(231, 255);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(246, 255);
                            }
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_102(aGen);
                    }
                    enzon.seekg(wep_pos + 506, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 506, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_103(aGen);
                    enzon.seekg(wep_pos + 508, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + 508, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                }
                loop_diff = 513;
                for (int i = 0; i < 6; i++) {
                    if (i == 0 || i == 1) {
                        dist_104 = std::uniform_int_distribution<>(0, (ene_hp_stat / 2));
                    }
                    else if (i == 2) {
                        dist_104 = std::uniform_int_distribution<>(0, (ene_hp_stat / 3));
                    }
                    else if (i == 3) {
                        dist_104 = std::uniform_int_distribution<>(0, ene_hp_stat / (100 / 75));
                    }
                    else if (i == 4) {
                        dist_104 = std::uniform_int_distribution<>(0, ene_hp_stat / (100 / 60));
                    }
                    else if (i == 5) {
                        enzon.seekg(wep_pos + loop_diff, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        enzon.seekg(wep_pos + loop_diff + 1, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass2 = enzon.get();
                        if (to_ass == 0 && to_ass2 == 0) {
                            break;
                        }
                        else {
                            dist_104 = std::uniform_int_distribution<>(0, ene_hp_stat / (100 / 30));
                        }
                    }
                    stat = dist_104(aGen);
                    sprintf_s(rand_hp, "%X", stat);
                    ss_rand_hp << rand_hp;
                    ss_rand_hp >> s_rand_hp;
                    ss_rand_hp.clear();
                    hs_rand_hp << std::hex << s_rand_hp;
                    hs_rand_hp >> int_rand_hp;
                    hs_rand_hp.clear();
                    s1 = "0";
                    if (stat > 255) {
                        s2 = s_rand_hp.at(0);
                        s3 = s_rand_hp.at(1);
                        s4 = s_rand_hp.at(2);
                    }
                    else if (stat > 16) {
                        s2 = "0";
                        s3 = s_rand_hp.at(0);
                        s4 = s_rand_hp.at(1);
                    }
                    else {
                        s2 = "0";
                        s3 = "0";
                        s4 = s_rand_hp.at(0);
                    }
                    s_rand_hp2 = s1 + s2;
                    s_rand_hp1 = s3 + s4;
                    fin_rand_hp << std::hex << s_rand_hp2;
                    fin_rand_hp >> stat;
                    fin_rand_hp.clear();
                    enzon.seekg(wep_pos + loop_diff, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    fin_rand_hp << std::hex << s_rand_hp1;
                    fin_rand_hp >> stat;
                    fin_rand_hp.clear();
                    enzon.seekg(wep_pos + loop_diff - 1, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff - 1, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_105(aGen);
                    enzon.seekg(wep_pos + loop_diff + 1, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 1, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    stat = dist_106(aGen);
                    enzon.seekg(wep_pos + loop_diff + 2, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 2, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 35);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 38);
                            }      
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 60);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 55);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(226, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_107(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 4, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 4, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 35);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 38);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 60);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 55);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(226, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_108(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 5, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 5, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 35);
                            }
                            else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 38);
                            }
                            else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 60);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 55);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(226, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_109(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 6, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 6, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 75);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 100);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(223, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_110(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 7, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 7, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 75);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 100);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(223, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_111(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 8, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 8, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 75);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 100);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(223, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_112(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 9, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 9, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 75);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 100);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(223, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_113(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 10, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 10, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 75);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 100);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(223, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_114(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 11, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 11, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 75);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 100);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(223, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_115(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 12, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 12, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    if (balDecision == "Y") {
                        stat = dist_11(aGen);
                        if (stat == 1) {
                            if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                dist_20 = std::uniform_int_distribution<>(0, 75);
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(0, 100);
                            }
                        }
                        else {
                            dist_20 = std::uniform_int_distribution<>(223, 255);
                        }
                        stat = dist_20(aGen);
                    }
                    else {
                        stat = dist_116(aGen);
                    }
                    enzon.seekg(wep_pos + loop_diff + 13, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    ch_val = new char(stat);
                    enzon.seekp(wep_pos + loop_diff + 13, ios::beg);
                    enzon.write(ch_val, 1);
                    delete ch_val;
                    enzon.seekg(wep_pos + loop_diff + 35, ios::beg);
                    stat_loc = enzon.tellg();
                    to_ass = enzon.get();
                    if (to_ass > 0) {
                        if (i == 0 || i == 1) {
                            stat = dist_117(aGen);
                        }
                        else if (i == 2) {
                            stat = dist_137(aGen);
                        }
                        else if (i == 3) {
                            stat = dist_138(aGen);
                        }
                        else if (i == 4) {
                            stat = dist_139(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 31, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 31, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat -= 126;
                        enzon.seekg(wep_pos + loop_diff + 33, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 33, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (i != 3) {
                            stat = dist_118(aGen);
                        }
                        else {
                            stat = dist_140(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 36, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 36, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (i != 3) {
                            stat = dist_119(aGen);
                        }
                        else {
                            stat = dist_141(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 37, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 37, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                stat = 0;
                            }
                            else {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(253, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(252, 255);
                                }
                                stat = dist_20(aGen);
                            }
                        }
                        else {
                            stat = dist_120(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 38, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 38, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_67(aGen) * 100;
                        sprintf_s(rand_dpm, "%X", stat);
                        ss_rand_dpm << rand_dpm;
                        ss_rand_dpm >> s_rand_dpm;
                        ss_rand_dpm.clear();
                        hs_rand_dpm << std::hex << s_rand_dpm;
                        hs_rand_dpm >> int_rand_dpm;
                        hs_rand_dpm.clear();
                        dist_68 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
                        stat = dist_68(aGen) * 100;
                        sprintf_s(rand_dp, "%X", stat);
                        ss_rand_dp << rand_dp;
                        ss_rand_dp >> s_rand_dp;
                        ss_rand_dp.clear();
                        s1 = s_rand_dpm.at(0);
                        s2 = s_rand_dpm.at(1);
                        s3 = s_rand_dpm.at(2);
                        s4 = s_rand_dpm.at(3);
                        s_rand_dpm_1 = s1 + s2;
                        s_rand_dpm_2 = s3 + s4;
                        s1 = s_rand_dp.at(0);
                        s2 = s_rand_dp.at(1);
                        s3 = s_rand_dp.at(2);
                        s4 = s_rand_dp.at(3);
                        s_rand_dp_1 = s1 + s2;
                        s_rand_dp_2 = s3 + s4;
                        rand_dpm_fin << std::hex << s_rand_dpm_1;
                        rand_dpm_fin >> stat;
                        rand_dpm_fin.clear();
                        enzon.seekg(wep_pos + loop_diff + 40, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 40, ios::beg);
                        enzon.write(ch_val, 1);
                        enzon.seekg(wep_pos + loop_diff + 42, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 42, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        rand_dpm_fin << std::hex << s_rand_dpm_2;
                        rand_dpm_fin >> stat;
                        rand_dpm_fin.clear();
                        enzon.seekg(wep_pos + loop_diff + 39, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 39, ios::beg);
                        enzon.write(ch_val, 1);
                        enzon.seekg(wep_pos + loop_diff + 41, ios::beg);
                        map_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 41, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_121(aGen);
                        enzon.seekg(wep_pos + loop_diff + 60, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 60, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_122(aGen);
                        enzon.seekg(wep_pos + loop_diff + 61, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 61, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_123(aGen);
                        enzon.seekg(wep_pos + loop_diff + 62, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 62, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 1);
                                }
                                else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 20);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 27);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_124(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 63, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 63, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 1);
                                }
                                else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 20);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 27);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_125(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 64, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 64, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 1);
                                }
                                else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 20);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 27);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_126(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 65, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 65, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 1);
                                }
                                else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 20);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 27);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_127(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 66, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 66, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 1);
                                }
                                else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 20);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 27);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_128(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 67, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 67, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 1);
                                }
                                else if (*ezp == "ZONE032.ZND" || *ezp == "ZONE036.ZND" || *ezp == "ZONE028.ZND" || *ezp == "ZONE048.ZND" || *ezp == "ZONE050.ZND" || *ezp == "ZONE040.ZND" || *ezp == "ZONE049.ZND" || *ezp == "ZONE051.ZND" || *ezp == "ZONE053.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 20);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 27);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                            }
                            else {
                                dist_20 = std::uniform_int_distribution<>(251, 255);
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_129(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 68, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 68, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 10);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 23);
                                }
                            }
                            else {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(239, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_130(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 71, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 71, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 10);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 23);
                                }
                            }
                            else {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(239, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_131(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 72, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 72, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 10);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 23);
                                }
                            }
                            else {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(239, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_132(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 73, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 73, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 10);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 23);
                                }
                            }
                            else {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(239, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_133(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 74, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 74, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 10);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 23);
                                }
                            }
                            else {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(239, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_134(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 75, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 75, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 10);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 23);
                                }
                            }
                            else {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(239, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_135(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 76, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 76, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        if (balDecision == "Y") {
                            stat = dist_11(aGen);
                            if (stat == 1) {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 10);
                                }
                                else if (*ezp == "ZONE041.ZND" || *ezp == "ZONE052.ZND" || *ezp == "ZONE054.ZND" || *ezp == "ZONE055.ZND" || *ezp == "ZONE056.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(0, 24);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(0, 23);
                                }
                            }
                            else {
                                if (*ezp == "ZONE009.ZND" || *ezp == "ZONE011.ZND" || *ezp == "ZONE012.ZND" || *ezp == "ZONE013.ZND" || *ezp == "ZONE014.ZND" || *ezp == "ZONE015.ZND" || *ezp == "ZONE016.ZND" || *ezp == "ZONE017.ZND") {
                                    dist_20 = std::uniform_int_distribution<>(251, 255);
                                }
                                else {
                                    dist_20 = std::uniform_int_distribution<>(239, 255);
                                }
                            }
                            stat = dist_20(aGen);
                        }
                        else {
                            stat = dist_136(aGen);
                        }
                        enzon.seekg(wep_pos + loop_diff + 77, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 77, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_81(aGen);
                        enzon.seekg(wep_pos + loop_diff + 79, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 79, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                        stat = dist_82(aGen);
                        enzon.seekg(wep_pos + loop_diff + 80, ios::beg);
                        stat_loc = enzon.tellg();
                        to_ass = enzon.get();
                        ch_val = new char(stat);
                        enzon.seekp(wep_pos + loop_diff + 80, ios::beg);
                        enzon.write(ch_val, 1);
                        delete ch_val;
                    }
                    loop_diff += 92;
                }
                wep_pos += 1124;
            }
            enzon.close();
            std::advance(ecp, 1);
            std::advance(ewop, 1);
            std::advance(ezp, 1);
            eneBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_zone + " '" + file + "'") << std::endl;
        }
    }
    eneBat.close();
}
