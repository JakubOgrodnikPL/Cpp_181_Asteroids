// Asteroids Game.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "olc.h"

class Asteroids : public olc
{
public:
    Asteroids()
    {
        m_sAppName = L"Asteroids"
    }

private:
    struct sSpaceObject
    {
        float x;
        float y;
        float dx;
        float dy;
        int nSize;
    };

    vector<sSpaceObject> vecAsteroids;


protected:
    virtual bool OnUserCreate()
    {
        vecAsteroids.push_back({20.0f, 20.0f,8.0f,-6.0f, (int)16})


        return true;
    }

    virtual bool OnUserUpdate(float fElapsedTime)
    {
        Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, 0);

        for (auto& a : vecAsteroids)
        {
            a.x += a.dx * fElapseTime;
            a.y += a.dy * fElapseTime;
        }

        return true;
    }
};

int main()
{
    Asteroids game;
    game.ConstructConsole(160, 100, 8, 8);
    game.Start();
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
