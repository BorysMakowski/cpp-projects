/*
Wersja 1.0   14.06.2021    Borys Makowski
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


struct lantern
{
    long x=0;
    long y=0;
    double angle = 0;

    bool operator < (const lantern& other) const
    {
        if (y == other.y)
            return (x < other.x);
        return (y < other.y);
    }
};

bool anglesorter(lantern a, lantern b) 
{ 
        return a.angle < b.angle; 
}

class Lanterns
{
public:
    Lanterns(int _numofbig)
    {
        numofbig = _numofbig;
        numofsmall = 0;

        small = new lantern[numofsmall];//initialised to get rid of warning
        big = new lantern[numofbig];
    }
    ~Lanterns()
    {
        delete[] big;
        delete[] small;
    }
    void set_numofsmall(int _numofsmall)
    {
        delete[] small;
        numofsmall = _numofsmall;
        small = new lantern[numofsmall];
    }
    void add_big(int place, lantern in)
    {
        big[place] = in;
    }
    void add_small(int place, lantern in)
    {
        small[place] = in;
    }
    void show_big()
    {
        std::cout << "Big lanterns: " << numofbig << std::endl;
        for (int i = 0; i < numofbig; i++)
        {
            std::cout << big[i].x << ", " << big[i].y << ", kat: " << big[i].angle << std::endl;
        }
    }
    void show_small()
    {
        std::cout << "Small lanterns: " << numofsmall << std::endl;
        for (int i = 0; i < numofsmall; i++)
        {
            std::cout << small[i].x << ", " << small[i].y <<", kat: "<< small[i].angle << std::endl;
        }
    }

    lantern find_lowest_y()
    {
        std::sort(big, big + numofbig);
        lantern result;
        result.x = big[0].x;
        result.y = big[0].y;
        return result;
    }

    void move_lanterns(long _x, long _y)
    {
        for (int i = 0; i < numofbig; i++)
        {
            big[i].x += _x;
            big[i].y += _y;
        }
    }

    void sort_byangle()
    {
        for (int i = 0; i < numofbig; i++)
        {
            double d = (double)abs(big[i].x) + (double)abs(big[i].y);

            if (big[i].x >= 0 && big[i].y >= 0)
                big[i].angle = (big[i].y / d);
            else if (big[i].x < 0 && big[i].y >= 0)
                big[i].angle = 2 - (big[i].y / d);
            else if (big[i].x > 0 && big[i].y < 0)
                big[i].angle = 2 + (abs(big[i].y) / d);
            else if (big[i].x >= 0 && big[i].y < 0)
                big[i].angle = 4 - (abs(big[i].y) / d);
        }
        std::sort(big+1, big + numofbig, anglesorter);
    }


    bool sidechecker(lantern T1, lantern T2, lantern X)//sprawdza czy X jest po prawej stronie wektora od T1 do T2
    {
        long long result = ((((long long)T2.x - (long long)T1.x) * ((long long)X.y - (long long)T1.y)) - (((long long)T2.y - (long long)T1.y) * ((long long)X.x - (long long)T1.x)));
        if (result < 0)
            return 1;
        else
            return 0;
        // zwraca 1 jezeli X po prawej
    }

    void find_convexhull()
    {
        for (int i = 0; i < numofbig; i++)
            big_vector.push_back(big[i]);

        convexhull.push_back(big[0]);
        convexhull.push_back(big[1]);

        unsigned int i = 0;
        while (i < (big_vector.size() - 3))
        {
            lantern A = big_vector.at(i+1);
            lantern B = big_vector.at(i+2);
            lantern C = big_vector.at(i+3);
            if (sidechecker(A,C,B)==1)//B jest poza trojkatem (0,0), A, C
            {
                convexhull.push_back(B);
                i++;
            }
            else
            {
                big_vector.erase(big_vector.begin() + (i+2));
                if (i != 0)
                    i--;
            }

        }
        delete[] big;
        numofbig = big_vector.size();
        big=new lantern[numofbig];
        for (int i = 0; i < numofbig; i++)
            big[i]=big_vector.at(i);
    }

    void finalcounter()
    {
        int result = 0;
        for (int i = 0; i < numofsmall; i++)
        {
            int suma = 0;
            for (int j = 0; j < numofbig; j++)
            {
                if (j < (numofbig-1))
                {
                    suma += sidechecker(big[j], big[j + 1], small[i]);
                }
                    
                else
                {
                    suma += sidechecker(big[j], big[0], small[i]);
                }
                    
            }
            if (suma == 0)
            {
                result++;
            }
                
           
        }
        std::cout << result << std::endl;
    }

private:
    int numofbig;
    int numofsmall;

    lantern* big;
    lantern* small;
    std::vector<lantern> big_vector;
    std::vector<lantern> convexhull;
};

std::vector<std::string> DivBySpace(std::string str) {
    std::vector<std::string> temp;
    std::string word = "";
    for (auto x : str) {
        if (x == ' ') {
            temp.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    temp.push_back(word);
    return temp;
}

int main()
{

    std::string temp;
    lantern templantern;

    std::vector<std::string> params;

    int numofbig;
    int numofsmall;

    std::getline(std::cin, temp);
    numofbig = stoi(temp);

    Lanterns* OBIEKT = new Lanterns(numofbig);

    for (int i = 0; i < numofbig; i++)
    {
        std::getline(std::cin, temp);
        params = DivBySpace(temp);

        templantern.x = stol(params.at(0));
        templantern.y = stol(params.at(1));

        OBIEKT->add_big(i, templantern);
    }

    std::getline(std::cin, temp);
    numofsmall = stoi(temp);
    OBIEKT->set_numofsmall(numofsmall);

    for (int i = 0; i < numofsmall; i++)
    {
        std::getline(std::cin, temp);
        params = DivBySpace(temp);

        templantern.x = stol(params.at(0));
        templantern.y = stol(params.at(1));

        OBIEKT->add_small(i, templantern);
    }

    lantern vectortomoveby = OBIEKT->find_lowest_y();

    OBIEKT->move_lanterns(-vectortomoveby.x, -vectortomoveby.y);
    OBIEKT->sort_byangle();
    OBIEKT->find_convexhull();
    OBIEKT->move_lanterns(vectortomoveby.x, vectortomoveby.y);

    OBIEKT->finalcounter();


    delete OBIEKT;
}


