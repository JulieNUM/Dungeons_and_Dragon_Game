#if false
#include "characterPlay.hpp"
#include <iostream>
//#include "consoleCharacterObserver.hpp"
using namespace std;

/*
observer
Part1_Character % 
g++ -o aa characterMain.cpp characterPlay.cpp consoleCharacterObserver.cpp -std=c++11
./aa
*/

//! main() function.
//! it does the following:
//! 1. Ask user to enter a character name
//! 2. Enter the choice for character class
//! 3. Dispay the character info at level 1
//! 4. Gain the experience(1000)
//! 5. Display the character info after gain experience (900)
int main() {
    string playerName;
    int fighterTypeChoice;
    bool startGame=true;

    // //以下四行用于测试直接读取历史存档的character file，然后展示数据
    // string filename="11";
    // Character character;
    // character.loadFromFile(filename);
    // cout<<"\n"<<endl;
    // character.displayInfo();



    // ConsoleCharacterObserver console;
    // character.addObserver(&console);
    // character.updateCharacter();

    // //读取character 更新之后的数据
    // character.loadFromFile(filename);
    // exit(0);

    //这里是开始一个新的Character的生成
    while(startGame){
        cout<<"-----------Welcome to Game------------"<<endl;
        cout<<"\nPlease enter any key to start game.";
        cin.ignore();  // Ignore any previous newline characters in the buffer
        cin.get();     // Wait for user to press any key
        cout<<"\n";
        //system("clear");
        cout<<"-------Create your character, please-------"<<endl;
         //! Get player name
    cout << "\nEnter your character's name: ";
    cin >> playerName;

    // ! Get character class choice
    cout << "\nChoose character fighter type (1: Bully, 2: Nimble, 3: Tank): ";
    cin >> fighterTypeChoice;
    

    //! Create a character
    Character playerCharacter(playerName);


    //playerCharacter.setClassChoice(classChoice);
    playerCharacter.setfighterChoice(fighterTypeChoice);
    //int hitDice= playerCharacter.getHitDice();

  
    //cout<<"\nDepending on the class you choose, your default hit dice: "<<hitDice<<endl;


    //store the character information at file: the file name is playerName + '.txt'
    playerCharacter.saveToFile();
    
    
    //这里用于测试新建的character  .txt的数据是否能读取，并且可以跟terminal里显示的数据进行比较
    // it is used for load character information from file
    //playerCharacter.loadFromFile(playerName);

    
    // Prompt user to press any key to continue
    cout << "\n\nNow that your character has been created, press any key to see your character information....";
    cin.ignore();  // Ignore any previous newline characters in the buffer
    cin.get();     // Wait for the user to press any key


    //! Display initial character info
    cout << "\nInitial Character Info:\n";
    playerCharacter.displayInfo();


    cout<<"\n\nCheck out the updated character information. Please any key to continue..."<<endl;
    cin.ignore();  // Ignore any previous newline characters in the buffer
    cin.get();     // Wait for user to press any key
    cout<<"\n";
    cout<<"\n***********************************************\n\n";

        // Prompt user to press any key to see updated information
    cout << "\n\nNow, you have gained 1000 experience points. Press any key to see your information.";
    cin.ignore();  // Ignore any previous newline characters in the buffer
    cin.get();     // Wait for user to press any key


    // //! create a observer to update value
    // ConsoleCharacterObserver consoleObserver;
    // playerCharacter.addObserver(&consoleObserver);
    // playerCharacter.updateCharacter();

    //读取character 更新之后的数据
    //playerCharacter.loadFromFile(playerName);
    return 0;
   

    }
   
}


#endif