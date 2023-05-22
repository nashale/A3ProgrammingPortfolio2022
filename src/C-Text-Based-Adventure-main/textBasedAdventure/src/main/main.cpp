#include "futuristic.h"
#include "historical.h"
#include "victorian.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

// Nash Hale and Jax Jameson on the code while Carson Medsker, Park James, Aiden
// Harris, Jesse Stallings are on scripts

using namespace std;
ifstream background_file("background.txt");
vector<string> background;
ifstream victorian_file("victorian.txt");
vector<string> victorian;
ifstream futuristic_file("futuristic.txt");
vector<string> futuristic;
ifstream historical_file("historical.txt");
vector<string> historical;
ifstream asciiArt_file("asciiArt.txt");
vector<string> asciiArt;
ifstream gameOverWin_file("gameOverWin.txt");
vector<string> gameOverWin;
ifstream gameOverFail_file("gameOverFail.txt");
vector<string> gameOverFail;

int main() {
  Victorian vic;
  Futuristic future{};
  Historical history;
  string line;
  string characterName;
  string travelInput;
  string input; // which method we are using
  string inputTwo;
  int inp; // int that is changed using vic.v
  int questsCompleted = 0;
  bool gameEnd = false;
  bool key, dagger, holoscanner, explosives, fKey; // puzzle elements
  vic.v = 0;
  bool gameWin = false;
  bool gameFail = false;
  bool vicWin = false;
  bool futureWin = false;
  bool historyWin = false;
  bool steakKnife = false;
  while (getline(background_file, line)) { // background reading
    background.push_back(line);
  }
  while (getline(victorian_file, line)) {
    victorian.push_back(line);
  }
  while (getline(futuristic_file, line)) {
    futuristic.push_back(line);
  }
  while (getline(asciiArt_file, line)) {
    asciiArt.push_back(line);
  }
  while (getline(historical_file, line)) {
    historical.push_back(line);
  }
  while (getline(gameOverWin_file, line)) {
    gameOverWin.push_back(line);
  }
  while (getline(gameOverFail_file, line)) {
    gameOverFail.push_back(line);
  }
  gameEnd = false;
  dagger = false;
  key = false;

  cout
        << "Welcome to Text Based Adventure! Type your character's name now... "
           "\n";
    cin >> characterName;
    cout << background[0] + characterName + background[1] + "\n" + background[2]
         << endl;

  // begin user selections in designated storylines
  while (gameWin == false && gameFail == false) {
    if (vicWin == true && futureWin == true && historyWin == true) {
      gameWin = true;
      break;
      break;
    }
    cout << "Victorian, 1900s, Futuristic \n Choose your next location " +
                characterName + "\n";
    cin >> travelInput;

    cout
        << "You pick " + travelInput +
               " and suddenly everything goes black. \n While you go through "
               "the "
               "wormholes into other dimensions and places, you only fall out "
               "of "
               "your regular descent. After choosing your destination, you are "
               "granted with that location. Only you wake up in that place..."
        << endl;
   if ((travelInput == "Futuristic") || (travelInput == "futuristic") && futureWin == false) {
      fKey = false;
      holoscanner = false;
      explosives = false;
      gameEnd = false;
      future.v = 0;
      cout << futuristic[0] << endl;
      if (future.v < 20) {
        future.moveTo(1);
        cout << characterName << futuristic[1] << endl;
        while (future.v < 20 && gameEnd == false) {
          getline(cin, input);
          for (int x = 0; x < input.length(); x++) {
            towlower(input[x]);
          }
          if (input.substr(0, 9) == "move back") {
            future.moveBack();
            cout << futuristic[future.v] << endl;
          } else if (input.substr(0, 10) == "pickup key") {
            cout << "You have picked up the key to Unit 39" << endl;
             cout << "\033[1m" << asciiArt[0] << endl;
            cout << "\033[1m" << asciiArt[1] << endl;
            cout << "\033[1m" << asciiArt[2] << endl;
            cout << "\033[1m" << asciiArt[3] << endl;
            cout << "\033[1m" << asciiArt[4] << endl;
            cout << "\033[1m" << asciiArt[5] << "\033[0m" << endl;
            fKey = true;
          } else if (input.substr(0, 18) == "pickup holoscanner") {
            cout << "You have picked up the holoscanner" << endl;
            holoscanner = true;
          } else if (input.substr(0, 17) == "pickup explosives") {
            cout << "You have picked up the bundle or explosives" << endl;
            explosives = true;
          } else if (input.substr(0, 4) == "help") {
            future.help();
            cout << futuristic[future.v] << endl;
          } else if (input.substr(0, 7) == "move to") {
            inputTwo = input.substr(7, 8);
            inp = stoi(inputTwo);
            if (future.v == 4 && fKey == false && inp == 1) {
              cout << "You try to enter unit 39 but you don't have a key to "
                      "open "
                      "it up."
                   << endl;
            } else if (future.v == 4 && fKey == true && inp == 1) {
              future.moveTo(1);
              cout << futuristic[future.v] << endl;
            } else if (future.v == 3 && holoscanner == false && inp == 2) {
              cout << "you can't enter the warrhouse because you don't have a "
                      "holoscanner/keycard"
                   << endl;
            } else if (future.v == 3 && inp == 2) {
              inp += 1;
              future.moveTo(inp);
              cout << futuristic[future.v] << endl;
            } else if (future.v == 11 && explosives == false && inp == 1) {
              cout << "you do not have the explosives, you must move back"
                   << endl;
              cout << futuristic[future.v] << endl;
            } else if (future.v == 11 && explosives == true && inp == 1) {
              future.moveTo(inp);
              cout << futuristic[future.v] << endl;
              cout << "As you stand at the threshold of the shimmering portal, your heart brims with a mix of emotions. A sense of fulfillment washes over you, knowing you have completed your noble quest and achieved victory. The surrounding landscape, once teeming with fantastical creatures and breathtaking vistas, now fades into a blur. Reluctantly, you step forward, feeling the tingle of otherworldly energy as the portal engulfs you, transporting you back through the ethereal depths of the wormhole. As you traverse the swirling currents of time and space, a profound gratitude fills your being, for the experiences gained, the growth attained, and the legacy left behind. And as you emerge on the other side, returning to your own reality, you carry the spirit of your heroic journey, forever changed and forever inspired." << endl;
              questsCompleted += 1;
              futureWin = true;
              cout << "\033[0;37m" << "\n You have completed " <<
              questsCompleted << "/3 quests. " << endl;
              gameEnd = true;
              travelInput = "";
              break;
            } else if (future.v == 11 && inp == 2) {
              future.moveTo(2);
              cout << futuristic[future.v] << endl;
              gameFail = true;
              gameEnd = true;
              break;
            } else {
              future.moveTo(inp);
              cout << futuristic[future.v] << endl;
            }
          }
        }

      } else {
        cout << "error" << endl;
      }
    } else if ((travelInput == "Victorian") || (travelInput == "victorian") && vicWin == false) {
gameEnd = false;
      cout << victorian[0] << endl;
      if (vic.v < victorian.size()) {
        vic.moveTo(1);
        cout << characterName + victorian[vic.v] << endl;
        while (vic.v < 20 && gameEnd == false) {
          getline(cin, input);
          for (int x = 0; x < input.length(); x++) {
            towlower(input[x]);
          }
          if (input.substr(0, 9) == "move back") {
            vic.moveBack();
            cout << victorian[vic.v] << endl;
          } else if (input.substr(0, 10) == "pickup key") {
            cout << "You have picked up the key (move to 1/2)" << endl;
            cout << "\033[1m" << asciiArt[0] << endl;
            cout << "\033[1m" << asciiArt[1] << endl;
            cout << "\033[1m" << asciiArt[2] << endl;
            cout << "\033[1m" << asciiArt[3] << endl;
            cout << "\033[1m" << asciiArt[4] << endl;
            cout << "\033[1m" << asciiArt[5] << "\033[0m" << endl;
            key = true;
          } else if (input.substr(0, 13) == "pickup dagger") {
            cout << "You have picked up the dagger (move back)" << "\n" << endl;
            cout << "\033[0;93m" << asciiArt[17] << endl;
            cout << "\033[0;93m" << asciiArt[18] << endl;
            cout << "\033[0;93m" << asciiArt[19] << endl;
            cout << "\033[0;93m" << asciiArt[20] << endl;
            cout << "\033[0;93m" << asciiArt[21] << endl;
            cout << "\033[0;93m" << asciiArt[22] << endl;
            cout << "\033[0;93m" << asciiArt[23] << endl;
            cout << "\033[0;93m" << asciiArt[24] << endl;
            cout << "\033[0;93m" << asciiArt[25] << endl;
            cout << "\033[0;93m" << asciiArt[26] << endl;
            cout << "\033[0;93m" << asciiArt[27] << endl;
            cout << "\033[0;93m" << asciiArt[28] << endl;
            cout << "\033[0;93m" << asciiArt[29] << endl;
            cout << "\033[0;93m" << asciiArt[30] << endl;
            cout << "\033[0;93m" << asciiArt[31] << endl;
            cout << "\033[0;93m" << asciiArt[32] << endl;
            cout << "\033[0;93m" << asciiArt[33] << endl;
            cout << "\033[0;93m" << asciiArt[34] << endl;
            cout << "\033[0;93m" << asciiArt[35] << "\033[0m" << endl;
            dagger = true;
          } else if (input.substr(0, 4) == "help") {
            vic.help();
            cout << victorian[vic.v] << endl;
          } else if (input.substr(0, 7) == "move to") {
            inputTwo = input.substr(7, 8);
            inp = stoi(inputTwo);
            if (vic.v == 8 && key == true) {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
            } else if (vic.v == 8 && key == false) {
              cout << "You can't move here because you don't have the key. You "
                      "must move back now."
                   << endl;
            } else if (vic.v == 7 && inp == 1) {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
              gameEnd = true;

            } else if (vic.v == 11 && dagger == true && inp == 2) {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
              travelInput = "";
              gameEnd = true;
              vicWin = true;
              questsCompleted += 1;
            } else if (vic.v == 11 && dagger == false && inp == 2) {
              cout << "You can't kill the king because you don't have the "
                      "dagger. You "
                      "must move back now and assist the king."
                   << endl;
              cout << victorian[vic.v] << endl;
            } else if (vic.v == 11 && inp == 1) {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
              gameEnd = true;
              gameFail = true;
              break;
            } else {
              vic.moveTo(inp);
              cout << victorian[vic.v] << endl;
            }
          }
        }

      } else {
        cout << "error" << endl;
      }
    }  else if (travelInput == "1900s") {
      fKey = false;
      holoscanner = false;
      explosives = false;
      gameEnd = false;
      history.v = 0;
      cout << historical[0] << endl;
      if (history.v < 20) {
        history.moveTo(1);
        cout << characterName << historical[1] << endl;
        while (history.v < 20 && gameEnd == false) {
          getline(cin, input);
          for (int x = 0; x < input.length(); x++) {
            towlower(input[x]);
          }
          if (input.substr(0, 9) == "move back") {
            history.moveBack();
            cout << historical[history.v] << endl;
          } else if (input.substr(0, 18) == "pickup steak knife") {
            cout << "You have picked up the steak knife" << endl;
            steakKnife = true;
          } else if (input.substr(0, 4) == "help") {
            history.help();
            cout << historical[history.v] << endl;
          } else if (input.substr(0, 7) == "move to") {
            inputTwo = input.substr(7, 8);
            inp = stoi(inputTwo);
            if (history.v == 8 && steakKnife == false && inp == 1) {
              cout << "You try to beat up the guard with your bare fists but before you even get close he catches you and takes you away" << endl;
              gameEnd = true;
              gameFail = true;
            } else if (history.v == 9 && inp == 1) {
              history.moveTo(inp);
              cout<< historical[history.v]<< endl;
              questsCompleted +=1;
               cout << "\033[0;37m"
         << "\n You have completed " << questsCompleted << "/3 quests. "
         << endl;
              gameEnd = true;
              historyWin = true;
            } else if (history.v == 6 && inp == 1) {
              history.moveTo(inp);
              cout<< historical[history.v]<< endl;
              gameEnd = true;
              gameFail = true;
            } else if (history.v == 3 && holoscanner == false && inp == 2) {
              cout << "you can't enter the warrhouse because you don't have a "
                      "holoscanner/keycard"
                   << endl;
            }  else {
              history.moveTo(inp);
              cout << historical[history.v] << endl;
            }
          }
        }
      } else {
        cout << "error" << endl;
      }
    } else {
      cout << "that is not a viable input" << endl;
    };
  }
  if (gameWin == true) {
    cout << "\n" << endl;
    cout << "\033[0;93m" << gameOverWin[1] << endl;
    cout << "\033[0;93m" << gameOverWin[2] << endl;
    cout << "\033[0;93m" << gameOverWin[3] << endl;
    cout << "\033[0;93m" << gameOverWin[4] << endl;
    cout << "\033[0;93m" << gameOverWin[5] << endl;
    cout << "\033[0;93m" << gameOverWin[6] << endl;
    cout << "\033[0;93m" << gameOverWin[7] << endl;
    cout << "\033[0;93m" << gameOverWin[8] << endl;
    cout << "\033[0;93m" << gameOverWin[9] << endl;
    cout << "\033[0;93m" << gameOverWin[10] << endl;
    cout << "\033[0;93m" << gameOverWin[11] << endl;
    cout << "\033[0;93m" << gameOverWin[12] << endl;
    cout << "\033[0;93m" << gameOverWin[13] << endl;
    cout << "\033[0;93m" << gameOverWin[14] << endl;
    cout << "\033[0;93m" << gameOverWin[15] << endl;
    cout << "\033[0;93m" << gameOverWin[16] << endl;
    cout << "\033[0;93m" << gameOverWin[17] << endl;
    cout << "\033[0;93m" << gameOverWin[18] << endl;
    cout << "\033[0;93m" << gameOverWin[19] << endl;
    cout << "\033[0;93m" << gameOverWin[20] << endl;
    cout << "\033[0;93m" << gameOverWin[21] << endl;
    cout << "\033[0;93m" << gameOverWin[22] << endl;
    cout << "\033[0;93m" << gameOverWin[23] << endl;
    cout << "\033[0;93m" << gameOverWin[24] << endl;
    cout << "\033[0;93m" << gameOverWin[25] << endl;
    cout << "\033[0;93m" << gameOverWin[26] << endl;
    cout << "\033[0;93m" << gameOverWin[27] << endl;
    cout << "\033[0;93m" << gameOverWin[28] << endl;
    cout << "\033[0;93m" << gameOverWin[29] << endl;
    cout << "\033[0;93m" << gameOverWin[30] << endl;
    cout << "\033[0;93m" << gameOverWin[31] << endl;
    cout << "\033[0;93m" << gameOverWin[32] << endl;
    cout << "\033[0;93m" << gameOverWin[33] << endl;
    cout << "\033[0;93m" << gameOverWin[34] << endl;
    cout << "\033[0;93m" << gameOverWin[35] << endl;
    cout << "\033[0;37m"
         << "\n You have completed " << questsCompleted << "/3 quests. "
         << endl;
    if(questsCompleted == 3) {
      cout << "In a breathtaking display of courage and unwavering determination, you embarked on a remarkable journey that transcended the boundaries of time. Fearlessly, you faced three distinct quests, each rooted in a different timeline, and emerged triumphant in all. With your indomitable spirit, you ventured into the past, present, and future, wielding your skills and wisdom to combat the imminent threats that loomed over each era. Through your selfless acts, you unraveled the mysteries, mended the fractures, and extinguished the flames of chaos that threatened to consume these timelines. Your heroic deeds saved countless lives, mending the fabric of history and ensuring a future of hope, unity, and prosperity. Your name will forever be revered across the ages, a legend woven into the tapestry of time itself, reminding us of the extraordinary power of courage and compassion." << endl;
    }
    exit(0);
  } else if (gameFail == true) {
    cout << "\n" << endl;
    cout << "\033[0;93m" << gameOverFail[1] << endl;
    cout << "\033[0;93m" << gameOverFail[2] << endl;
    cout << "\033[0;93m" << gameOverFail[3] << endl;
    cout << "\033[0;93m" << gameOverFail[4] << endl;
    cout << "\033[0;93m" << gameOverFail[5] << endl;
    cout << "\033[0;93m" << gameOverFail[6] << endl;
    cout << "\033[0;93m" << gameOverFail[7] << endl;
    cout << "\033[0;93m" << gameOverFail[8] << endl;
    cout << "\033[0;93m" << gameOverFail[9] << endl;
    cout << "\033[0;93m" << gameOverFail[10] << endl;
    cout << "\033[0;93m" << gameOverFail[11] << endl;
    cout << "\033[0;93m" << gameOverFail[12] << endl;
    cout << "\033[0;93m" << gameOverFail[13] << endl;
    cout << "\033[0;93m" << gameOverFail[14] << endl;
    cout << "\033[0;93m" << gameOverFail[15] << endl;
    cout << "\033[0;93m" << gameOverFail[16] << endl;
    cout << "\033[0;93m" << gameOverFail[17] << endl;
    cout << "\033[0;93m" << gameOverFail[18] << endl;
    cout << "\033[0;93m" << gameOverFail[19] << endl;
    cout << "\033[0;93m" << gameOverFail[20] << endl;
    cout << "\033[0;93m" << gameOverFail[21] << endl;
    cout << "\033[0;93m" << gameOverFail[22] << endl;
    cout << "\033[0;93m" << gameOverFail[23] << endl;
    cout << "\033[0;93m" << gameOverFail[24] << endl;
    cout << "\033[0;93m" << gameOverFail[25] << endl;
    cout << "\033[0;93m" << gameOverFail[26] << endl;
    cout << "\033[0;93m" << gameOverFail[27] << endl;
    cout << "\033[0;93m" << gameOverFail[28] << endl;
    cout << "\033[0;93m" << gameOverFail[29] << endl;
    cout << "\033[0;93m" << gameOverFail[30] << endl;
    cout << "\033[0;93m" << gameOverFail[31] << endl;
    cout << "\033[0;93m" << gameOverFail[32] << endl;
    cout << "\033[0;93m" << gameOverFail[33] << endl;
    cout << "\033[0;93m" << gameOverFail[34] << endl;
    cout << "\033[0;93m" << gameOverFail[35] << endl;
    cout << "\033[0;93m" << gameOverFail[36] << endl;
    cout << "\033[0;93m" << gameOverFail[37] << endl;
    cout << "\033[0;93m" << gameOverFail[38] << endl;
    cout << "\033[0;93m" << gameOverFail[39] << endl;
    cout << "\033[0;93m" << gameOverFail[40] << endl;
    cout << "\033[0;37m" << gameOverFail[42] << endl;
  }
  background_file.close();
  victorian_file.close();
  futuristic_file.close();
  historical_file.close();
  asciiArt_file.close();
  gameOverWin_file.close();
  gameOverFail_file.close();

  return 0;
}

// # colors
// Red = "\033[0;31m"
// Green = "\033[0;32m"
// Orange = "\033[0;33m"
// Blue = "\033[0;34m"
// Purple = "\033[0;35m"
// Cyan = "\033[0;36m"
// White = "\033[0;37m" 
// black = "\033[0;30m"
// black = "\033[0;90m"
// red = "\033[0;91m"
// green = "\033[0;92m"
// yellow = "\033[0;93m"
// blue = "\033[0;94m"
// magenta = "\033[0;95m"
// cyan = "\033[0;96m"
// white = "\033[0;97m"
// cyan_back="\033[0;46m"
// pink_back="\033[0;45m"
// white_back="\033[0;47m"
// blue_back="\033[0;44m"
// orange_back="\033[0;43m"
// green_back="\033[0;42m"
// red_back="\033[0;41m"
// grey_back="\033[0;40m"
// bold = "\033[1m"
// underline = "\033[4m"
// italic = "\033[3m"
// darken = "\033[2m"
// reset = "\033[0m"