//Reinforcements? He is the reinforcements!

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
#include "Ashley.h"
#include <algorithm>

using namespace std;

Ashley::Ashley() {
	//Ashley
}

void Ashley::statIterate(Reference_Files aRF, Add_Game& aGame, std::mt19937 aGen, string aDecision, string secondDecision, string thirdDecision) {
    string file;
    string ashStat = aGame.getStringPath() + "\\MISC\\INITBTL.PRG";
    string ashEqu = aGame.getStringPath() + "\\MISC\\TITLE.PRG";
    string s_rand_hp;
    string s_rand_mp;
    string s_rand_hp1;
    string s_rand_hp2;
    string s_rand_mp1;
    string s_rand_mp2;
    string s1;
    string s2;
    string s3;
    string s4;
    string s_rand_dpm;
    string s_rand_dpm_1;
    string s_rand_dpm_2;
    string s_rand_dp;
    string s_rand_dp_1;
    string s_rand_dp_2;
	
    int start;
    int statStart = 4916;
    int equStart = 50827;
    int stat;
    int ash_hp_stat;
    int int_rand_hp;
    int int_rand_mp;
    int to_ass;
    int to_ass2;
    int int_rand_dpm;
    int ppm;
    int pp;
    int gem_count;
    int loop_tracker;
    int loop_diff;
    int cho_blade = 2;
    int cho_grip = 1;

    char* ch_val;
    char rand_hp[20];
    char rand_mp[20];
    char rand_dp[20];
    char rand_dpm[20];

    std::stringstream ss_rand_hp;
    std::stringstream ss_rand_mp;
    std::stringstream hs_rand_hp;
    std::stringstream hs_rand_mp;
    std::stringstream fin_rand_hp;
    std::stringstream fin_rand_mp;
    std::stringstream rand_dpm_fin;
    std::stringstream ss_rand_dpm;
    std::stringstream ss_rand_dp;
    std::stringstream hs_rand_dpm;

    std::ofstream ashBat;

    std::streampos stat_loc;

    fstream map;


	std::uniform_int_distribution<> dist_1;
    std::uniform_int_distribution<> dist_2;
    std::uniform_int_distribution<> dist_3;
    std::uniform_int_distribution<> dist_4;
    std::uniform_int_distribution<> dist_5;
    std::uniform_int_distribution<> dist_6 = std::uniform_int_distribution<>(10, 14);
    std::uniform_int_distribution<> dist_7 = std::uniform_int_distribution<>(20, 28);
    std::uniform_int_distribution<> dist_8 = std::uniform_int_distribution<>(1, 9);
    std::uniform_int_distribution<> dist_9;
    std::uniform_int_distribution<> dist_10;
    std::uniform_int_distribution<> dist_11;
    std::uniform_int_distribution<> dist_12 = std::uniform_int_distribution<>(1, 2);
    std::uniform_int_distribution<> dist_13;
    std::uniform_int_distribution<> dist_14 = std::uniform_int_distribution<>(41, 327);
    std::uniform_int_distribution<> dist_15 = std::uniform_int_distribution<>(100, 250);
    std::uniform_int_distribution<> dist_16;
    std::uniform_int_distribution<> dist_17 = std::uniform_int_distribution<>(1, 3);
    std::uniform_int_distribution<> dist_18 = std::uniform_int_distribution<>(1, 4);
    std::uniform_int_distribution<> dist_19 = std::uniform_int_distribution<>(1, 255);
    std::uniform_int_distribution<> dist_20 = std::uniform_int_distribution<>(1, 255);
    std::uniform_int_distribution<> dist_21 = std::uniform_int_distribution<>(1, 255);
    std::uniform_int_distribution<> dist_22 = std::uniform_int_distribution<>(1, 255);
    std::uniform_int_distribution<> dist_23;
    std::uniform_int_distribution<> dist_24;
    std::uniform_int_distribution<> dist_25;
    std::uniform_int_distribution<> dist_26;
    std::uniform_int_distribution<> dist_27;
    std::uniform_int_distribution<> dist_28 = std::uniform_int_distribution<>(0, 3);
    std::uniform_int_distribution<> dist_29 = std::uniform_int_distribution<>(5, 51);
    std::uniform_int_distribution<> dist_30;
    std::uniform_int_distribution<> dist_31;
    std::uniform_int_distribution<> dist_32 = std::uniform_int_distribution<>(1, 255);
    std::uniform_int_distribution<> dist_33;
    std::uniform_int_distribution<> dist_34 = std::uniform_int_distribution<>(0, 255);
    std::uniform_int_distribution<> dist_35 = std::uniform_int_distribution<>(127, 142);
    std::uniform_int_distribution<> dist_36;
    std::uniform_int_distribution<> dist_37;
    std::uniform_int_distribution<> dist_38;
    std::uniform_int_distribution<> dist_39 = std::uniform_int_distribution<>(41, 327);
    std::uniform_int_distribution<> dist_40;
    std::uniform_int_distribution<> dist_41 = std::uniform_int_distribution<>(100, 250);
    std::uniform_int_distribution<> dist_42;
    std::uniform_int_distribution<> dist_43;
    std::uniform_int_distribution<> dist_44;
    std::uniform_int_distribution<> dist_45;
    std::uniform_int_distribution<> dist_46;
    std::uniform_int_distribution<> dist_47 = std::uniform_int_distribution<>(223, 253);
    std::uniform_int_distribution<> dist_48;
    std::uniform_int_distribution<> dist_49 = std::uniform_int_distribution<>(0, 255);
    std::uniform_int_distribution<> dist_50;
    std::uniform_int_distribution<> dist_51;
    std::uniform_int_distribution<> dist_52;
    std::uniform_int_distribution<> dist_53;
    std::uniform_int_distribution<> dist_54;
    std::uniform_int_distribution<> dist_55;
    std::uniform_int_distribution<> dist_56 = std::uniform_int_distribution<>(191, 206);
    std::uniform_int_distribution<> dist_57 = std::uniform_int_distribution<>(143, 158);
    std::uniform_int_distribution<> dist_58 = std::uniform_int_distribution<>(159, 174);
    std::uniform_int_distribution<> dist_59 = std::uniform_int_distribution<>(175, 190);
    std::uniform_int_distribution<> dist_60;
    std::uniform_int_distribution<> dist_61;
    std::uniform_int_distribution<> dist_62 = std::uniform_int_distribution<>(41, 327);;
    std::uniform_int_distribution<> dist_63;
    std::uniform_int_distribution<> dist_64;
    std::uniform_int_distribution<> dist_65;
    std::uniform_int_distribution<> dist_66;
    std::uniform_int_distribution<> dist_67;
    std::uniform_int_distribution<> dist_68;
    std::uniform_int_distribution<> dist_69;

	ashBat.open("ashCmd.cmd", std::ios::trunc);
	ashBat << ("cd " + aGame.getStringPath() + " \n");


	if (aDecision == "Y") {
		dist_1 = std::uniform_int_distribution<>(40, 480);
        dist_2 = std::uniform_int_distribution<>(5, 130);
        dist_3 = std::uniform_int_distribution<>(90, 112);
        dist_4 = std::uniform_int_distribution<>(48, 127);
        dist_5 = std::uniform_int_distribution<>(75, 132);
        dist_10 = std::uniform_int_distribution<>(1, 14);
        dist_11 = std::uniform_int_distribution<>(1, 4);
        dist_24 = std::uniform_int_distribution<>(0, 12);
        dist_25 = std::uniform_int_distribution<>(0, 12);
        dist_26 = std::uniform_int_distribution<>(253, 255);
        dist_27 = std::uniform_int_distribution<>(0, 13);
        dist_30 = std::uniform_int_distribution<>(0, 5);
        dist_33 = std::uniform_int_distribution<>(3, 4);
        dist_36 = std::uniform_int_distribution<>(4, 9);
        dist_37 = std::uniform_int_distribution<>(4, 9);
        dist_38 = std::uniform_int_distribution<>(253, 255);
        dist_43 = std::uniform_int_distribution<>(0, 10);
        dist_44 = std::uniform_int_distribution<>(251, 255);
        dist_46 = std::uniform_int_distribution<>(1, 4);
        dist_48 = std::uniform_int_distribution<>(1, 3);
        dist_53 = std::uniform_int_distribution<>(0, 251);
        dist_60 = std::uniform_int_distribution<>(1, 13);
        dist_64 = std::uniform_int_distribution<>(0, 5);
	}
	else {
		dist_1 = std::uniform_int_distribution<>(1, 999);
		dist_2 = std::uniform_int_distribution<>(1, 999);
		dist_3 = std::uniform_int_distribution<>(1, 255);
		dist_4 = std::uniform_int_distribution<>(1, 255);
		dist_5 = std::uniform_int_distribution<>(1, 255);
        dist_10 = std::uniform_int_distribution<>(1, 255);
        dist_11 = std::uniform_int_distribution<>(1, 255);
        dist_24 = std::uniform_int_distribution<>(0, 255);
        dist_25 = std::uniform_int_distribution<>(0, 255);
        dist_26 = std::uniform_int_distribution<>(1, 255);
        dist_27 = std::uniform_int_distribution<>(0, 255);
        dist_30 = std::uniform_int_distribution<>(0, 255);
        dist_31 = std::uniform_int_distribution<>(1, 255);
        dist_33 = std::uniform_int_distribution<>(3, 7);
        dist_36 = std::uniform_int_distribution<>(1, 255);
        dist_37 = std::uniform_int_distribution<>(1, 255);
        dist_38 = std::uniform_int_distribution<>(1, 255);
        dist_43 = std::uniform_int_distribution<>(0, 255);
        dist_44 = std::uniform_int_distribution<>(0, 255);
        dist_45 = std::uniform_int_distribution<>(0, 255);
        dist_46 = std::uniform_int_distribution<>(1, 7);
        dist_48 = std::uniform_int_distribution<>(0, 255);
        dist_53 = std::uniform_int_distribution<>(0, 255);
        dist_60 = std::uniform_int_distribution<>(0, 255);
        dist_64 = std::uniform_int_distribution<>(0, 255);
	}
    if (thirdDecision == "L") {
        dist_3, dist_4, dist_5 = std::uniform_int_distribution<>(75, 125);
    }
    else if (thirdDecision == "M") {
        dist_3, dist_4, dist_5 = std::uniform_int_distribution<>(50, 150);
    }
    else if (thirdDecision == "H") {
        dist_3, dist_4, dist_5 = std::uniform_int_distribution<>(25, 175);
    }
    file = ashStat;
    start = statStart;
	map.open(file, ios::in | ios::out | ios::binary | ios::ate);
    stat = dist_1(aGen);
    ash_hp_stat = stat;
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
    map.seekg(start, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekg(start, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    fin_rand_hp << std::hex << s_rand_hp2;
    fin_rand_hp >> stat;
    fin_rand_hp.clear();
    map.seekg(start + 1, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekg(start + 1, ios::beg);
    map.write(ch_val, 1);
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
    map.seekg(start + 2, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 2, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    fin_rand_mp << std::hex << s_rand_mp2;
    fin_rand_mp >> stat;
    fin_rand_mp.clear();
    map.seekg(start + 3, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 3, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_3(aGen);
    map.seekg(start + 4, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 4, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_4(aGen);
    map.seekg(start + 5, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 5, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_5(aGen);
    map.seekg(start + 6, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 6, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_6(aGen);
    map.seekg(start + 9, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 9, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_7(aGen);
    map.seekg(start + 11, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 11, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    map.close();
    file = ashEqu;
    start = equStart;
    map.open(file, ios::in | ios::out | ios::binary | ios::ate);
    if (secondDecision == "Y") {
        stat = dist_8(aGen);
        map.seekg(start + 28, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 28, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        if (stat == 1) {
            dist_9 = std::uniform_int_distribution<>(1, 12);
        }
        else if (stat == 2) {
            dist_9 = std::uniform_int_distribution<>(13, 24);
        }
        else if (stat == 3) {
            dist_9 = std::uniform_int_distribution<>(25, 34);
        }
        else if (stat == 4) {
            dist_9 = std::uniform_int_distribution<>(35, 50);
        }
        else if (stat == 5) {
            dist_9 = std::uniform_int_distribution<>(51, 56);
        }
        else if (stat == 6) {
            dist_9 = std::uniform_int_distribution<>(57, 62);
        }
        else if (stat == 7) {
            dist_9 = std::uniform_int_distribution<>(63, 69);
        }
        else if (stat == 8) {
            dist_9 = std::uniform_int_distribution<>(70, 82);
        }
        else if (stat == 9) {
            dist_9 = std::uniform_int_distribution<>(83, 90);
        }
        cho_blade = stat;
        cho_grip = stat;
        stat = dist_9(aGen);
        map.seekg(start + 25, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 25, ios::beg);
        map.write(ch_val, 1);
        map.seekg(start + 26, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        map.seekp(start + 26, ios::beg);
        map.write(ch_val, 1);
        map.seekg(start + 27, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        map.seekp(start + 27, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    stat = dist_10(aGen);
    map.seekg(start + 37, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 37, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_11(aGen);
    map.seekg(start + 38, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 38, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    if (aDecision == "Y") {
        stat = dist_12(aGen);
        if (stat == 1) {
            stat = 0;
        }
        else {
            if (cho_blade == 1) {
                dist_13 = std::uniform_int_distribution<>(254, 255);
            }
            else if (cho_blade == 2 || cho_blade == 5 || cho_blade == 8 || cho_blade == 9) {
                dist_13 = std::uniform_int_distribution<>(250, 255);
            }
            else if (cho_blade == 3) {
                dist_13 = std::uniform_int_distribution<>(249, 255);
            }
            else if (cho_blade == 4) {
                dist_13 = std::uniform_int_distribution<>(251, 255);
            }
            else if (cho_blade == 6) {
                dist_13 = std::uniform_int_distribution<>(252, 255);
            }
            else if (cho_blade == 7) {
                dist_13 = std::uniform_int_distribution<>(248, 255);
            }
            stat = dist_13(aGen);
        }
    }
    else {
        dist_13 = std::uniform_int_distribution<>(0, 255);
        stat = dist_13(aGen);
    }
    map.seekg(start + 39, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 39, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_14(aGen) * 100;
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
    map.seekg(start + 30, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekg(start + 30, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    rand_dpm_fin << std::hex << s_rand_dpm_2;
    rand_dpm_fin >> stat;
    rand_dpm_fin.clear();
    map.seekg(start + 29, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekg(start + 29, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    ppm = dist_15(aGen);
    map.seekg(start + 31, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(ppm);
    map.seekp(start + 31, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    rand_dpm_fin << std::hex << s_rand_dp_1;
    rand_dpm_fin >> stat;
    rand_dpm_fin.clear();
    map.seekg(start + 34, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 34, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    rand_dpm_fin << std::hex << s_rand_dp_2;
    rand_dpm_fin >> stat;
    rand_dpm_fin.clear();
    map.seekg(start + 33, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 33, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    dist_16 = std::uniform_int_distribution<>(1, ppm);
    pp = dist_16(aGen);
    map.seekg(start + 35, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(pp);
    map.seekp(start + 35, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = (4 * dist_17(aGen)) + dist_18(aGen);
    map.seekg(start + 41, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 41, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_19(aGen);
    map.seekg(start + 40, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 40, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    for (int i = 0; i < 3; i++) {
        if (aDecision == "N") {
            stat = dist_20(aGen);
        }
        else {
            if (cho_blade == 1) {
                stat = 1;
            }
            else if (cho_blade == 4) {
                stat = 3;
            }
            else if (cho_blade == 5) {
                stat = 4;
            }
            else {
                if (cho_blade == 2) {
                    dist_20 = std::uniform_int_distribution<>(3, 5);
                }
                if (cho_blade == 3) {
                    dist_20 = std::uniform_int_distribution<>(4, 6);
                }
                if (cho_blade == 6) {
                    dist_20 = std::uniform_int_distribution<>(2, 3);
                }
                if (cho_blade == 7) {
                    dist_20 = std::uniform_int_distribution<>(4, 7);
                }
                if (cho_blade == 8) {
                    dist_20 = std::uniform_int_distribution<>(5, 6);
                }
                if (cho_blade == 9) {
                    dist_20 = std::uniform_int_distribution<>(9, 12);
                }
                stat = dist_20(aGen);
            }
        }
        map.seekg(start + (45 + i), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + (45 + i), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    for (int i = 0; i < 6; i++) {
        if (aDecision == "Y") {
            stat = dist_12(aGen);
            if (stat == 1) {
                dist_21 = std::uniform_int_distribution<>(0, 14);
            }
            else {
                dist_21 = std::uniform_int_distribution<>(236, 255);
            }
        }
        stat = dist_21(aGen);
        map.seekg(start + (49 + i), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + (49 + i), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    for (int i = 0; i < 7; i++) {
        if (aDecision == "Y") {
            stat = dist_12(aGen);
            if (stat == 1) {
                dist_22 = std::uniform_int_distribution<>(0, 10);
            }
            else {
                dist_22 = std::uniform_int_distribution<>(253, 255);
            }
        }
        stat = dist_22(aGen);
        map.seekg(start + (57 + i), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + (57 + i), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    if (secondDecision == "Y") {
        map.seekg(start + 732, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        if (cho_grip >= 1 && cho_grip <= 3) {
            stat = 1;
        }
        else if (cho_grip >= 4 && cho_grip <= 7) {
            stat = 2;
        }
        else if (cho_grip == 8) {
            stat = 3;
        }
        else if (cho_grip == 9) {
            stat = 4;
        }
        cho_grip = stat;
        ch_val = new char(stat);
        map.seekp(start + 732, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        if (cho_grip == 1) {
            dist_23 = std::uniform_int_distribution<>(96, 104);
        }
        else if (cho_grip == 2) {
            dist_23 = std::uniform_int_distribution<>(105, 114);
        }
        else if (cho_grip == 3) {
            dist_23 = std::uniform_int_distribution<>(115, 120);
        }
        else if (cho_grip == 4) {
            dist_23 = std::uniform_int_distribution<>(121, 126);
        }
        stat = dist_23(aGen);
        map.seekg(start + 729, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 729, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        stat -= 95;
        map.seekg(start + 731, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 731, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    stat = dist_24(aGen);
    map.seekg(start + 734, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 734, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_25(aGen);
    map.seekg(start + 735, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 735, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    if (secondDecision == "Y") {
        if (cho_grip == 1) {
            dist_26 = std::uniform_int_distribution<>(252, 254);
        }
        else if (cho_grip == 2) {
            dist_26 = std::uniform_int_distribution<>(251, 253);
        }
        else if (cho_grip == 3) {
            dist_26 = std::uniform_int_distribution<>(250, 252);
        }
        else if (cho_grip == 4) {
            dist_26 = std::uniform_int_distribution<>(253, 254);
        }
    }
    stat = dist_26(aGen);
    map.seekg(start + 736, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 736, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    for (int i = 0; i < 3; i++) {
        stat = dist_27(aGen);
        map.seekg(start + (738 + i), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + (738 + i), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    stat = dist_33(aGen);
    map.seekg(start + 264, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 264, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat = dist_47(aGen);
    map.seekg(start + 1185, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 1185, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    stat -= 126;
    map.seekg(start + 1186, ios::beg);
    stat_loc = map.tellg();
    to_ass = map.get();
    ch_val = new char(stat);
    map.seekp(start + 1186, ios::beg);
    map.write(ch_val, 1);
    delete ch_val;
    for (int i = 0; i < 3; i++) {
        stat = dist_48(aGen);
        map.seekg((start + 1198 + i), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp((start + 1198 + i), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    for (int i = 0; i < 3; i++) {
        if (aDecision == "Y") {
            stat = 0;
        }
        else {
            stat = dist_49(aGen);
        }
        map.seekg((start + 1202 + i), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp((start + 1202 + i), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    for (int i = 0; i < 6; i++) {
        if (aDecision == "Y") {
            stat = dist_12(aGen);
            if (stat == 1) {
                dist_50 = std::uniform_int_distribution<>(0, 10);
            }
            else {
                dist_50 = std::uniform_int_distribution<>(246, 255);
            }
        }
        else {
            dist_50 = std::uniform_int_distribution<>(0, 255);
        }
        stat = dist_50(aGen);
        map.seekg((start + 1205 + i), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp((start + 1205 + i), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    for (int i = 0; i < 7; i++) {
        if (aDecision == "Y") {
            stat = dist_12(aGen);
            if (stat == 1) {
                dist_51 = std::uniform_int_distribution<>(0, 10);
            }
            else {
                dist_51 = std::uniform_int_distribution<>(251, 255);
            }
        }
        else {
            dist_51 = std::uniform_int_distribution<>(0, 255);
        }
        stat = dist_51(aGen);
        map.seekg((start + 1213 + i), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp((start + 1213 + i), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
    }
    loop_diff = 541;
    for (int i = 0; i < 6; i++) {
        map.close();
        file = ashStat;
        start = statStart;
        map.open(file, ios::in | ios::out | ios::binary | ios::ate);
        if (i == 0 || i == 1) {
            stat = ash_hp_stat / 2;
        }
        else if (i == 2) {
            stat = ash_hp_stat / 3;
        }
        else if (i == 3) {
            stat = ash_hp_stat / (100 / 75);
        }
        else if (i == 4) {
            stat = ash_hp_stat / (100 / 60);
        }
        else if (i == 5) {
            map.seekg(start + loop_diff, ios::beg);
            stat_loc = map.tellg();
            to_ass = map.get();
            map.seekg(start + loop_diff + 1, ios::beg);
            stat_loc = map.tellg();
            to_ass2 = map.get();
            if (to_ass == 0 && to_ass2 == 0) {
                break;
            }
            else {
                stat = ash_hp_stat / (100 / 30);
            }
        }
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
        map.seekg(start + loop_diff, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + loop_diff, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        fin_rand_hp << std::hex << s_rand_hp1;
        fin_rand_hp >> stat;
        fin_rand_hp.clear();
        map.seekg(start + loop_diff - 1, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + loop_diff - 1, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        stat = dist_53(aGen);
        map.seekg(start + loop_diff + 1, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + loop_diff + 1, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        stat = dist_53(aGen);
        map.seekg(start + loop_diff + 2, ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + loop_diff + 2, ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        for (int i2 = 0; i2 < 3; i2++) {
            if (aDecision == "Y") {
                stat = dist_12(aGen);
                if (stat == 1) {
                    dist_54 = std::uniform_int_distribution<>(0, 35);
                }
                else {
                    dist_54 = std::uniform_int_distribution<>(226, 255);
                }
            }
            else {
                dist_54 = std::uniform_int_distribution<>(0, 255);
            }
            stat = dist_54(aGen);
            map.seekg((start + loop_diff + 4 + i2), ios::beg);
            stat_loc = map.tellg();
            to_ass = map.get();
            ch_val = new char(stat);
            map.seekp((start + loop_diff + 4 + i2), ios::beg);
            map.write(ch_val, 1);
            delete ch_val;
        }
        for (int i2 = 0; i2 < 7; i2++) {
            if (aDecision == "Y") {
                stat = dist_12(aGen);
                if (stat == 1) {
                    dist_55 = std::uniform_int_distribution<>(0, 75);
                }
                else {
                    dist_55 = std::uniform_int_distribution<>(223, 255);
                }
            }
            else {
                dist_55 = std::uniform_int_distribution<>(0, 255);
            }
            stat = dist_55(aGen);
            map.seekg((start + loop_diff + 7 + i2), ios::beg);
            stat_loc = map.tellg();
            to_ass = map.get();
            ch_val = new char(stat);
            map.seekp((start + loop_diff + 7 + i2), ios::beg);
            map.write(ch_val, 1);
            delete ch_val;
        }
        map.close();
        file = ashEqu;
        start = equStart;
        map.open(file, ios::in | ios::out | ios::binary | ios::ate);
        if (i == 0 || i == 1) {
            stat = dist_56(aGen);
        }
        else if (i == 2) {
            stat = dist_57(aGen);
        }
        else if (i == 3) {
            stat = dist_58(aGen);
        }
        else if (i == 4) {
            stat = dist_59(aGen);
        }
        map.seekg(start + 985 + (i * 40), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 985 + (i * 40), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        stat -= 126;
        map.seekg(start + 986 + (i * 40), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 986 + (i * 40), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        for (int i2 = 0; i2 < 2; i2++) {
            stat = dist_60(aGen);
            map.seekg((start + 998 + (i * 40) + i2), ios::beg);
            stat_loc = map.tellg();
            to_ass = map.get();
            ch_val = new char(stat);
            map.seekp((start + 998 + (i * 40) + i2), ios::beg);
            map.write(ch_val, 1);
            delete ch_val;
        }
        if (aDecision == "Y") {
            stat = dist_11(aGen);
            if (stat == 1) {
                stat = 0;
            }
            else {
                dist_61 = std::uniform_int_distribution<>(253, 255);
                stat = dist_61(aGen);
            }
        }
        else {
            dist_61 = std::uniform_int_distribution<>(0, 255);
            stat = dist_61(aGen);
        }
        map.seekg(start + 1000 + (i * 40), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 1000 + (i * 40), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        stat = dist_62(aGen) * 100;
        sprintf_s(rand_dpm, "%X", stat);
        ss_rand_dpm << rand_dpm;
        ss_rand_dpm >> s_rand_dpm;
        ss_rand_dpm.clear();
        hs_rand_dpm << std::hex << s_rand_dpm;
        hs_rand_dpm >> int_rand_dpm;
        hs_rand_dpm.clear();
        dist_63 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
        stat = dist_63(aGen) * 100;
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
        map.seekg(start + 990 + (i * 40), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 990 + (i * 40), ios::beg);
        map.write(ch_val, 1);
        rand_dpm_fin << std::hex << s_rand_dpm_2;
        rand_dpm_fin >> stat;
        rand_dpm_fin.clear();
        map.seekg(start + 989 + (i * 40), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 989 + (i * 40), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        rand_dpm_fin << std::hex << s_rand_dp_1;
        rand_dpm_fin >> stat;
        rand_dpm_fin.clear();
        map.seekg(start + 994 + (i * 40), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 994 + (i * 40), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        rand_dpm_fin << std::hex << s_rand_dp_2;
        rand_dpm_fin >> stat;
        rand_dpm_fin.clear();
        map.seekg(start + 993 + (i * 40), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 993 + (i * 40), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        for (int i2 = 0; i2 < 3; i2++) {
            stat = dist_64(aGen);
            map.seekg((start + 1002 + (i * 40) + i2), ios::beg);
            stat_loc = map.tellg();
            to_ass = map.get();
            ch_val = new char(stat);
            map.seekp((start + 1002 + (i * 40) + i2), ios::beg);
            map.write(ch_val, 1);
            delete ch_val;
        }
        for (int i2 = 0; i2 < 6; i2++) {
            if (aDecision == "Y") {
                stat = dist_12(aGen);
                if (stat == 1) {
                    dist_65 = std::uniform_int_distribution<>(0, 1);
                }
                else {
                    dist_65 = std::uniform_int_distribution<>(251, 255);
                }
            }
            else {
                dist_65 = std::uniform_int_distribution<>(0, 255);
            }
            stat = dist_65(aGen);
            map.seekg((start + 1005 + (i * 40) + i2), ios::beg);
            stat_loc = map.tellg();
            to_ass = map.get();
            ch_val = new char(stat);
            map.seekp((start + 1005 + (i * 40) + i2), ios::beg);
            map.write(ch_val, 1);
            delete ch_val;
        }
        for (int i2 = 0; i2 < 7; i2++) {
            if (aDecision == "Y") {
                stat = dist_12(aGen);
                if (stat == 1) {
                    dist_66 = std::uniform_int_distribution<>(0, 10);
                }
                else {
                    dist_66 = std::uniform_int_distribution<>(251, 255);
                }
            }
            else {
                dist_66 = std::uniform_int_distribution<>(0, 255);
            }
            stat = dist_66(aGen);
            map.seekg((start + 1013 + (i * 40) + i2), ios::beg);
            stat_loc = map.tellg();
            to_ass = map.get();
            ch_val = new char(stat);
            map.seekp((start + 1013 + (i * 40) + i2), ios::beg);
            map.write(ch_val, 1);
            delete ch_val;
        }
        stat = dist_46(aGen);
        map.seekg(start + 1021 + (i * 40), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + 1021 + (i * 40), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        loop_diff += 92;
    }
    ashBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /BATTLE/INITBTL.PRG" + " '" + ashStat + "'") << std::endl;
    ashBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /TITLE/TITLE.PRG" + " '" + ashEqu + "'") << std::endl;
    ashBat.close();
}

void Ashley::miscIterate(Reference_Files aRF, Add_Game& aGame, string aDecision, std::mt19937 aGen) {
    string ashMisc = aGame.getStringPath() + "\\MISC\\TITLE.PRG";

    std::ofstream ashBat;

    ashBat.open("miscCmd.cmd", std::ios::trunc);
    ashBat << ("cd " + aGame.getStringPath() + " \n");

    fstream map;

    int stat;
    int start = 53796;
    int to_ass;

    char* ch_val;

    std::streampos stat_loc;

    std::uniform_int_distribution<> dist_1 = std::uniform_int_distribution<>(67, 233);
    std::uniform_int_distribution<> dist_2 = std::uniform_int_distribution<>(0, 1);
    std::uniform_int_distribution<> dist_3 = std::uniform_int_distribution<>(67, 100);
    std::uniform_int_distribution<> dist_4 = std::uniform_int_distribution<>(130, 139);
    std::uniform_int_distribution<> dist_5 = std::uniform_int_distribution<>(167, 200);
    std::uniform_int_distribution<> dist_6 = std::uniform_int_distribution<>(202, 233);
    std::uniform_int_distribution<> dist_7 = std::uniform_int_distribution<>(1, 99);

    map.open(ashMisc, ios::in | ios::out | ios::binary | ios::ate);
    for (int s = 0; s < 5; s++) {
        stat = dist_1(aGen);
        if (stat >= 101 && stat <= 129) {
            stat = dist_2(aGen);
            if (stat == 0) {
                stat = dist_3(aGen);
            }
            else {
                stat = dist_4(aGen);
            }
        }
        else if (stat >= 140 && stat <= 142) {
            stat = 139;
        }
        else if (stat >= 144 && stat <= 146) {
            stat = 143;
        }
        else if (stat >= 148 && stat <= 150) {
            stat = 147;
        }
        else if (stat >= 152 && stat <= 154) {
            stat = 151;
        }
        else if (stat >= 156 && stat <= 158) {
            stat = 155;
        }
        else if (stat >= 160 && stat <= 162) {
            stat = 159;
        }
        else if (stat >= 164 && stat <= 166) {
            stat = 163;
        }
        else if (stat == 201) {
            stat = dist_2(aGen);
            if (stat == 0) {
                stat = dist_5(aGen);
            }
            else {
                stat = dist_6(aGen);
            }
        }
        map.seekg(start + (s * 4), ios::beg);
        stat_loc = map.tellg();
        to_ass = map.get();
        ch_val = new char(stat);
        map.seekp(start + (s * 4), ios::beg);
        map.write(ch_val, 1);
        delete ch_val;
        if (aDecision == "Y" || stat >= 130)  {
            if (stat < 130 && aDecision == "Y") {
                stat = dist_7(aGen);
            }
            else {
                stat = 1;
            }
            map.seekg(start + (s * 4) + 2, ios::beg);
            stat_loc = map.tellg();
            to_ass = map.get();
            ch_val = new char(stat);
            map.seekp(start + (s * 4) + 2, ios::beg);
            map.write(ch_val, 1);
            delete ch_val;
        }
    }
    ashBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /TITLE/TITLE.PRG" + " '" + ashMisc + "'") << std::endl;
    ashBat.close(); 
}