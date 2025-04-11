#include "headers.h"
#include "gameList.h"
using namespace std;
//Function for loading in file
void loadData(GameList &games)
{

    ifstream ofile;
    string theFile;
    bool exists = false;
    string line;
    string gName;
    vector<string> gTags;
    string capt;
    int id = 1;
    int comCount = 0;
    float gRate;
    
    //Test
    //vector<GameData*> testvec;
    
    //Loops until a valid file is entered
    while(exists == false)
    {
        cout << "\nPlease enter the file name: ";
        cin >> theFile;
        ofile.open(theFile);
        if(ofile)
        {
            exists = true;
            cout << "\nFile Loading\n";
        }
        else
        {
            cout << "\nFile Not Found\n";
        }
    }

    //Populates Linked list with games from file
    while(!ofile.eof())
    {
        comCount = 0;
        getline(ofile, line);
        
        //Stores .CSV file values based on the number of commas encounterd
        for(int i = 0; i < line.length(); ++i)
        {
            if(line[i] != ',')
            {
                capt += line[i];
                if(i == line.length() - 1)
                {
                    gTags.push_back(capt);
                    capt = "";
                }
            }
            else
            {
                ++comCount;
                if(comCount == 1)
                {
                    gName = capt;
                }
                else if(comCount == 2)
                {
                    gRate = stof(capt);
                }
                else if(comCount >= 3)
                {
                    gTags.push_back(capt);
                }
                capt = "";
            }
        }
        //Creates Gamedata object and stores in Linked List
        games.push_front(new GameData(id, gName, gTags, gRate));
       
        //temp to test
        //testvec.push_back(new GameData(id, gName, gTags, gRate));

        //Reset temp Variables increment id
        //gTags.clear();

        //Game ID incremented
        ++id;
    }
    ofile.close();
    cout << "\nFile loaded\n";

    //Temp to test
    /*for(unsigned int i = 0; i < testvec.size(); ++i)
    {
        testvec[i]->print();
    }
    cout << endl;
    for(unsigned int i = 0; i < testvec.size(); ++i)
    {
        cout << testvec[i] << endl;
        delete testvec[i];
        
    }
    testvec.clear();
    */
}
//Function for the games menu to make main prettier
void vgamesMenu(GameList &games)
{
    int choice; 
    bool correct = false;
    //Loops until valid choice is entered
    while(correct == false)
    {
        cout << "\nPlease enter the number of your selection"
            << "\n1:View games by rating"
            << "\n2:View games alphabetically"
            << "\n3:View games by a genre"
            << "\n4:Search for game by name"
            << "\n: ";
        cin >> choice;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "\nERROR: Invalid Choice\n";
        }
        else if(choice < 1 || choice > 4)
        {
            cout << "\nERROR: Invalid Choice\n";
        }
        else
        {
            correct = true;
        }
    }
    //Switch for user's choice
    switch(choice)
    {
        //Prints list thats sorted by rating
        case 1:
            if(games.alphaSorted == true)
            {
                games.quicksortRating();
            }
            games.printList();
        break;
        //Prints list thats sorted alphabetically
        case 2:
            if(games.alphaSorted == false)
            {
                games.quicksortAlph();
            }
            games.printList();
        break;
        //Calls Genre search function -> allows user to search list for a genre and displays games of that type
        case 3:
            games.genreSearch();
        break;  
        //Sorts games alphabetically and allows user to view a specific title
        case 4:
            if(games.alphaSorted == false)
            {
                games.quicksortAlph();
            }
            games.nameSearch();
    }

}
int main()
{
    GameList games;
    string aFile;
    int choice;
    bool quit = false;
    bool correct = false;
    
    //Loops until user types 3 to quit program
    while(quit == false)
    {   
        //Loops until a valid choice is entered
        while(correct == false)
        {
            cout << "\nPlease enter the number of your selection\n"
                << "1: Load data set\n" 
                << "2: View games\n"            
                << "3: Quit\n"
                << ": ";
                cin >> choice;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "\nERROR: Invalid Choice\n";
                }
                else if(choice < 1 || choice > 3)
                {
                    cout << "\nERROR: Invalid Choice\n";
                }
                else
                {
                    correct = true;
                }
            }
        //Switch for users choice
        switch(choice)
        {
            //Loads data file
            case 1:
                loadData(games);
            break;
            //Opens the view games menu 
            case 2:
                vgamesMenu(games);
            break;
            //Quits program
            case 3:
                quit = true;
            break;
        }
        //Re-enables Bad user while loop 
        correct = false;
    }
    return 0;    
}