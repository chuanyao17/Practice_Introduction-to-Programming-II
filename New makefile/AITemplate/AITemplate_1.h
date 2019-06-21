#pragma once

#include <BattleShipGame/Wrapper/AI.h>
#include <BattleShipGame/Ship.h>
#include <algorithm>
#include <random>
#include <ctime>
#include <stdlib.h>

class AI : public AIInterface
{
    //std::vector<std::pair<int,int>> way;
    int dens[20][20] = {0};
public:
    virtual std::vector<TA::Ship> init(int size ,std::vector<int> ship_size, bool order, std::chrono::milliseconds runtime) override
    {
        (void)ship_size;
        (void)runtime;

        std::vector<TA::Ship> tmp;

        int i, j, k;
        int sz[4] = {3, 3, 5, 7};
        int map[20][20] = {0};

        srand((unsigned)time(nullptr));

        for (i=0; i<4; i++){
            int check = 0;
            int place_i = rand()%(20-sz[i]);
            int place_j = rand()%(20-sz[i]);

            for (j = place_i; j < place_i+sz[i]; j++){
                for (k = place_j; k < place_j+sz[i]; k++){
                    if (map[j][k] == 1){
                        check = 1;
                    }
                }
            }

            if (check){
                i--;
            }
            else{
                tmp.push_back({sz[i], place_i, place_j,TA::Ship::State::Available});

                for (j = place_i; j < place_i+sz[i]; j++){
                    for (k = place_j; k < place_j+sz[i]; k++){
                        map[j][k] = 1;
                    }
                }
            }
        }
        
        for(i=0;i<size;++i)
            for(j=0;j<size;++j)
                way.emplace_back(i,j);

        std::mt19937 mt;
        mt.seed( std::time(nullptr) + 7122 + (order?1:0) );
        std::shuffle(way.begin(), way.end(), mt);
        return tmp;
    }

    virtual void callbackReportEnemy(std::vector<std::pair<int,int>>) override
    {

    }

    virtual std::pair<int,int> queryWhereToHit(TA::Board) override
    {
        auto res = way.back();
        way.pop_back();
        return res;
    }

    virtual void callbackReportHit(bool)  override
    {

    }

    virtual std::vector<std::pair<int,int>> queryHowToMoveShip(std::vector<TA::Ship>) override
    {
        return {};
    }
};
