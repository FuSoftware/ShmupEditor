#ifndef CONSTANTES
#define CONSTANTES

#define PI 3.14159265359

#define DEBUG 1

#define ENGINE_VER 0.1
#define ENGINE_NAME "FuEngine"

#define FPS 60

#define TEST_FILE_PLAYER "/home/florent/git/SchmupEditor.git/data/test/main_character.json"

#define BULLET_WIDTH 10
#define BULLET_HEIGHT 10

#define BULLET_SPEED_DIVIDER 25
#define BULLET_SPEED 10

/*Paths*/
#ifdef __linux
#define TEXTURE_FOLDER "/home/florent/Git/SchmupEditor.git/data/sprites/"
#elif _WIN32
#define TEXTURE_FOLDER "F:/GitHub/SchmupEditor/data/sprites/"
#endif

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

#endif // CONSTANTES

