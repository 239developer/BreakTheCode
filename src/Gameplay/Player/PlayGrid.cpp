// #include "PlayGrid.h"
// #include "../Engine/Input.h"
// #include "../Engine/Transform.h"
// #include "../Viewport/Camera.h"
// #include "LevelManager.h"
// #include <iostream>

// void PlayGrid::addTexture(sf::Texture texture)
// {
//     textures.push_back(texture);
// }

// void PlayGrid::setSize(int sizeX, int sizeY)
// {
//     width = sizeX;
//     height = sizeY;
//     for(int x = 0; x < width; x++)
//     {
//         for(int y = 0; y < height; y++)
//         {
//             Tile* tile = new Tile();
//             tile->x = x;
//             tile->y = y;
//             tile->sprite.setTexture(textures[0]);
//             sf::IntRect rect = tile->sprite.getTextureRect();
//             tile->sprite.setOrigin(rect.width / 2.0f, rect.height / 2.0f);
//             float scale = 1.0 * cellSize / tile->sprite.getTextureRect().width;
//             tile->sprite.setScale(scale, scale);
//             floor.push_back(tile);
//         }
//     }
// }

// void PlayGrid::addTile(int x, int y, int rotation, int type, int network)
// {   
//     Tile* tile = new Tile();
//     tile->sprite.setTexture(textures[type]);
//     sf::IntRect rect = tile->sprite.getTextureRect();
//     tile->sprite.setOrigin(rect.width / 2.0f, rect.height / 2.0f);
//     float scale = 1.0 * cellSize / rect.width;
//     tile->sprite.setScale(scale, scale);
//     tile->sprite.setRotation(90.0f * rotation);
//     tile->rotation = rotation;
//     tile->x = x;
//     tile->y = y;
    
//     if(network <= networks.size())
//     {
//         tile->network = network;
//         if(network == networks.size())
//         {
//             networks.push_back(0);
//         }
//     }

//     tile->type = type;
//     switch(type)
//     {
//         case Tile::Player:
//             player = tile;
//             break;
//         case Tile::Floor:
//             floor.push_back(tile);
//             break;
//         case Tile::Wall:
//             walls.push_back(tile);
//             break;
//         case Tile::Button:
//             buttons.push_back(tile);
//             break;
//         case Tile::PistonBase:
//             walls.push_back(tile);
//             break;
//         case Tile::PistonHead:
//             walls.push_back(tile);
//             pistons.push_back(tile);
//             break;
//         case Tile::Crate:
//             crates.push_back(tile);
//             break;
//         case Tile::Win:
//             buttons.push_back(tile);
//             break;
//         default:
//             tile->type = -1;
//     }

//     std::cout << "Added a tile to the grid: " << x << " " << y << " " << rotation << " " << type << "\n";
// }

// void PlayGrid::pushThing(Tile* thing, int dx, int dy)
// {
//     //check if there's something behind the thing
//     bool allow = thing->y + dy >= 0 && thing->y + dy < height && thing->x + dx >= 0 && thing->x + dx < width;
//     for(Tile* wall : walls)
//     {
//         allow = allow && !(thing->x + dx == wall->x + wall->dx && thing->y + dy == wall->y + wall->dy);
//     }
//     for(Tile* crate : crates)
//     {
//         allow = allow && !(thing->x + dx == crate->x && thing->y  + dy== crate->y);
//     }

//     //if yes, apply movement to it
//     if(allow)
//     {
//         thing->x += dx;
//         thing->y += dy;
//     }
// }

// void PlayGrid::gameStep()
// {
//     // player movement
//     int dx = 0;
//     int dy = 0;
//     if(Input::getKeyDown(sf::Keyboard::Key::W))
//     {
//         dy = -1;
//     }
//     else if(Input::getKeyDown(sf::Keyboard::Key::S))
//     {
//         dy = 1;
//     }
//     else if(Input::getKeyDown(sf::Keyboard::Key::A))
//     {
//         dx = -1;
//     }
//     else if(Input::getKeyDown(sf::Keyboard::Key::D))
//     {
//         dx = 1;
//     }
//     for(Tile* crate : crates)
//     {
//         if(crate->x == player->x + dx && crate->y == player->y + dy) //if there's a crate where we wanna move
//         {
//             pushThing(crate, dx, dy);
//         }
//     }
//     pushThing(player, dx, dy);

//     // check every button
//     for(int i = 0; i < buttons.size(); i++)
//     {
//         Tile* tile = buttons[i];
//         switch(tile->type)
//         {
//             case Tile::Button:
//                 if(player->x == tile->x && player->y == tile->y)
//                 {
//                     networks[tile->network] = 1;
//                 }
//                 else
//                 {
//                     networks[tile->network] = 0;
//                 }
//                 break;
//             case Tile::Win:
//                 if(player->x == tile->x && player->y == tile->y)
//                 {
//                     LevelManager::loadNext();
//                 }
//                 break;
//         }
//     }

//     // check every piston
//     for(int i = 0; i < pistons.size(); i++)
//     {
//         Tile* tile = pistons[i];
//         switch(tile->type)
//         {
//             case Tile::PistonHead:
//                 if(networks[tile->network] == 0)
//                 {
//                     tile->dx = 0;
//                     tile->dy = 0;
//                 }
//                 else
//                 {
//                     switch(tile->rotation)
//                     {
//                         case 0:
//                             tile->dx = 1;
//                             tile->dy = 0;
//                             break;
//                         case 1:
//                             tile->dx = 0;
//                             tile->dy = 1;
//                             break;
//                         case 2:
//                             tile->dx = -1;
//                             tile->dy = 0;
//                             break;
//                         case 3:
//                             tile->dx = 0;
//                             tile->dy = -1;
//                             break;
//                     }
//                     if(player->x == tile->x + tile->dx && player->y == tile->y + tile->dy) //if there's a player where we wanna move
//                     {
//                         pushThing(player, tile->dx, tile->dy);
//                     }
//                     for(Tile* crate : crates)
//                     {
//                         if(crate->x == tile->x + tile->dx && crate->y == tile->y + tile->dy) //if there's a crate where we wanna move
//                         {
//                             pushThing(crate, tile->dx, tile->dy);
//                         }
//                     }
//                     bool canMove = true;
//                     if(player->x == tile->x + tile->dx && player->y == tile->y + tile->dy) //if there's a player where we wanna move
//                     {
//                         canMove = false;
//                     }
//                     for(Tile* crate : crates)
//                     {
//                         if(crate->x == tile->x + tile->dx && crate->y == tile->y + tile->dy) //if there's a crate where we wanna move
//                         {
//                             canMove = false;
//                         }
//                     }
//                     if(!canMove)
//                     {
//                         tile->dx = 0;
//                         tile->dy = 0;
//                     }
//                 }
//                 break;
//         }
//     }

// }

// void PlayGrid::update()
// {
//     if(    Input::getKeyDown(sf::Keyboard::Key::W)
//         || Input::getKeyDown(sf::Keyboard::Key::A)
//         || Input::getKeyDown(sf::Keyboard::Key::S)
//         || Input::getKeyDown(sf::Keyboard::Key::D))
//     {
//         gameStep();
//     }
// }

// void PlayGrid::draw()
// {
//     sf::Vector2f position(0.0f, 0.0f);
//     Transform* transform = parent->getComponent<Transform>();
//     if(transform)
//     {
//         position = transform->position - Camera::position;
//     }

//     //floor
//     for(int i = 0; i < floor.size(); i++)
//     {
//         sf::Vector2f pos((floor[i]->x + floor[i]->dx) * cellSize, (floor[i]->y + floor[i]->dy) * cellSize);
//         floor[i]->sprite.setPosition(position + pos);
//         Camera::window.draw(floor[i]->sprite);
//     }

//     //walls
//     for(int i = 0; i < walls.size(); i++)
//     {
//         sf::Vector2f pos((walls[i]->x + walls[i]->dx) * cellSize, (walls[i]->y + walls[i]->dy) * cellSize);
//         walls[i]->sprite.setPosition(position + pos);
//         if(walls[i]->type == Tile::PistonBase)
//         {
//             Tile* rod = new Tile();
//             rod->sprite.setTexture(textures[Tile::PistonRod]);
//             sf::IntRect rect = rod->sprite.getTextureRect();
//             rod->sprite.setOrigin(rect.width / 2.0f, rect.height / 2.0f);
//             float scale = 1.0 * cellSize / rod->sprite.getTextureRect().width;
//             rod->sprite.setScale(scale, scale);
//             rod->sprite.setRotation(90.0f * walls[i]->rotation);
//             rod->rotation = walls[i]->rotation;
//             rod->sprite.setPosition(position + pos);
//             Camera::window.draw(rod->sprite);
//         }
//         Camera::window.draw(walls[i]->sprite);
//     }

//     //buttons
//     for(int i = 0; i < buttons.size(); i++)
//     {
//         sf::Vector2f pos((buttons[i]->x + buttons[i]->dx) * cellSize, (buttons[i]->y + buttons[i]->dy) * cellSize);
//         buttons[i]->sprite.setPosition(position + pos);
//         Camera::window.draw(buttons[i]->sprite);
//     }

//     //pistons
//     for(int i = 0; i < pistons.size(); i++)
//     {
//         sf::Vector2f pos((pistons[i]->x + pistons[i]->dx) * cellSize, (pistons[i]->y + pistons[i]->dy) * cellSize);
//         pistons[i]->sprite.setPosition(position + pos);
//         if(pistons[i]->dx + pistons[i]->dy != 0)
//         {
//             Tile* rod = new Tile();
//             rod->sprite.setTexture(textures[Tile::PistonRod]);
//             sf::IntRect rect = rod->sprite.getTextureRect();
//             rod->sprite.setOrigin(rect.width / 2.0f, rect.height / 2.0f);
//             float scale = 1.0 * cellSize / rod->sprite.getTextureRect().width;
//             rod->sprite.setScale(scale, scale);
//             rod->sprite.setRotation(90.0f * pistons[i]->rotation);
//             rod->rotation = pistons[i]->rotation;
//             rod->sprite.setPosition(position + pos);
//             Camera::window.draw(rod->sprite);
//         }
//         Camera::window.draw(pistons[i]->sprite);
//     }

//     //crates
//     for(int i = 0; i < crates.size(); i++)
//     {
//         sf::Vector2f pos((crates[i]->x) * cellSize, (crates[i]->y) * cellSize);
//         crates[i]->sprite.setPosition(position + pos);
//         Camera::window.draw(crates[i]->sprite);
//     }

//     //player
//     sf::Vector2f pos((player->x) * cellSize, (player->y) * cellSize);
//     player->sprite.setPosition(position + pos);
//     Camera::window.draw(player->sprite);
// }