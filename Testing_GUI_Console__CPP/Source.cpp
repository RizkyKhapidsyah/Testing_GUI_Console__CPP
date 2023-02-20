#include <iostream>
#include <Windows.h>

// Fungsi untuk mengatur ukuran konsol
void SetConsoleWindowSize(int width, int height) {
    _COORD coord;
    coord.X = width;
    coord.Y = height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = height - 1;
    Rect.Right = width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

// Fungsi untuk mengatur posisi kursor
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    // Mengatur ukuran konsol menjadi 80x25
    SetConsoleWindowSize(80, 25);

    // Mengatur warna background dan teks
    system("color 17");

    // Menggambar bingkai pada layar konsol
    for (int i = 1; i <= 80; i++) {
        gotoxy(i, 1);
        std::cout << "\xBA";
        gotoxy(i, 25);
        std::cout << "\xBA";
    }
    for (int i = 2; i <= 24; i++) {
        gotoxy(1, i);
        std::cout << "\xC4";
        gotoxy(80, i);
        std::cout << "\xC4";
    }
    gotoxy(1, 1);
    std::cout << "\xC9";
    gotoxy(80, 1);
    std::cout << "\xBB";
    gotoxy(1, 25);
    std::cout << "\xC8";
    gotoxy(80, 25);
    std::cout << "\xBC";

    // Menambahkan teks pada layar konsol
    gotoxy(20, 5);
    std::cout << "Halo";
    gotoxy(10, 7);
    std::cout << "Ini adalah contoh GUI bergaya Turbo Pascal";
    gotoxy(20, 9);
    std::cout << "Untuk Pembelajaran";

    // Menunggu input dari user sebelum menutup konsol
    std::cin.get();

    return 0;
}
