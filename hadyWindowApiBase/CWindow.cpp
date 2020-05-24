#include "CWindow.h"

hady::CWindow::CWindow(int x, int y) : _wndWidth{ x }, _wndHeight{ y }
{
	__noop;
}

hady::CWindow::~CWindow()
{
	
}

void hady::CWindow::createWindow(HINSTANCE hInstance, WNDPROC WndProc, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wndClass{};
	wndClass.cbSize = sizeof(wndClass);
	wndClass.hbrBackground = CreateSolidBrush(RGB(10, 220, 160));
	wndClass.hCursor = LoadCursor(nullptr, IDC_PERSON); 
	wndClass.hIcon = LoadIcon(nullptr, IDI_QUESTION);
	wndClass.hIconSm = LoadIcon(nullptr, IDI_SHIELD);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = L"myclass";
	wndClass.lpszMenuName = nullptr;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&wndClass);

	// CreateWindow라는 함수는 윈도우를 생성하고, 생성된 윈도우의 핸들을 리턴해준다. 그 값을 HWND hWnd에다가 저장한다.
	_hWnd = CreateWindow(wndClass.lpszClassName, L"윈도우", WS_OVERLAPPEDWINDOW, 0, 0, 600, 200, nullptr, nullptr, hInstance, nullptr);

	// 생성된 윈도우(hWnd)를 보여주는 방법을 지정해서 보여줌
	ShowWindow(_hWnd, nCmdShow);
	// 윈도우를 업데이트 해준다. 
	// 생성된 윈도우(hWnd)를 다시 그린다.
	UpdateWindow(_hWnd);
}
 

LRESULT hady::CWindow::processProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CHAR:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
