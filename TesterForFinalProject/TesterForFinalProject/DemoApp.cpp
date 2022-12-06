#include "DemoApp.h"
//
//
//DemoApp::DemoApp() :
//    m_hwnd(NULL),
//    m_pDirect2dFactory(NULL),
//    m_pRenderTarget(NULL),
//    m_pLightSlateGrayBrush(NULL),
//    m_pCornflowerBlueBrush(NULL),
//    m_pBlackBrush(NULL),
//    m_pRedBrush(NULL)
//
//{}
//
//DemoApp::~DemoApp()
//{
//    SafeRelease(&m_pDirect2dFactory);
//    SafeRelease(&m_pRenderTarget);
//    SafeRelease(&m_pLightSlateGrayBrush);
//    SafeRelease(&m_pCornflowerBlueBrush);
//    SafeRelease(&m_pRedBrush);
//    SafeRelease(&m_pBlackBrush);
//}
//
//void DemoApp::RunMessageLoop()
//{
//    MSG msg;
//
//    while (GetMessage(&msg, NULL, 0, 0))
//    {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//}
//
//HRESULT DemoApp::Initialize()
//{
//    HRESULT hr;
//
//    // Initialize device-indpendent resources, such
//    // as the Direct2D factory.
//    hr = CreateDeviceIndependentResources();
//
//    if (SUCCEEDED(hr))
//    {
//        // Register the window class.
//        WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
//        wcex.style = CS_HREDRAW | CS_VREDRAW;
//        wcex.lpfnWndProc = DemoApp::WndProc;
//        wcex.cbClsExtra = 0;
//        wcex.cbWndExtra = sizeof(LONG_PTR);
//        wcex.hInstance = HINST_THISCOMPONENT;
//        wcex.hbrBackground = NULL;
//        wcex.lpszMenuName = NULL;
//        wcex.hCursor = LoadCursor(NULL, IDI_APPLICATION);
//        wcex.lpszClassName = L"D2DDemoApp";
//
//        RegisterClassEx(&wcex);
//
//        // In terms of using the correct DPI, to create a window at a specific size
//        // like this, the procedure is to first create the window hidden. Then we get
//        // the actual DPI from the HWND (which will be assigned by whichever monitor
//        // the window is created on). Then we use SetWindowPos to resize it to the
//        // correct DPI-scaled size, then we use ShowWindow to show it.
//
//        m_hwnd = CreateWindow(
//            L"D2DDemoApp",
//            L"Direct2D demo application",
//            WS_OVERLAPPEDWINDOW,
//            CW_USEDEFAULT,
//            CW_USEDEFAULT,
//            0,
//            0,
//            NULL,
//            NULL,
//            HINST_THISCOMPONENT,
//            this);
//
//        if (m_hwnd)
//        {
//            // Because the SetWindowPos function takes its size in pixels, we
//            // obtain the window's DPI, and use it to scale the window size.
//            float dpi = GetDpiForWindow(m_hwnd);
//
//            SetWindowPos(
//                m_hwnd,
//                NULL,
//                NULL,
//                NULL,
//                static_cast<int>(ceil(640.f * dpi / 96.f)),
//                static_cast<int>(ceil(480.f * dpi / 96.f)),
//                SWP_NOMOVE);
//            ShowWindow(m_hwnd, SW_SHOWNORMAL);
//            UpdateWindow(m_hwnd);
//        }
//    }
//
//    return hr;
//}
//
//HRESULT DemoApp::CreateDeviceIndependentResources()
//{
//    HRESULT hr = S_OK;
//
//    // Create a Direct2D factory.
//    hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pDirect2dFactory);
//
//    return hr;
//}
//
//HRESULT DemoApp::CreateDeviceResources()
//{
//    HRESULT hr = S_OK;
//
//    if (!m_pRenderTarget)
//    {
//        RECT rc;
//        GetClientRect(m_hwnd, &rc);
//
//        D2D1_SIZE_U size = D2D1::SizeU(
//            rc.right - rc.left,
//            rc.bottom - rc.top
//        );
//
//        // Create a Direct2D render target.
//        hr = m_pDirect2dFactory->CreateHwndRenderTarget(
//            D2D1::RenderTargetProperties(),
//            D2D1::HwndRenderTargetProperties(m_hwnd, size),
//            &m_pRenderTarget
//        );
//
//        if (SUCCEEDED(hr))
//        {
//            // Create a gray brush.
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::LightSlateGray),
//                &m_pLightSlateGrayBrush
//            );
//        }
//        if (SUCCEEDED(hr))
//        {
//            // Create a blue brush.
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::CornflowerBlue),
//                &m_pCornflowerBlueBrush
//            );
//        }
//        if (SUCCEEDED(hr))
//        {
//            // Create a black brush.
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::Black),
//                &m_pBlackBrush
//            );
//        }
//        if (SUCCEEDED(hr))
//        {
//            // Create a red brush.
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::Red),
//                &m_pRedBrush
//            );
//        }
//    }
//
//    return hr;
//}
//
//void DemoApp::DiscardDeviceResources()
//{
//    SafeRelease(&m_pRenderTarget);
//    SafeRelease(&m_pLightSlateGrayBrush);
//    SafeRelease(&m_pCornflowerBlueBrush);
//    SafeRelease(&m_pBlackBrush);
//    SafeRelease(&m_pRedBrush);
//}
//
//LRESULT CALLBACK DemoApp::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    LRESULT result = 0;
//
//    if (message == WM_CREATE)
//    {
//        LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
//        DemoApp* pDemoApp = (DemoApp*)pcs->lpCreateParams;
//
//        ::SetWindowLongPtrW(
//            hwnd,
//            GWLP_USERDATA,
//            reinterpret_cast<LONG_PTR>(pDemoApp)
//        );
//
//        result = 1;
//    }
//    else
//    {
//        DemoApp* pDemoApp = reinterpret_cast<DemoApp*>(static_cast<LONG_PTR>(
//            ::GetWindowLongPtrW(
//                hwnd,
//                GWLP_USERDATA
//            )));
//
//        bool wasHandled = false;
//
//        if (pDemoApp)
//        {
//            switch (message)
//            {
//            case WM_SIZE:
//            {
//                UINT width = LOWORD(lParam);
//                UINT height = HIWORD(lParam);
//                pDemoApp->OnResize(width, height);
//            }
//            result = 0;
//            wasHandled = true;
//            break;
//
//            case WM_DISPLAYCHANGE:
//            {
//                InvalidateRect(hwnd, NULL, FALSE);
//            }
//            result = 0;
//            wasHandled = true;
//            break;
//
//            case WM_PAINT:
//            {
//                //pDemoApp->OnRender();
//                pDemoApp->LineTest();
//
//                ValidateRect(hwnd, NULL);
//
//            }
//            result = 0;
//            wasHandled = true;
//            break;
//
//            case WM_DESTROY:
//            {
//                PostQuitMessage(0);
//            }
//            result = 1;
//            wasHandled = true;
//            break;
//            }
//        }
//
//        if (!wasHandled)
//        {
//            result = DefWindowProc(hwnd, message, wParam, lParam);
//        }
//    }
//
//    return result;
//}
//
//HRESULT DemoApp::OnRender()
//{
//    HRESULT hr = S_OK;
//
//    hr = CreateDeviceResources();
//
//    if (SUCCEEDED(hr))
//    {
//        m_pRenderTarget->BeginDraw();
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
//        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
//
//        D2D1_SIZE_F rtSize = m_pRenderTarget->GetSize();
//
//        // Draw a grid background.
//        int width = static_cast<int>(rtSize.width);
//        int height = static_cast<int>(rtSize.height);
//
//        for (int x = 0; x < width; x += 10)
//        {
//            m_pRenderTarget->DrawLine(
//                D2D1::Point2F(static_cast<FLOAT>(x), 0.0f),
//                D2D1::Point2F(static_cast<FLOAT>(x), rtSize.height),
//                m_pLightSlateGrayBrush,
//                0.5f
//            );
//        }
//
//        for (int y = 0; y < height; y += 10)
//        {
//            m_pRenderTarget->DrawLine(
//                D2D1::Point2F(0.0f, static_cast<FLOAT>(y)),
//                D2D1::Point2F(rtSize.width, static_cast<FLOAT>(y)),
//                m_pLightSlateGrayBrush,
//                0.5f
//            );
//        }
//
//        // Draw two rectangles.
//        D2D1_RECT_F rectangle1 = D2D1::RectF(
//            rtSize.width / 2 - 50.0f,
//            rtSize.height / 2 - 50.0f,
//            rtSize.width / 2 + 50.0f,
//            rtSize.height / 2 + 50.0f
//        );
//
//        D2D1_RECT_F rectangle2 = D2D1::RectF(
//            rtSize.width / 2 - 100.0f,
//            rtSize.height / 2 - 100.0f,
//            rtSize.width / 2 + 100.0f,
//            rtSize.height / 2 + 100.0f
//        );
//
//        // Draw a filled rectangle.
//        m_pRenderTarget->FillRectangle(&rectangle1, m_pLightSlateGrayBrush);
//
//        // Draw the outline of a rectangle.
//        m_pRenderTarget->DrawRectangle(&rectangle2, m_pCornflowerBlueBrush);
//
//        hr = m_pRenderTarget->EndDraw();
//    }
//
//    if (hr == D2DERR_RECREATE_TARGET)
//    {
//        hr = S_OK;
//        DiscardDeviceResources();
//    }
//
//    return hr;
//}

//// Draws the lines
//HRESULT DemoApp::LineTest()
//{
//    // macro for window signalling???
//    HRESULT hr = S_OK;
//
//    // create device resources, brush, window, etc
//    hr = CreateDeviceResources();
//
//    if (SUCCEEDED(hr))
//    {
//        // begins draw call
//        m_pRenderTarget->BeginDraw();
//        // sets transform
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
//        // clears render target, sets background to white
//        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
//
//        D2D1_SIZE_F rtSize = m_pRenderTarget->GetSize();
//
//
//        int width = static_cast<int>(rtSize.width);
//        int height = static_cast<int>(rtSize.height);
//
//        // used to help define the second point coordinates
//        int angle = Random::get(0, 360);
//
//        // sets length of lines to be drawn
//        double length = 10;
//
//        //for (int lines{}; lines < 100; lines++)
//        //{
//        //    //int direction{ Random::get(0, 1) };
//        //
//        //    int point1x{ Random::get(0, static_cast<int>(rtSize.width)) };
//        //    int point1y{ Random::get(0, static_cast<int>(rtSize.height)) };
//        //
//        //    int point2x{ Random::get(0, static_cast<int>(rtSize.width)) };
//        //    int point2y{ Random::get(0, static_cast<int>(rtSize.height)) };
//        //
//        //    /*if (direction == 0)
//        //    {
//        //        point2x = point1x + length;
//        //        point2y = point1y + length;
//        //    }
//        //    else
//        //    {
//        //        point2x = point1x - length;
//        //        point2y = point1y - length;
//        //    }
//        //    */
//        //
//        //    m_pRenderTarget->DrawLine(
//        //        D2D1::Point2F(point1x, point1y),
//        //        D2D1::Point2F(point2x, point2y),
//        //        m_pBlackBrush,
//        //        1.5f
//        //    );
//        //
//        //    
//        //}
//
//        // generates first point (set of x,y coords) based on a random number between
//        // 0 and the width or height of the window
//        int point1x{ Random::get(0, static_cast<int>(rtSize.width)) };
//        int point1y{ Random::get(0, static_cast<int>(rtSize.height)) };
//
//        // generates the second point (set of x,y coords) a fixed distance from the first, 
//        // but in a random direction
//        int point2x{ point1x + (int)((std::cos(angle) * length)) };
//        int point2y{ point1y + (int)((std::cos(angle) * length)) };
//
//        // points render target to DrawLine() function
//        // parameters are two x,y points, brush style, and width as a floating point value
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F((FLOAT)(point1x), (FLOAT)(point1y)),
//            D2D1::Point2F((FLOAT)(point2x), (FLOAT)(point2y)),
//            m_pBlackBrush,
//            1.5f
//        );
//
//        /*m_pRenderTarget->DrawLine(
//            D2D1::Point2F(45.0f, 50.0f),
//            D2D1::Point2F(60.0f, 12.0f),
//            m_pRedBrush,
//            3.0f
//        );*/
//    }
//
//    // Ends draw call
//    hr = m_pRenderTarget->EndDraw();
//
//    // 
//    if (hr == D2DERR_RECREATE_TARGET)
//    {
//        hr = S_OK;
//        DiscardDeviceResources();
//    }
//
//    // return hr which is....
//    return hr;
//}

//void DemoApp::OnResize(UINT width, UINT height)
//{
//    if (m_pRenderTarget)
//    {
//        // Note: This method can fail, but it's okay to ignore the
//        // error here, because the error will be returned again
//        // the next time EndDraw is called.
//        m_pRenderTarget->Resize(D2D1::SizeU(width, height));
//    }
//}


// uses screen dimensions and numLines const to fill a vector with lines
void DemoApp::generateLines(int const numLines, float width, float height, std::string color, int length)
{
    // length of lines
    // int length = 5;      // commented out to control variable elsewhere during testing

    // for loop to generate lines to fill vector
    for (int i{}; i < numLines; i++)
    {

        // angle used for creation of second set of coordinates
        int angle = Random::get(0, 360);

        // generates first point (set of x,y coords) based on a random number between
        // 0 and the width or height of the window
        int point1x{ Random::get(0, static_cast<int>(width)) };
        int point1y{ Random::get(0, static_cast<int>(height)) };

        // generates the second point (set of x,y coords) a fixed distance from the first, 
        // but in a random direction
        int point2x{ point1x + (static_cast<int>(std::cos(angle) * length)) };
        int point2y{ point1y + (static_cast<int>(std::sin(angle) * length)) };

        Line temp{ point1x, point1y, point2x, point2y, color };

        lines.push_back(temp);
    }

}

void DemoApp::outputLines()
{
    int count{};

    for (auto line : lines)
    {
        std::cout << "\tLine: --" << count << "--\n";

        std::cout << line.m_color << '\n';
        std::cout << line.m_startX << '\n';
        std::cout << line.m_startY << '\n';
        std::cout << line.m_endX << '\n';
        std::cout << line.m_endY << '\n';

        count++;
    }
}