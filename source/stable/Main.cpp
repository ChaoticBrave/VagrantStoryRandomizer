#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <filesystem>
#include <stddef.h> 
#include "Reference_Files.h"
#include "Add_Game.h"
#include "Enemies.h"
#include "Chests.h"
#include "Rooms.h"


using namespace std;
using std::filesystem::current_path;
using std::filesystem::path;
using std::filesystem::u8path;


int main() {
    cout << "============================" << endl;
    cout << "Instructions:" << endl;
    cout << "1) Insert your Vagrant Story bin file into the unzipped randomizer folder." << endl;
    cout << "2) Open vagrant_story_randomizer." << endl;
    cout << "3) Enter the name of your Vagrant Story bin file." << endl;
    cout << "4) Let the randomizer run. You will get to choose what you randomize as you go along." << endl;
    cout << "============================" << endl;

    Reference_Files ref = Reference_Files();
    string rom_code = ref.getCom();

    bool is_vs = false;
    int start_range = 0;

    Add_Game adder = Add_Game();
    fstream game;

    adder.validate(game, ref);

    string decision_e;
    string decision_d;
    string decision_c;
    string decision_r;

    while (decision_e != "Y" && decision_e != "N") {
        decision_e = "";
        cout << "Would you like to randomize enemies? (Y/N)" << endl;
        getline(cin, decision_e);
        if (decision_e != "Y" && decision_e != "N") {
            cout << "Please input 'Y' or 'N' " << endl;
        }
    }

    if (decision_e == "Y") {
        while (decision_d != "Y" && decision_d != "N") {
            decision_d = "";
            cout << "Would you like to randomize enemy drops? (Y/N)" << endl;
            getline(cin, decision_d);
            if (decision_d != "Y" && decision_d != "N") {
                cout << "Please input 'Y' or 'N' " << endl;
            }
        }
        cout << "Please wait..." << endl;
        Enemies ene_ran = Enemies();
        ene_ran.mapIterate(ref, adder, decision_d);
        cout << "Enemy randomization completed." << endl;
    }

    while (decision_c != "Y" && decision_c != "N") {
        decision_c = "";
        cout << "Would you like to randomize chests? (Y/N)" << endl;
        getline(cin, decision_c);
        if (decision_c != "Y" && decision_c != "N") {
            cout << "Please input 'Y' or 'N' " << endl;
        }
    }

    if (decision_c == "Y") {
        cout << "Please wait..." << endl;
        Chests che_ran = Chests();
        che_ran.mapIterate(ref, adder);
        cout << "Chest randomization completed." << endl;
    }

    while (decision_r != "Y" && decision_r != "N") {
        decision_r = "";
        cout << "Would you like to randomize area progression? (Y/N)" << endl;
        getline(cin, decision_r);
        if (decision_r != "Y" && decision_r != "N") {
            cout << "Please input 'Y' or 'N' " << endl;
        }
    }

    if (decision_r == "Y") {
        cout << "Please wait..." << endl;
        Rooms room_ran = Rooms();
        room_ran.roomIterate(ref, adder);
        cout << "Room randomization completed." << endl;
    }

    cout << "Randomization complete!" << endl;
    game.close();

    system("pause");

	return 0;
}
