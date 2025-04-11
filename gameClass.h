#include "headers.h"
class GameData
{
    public:
    void print();
    bool vectorSearch(string);
    void vecQuickSort();
    int partition(unsigned int, unsigned int);
    GameData();
    GameData(int, string, vector<string>, float);
    GameData *next;
    GameData *previous;
    private:
        int id;
        string name;
        vector<string> tags;
        float rating;

        
};