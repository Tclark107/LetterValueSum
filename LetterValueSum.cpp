#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> words;
std::map <int,int> amountOfTimes;

//I don't know if I should use this
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

int lettersum(std::string word)
{
    int size = word.size();
    int lettersum = 0;
    // size - 1 because the last value is carrage return
    // is there an empty space after a c++ string??
    // the right way to do this would be to strip whitespace off these
    // I'm cheating for speed
    // TODO: strip white space
    // I can cheat because I know what Input I am getting
    for(int i = 0; i < size-1; i++)
    {
        lettersum += (int)word[i] - 96;
    }
    return lettersum;
}

void findWordsForSum(int sum)
{

}

void saveInput()
{
    std::ifstream myfile;
    //myfile.open("example.txt");
    myfile.open("example2.txt");
    //myfile.open("Input.txt");
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
    int value = 0;
    for(int i = 0; i < words.size(); i++)
    {
        value = (int)lettersum(words.at(i));
        amountOfTimes[value] += 1;
    }
}

int main()
{
    saveInput();
    saveSums();
    return 0;
}
