#ifndef CONSTANTES
#define CONSTANTES

#define DEBUG 1

#define ENGINE_VER 0.1
#define ENGINE_NAME "FuEngine"

#define FPS 60

#define PLAYER_WIDTH 27
#define PLAYER_HEIGHT 28

#define BULLET_WIDTH 10
#define BULLET_HEIGHT 10

#define MOVE_INCREMENT 5
#define BULLET_SPEED_DIVIDER 25
#define BULLET_SPEED 10

/*Paths*/
#define TEXTURE_FOLDER "F:/Qt/Moteur_Schmup/data/textures/"
#define FONT_FOLDER "F:/Qt/Moteur_Schmup/data/font/"

/*Array sizes*/
#define MAX_PLAYER_NUMBER 16
#define MAX_ENNEMY_NUMBER 64
#define MAX_BULLET_NUMBER 256

/*Enum*/

enum Direction
{
    HAUT,
    BAS,
    DROITE,
    GAUCHE
};

enum Bullet_Type
{
    NORMAL
};

#endif // CONSTANTES

