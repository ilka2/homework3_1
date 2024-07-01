#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Parser
{
    string s; //считанная строка
    int count;  //число адресов

    vector<string> address; // здесь хранятся адреса

    void ReadFile()
    {
        ifstream read("in.txt");

        if (read.is_open())
        {
            read >> s;
            count = stoi(s);

            for (int i = 0; i < count; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    read >> s;
                    address.push_back(s);
                }
            }
            read.close();
        }
        else
        {
            cout << "Файл не найден :(" << endl;
        }
    }

    void WriteFile()
    {
        ofstream write("out.txt");

        if (write.is_open())
        {
            write << count << endl;

            for (int i = count; i > 0; i--)
            {
                write << address[i * 4 - 4] << ", " << address[i * 4 - 3] << ", " << address[i * 4 - 2] << ", " << address[i * 4 - 1] << endl;
            }

            write.close();
        }
        else
        {
            cout << "Что-то пошло не по плану" << endl;
        }
    }
public:
    void Rewrite()
    {
        ReadFile();
        WriteFile();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Parser parser;
    parser.Rewrite();
}