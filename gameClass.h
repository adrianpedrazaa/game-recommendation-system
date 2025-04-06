#include "headers.h"
class GameData
{
    public:
    GameData();
    GameData(string, string, string, float);
    private:
        string name;
        string desc;
        string genre;
        float rating;
        
};