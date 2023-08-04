#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

Champion *createChampion ()
{
  Champion *c = (Champion*)malloc(sizeof(Champion));
  if (c == NULL)
    return NULL;

  int randomRole = rand () % 4;
  int randomLevel = 0;
  switch (randomRole)
    {
    case 0:
      c->level = rand () % 4 + 5;
      c->role = MAGE;
      break;

    case 1:
      c->level = rand () % 4 + 1;
      c->role = FIGHTER;
      break;

    case 2:
      c->level = rand () % 4 + 3;
      c->role = SUPPORT;
      break;

    case 3:
      c->level = rand () % 8 + 1;
      c->role = TANK;
      break;

    default:
      break;
    }
  c->level = c->level - randomLevel;
  c->next = NULL;
  return c;
}

Champion *addChampion (Champion * head, Champion * c)
{
  Champion* prev = NULL;
  Champion* curr = head;

  if (head == NULL) 
  {
    head = c;
  } 
  else
  {
    while ((curr != NULL) && (c->level > curr->level))
    {
      prev = curr;
      curr = curr->next;
    }
    if (prev == NULL) 
    {
      c->next = head;
      head = c;
    } 
    else
    {
      prev->next = c;
      c->next = curr;
    }
  }
  return head;
}

Champion *buildChampionList (int n)
{
  Champion *head = NULL;
  for( int i = 0 ; i < n ; i++ )
  {
    Champion* c = createChampion();
    head = addChampion( head , c );
  }
  return head;
}

void printChampionList (Champion * head)
{
  while(head != NULL)
  {
    printf("%c%d " , head->role , head->level);
    head = head->next;
  }
}

Champion *removeChampion( Champion * head )
{
  if(head == NULL)
  {
    return NULL;
  }
  Champion* temp = head->next;
  free(head);
  head = temp;
  return head;
}

Champion *destroyChampionList( Champion * head )
{
  Champion *curr = head;
  while(curr != NULL)
  {
    head = curr->next;
    free(curr);
    curr = head;
  }
  return NULL;
}