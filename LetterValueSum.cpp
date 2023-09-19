#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> words;
std::vector<int> amountOfTimes;

enum alphabet
{
    empty = 0,
    a = 1,
    b = 2,
    c = 3,
    d = 4,
    e = 5,
    f = 6,
    g = 7,
    h = 8,
    i = 9,
    j = 10,
    k = 11,
    l = 12,
    m = 13,
    n = 14,
    o = 15,
    p = 16,
    q = 17,
    r = 18,
    s = 19,
    t = 20,
    u = 21,
    v = 22,
    w = 23,
    x = 24,
    y = 25,
    z = 26
};

int lettersum(std::string thing)
{
    int size = thing.size();
    for(int i = 0; i < size; i++)
    {
        std::cout << thing[i] << std::endl;
    }
    for(int i = 0; i < size; i++)
    {
        std::cout << (char)thing[i] << std::endl;
    }
    for(int i = 0; i < size; i++)
    {
        std::cout << (int)thing[i] << std::endl;
    }
    return 0;
}

void saveInput()
{
    std::ifstream myfile;
    myfile.open("Input.txt");
    if(myfile.is_open())
    {
        std::string line;
        while(getline(myfile,line))
        {
            words.push_back(line);
        }
    }
    myfile.close();
}

void saveSums()
{

}

int main()
{
    //saveInput();
    saveSums();
    lettersum("a");
}
