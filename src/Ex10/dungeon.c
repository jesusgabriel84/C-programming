


int isBlocked(Game *game, int x, int y)
{
    if ((unsigned)x<game->opts.mapHeight && (unsigned)y<game->opts.mapWidth)
    {
        Map map = game -> map;
        if (map.tile[y][x] != TILE_WALL)
        {
            for (unsigned j=0; j<game->numMonsters; j++)
            {
                if(x==game->monsters[j].pos.x && y==game->monsters[j].pos.y)
                    return 1;
            }
            return 0;
        }
    }
    return 1;
}

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




void moveTowards(Game *game, Creature *monst) {
    move(game, monst, TOWARDS);
}

void moveAway(Game *game, Creature *monst) {
    move(game, monst, AWAY);
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