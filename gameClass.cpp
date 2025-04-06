#include "gameClass.h"
GameData::GameData()
{
    name = "EMPTY";
    desc = "EMPTY";
    genre = "EMPTY";
    rating = 0.00;
}
GameData::GameData(string nam, string des, string gen, float rat)
{
    name = nam;
    desc = des;
    genre = gen;
    rating = rat;
}