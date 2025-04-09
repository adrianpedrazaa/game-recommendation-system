#include "headers.h"
class GameData
{
    public:
    void print();
    GameData();
    GameData(int, string, vector<string>, float);
    private:
        int id;
        string name;
        vector<string> tags;
        float rating;
        
};