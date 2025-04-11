#include "headers.h"
class GameData
{
    public:
    void print();
    //Not worth using
    bool vectorSearch(string);
    //void vecQuickSort(unsigned int, unsigned int);
    //unsigned int partition(unsigned int, unsigned int);
    GameData();
    GameData(int, string, vector<string>, float);
    GameData *next;
    GameData *previous;
    private:
        int id;
        string name;
        vector<string> tags;
        float rating;
        bool sortStart;

        
};