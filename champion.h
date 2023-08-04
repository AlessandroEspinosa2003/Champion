#ifndef CHAMPION_H
#define CHAMPION_H

typedef struct Champion Champion;

typedef enum { 
    MAGE = 'M', 
    FIGHTER = 'F', 
    SUPPORT = 'S', 
    TANK = 'T' 
}ChampionRole;

typedef struct Champion {
    ChampionRole role;
    int level;
    struct Champion * next;
}Champion;

Champion* createChampion();
Champion* addChampion( Champion *head, Champion *c );
Champion* buildChampionList( int n );
void printChampionList( Champion *head );
Champion* removeChampion( Champion *head );
Champion* destroyChampionList( Champion *head );

#endif