// VagrantStoryRandomizerGUI.cpp : Defines the entry point for the application.
//
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma warning(disable : 4996)

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
#include <openssl/md5.h>
#include <wincrypt.h>


using namespace std;


#define OPENSSL_API_COMPAT 0x10100000L

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
HWND quant;
HWND ashMisc;
HWND ashMiscQua;
HWND ashThres;
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
int runMisc;
int point;
int winWidth = 640;
int winHeight = 380;
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
bool pa_ashMisc = false;
bool pa_ashMiscQua = false;
bool pa_ashThres = false;
bool pa_fandango = false;
bool pa_quant = false;
//bool pa_cusAsh = false;
bool cusSeedU = false;
bool freshPick = false;
bool isVanilla = false;
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
string choiceQuant;
string choiceAshMisc;
string choiceAshMiscQua;
string choiceAshThres = "N";
//string choiceCusAsh;
string seedChoice;
string cusSeedS;
string strForPath;
string cur_map;
string cur_zone;
string m_file;
string z_file;
string choices;
string gameHash;
vector<string> ivm;
vector<string>::iterator ivmp;
vector<string>::iterator wmp;
vector<string>::iterator rmp;
vector<vector<string>> mlForEne;
vector<vector<string>>::iterator mlpForEne;
vector<string> ml;
vector<string> wm;
vector<string> rm;
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
TCHAR progtext[256];
TCHAR ashtext[256];
UINT cur_dpi;
UINT_PTR IDC_MENUCOMMAND1;
UINT_PTR IDC_MENUCOMMAND2;
double opBuX;
double opBuY;
double ranBuY;
double enBuX;
double enBuY;
double entBuX;
double entBuY;
double cleBuX;
double eneBuY;
double cheBuY;
double rooBuY;
double droBuX;
double cheBuX;
double areaBuX;
double ashBuX;
double zenBuX;
double droBuY;
double thresBuY;
double modBuY;
double balEneBuY;
double itStBuY;
double enStBuY;
double ashStBuY;
double balAshStBuY;
double balItQuaBuY;
double revBuX;
double zenQuiBuY;
double eneHeadX;
double cheHeadX;
double areaHeadX;
double ashHeadX;
double zenHeadX;
double musHeadX;
double eneHeadY;
double chestHeadY;
double miscHeadY;
double mul;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

string make_MD5(unsigned char* md, long size = MD5_DIGEST_LENGTH) {
    stringstream result;
    for (int i = 0; i < size; i++) {
        result << hex << setw(2) << setfill('0') << (int)md[i];
    }
    string fin = result.str();
    return fin;
}

string computeMD5FromFile(const string& filePath, HWND hWnd) {
    ifstream file(filePath, ios::in | ios::binary | ios::ate);

    if (!file.is_open()) {
        MessageBox(hWnd, L"Cannot load file", L"Error", MB_OK);
        return "null";
    }

    // Get file size
    long fileSize = file.tellg();

    // Allocate memory to hold the entire file
    char* memBlock = new char[fileSize];

    // Read the file into memory
    file.seekg(0, ios::beg);
    file.read(memBlock, fileSize);
    file.close();

    // Compute the MD5 hash of the file content
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)memBlock, fileSize, result);

    cout << "MD5 of file '" << filePath << "' : ";
    string hash = make_MD5(result);

    // Clean up
    delete[] memBlock;

    return hash;
}

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
      CW_USEDEFAULT, 0, winWidth, winHeight, nullptr, nullptr, hInstance, nullptr);
   if (!hWnd)
   {
      return FALSE;
   }
   //StartCommonControls(ICC_TAB_CLASSES);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   cur_dpi = GetDpiForWindow(hWnd);
   if (cur_dpi > 96) {
       SetWindowPos(hWnd, 0, 0, 0, winWidth * 1.25, winHeight * 1.25, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
   }
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
                            SetWindowTextA(hWnd, "Getting hash value...");
                            gameHash = computeMD5FromFile(path, hWnd);
                            SetWindowTextA(hWnd, "Vagrant Story Randomizer");
                            const char * cHash = gameHash.c_str();
                            const char * vanHash = "8531bc73ea7cd33a4c8e97bdf139ba9c";
                            if (strcmp(cHash, vanHash) == 0) {
                                isVanilla = true;
                            }
                            else {
                                isVanilla = false;
                            }
                            checkBoxLock();
                            if (!isVanilla) {
                                EnableWindow(butRos[4], TRUE);
                            }
                            else {
                                EnableWindow(butRos[4], FALSE);
                            }
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
                LRESULT quanTicked = SendMessage(quant, BM_GETCHECK, NULL, NULL);
                LRESULT ashMiscTicked = SendMessage(ashMisc, BM_GETCHECK, NULL, NULL);
                LRESULT ashMiscQuaTicked = SendMessage(ashMiscQua, BM_GETCHECK, NULL, NULL);
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
                    EnableWindow(butRos[butRos.size() - 7], true);
                    EnableWindow(butRos[butRos.size() - 3], true);
                    EnableWindow(butRos[butRos.size() - 2], true);
                    choiceChe = "Y";
                }
                else {
                    pa_chests = false;
                    EnableWindow(butRos[butRos.size() - 7], false);
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
                if (ashMiscTicked == BST_CHECKED) {
                    pa_ashMisc = true;
                    choiceAshMisc = "Y";
                    EnableWindow(butRos[butRos.size() - 8], true);
                }
                else {
                    pa_ashMisc = false;
                    choiceAshMisc = "N";
                    EnableWindow(butRos[butRos.size() - 8], false);
                }
                if (ashMiscQuaTicked == BST_CHECKED && ashMiscTicked == BST_CHECKED) {
                    choiceAshMiscQua = "Y";
                }
                else {
                    choiceAshMiscQua = "N";
                }
                if (balAshticked == BST_CHECKED) {
                    pa_balAshley = true;
                    choiceBalAsh = "Y";
                    EnableWindow(butRos[butRos.size() - 9], true);
                }
                else {
                    pa_balAshley = false;
                    choiceBalAsh = "N";
                    EnableWindow(butRos[butRos.size() - 9], false);
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
                if (quanTicked == BST_CHECKED) {
                    pa_quant = true;
                    choiceQuant = "Y";
                }
                else {
                    pa_quant = false;
                    choiceQuant = "N";
                }
                if (blcticked == BST_CHECKED && cheticked == BST_CHECKED) {
                    choiceB = "Y";
                }
                else {
                    choiceB = "N";
                }
                if (keeticked == BST_CHECKED && cheticked == BST_CHECKED) {
                    choiceK = "Y";
                    EnableWindow(butRos[butRos.size() - 4], true);
                }
                else {
                    choiceK = "N";
                    EnableWindow(butRos[butRos.size() - 4], false);
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
                choices = "." + choiceAshThres + choiceAshMiscQua + choiceAshMisc + choiceQuant + choiceFan + choiceBalAsh + choiceAsh + choiceBe + choiceSt + choiceM + choiceE + choiceChe + choiceA + choiceD + choiceB + choiceK + choiceC;
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
                if (seedChoice == "Y") {
                    MessageBox(hWnd, L"Seed saved to 'seed.txt'.", L"Seed Saved", MB_OK);
                }
                if (!isVanilla) {
                    vanBoxID = MessageBox(hWnd, L"Would you like to revert your game to the vanilla version?", L"Use vanilla version?", MB_YESNO);
                    switch (vanBoxID)
                    {
                    case IDYES:
                        freshPick = true;
                        revertCode(hWnd);
                        break;
                    case IDNO:
                        break;
                    }
                }
                if (cusSeedU == true) {
                    ag.makeGenPlus(seedChoice, cusSeedI, choices);
                }
                else {
                    ag.makeGen(seedChoice, choices);
                }
                finGen = ag.getGen();
                if (pa_ashley) {
                    changed = true;
                    remove("ashCmd.cmd");
                    Ashley ash_maker = Ashley();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Ashley...");
                    ash_maker.statIterate(rf, ag, finGen, choiceBalAsh, choiceFan, choiceAshThres);
                    runAsh = system("cmd.exe /c ashCmd.cmd");
                    remove("ashCmd.cmd");
                    SetWindowTextA(hWnd, "Ashley Randomized");
                }
                if (pa_ashMisc) {
                    changed = true;
                    remove("miscCmd.cmd");
                    Ashley ash_scrambler = Ashley();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Ashley's Items...");
                    ash_scrambler.miscIterate(rf, ag, choiceAshMiscQua, finGen);
                    runMisc = system("cmd.exe /c miscCmd.cmd");
                    remove("miscCmd.cmd");
                    SetWindowTextA(hWnd, "Ashley's Items Randomized");
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
                    che_ran.mapIterate(rf, ag, finGen, choiceB, choiceK, choiceC, choiceQuant);
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
                    isVanilla = false;
                    EnableWindow(butRos[4], TRUE);
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
                            seedFile.seekg(-19, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point != 78) {
                                if (point == 76) {
                                    choiceAshThres = "L";
                                    SetWindowText(ashThres, L"75 - 125");
                                }
                                else if (point == 77) {
                                    choiceAshThres = "M";
                                    SetWindowText(ashThres, L"50 - 150");
                                }
                                else if (point == 72) {
                                    choiceAshThres = "H";
                                    SetWindowText(ashThres, L"25 - 175");
                                }
                                LRESULT tickebalash = SendMessage(balAshley, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickeash = SendMessage(ashley, BM_SETCHECK, BST_CHECKED, 0);
                                pa_balAshley = true;
                                choiceBalAsh = "Y";
                                pa_ashley = true;
                                choiceAsh = "Y";
                            }
                            else {
                                choiceAshThres = "N";
                                SetWindowText(ashThres, L"None");
                            }
                            seedFile.seekg(-18, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickMisc = SendMessage(ashMisc, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickMiscQua = SendMessage(ashMiscQua, BM_SETCHECK, BST_CHECKED, 0);
                                pa_ashMisc = true;
                                choiceAshMisc = "Y";
                                pa_ashMiscQua = true;
                                choiceAshMiscQua = "Y";
                            }
                            else {
                                pa_ashMiscQua = false;
                                choiceAshMiscQua = "N";
                            }
                            seedFile.seekg(-17, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickMisc = SendMessage(ashMisc, BM_SETCHECK, BST_CHECKED, 0);
                                pa_ashMisc = true;
                                choiceAshMisc = "Y";
                                EnableWindow(butRos[butRos.size() - 8], true);
                            }
                            else {
                                pa_ashMisc = false;
                                choiceAshMisc = "N";
                                EnableWindow(butRos[butRos.size() - 8], false);
                            }
                            seedFile.seekg(-16, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickquant = SendMessage(quant, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickche = SendMessage(chests, BM_SETCHECK, BST_CHECKED, 0);
                                pa_chests = true;
                                choiceChe = "Y";
                                pa_quant = true;
                                choiceQuant = "Y";
                            }
                            else {
                                pa_quant = false;
                                choiceQuant = "N";
                            }
                            seedFile.seekg(-15, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickefandango = SendMessage(fandango, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickeash = SendMessage(ashley, BM_SETCHECK, BST_CHECKED, 0);
                                pa_fandango = true;
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
                                EnableWindow(butRos[butRos.size() - 9], true);
                            }
                            else {
                                pa_balAshley = false;
                                choiceBalAsh = "N";
                                EnableWindow(butRos[butRos.size() - 9], false);
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
                                EnableWindow(butRos[butRos.size() - 1], false);
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
                                EnableWindow(butRos[butRos.size() - 7], true);
                                EnableWindow(butRos[butRos.size() - 3], true);
                                EnableWindow(butRos[butRos.size() - 2], true);
                                choiceChe = "Y";
                            }
                            else {
                                pa_chests = false;
                                EnableWindow(butRos[butRos.size() - 7], false);
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
                                EnableWindow(butRos[butRos.size() - 7], true);
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
                                EnableWindow(butRos[butRos.size() - 7], true);
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
                                EnableWindow(butRos[butRos.size() - 7], true);
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
            case IDM_DROPDOWN:
            {
                MessageBox(hWnd, L"Select a threshold by clicking on the arrow to the right.", L"Choose a threshold", MB_OK);
            }
            break;
            case IDM_THRES1:
            {
                SetWindowText(ashThres, L"Default");
                choiceAshThres = "N";
            }
            break;
            case IDM_THRES2:
            {
                SetWindowText(ashThres, L"75 - 125");
                choiceAshThres = "L";
            }
            break;
            case IDM_THRES3:
            {
                SetWindowText(ashThres, L"50 - 150");
                choiceAshThres = "M";
            }
            break;
            case IDM_THRES4:
            {
                SetWindowText(ashThres, L"25 - 175");
                choiceAshThres = "H";
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
	case WM_NOTIFY:
        switch (((LPNMHDR)lParam)->code)
        {
        case BCN_DROPDOWN:
            NMBCDROPDOWN* pDropDown = (NMBCDROPDOWN*)lParam;
            if (pDropDown->hdr.hwndFrom == GetDlgItem(hWnd, 9007))
            {
                POINT pt;
                pt.x = pDropDown->rcButton.left;
                pt.y = pDropDown->rcButton.bottom;
                ClientToScreen(pDropDown->hdr.hwndFrom, &pt);

                HMENU hSplitMenu = CreatePopupMenu();
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_THRES1, L"None");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_THRES2, L"75 - 125");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_THRES3, L"50 - 150");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_THRES4, L"25 - 175");

                TrackPopupMenu(hSplitMenu, TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, 0, hWnd, NULL);
                //return TRUE;
            }
            break;
        }
        //return FALSE;
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
            swprintf_s(progtext, 256, L"Progression data:");
            swprintf_s(ashtext, 256, L"Ashley data:");
            eneHeadX = 0.0325 * mul;
            cheHeadX = 0.2725 * mul;
            areaHeadX = 0.5125 * mul;
            ashHeadX = 0.7525 * mul;
            eneHeadY = 0.15 * mul;
            //chestHeadY = 0.39 * mul;
            //miscHeadY = 0.63 * mul;
            TextOut(hdc, xCor * eneHeadX, yCor * eneHeadY, enetext, wcslen(enetext));
            TextOut(hdc, xCor * cheHeadX, yCor * eneHeadY, chetext, wcslen(chetext));
            TextOut(hdc, xCor * areaHeadX, yCor * eneHeadY, progtext, wcslen(progtext));
            TextOut(hdc, xCor * ashHeadX, yCor * eneHeadY, ashtext, wcslen(ashtext));
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
    butRos.emplace_back(ashMisc);
    butRos.emplace_back(ashThres);
    butRos.emplace_back(ashMiscQua);
    butRos.emplace_back(quant);
    butRos.emplace_back(balAshley);
    butRos.emplace_back(fandango);
    //butRos.emplace_back(cusAsh);
    butRos.emplace_back(balance);
    butRos.emplace_back(keep);
    butRos.emplace_back(consEqu);
    butRos.emplace_back(balEneStat);
}

void makeButtons(HWND hWnd) {
    cur_dpi = GetDpiForWindow(hWnd);
    if (cur_dpi > 96) {
        mul = 1.25;
    }
    else {
        mul = 1.00;
    }
    opBuX = 0.4 * mul;
    opBuY = 0.05 * mul;
    ranBuY = 0.7895 * mul;
    enBuX = 0.0325 * mul;
    enBuY = 0.20 * mul;
    entBuY = 0.6885 * mul;
    cleBuX = 0.1825 * mul;
    cheBuY = 0.44 * mul;
    balEneBuY = 0.43 * mul;
    rooBuY = 0.6725 * mul;
    cheBuX = 0.270 * mul;
    areaBuX = 0.5075 * mul;
    ashBuX = 0.745 * mul;
    zenBuX = 0.9825 * mul;
    droBuX = 0.275 * mul;
    droBuY = 0.315 * mul; 
    thresBuY = 0.320 * mul; 
    modBuY = 0.2575 * mul;
    itStBuY = 0.4975 * mul;
    enStBuY = 0.3725 * mul;
    ashStBuY = 0.73 * mul;
    balAshStBuY = 0.7875 * mul;
    balItQuaBuY = 0.5550 * mul;
    entBuX = 0.2325 * mul;
    revBuX = 0.5675 * mul;
    zenQuiBuY = 0.4875 * mul;

    openGame = CreateWindow(L"BUTTON", L"Open Game", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * opBuX), (int)(yCor * opBuY), 90 * mul, 25, hWnd, (HMENU)101, hInst, NULL);
    randomizeButton = CreateWindow(L"BUTTON", L"Randomize", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * opBuX), (int)(yCor * ranBuY), 90 * mul, 25, hWnd, (HMENU)9003, hInst, NULL);
    seedButton = CreateWindow(L"BUTTON", L"Enter Seed", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * entBuX), (int)(yCor * entBuY), 90 * mul, 25, hWnd, (HMENU)9004, hInst, NULL);
    cSeedButton = CreateWindow(L"BUTTON", L"Clear Seed", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * opBuX), (int)(yCor * entBuY), 90 * mul, 25, hWnd, (HMENU)9005, hInst, NULL);
    revertButton = CreateWindow(L"BUTTON", L"Revert to Vanilla", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * revBuX), (int)(yCor * entBuY), 90 * mul, 25, hWnd, (HMENU)9006, hInst, NULL);
    enemies = CreateWindow(L"BUTTON", L"Enemies", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * enBuY), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    chests = CreateWindow(L"BUTTON", L"Chests", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * enBuY), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    rooms = CreateWindow(L"BUTTON", L"Area Progression", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * areaBuX), (int)(yCor * enBuY), 130, 25, hWnd, (HMENU)9002, hInst, NULL);
    drops = CreateWindow(L"BUTTON", L"Drops", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * droBuY), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    balance = CreateWindow(L"BUTTON", L"Balance Item Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * droBuY), 150, 25, hWnd, (HMENU)9002, hInst, NULL);
    keep = CreateWindow(L"BUTTON", L"Item Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * modBuY), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    consEqu = CreateWindow(L"BUTTON", L"Inconsistent Gear", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * balEneBuY), 150, 25, hWnd, (HMENU)9002, hInst, NULL);
    eneMod = CreateWindow(L"BUTTON", L"Enemy Models (Unstable)", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * modBuY), 140, 25, hWnd, (HMENU)9002, hInst, NULL);
    eneStat = CreateWindow(L"BUTTON", L"Enemy Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * enStBuY), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    balEneStat = CreateWindow(L"BUTTON", L"Balance Enemy Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * balEneBuY), 150, 25, hWnd, (HMENU)9002, hInst, NULL);
    ashley = CreateWindow(L"BUTTON", L"Ashley's Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * enBuY), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    balAshley = CreateWindow(L"BUTTON", L"Balance Ashley's Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * modBuY), 150, 25, hWnd, (HMENU)9002, hInst, NULL);
    fandango = CreateWindow(L"BUTTON", L"Fandango Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * enStBuY), 150, 25, hWnd, (HMENU)9002, hInst, NULL);
    quant = CreateWindow(L"BUTTON", L"Balance Item Quantities", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * enStBuY), 180, 25, hWnd, (HMENU)9002, hInst, NULL);
    ashMisc = CreateWindow(L"BUTTON", L"Ashley's Misc Items", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * balEneBuY), 150, 25, hWnd, (HMENU)9002, hInst, NULL);
    ashMiscQua = CreateWindow(L"BUTTON", L"Misc Item Quantities", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * zenQuiBuY), 150, 25, hWnd, (HMENU)9002, hInst, NULL);
    ashThres = CreateWindow(L"BUTTON", L"Ashley Stat Threshold", WS_CHILD | WS_VISIBLE | BS_SPLITBUTTON, (int)(xCor * ashBuX), (int)(yCor * thresBuY), 135, 20, hWnd, (HMENU)9007, hInst, NULL);
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
        "Randomizes the contents inside a chest.\n";
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
        "This will make the randomized stats\n"
        "more balanced and like what you'd expect\n"
        "in the original game.\n"
        "Blades, grips and gems will be balanced\n"
        "by where you are in the game.";
    HWND balTip = toolGen(balDesc, hWnd, balance);
    char quanDesc[] =
        "You can only access this once you\n"
        "decide to randomize chests.\n"
        "This will make the randomized quantities\n"
        "of items more balanced and like what you'd\n"
        "expect in the original game.";
    HWND quanTip = toolGen(quanDesc, hWnd, quant);
    char keepDesc[] =
        "You can only access this once you\n"
        "decide to randomize chests.\n"
        "This will let you randomize the\n"
        "stats of items such as equipment\n"
        "and gems from chests.";
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
        "could use wyvern models. This option is\n"
        "highly unstable and difficult to properly\n"
        "ACID test. Use this at risk.";
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
    char ashMiscTipDesc[] =
        "Randomize the starting misc items\n"
        "which Ashley has. Keys, Grimoires, and\n"
        "Sigils will have a quantity of 1.";
    HWND ashMiscTip = toolGen(ashMiscTipDesc, hWnd, ashMisc);
    char ashMiscQuaTipDesc[] =
        "Randomize the quantites of the\n"
        "starting items which Ashley will\n"
        "get. Though Grimoires, Keys, and\n"
        "Sigils will still have quantities of 1.";
    HWND ashMiscQuaTip = toolGen(ashMiscQuaTipDesc, hWnd, ashMiscQua);
    char ashThresTipDesc[] =
        "Choose the minimum and maximum values\n"
        "Ashley's STR, INT and AGL can be.";
    HWND ashThresTip = toolGen(ashThresTipDesc, hWnd, ashThres);
}

void ranBoxLock() {
    bool checkFound = false;
    for (int i = 5; i < butRos.size() - 9; i++) {
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
        for (int i = 1; i < butRos.size() - 9; i++) {
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
    m_file = ag.getStringPath() + "\\BACKUP\\BATTLE\\BATTLE.PRG";
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /BATTLE/BATTLE.PRG" + " '" + m_file + "'") << std::endl;
    //m_file = ag.getStringPath() + "\\BACKUP\\MAP000.MPD";
    //vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/MAP000.MPD" + " '" + m_file + "'") << std::endl;
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
    for (int i = 0; i < wm.size(); i++) {
        m_file = ag.getStringPath() + "\\BACKUP\\" + *wmp;
        cur_map = *wmp;
        vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
        std::advance(wmp, 1);
    }
    rm = rf.getRetWarpMaps();
    rmp = rm.begin();
    for (int i = 0; i < rm.size(); i++) {
        m_file = ag.getStringPath() + "\\BACKUP\\" + *rmp;
        cur_map = *rmp;
        vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
        std::advance(rmp, 1);
    }
    ez = rf.getEneZones();
    ezp = ez.begin();
    for (int i = 0; i < ez.size(); i++) {
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
        isVanilla = true;
        EnableWindow(butRos[4], FALSE);
        MessageBox(hWnd, L"Game unrandomized!", L"Success", MB_OK);
    }
    else {
        freshPick = false;
    }
}

