#pragma once

void Color_Pixel_Julia_1(size_t rx, int ix, HDC& hdc)
{
    const size_t w{ 1000 };

    auto swapBlueRed = [](uint32_t x)
    {
        uint32_t red = x >> 16;
        uint32_t blue = (x << 16) & 0xff0000;
        uint32_t green = x & 0x00ff00;
        return (red | green | blue);
    };

    auto Set_Pixel = [&hdc, &swapBlueRed](int i, const char* s) { SetPixel(hdc, i % w + 50, i / w + 50, swapBlueRed(color_select[s])); };

    if (rx > 998)
        Set_Pixel(ix, "Yellow");
    else if (rx > 150)
        Set_Pixel(ix, "Cobalt");
    else if (rx > 100)
        Set_Pixel(ix, "Light Blue");
    else if (rx > 75)
        Set_Pixel(ix, "Green");
    else if (rx > 50)
        Set_Pixel(ix, "Red");
    else if (rx > 45)
        Set_Pixel(ix, "Maroon");
    else if (rx > 40)
        Set_Pixel(ix, "Mahogany");
    else if (rx > 37)
        Set_Pixel(ix, "Blue");
    else if (rx > 36)
        Set_Pixel(ix, "Red");
    else if (rx > 35)
        Set_Pixel(ix, "Light yellow");
    else if (rx > 28)
        Set_Pixel(ix, "Maroon");
    else if (rx > 25)
        Set_Pixel(ix, "Cyan");
    else if (rx > 23)
        Set_Pixel(ix, "Cobalt");
    else if (rx > 21)
        Set_Pixel(ix, "Crimson");
    else if (rx > 20)
        Set_Pixel(ix, "Maya blue");
    else if (rx > 19)
        Set_Pixel(ix, "Coral pink");
    else if (rx > 18)
        Set_Pixel(ix, "Copper rose");
    else if (rx > 17)
        Set_Pixel(ix, "Mahogany");
    else if (rx > 16)
        Set_Pixel(ix, "Lime green");
    else if (rx > 15)
        Set_Pixel(ix, "Banana yellow");
    else if (rx > 13)
        Set_Pixel(ix, "Light blue");
    else if (rx > 10)
        Set_Pixel(ix, "Green");
    else if (rx > 5)
        Set_Pixel(ix, "Violet");
    else
        Set_Pixel(ix, "White");
}

void Color_Pixel_Julia_2(size_t rx, int ix, HDC& hdc)
{
    const size_t w{ 1000 };

    auto swapBlueRed = [](uint32_t x)
    {
        uint32_t red = x >> 16;
        uint32_t blue = (x << 16) & 0xff0000;
        uint32_t green = x & 0x00ff00;
        return (red | green | blue);
    };

    auto Set_Pixel = [&hdc, &swapBlueRed](int i, const char* s) { SetPixel(hdc, i % w + 50, i / w + 50, swapBlueRed(color_select[s])); };
 
    if (rx > 19999)
        Set_Pixel(ix, "Light blue");
    else if (rx > 8000)
        Set_Pixel(ix, "Green");
    else if (rx > 6000)
        Set_Pixel(ix, "Green");
    else if (rx > 5000)
        Set_Pixel(ix, "Blue");
    else if (rx > 500)
        Set_Pixel(ix, "Yellow");
    else if (rx > 205)
        Set_Pixel(ix, "Red");
    else if (rx > 200)
        Set_Pixel(ix, "Blue");
    else if (rx > 165)
        Set_Pixel(ix, "Light blue");
    else if (rx > 150)
        Set_Pixel(ix, "Cobalt");
    else if (rx > 75)
        Set_Pixel(ix, "Green");
    else if (rx > 45)
        Set_Pixel(ix, "Maroon");
    else if (rx > 30)
        Set_Pixel(ix, "Yellow");
    else if (rx > 13)
        Set_Pixel(ix, "Cobalt");
    else if (rx > 10)
        Set_Pixel(ix, "Green");
    else
        Set_Pixel(ix, "White");
}

void Color_Pixel_Julia_3(size_t rx, int ix, HDC& hdc)
{
    const size_t w{ 1000 };

    auto swapBlueRed = [](uint32_t x)
    {
        uint32_t red = x >> 16;
        uint32_t blue = (x << 16) & 0xff0000;
        uint32_t green = x & 0x00ff00;
        return (red | green | blue);
    };

    auto Set_Pixel = [&hdc, &swapBlueRed](int i, const char* s) { SetPixel(hdc, i % w + 50, i / w + 50, swapBlueRed(color_select[s])); };

    if (rx > 19999)
        Set_Pixel(ix, "Light blue");
    else if (rx > 8000)
        Set_Pixel(ix, "Dark cerulean");
    else if (rx > 6000)
        Set_Pixel(ix, "Dark cerulean");
    else if (rx > 5000)
        Set_Pixel(ix, "Blue");
    else if (rx > 500)
        Set_Pixel(ix, "Light blue");
    else if (rx > 205)
        Set_Pixel(ix, "Prussian blue");
    else if (rx > 200)
        Set_Pixel(ix, "Blue");
    else if (rx > 165)
        Set_Pixel(ix, "Light blue");
    else if (rx > 150)
        Set_Pixel(ix, "Cobalt");
    else if (rx > 75)
        Set_Pixel(ix, "Dark cerulean");
    else if (rx > 45)
        Set_Pixel(ix, "Pastel blue");
    else if (rx > 30)
        Set_Pixel(ix, "Dark cyan");
    else if (rx > 13)
        Set_Pixel(ix, "Cobalt");
    else if (rx > 10)
        Set_Pixel(ix, "Dark powder blue");
    else
        Set_Pixel(ix, "White");
}
