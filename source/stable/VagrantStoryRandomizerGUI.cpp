// VagrantStoryRandomizerGUI.cpp : Defines the entry point for the application.
//
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
#include <stdio.h>
#include <stddef.h>
#include <commdlg.h>
#include "Enemies.h"
#include "Chests.h"
#include "Rooms.h"
#include <chrono>



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
HWND randomizeButton;
HWND seedButton;
HWND window;
HWND getCon = GetConsoleWindow();
DWORD dwStyle = WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;
std::vector<HWND> butRos;
Add_Game ag = Add_Game();
int xCor = 640;
int yCor = 380;
int seedBoxID;
int cusSeedI = NULL;
void placeButtons();
void setWin(HWND hWnd);
void makeButtons(HWND hWnd);
void ranBoxLock();
void relock();
void checkBoxLock();
void clearText();
bool gamePathFound = false;
bool pa_enemies = false;
bool pa_chests = false;
bool pa_rooms = false;
bool pa_drops = false;
bool cusSeedU = false;
string choice;
string seedChoice;
string cusSeedS;
fstream game;
fstream seedFile;
Reference_Files rf = Reference_Files();
RECT rcWindow;
std::mt19937 gen;
std::mt19937 finGen;
//int seedBox();


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
      CW_USEDEFAULT, 0, 320, 240, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
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
                LRESULT cheticked = SendMessage(chests, BM_GETCHECK, NULL, NULL);
                LRESULT rooticked = SendMessage(rooms, BM_GETCHECK, NULL, NULL);
                if (eneticked == BST_CHECKED) {
                    pa_enemies = true;
                    EnableWindow(butRos[butRos.size() - 1], true);
                }
                else {
                    pa_enemies = false;
                    EnableWindow(butRos[butRos.size() - 1], false);
                }
                if (cheticked == BST_CHECKED) {
                    pa_chests = true;
                }
                else {
                    pa_chests = false;
                }
                if (rooticked == BST_CHECKED) {
                    pa_rooms = true;
                }
                else {
                    pa_rooms = false;
                }
                if (droticked == BST_CHECKED && eneticked == BST_CHECKED) {
                    choice = "Y";
                }
                else {
                    choice = "N";
                }
                ranBoxLock();
            }
            break;
            case IDM_RANDOMIZE:
            {
                bool changed = false;
                //seedBox() {
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
                    ag.makeGenPlus(seedChoice, cusSeedI);
                }
                else {
                    ag.makeGen(seedChoice);
                }
                finGen = ag.getGen();
                if (seedChoice == "Y") {
                    MessageBox(hWnd, L"Seed saved to 'seed.txt'.", L"Seed Saved", MB_OK);
                }
                if (pa_enemies) {
                    changed = true;
                    Enemies ene_ran = Enemies();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    ene_ran.mapIterate(rf, ag, choice, finGen);
                }
                if (pa_chests) {
                    changed = true;
                    Chests che_ran = Chests();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    che_ran.mapIterate(rf, ag, finGen);
                }
                if (pa_rooms) {
                    changed = true;
                    Rooms roo_ran = Rooms();
                    SetCursor(LoadCursor(NULL, IDC_WAIT));
                    roo_ran.roomIterate(rf, ag, finGen);
                }
                if (changed == true)
                {
                    MessageBox(hWnd, L"Randomization completed!", L"Success", MB_OK);
                    relock();
                }
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
                        for (int p = 0; p < dest - 2; p++) {
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
                            cusSeedI = stoi(cusSeedS);
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

void placeButtons() {
    butRos.emplace_back(openGame);
    butRos.emplace_back(randomizeButton);
    butRos.emplace_back(seedButton);
    butRos.emplace_back(enemies);
    butRos.emplace_back(chests);
    butRos.emplace_back(rooms);
    butRos.emplace_back(drops);
}

void makeButtons(HWND hWnd) {
    openGame = CreateWindow(L"BUTTON", L"Open Game", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * 0.15), (int)(yCor * 0.05), 90, 25, hWnd, (HMENU)101, hInst, NULL);
    randomizeButton = CreateWindow(L"BUTTON", L"Randomize", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * 0.15), (int)(yCor * 0.45), 90, 25, hWnd, (HMENU)9003, hInst, NULL);
    seedButton = CreateWindow(L"BUTTON", L"Enter Seed", WS_BORDER | WS_CHILD | WS_VISIBLE, (int)(xCor * 0.15), (int)(yCor * 0.35), 90, 25, hWnd, (HMENU)9004, hInst, NULL);
    enemies = CreateWindow(L"BUTTON", L"Enemies", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.15), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    chests = CreateWindow(L"BUTTON", L"Chests", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.25), (int)(yCor * 0.15), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    rooms = CreateWindow(L"BUTTON", L"Area Progression", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.25), (int)(yCor * 0.25), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
    drops = CreateWindow(L"BUTTON", L"Drops", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, (int)(xCor * 0.0325), (int)(yCor * 0.25), 110, 25, hWnd, (HMENU)9002, hInst, NULL);
}

void ranBoxLock() {
    bool checkFound = false;
    for (int i = 3; i < butRos.size() - 1; i++) {
        LRESULT boxticked = SendMessage(butRos[i], BM_GETCHECK, NULL, NULL);
        if (boxticked == BST_CHECKED) {
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
        for (int i = 3; i < butRos.size() - 1; i++) {
            EnableWindow(butRos[i], found);
        }
    }
    else {
        found = false;
        for (int i = 3; i < butRos.size(); i++) {
           LRESULT untick = SendMessage(butRos[i], BM_SETCHECK, BST_UNCHECKED, NULL);
        }
        for (int i = 3; i < butRos.size(); i++) {
            EnableWindow(butRos[i], found);
        }
    }
}
