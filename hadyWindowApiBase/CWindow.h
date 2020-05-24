#include <Windows.h>

namespace hady 
{
	class CWindow
	{
	public:
		CWindow(int x, int y);
		~CWindow();

	public:
		void createWindow(HINSTANCE hInstance, WNDPROC WndProc, LPSTR lpCmdLine, int nCmdShow);

		LRESULT processProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		HWND _hWnd{};

		int _wndWidth{};
		int _wndHeight{};
	};
}
