/* monster.c -- Implementation of monster actions
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dungeon.h"


//Defining directions
typedef enum {
  TOWARDS,  // can be moved to
  AWAY,  // cannot be moved to
} Direction;


// for defining some monster types below that can be used in the game
typedef struct {
    char name[20];  // Name of monster
    char sign;  // character to show it on map
    unsigned int hplow;  // lowest possible initial maxhp
    unsigned int hphigh;  // highest possible initial maxhp
} MonstType;

// Specifying three monster types to start with.
// Feel free to add more, or change the below
// Note that it is up to you to decide whether to use this array from createMonsters
// you may or may not use it
const MonstType types[] = {
    { "Goblin", 'G', 6, 10},
    { "Rat", 'R', 3, 5},
    { "Dragon", 'D', 15, 20}
};


double calc_distance(Point p1, Point p2)
{
    double distance;
    distance = sqrt(((p2.x-p1.x)*(p2.x-p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));
    return distance;
}

/* One kind of attack done by monster.
 * The attack function pointer can refer to this.
 * 
 * Parameters:
 * game: the game state
 * monst: The monster performing attack
 */
void attackPunch(Game *game, Creature *monst) {
    printf("%s punches you! ", monst->name);
    int hitprob = 50;
    int maxdam = 4;
    if (rand() % 100 < hitprob) {
        printf("Hit! ");
        int dam = rand() % maxdam + 1;
        printf("Damage: %d ", dam);
        game->hp = game->hp - dam;
        if (game->hp <= 0)
            printf("You died!");
        printf("\n");
    } else {
        printf("Miss!\n");
    }
}


void move(Game *game, Creature *monst, Direction direction)
{
  Point monster_position = monst->pos;
  Point player_position = game->position;
  double original_distance = calc_distance(monster_position, player_position);

  int x_pos[3];
  x_pos[0] = monster_position.x - 1 < 1 ? 1 : monster_position.x - 1;
  x_pos[1] = monster_position.x;
  x_pos[2] = ((unsigned)monster_position.x + 1 >= game->opts.mapWidth) ? game->opts.mapWidth : (unsigned)monster_position.x + 1;

  int y_pos[3];
  y_pos[0] = monster_position.y - 1 < 1 ? 1 : monster_position.y - 1;
  y_pos[1] = monster_position.y;
  y_pos[2] = ((unsigned)monster_position.y + 1 >= game->opts.mapHeight) ? game->opts.mapHeight : (unsigned)monster_position.y + 1;

  double dist = original_distance;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Point new_position;
      new_position.x = x_pos[i];
      new_position.y = y_pos[j];
      double distance = calc_distance(new_position, player_position);

      if (direction == 0)
            {
        if (distance > 0 && distance < dist && !isBlocked(game, x_pos[i], y_pos[j]))
                {
                    monst->pos.x = new_position.x;
          monst->pos.y = new_position.y;
        }
      }
      else
                if (direction == 1)
                {
                    if (distance > 0 && distance > dist && !isBlocked(game, x_pos[i], y_pos[j]))
                    {
                        monst->pos.x = new_position.x;
                        monst->pos.y = new_position.y;
                    }
                }
    }
  }
}


/* Exercise (c)
 *
 * Move monster 'monst' towards the player character.
 * See exercise description for more detailed rules.
 */
void moveTowards(Game *game, Creature *monst) {
    move(game, monst, TOWARDS);
}


/* Exercise (d)
 *
 * Move monster 'monst' away from the player character.
 * See exercise description for more detailed rules.
 */
void moveAway(Game *game, Creature *monst) {
    move(game, monst, AWAY);
}

/* Exercise (e)
 *
 * Take action on each monster (that is alive) in 'monsters' array.
 * Each monster either attacks or moves (or does nothing if no action is specified)
 */
void monsterAction(Game *game) {
    //(void) game;
    for (unsigned int k = 0; k < game->numMonsters; k++) {
    Creature monster = game->monsters[k];

    double distance = calc_distance(game->position, monster.pos);

    if (distance == 1.0) {
      monster.attack(game, &game->monsters[k]);
    } else {
      monster.move(game, &game->monsters[k]);
    }
}
}


/* Exercise (b)
 *
 * Create opts.numMonsters monsters and position them on valid position
 * in the the game map. The moster data (hitpoints, name, map sign) should be
 * set appropriately (see exercise instructions) 
 */
void createMonsters(Game *game)
{
    game->monsters = malloc(sizeof(Creature) * game->opts.numMonsters);
  game->numMonsters = 0;
  for (unsigned int k = 0; k < game->opts.numMonsters; k++) {
    Creature creature;
    unsigned int x,y;

    do {
      x = rand() % game->opts.mapWidth;
      y = rand() % game->opts.mapHeight;
    } while (isBlocked(game, x, y));

    Point position;
    position.x = x;
    position.y = y;
    creature.pos = position;
    creature.maxhp = (rand() % 200) + 1;
        creature.hp = creature.maxhp;
        creature.sign = 'D';
        for (unsigned int i = 0; i < 12; i++) {
      creature.name[i] = 17 + (rand() % 28);
    }
    creature.name[12] = '\0';

        game->monsters[k] = creature;
        game->numMonsters++;
    }
}

/* Determine whether monster moves towards or away from player character.
 */
void checkIntent(Game *game)
{
    for (unsigned int i = 0; i < game->numMonsters; i++) {
        Creature *m = &game->monsters[i];
        if (m->hp <= 2) {
            m->move = moveAway;
        } else {
            m->move = moveTowards;
        }
        if (m->hp < m->maxhp)
            m->hp = m->hp + 0.1;  // heals a bit every turn
    }
}
