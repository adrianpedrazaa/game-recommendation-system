#include "headers.h"
void loadData()
{

    ifstream readF;
    bool exists = false;
    string fileName;
    string line;
    string gName;
    string gDesc;
    string gGenre;
    string toStore;
    float gRate;
    int itter1 = 0, itter2;
    //Checks if file exists loops until valid file is entered.
    while(exists == false)
    {
        cout << "\nPlease enter the file name: ";
        cin >> fileName;
        readF.open(fileName);
        if(readF)
        {
            exists = true;
        }
        else
        {
            cout << "\nFile not found";
            readF.close();
        }
    }

    while(!readF.eof())
    {
        getline(readF, line);
        itter1 = 0;
        while(itter1 < 4)
        {
            itter2 = 0;
            while(line[itter2] != ',')
            {
                toStore += line[itter2];
                itter2++;
            }
            ++itter1;
            ++itter2;
            if(itter1 == 0)
            {
                gName = toStore;
            }
            else if(itter1 == 1)
            {
                
            }

        }
    }
    readF.close();
}
int main()
{
    int selection;
    bool quit = false;
    while(quit == false)
    {   
        cout << "Please enter the number of your selection\n"
            << "1: Load data set\n" 
            << "2: View games by genre\n"
            << "3: Search for by feel\n"
            << "4: Quit\n";
        switch(selection)
        {
            case 1:
                loadData();
        }


    }
    return 0;    
}