// man.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "man.h"

#include <algorithm>
#include <vector>
#include <numeric>
#include <complex>
#include <future>
#include "rgbColors.hpp"
#include "fractal_map.hpp"

using namespace std;

using cmplx = complex<double>;

///////////////////////////////////////////////////////////////////////////////

static auto scaler(int min_from, int max_from,
    double min_to, double max_to)
{
    const int w_from{ max_from - min_from };
    const double w_to{ max_to - min_to };
    const int mid_from{ (max_from - min_from) / 2 + min_from };
    const double mid_to{ (max_to - min_to) / 2.0 + min_to };

    return [=](int from)
    {
        return (static_cast<double>(from) - static_cast<double>(mid_from)) / w_from * w_to + mid_to;
    };
}

///////////////////////////////////////////////////////////////////////////////

template <typename A, typename B>
static auto scaled_cmplx(A scaler_x, B scaler_y)
{
    return [=](int x, int y)
    {
        return cmplx{ scaler_x(x), scaler_y(y) };
    };
}

///////////////////////////////////////////////////////////////////////////////

static auto mandelbrodt_iterations(cmplx c)
{
    cmplx z{0};
    size_t iterations{ 0 };
    const size_t max_iterations{ 20000 };
    while (abs(z) < 2.0 && iterations < max_iterations)
    {
        ++iterations;
        z = pow(z, 2) + c;
    }
    return iterations;
}

///////////////////////////////////////////////////////////////////////////////

static auto julia_iterations(cmplx i_z)
{
    cmplx z{ i_z };
    //const cmplx c( - 0.8, 0.156 );
    const cmplx c(-0.4, 0.6);
    //const cmplx c(-0.835, -0.2321);
    //const cmplx c(0.0, 0.8);
    //const cmplx c(0.355, 0.355);
    //const cmplx c(0.37, 0.1);
    //const cmplx c(-0.54, 0.54);
    //const cmplx c(-0.4, -0.59);
    //const cmplx c(0.355534, -0.337292);
    //const cmplx c(-0.202420806884766, 0.39527333577474);
    //const cmplx c(-0.162, 1.04);
    //const cmplx c(-0.12, 0.74);
    //const cmplx c(0.3853707414829657, 0.3135804996222915);
    size_t iterations{ 0 };
    const size_t max_iterations{ 20000 };
    while (abs(z) < 2 && iterations < max_iterations)
    {
        ++iterations;
        z = pow(z, 2) + c;
    }
    return iterations;
}

///////////////////////////////////////////////////////////////////////////////

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

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
    LoadStringW(hInstance, IDC_MAN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MAN));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MAN);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


void draw_mandelbrodt(HDC& hdc)
{
    const size_t w{ 1000 };
    const size_t h{ 500 };

    auto scale{ scaled_cmplx(
        //scaler(0, w, -3.0, 3.0),
        scaler(0, w, -1.5, 1.5),
        //scaler(0, w, -0.25, 0.25),
        //scaler(0, w, -0.30, -0.25),
        //scaler(0, h, -2.0, 2.0)
        scaler(0, h, -1.2, 1.2)
        //scaler(0, h, 0.75, 1.0)
        //scaler(0, h, 0.75, 0.755)
        //scaler(0, h, 0.3, 0.4)
    ) };

    auto i_to_z_cmplx([=](int i) {return scale(i % w, i / w); });

    // auto to_iteration_count([=](int i) {return mandelbrodt_iterations(i_to_xy(i));});
    auto to_iteration_count([=](int i) {
        return std::async(launch::async, julia_iterations, i_to_z_cmplx(i));
        // return mandelbrodt_iterations(i_to_xy(i));
    });

    std::vector<int> v(w * h);
    std::vector<std::future<size_t>> r(w * h);
    // std::vector<int> r(w * h);
    std::iota(begin(v), end(v), 0);
    std::transform(begin(v), end(v), begin(r), to_iteration_count);

    /*auto binfunc([w, n{0}](auto output_it, int x) mutable
        {
            *++output_it = x > 50 ? '*' : ' ';
            if (++n % w == 0) {*++output_it = '\n';}
            return output_it;
        }
        );*/

        // std::accumulate(begin(v), end(v), ostream_iterator<char>{cout}, binfunc);
    //auto Set_Pixel = [&hdc, &swapBlueRed](int i, const char* s) { SetPixel(hdc, i % w + 50, i / w + 50, swapBlueRed(color_select[s])); };
    for (int ix = 0; ix < v.size(); ++ix)
    {
        auto rx = r[ix].get();
        // auto rx = r[ix];
        Color_Pixel_Julia_3(rx, ix, hdc);
    }

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
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
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
            // TODO: Add any drawing code that uses hdc here...
            draw_mandelbrodt(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
