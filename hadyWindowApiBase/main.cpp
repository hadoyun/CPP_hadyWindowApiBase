#include "CWindow.h"


static const int g_kWitdh{ 200 };
static const int g_kheight{ 200 };

hady::CWindow cWin{ g_kWitdh, g_kheight };

//WndProc 함수를 선언
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return cWin.processProc(hWnd, message, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	cWin.createWindow(hInstance, WndProc, lpCmdLine, nCmdShow);

	MSG message{};

	while (GetMessage(&message, nullptr, 0, 0))
	{
		TranslateMessage(&message);

		DispatchMessage(&message);
	}

	return 0;
}
