#include "headers.h"
class GameData
{
    public:
    void print();
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