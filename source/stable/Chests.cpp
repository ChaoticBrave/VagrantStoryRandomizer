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
#include "Chests.h"
#include <algorithm>

using namespace std;

Chests::Chests() {

}

void Chests::mapIterate(Reference_Files aRF, Add_Game& aGame, std::mt19937 aGen, string aChoice, string secondChoice, string thirdChoice) {
    vector<string> ml = aRF.getChestCheck();
    vector<string>::iterator mlp = ml.begin();
    list<string> mlks = aRF.getKSCheck();
    vector<int> unt = aRF.getUntitleds();

    
    string ivm = *mlp;
    string m_file;
    string cur_map;
    string s_rand_dpm;
    string s_rand_dp;
    string s_rand_dpm_1;
    string s_rand_dpm_2;
    string s_rand_dp_1;
    string s_rand_dp_2;
    string sp1;
    string sp2;
    string sp3;
    string sp4;

    

    fstream acmap;

    int size;
    int to_ass;
    int prop;
    int bla_nam;
    int gri_nam;
    int shi_nam;
    int arm_nam;
    int int_rand_dpm;
    int pp;
    int ppm;
    int p_53;
    int p_257;
    int misc_item;
    int choice;
    int cho_grip;
    int cho_blade;

    streampos map_loc;


    std::uniform_int_distribution<> dist_1 = std::uniform_int_distribution<>(1, 100);
    std::uniform_int_distribution<> dist_2 = std::uniform_int_distribution<>(1, 90);
    std::uniform_int_distribution<> dist_3 = std::uniform_int_distribution<>(1, 9);
    std::uniform_int_distribution<> dist_4 = std::uniform_int_distribution<>(41, 327);
    std::uniform_int_distribution<> dist_5;
    std::uniform_int_distribution<> dist_6 = std::uniform_int_distribution<>(100, 250);
    std::uniform_int_distribution<> dist_7;
    std::uniform_int_distribution<> dist_8 = std::uniform_int_distribution<>(0, 255);
    std::uniform_int_distribution<> dist_9 = std::uniform_int_distribution<>(1, 5);
    std::uniform_int_distribution<> dist_10 = std::uniform_int_distribution<>(1, 4);
    std::uniform_int_distribution<> dist_11 = std::uniform_int_distribution<>(1, 3);
    std::uniform_int_distribution<> dist_12 = std::uniform_int_distribution<>(1, 12);
    std::uniform_int_distribution<> dist_13 = std::uniform_int_distribution<>(1, 7);
    std::uniform_int_distribution<> dist_14 = std::uniform_int_distribution<>(253, 255);
    std::uniform_int_distribution<> dist_15 = std::uniform_int_distribution<>(1, 31);
    std::uniform_int_distribution<> dist_16 = std::uniform_int_distribution<>(1, 42);
    std::uniform_int_distribution<> dist_17 = std::uniform_int_distribution<>(1, 16);
    std::uniform_int_distribution<> dist_18;
    std::uniform_int_distribution<> dist_19 = std::uniform_int_distribution<>(96, 126);
    std::uniform_int_distribution<> dist_20 = std::uniform_int_distribution<>(323, 489);
    std::uniform_int_distribution<> dist_21 = std::uniform_int_distribution<>(1, 40);
    std::uniform_int_distribution<> dist_22 = std::uniform_int_distribution<>(1, 30);
    std::uniform_int_distribution<> dist_23 = std::uniform_int_distribution<>(248, 255);
    std::uniform_int_distribution<> dist_24 = std::uniform_int_distribution<>(1, 6);
    std::uniform_int_distribution<> dist_25 = std::uniform_int_distribution<>(250, 254);
    std::uniform_int_distribution<> dist_26 = std::uniform_int_distribution<>(5, 25);
    std::uniform_int_distribution<> dist_27 = std::uniform_int_distribution<>(3, 20);
    std::uniform_int_distribution<> dist_28 = std::uniform_int_distribution<>(252, 254);
    std::uniform_int_distribution<> dist_29 = std::uniform_int_distribution<>(1, 25);
    std::uniform_int_distribution<> dist_30 = std::uniform_int_distribution<>(1, 20);
    std::uniform_int_distribution<> dist_31 = std::uniform_int_distribution<>(3, 19);
    std::uniform_int_distribution<> dist_32 = std::uniform_int_distribution<>(252, 255);
    std::uniform_int_distribution<> dist_33 = std::uniform_int_distribution<>(0, 2);
    std::uniform_int_distribution<> dist_34 = std::uniform_int_distribution<>(44, 47);
    std::uniform_int_distribution<> dist_35 = std::uniform_int_distribution<>(1, 47);
    std::uniform_int_distribution<> dist_36 = std::uniform_int_distribution<>(5, 51);
    std::uniform_int_distribution<> dist_37 = std::uniform_int_distribution<>(1, 2);
    std::uniform_int_distribution<> dist_38 = std::uniform_int_distribution<>(5, 46);
    std::uniform_int_distribution<> dist_39 = std::uniform_int_distribution<>(48, 51);
    std::uniform_int_distribution<> dist_40 = std::uniform_int_distribution<>(127, 142);
    std::uniform_int_distribution<> dist_41 = std::uniform_int_distribution<>(143, 158);
    std::uniform_int_distribution<> dist_42 = std::uniform_int_distribution<>(159, 174);
    std::uniform_int_distribution<> dist_43 = std::uniform_int_distribution<>(175, 190);
    std::uniform_int_distribution<> dist_44 = std::uniform_int_distribution<>(191, 200);
    std::uniform_int_distribution<> dist_45 = std::uniform_int_distribution<>(223, 253);
    std::uniform_int_distribution<> dist_46 = std::uniform_int_distribution<>(0, 30);
    std::uniform_int_distribution<> dist_47 = std::uniform_int_distribution<>(241, 255);
    std::uniform_int_distribution<> dist_48 = std::uniform_int_distribution<>(0, 25);
    std::uniform_int_distribution<> dist_49 = std::uniform_int_distribution<>(0, 15);
    std::uniform_int_distribution<> dist_50 = std::uniform_int_distribution<>(3, 7);
    std::uniform_int_distribution<> dist_51 = std::uniform_int_distribution<>(96, 104);
    std::uniform_int_distribution<> dist_52 = std::uniform_int_distribution<>(105, 114);
    std::uniform_int_distribution<> dist_53 = std::uniform_int_distribution<>(115, 120);
    std::uniform_int_distribution<> dist_54 = std::uniform_int_distribution<>(121, 126);
    std::uniform_int_distribution<> dist_55 = std::uniform_int_distribution<>(0, 128);
    std::uniform_int_distribution<> dist_56 = std::uniform_int_distribution<>(0, 25);
    std::uniform_int_distribution<> dist_57 = std::uniform_int_distribution<>(3, 7);
    std::uniform_int_distribution<> dist_58 = std::uniform_int_distribution<>(1, 10);
    std::uniform_int_distribution<> dist_59 = std::uniform_int_distribution<>(1, 5);



    char* ch_val;
    char rand_dpm[20];
    char rand_dp[20];

    std::stringstream ss_rand_dpm;
    std::stringstream hs_rand_dpm;
    std::stringstream ss_rand_dp;
    std::stringstream rand_dpm_fin;
    std::stringstream rand_dp_fin;

    std::ofstream cheBat;
    cheBat.open("cheCmd.cmd", std::ios::trunc);
    cheBat << ("cd " + aGame.getStringPath() + " \n");

    for (int mi = 0; mi < ml.size(); mi++) {
        m_file = aGame.getStringPath() + "\\MAPS\\" + *mlp;
        cur_map = *mlp;
        if (aChoice == "Y") {
            if (*mlp == "MAP018.MPD" || *mlp == "MAP027.MPD" || *mlp == "MAP409.MPD" || *mlp == "MAP025.MPD" || *mlp == "MAP026.MPD" || *mlp == "MAP408.MPD" || *mlp == "MAP032.MPD" || *mlp == "MAP033.MPD" || *mlp == "MAP037.MPD" || *mlp == "MAP045.MPD" || *mlp == "MAP050.MPD") {
                dist_46 = std::uniform_int_distribution<>(0, 20);
                dist_47 = std::uniform_int_distribution<>(251, 255);
                dist_21 = std::uniform_int_distribution<>(1, 15);
                dist_22 = std::uniform_int_distribution<>(1, 5);
                dist_49 = std::uniform_int_distribution<>(0, 5);
                dist_48 = std::uniform_int_distribution<>(0, 7);
            }
            else if (*mlp == "MAP124.MPD" || *mlp == "MAP175.MPD" || *mlp == "MAP176.MPD" || *mlp == "MAP177.MPD" || *mlp == "MAP202.MPD" || *mlp == "MAP203.MPD" || *mlp ==  "MAP227.MPD" || *mlp == "MAP241.MPD" || *mlp == "MAP240.MPD" || *mlp == "MAP261.MPD" || *mlp == "MAP270.MPD" || *mlp == "MAP274.MPD" || *mlp == "MAP276.MPD") {
                dist_46 = std::uniform_int_distribution<>(0, 20);
                dist_47 = std::uniform_int_distribution<>(250, 255);
                dist_21 = std::uniform_int_distribution<>(1, 15);
                dist_22 = std::uniform_int_distribution<>(1, 5);
                dist_49 = std::uniform_int_distribution<>(0, 6);
                dist_48 = std::uniform_int_distribution<>(0, 7);
            }
            else if (*mlp == "MAP254.MPD" || *mlp == "MAP255.MPD" || *mlp == "MAP259.MPD" || *mlp == "MAP289.MPD" || *mlp == "MAP292.MPD" || *mlp == "MAP295.MPD" || *mlp == "MAP306.MPD" || *mlp == "MAP326.MPD" || *mlp == "MAP331.MPD" || *mlp == "MAP333.MPD" || *mlp == "MAP336.MPD") {
                dist_46 = std::uniform_int_distribution<>(0, 20);
                dist_47 = std::uniform_int_distribution<>(245, 255);
                dist_21 = std::uniform_int_distribution<>(1, 35);
                dist_22 = std::uniform_int_distribution<>(1, 5);
                dist_49 = std::uniform_int_distribution<>(0, 6);
                dist_48 = std::uniform_int_distribution<>(0, 20);
            }
            else {
                dist_46 = std::uniform_int_distribution<>(0, 30);
                dist_47 = std::uniform_int_distribution<>(241, 255);
                dist_48 = std::uniform_int_distribution<>(0, 25);
                dist_49 = std::uniform_int_distribution<>(0, 15);
                dist_21 = std::uniform_int_distribution<>(1, 40);
                dist_22 = std::uniform_int_distribution<>(1, 30);
            }
            
        }
        acmap.open(m_file, ios::in | ios::out | ios::binary | ios::ate);
        size = acmap.tellg();
        size = round((size - 544) - 1);
        acmap.seekg(size + 1, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 5, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_2(aGen);
            if (thirdChoice == "N") {
                bla_nam = prop;
            }
            ch_val = new char(prop);
            acmap.seekp(size + 5, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 6, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = bla_nam;
            }
            else {
                prop = dist_2(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 6, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 7, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = bla_nam;
            }
            else {
                prop = dist_2(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 7, ios::beg);
            acmap.write(ch_val, 1);
            acmap.seekg(size + 8, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                if (bla_nam >= 1 && bla_nam <= 12) {
                    prop = 1;
                }
                if (bla_nam >= 13 && bla_nam <= 24) {
                    prop = 2;
                }
                if (bla_nam >= 25 && bla_nam <= 34) {
                    prop = 3;
                }
                if (bla_nam >= 35 && bla_nam <= 50) {
                    prop = 4;
                }
                if (bla_nam >= 51 && bla_nam <= 56) {
                    prop = 5;
                }
                if (bla_nam >= 57 && bla_nam <= 62) {
                    prop = 6;
                }
                if (bla_nam >= 63 && bla_nam <= 69) {
                    prop = 7;
                }
                if (bla_nam >= 70 && bla_nam <= 82) {
                    prop = 8;
                }
                if (bla_nam >= 83 && bla_nam <= 90) {
                    prop = 9;
                }
            }
            else {
                prop = dist_3(aGen);
            }
            cho_blade = prop;
            cho_grip = prop;
            ch_val = new char(prop);
            acmap.seekp(size + 8, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                prop = dist_4(aGen) * 100;
                sprintf_s(rand_dpm, "%X", prop);
                ss_rand_dpm << rand_dpm;
                ss_rand_dpm >> s_rand_dpm;
                ss_rand_dpm.clear();
                hs_rand_dpm << std::hex << s_rand_dpm;
                hs_rand_dpm >> int_rand_dpm;
                hs_rand_dpm.clear();
                dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
                prop = dist_5(aGen) * 100;
                sprintf_s(rand_dp, "%X", prop);
                ss_rand_dp << rand_dp;
                ss_rand_dp >> s_rand_dp;
                ss_rand_dp.clear();
                sp1 = s_rand_dpm.at(0);
                sp2 = s_rand_dpm.at(1);
                sp3 = s_rand_dpm.at(2);
                sp4 = s_rand_dpm.at(3);
                s_rand_dpm_1 = sp1 + sp2;
                s_rand_dpm_2 = sp3 + sp4;
                sp1 = s_rand_dp.at(0);
                sp2 = s_rand_dp.at(1);
                sp3 = s_rand_dp.at(2);
                sp4 = s_rand_dp.at(3);
                s_rand_dp_1 = sp1 + sp2;
                s_rand_dp_2 = sp3 + sp4;
                rand_dpm_fin << std::hex << s_rand_dpm_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 10, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 10, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 9, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 9, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ppm = dist_6(aGen);
                acmap.seekg(size + 11, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(ppm);
                acmap.seekp(size + 11, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dp_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 14, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 14, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 13, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 13, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                dist_7 = std::uniform_int_distribution<>(1, ppm);
                pp = dist_7(aGen);
                acmap.seekg(size + 15, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(pp);
                acmap.seekp(size + 15, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 17, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_21(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 17, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 18, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_22(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 18, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 19, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                if (aChoice == "Y") {
                    if (cho_blade == 1) {
                        dist_23 = std::uniform_int_distribution<>(254, 255);
                    }
                    else if (cho_blade == 2 || cho_blade == 5 || cho_blade == 8 || cho_blade == 9) {
                        dist_23 = std::uniform_int_distribution<>(250, 255);
                    }
                    else if (cho_blade == 3) {
                        dist_23 = std::uniform_int_distribution<>(249, 255);
                    }
                    else if (cho_blade == 4) {
                        dist_23 = std::uniform_int_distribution<>(251, 255);
                    }
                    else if (cho_blade == 6) {
                        dist_23 = std::uniform_int_distribution<>(252, 255);
                    }
                    else if (cho_blade == 7) {
                        dist_23 = std::uniform_int_distribution<>(248, 255);
                    }
                }
                prop = dist_23(aGen) - 255;
                ch_val = new char(prop);
                acmap.seekp(size + 19, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 20, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_9(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 20, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            prop = (4 * dist_10(aGen)) + dist_11(aGen);
            acmap.seekg(size + 21, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            ch_val = new char(prop);
            acmap.seekp(size + 21, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                for (int b = 25; b < 28; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "Y") {
                        if (cho_blade == 1) {
                            prop = 1;
                        }
                        else if (cho_blade == 4) {
                            prop = 3;
                        }
                        else if (cho_blade == 5) {
                            prop = 4;
                        }
                        else {
                            if (cho_blade == 2) {
                                dist_12 = std::uniform_int_distribution<>(3, 5);
                            }
                            if (cho_blade == 3) {
                                dist_12 = std::uniform_int_distribution<>(4, 6);
                            }
                            if (cho_blade == 6) {
                                dist_12 = std::uniform_int_distribution<>(2, 3);
                            }
                            if (cho_blade == 7) {
                                dist_12 = std::uniform_int_distribution<>(4, 7);
                            }
                            if (cho_blade == 8) {
                                dist_12 = std::uniform_int_distribution<>(5, 6);
                            }
                            if (cho_blade == 9) {
                                dist_12 = std::uniform_int_distribution<>(9, 12);
                            }
                            prop = dist_12(aGen);
                        }
                    }
                    else {
                        prop = dist_12(aGen);
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                acmap.seekg(size + 28, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_57(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 28, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 29; b < 35; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 37; b < 44; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                acmap.seekg(size + 45, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_50(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 45, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 49, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                if (cho_grip >= 1 && cho_grip <= 3) {
                    prop = dist_51(aGen);
                }
                else if (cho_grip >= 4 && cho_grip <= 7) {
                    prop = dist_52(aGen);
                }
                else if (cho_grip == 8) {
                    prop = dist_53(aGen);
                }
                else if (cho_grip == 9) {
                    prop = dist_54(aGen);
                }
                gri_nam = prop;
            }
            else {
                prop = dist_19(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 49, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            ch_val = new char(0);
            acmap.seekg(size + 50, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 50, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 51, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = gri_nam - 95;
            }
            else {
                prop = dist_15(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 51, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 52, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                if (gri_nam >= 96 && gri_nam <= 104) {
                    prop = 1;
                }
                else if (gri_nam >= 105 && gri_nam <= 114) {
                    prop = 2;
                }
                else if (gri_nam >= 115 && gri_nam <= 120) {
                    prop = 3;
                }
                else if (gri_nam >= 121 && gri_nam <= 126) {
                    prop = 4;
                }
            }
            else {
                if (cho_grip >= 1 && cho_grip <= 3) {
                    prop = 1;
                }
                else if (cho_grip >= 4 && cho_grip <= 7) {
                    prop = 2;
                }
                else if (cho_grip == 8) {
                    prop = 3;
                }
                else if (cho_grip == 9) {
                    prop = 4;
                }
            }
            cho_grip = prop;
            ch_val = new char(prop);
            acmap.seekp(size + 52, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 53, ios::beg);
            map_loc = acmap.tellg();
            p_53 = acmap.get();
            if (p_53 > 0) {
                if (secondChoice == "Y" || size + 63 == 3) {
                    acmap.seekg(size + 65, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_36(aGen);
                    if (prop == 47) {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_38(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_39(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + 65, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    ch_val = new char(1);
                    acmap.seekg(size + 66, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    acmap.seekp(size + 66, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    acmap.seekg(size + 67, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_35(aGen);
                    if (prop == 43) {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_16(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_34(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + 67, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                if (secondChoice == "Y") {
                    for (int b = 70; b < 79; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        if (aChoice == "N") {
                            prop = dist_8(aGen);
                        }
                        else {
                            choice = dist_37(aGen);
                            if (choice == 1) {
                                if (b > 72) {
                                    prop = dist_46(aGen);
                                }
                                else {
                                    prop = dist_49(aGen);
                                }
                            }
                            if (choice == 2) {
                                if (b > 72) {
                                    prop = dist_47(aGen);
                                }
                                else {
                                    prop = dist_14(aGen);
                                }
                            }
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                    for (int b = 81; b < 88; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        if (aChoice == "N") {
                            prop = dist_8(aGen);
                        }
                        else {
                            choice = dist_37(aGen);
                            if (choice == 1) {
                                prop = dist_46(aGen);
                            }
                            if (choice == 2) {
                                prop = dist_47(aGen);
                            }
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                }
                if (p_53 > 1) {
                    if (secondChoice == "Y" || size + 91 == 3) {
                        acmap.seekg(size + 93, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_36(aGen);
                        if (prop == 47) {
                            choice = dist_37(aGen);
                            if (choice == 1) {
                                prop = dist_38(aGen);
                            }
                            if (choice == 2) {
                                prop = dist_39(aGen);
                            }
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + 93, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        ch_val = new char(1);
                        acmap.seekg(size + 94, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        acmap.seekp(size + 94, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        acmap.seekg(size + 95, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_35(aGen);
                        if (prop == 43) {
                            choice = dist_37(aGen);
                            if (choice == 1) {
                                prop = dist_16(aGen);
                            }
                            if (choice == 2) {
                                prop = dist_34(aGen);
                            }
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + 95, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                    if (secondChoice == "Y") {
                        for (int b = 98; b < 107; b++) {
                            acmap.seekg(size + b, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            if (aChoice == "N") {
                                prop = dist_8(aGen);
                            }
                            else {
                                choice = dist_37(aGen);
                                if (choice == 1) {
                                    if (b > 100) {
                                        prop = dist_46(aGen);
                                    }
                                    else {
                                        prop = dist_49(aGen);
                                    }
                                }
                                if (choice == 2) {
                                    if (b > 100) {
                                        prop = dist_47(aGen);
                                    }
                                    else {
                                        prop = dist_14(aGen);
                                    }
                                }
                            }
                            ch_val = new char(prop);
                            acmap.seekp(size + b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                        for (int b = 109; b < 116; b++) {
                            acmap.seekg(size + b, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            if (aChoice == "N") {
                                prop = dist_8(aGen);
                            }
                            else {
                                choice = dist_37(aGen);
                                if (choice == 1) {
                                    prop = dist_46(aGen);
                                }
                                if (choice == 2) {
                                    prop = dist_47(aGen);
                                }
                            }
                            ch_val = new char(prop);
                            acmap.seekp(size + b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                    }
                    if (p_53 > 2) {
                        if (secondChoice == "Y" || size + 119 == 3) {
                            acmap.seekg(size + 121, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            prop = dist_36(aGen);
                            if (prop == 47) {
                                choice = dist_37(aGen);
                                if (choice == 1) {
                                    prop = dist_38(aGen);
                                }
                                if (choice == 2) {
                                    prop = dist_39(aGen);
                                }
                            }
                            ch_val = new char(prop);
                            acmap.seekp(size + 121, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            ch_val = new char(1);
                            acmap.seekg(size + 122, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            acmap.seekp(size + 122, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            acmap.seekg(size + 123, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            prop = dist_35(aGen);
                            if (prop == 43) {
                                choice = dist_37(aGen);
                                if (choice == 1) {
                                    prop = dist_16(aGen);
                                }
                                if (choice == 2) {
                                    prop = dist_34(aGen);
                                }
                            }
                            ch_val = new char(prop);
                            acmap.seekp(size + 123, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                        if (secondChoice == "Y") {
                            for (int b = 126; b < 135; b++) {
                                acmap.seekg(size + b, ios::beg);
                                map_loc = acmap.tellg();
                                to_ass = acmap.get();
                                if (aChoice == "N") {
                                    prop = dist_8(aGen);
                                }
                                else {
                                    choice = dist_37(aGen);
                                    if (choice == 1) {
                                        if (b > 128) {
                                            prop = dist_46(aGen);
                                        }
                                        else {
                                            prop = dist_49(aGen);
                                        }
                                    }
                                    if (choice == 2) {
                                        if (b > 128) {
                                            prop = dist_47(aGen);
                                        }
                                        else {
                                            prop = dist_14(aGen);
                                        }
                                    }
                                }
                                ch_val = new char(prop);
                                acmap.seekp(size + b, ios::beg);
                                acmap.write(ch_val, 1);
                                delete ch_val;
                            }
                            for (int b = 137; b < 143; b++) {
                                acmap.seekg(size + b, ios::beg);
                                map_loc = acmap.tellg();
                                to_ass = acmap.get();
                                if (aChoice == "N") {
                                    prop = dist_8(aGen);
                                }
                                else {
                                    choice = dist_37(aGen);
                                    if (choice == 1) {
                                        prop = dist_46(aGen);
                                    }
                                    if (choice == 2) {
                                        prop = dist_47(aGen);
                                    }
                                }
                                ch_val = new char(prop);
                                acmap.seekp(size + b, ios::beg);
                                acmap.write(ch_val, 1);
                                delete ch_val;
                            }
                        }
                    }
                }
            }
            if (secondChoice == "Y") {
                acmap.seekg(size + 54, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_24(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 54, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 55, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_59(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 55, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 56, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                if (aChoice == "Y") {
                    if (cho_grip == 1) {
                        dist_25 = std::uniform_int_distribution<>(252, 254);
                    }
                    else if (cho_grip == 2) {
                        dist_25 = std::uniform_int_distribution<>(251, 253);
                    }
                    else if (cho_grip == 3) {
                        dist_25 = std::uniform_int_distribution<>(250, 252);
                    }
                    else if (cho_grip == 4) {
                        dist_25 = std::uniform_int_distribution<>(253, 254);
                    }
                }
                prop = dist_25(aGen) - 255;
                ch_val = new char(prop);
                acmap.seekp(size + 56, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 58; b < 61; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        prop = dist_48(aGen);
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
            }
        }
        acmap.seekg(size + 173, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 177, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_2(aGen);
            if (thirdChoice == "N") {
                bla_nam = prop;
            }
            ch_val = new char(prop);
            acmap.seekp(size + 177, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 178, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = bla_nam;
            }
            else {
                prop = dist_2(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 178, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 179, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = bla_nam;
            }
            else {
                prop = dist_2(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 179, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 180, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                if (bla_nam >= 1 && bla_nam <= 12) {
                    prop = 1;
                }
                if (bla_nam >= 13 && bla_nam <= 24) {
                    prop = 2;
                }
                if (bla_nam >= 25 && bla_nam <= 34) {
                    prop = 3;
                }
                if (bla_nam >= 35 && bla_nam <= 50) {
                    prop = 4;
                }
                if (bla_nam >= 51 && bla_nam <= 56) {
                    prop = 5;
                }
                if (bla_nam >= 57 && bla_nam <= 62) {
                    prop = 6;
                }
                if (bla_nam >= 63 && bla_nam <= 69) {
                    prop = 7;
                }
                if (bla_nam >= 70 && bla_nam <= 82) {
                    prop = 8;
                }
                if (bla_nam >= 83 && bla_nam <= 90) {
                    prop = 9;
                }
            }
            else {
                prop = dist_3(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 180, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                prop = dist_4(aGen) * 100;
                sprintf_s(rand_dpm, "%X", prop);
                ss_rand_dpm << rand_dpm;
                ss_rand_dpm >> s_rand_dpm;
                ss_rand_dpm.clear();
                hs_rand_dpm << std::hex << s_rand_dpm;
                hs_rand_dpm >> int_rand_dpm;
                hs_rand_dpm.clear();
                dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
                prop = dist_5(aGen) * 100;
                sprintf_s(rand_dp, "%X", prop);
                ss_rand_dp << rand_dp;
                ss_rand_dp >> s_rand_dp;
                ss_rand_dp.clear();
                sp1 = s_rand_dpm.at(0);
                sp2 = s_rand_dpm.at(1);
                sp3 = s_rand_dpm.at(2);
                sp4 = s_rand_dpm.at(3);
                s_rand_dpm_1 = sp1 + sp2;
                s_rand_dpm_2 = sp3 + sp4;
                sp1 = s_rand_dp.at(0);
                sp2 = s_rand_dp.at(1);
                sp3 = s_rand_dp.at(2);
                sp4 = s_rand_dp.at(3);
                s_rand_dp_1 = sp1 + sp2;
                s_rand_dp_2 = sp3 + sp4;
                rand_dpm_fin << std::hex << s_rand_dpm_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 182, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 182, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 181, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 181, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ppm = dist_6(aGen);
                acmap.seekg(size + 183, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(ppm);
                acmap.seekp(size + 183, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dp_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 186, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 186, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 185, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 185, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                dist_7 = std::uniform_int_distribution<>(1, ppm);
                pp = dist_7(aGen);
                acmap.seekg(size + 187, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(pp);
                acmap.seekp(size + 187, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 189, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_21(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 189, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 190, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_22(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 190, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 191, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                if (aChoice == "Y") {
                    if (cho_blade == 1) {
                        dist_23 = std::uniform_int_distribution<>(254, 255);
                    }
                    else if (cho_blade == 2 || cho_blade == 5 || cho_blade == 8 || cho_blade == 9) {
                        dist_23 = std::uniform_int_distribution<>(250, 255);
                    }
                    else if (cho_blade == 3) {
                        dist_23 = std::uniform_int_distribution<>(249, 255);
                    }
                    else if (cho_blade == 4) {
                        dist_23 = std::uniform_int_distribution<>(251, 255);
                    }
                    else if (cho_blade == 6) {
                        dist_23 = std::uniform_int_distribution<>(252, 255);
                    }
                    else if (cho_blade == 7) {
                        dist_23 = std::uniform_int_distribution<>(248, 255);
                    }
                }
                prop = dist_23(aGen) - 255;
                ch_val = new char(prop);
                acmap.seekp(size + 191, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 192, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_9(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 192, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            prop = (4 * dist_10(aGen)) + dist_11(aGen);
            acmap.seekg(size + 193, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            ch_val = new char(prop);
            acmap.seekp(size + 193, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                for (int b = 197; b < 200; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "Y") {
                        if (cho_blade == 1) {
                            prop = 1;
                        }
                        else if (cho_blade == 4) {
                            prop = 3;
                        }
                        else if (cho_blade == 5) {
                            prop = 4;
                        }
                        else {
                            if (cho_blade == 2) {
                                dist_12 = std::uniform_int_distribution<>(3, 5);
                            }
                            if (cho_blade == 3) {
                                dist_12 = std::uniform_int_distribution<>(4, 6);
                            }
                            if (cho_blade == 6) {
                                dist_12 = std::uniform_int_distribution<>(2, 3);
                            }
                            if (cho_blade == 7) {
                                dist_12 = std::uniform_int_distribution<>(4, 7);
                            }
                            if (cho_blade == 8) {
                                dist_12 = std::uniform_int_distribution<>(5, 6);
                            }
                            if (cho_blade == 9) {
                                dist_12 = std::uniform_int_distribution<>(9, 12);
                            }
                            prop = dist_12(aGen);
                        }
                    }
                    else {
                        prop = dist_12(aGen);
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                acmap.seekg(size + 200, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_57(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 200, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 201; b < 207; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 209; b < 216; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                acmap.seekg(size + 217, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_50(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 217, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }                   
        }
        acmap.seekg(size + 221, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 225, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_19(aGen);
            if (thirdChoice == "N") {
                gri_nam = prop;
            }
            ch_val = new char(prop);
            acmap.seekp(size + 225, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            ch_val = new char(0);
            acmap.seekg(size + 226, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 226, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 227, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = gri_nam - 95;
            }
            else {
                prop = dist_15(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 227, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 228, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                if (gri_nam >= 96 && gri_nam <= 104) {
                    prop = 1;
                }
                else if (gri_nam >= 105 && gri_nam <= 114) {
                    prop = 2;
                }
                else if (gri_nam >= 115 && gri_nam <= 120) {
                    prop = 3;
                }
                else if (gri_nam >= 121 && gri_nam <= 126) {
                    prop = 4;
                }
            }
            else {
                prop = dist_10(aGen);
            }
            cho_grip = prop;
            ch_val = new char(prop);
            acmap.seekp(size + 228, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 229, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_33(aGen);
            ch_val = new char(prop);
            acmap.seekp(size + 229, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                acmap.seekg(size + 230, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_24(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 230, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 231, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_59(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 231, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 232, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                if (aChoice == "Y") {
                    if (cho_grip == 1) {
                        dist_25 = std::uniform_int_distribution<>(252, 254);
                    }
                    else if (cho_grip == 2) {
                        dist_25 = std::uniform_int_distribution<>(251, 253);
                    }
                    else if (cho_grip == 3) {
                        dist_25 = std::uniform_int_distribution<>(250, 252);
                    }
                    else if (cho_grip == 4) {
                        dist_25 = std::uniform_int_distribution<>(253, 254);
                    }
                }
                prop = dist_25(aGen) - 255;
                ch_val = new char(prop);
                acmap.seekp(size + 232, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 234; b < 237; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        prop = dist_48(aGen);
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
            }
        }
        acmap.seekg(size + 241, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        //Shields
        if (to_ass == 3) {
            acmap.seekg(size + 245, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_40(aGen);
            if (thirdChoice == "N") {
                shi_nam = prop;
            }
            ch_val = new char(prop);
            acmap.seekp(size + 245, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 246, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = shi_nam - 126;
            }
            else {
                prop = dist_17(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 246, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 247, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = shi_nam - 31;
            }
            else {
                prop = dist_17(aGen) + 95;
            }
            ch_val = new char(prop);
            acmap.seekp(size + 247, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                prop = dist_4(aGen) * 100;
                sprintf_s(rand_dpm, "%X", prop);
                ss_rand_dpm << rand_dpm;
                ss_rand_dpm >> s_rand_dpm;
                ss_rand_dpm.clear();
                hs_rand_dpm << std::hex << s_rand_dpm;
                hs_rand_dpm >> int_rand_dpm;
                hs_rand_dpm.clear();
                dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
                prop = dist_5(aGen) * 100;
                sprintf_s(rand_dp, "%X", prop);
                ss_rand_dp << rand_dp;
                ss_rand_dp >> s_rand_dp;
                ss_rand_dp.clear();
                sp1 = s_rand_dpm.at(0);
                sp2 = s_rand_dpm.at(1);
                sp3 = s_rand_dpm.at(2);
                sp4 = s_rand_dpm.at(3);
                s_rand_dpm_1 = sp1 + sp2;
                s_rand_dpm_2 = sp3 + sp4;
                sp1 = s_rand_dp.at(0);
                sp2 = s_rand_dp.at(1);
                sp3 = s_rand_dp.at(2);
                sp4 = s_rand_dp.at(3);
                s_rand_dp_1 = sp1 + sp2;
                s_rand_dp_2 = sp3 + sp4;
                rand_dpm_fin << std::hex << s_rand_dpm_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 250, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 250, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 249, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 249, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ppm = dist_6(aGen);
                acmap.seekg(size + 251, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(ppm);
                acmap.seekp(size + 251, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dp_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 254, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 254, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 253, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 253, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                dist_7 = std::uniform_int_distribution<>(1, ppm);
                pp = dist_7(aGen);
                acmap.seekg(size + 255, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(pp);
                acmap.seekp(size + 255, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 257, ios::beg);
            map_loc = acmap.tellg();
            p_257 = acmap.get();
            if (p_257 > 0) {
                if (secondChoice == "Y" || size + 283 == 3) {
                    acmap.seekg(size + 285, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_36(aGen);
                    if (prop == 47) {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_38(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_39(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + 285, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    ch_val = new char(1);
                    acmap.seekg(size + 286, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    acmap.seekp(size + 286, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    acmap.seekg(size + 287, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_35(aGen);
                    if (prop == 43) {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_16(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_34(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + 287, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                if (secondChoice == "Y") {
                    for (int b = 290; b < 293; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        if (aChoice == "N") {
                            prop = dist_55(aGen);
                        }
                        else {
                            prop = dist_56(aGen);
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                    for (int b = 293; b < 299; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        if (aChoice == "N") {
                            prop = dist_8(aGen);
                        }
                        else {
                            choice = dist_37(aGen);
                            if (choice == 1) {
                                prop = dist_46(aGen);
                            }
                            if (choice == 2) {
                                prop = dist_47(aGen);
                            }
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                    for (int b = 301; b < 308; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        if (aChoice == "N") {
                            prop = dist_8(aGen);
                        }
                        else {
                            choice = dist_37(aGen);
                            if (choice == 1) {
                                prop = dist_46(aGen);
                            }
                            if (choice == 2) {
                                prop = dist_47(aGen);
                            }
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                }
                if (p_257 > 1) {
                    if (secondChoice == "Y" || size + 311 == 3) {
                        acmap.seekg(size + 313, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_36(aGen);
                        if (prop == 47) {
                            choice = dist_37(aGen);
                            if (choice == 1) {
                                prop = dist_38(aGen);
                            }
                            if (choice == 2) {
                                prop = dist_39(aGen);
                            }
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + 313, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        ch_val = new char(1);
                        acmap.seekg(size + 314, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        acmap.seekp(size + 314, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        acmap.seekg(size + 315, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_35(aGen);
                        if (prop == 43) {
                            choice = dist_37(aGen);
                            if (choice == 1) {
                                prop = dist_16(aGen);
                            }
                            if (choice == 2) {
                                prop = dist_34(aGen);
                            }
                        }
                        ch_val = new char(prop);
                        acmap.seekp(size + 315, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }

                    if (secondChoice == "Y") {
                        for (int b = 318; b < 327; b++) {
                            acmap.seekg(size + b, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            if (aChoice == "N") {
                                prop = dist_8(aGen);
                            }
                            else {
                                choice = dist_37(aGen);
                                if (choice == 1) {
                                    if (b > 320) {
                                        prop = dist_46(aGen);
                                    }
                                    else {
                                        prop = dist_49(aGen);
                                    }
                                }
                                if (choice == 2) {
                                    if (b > 320) {
                                        prop = dist_47(aGen);
                                    }
                                    else {
                                        prop = dist_14(aGen);
                                    }
                                }
                            }
                            ch_val = new char(prop);
                            acmap.seekp(size + b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                        for (int b = 329; b < 336; b++) {
                            acmap.seekg(size + b, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            if (aChoice == "N") {
                                prop = dist_8(aGen);
                            }
                            else {
                                choice = dist_37(aGen);
                                if (choice == 1) {
                                    prop = dist_46(aGen);
                                }
                                if (choice == 2) {
                                    prop = dist_47(aGen);
                                }
                            }
                            ch_val = new char(prop);
                            acmap.seekp(size + b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                    }
                    if (p_257 > 2) {
                        if (secondChoice == "Y" || size + 339 == 3) {
                            acmap.seekg(size + 341, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            prop = dist_36(aGen);
                            if (prop == 47) {
                                choice = dist_37(aGen);
                                if (choice == 1) {
                                    prop = dist_38(aGen);
                                }
                                if (choice == 2) {
                                    prop = dist_39(aGen);
                                }
                            }
                            ch_val = new char(prop);
                            acmap.seekp(size + 341, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            ch_val = new char(1);
                            acmap.seekg(size + 342, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            acmap.seekp(size + 342, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            acmap.seekg(size + 343, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            prop = dist_35(aGen);
                            if (prop == 43) {
                                choice = dist_37(aGen);
                                if (choice == 1) {
                                    prop = dist_16(aGen);
                                }
                                if (choice == 2) {
                                    prop = dist_34(aGen);
                                }
                            }
                            ch_val = new char(prop);
                            acmap.seekp(size + 343, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                        if (secondChoice == "Y") {
                            for (int b = 346; b < 355; b++) {
                                acmap.seekg(size + b, ios::beg);
                                map_loc = acmap.tellg();
                                to_ass = acmap.get();
                                if (aChoice == "N") {
                                    prop = dist_8(aGen);
                                }
                                else {
                                    choice = dist_37(aGen);
                                    if (choice == 1) {
                                        if (b > 348) {
                                            prop = dist_46(aGen);
                                        }
                                        else {
                                            prop = dist_49(aGen);
                                        }
                                    }
                                    if (choice == 2) {
                                        if (b > 348) {
                                            prop = dist_47(aGen);
                                        }
                                        else {
                                            prop = dist_14(aGen);
                                        }
                                    }
                                }
                                ch_val = new char(prop);
                                acmap.seekp(size + b, ios::beg);
                                acmap.write(ch_val, 1);
                                delete ch_val;
                            }
                            for (int b = 357; b < 363; b++) {
                                acmap.seekg(size + b, ios::beg);
                                map_loc = acmap.tellg();
                                to_ass = acmap.get();
                                if (aChoice == "N") {
                                    prop = dist_8(aGen);
                                }
                                else {
                                    choice = dist_37(aGen);
                                    if (choice == 1) {
                                        prop = dist_46(aGen);
                                    }
                                    if (choice == 2) {
                                        prop = dist_47(aGen);
                                    }
                                }
                                ch_val = new char(prop);
                                acmap.seekp(size + b, ios::beg);
                                acmap.write(ch_val, 1);
                                delete ch_val;
                            }
                        }   
                    }
                }
            }
            if (secondChoice == "Y") {
                acmap.seekg(size + 258, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_26(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 258, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 259, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_27(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 259, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 260, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_28(aGen) - 255;
                ch_val = new char(prop);
                acmap.seekp(size + 260, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 262; b < 271; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 273; b < 280; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                acmap.seekg(size + 281, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_13(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 281, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
        }
        acmap.seekg(size + 369, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 376, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekg(size + 373, ios::beg);
            map_loc = acmap.tellg();
            if (to_ass == 2) {
                to_ass = acmap.get();
                prop = dist_41(aGen);
                if (thirdChoice == "N") {
                    arm_nam = prop;
                }
                ch_val = new char(prop);
                acmap.seekp(size + 373, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                if (thirdChoice == "Y") {
                    dist_18 = std::uniform_int_distribution<>(17, 32);
                }
            }
            else if (to_ass == 3) {
                to_ass = acmap.get();
                prop = dist_42(aGen);
                if (thirdChoice == "N") {
                    arm_nam = prop;
                }
                ch_val = new char(prop);
                acmap.seekp(size + 373, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                if (thirdChoice == "Y") {
                    dist_18 = std::uniform_int_distribution<>(33, 48);
                }
            }
            else if (to_ass == 4) {
                to_ass = acmap.get();
                prop = dist_43(aGen);
                if (thirdChoice == "N") {
                    arm_nam = prop;
                }
                ch_val = new char(prop);
                acmap.seekp(size + 373, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                if (thirdChoice == "Y") {
                    dist_18 = std::uniform_int_distribution<>(49, 64);
                }
            }
            else if (to_ass == 5) {
                to_ass = acmap.get();
                prop = dist_44(aGen);
                if (thirdChoice == "N") {
                    arm_nam = prop;
                }
                ch_val = new char(prop);
                acmap.seekp(size + 373, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                if (thirdChoice == "Y") {
                    dist_18 = std::uniform_int_distribution<>(65, 80);
                }
            }
            if (thirdChoice == "N") {
                prop = arm_nam - 126;
            }
            else {
                prop = dist_18(aGen);
            }
            ch_val = new char(prop);
            acmap.seekg(size + 374, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 374, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                prop = dist_4(aGen) * 100;
                sprintf_s(rand_dpm, "%X", prop);
                ss_rand_dpm << rand_dpm;
                ss_rand_dpm >> s_rand_dpm;
                ss_rand_dpm.clear();
                hs_rand_dpm << std::hex << s_rand_dpm;
                hs_rand_dpm >> int_rand_dpm;
                hs_rand_dpm.clear();
                dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
                prop = dist_5(aGen) * 100;
                sprintf_s(rand_dp, "%X", prop);
                ss_rand_dp << rand_dp;
                ss_rand_dp >> s_rand_dp;
                ss_rand_dp.clear();
                sp1 = s_rand_dpm.at(0);
                sp2 = s_rand_dpm.at(1);
                sp3 = s_rand_dpm.at(2);
                sp4 = s_rand_dpm.at(3);
                s_rand_dpm_1 = sp1 + sp2;
                s_rand_dpm_2 = sp3 + sp4;
                sp1 = s_rand_dp.at(0);
                sp2 = s_rand_dp.at(1);
                sp3 = s_rand_dp.at(2);
                sp4 = s_rand_dp.at(3);
                s_rand_dp_1 = sp1 + sp2;
                s_rand_dp_2 = sp3 + sp4;
                rand_dpm_fin << std::hex << s_rand_dpm_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 378, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 378, ios::beg);
                acmap.write(ch_val, 1);
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 377, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 377, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dp_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 382, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 382, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 381, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 381, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 386, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_30(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 386, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 387, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_31(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 387, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 388, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_32(aGen) - 255;
                ch_val = new char(prop);
                acmap.seekp(size + 388, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 390; b < 399; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 401; b < 408; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                acmap.seekg(size + 409, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_13(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 409, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
        }
        acmap.seekg(size + 413, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 420, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekg(size + 417, ios::beg);
            map_loc = acmap.tellg();
            if (to_ass == 2) {
                to_ass = acmap.get();
                prop = dist_41(aGen);
                if (thirdChoice == "N") {
                    arm_nam = prop;
                }
                ch_val = new char(prop);
                acmap.seekp(size + 417, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                if (thirdChoice == "Y") {
                    dist_18 = std::uniform_int_distribution<>(17, 32);
                }
            }
            else if (to_ass == 3) {
                to_ass = acmap.get();
                prop = dist_42(aGen);
                if (thirdChoice == "N") {
                    arm_nam = prop;
                }
                ch_val = new char(prop);
                acmap.seekp(size + 417, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                dist_18 = std::uniform_int_distribution<>(33, 48);
            }
            else if (to_ass == 4) {
                to_ass = acmap.get();
                prop = dist_43(aGen);
                if (thirdChoice == "N") {
                    arm_nam = prop;
                }
                ch_val = new char(prop);
                acmap.seekp(size + 417, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                if (thirdChoice == "Y") {
                    dist_18 = std::uniform_int_distribution<>(49, 64);
                }
            }
            else if (to_ass == 5) {
                to_ass = acmap.get();
                prop = dist_44(aGen);
                if (thirdChoice == "N") {
                    arm_nam = prop;
                }
                ch_val = new char(prop);
                acmap.seekp(size + 417, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                if (thirdChoice == "Y") {
                    dist_18 = std::uniform_int_distribution<>(65, 80);
                }
            }
            if (thirdChoice == "N") {
                prop = arm_nam - 126;
            }
            else {
                prop = dist_18(aGen);
            }
            ch_val = new char(prop);
            acmap.seekg(size + 418, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 418, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                prop = dist_4(aGen) * 100;
                sprintf_s(rand_dpm, "%X", prop);
                ss_rand_dpm << rand_dpm;
                ss_rand_dpm >> s_rand_dpm;
                ss_rand_dpm.clear();
                hs_rand_dpm << std::hex << s_rand_dpm;
                hs_rand_dpm >> int_rand_dpm;
                hs_rand_dpm.clear();
                dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
                prop = dist_5(aGen) * 100;
                sprintf_s(rand_dp, "%X", prop);
                ss_rand_dp << rand_dp;
                ss_rand_dp >> s_rand_dp;
                ss_rand_dp.clear();
                sp1 = s_rand_dpm.at(0);
                sp2 = s_rand_dpm.at(1);
                sp3 = s_rand_dpm.at(2);
                sp4 = s_rand_dpm.at(3);
                s_rand_dpm_1 = sp1 + sp2;
                s_rand_dpm_2 = sp3 + sp4;
                sp1 = s_rand_dp.at(0);
                sp2 = s_rand_dp.at(1);
                sp3 = s_rand_dp.at(2);
                sp4 = s_rand_dp.at(3);
                s_rand_dp_1 = sp1 + sp2;
                s_rand_dp_2 = sp3 + sp4;
                rand_dpm_fin << std::hex << s_rand_dpm_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 422, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 422, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 421, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 421, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dp_1;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 426, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 426, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                rand_dpm_fin << std::hex << s_rand_dpm_2;
                rand_dpm_fin >> prop;
                rand_dpm_fin.clear();
                acmap.seekg(size + 425, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                ch_val = new char(prop);
                acmap.seekp(size + 425, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 430, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_30(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 430, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 431, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_31(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 431, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 432, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_32(aGen) - 255;
                ch_val = new char(prop);
                acmap.seekp(size + 432, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 434; b < 443; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 445; b < 452; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                acmap.seekg(size + 453, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_13(aGen);
                ch_val = new char(prop);
                acmap.seekp(size + 453, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
        }
        acmap.seekg(size + 457, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 461, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_45(aGen);
            if (thirdChoice == "N") {
                arm_nam = prop;
            }
            ch_val = new char(prop);
            acmap.seekp(size + 461, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 462, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (thirdChoice == "N") {
                prop = arm_nam - 222;
            }
            else {
                prop = dist_22(aGen);
            }
            ch_val = new char(prop);
            acmap.seekp(size + 462, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                for (int b = 474; b < 477; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_29(aGen);
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 478; b < 487; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 489; b < 496; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
            }
        }
        acmap.seekg(size + 501, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 505, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_36(aGen);
            if (prop == 47) {
                choice = dist_37(aGen);
                if (choice == 1) {
                    prop = dist_38(aGen);
                }
                if (choice == 2) {
                    prop = dist_39(aGen);
                }
            }
            ch_val = new char(prop);
            acmap.seekp(size + 505, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            ch_val = new char(1);
            acmap.seekg(size + 506, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 506, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 507, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_35(aGen);
            if (prop == 43) {
                choice = dist_37(aGen);
                if (choice == 1) {
                    prop = dist_16(aGen);
                }
                if (choice == 2) {
                    prop = dist_34(aGen);
                }
            }
            ch_val = new char(prop);
            acmap.seekp(size + 507, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            if (secondChoice == "Y") {
                for (int b = 510; b < 519; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            if (b > 512) {
                                prop = dist_46(aGen);
                            }
                            else {
                                prop = dist_49(aGen);
                            }
                        }
                        if (choice == 2) {
                            if (b > 512) {
                                prop = dist_47(aGen);
                            }
                            else {
                                prop = dist_14(aGen);
                            }
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 521; b < 528; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    if (aChoice == "N") {
                        prop = dist_8(aGen);
                    }
                    else {
                        choice = dist_37(aGen);
                        if (choice == 1) {
                            prop = dist_46(aGen);
                        }
                        if (choice == 2) {
                            prop = dist_47(aGen);
                        }
                    }
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
            }
        }
        acmap.seekg(size + 535, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3 && std::find(mlks.begin(), mlks.end(), ivm) == mlks.end()) {
            acmap.seekg(size + 533, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_20(aGen) - 256;
            if (std::find(unt.begin(), unt.end(), prop) != unt.end()) {
                while (std::find(unt.begin(), unt.end(), prop) != unt.end()) {
                    prop = dist_20(aGen) - 256;
                }
            }
            misc_item = prop;
            ch_val = new char(prop);
            acmap.seekp(size + 533, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            ch_val = new char(1);
            acmap.seekg(size + 534, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 534, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 536, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (misc_item >= 130 && misc_item <= 233) {
                prop = 1;
            }
            else {
                if (aChoice == "Y") {
                    prop = dist_58(aGen);
                }
                else {
                    prop = dist_1(aGen);
                }
            }
            ch_val = new char(prop);
            acmap.seekp(size + 536, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
        }
        acmap.seekg(size + 539, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3 && std::find(mlks.begin(), mlks.end(), ivm) == mlks.end()) {
            acmap.seekg(size + 537, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_20(aGen) - 256;
            if (std::find(unt.begin(), unt.end(), prop) != unt.end()) {
                while (std::find(unt.begin(), unt.end(), prop) != unt.end()) {
                    prop = dist_20(aGen) - 256;
                }
            }
            misc_item = prop;
            ch_val = new char(prop);
            acmap.seekp(size + 537, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            ch_val = new char(1);
            acmap.seekg(size + 538, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 538, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 540, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (misc_item >= 130 && misc_item <= 233) {
                prop = 1;
            }
            else {
                if (aChoice == "Y") {
                    prop = dist_58(aGen);
                }
                else {
                    prop = dist_1(aGen);
                }
            }
            ch_val = new char(prop);
            acmap.seekp(size + 540, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
        }
        acmap.seekg(size + 543, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3 && std::find(mlks.begin(), mlks.end(), ivm) == mlks.end()) {
            acmap.seekg(size + 541, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_20(aGen) - 256;
            if (std::find(unt.begin(), unt.end(), prop) != unt.end()) {
                while (std::find(unt.begin(), unt.end(), prop) != unt.end()) {
                    prop = dist_20(aGen) - 256;
                }
            }
            misc_item = prop;
            ch_val = new char(prop);
            acmap.seekp(size + 541, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            ch_val = new char(1);
            acmap.seekg(size + 542, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 542, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 544, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (misc_item >= 130 && misc_item <= 233) {
                prop = 1;
            }
            else {
                if (aChoice == "Y") {
                    prop = dist_58(aGen);
                }
                else {
                    prop = dist_1(aGen);
                }
            }
            ch_val = new char(prop);
            acmap.seekp(size + 544, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
        }
        cheBat << (aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
        acmap.close();
        std::advance(mlp, 1);
    }
    cheBat.close();
}