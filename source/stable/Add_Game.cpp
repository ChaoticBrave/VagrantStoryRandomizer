#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>

#include "Add_Game.h"
#include "Reference_Files.h"

using namespace std;

Add_Game::Add_Game() {
    cp = current_path();
}

path Add_Game::getPath() {
    return cp;
}

string Add_Game::getStringPath() {
    return cp.string();
}

string Add_Game::getFileName() {
    return file_name;
}

void Add_Game::giveName() {
    file_name = "";
    cout << "Please enter the ROM file name: " << endl;
    getline(cin, file_name);
}

path Add_Game::getWhole() {
    if (guiValidatorUsed == true) {
        return file_name;
    }
    else {
        return getStringPath() + "\\" + getFileName();
    }
}

void Add_Game::validate(fstream& aGame, Reference_Files aRef) {
    bool is_vs = false;
    string rom_com;
    streampos address;
    int add_val;
    while (is_vs == false) {
        giveName();
        rom_com = "";
        aGame.open(getWhole(), ios::in | ios::out | ios::binary | ios::ate);
        if (!aGame) {
            cout << "File not found" << endl;
            aGame.close();
        }
        else {
            for (int o = 37696; o < 37704; o++) {
                aGame.seekg(o, ios::beg);
                address = aGame.tellg();
                add_val = aGame.get();
                rom_com += to_string(add_val);
            }
            if (rom_com == aRef.getCom()) {
                is_vs = true;
                cout << "ROM accepted!" << endl;
            }  
            else {
                cout << "This isn't Vagrant Story" << endl;
                aGame.close();
            }
        }
    }
}

bool Add_Game::guiValidate(fstream& aGame, Reference_Files aRef, string aPath) {
    guiValidatorUsed = false;
    bool is_vs = false;
    string rom_com = "";
    streampos address;
    int add_val;
    aGame.open(aPath, ios::in | ios::out | ios::binary | ios::ate);
    if (!aGame) {
        aGame.close();
        return is_vs;
    }
    else {
        for (int o = 37696; o < 37704; o++) {
            aGame.seekg(o, ios::beg);
            address = aGame.tellg();
            add_val = aGame.get();
            rom_com += to_string(add_val);
        }
        if (rom_com == aRef.getCom()) {
            is_vs = true;
            guiValidatorUsed = true;
            file_name = aPath;
            aGame.close();
            return is_vs;
        }
        else {
            aGame.close();
            return is_vs;
        }
    }
}
   

