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

using namespace std;

Chests::Chests() {

}

void Chests::mapIterate(Reference_Files aRF, Add_Game& aGame) {
    vector<string> ml = aRF.getChestCheck();
    vector<string>::iterator mlp = ml.begin();
    list<string> mlks = aRF.getKSCheck();
    
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
    int int_rand_dpm;
    int pp;
    int ppm;
    int p_53;
    int p_257;

    streampos map_loc;

    std::random_device ran;

    std::mt19937 gener(ran());

    std::uniform_int_distribution<> dist_1 = std::uniform_int_distribution<>(1, 255);
    std::uniform_int_distribution<> dist_2 = std::uniform_int_distribution<>(1, 90);
    std::uniform_int_distribution<> dist_3 = std::uniform_int_distribution<>(1, 10);
    std::uniform_int_distribution<> dist_4 = std::uniform_int_distribution<>(41, 327);
    std::uniform_int_distribution<> dist_5;
    std::uniform_int_distribution<> dist_6 = std::uniform_int_distribution<>(100, 250);
    std::uniform_int_distribution<> dist_7;
    std::uniform_int_distribution<> dist_8 = std::uniform_int_distribution<>(0, 255);
    std::uniform_int_distribution<> dist_9 = std::uniform_int_distribution<>(1, 5);
    std::uniform_int_distribution<> dist_10 = std::uniform_int_distribution<>(1, 4);
    std::uniform_int_distribution<> dist_11 = std::uniform_int_distribution<>(1, 3);
    std::uniform_int_distribution<> dist_12 = std::uniform_int_distribution<>(5, 15);
    std::uniform_int_distribution<> dist_13 = std::uniform_int_distribution<>(1, 7);
    std::uniform_int_distribution<> dist_14 = std::uniform_int_distribution<>(1, 511);
    std::uniform_int_distribution<> dist_15 = std::uniform_int_distribution<>(1, 31);
    std::uniform_int_distribution<> dist_16 = std::uniform_int_distribution<>(1, 43);
    std::uniform_int_distribution<> dist_17 = std::uniform_int_distribution<>(1, 16);
    std::uniform_int_distribution<> dist_18;
    std::uniform_int_distribution<> dist_19 = std::uniform_int_distribution<>(97, 127);
    std::uniform_int_distribution<> dist_20 = std::uniform_int_distribution<>(323, 511);
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

    char* ch_val;
    char rand_dpm[20];
    char rand_dp[20];

    std::stringstream ss_rand_dpm;
    std::stringstream hs_rand_dpm;
    std::stringstream ss_rand_dp;
    std::stringstream rand_dpm_fin;
    std::stringstream rand_dp_fin;

    for (int mi = 0; mi < ml.size(); mi++) {
        m_file = aGame.getStringPath() + "\\MAPS\\" + *mlp;
        cur_map = *mlp;
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
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 5, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 6, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_2(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 6, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 7, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 7, ios::beg);
            acmap.write(ch_val, 1);
            acmap.seekg(size + 8, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_3(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 8, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            prop = dist_4(gener) * 100;
            sprintf_s(rand_dpm, "%X", prop);
            ss_rand_dpm << rand_dpm;
            ss_rand_dpm >> s_rand_dpm;
            ss_rand_dpm.clear();
            hs_rand_dpm << std::hex << s_rand_dpm;
            hs_rand_dpm >> int_rand_dpm;
            hs_rand_dpm.clear();
            dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
            prop = dist_5(gener) * 100;
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
            ppm = dist_6(gener);
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
            pp = dist_7(gener);
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
            prop = dist_21(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 17, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 18, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_22(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 18, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 19, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_23(gener) - 255;
            ch_val = new char(prop);
            acmap.seekp(size + 19, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 20, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_9(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 20, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            prop = (4 * dist_10(gener)) + dist_11(gener);
            acmap.seekg(size + 21, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            ch_val = new char(prop);
            acmap.seekp(size + 21, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 25; b < 28; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_12(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 28, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_13(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 28, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 29; b < 35; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            for (int b = 37; b < 44; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 45, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_13(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 45, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 49, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_14(gener);
            if (prop > 255) {
                prop -= 256;
                ch_val = new char(prop);
                acmap.seekp(size + 49, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ch_val = new char(1);
            }
            else {
                ch_val = new char(prop);
                acmap.seekp(size + 49, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ch_val = new char(0);
            }
            acmap.seekg(size + 50, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 50, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 51, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_15(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 51, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 52, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_10(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 52, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 53, ios::beg);
            map_loc = acmap.tellg();
            p_53 = acmap.get();
            if (p_53 > 0) {
                acmap.seekg(size + 65, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_14(gener);
                if (prop > 255) {
                    prop -= 256;
                    ch_val = new char(prop);
                    acmap.seekp(size + 65, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    ch_val = new char(1);
                }
                else {
                    ch_val = new char(prop);
                    acmap.seekp(size + 65, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    ch_val = new char(0);
                }
                acmap.seekg(size + 66, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                acmap.seekp(size + 66, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 67, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_16(gener);
                ch_val = new char(prop);
                acmap.seekp(size + 67, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 70; b < 79; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_8(gener);
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 81; b < 88; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_8(gener);
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                if (p_53 > 1) {
                    acmap.seekg(size + 93, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_14(gener);
                    if (prop > 255) {
                        prop -= 256;
                        ch_val = new char(prop);
                        acmap.seekp(size + 93, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        ch_val = new char(1);
                    }
                    else {
                        ch_val = new char(prop);
                        acmap.seekp(size + 93, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        ch_val = new char(0);
                    }
                    acmap.seekg(size + 94, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    acmap.seekp(size + 94, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    acmap.seekg(size + 95, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_16(gener);
                    ch_val = new char(prop);
                    acmap.seekp(size + 95, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    for (int b = 98; b < 107; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_8(gener);
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                    for (int b = 109; b < 116; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_8(gener);
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                    if (p_53 > 2) {
                        acmap.seekg(size + 121, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_14(gener);
                        if (prop > 255) {
                            prop -= 256;
                            ch_val = new char(prop);
                            acmap.seekp(size + 121, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            ch_val = new char(1);
                        }
                        else {
                            ch_val = new char(prop);
                            acmap.seekp(size + 121, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            ch_val = new char(0);
                        }
                        acmap.seekg(size + 122, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        acmap.seekp(size + 122, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        acmap.seekg(size + 123, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_16(gener);
                        ch_val = new char(prop);
                        acmap.seekp(size + 123, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        for (int b = 126; b < 135; b++) {
                            acmap.seekg(size + b, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            prop = dist_8(gener);
                            ch_val = new char(prop);
                            acmap.seekp(size + b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                        for (int b = 137; b < 143; b++) {
                            acmap.seekg(size + b, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            prop = dist_8(gener);
                            ch_val = new char(prop);
                            acmap.seekp(size + b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                    }
                }
            }
            acmap.seekg(size + 54, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_24(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 54, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 55, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_9(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 55, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 56, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_25(gener) - 255;
            ch_val = new char(prop);
            acmap.seekp(size + 56, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 58; b < 61; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
        }
        acmap.seekg(size + 173, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 177, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 177, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 178, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_2(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 178, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 179, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 179, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 180, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_3(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 180, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            prop = dist_4(gener) * 100;
            sprintf_s(rand_dpm, "%X", prop);
            ss_rand_dpm << rand_dpm;
            ss_rand_dpm >> s_rand_dpm;
            ss_rand_dpm.clear();
            hs_rand_dpm << std::hex << s_rand_dpm;
            hs_rand_dpm >> int_rand_dpm;
            hs_rand_dpm.clear();
            dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
            prop = dist_5(gener) * 100;
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
            ppm = dist_6(gener);
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
            pp = dist_7(gener);
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
            prop = dist_21(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 189, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 190, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_22(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 190, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 191, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_23(gener) - 255;
            ch_val = new char(prop);
            acmap.seekp(size + 191, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 192, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_9(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 192, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            prop = (4 * dist_10(gener)) + dist_11(gener);
            acmap.seekg(size + 193, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            ch_val = new char(prop);
            acmap.seekp(size + 193, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 197; b < 200; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_12(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 200, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_13(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 200, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 201; b < 207; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            for (int b = 209; b < 216; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 217, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_13(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 217, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;                    
        }
        acmap.seekg(size + 221, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 225, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_14(gener);
            if (prop > 255) {
                prop -= 256;
                ch_val = new char(prop);
                acmap.seekp(size + 225, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ch_val = new char(1);
            }
            else {
                ch_val = new char(prop);
                acmap.seekp(size + 225, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ch_val = new char(0);
            }
            acmap.seekg(size + 226, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 226, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 227, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_15(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 227, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 228, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_10(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 228, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 229, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_33(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 229, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 230, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_24(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 230, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 231, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_9(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 231, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 232, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_25(gener) - 255;
            ch_val = new char(prop);
            acmap.seekp(size + 232, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 234; b < 237; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
        }
        acmap.seekg(size + 241, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 245, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 245, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 246, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_17(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 246, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 247, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 247, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            prop = dist_4(gener) * 100;
            sprintf_s(rand_dpm, "%X", prop);
            ss_rand_dpm << rand_dpm;
            ss_rand_dpm >> s_rand_dpm;
            ss_rand_dpm.clear();
            hs_rand_dpm << std::hex << s_rand_dpm;
            hs_rand_dpm >> int_rand_dpm;
            hs_rand_dpm.clear();
            dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
            prop = dist_5(gener) * 100;
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
            ppm = dist_6(gener);
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
            pp = dist_7(gener);
            acmap.seekg(size + 255, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            ch_val = new char(pp);
            acmap.seekp(size + 255, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 257, ios::beg);
            map_loc = acmap.tellg();
            p_257 = acmap.get();
            if (p_257 > 0) {
                acmap.seekg(size + 285, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_14(gener);
                if (prop > 255) {
                    prop -= 256;
                    ch_val = new char(prop);
                    acmap.seekp(size + 285, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    ch_val = new char(1);
                }
                else {
                    ch_val = new char(prop);
                    acmap.seekp(size + 285, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    ch_val = new char(0);
                }
                acmap.seekg(size + 286, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                acmap.seekp(size + 286, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                acmap.seekg(size + 287, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_16(gener);
                ch_val = new char(prop);
                acmap.seekp(size + 287, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                for (int b = 290; b < 299; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_8(gener);
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                for (int b = 301; b < 308; b++) {
                    acmap.seekg(size + b, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_8(gener);
                    ch_val = new char(prop);
                    acmap.seekp(size + b, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                }
                if (p_257 > 1) {
                    acmap.seekg(size + 313, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_14(gener);
                    if (prop > 255) {
                        prop -= 256;
                        ch_val = new char(prop);
                        acmap.seekp(size + 313, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        ch_val = new char(1);
                    }
                    else {
                        ch_val = new char(prop);
                        acmap.seekp(size + 313, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        ch_val = new char(0);
                    }
                    acmap.seekg(size + 314, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    acmap.seekp(size + 314, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    acmap.seekg(size + 315, ios::beg);
                    map_loc = acmap.tellg();
                    to_ass = acmap.get();
                    prop = dist_16(gener);
                    ch_val = new char(prop);
                    acmap.seekp(size + 315, ios::beg);
                    acmap.write(ch_val, 1);
                    delete ch_val;
                    for (int b = 318; b < 327; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_8(gener);
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                    for (int b = 329; b < 336; b++) {
                        acmap.seekg(size + b, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_8(gener);
                        ch_val = new char(prop);
                        acmap.seekp(size + b, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                    }
                    if (p_257 > 2) {
                        acmap.seekg(size + 341, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_14(gener);
                        if (prop > 255) {
                            prop -= 256;
                            ch_val = new char(prop);
                            acmap.seekp(size + 341, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            ch_val = new char(1);
                        }
                        else {
                            ch_val = new char(prop);
                            acmap.seekp(size + 341, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                            ch_val = new char(0);
                        }
                        acmap.seekg(size + 342, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        acmap.seekp(size + 342, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        acmap.seekg(size + 343, ios::beg);
                        map_loc = acmap.tellg();
                        to_ass = acmap.get();
                        prop = dist_16(gener);
                        ch_val = new char(prop);
                        acmap.seekp(size + 343, ios::beg);
                        acmap.write(ch_val, 1);
                        delete ch_val;
                        for (int b = 346; b < 355; b++) {
                            acmap.seekg(size + b, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            prop = dist_8(gener);
                            ch_val = new char(prop);
                            acmap.seekp(size + b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                        for (int b = 357; b < 363; b++) {
                            acmap.seekg(size + b, ios::beg);
                            map_loc = acmap.tellg();
                            to_ass = acmap.get();
                            prop = dist_8(gener);
                            ch_val = new char(prop);
                            acmap.seekp(size + b, ios::beg);
                            acmap.write(ch_val, 1);
                            delete ch_val;
                        }
                    }
                }
            }
            acmap.seekg(size + 258, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_26(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 258, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 259, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_27(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 259, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 260, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_28(gener) - 255;
            ch_val = new char(prop);
            acmap.seekp(size + 260, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 262; b < 271; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            for (int b = 273; b < 280; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 281, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_13(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 281, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
        }
        acmap.seekg(size + 369, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 373, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 373, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 376, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (to_ass == 2) {
                dist_18 = std::uniform_int_distribution<>(17, 32);
            }
            else if (to_ass == 3) {
                dist_18 = std::uniform_int_distribution<>(33, 48);
            }
            else if (to_ass == 4) {
                dist_18 = std::uniform_int_distribution<>(49, 64);
            }
            else if (to_ass == 5) {
                dist_18 = std::uniform_int_distribution<>(65, 80);
            }
            prop = dist_18(gener);
            ch_val = new char(prop);
            acmap.seekg(size + 374, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 374, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            prop = dist_4(gener) * 100;
            sprintf_s(rand_dpm, "%X", prop);
            ss_rand_dpm << rand_dpm;
            ss_rand_dpm >> s_rand_dpm;
            ss_rand_dpm.clear();
            hs_rand_dpm << std::hex << s_rand_dpm;
            hs_rand_dpm >> int_rand_dpm;
            hs_rand_dpm.clear();
            dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
            prop = dist_5(gener) * 100;
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
            prop = dist_30(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 386, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 387, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_31(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 387, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 388, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_32(gener) - 255;
            ch_val = new char(prop);
            acmap.seekp(size + 388, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 390; b < 399; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            for (int b = 401; b < 408; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 409, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_13(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 409, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
        }
        acmap.seekg(size + 413, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 417, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 417, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 420, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            if (to_ass == 2) {
                dist_18 = std::uniform_int_distribution<>(17, 32);
            }
            else if (to_ass == 3) {
                dist_18 = std::uniform_int_distribution<>(33, 48);
            }
            else if (to_ass == 4) {
                dist_18 = std::uniform_int_distribution<>(49, 64);
            }
            else if (to_ass == 5) {
                dist_18 = std::uniform_int_distribution<>(65, 80);
            }
            prop = dist_18(gener);
            ch_val = new char(prop);
            acmap.seekg(size + 418, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 418, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            prop = dist_4(gener) * 100;
            sprintf_s(rand_dpm, "%X", prop);
            ss_rand_dpm << rand_dpm;
            ss_rand_dpm >> s_rand_dpm;
            ss_rand_dpm.clear();
            hs_rand_dpm << std::hex << s_rand_dpm;
            hs_rand_dpm >> int_rand_dpm;
            hs_rand_dpm.clear();
            dist_5 = std::uniform_int_distribution<>(41, round(int_rand_dpm / 100));
            prop = dist_5(gener) * 100;
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
            prop = dist_30(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 430, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 431, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_31(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 431, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 432, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_32(gener) - 255;
            ch_val = new char(prop);
            acmap.seekp(size + 432, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 434; b < 443; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            for (int b = 445; b < 452; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            acmap.seekg(size + 453, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_13(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 453, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
        }
        acmap.seekg(size + 457, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 461, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 461, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 462, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_19(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 462, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 474; b < 477; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_29(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            for (int b = 478; b < 487; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            for (int b = 489; b < 496; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
        }
        acmap.seekg(size + 501, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3) {
            acmap.seekg(size + 505, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_14(gener);
            if (prop > 255) {
                prop -= 256;
                ch_val = new char(prop);
                acmap.seekp(size + 505, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ch_val = new char(1);
            }
            else {
                ch_val = new char(prop);
                acmap.seekp(size + 505, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
                ch_val = new char(0);
            }
            acmap.seekg(size + 506, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            acmap.seekp(size + 506, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            acmap.seekg(size + 507, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_16(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 507, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
            for (int b = 510; b < 519; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
            for (int b = 521; b < 528; b++) {
                acmap.seekg(size + b, ios::beg);
                map_loc = acmap.tellg();
                to_ass = acmap.get();
                prop = dist_8(gener);
                ch_val = new char(prop);
                acmap.seekp(size + b, ios::beg);
                acmap.write(ch_val, 1);
                delete ch_val;
            }
        }
        acmap.seekg(size + 535, ios::beg);
        map_loc = acmap.tellg();
        to_ass = acmap.get();
        if (to_ass == 3 && std::find(mlks.begin(), mlks.end(), ivm) == mlks.end()) {
            acmap.seekg(size + 533, ios::beg);
            map_loc = acmap.tellg();
            to_ass = acmap.get();
            prop = dist_20(gener) - 256;
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
            prop = dist_1(gener);
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
            prop = dist_20(gener) - 256;
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
            prop = dist_1(gener);
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
            prop = dist_20(gener) - 256;
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
            prop = dist_1(gener);
            ch_val = new char(prop);
            acmap.seekp(size + 544, ios::beg);
            acmap.write(ch_val, 1);
            delete ch_val;
        }
        system((aRF.getTool() + " '" + aGame.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'").c_str());
        acmap.close();
        std::advance(mlp, 1);
    }
}
