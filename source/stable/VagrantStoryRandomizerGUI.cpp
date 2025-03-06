// VagrantStoryRandomizerGUI.cpp : Defines the entry point for the application.
//
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <afxwin.h>
#include "framework.h"
#include "VagrantStoryRandomizerGUI.h"
#include <shobjidl.h> 
#include <string>
#include <winuser.h>
#include <stdio.h>
#include <vector>
#include <filesystem>
#include "Add_Game.h"
#include <iostream>
#include <list>
#include <fstream>
#include <stddef.h>
#include <commdlg.h>
#include "Enemies.h"
#include "Chests.h"
#include "Rooms.h"
#include "Ashley.h"
#include <chrono>
#include <commctrl.h>




#define MAX_LOADSTRING 100



// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND openGame;
HWND gamePath;
HWND enemies;
HWND chests;
HWND rooms;
HWND drops;
HWND balance;
HWND keep;
HWND consEqu;
HWND eneMod;
HWND eneStat;
HWND balEneStat;
HWND ashley;
HWND balAshley;
HWND fandango;
//HWND cusAsh;
HWND randomizeButton;
HWND revertButton;
HWND seedButton;
HWND cSeedButton;
HWND window;
HWND getCon = GetConsoleWindow();
DWORD dwStyle = WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;
std::vector<HWND> butRos;
Add_Game ag = Add_Game();
int xCor = 640;
int yCor = 380;
int seedBoxID;
int vanBoxID;
int runEne;
int runChe;
int runRoo;
int runAsh;
int point;
unsigned int cusSeedI = NULL;
void placeButtons();
void setWin(HWND hWnd);
void makeButtons(HWND hWnd);
void toolTipMaker(HWND hWnd);
void ranBoxLock();
void relock();
void checkBoxLock();
void revertCode(HWND hWnd);
HWND CreateToolTip(HWND hParent, HWND hText, HINSTANCE hInst, PTSTR ptText);
HWND toolGen(char* text, HWND hWnd, HWND hText);
bool gamePathFound = false;
bool pa_enemies = false;
bool pa_models = false;
bool pa_stats = false;
bool pa_balstats = false;
bool pa_chests = false;
bool pa_rooms = false;
bool pa_drops = false;
bool pa_balance = false;
bool pa_keep = false;
bool pa_cons = false;
bool pa_ashley = false;
bool pa_balAshley = false;
bool pa_fandango = false;
//bool pa_cusAsh = false;
bool cusSeedU = false;
bool freshPick = false;
string choiceD;
string choiceE;
string choiceM;
string choiceSt;
string choiceB;
string choiceBe;
string choiceK;
string choiceC;
string choiceChe;
string choiceA;
string choiceAsh;
string choiceBalAsh;
string choiceFan;
//string choiceCusAsh;
string seedChoice;
string cusSeedS;
string strForPath;
string cur_map;
string cur_zone;
string m_file;
string z_file;
string choices;
vector<string> ivm;
vector<string>::iterator ivmp;
vector<string>::iterator wmp;
vector<vector<string>> mlForEne;
vector<vector<string>>::iterator mlpForEne;
vector<string> ml;
vector<string> wm;
list<string> ez;
list<string>::iterator ezp;
vector<string>::iterator mlp;
fstream game;
fstream seedFile;
Reference_Files rf = Reference_Files();
RECT rcWindow;
std::mt19937 gen;
std::mt19937 finGen;
std::ofstream vanBat;
TOOLINFO paraInfo;
TCHAR enetext[256];
TCHAR chetext[256];
TCHAR mistext[256];


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_VAGRANTSTORYRANDOMIZERGUI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VAGRANTSTORYRANDOMIZERGUI));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VAGRANTSTORYRANDOMIZERGUI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_VAGRANTSTORYRANDOMIZERGUI);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   //WS_OVERLAPPEDWINDOW

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, dwStyle,
      CW_USEDEFAULT, 0, 350, 450, nullptr, nullptr, hInstance, nullptr);
   if (!hWnd)
   {
      return FALSE;
   }
   //StartCommonControls(ICC_TAB_CLASSES);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        makeButtons(hWnd);
        placeButtons();
        for (int i = 0; i < butRos.size(); i++) {
            SendMessage(butRos[i], WM_SETFONT, (LPARAM)GetStockObject(DEFAULT_GUI_FONT), NULL);
        }
        ranBoxLock();
        checkBoxLock();
        toolTipMaker(hWnd);
        break;
    }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_OPEN:
            {
                OPENFILENAMEA opfi;
                ZeroMemory(&opfi, sizeof(opfi));
                opfi.lStructSize = sizeof(opfi);
                opfi.hwndOwner = hWnd;
                opfi.lpstrFilter = "Bin File (*.bin)\0*.bin\0";
                opfi.Flags = OFN_DONTADDTORECENT | OFN_ENABLESIZING | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                opfi.nMaxFile = MAX_PATH;
                char fisi[MAX_PATH];
                opfi.lpstrFile = fisi;
                opfi.lpstrFile[0] = '\0';
                opfi.nFilterIndex = 1;
                if (GetOpenFileNameA(&opfi)) {
                    string path = opfi.lpstrFile;
                    if (ag.guiValidate(game, rf, path) == true) {
                        gamePathFound = true;
                        std::wstring wpath = std::wstring(path.begin(), path.end());
                        LPCWSTR lpath = wpath.c_str();
                        if (gamePathFound) {
                            checkBoxLock();
                        }
                    }
                    else {
                        MessageBox(hWnd, L"The bin is not valid.", L"Error", MB_ICONERROR);
                    }
                }
            }
            break;
            case IDM_CHOOSE_PARA:
            {
                LRESULT eneticked = SendMessage(enemies, BM_GETCHECK, NULL, NULL);
                LRESULT droticked = SendMessage(drops, BM_GETCHECK, NULL, NULL);
                LRESULT blcticked = SendMessage(balance, BM_GETCHECK, NULL, NULL);
                LRESULT keeticked = SendMessage(keep, BM_GETCHECK, NULL, NULL);
                LRESULT consticked = SendMessage(consEqu, BM_GETCHECK, NULL, NULL);
                LRESULT modticked = SendMessage(eneMod, BM_GETCHECK, NULL, NULL);
                LRESULT statticked = SendMessage(eneStat, BM_GETCHECK, NULL, NULL);
                LRESULT balstatticked = SendMessage(balEneStat, BM_GETCHECK, NULL, NULL);
                LRESULT cheticked = SendMessage(chests, BM_GETCHECK, NULL, NULL);
                LRESULT rooticked = SendMessage(rooms, BM_GETCHECK, NULL, NULL);
                LRESULT ashticked = SendMessage(ashley, BM_GETCHECK, NULL, NULL);
                LRESULT balAshticked = SendMessage(balAshley, BM_GETCHECK, NULL, NULL);
                LRESULT fanTicked = SendMessage(fandango, BM_GETCHECK, NULL, NULL);
                //LRESULT cusTicked = SendMessage(cusAsh, BM_GETCHECK, NULL, NULL);

                if (eneticked == BST_CHECKED) {
                    pa_enemies = true;
                    choiceE = "Y";
                }
                else {
                    pa_enemies = false;
                    choiceE = "N";
                }
                if (modticked == BST_CHECKED) {
                    pa_models = true;
                    choiceM = "Y";
                }
                else {
                    pa_models = false;
                    choiceM = "N";
                }
                if (statticked == BST_CHECKED) {
                    pa_stats = true;
                    EnableWindow(butRos[butRos.size() - 1], true);
                    choiceSt = "Y";
                }
                else {
                    pa_stats = false;
                    EnableWindow(butRos[butRos.size() - 1], false);
                    choiceSt = "N";
                }
                if (balstatticked == BST_CHECKED) {
                    pa_balstats = true;
                    choiceBe = "Y";
                }
                else {
                    pa_balstats = false;
                    choiceBe = "N";
                }
                if (cheticked == BST_CHECKED) {
                    pa_chests = true;
                    EnableWindow(butRos[butRos.size() - 4], true);
                    EnableWindow(butRos[butRos.size() - 3], true);
                    EnableWindow(butRos[butRos.size() - 2], true);
                    choiceChe = "Y";
                }
                else {
                    pa_chests = false;
                    EnableWindow(butRos[butRos.size() - 4], false);
                    EnableWindow(butRos[butRos.size() - 3], false);
                    EnableWindow(butRos[butRos.size() - 2], false);
                    choiceChe = "N";
                }
                if (rooticked == BST_CHECKED) {
                    pa_rooms = true;
                    choiceA = "Y";
                }
                else {
                    pa_rooms = false;
                    choiceA = "N";
                }
                if (ashticked == BST_CHECKED) {
                    pa_ashley = true;
                    choiceAsh = "Y";
                    EnableWindow(butRos[butRos.size() - 6], true);
                    EnableWindow(butRos[butRos.size() - 5], true);
                }
                else {
                    pa_ashley = false;
                    choiceAsh = "N";
                    EnableWindow(butRos[butRos.size() - 6], false);
                    EnableWindow(butRos[butRos.size() - 5], false);
                }
                if (balAshticked == BST_CHECKED) {
                    pa_balAshley = true;
                    choiceBalAsh = "Y";
                }
                else {
                    pa_balAshley = false;
                    choiceBalAsh = "N";
                }
                if (fanTicked == BST_CHECKED) {
                    pa_fandango = true;
                    choiceFan = "Y";
                }
                else {
                    pa_fandango = false;
                    choiceFan = "N";
                }
                //if (cusTicked == BST_CHECKED) {
                    //pa_cusAsh = true;
                    //choiceCusAsh = "Y";
                //}
                //else {
                    //pa_cusAsh = false;
                    //choiceCusAsh = "N";
                //}
                if (droticked == BST_CHECKED) {
                    pa_drops = true;
                    choiceD = "Y";
                }
                else {
                    pa_drops = false;
                    choiceD = "N";
                }
                if (blcticked == BST_CHECKED && cheticked == BST_CHECKED) {
                    choiceB = "Y";
                }
                else {
                    choiceB = "N";
                }
                if (keeticked == BST_CHECKED && cheticked == BST_CHECKED) {
                    choiceK = "Y";
                }
                else {
                    choiceK = "N";
                }
                if (consticked == BST_CHECKED && cheticked == BST_CHECKED) {
                    choiceC = "Y";
                }
                else {
                    choiceC = "N";
                }
                ranBoxLock();
            }
            break;
            case IDM_RANDOMIZE:
            {
                bool changed = false;
                //seedBox() {
                choices = "." + choiceFan + choiceBalAsh + choiceAsh + choiceBe + choiceSt + choiceM + choiceE + choiceChe + choiceA + choiceD + choiceB + choiceK + choiceC;
                seedBoxID = MessageBox(hWnd, L"Would you like to save the seed used?", L"Save Seed?", MB_YESNO);
                switch (seedBoxID)
                {
                case IDYES:
                    seedChoice = "Y";
                    break;
                case IDNO:
                    seedChoice = "N";
                    break;
                }
                    //return seedBoxID;
                //}
                if (cusSeedU == true) {
                    ag.makeGenPlus(seedChoice, cusSeedI, choices);
                }
                else {
                    ag.makeGen(seedChoice, choices);
                }
                finGen = ag.getGen();
                if (seedChoice == "Y") {
                    MessageBox(hWnd, L"Seed saved to 'seed.txt'.", L"Seed Saved", MB_OK);
                }
                vanBoxID = MessageBox(hWnd, L"Would you like to randomize a fresh game?", L"Use vanilla version?", MB_YESNO);
                switch (vanBoxID)
                {
                case IDYES:
                    freshPick = true;
                    revertCode(hWnd);
                    break;
                case IDNO:
                    break;
                }
                if (pa_ashley) {
                    changed = true;
                    remove("ashCmd.cmd");
                    Ashley ash_maker = Ashley();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Ashley...");
                    ash_maker.statIterate(rf, ag, finGen, choiceBalAsh, choiceFan);
                    runAsh = system("cmd.exe /c ashCmd.cmd");
                    remove("ashCmd.cmd");
                    SetWindowTextA(hWnd, "Ashley Randomized");
                }
                if (pa_rooms) {
                    changed = true;
                    remove("rooCmd.cmd");
                    Rooms roo_ran = Rooms();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Rooms...");
                    roo_ran.roomIterate(rf, ag, finGen);
                    runRoo = system("cmd.exe /c rooCmd.cmd");
                    remove("rooCmd.cmd");
                    SetWindowTextA(hWnd, "Rooms Randomized");
                }
                if (pa_chests) {
                    changed = true;
                    remove("cheCmd.cmd");
                    Chests che_ran = Chests();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Chests...");
                    che_ran.mapIterate(rf, ag, finGen, choiceB, choiceK, choiceC);
                    runChe = system("cmd.exe /c cheCmd.cmd");
                    remove("cheCmd.cmd");
                    SetWindowTextA(hWnd, "Chests Randomized");
                }
                if (pa_enemies || pa_models || pa_stats || pa_drops) {
                    changed = true;
                    remove("eneCmd.cmd");
                    Enemies ene_ran = Enemies();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Enemies...");
                    ene_ran.mapIterate(rf, ag, choiceD, finGen, choiceM, choiceE, choiceSt, choiceBe);
                    runEne = system("cmd.exe /c eneCmd.cmd");
                    remove("eneCmd.cmd");
                    SetWindowTextA(hWnd, "Enemies Randomized");
                }
                if (changed == true)
                {
                    SetWindowTextA(hWnd, "Vagrant Story Randomizer");
                    MessageBox(hWnd, L"Randomization completed!", L"Success", MB_OK);
                    relock();
                }
            }
            break;
            case IDM_REVERT:
            {
                revertCode(hWnd);
            }
            break;
            case IDM_GETSEED:
            {
                OPENFILENAMEA opse;
                ZeroMemory(&opse, sizeof(opse));
                streampos address;
                int lastPoint;
                int penPoint;
                int seedPoint;
                int rawSeedPoint;
                int dest;
                string num;
                opse.lStructSize = sizeof(opse);
                opse.hwndOwner = hWnd;
                opse.lpstrFilter = "Text File (*.txt)\0*.txt\0";
                opse.Flags = OFN_DONTADDTORECENT | OFN_ENABLESIZING | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                opse.nMaxFile = MAX_PATH;
                char sesi[MAX_PATH];
                opse.lpstrFile = sesi;
                opse.lpstrFile[0] = '\0';
                opse.nFilterIndex = 1;
                if (GetOpenFileNameA(&opse)) {
                    string seedPath = opse.lpstrFile;
                    seedFile.open(seedPath, ios::in | ios::out | ios::binary | ios::ate);
                    dest = seedFile.tellg();
                    seedFile.seekg(-1, ios::end);
                    address = seedFile.tellg();
                    lastPoint = seedFile.get();
                    seedFile.seekg(-2, ios::end);
                    address = seedFile.tellg();
                    penPoint = seedFile.get();
                    if ((penPoint == 13 && lastPoint == 10) == true) {
                        cusSeedI = NULL;
                        cusSeedS = "";
                        for (int p = 0; p < dest - 1; p++) {
                            seedFile.seekg(p, sizeof(opse) - sizeof(opse));
                            address = seedFile.tellg();
                            rawSeedPoint = seedFile.get();
                            if (rawSeedPoint >= 48 && rawSeedPoint <= 57) {
                                seedPoint = rawSeedPoint - 48;
                                num = std::to_string(seedPoint);
                                cusSeedS = cusSeedS + num;
                            }
                        }
                        if (cusSeedS != "") {
                            istringstream iss(cusSeedS);
                            iss >> cusSeedI;
                            seedFile.seekg(-15, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickefandango = SendMessage(fandango, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickeash = SendMessage(ashley, BM_SETCHECK, BST_CHECKED, 0);
                                pa_balAshley = true;
                                choiceFan = "Y";
                                pa_ashley = true;
                                choiceAsh = "Y";
                            }
                            else {
                                pa_fandango = false;
                                choiceFan = "N";
                            }
                            seedFile.seekg(-14, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickebalash = SendMessage(balAshley, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickeash = SendMessage(ashley, BM_SETCHECK, BST_CHECKED, 0);
                                pa_balAshley = true;
                                choiceBalAsh = "Y";
                                pa_ashley = true;
                                choiceAsh = "Y";
                            }
                            else {
                                pa_balAshley = false;
                                choiceBalAsh = "N";
                            }
                            seedFile.seekg(-13, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickeash = SendMessage(ashley, BM_SETCHECK, BST_CHECKED, 0);
                                pa_ashley = true;
                                choiceAsh = "Y";
                                EnableWindow(butRos[butRos.size() - 6], true);
                                EnableWindow(butRos[butRos.size() - 5], true);
                            }
                            else {
                                pa_ashley = false;
                                choiceAsh = "N";
                                EnableWindow(butRos[butRos.size() - 6], false);
                                EnableWindow(butRos[butRos.size() - 5], false);
                            }
                            seedFile.seekg(-12, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickebalstat = SendMessage(balEneStat, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickestat = SendMessage(eneStat, BM_SETCHECK, BST_CHECKED, 0);
                                pa_stats = true;
                                pa_balstats = true;
                                choiceBe = "Y";
                                choiceSt = "Y";
                            }
                            else {
                                pa_stats = false;
                                choiceBe = "N";
                            }
                            seedFile.seekg(-11, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickestat = SendMessage(eneStat, BM_SETCHECK, BST_CHECKED, 0);
                                EnableWindow(butRos[butRos.size() - 1], true);
                                pa_stats = true;
                                choiceSt = "Y";
                            }
                            else {
                                EnableWindow(butRos[butRos.size() - 1], true);
                                pa_stats = false;
                                choiceSt = "N";
                            }
                            seedFile.seekg(-10, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickemod = SendMessage(eneMod, BM_SETCHECK, BST_CHECKED, 0);
                                pa_models = true;
                                choiceM = "Y";
                            }
                            else {
                                pa_models = false;
                                choiceM = "N";
                            }
                            seedFile.seekg(-9, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickene = SendMessage(enemies, BM_SETCHECK, BST_CHECKED, 0);
                                pa_enemies = true;
                                choiceE = "Y";
                            }
                            else {
                                pa_enemies = false;
                                choiceE = "N";
                            }
                            seedFile.seekg(-8, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickche = SendMessage(chests, BM_SETCHECK, BST_CHECKED, 0);
                                pa_chests = true;
                                EnableWindow(butRos[butRos.size() - 4], true);
                                EnableWindow(butRos[butRos.size() - 3], true);
                                EnableWindow(butRos[butRos.size() - 2], true);
                                choiceChe = "Y";
                            }
                            else {
                                pa_chests = false;
                                EnableWindow(butRos[butRos.size() - 4], false);
                                EnableWindow(butRos[butRos.size() - 3], false);
                                EnableWindow(butRos[butRos.size() - 2], false);
                                choiceChe = "N";
                            }
                            seedFile.seekg(-7, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickroo = SendMessage(rooms, BM_SETCHECK, BST_CHECKED, 0);
                                pa_rooms = true;
                                choiceA = "Y";
                            }
                            else {
                                pa_rooms = false;
                                choiceA = "N";
                            }
                            seedFile.seekg(-6, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickdro = SendMessage(drops, BM_SETCHECK, BST_CHECKED, 0);
                                pa_drops = true;
                                choiceD = "Y";
                            }
                            else {
                                pa_drops = false;
                                choiceD = "N";
                            }
                            seedFile.seekg(-5, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickbal = SendMessage(balance, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickche = SendMessage(chests, BM_SETCHECK, BST_CHECKED, 0);
                                EnableWindow(butRos[butRos.size() - 4], true);
                                EnableWindow(butRos[butRos.size() - 3], true);
                                EnableWindow(butRos[butRos.size() - 2], true);
                                choiceB = "Y";
                                choiceChe = "Y";
                            }
                            else {
                                choiceB = "N";
                            }
                            seedFile.seekg(-4, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickkee = SendMessage(keep, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickche = SendMessage(chests, BM_SETCHECK, BST_CHECKED, 0);
                                EnableWindow(butRos[butRos.size() - 4], true);
                                EnableWindow(butRos[butRos.size() - 3], true);
                                EnableWindow(butRos[butRos.size() - 2], true);
                                choiceK = "Y";
                                choiceChe = "Y";
                            }
                            else {
                                choiceK = "N";
                            }
                            seedFile.seekg(-3, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickcon = SendMessage(consEqu, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickche = SendMessage(chests, BM_SETCHECK, BST_CHECKED, 0);
                                EnableWindow(butRos[butRos.size() - 4], true);
                                EnableWindow(butRos[butRos.size() - 3], true);
                                EnableWindow(butRos[butRos.size() - 2], true);
                                choiceC = "Y";
                                choiceChe = "Y";
                            }
                            else {
                                choiceC = "N";
                            }
                            ranBoxLock();
                            MessageBox(hWnd, L"The given seed will be used.", L"Seed Stored", MB_OK);
                            cusSeedU = true;
                        }
                        else {
                            MessageBox(hWnd, L"The seed must only contain numbers.", L"Error", MB_ICONERROR);
                            cusSeedU = false;
                        }
                    }
                    else {
                        MessageBox(hWnd, L"The seed is not valid.", L"Error", MB_ICONERROR);
                        cusSeedU = false;
                    }
                    seedFile.close();
                }
            }
            break;
            case IDM_CLEARSEED:
            {
                cusSeedI = NULL;
                cusSeedS = "";
                MessageBox(hWnd, L"Any given seeds have been cleared.", L"Seed Cleared", MB_OK);
                cusSeedU = false;
            }
            break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
            SetBkMode(hdc, TRANSPARENT);
            // TODO: Add any drawing code that uses hdc here...
            SelectObject(hdc, hFont);
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
            GetClientRect(hWnd, &rcWindow);
            swprintf_s(enetext, 256, L"Enemy data:");
            swprintf_s(chetext, 256, L"Chest data:");
            swprintf_s(mistext, 256, L"Misc data:");
            TextOut(hdc, xCor * 0.0325, yCor * 0.15, enetext, wcslen(enetext));
            TextOut(hdc, xCor * 0.0325, yCor * 0.39, chetext, wcslen(chetext));
            TextOut(hdc, xCor * 0.0325, yCor * 0.5725, mistext, wcslen(mistext));
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_CTLCOLORSTATIC:
        for (int i = 0; i < butRos.size(); i++) {
            return (LONG)GetStockObject(WHITE_BRUSH);
        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

HWND CreateToolTip(HWND hParent, HWND hText, HINSTANCE hInst, PTSTR ptText) {
    if (!hParent || !hText || !ptText)
    {
        return NULL;
    }

    HWND hwndTip = CreateWindowEx(NULL, TOOLTIPS_CLASS, NULL,
        WS_POPUP | TTS_ALWAYSTIP,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        hParent, NULL,
        hInst, NULL);

    if (!hwndTip)
    {
        return NULL;
    }

    paraInfo.cbSize = sizeof(paraInfo);
    paraInfo.hwnd = hParent;
    paraInfo.hinst = hInst;
    paraInfo.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
    paraInfo.uId = (UINT_PTR)hText;
    paraInfo.lpszText = ptText;
    GetClientRect(hParent, &paraInfo.rect);
    SendMessage(hwndTip, TTM_ADDTOOL, 0, (LPARAM)&paraInfo);
    SendMessage(hwndTip, TTM_SETMAXTIPWIDTH, 0, 255);
    return hwndTip;
}

HWND toolGen(char* text, HWND hWnd, HWND hText) {
    wchar_t wtext[256];
    mbstowcs(wtext, text, strlen(text) + 1);
    LPWSTR ptr = wtext;
    HWND hWndTT = CreateToolTip(hWnd, hText, hInst, ptr);
    return hWndTT;
}

void placeButtons() {
    butRos.emplace_back(openGame);
    butRos.emplace_back(randomizeButton);
    butRos.emplace_back(seedButton);
    butRos.emplace_back(cSeedButton);
    butRos.emplace_back(revertButton);
    butRos.emplace_back(enemies);
    butRos.emplace_back(chests);
    butRos.emplace_back(rooms);
    butRos.emplace_back(eneMod);
    butRos.emplace_back(drops);
    butRos.emplace_back(eneStat);
    butRos.emplace_back(ashley);
    butRos.emplace_back(balAshley);
    butRos.emplace_back(fandango);
    //butRos.emplace_back(cusAsh);
    butRos.emplace_back(balance);
    butRos.emplace_back(keep);
    butRos.emplace_back(consEqu);
    butRos.emplace_back(balEneStat);
}

void makeButtons(HWND hWnd) {
    openGame = CreateWindow(L"BUTTON", L"Open Game", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * 0.1825), (int)(yCor * 0.05), 90, 25, hWnd, (HMENU)101, hInst, NULL);
    randomizeButton = CreateWindow(L"BUTTON", L"Randomize", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * 0.1825), (int)(yCor * 0.9395), 90, 25, hWnd, (HMENU)9003, hInst, NULL);
    seedButton = CreateWindow(L"BUTTON", L"Enter Seed", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * 0.0325), (int)(yCor * 0.8385), 90, 25, hWnd, (HMENU)9004, hInst, NULL);
    cSeedButton = CreateWindow(L"BUTTON", L"Clear Seed", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * 0.1825), (int)(yCor * 0.8385), 90, 25, hWnd, (HMENU)9005, hInst, NULL);
    revertButton = CreateWindow(L"BUTTON", L"Revert to Vanilla", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * 0.3325), (int)(yCor * 0.8385), 90, 25, hWnd, (HMENU)9006, hInst, NULL);
    enemies = CreateWindow(L"BUTTON", L"Enemies", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.20), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    chests = CreateWindow(L"BUTTON", L"Chests", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.44), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    rooms = CreateWindow(L"BUTTON", L"Area Progression", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.6225), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    drops = CreateWindow(L"BUTTON", L"Drops", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.275), (int)(yCor * 0.2575), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    balance = CreateWindow(L"BUTTON", L"Balance Item Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.275), (int)(yCor * 0.44), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    keep = CreateWindow(L"BUTTON", L"Keep Item Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.4975), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    consEqu = CreateWindow(L"BUTTON", L"Inconsistent Gear", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.275), (int)(yCor * 0.4975), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    eneMod = CreateWindow(L"BUTTON", L"Enemy Models", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.2575), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    eneStat = CreateWindow(L"BUTTON", L"Enemy Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.315), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    balEneStat = CreateWindow(L"BUTTON", L"Balance Enemy Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.275), (int)(yCor * 0.315), 120, 25, hWnd, (HMENU)9002, hInst, NULL);
    ashley = CreateWindow(L"BUTTON", L"Ashley's Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.68), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    balAshley = CreateWindow(L"BUTTON", L"Balance Ashley's Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.275), (int)(yCor * 0.7375), 140, 25, hWnd, (HMENU)9002, hInst, NULL);
    fandango = CreateWindow(L"BUTTON", L"Fandango Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.7375), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    //cusAsh = CreateWindow(L"BUTTON", L"Add Gem and Shield Data", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.275), (int)(yCor * 0.7375), 140, 25, hWnd, (HMENU)9002, hInst, NULL);
}

void toolTipMaker(HWND hWnd) {
    char open[] =
        "Load up a copy of Vagrant Story and get\n"
        "started.";
    HWND openTip = toolGen(open, hWnd, openGame);
    char randomize[] =
        "Get randomizing once you've picked some\n"
        "paramaters.";
    HWND randoTip = toolGen(randomize, hWnd, randomizeButton);
    char entSeed[] =
        "Input your own seed for the randomizer\n"
        "to use.";
    HWND seedTip = toolGen(entSeed, hWnd, seedButton);
    char jaffa[] =
        "Clear the seed which you have stored.";
    HWND jaffaTip = toolGen(jaffa, hWnd, cSeedButton);
    char revert[] =
        "Revert your randomized game back to\n"
        "the original unrandomized state.";
    HWND revTip = toolGen(revert, hWnd, revertButton);
    char eneDesc[] =
        "Randomizes the places of enemies within\n"
        "a particular area in the game.";
    HWND eneTip = toolGen(eneDesc, hWnd, enemies);  
    char cheDesc[] =
        "Randomizes the contents and item stats\n" 
        "inside a chest.";
    HWND cheTip = toolGen(cheDesc, hWnd, chests);
    char rooDesc[] =
        "Randomizes the progression of the game.\n"
        "Specific areas will take you to a new\n"
        "place entirely once you reach the end of\n"
        "them.";
    HWND rooTip = toolGen(rooDesc, hWnd, rooms);
    char dropDesc[] =
        "This will let you randomize what an\n"
        "enemy's random drop is. 100% drops\n"
        "are kept as is to prevent softlocks.";
    HWND dropTip = toolGen(dropDesc, hWnd, drops);
    char balDesc[] =
        "You can only access this once you\n"
        "decide to randomize chests.\n"
        "This will make the randomized stats of\n"
        "items more balanced and like what\n"
        "you'd expect in the original game.";
    HWND balTip = toolGen(balDesc, hWnd, balance);
    char keepDesc[] =
        "You can only access this once you\n"
        "decide to randomize chests.\n"
        "This will let you keep the\n"
        "stats of items as they\n"
        "were in the original game.\n";
        "They will be ignored when\n"
        "chests are being randomized.";
    HWND keepTip = toolGen(keepDesc, hWnd, keep);
    char consDesc[] =
        "Equipment names, types and models\n"
        "will not be consistent with one\n"
        "another.\n"
        "For example, the Arbalest could\n"
        "be a Great Sword with a Dagger\n"
        "model.";
    HWND consTip = toolGen(consDesc, hWnd, consEqu);  
    char modDesc[] =
        "Models from other locations can be\n"
        "used for enemies. For example, bats\n"
        "could use wyvern models.";
    HWND modTip = toolGen(modDesc, hWnd, eneMod);
    char statDesc[] =
        "The stats and equipment of enemies\n"
        "can be randomized.";
    HWND statTip = toolGen(statDesc, hWnd, eneStat);
    char balStatDesc[] =
        "The stats of the randomized enemies\n"
        "will be balanced according to their\n"
        "location.";
    HWND balStatTip = toolGen(balStatDesc, hWnd, balEneStat);
    char ashDesc[] =
        "Randomizes the stats of both Ashley\n"
        "and his starting equipment.";
    HWND ashTip = toolGen(ashDesc, hWnd, ashley);
    char fanDesc[] =
        "Randomizes the blade and grip\n"
        "of Ashley's starting weapon.";
    HWND fanTip = toolGen(fanDesc, hWnd, fandango);
    char balEquDesc[] =
        "Balances how Ashley's equipment\n"
        "and stats are randomized.";
    HWND balEquTip = toolGen(balEquDesc, hWnd, balAshley);
}

void ranBoxLock() {
    bool checkFound = false;
    for (int i = 4; i < butRos.size() - 6; i++) {
        LRESULT boxticked = SendMessage(butRos[i], BM_GETCHECK, NULL, NULL);
        if (boxticked == BST_CHECKED && gamePathFound) {
            checkFound = true;
            EnableWindow(randomizeButton, TRUE);
            break;
        }
    }
    if (!checkFound) {
        EnableWindow(randomizeButton, FALSE);
    }
}

void relock() {
    ranBoxLock();
    checkBoxLock();
}

void checkBoxLock() {
    bool found;
    if (gamePathFound) {
        found = true;
        for (int i = 1; i < butRos.size() - 6; i++) {
            EnableWindow(butRos[i], found);
            ranBoxLock();
        }
    }
    else {
        found = false;
        for (int i = 1; i < butRos.size(); i++) {
           LRESULT untick = SendMessage(butRos[i], BM_SETCHECK, BST_UNCHECKED, NULL);
        }
        for (int i = 1; i < butRos.size(); i++) {
            EnableWindow(butRos[i], found);
        }
    }
}

void revertCode(HWND hWnd) {
    vanBat.open("vanCmd.cmd", std::ios::trunc);
    m_file = ag.getStringPath() + "\\BACKUP\\BATTLE\\INITBTL.PRG";
    ml = rf.getChestCheck();
    mlp = ml.begin();
    vanBat << ("cd " + ag.getStringPath() + " \n");
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /BATTLE/INITBTL.PRG" + " '" + m_file + "'") << std::endl;
    m_file = ag.getStringPath() + "\\BACKUP\\TITLE\\TITLE.PRG";
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /TITLE/TITLE.PRG" + " '" + m_file + "'") << std::endl;
    for (int mi = 0; mi < ml.size(); mi++) {
        m_file = ag.getStringPath() + "\\BACKUP\\" + *mlp;
        cur_map = *mlp;
        vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
        std::advance(mlp, 1);
    }
    mlForEne = rf.getMapList();
    mlpForEne = mlForEne.begin();
    vector<string> ivm = *mlpForEne;
    vector<string>::iterator ivmp = ivm.begin();
    for (int i = 0; i < mlForEne.size(); i++) {
        for (int mi = 0; mi < rf.getIndivZone(*mlpForEne).size(); mi++) {
            m_file = ag.getStringPath() + "\\BACKUP\\" + *ivmp;
            cur_map = *ivmp;
            vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
            std::advance(ivmp, 1);
        }
        std::advance(mlpForEne, 1);
        if (i != (mlForEne.size()) - 1) {
            ivm = *mlpForEne;
            ivmp = ivm.begin();
        }
    }
    wm = rf.getWarpMaps();
    wmp = wm.begin();
    for (int i = 0; i < wm.size() - 1; i++) {
        m_file = ag.getStringPath() + "\\BACKUP\\" + *wmp;
        cur_map = *wmp;
        vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
        std::advance(wmp, 1);
    }
    ez = rf.getEneZones();
    ezp = ez.begin();
    for (int i = 0; i < ez.size() - 1; i++) {
        z_file = ag.getStringPath() + "\\BACKUP\\" + *ezp;
        cur_zone = *ezp;
        vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_zone + " '" + z_file + "'") << std::endl;
        std::advance(ezp, 1);
    }
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\\" \"" + ag.getStringPath() + "\\MAPS\\\"") << std::endl;
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\\" \"" + ag.getStringPath() + "\\ZONES\\\"") << std::endl;
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\BATTLE\\\" \"" + ag.getStringPath() + "\\MISC\\\"") << std::endl;
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\TITLE\\\" \"" + ag.getStringPath() + "\\MISC\\\"") << std::endl;
    vanBat.close();
    runChe = system("cmd.exe /c vanCmd.cmd");
    remove("vanCmd.cmd");
    if (freshPick != true) {
        MessageBox(hWnd, L"Game unrandomized!", L"Success", MB_OK);
    }
    else {
        freshPick = false;
    }
}