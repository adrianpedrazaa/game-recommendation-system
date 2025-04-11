#include "gameClass.h"
GameData::GameData()
{
    name = "EMPTY";
    rating = 0.00;
}
GameData::GameData(int ids, string nam, vector<string> tVec, float rat)
{
    id = ids;
    name = nam;
    tags = tVec;
    rating = rat;
}
void GameData::print()
{
    cout << "\nId: " << id
         << "\nName: " << name
         << "\nTags: ";
    for(unsigned int i = 0; i < tags.size(); ++i)
    {
        cout << tags[i];
        if(i != tags.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "\nRating: " << rating;
}
int GameData::partition(unsigned int top, unsigned int bottom)
{
    unsigned int itt;
    int pivot = tags[top].length();
    
}
void GameData::vecQuickSort()
{

}
bool GameData::vectorSearch(string genre)
{

}