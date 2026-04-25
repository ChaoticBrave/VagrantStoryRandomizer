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
#include "Zenith.h"
#include "Music.h"
#include <chrono>
#include <commctrl.h>
#include <openssl/md5.h>
#include <wincrypt.h>
#include <algorithm>
#include <thread>

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
HWND maiden;
HWND openW;
HWND breakA;
HWND balBreak;
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
HWND zenTel;
HWND zenAnal;
HWND zenMan;
HWND zenDrop;
HWND zenBoss;
HWND zenQui;
HWND ashBuild;
HWND areaMusic;
HWND cutRes;
HWND bossMusic;
//HWND cusAsh;
HWND randomizeButton;
HWND revertButton;
HWND seedButton;
HWND cSeedButton;
HWND window;
HWND prog;
HWND progCont;
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
int runRev;
int runRoo;
int runMaid;
int runOpen;
int runBreak;
int runAsh;
int runMisc;
int runZen;
int runMus;
int point;
int winWidth = 920;
int winHeight = 450;
int g_liz;
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
bool pa_maid = false;
bool pa_open = false;
bool pa_break = false;
bool pa_balBreak = false;
bool pa_areaMus = false;
bool pa_cutRes = false;
bool pa_bossMus = false;
bool pa_drops = false;
bool pa_balance = false;
bool pa_keep = false;
bool pa_cons = false;
bool pa_ashley = false;
bool pa_balAshley = false;
bool pa_zenTel = false;
bool pa_zenAnal = false;
bool pa_zenMan = false;
bool pa_zenDrop = false;
bool pa_zenBoss = false;
bool pa_zenQui = false;
bool pa_ashMisc = false;
bool pa_ashMiscQua = false;
bool pa_fandango = false;
bool pa_quant = false;
bool is_lizard = false;
//bool pa_cusAsh = false;
bool cusSeedU = false;
bool freshPick = false;
bool isVanilla = false;
string choiceD = "N";
string choiceE = "N";
string choiceM = "N";
string choiceSt = "N";
string choiceB = "N";
string choiceBe = "N";
string choiceK = "N";
string choiceC = "N";
string choiceChe = "N";
string choiceA = "N";
string choiceMM = "N";
string choiceO = "N";
string choiceBr = "N";
string choiceBalBr = "N";
string choiceAsh = "N";
string choiceBalAsh = "N";
string choiceFan = "N";
string choiceQuant = "N";
string choiceZenTel = "N";
string choiceZenAnal = "N";
string choiceZenMan = "N";
string choiceZenDrop = "N";
string choiceZenBoss = "N";
string choiceZenQui = "N";
string choiceAshMisc = "N";
string choiceAshMiscQua = "N";
string choiceAshThres = "N";
string choiceAshBuild = "V";
string choiceAreaMus = "N";
string choiceCutRes = "N";
string choiceBossMus = "N";
string path;
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
vector<string> m;
vector<string> wm;
vector<string> rm;
list<string> ez;
list<string> pz;
list<string>::iterator ezp;
list<string>::iterator pzp;
vector<string>::iterator mlp;
vector<string>::iterator mp;
fstream game;
fstream seedFile;
Reference_Files rf = Reference_Files();
RECT rcWindow;
std::mt19937 gen;
std::mt19937 finGen;
std::ofstream vanBat;
std::ofstream revBat;
TOOLINFO paraInfo;
TCHAR enetext[256];
TCHAR chetext[256];
TCHAR progtext[256];
TCHAR ashtext[256];
TCHAR zentext[256];
TCHAR mustext[256];
double cur_dpi;
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
double buildBuY;
double breakBuY;
double balBrBuY;
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
double areaMusBuX;
double eneHeadY;
double chestHeadY;
double miscHeadY;
double progBaX;
double progBaY;
double mul;
streampos liz_loc;

char* ch_val;

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
       SetWindowPos(hWnd, 0, 0, 0, winWidth * (cur_dpi / 96), winHeight * (cur_dpi / 96), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
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
                    path = opfi.lpstrFile;
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
                                game.open(path, ios::in | ios::out | ios::binary | ios::ate);
                                game.seekg(3478738, ios::beg);
                                liz_loc = game.tellg();
                                g_liz = game.get();
                                if (g_liz == 164) {
                                    is_lizard = true;
                                }
                                game.close();
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
                LRESULT maidticked = SendMessage(maiden, BM_GETCHECK, NULL, NULL);
                LRESULT openticked = SendMessage(openW, BM_GETCHECK, NULL, NULL);
                LRESULT brticked = SendMessage(breakA, BM_GETCHECK, NULL, NULL);
                LRESULT balBrticked = SendMessage(balBreak, BM_GETCHECK, NULL, NULL);
                LRESULT areaMusticked = SendMessage(areaMusic, BM_GETCHECK, NULL, NULL);
                LRESULT cutResticked = SendMessage(cutRes, BM_GETCHECK, NULL, NULL);
                LRESULT bossMusticked = SendMessage(bossMusic, BM_GETCHECK, NULL, NULL);
                LRESULT ashticked = SendMessage(ashley, BM_GETCHECK, NULL, NULL);
                LRESULT balAshticked = SendMessage(balAshley, BM_GETCHECK, NULL, NULL);
                LRESULT fanTicked = SendMessage(fandango, BM_GETCHECK, NULL, NULL);
                LRESULT quanTicked = SendMessage(quant, BM_GETCHECK, NULL, NULL);
                LRESULT zenTelTicked = SendMessage(zenTel, BM_GETCHECK, NULL, NULL);
                LRESULT zenAnalTicked = SendMessage(zenAnal, BM_GETCHECK, NULL, NULL);
                LRESULT zenManTicked = SendMessage(zenMan, BM_GETCHECK, NULL, NULL);
                LRESULT zenDropTicked = SendMessage(zenDrop, BM_GETCHECK, NULL, NULL);
                LRESULT zenBossTicked = SendMessage(zenBoss, BM_GETCHECK, NULL, NULL);
                LRESULT zenQuiTicked = SendMessage(zenQui, BM_GETCHECK, NULL, NULL);
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
                if (maidticked == BST_CHECKED) {
                    pa_maid = true;
                    choiceMM = "Y";
                }
                else {
                    pa_maid = false;
                    choiceMM = "N";
                }
                if (openticked == BST_CHECKED) {
                    pa_open = true;
                    choiceO = "Y";
                }
                else {
                    pa_open = false;
                    choiceO = "N";
                }
                if (brticked == BST_CHECKED) {
                    pa_break = true;
                    choiceBr = "Y";
                    EnableWindow(butRos[butRos.size() - 10], true);
                }
                else {
                    pa_break = false;
                    choiceBr = "N";
                    EnableWindow(butRos[butRos.size() - 10], false);
                }
                if (balBrticked == BST_CHECKED) {
                    pa_balBreak = true;
                    choiceBalBr = "Y";
                }
                else {
                    pa_balBreak = false;
                    choiceBalBr = "N";
                }
                if (areaMusticked == BST_CHECKED) {
                    pa_areaMus = true;
                    choiceAreaMus = "Y";
                }
                else {
                    pa_areaMus = false;
                    choiceAreaMus = "N";
                }
                if (bossMusticked == BST_CHECKED) {
                    pa_bossMus = true;
                    choiceBossMus = "Y";
                }
                else {
                    pa_bossMus = false;
                    choiceBossMus = "N";
                }
                if (cutResticked == BST_CHECKED) {
                    pa_cutRes = true;
                    choiceCutRes = "Y";
                }
                else {
                    pa_cutRes = false;
                    choiceCutRes = "N";
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
                if (zenTelTicked == BST_CHECKED) {
                    pa_zenTel = true;
                    choiceZenTel = "Y";
                }
                else {
                    pa_zenTel = false;
                    choiceZenTel = "N";
                }
                if (zenAnalTicked == BST_CHECKED) {
                    pa_zenAnal = true;
                    choiceZenAnal = "Y";
                }
                else {
                    pa_zenAnal = false;
                    choiceZenAnal = "N";
                }
                if (zenManTicked == BST_CHECKED) {
                    pa_zenMan = true;
                    choiceZenMan = "Y";
                }
                else {
                    pa_zenMan = false;
                    choiceZenMan = "N";
                }
                if (zenDropTicked == BST_CHECKED) {
                    pa_zenDrop = true;
                    choiceZenDrop = "Y";
                }
                else {
                    pa_zenDrop = false;
                    choiceZenDrop = "N";
                }
                if (zenBossTicked == BST_CHECKED) {
                    pa_zenBoss = true;
                    choiceZenBoss = "Y";
                }
                else {
                    pa_zenBoss = false;
                    choiceZenBoss = "N";
                }
                if (zenQuiTicked == BST_CHECKED) {
                    pa_zenQui = true;
                    choiceZenQui = "Y";
                }
                else {
                    pa_zenQui = false;
                    choiceZenQui = "N";
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
                choices = "." + choiceBossMus + choiceCutRes + choiceAreaMus + choiceBalBr + choiceBr + choiceO + choiceMM + choiceAshBuild + choiceAshThres + choiceAshMiscQua + choiceAshMisc + choiceZenQui + choiceZenBoss + choiceZenDrop + choiceZenMan + choiceZenAnal + choiceZenTel + choiceQuant + choiceFan + choiceBalAsh + choiceAsh + choiceBe + choiceSt + choiceM + choiceE + choiceChe + choiceA + choiceD + choiceB + choiceK + choiceC;
                int count = 0;
                for (int i = 0; i < choices.length(); i++) {
                    if (choices[i] != 'N' && choices[i] != 'V') {
                        count++;
                    }
                }
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
                prog = CreateWindowExW(0, PROGRESS_CLASSW, (LPTSTR)NULL, WS_CHILD | WS_VISIBLE, xCor * entBuX, yCor * progBaY, 305 * mul, 25 * mul, hWnd, (HMENU)0, hInst, NULL);
                SendMessage(prog, PBM_SETRANGE, 0, MAKELPARAM(0, (count)));
                SendMessage(prog, PBM_SETSTEP, (WPARAM)1, 0);
                if (cusSeedU == true) {
                    ag.makeGenPlus(seedChoice, cusSeedI, choices);
                }
                else {
                    ag.makeGen(seedChoice, choices);
                }
                finGen = ag.getGen();
                if (pa_areaMus || pa_cutRes || pa_bossMus) {
                    changed = true;
                    Music mus_rando = Music();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    if (pa_cutRes) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("lizCmd.cmd");
                        remove("cutMuCmd.cmd");
                        SetWindowTextA(hWnd, "Restoring cut tracks...");
                        mus_rando.musicRes(rf, ag);
                        runMus = system("cmd.exe start /min /c lizCmd.cmd");
                        runMus = system("cmd.exe start /min /c cutMuCmd.cmd");
                        remove("lizCmd.cmd");
                        remove("cutMuCmd.cmd");
                        SetWindowTextA(hWnd, "Cut music restored");
                        is_lizard = true;
                    }
                    if (pa_areaMus) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("arMuCmd.cmd");
                        SetWindowTextA(hWnd, "Randomizing area music...");
                        mus_rando.areaMusic(rf, ag, finGen);
                        runMus = system("cmd.exe start /min /c arMuCmd.cmd");
                        remove("arMuCmd.cmd");
                        SetWindowTextA(hWnd, "Area music randomized");
                    }
                    if (pa_bossMus) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("boMuCmd.cmd");
                        SetWindowTextA(hWnd, "Randomizing boss music...");
                        mus_rando.bossMusic(rf, ag, finGen, path, is_lizard);
                        runMus = system("cmd.exe start /min /c boMuCmd.cmd");
                        remove("boMuCmd.cmd");
                        SetWindowTextA(hWnd, "Boss music randomized");
                    }
                }
                if (pa_zenTel || pa_zenAnal || pa_zenMan || pa_zenDrop || pa_zenBoss || pa_zenQui) {
                    changed = true;
                    Zenith zen_maker = Zenith();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Zenith feature(s)...");
                    if (pa_zenDrop) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("dropCmd.cmd");
                        zen_maker.newDrops(ag, rf);
                        runZen = system("cmd.exe start /min /c dropCmd.cmd");
                        remove("dropCmd.cmd");
                    }
                    if (pa_zenTel) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("teleCmd.cmd");
                        zen_maker.freeTeleport(ag, rf);
                        runZen = system("cmd.exe start /min /c teleCmd.cmd");
                        remove("teleCmd.cmd");
                    }
                    if (pa_zenAnal) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("analCmd.cmd");
                        zen_maker.perfectAnalyze(ag, rf);
                        runZen = system("cmd.exe start /min /c analCmd.cmd");
                        remove("analCmd.cmd");
                    }
                    if (pa_zenMan) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("manaCmd.cmd");
                        zen_maker.friendlyManabreaker(ag, rf);
                        runZen = system("cmd.exe start /min /c manaCmd.cmd");
                        remove("manaCmd.cmd");
                    }
                    if (pa_zenBoss) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("bossCmd.cmd");
                        zen_maker.bossDrops(ag, rf);
                        runZen = system("cmd.exe start /min /c bossCmd.cmd");
                        remove("bossCmd.cmd");
                    }
                    if (pa_zenQui) {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                        remove("quietCmd.cmd");
                        zen_maker.quietEnemies(ag, rf);
                        runZen = system("cmd.exe start /min /c quietCmd.cmd");
                        remove("quietCmd.cmd");
                    }
                    SetWindowTextA(hWnd, "Zenith feature(s) added");
                }
                if (pa_ashley) {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    if (choiceBalAsh == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceFan == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceAshThres != "N") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    changed = true;
                    remove("ashCmd.cmd");
                    Ashley ash_maker = Ashley();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Ashley...");
                    ash_maker.statIterate(rf, ag, finGen, choiceBalAsh, choiceFan, choiceAshThres);
                    runAsh = system("cmd.exe start /min /c ashCmd.cmd");
                    remove("ashCmd.cmd");
                    SetWindowTextA(hWnd, "Ashley Randomized");
                }
                if (pa_ashMisc) {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    if (choiceAshMiscQua == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    changed = true;
                    remove("miscCmd.cmd");
                    Ashley ash_scrambler = Ashley();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Ashley's items...");
                    ash_scrambler.miscIterate(rf, ag, choiceAshMiscQua, finGen);
                    runMisc = system("cmd.exe start /min /c miscCmd.cmd");
                    remove("miscCmd.cmd");
                    SetWindowTextA(hWnd, "Ashley's items randomized");
                }
                if (pa_rooms) {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    changed = true;
                    remove("rooCmd.cmd");
                    Rooms roo_ran = Rooms();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing rooms...");
                    roo_ran.roomIterate(rf, ag, finGen);
                    runRoo = system("cmd.exe start /min /c rooCmd.cmd");
                    remove("rooCmd.cmd");
                    SetWindowTextA(hWnd, "Rooms randomized");
                }
                if (pa_maid) {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    changed = true;
                    remove("maidCmd.cmd");
                    Rooms mandy = Rooms();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Making Iron Maiden mandatory...");
                    mandy.mandyMaiden(rf, ag);
                    runMaid = system("cmd.exe start /min /c maidCmd.cmd");
                    remove("maidCmd.cmd");
                    SetWindowTextA(hWnd, "Iron Maiden is now mandatory");
                }
                if (pa_open) {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    changed = true;
                    remove("worCmd.cmd");
                    Rooms allKeys = Rooms();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Making the game open world...");
                    allKeys.openWorld(rf, ag);
                    runOpen = system("cmd.exe start /min /c worCmd.cmd");
                    remove("worCmd.cmd");
                    SetWindowTextA(hWnd, "Vagrant Story is now open world!");
                }
                if (pa_break) {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    if (choiceBalAsh == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    changed = true;
                    remove("breakCmd.cmd");
                    Ashley breakArtCosts = Ashley();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Break Art costs...");
                    breakArtCosts.breakArts(rf, ag, choiceBalBr, finGen);
                    runBreak = system("cmd.exe start /min /c breakCmd.cmd");
                    remove("breakCmd.cmd");
                    SetWindowTextA(hWnd, "Break Art costs randomized");
                }
                if (pa_chests) {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    if (choiceB == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceK == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceC == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceQuant == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    changed = true;
                    remove("cheCmd.cmd");
                    Chests che_ran = Chests();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing chests...");
                    che_ran.mapIterate(rf, ag, finGen, choiceB, choiceK, choiceC, choiceQuant, is_lizard);
                    runChe = system("cmd.exe start /min /c cheCmd.cmd");
                    remove("cheCmd.cmd");
                    SetWindowTextA(hWnd, "Chests randomized");
                }
                if (pa_enemies || pa_models || pa_stats || pa_drops) {
                    if (choiceD == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceM == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceE == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceSt == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    if (choiceBe == "Y") {
                        SendMessage(prog, PBM_STEPIT, 0, 0);
                    }
                    changed = true;
                    remove("eneCmd.cmd");
                    Enemies ene_ran = Enemies();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing enemies...");
                    ene_ran.mapIterate(rf, ag, choiceD, finGen, choiceM, choiceE, choiceSt, choiceBe, is_lizard);
                    runEne = system("cmd.exe start /min /c eneCmd.cmd");
                    remove("eneCmd.cmd");
                    SetWindowTextA(hWnd, "Enemies randomized");
                }
                if (choiceAshBuild != "V") {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    changed = true;
                    remove("buildCmd.cmd");
                    Ashley ash_scrambler = Ashley();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    SetWindowTextA(hWnd, "Randomizing Ashley's build...");
                    ash_scrambler.buildIterate(rf, ag, choiceAshBuild, finGen);
                    runMisc = system("cmd.exe start /min /c buildCmd.cmd");
                    remove("buildCmd.cmd");
                    SetWindowTextA(hWnd, "Ashley's build randomized");
                }
                if (changed == true) {
                    SendMessage(prog, PBM_STEPIT, 0, 0);
                    SetWindowTextA(hWnd, "Cleaning up");
                    vanBat.open("vanCmd.cmd", std::ios::trunc);
                    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\\" \"" + ag.getStringPath() + "\\MAPS\\\"") << std::endl;
                    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\\" \"" + ag.getStringPath() + "\\ZONES\\\"") << std::endl;
                    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\BATTLE\\\" \"" + ag.getStringPath() + "\\MISC\\\"") << std::endl;
                    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\TITLE\\\" \"" + ag.getStringPath() + "\\MISC\\\"") << std::endl;
                    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\PATCHED\\\" \"" + ag.getStringPath() + "\\MAPS\\PATCHED\\\"") << std::endl;
                    vanBat.close();
                    runRev = system("cmd.exe /c vanCmd.cmd");
                    remove("vanCmd.cmd");
                    SetWindowTextA(hWnd, "Vagrant Story Randomizer");
                    MessageBox(hWnd, L"Randomization completed!", L"Success", MB_OK);
                    DestroyWindow(prog);
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
                            seedFile.seekg(-33, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickbossmus = SendMessage(bossMusic, BM_SETCHECK, BST_CHECKED, 0);
                                pa_bossMus = true;
                                choiceBossMus = "Y";
                            }
                            else {
                                pa_bossMus = false;
                                choiceBossMus = "N";
                            }
                            seedFile.seekg(-32, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickcutres = SendMessage(cutRes, BM_SETCHECK, BST_CHECKED, 0);
                                pa_cutRes = true;
                                choiceCutRes = "Y";
                            }
                            else {
                                pa_cutRes = false;
                                choiceCutRes = "N";
                            }
                            seedFile.seekg(-31, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickareamusic = SendMessage(areaMusic, BM_SETCHECK, BST_CHECKED, 0);
                                pa_areaMus = true;
                                choiceAreaMus = "Y";
                            }
                            else {
                                pa_areaMus = false;
                                choiceAreaMus = "N";
                            }
                            seedFile.seekg(-30, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickbalbreak = SendMessage(balBreak, BM_SETCHECK, BST_CHECKED, 0);
                                LRESULT tickbreak = SendMessage(breakA, BM_SETCHECK, BST_CHECKED, 0);
                                pa_balBreak = true;
                                choiceBalBr = "Y";
                                pa_break = true;
                                choiceBr = "Y";
                            }
                            else {
                                pa_balBreak = false;
                                choiceBalBr = "N";
                            }
                            seedFile.seekg(-29, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickbreak = SendMessage(breakA, BM_SETCHECK, BST_CHECKED, 0);
                                pa_break = true;
                                choiceBr = "Y";
                                EnableWindow(butRos[butRos.size() - 10], true);
                            }
                            else {
                                pa_break = false;
                                choiceBr = "N";
                                EnableWindow(butRos[butRos.size() - 10], false);
                            }
                            seedFile.seekg(-28, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickopen = SendMessage(openW, BM_SETCHECK, BST_CHECKED, 0);
                                pa_open = true;
                                choiceO = "Y";
                            }
                            else {
                                pa_open = false;
                                choiceO = "N";
                            }
                            seedFile.seekg(-27, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickmaid = SendMessage(maiden, BM_SETCHECK, BST_CHECKED, 0);
                                pa_maid = true;
                                choiceMM = "Y";
                            }
                            else {
                                pa_maid = false;
                                choiceMM = "N";
                            }
                            seedFile.seekg(-26, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point != 78) {
                                if (point == 82) {
                                    choiceAshBuild = "R";
                                    SetWindowText(ashBuild, L"Random");
                                }
                                else if (point == 65) {
                                    choiceAshBuild = "A";
                                    SetWindowText(ashBuild, L"Dagger");
                                }
                                else if (point == 66) {
                                    choiceAshBuild = "B";
                                    SetWindowText(ashBuild, L"Great Sword");
                                }
                                else if (point == 67) {
                                    choiceAshBuild = "C";
                                    SetWindowText(ashBuild, L"Axe");
                                }
                                else if (point == 68) {
                                    choiceAshBuild = "D";
                                    SetWindowText(ashBuild, L"Mace");
                                }
                                else if (point == 69) {
                                    choiceAshBuild = "E";
                                    SetWindowText(ashBuild, L"Great Axe");
                                }
                                else if (point == 70) {
                                    choiceAshBuild = "F";
                                    SetWindowText(ashBuild, L"Great Mace");
                                }
                                else if (point == 71) {
                                    choiceAshBuild = "G";
                                    SetWindowText(ashBuild, L"Polearm");
                                }
                                else if (point == 72) {
                                    choiceAshBuild = "H";
                                    SetWindowText(ashBuild, L"Staff");
                                }
                                else if (point == 73) {
                                    choiceAshBuild = "I";
                                    SetWindowText(ashBuild, L"Crossbow");
                                }
                            }
                            else {
                                choiceAshBuild = "V";
                                SetWindowText(ashBuild, L"Default");
                            }
                            seedFile.seekg(-25, ios::end);
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
                            seedFile.seekg(-24, ios::end);
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
                            seedFile.seekg(-23, ios::end);
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
                            seedFile.seekg(-22, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickBoss = SendMessage(zenQui, BM_SETCHECK, BST_CHECKED, 0);
                                pa_zenQui = true;
                                choiceZenQui = "Y";
                            }
                            else {
                                pa_zenQui = false;
                                choiceZenQui = "N";
                            }
                            seedFile.seekg(-21, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickBoss = SendMessage(zenBoss, BM_SETCHECK, BST_CHECKED, 0);
                                pa_zenBoss = true;
                                choiceZenBoss = "Y";
                            }
                            else {
                                pa_zenBoss = false;
                                choiceZenBoss = "N";
                            }
                            seedFile.seekg(-20, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickDrop = SendMessage(zenDrop, BM_SETCHECK, BST_CHECKED, 0);
                                pa_zenDrop = true;
                                choiceZenDrop = "Y";
                            }
                            else {
                                pa_zenDrop = false;
                                choiceZenDrop = "N";
                            }
                            seedFile.seekg(-19, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickman = SendMessage(zenMan, BM_SETCHECK, BST_CHECKED, 0);
                                pa_zenMan = true;
                                choiceZenMan = "Y";
                            }
                            else {
                                pa_zenMan = false;
                                choiceZenMan = "N";
                            }
                            seedFile.seekg(-18, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT tickanal = SendMessage(zenAnal, BM_SETCHECK, BST_CHECKED, 0);
                                pa_zenAnal = true;
                                choiceZenAnal = "Y";
                            }
                            else {
                                pa_zenAnal = false;
                                choiceZenAnal = "N";
                            }
                            seedFile.seekg(-17, ios::end);
                            address = seedFile.tellg();
                            point = seedFile.get();
                            if (point == 89) {
                                LRESULT ticktel = SendMessage(zenTel, BM_SETCHECK, BST_CHECKED, 0);
                                pa_zenTel = true;
                                choiceZenTel = "Y";
                            }
                            else {
                                pa_zenTel = false;
                                choiceZenTel = "N";
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
            case IDM_DROPDOWN2:
            {
                MessageBox(hWnd, L"Select a build by clicking on the arrow to the right.", L"Choose a build", MB_OK);
            }
            break;
            case IDM_BUILD1:
            {
                SetWindowText(ashBuild, L"Default");
                choiceAshBuild = "V";
                ranBoxLock();
            }
            break;
            case IDM_BUILD2:
            {
                choiceAshBuild = "A";
                SetWindowText(ashBuild, L"Dagger");
                ranBoxLock();
            }
            break;
            case IDM_BUILD3:
            {
                choiceAshBuild = "B";
                SetWindowText(ashBuild, L"Great Sword");
                ranBoxLock();
            }
            break;
            case IDM_BUILD4:
            {
                choiceAshBuild = "C";
                SetWindowText(ashBuild, L"Axe");
                ranBoxLock();
            }
            break;
            case IDM_BUILD5:
            {
                choiceAshBuild = "D";
                SetWindowText(ashBuild, L"Mace");
                ranBoxLock();
            }
            break;
            case IDM_BUILD6:
            {
                choiceAshBuild = "E";
                SetWindowText(ashBuild, L"Great Axe");
                ranBoxLock();
            }
            break;
            case IDM_BUILD7:
            {
                choiceAshBuild = "F";
                SetWindowText(ashBuild, L"Great Mace");
                ranBoxLock();
            }
            break;
            case IDM_BUILD8:
            {
                choiceAshBuild = "G";
                SetWindowText(ashBuild, L"Polearm");
                ranBoxLock();
            }
            break;
            case IDM_BUILD9:
            {
                choiceAshBuild = "H";
                SetWindowText(ashBuild, L"Staff");
                ranBoxLock();
            }
            break;
            case IDM_BUILD10:
            {
                choiceAshBuild = "I";
                SetWindowText(ashBuild, L"Crossbow");
                ranBoxLock();
            }
            break;
            case IDM_BUILD11:
            {
                choiceAshBuild = "R";
                SetWindowText(ashBuild, L"Random");
                ranBoxLock();
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
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_THRES1, L"Default");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_THRES2, L"75 - 125");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_THRES3, L"50 - 150");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_THRES4, L"25 - 175");

                TrackPopupMenu(hSplitMenu, TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, 0, hWnd, NULL);
                //return TRUE;
            }
            else if (pDropDown->hdr.hwndFrom == GetDlgItem(hWnd, 9012))
            {
                POINT pt;
                pt.x = pDropDown->rcButton.left;
                pt.y = pDropDown->rcButton.bottom;
                ClientToScreen(pDropDown->hdr.hwndFrom, &pt);

                HMENU hSplitMenu = CreatePopupMenu();
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD1, L"Default");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD2, L"Dagger");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD3, L"Great Sword");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD4, L"Axe");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD5, L"Mace");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD6, L"Great Axe");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD7, L"Great Mace");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD8, L"Polearm");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD9, L"Staff");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD10, L"Crossbow");
                AppendMenu(hSplitMenu, MF_BYPOSITION, (UINT_PTR)IDM_BUILD11, L"Random");

                TrackPopupMenu(hSplitMenu, TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, 0, hWnd, NULL);
                //return TRUE;
            }
            break;
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
            swprintf_s(progtext, 256, L"Progression data:");
            swprintf_s(ashtext, 256, L"Ashley data:");
            swprintf_s(zentext, 256, L"Zenith options:");
            swprintf_s(mustext, 256, L"Music options:");
            eneHeadX = 0.0325 * mul;
            cheHeadX = 0.2725 * mul;
            areaHeadX = 0.5125 * mul;
            ashHeadX = 0.7525 * mul;
            zenHeadX = 0.9925 * mul;
            musHeadX = 1.2325 * mul;
            eneHeadY = 0.15 * mul;
            //chestHeadY = 0.39 * mul;
            //miscHeadY = 0.63 * mul;
            TextOut(hdc, xCor * eneHeadX, yCor * eneHeadY, enetext, wcslen(enetext));
            TextOut(hdc, xCor * cheHeadX, yCor * eneHeadY, chetext, wcslen(chetext));
            TextOut(hdc, xCor * areaHeadX, yCor * eneHeadY, progtext, wcslen(progtext));
            TextOut(hdc, xCor * ashHeadX, yCor * eneHeadY, ashtext, wcslen(ashtext));
            TextOut(hdc, xCor* zenHeadX, yCor* eneHeadY, zentext, wcslen(zentext));
            TextOut(hdc, xCor* musHeadX, yCor* eneHeadY, mustext, wcslen(mustext));
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
    butRos.emplace_back(maiden);
    butRos.emplace_back(openW);
    butRos.emplace_back(breakA);
    butRos.emplace_back(eneMod);
    butRos.emplace_back(drops);
    butRos.emplace_back(eneStat);
    butRos.emplace_back(ashley);
    butRos.emplace_back(ashBuild);
    butRos.emplace_back(zenTel);
    butRos.emplace_back(zenAnal);
    butRos.emplace_back(zenMan);
    butRos.emplace_back(zenDrop);
    butRos.emplace_back(zenBoss);
    butRos.emplace_back(zenQui);
    butRos.emplace_back(ashMisc);
    butRos.emplace_back(areaMusic);
    butRos.emplace_back(bossMusic);
    butRos.emplace_back(cutRes);
    butRos.emplace_back(balBreak);
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
        mul = (cur_dpi / 96);
    }
    else {
        mul = 1.00;
    }
    opBuX = 0.625 * mul;
    progBaX = 0.6 * mul;
    opBuY = 0.05 * mul;
    ranBuY = 0.8895 * mul;
    progBaY = 0.9905 * mul;
    enBuX = 0.025 * mul;
    enBuY = 0.20 * mul;
    entBuY = 0.7885 * mul;
    cleBuX = 0.1825 * mul;
    cheBuY = 0.44 * mul;
    balEneBuY = 0.43 * mul;
    rooBuY = 0.6725 * mul;
    cheBuX = 0.270 * mul;
    areaBuX = 0.5075 * mul;
    ashBuX = 0.745 * mul;
    zenBuX = 0.9825 * mul;
    areaMusBuX = 1.22 * mul;
    droBuX = 0.275 * mul;
    droBuY = 0.315 * mul; 
    thresBuY = 0.320 * mul; 
    buildBuY = 0.5520 * mul; 
    breakBuY = 0.6045 * mul; 
    balBrBuY = 0.657 * mul; 
    modBuY = 0.2575 * mul;
    itStBuY = 0.4975 * mul;
    enStBuY = 0.3725 * mul;
    ashStBuY = 0.73 * mul;
    balAshStBuY = 0.7875 * mul;
    balItQuaBuY = 0.5550 * mul;
    entBuX = 0.4575 * mul;
    revBuX = 0.7925 * mul;
    zenQuiBuY = 0.4875 * mul;

    openGame = CreateWindow(L"BUTTON", L"Open Game", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * opBuX), (int)(yCor * opBuY), 90 * mul, 25 * mul, hWnd, (HMENU)101, hInst, NULL);
    randomizeButton = CreateWindow(L"BUTTON", L"Randomize", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * opBuX), (int)(yCor * ranBuY), 90 * mul, 25 * mul, hWnd, (HMENU)9003, hInst, NULL);
    seedButton = CreateWindow(L"BUTTON", L"Enter Seed", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * entBuX), (int)(yCor * entBuY), 90 * mul, 25 * mul, hWnd, (HMENU)9004, hInst, NULL);
    cSeedButton = CreateWindow(L"BUTTON", L"Clear Seed", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * opBuX), (int)(yCor * entBuY), 90 * mul, 25 * mul, hWnd, (HMENU)9005, hInst, NULL);
    revertButton = CreateWindow(L"BUTTON", L"Revert to Vanilla", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * revBuX), (int)(yCor * entBuY), 90 * mul, 25 * mul, hWnd, (HMENU)9006, hInst, NULL);
    enemies = CreateWindow(L"BUTTON", L"Enemies", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * enBuY), 110 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    chests = CreateWindow(L"BUTTON", L"Chests", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * enBuY), 110 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    rooms = CreateWindow(L"BUTTON", L"Area Progression", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * areaBuX), (int)(yCor * enBuY), 130 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    maiden = CreateWindow(L"BUTTON", L"Mandatory Iron Maiden", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * areaBuX), (int)(yCor * modBuY), 130 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    openW = CreateWindow(L"BUTTON", L"Open World", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * areaBuX), (int)(yCor * droBuY), 130 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    breakA = CreateWindow(L"BUTTON", L"Break Art Costs", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * breakBuY), 130 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    balBreak = CreateWindow(L"BUTTON", L"Balance Break Art Costs", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * balBrBuY), 130 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    areaMusic = CreateWindow(L"BUTTON", L"Area Music", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * areaMusBuX), (int)(yCor * enBuY), 130 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    bossMusic = CreateWindow(L"BUTTON", L"Boss Music", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * areaMusBuX), (int)(yCor * droBuY), 130 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    cutRes = CreateWindow(L"BUTTON", L"Restore Cut Music", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * areaMusBuX), (int)(yCor * modBuY), 130 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    drops = CreateWindow(L"BUTTON", L"Drops", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * droBuY), 110 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    balance = CreateWindow(L"BUTTON", L"Balance Item Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * droBuY), 150 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    keep = CreateWindow(L"BUTTON", L"Item Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * modBuY), 110 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    consEqu = CreateWindow(L"BUTTON", L"Inconsistent Gear", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * balEneBuY), 150 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    eneMod = CreateWindow(L"BUTTON", L"Enemy Models (Unstable)", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * modBuY), 140 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    eneStat = CreateWindow(L"BUTTON", L"Enemy Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * enStBuY), 110 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    balEneStat = CreateWindow(L"BUTTON", L"Balance Enemy Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * enBuX), (int)(yCor * balEneBuY), 150 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    ashley = CreateWindow(L"BUTTON", L"Ashley's Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * enBuY), 110 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    balAshley = CreateWindow(L"BUTTON", L"Balance Ashley's Stats", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * modBuY), 150 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    fandango = CreateWindow(L"BUTTON", L"Fandango Blade and Grip", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * enStBuY), 150 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    quant = CreateWindow(L"BUTTON", L"Balance Item Quantities", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * cheBuX), (int)(yCor * enStBuY), 180 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    zenTel = CreateWindow(L"BUTTON", L"Free Teleport", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * zenBuX), (int)(yCor * enBuY), 120 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    zenAnal = CreateWindow(L"BUTTON", L"Perfect Analyze Hit Rate", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * zenBuX), (int)(yCor * modBuY), 150 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    zenMan = CreateWindow(L"BUTTON", L"Friendly Manabreaker", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * zenBuX), (int)(yCor * droBuY), 120 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    zenDrop = CreateWindow(L"BUTTON", L"New Drop System", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * zenBuX), (int)(yCor * enStBuY), 180 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    zenBoss = CreateWindow(L"BUTTON", L"Warlock Grimoire Drops", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * zenBuX), (int)(yCor * balEneBuY), 180 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    zenQui = CreateWindow(L"BUTTON", L"Buffless Blades and Gremlins", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * zenBuX), (int)(yCor * zenQuiBuY), 180 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    ashMisc = CreateWindow(L"BUTTON", L"Ashley's Misc Items", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * balEneBuY), 150 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    ashMiscQua = CreateWindow(L"BUTTON", L"Misc Item Quantities", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * ashBuX), (int)(yCor * zenQuiBuY), 150 * mul, 25 * mul, hWnd, (HMENU)9002, hInst, NULL);
    ashThres = CreateWindow(L"BUTTON", L"Ashley Stat Threshold", WS_CHILD | WS_VISIBLE | BS_SPLITBUTTON, (int)(xCor * ashBuX), (int)(yCor * thresBuY), 135 * mul, 20 * mul, hWnd, (HMENU)9007, hInst, NULL);
    ashBuild = CreateWindow(L"BUTTON", L"Ashley Build", WS_CHILD | WS_VISIBLE | BS_SPLITBUTTON, (int)(xCor * ashBuX), (int)(yCor * buildBuY), 135 * mul, 20 * mul, hWnd, (HMENU)9012, hInst, NULL);
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
    char telTipDesc[] =
        "Lets Ashley teleport without MP costs\n"
        "once the spell is unlocked.\n"
        "Credit goes to the_E_y_Es";
    HWND telTip = toolGen(telTipDesc, hWnd, zenTel);
    char analTipDesc[] =
        "Analyze will always work whenever\n"
        "it is used.\n"
        "Credit goes to the_E_y_Es";
    HWND analTip = toolGen(analTipDesc, hWnd, zenAnal);
    char manTipDesc[] =
        "The Manabreaker gem stops blocking\n"
        "friendly spells.\n"
        "Credit goes to the_E_y_Es";
    HWND manTip = toolGen(manTipDesc, hWnd, zenMan);
    char newDropTipDesc[] =
        "Repeatedly killing an enemy will\n"
        "increase their chances of dropping\n"
        "their equipment, though this will\n"
        "not affect rarer drops like those\n"
        "found in the deeper Iron Maiden levels.\n"
        "Credit goes to the_E_y_Es";
    HWND newDropTip = toolGen(newDropTipDesc, hWnd, zenDrop);
    char bossDropTipDesc[] =
        "The Ghost at The Lamenting Mother and\n"
        "the elemental bosses all drop single-target\n"
        "Warlock Grimoires based on each of their affinities.\n"
        "Credit goes to the_E_y_Es";
    HWND bossDropTip = toolGen(bossDropTipDesc, hWnd, zenBoss);
    char zenQuiTipDesc[] =
        "Crimson Blades at the Town Center and\n"
        "Gremlins at Limestone Quarry and Temple\n"
        "of Kiltia will not buff themselves.\n"
        "Credit goes to the_E_y_Es";
    HWND zenQuiTip = toolGen(zenQuiTipDesc, hWnd, zenQui);
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
    char ashBuildTipDesc[] =
        "Randomizes Ashley's stats and initial items\n"
        "based on a weapon type. The chosen weapon\n"
        "type will determine what the Fandango is.\n"
        "Picking 'Random' will pick a build for you.\n"
        "More details can be found in the README.";
    HWND ashBuildTip = toolGen(ashBuildTipDesc, hWnd, ashBuild);
    char maidenTipDesc[] =
        "Makes the Iron Maiden mandatory in New\n"
        "Game by locking Great Cathedral with a\n"
        "Tigertail Sigil, and having Kali drop the\n"
        "Gold and Platinum keys.";
    HWND maidenTip = toolGen(maidenTipDesc, hWnd, maiden);
    char openWTipDesc[] =
        "Starts Ashley with every Key and Sigil.";
    HWND openWTip = toolGen(openWTipDesc, hWnd, openW);
    char breakArtTipDesc[] =
        "Randomizes the HP costs to use Break Arts\n"
        "and the enemy kill costs to learn them.";
    HWND breakArtTip = toolGen(breakArtTipDesc, hWnd, breakA);
    char balBreakTipDesc[] =
        "Balances the Break Arts randomizer so that HP\n"
        "costs range from 25 to 75, and kill costs range\n"
        "from 10 to 485.";
    HWND balBreakTip = toolGen(balBreakTipDesc, hWnd, balBreak);
    char areaMusicTipDesc[] =
        "Randomizes the music that plays in areas.\n"
        "Only area music will be chosen, but removed\n"
        "area tracks are included in the pool.";
    HWND areaMusicTip = toolGen(areaMusicTipDesc, hWnd, areaMusic);
    char restoreCutMusicTipDesc[] =
        "Restores Lizardman, Leá Monde, and Within\n"
        "the City Walls and have them play for their\n"
        "respective contexts. These will get randomized\n"
        "if other parameters are selected.";
    HWND restoreCutMusicTip = toolGen(restoreCutMusicTipDesc, hWnd, cutRes);
    char bossMusicTipDesc[] =
        "Randomizes the track which plays for each\n"
        "boss. Any bosses which just play the area\n"
        "music are not randomized.";
    HWND bossMusicTip = toolGen(bossMusicTipDesc, hWnd, bossMusic);
}

void ranBoxLock() {
    bool checkFound = false;
    for (int i = 5; i < butRos.size() - 10; i++) {
        LRESULT boxticked = SendMessage(butRos[i], BM_GETCHECK, NULL, NULL);
        if ((boxticked == BST_CHECKED || choiceAshBuild != "V") && gamePathFound) {
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
        for (int i = 1; i < butRos.size() - 10; i++) {
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
    SetWindowTextA(hWnd, "Reverting to vanilla...");
    if (is_lizard) {
        revBat.open("revCmd.cmd", std::ios::trunc);
        revBat << ("cd " + ag.getStringPath() + " \n");
        revBat << "copy \"" + ag.getWhole().string() + "\" \"Backup Game.bin\" \n" << std::endl;
        revBat << ("Patches\\xdelta3-3.1.0-i686.exe -d  -f -s \"Backup Game.bin\" Patches\\Revert.xdelta \"" + ag.getWhole().string() + "\" \n") << std::endl;
        revBat.close();
        runRev = system("cmd.exe /c revCmd.cmd");
        remove("revCmd.cmd");
        is_lizard = false;
    }
    vanBat.open("vanCmd.cmd", std::ios::trunc);
    m_file = ag.getStringPath() + "\\BACKUP\\BATTLE\\INITBTL.PRG";
    ml = rf.getChestCheck();
    mlp = ml.begin();
    vanBat << ("cd " + ag.getStringPath() + " \n");
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /BATTLE/INITBTL.PRG" + " '" + m_file + "'") << std::endl;
    //m_file = ag.getStringPath() + "\\BACKUP\\PATCHED\\MAP046.MPD";
    //vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /BACKUP/PATCHED/MAP046.MPD" + " '" + m_file + "'") << std::endl;
    m_file = ag.getStringPath() + "\\BACKUP\\TITLE\\TITLE.PRG";
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /TITLE/TITLE.PRG" + " '" + m_file + "'") << std::endl;
    m_file = ag.getStringPath() + "\\BACKUP\\BATTLE\\BATTLE.PRG";
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /BATTLE/BATTLE.PRG" + " '" + m_file + "'") << std::endl;
    m_file = ag.getStringPath() + "\\BACKUP\\ZENITH_QOL\\MENU\\MENU0.PRG";
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MENU/MENU0.PRG" + " '" + m_file + "'") << std::endl;
    m_file = ag.getStringPath() + "\\BACKUP\\ZENITH_QOL\\SLUS_010.40";
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /SLUS_010.40" + " '" + m_file + "'") << std::endl;
    for (int mi = 0; mi < ml.size(); mi++) {
        m_file = ag.getStringPath() + "\\BACKUP\\" + *mlp;
        cur_map = *mlp;
        vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
        std::advance(mlp, 1);
    }
    vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + "MAP145.MPD" + " '" + ag.getStringPath() + "\\BACKUP\\" + "MAP145.MPD" + "'") << std::endl;
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
    m = rf.getBossMusicRooms();
    mp = m.begin();
    for (int i = 0; i < m.size(); i++) {
        m_file = ag.getStringPath() + "\\BACKUP\\" + *mp;
        cur_map = *mp;
        vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
        std::advance(mp, 1);
    }
    pz = rf.getPlayZones();
    pzp = pz.begin();
    for (int i = 0; i < pz.size(); i++) {
        m_file = ag.getStringPath() + "\\BACKUP\\" + *pzp;
        cur_map = *pzp;
        vanBat << (rf.getTool() + " '" + ag.getWhole().string() + "' /MAP/" + cur_map + " '" + m_file + "'") << std::endl;
        std::advance(pzp, 1);
    }
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\\" \"" + ag.getStringPath() + "\\MAPS\\\"") << std::endl;
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\\" \"" + ag.getStringPath() + "\\ZONES\\\"") << std::endl;
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\BATTLE\\\" \"" + ag.getStringPath() + "\\MISC\\\"") << std::endl;
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\TITLE\\\" \"" + ag.getStringPath() + "\\MISC\\\"") << std::endl;
    vanBat << ("xcopy /s /y \"" + ag.getStringPath() + "\\BACKUP\\PATCHED\\\" \"" + ag.getStringPath() + "\\MAPS\\PATCHED\\\"") << std::endl;
    vanBat.close();
    runRev = system("cmd.exe /c vanCmd.cmd");
    remove("vanCmd.cmd");
    game.open(path, ios::in | ios::out | ios::binary | ios::ate);
    ch_val = new char(31);
    game.seekp(258798096, ios::beg);
    game.write(ch_val, 1);
    game.seekp(258798099, ios::beg);
    game.write(ch_val, 1);
    delete ch_val;
    ch_val = new char(32);
    game.seekp(258784337, ios::beg);
    game.write(ch_val, 1);
    game.seekp(258784340, ios::beg);
    game.write(ch_val, 1);
    delete ch_val;
    ch_val = new char(49);
    game.seekp(259164576, ios::beg);
    game.write(ch_val, 1);
    game.seekp(259164579, ios::beg);
    game.write(ch_val, 1);
    delete ch_val;
    ch_val = new char(38);
    game.seekp(259312761, ios::beg);
    game.write(ch_val, 1);
    game.seekp(259312764, ios::beg);
    game.write(ch_val, 1);
    ch_val = new char(48);
    game.seekp(259319803, ios::beg);
    game.write(ch_val, 1);
    game.seekp(259319806, ios::beg);
    game.write(ch_val, 1);
    delete ch_val;
    ch_val = new char(156);
    game.seekp(259066021, ios::beg);
    game.write(ch_val, 1);
    game.seekp(259066024, ios::beg);
    game.write(ch_val, 1);
    game.seekp(259066024, ios::beg);
    game.write(ch_val, 1);
    game.seekp(259067146, ios::beg);
    game.write(ch_val, 1);
    game.seekp(259067149, ios::beg);
    game.write(ch_val, 1);
    delete ch_val;
    ch_val = new char(36);
    game.seekp(21916973, ios::beg);
    game.write(ch_val, 1);
    game.seekp(21916976, ios::beg);
    game.write(ch_val, 1);
    delete ch_val;
    game.close();
    if (freshPick != true) {
        isVanilla = true;
        EnableWindow(butRos[4], FALSE);
        MessageBox(hWnd, L"Game unrandomized!", L"Success", MB_OK);
    }
    else {
        freshPick = false;
    }
    SetWindowTextA(hWnd, "Vagrant Story Randomizer");
}

