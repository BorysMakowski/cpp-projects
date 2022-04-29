/*
program to decode a message coded with caesars cipher
input: text file containing upper and lower case letters
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
string m, mm;

float temp;
float chis[26] = { 0 };
float minchi = 10000;
int suskey;
int t = 0;

string decesar(string m, char k)
{
    string c;
    c.resize(m.length());
    if (k >= 'a' && k <= 'z')
        k -= 'a';
    else if (k >= 'A' && k <= 'Z')
        k -= 'A';
    else if (k < 0 || k>25)
    {
        cout << "key out of range";
        return "failed";
    }
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == ' ')
        {
            c[i] = ' ';
        }
        else
        {
            if (m[i] >= 'a' && m[i] <= 'z')
            {
                m[i] -= 'a';
                m[i] -= k;
                if ((m[i] - k) < 0)
                    m[i] += 26;
                c[i] = m[i] % 26;
                c[i] += 'a';
            }
            else if (m[i] >= 'A' && m[i] <= 'Z')
            {
                m[i] -= 'A';
                m[i] -= k;
                if ((m[i] - k) < 0)
                    m[i] += 26;
                c[i] = m[i] % 26;
                c[i] += 'A';
            }
            else
            {
                c[i] = m[i];
            }
        }
    }
    return c;
}


float chi(string m)
{
    float CHI = 0;
    float c[26] = { 0 };
    float e[26] = { 8.087,1.493,2.781,4.253,12.702,2.228,2.015,6.094,6.966,0.153,0.772,4.094,2.587,6.749,7.507,1.929,0.096,5.987,6.234,9.056,2.758,0.978,2.360,0.150,1.974,0.074 };
    float temp;
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] >= 'a' && m[i] <= 'z')
            c[(int)m[i] - 'a']++;
        if (m[i] >= 'A' && m[i] <= 'Z')
            c[(int)m[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++)
    {
        t += c[i];
    }
    for (int i = 0; i < 26; i++)
    {
        c[i] = c[i] / t;
        e[i] /= 100;
        temp = c[i] - e[i];
        temp *= temp;
        temp /= e[i];
        CHI += temp;
    }
    return CHI;
}



int main()
{
    ifstream t("dane.txt");
    string m((istreambuf_iterator<char>(t)),
        istreambuf_iterator<char>());

    for (char key = 'a'; key < 'z'; key++)
    {
        mm = decesar(m, key);
        chis[(int)(key - 'a')] = chi(mm);
        //cout << chis[(int)(key - 'a')] << "    " << key << std::endl;
        if (chis[(int)(key - 'a')] < minchi)
        {
            minchi = chis[(int)(key - 'a')];
            suskey = key;
        }

    }
    cout << "--------------------------" << endl;

    cout << "Smallest chi: " << minchi << endl;
    cout << "Podejrzewany klucz: " << (char)suskey << endl;
    mm = decesar(m, (char)suskey);
    cout << "Odszyfrowany tekst:" << std::endl;
    cout << mm << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Tekst przed odszyfrowaniem:" << std::endl;
    cout << m << endl;

    return 0;
}

