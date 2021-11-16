#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>


// ifstream - wejsciowe do programu
// ofstream - wyjsciowe z programu
// fstream - wejsciowo-wyjsciowe
// << program --> honolulu
// >> honolulu --> program

using namespace std;

int losowanieCalkowitej(int p, int q)
{
    int liczba = rand()%(q-p+1);
    return liczba;
}

double losowanieRzeczywistej(int p, int q)
{
    double liczba = p+(double)rand()/RAND_MAX*(q-p);
    return liczba;
}

void zapis()
{
    ofstream plik;
    plik.open("dane.txt");
    for (int i = 2; i < 9; i++)
    {
        plik << i << endl;
    }
    plik.close();
}

void obslugaPliku()
{
    ifstream fin;
    fin.open("dane.txt" /*, tutaj drugi argument moze byc, domyslnie ios::app jest */);
    // ios::app         --> dopisywanie do konca pliku, append
    // ios::ate         --> przesuniecie aktualnej pozycji w pliku na koniec pliku
    // ios::in          --> otwarcie pliku do odczytu (domyslne dla ifstream)
    // ios::out         --> otwarcie pliku do zapisu (domyslne dla ofstream)
    // ios::binary      --> otwarcie pliku w trybie binarnym (domyslnie w trybie tekstowym)
    // ios::trunc       --> zapisywanie na dotychczasowej zawartosci pliku
    // ios::nocreate    --> otworzy jak plik juz istnieje
    // ios::noreplace   --> otworzy jak plik nie istnieje

    int x;
    int y;

    ofstream fout("wyniki.txt");
    while (!fin.eof()) //eof -- end of file
    {
        fin >> x >> y;
        fout << x * y << endl;
        fin.close();
        fout.close();
    }
}

void sortuj()
{
    int n = 10;
    int T[] = {2,1,3,7,6,8,3,4,9,0};
    double temp;
    for (int j = n - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (T[i]>T[i+1])
            {
                temp = T[i];
                T[i] = T[i+1];
                T[i+1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << T[i] << endl;
    }
}

int main()
{
    srand(time(NULL));
    cout << "Hello world!" << endl;
    int i = 0;
    while (i < 10)
    {
        cout << losowanieCalkowitej(10,100) << endl;
        i++;
    }
    cout << "-----------------------------" << endl;
    i = 0;
    while (i < 10)
    {
        cout << losowanieRzeczywistej(10,100) << endl;
        i++;
    }

    cout << "-----------------------------" << endl;

    struct osoba
    {
        int wiek;
        string imie;
    } Kowalski;

    Kowalski.imie = "Jan";
    Kowalski.wiek = 24;

    cout << "Chociaz ze " << Kowalski.imie << " ma juz " << Kowalski.wiek << " lata to dalej mieszka z rodzicami pasozyt by sie za robote chycil." << endl;
    cout << "-----------------------------" << endl;

    zapis();
    obslugaPliku();
    cout << "-----------------------------" << endl;
    sortuj();

    return 0;
}
