#include "headers.h"
class GameData
{
    public:
    //Prints node data
    void print();
    //Searches linearly to see if vector holds genre
    bool vectorSearch(string);
    
    /*Not worth using kept just in case
    void vecQuickSort(unsigned int, unsigned int);
    unsigned int partition(unsigned int, unsigned int);
    */
    //Default Constructor
    GameData();
    //Parameterized Constructor
    GameData(int, string, vector<string>, float);
    //Node Pointers
    GameData *next;
    GameData *previous;
    
    string name;            //Game name from .CSV
    private:
        int id;                 //Game ID assigned at file loading
        vector<string> tags;    //Vector of games tags 
        float rating;           //Game rating from .CSV
        
        bool sortStart;        

        
};