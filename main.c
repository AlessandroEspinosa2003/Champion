#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

int main( int argc , char *argv[] )
{
    srand(time(NULL));

    if( argc != 2 )
    {
        printf("ERROR: Missing command line argument.\n");
        return 1;
    }

    int numChamp = atoi(argv[1]);
    if ( numChamp <= 0 )
    {
        printf("ERROR: The number of champions has to be greater than 0\n");
        return 1;
    }

    Champion *player1 = buildChampionList(numChamp);
    Champion *player2 = buildChampionList(numChamp);
    
    printf("\n============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
    
    int round = 1;
    while(player1 != NULL && player2 != NULL)
    {
        printf("\n----- ROUND %d -----\n", round);
        printf("Player 1: ");
        printChampionList(player1);
        printf("\nPlayer 2: ");
        printChampionList(player2);

        ChampionRole player1_role = player1->role;
        ChampionRole player2_role = player2->role;

        int player1_level = player1->level;
        int player2_level = player2->level;

        player1 = removeChampion(player1);
        player2 = removeChampion(player2);

         switch(player1_role)
         {
             case 'M':
                 switch(player2_role)
                 {
                     case 'M':
                         if(player1_level > player2_level)
                         {
                            printf("\nPlayer 1 (MAGE) wins and gains a champion.\n");
                            printf("\nPlayer 2 (MAGE) loses one champion.\n");
                            player1 = addChampion(player1, createChampion());  
                            player2 = removeChampion(player2);                          
                         }
                         else
                         {
                            if(player1_level < player2_level)
                            {
                                printf("\nPlayer 1 (MAGE) loses one champion.\n");
                                printf("\nPlayer 2 (MAGE) wins and gains a champion.\n");                                
                                player2 = addChampion(player2, createChampion());
                                player1 = removeChampion(player1);
                            }
                            else
                            {
                                printf("\nNothing happens - no penalty or reward.\n");                        
                            }
                         }
                         break;
                     case 'F':
                         if(player1_level > player2_level)
                         {
                            printf("\nPlayer 1 (MAGE) wins and gains a new champion.\n");
                            printf("\nPlayer 2 (FIGHTER) loses but with no penalty.\n");                         
                            player1 = addChampion(player1, createChampion());
                         }
                         else
                         {
                            if(player1_level < player2_level)
                            {
                                printf("\n Player 1 (MAGE) loses one champion.\n");                                
                                printf("\nPlayer 2 (FIGHTER) wins but with no reward.\n");
                                player1 = removeChampion(player1);
                            }
                            else
                            {
                                printf("\nNothing happens - no penalty or reward.\n");                               
                            }
                         }
                         break;
                     case 'S':
                         if(player1_level > player2_level)
                         {
                            printf("\nPlayer 1 (MAGE) wins and gains a new champion.\n");
                            printf("\nPlayer 2 (SUPPORT) loses two champions.\n");
                            player1 = addChampion(player1, createChampion());
                            player2 = removeChampion(player2);
                            player2 = removeChampion(player2);
                         }
                         else
                         {
                            if(player1_level < player2_level)
                            {
                                printf("\nPlayer 1 (MAGE) loses one champion.\n");
                                printf("\nPlayer 2 (SUPPORT) wins and gains two new champions.\n");
                                player2 = addChampion(player2, createChampion());
                                player2 = addChampion(player2, createChampion());
                                player1 = removeChampion(player1);
                            }
                            else
                            {
                                printf("\nNothing happens - no penalty or reward.\n");                         
                            }
                         }
                         break;
                     case 'T':
                         printf("\nPlayer 1 (MAGE) wins and gains a new champion.\n");
                         printf("\nPlayer 2 (TANK) loses one champion.\n");
                         player1 = addChampion(player1, createChampion());
                         player2 = removeChampion(player2);
                         break;
                 }
                 break;
             case 'F':
                 switch(player2_role)
                 {
                     case 'M':
                         if(player1_level > player2_level)
                         {
                            printf("\nPlayer 1 (FIGHTER) wins but with no reward.\n");
                            printf("\n Player 2 (MAGE) loses one champion.\n");  
                            player2 = removeChampion(player2);                          
                         }
                         else
                         {
                            if(player1_level < player2_level)
                            {
                                printf("\nPlayer 1 (FIGHTER) loses but with no penalty.\n");
                                printf("\nPlayer 2 (MAGE) wins and gains a new champion.\n");                              
                                player2 = addChampion(player2,createChampion());
                            }
                            else
                            {
                                printf("\nNothing happens - no penalty or reward.\n");                             
                            }
                         }
                         break;
                     case 'F':
                         printf("\nPlayer 1 (FIGHTER) gains a new champion.\n");
                         printf("\nPlayer 2 (FIGHTER) gains a new champion.\n");                     
                         player1 = addChampion(player1, createChampion());
                         player2 = addChampion(player2, createChampion());
                         break;
                     case 'S':
                         if(player1_level > player2_level)
                         {
                            printf("\nPlayer 1 (FIGHTER) wins but with no reward.\n");
                            printf("\n Player 2 (SUPPORT) loses one champion.\n");
                            player2 = removeChampion(player2);                            
                         }
                         else
                         {
                            if(player1_level < player2_level)
                            {
                                printf("\nPlayer 1 (FIGHTER) loses but with no penalty.\n");
                                printf("\nPlayer 2 (SUPPORT) wins and gains a new champion.\n");                         
                                player2 = addChampion(player2,createChampion());
                            }
                            else
                            {
                                printf("\nNothing happens - no penalty or reward.\n");                            
                            }
                         }
                         break;                         
                     case 'T':
                         printf("\nPlayer 1 (FIGHTER) wins and gains a new champion.\n");
                         printf("\nPlayer 2 (TANK) loses with no penalty.\n");                 
                         player1 = addChampion(player1, createChampion());
                         break;
                 }
                 break;
             case 'S':
                 switch(player2_role)
                 {
                     case 'M':
                         if(player1_level > player2_level)
                         {
                            printf("\nPlayer 1 (SUPPORT) wins and gains two new champions.\n");
                            printf("\nPlayer 2 (MAGE) loses one champion.\n");
                            player1 = addChampion(player1, createChampion());
                            player1 = addChampion(player1, createChampion());
                            player2 = removeChampion(player2);                            
                         }
                         else
                         {
                            if(player1_level < player2_level)
                            {
                                printf("\nPlayer 1 (SUPPORT) loses two champions.\n");
                                printf("\nPlayer 2 (MAGE) wins and gains one new champion.\n");
                                player2 = addChampion(player2, createChampion());
                                player1 = removeChampion(player1);
                                player1 = removeChampion(player1);                                                           
                            }
                            else
                            {
                                printf("\nNothing happens - no penalty or reward.\n");                
                            }
                         }
                         break;
                     case 'F':
                         if(player1_level > player2_level)
                         {
                            printf("\nPlayer 1 (SUPPORT) wins and gains a new champion.\n");
                            printf("\n Player 2 (FIGHTER) loses with no penalty.\n");                                                    
                            player1 = addChampion(player1, createChampion());
                         }
                         else
                         {
                            if(player1_level < player2_level)
                            {
                                printf("\nPlayer 1 (SUPPORT) loses a champion.\n");
                                printf("\nPlayer 2 (FIGHTER) wins but with no reward.\n");                              
                                player1 = removeChampion(player1);
                            }
                            else
                            {
                                printf("\nNothing happens - no penalty or reward.\n");                               
                            }
                         }  
                         break;
                     case 'S':
                         printf("\nPlayer 1 (SUPPORT) loses a champion.\n");
                         printf("\nPlayer 2 (SUPPORT) loses a champion.\n");
                         player1 = removeChampion(player1);
                         player2 = removeChampion(player2);
                         break;
                     case 'T':
                         printf("\nPlayer 1 (SUPPORT) loses but with no penalty.\n");
                         printf("\nPlayer 2 (TANK) wins and gains a new champion.\n");                    
                         player2 = addChampion(player2, createChampion());
                         break;
                 }
                 break;
             case 'T':
                 switch(player2_role)
                 {
                     case 'M':
                         printf("\nPlayer 1 (TANK) loses one champion.\n");
                         printf("\nPlayer 2 (MAGE) wins and gains a new champion.\n");
                         player1 = removeChampion(player1);
                         player2 = addChampion(player2, createChampion());
                         break;
                     case 'F':
                         printf("\nPlayer 1 (TANK) loses with no penalty.\n");
                         printf("\nPlayer 2 (FIGHTER) wins and gains a new champion.\n");                       
                         player2 = addChampion(player2, createChampion());
                         break;
                     case 'S':
                         printf("\nPlayer 1 (TANK) wins and gains a new champion.\n");
                         printf("\nPlayer 2 (SUPPORT) loses but with no penalty.\n");                        
                         player1 = addChampion(player1, createChampion());
                         break;
                     case 'T':
                         printf("\nNothing happens - no penalty or reward.\n");                    
                         break;
                 }
                 break;            
         }
                 
         
        round++;
        printf("\n");
     }
    

    printf("\n============ GAME OVER  =============\n");
    printf("\nPlayer 1 ending champion list: ");
    printChampionList(player1);
    printf("\nPlayer 2 ending champion list: ");
    printChampionList(player2);
    printf("\n");

    if(player1 == NULL && player2 == NULL)
    {
        printf("\nTIE -- both players ran out of champions.\n");
    }
    else if(player1 == NULL)
    {
        printf("\nPlayer 1 ran out of champions. Player 2 wins.\n");
    }
    else
    {
        printf("\nPlayer 2 ran out of champions. Player 1 wins.");
    }
    player1 = destroyChampionList(player1);
    player2 = destroyChampionList(player2);
    
    return 0;
}