#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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

void findSum319(std::string word, int lettersum)
{
    if(lettersum == 319)
    {
        std::cout << "The number with 319 is " << word << std::endl;
    }
}

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

    // Quick and easy way to find 319
    // TODO: could make this better to allow user to find any number
    findSum319(word, lettersum);
    
    return lettersum;
}

void findWordsForSum(int sum)
{
    //If I were to expand the find319 functionality this is 
    //where I would do it
    //current plan
    //rather than save an int to map, we would save an array
    //then here we could give the map->second and iterate through
    //to give all the words and return array.size to give amount
}

void findWordsBySumAndLength(int sum, int len)
{
    //prompt 4
}

void findNoLettersInCommon()
{
    //prompt 5
    //if we save a list with all the letters in common in a map
    //then we just compare everylist with itslef and find
    //letters that each word has in common
    //the way I'm thinking this would be kind of slow
    //but it would do it
    //we only have to check lists with lengths greater than 1
}

void saveInput()
{
    std::ifstream myfile;
    //myfile.open("example.txt");
    //myfile.open("example2.txt");
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
    int value = 0;
    for(int i = 0; i < words.size(); i++)
    {
        value = (int)lettersum(words.at(i));
        amountOfTimes[value] += 1;
    }
}

int findOdds()
{
    int countOfOdds = 0;
    std::map<int,int>::iterator it = amountOfTimes.begin();
    while(it != amountOfTimes.end())
    {
        if(it->second % 2 != 0)
        {
            countOfOdds += 1;
        }
        it++;
    }
    return countOfOdds;
}

// should be easy
int findMostSums()
{
    std::map<int,int>::iterator it = amountOfTimes.begin();
    int greatestAmount = 0;
    int previousGreatestAmount = 0;
    int greatestSum = 0;

    while(it != amountOfTimes.end())
    {
        previousGreatestAmount = greatestAmount;
        greatestAmount = std::max(it->second, previousGreatestAmount);
        if(greatestAmount > previousGreatestAmount)
        {
            greatestSum = it->first;
        }
        it++;
    }

    return greatestSum;
}

int main()
{
    saveInput();
    saveSums();

    int odds = findOdds();
    std::cout << "odds = " << odds << std::endl;

    int greatestsum = findMostSums();
    std::cout << "the sum that shows up the most is " << greatestsum << std::endl;
    std::cout << "And it shows up " << amountOfTimes[greatestsum] << " times" << std::endl;

    //prompt6
    //as you compare each word, check it has a different sum and length
    //to each one after it??? don't know yet 

    return 0;
}
