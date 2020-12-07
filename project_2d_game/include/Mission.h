//
// Created by Admin on 05.12.2020.
//

#ifndef PROJECT_2D_GAME_MISSION_H
#define PROJECT_2D_GAME_MISSION_H

int getCurrentMission(int x)
{
    int mission = 0;
    if (x>0 && x<600)
        mission = 0;
    if (x>400)
        mission = 1;

    return mission;
}

std::string getTextMission(int currentMission) {

    std::string missionText;

    switch (currentMission)
    {
        case 0:
            missionText = "\n Training";
            break;
        case 1:
            missionText = "\nMission 1\n\nThis is your\n first mission\n";
            break;
    }
    return missionText;
};

#endif //PROJECT_2D_GAME_MISSION_H
