// Compile as X64 for 64 Bit Systems
// Compile as X86 for 32 Bit Systems

#include <windows.h>
#include <iostream>
using namespace std;

DWORD Y_Axis = 0x00DA4C68;
int Y_Axisint;

DWORD X_Axis = 0x00DA4C60;
int X_Axisint;

DWORD Z_Axis = 0x00DA4C64;
int Z_Axisint;
DWORD pID;

unsigned int scan_delay = 300;

int Agro = 250000;
int Dgro = -250000;

void clear() {
	system("cls");
}

int main() {
	SetConsoleTitleA("ZombiU Noclip Cheat [ Version: 1.3.6 ]");
	// Hook To Process Memory //
	HWND hwnd = FindWindowA(0, ("ZOMBI"));
	if (!hwnd) cerr << "CANNOT FIND ZOMBI.EXE" << endl;
	GetWindowThreadProcessId(hwnd, &pID);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
	if (!pHandle) cerr << "ERROR" << endl;
	// Read Process Memory //
	cout << "Controls are in [controls.txt] file." << endl;
	while (true) {
		// clear();
		Sleep(scan_delay); // Wait for (Time In Miliseconds)
		ReadProcessMemory(pHandle, (void*)X_Axis, &X_Axisint, sizeof(X_Axisint), 0); // Get X Axis
		ReadProcessMemory(pHandle, (void*)Y_Axis, &Y_Axisint, sizeof(Y_Axisint), 0); // Get Y Axis
		ReadProcessMemory(pHandle, (void*)Z_Axis, &Z_Axisint, sizeof(Z_Axisint), 0); // Get Z Axis
		// cout << "X Axis: " << X_Axisint << endl;
		// cout << "Y Axis: " << Y_Axisint << endl;
		// cout << "Z Axis: " << Z_Axisint << endl;
		// Keybinds //
		if (GetAsyncKeyState(VK_NUMPAD9)) {
			int Final_UP = Agro + Y_Axisint; // Take Y Axis and + By (Agro)
			WriteProcessMemory(pHandle, (LPVOID)Y_Axis, &Final_UP, (DWORD)sizeof(Final_UP), 0);
			cout << "WriteProcessMemory >> OK // Written To Byte " << Y_Axis << " with " << Final_UP << endl;
		}
		if (GetAsyncKeyState(VK_NUMPAD3)) {
			int Final_DOWN = Dgro + Y_Axisint; // Take Y Axis and - By (Dgro)
			WriteProcessMemory(pHandle, (LPVOID)Y_Axis, &Final_DOWN, (DWORD)sizeof(Final_DOWN), 0);
			cout << "WriteProcessMemory >> OK // Written To Byte " << Y_Axis << " with " << Final_DOWN << endl;
		}
		if (GetAsyncKeyState(VK_NUMPAD6)) {
			int Final_RIGHT = Agro + X_Axisint;
			WriteProcessMemory(pHandle, (LPVOID)X_Axis, &Final_RIGHT, (DWORD)sizeof(Final_RIGHT), 0);
			cout << "WriteProcessMemory >> OK // Written To Byte " << X_Axis << " with " << Final_RIGHT << endl;
		}
		if (GetAsyncKeyState(VK_NUMPAD4)) {
			int Final_LEFT = Dgro + X_Axisint;
			WriteProcessMemory(pHandle, (LPVOID)X_Axis, &Final_LEFT, (DWORD)sizeof(Final_LEFT), 0);
			cout << "WriteProcessMemory >> OK // Written To Byte " << X_Axis << " with " << Final_LEFT << endl;
		}
		if (GetAsyncKeyState(VK_NUMPAD8)) {
			int Final_FORWARD = Agro + Z_Axisint;
			WriteProcessMemory(pHandle, (LPVOID)Z_Axis, &Final_FORWARD, (DWORD)sizeof(Final_FORWARD), 0);
			cout << "WriteProcessMemory >> OK // Written To Byte " << Z_Axis << " with " << Final_FORWARD << endl;
		}
		if (GetAsyncKeyState(VK_NUMPAD2)) {
			int Final_BACKWARD = Dgro + Z_Axisint;
			WriteProcessMemory(pHandle, (LPVOID)Z_Axis, &Final_BACKWARD, (DWORD)sizeof(Final_BACKWARD), 0);
			cout << "WriteProcessMemory >> OK // Written To Byte " << Z_Axis << " with " << Final_BACKWARD << endl;
		}
		// Specify A Cord //
		if (GetAsyncKeyState(VK_NUMPAD5)) {
			int specify_x;
			int specify_y;
			int specify_z;
			cout << "Specify A Cord" << endl;
			cout << "\nX Cord > ";
			cin >> specify_x;
			cout << "\nY Cord > ";
			cin >> specify_y;
			cout << "\nZ Cord > ";
			cin >> specify_z;
			WriteProcessMemory(pHandle, (LPVOID)X_Axis, &specify_x, (DWORD)sizeof(specify_x), 0);
			WriteProcessMemory(pHandle, (LPVOID)Y_Axis, &specify_y, (DWORD)sizeof(specify_y), 0);
			WriteProcessMemory(pHandle, (LPVOID)Z_Axis, &specify_z, (DWORD)sizeof(specify_z), 0);
		}
	}
}