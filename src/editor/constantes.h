#ifndef CONSTANTES
#define CONSTANTES

#define DEBUG 1

#define FPS 60

#define VERSION_MAJ 0 //Major release
#define VERSION_MIN 0 //Minor release
#define VERSION_BUG 1 //Bugfix
#define VERSION_REV 1 //Code revision wo bugfix

#if DEBUG
    #ifdef _WIN32
    #define SOFTWARE_ROOT "F:/GitHub/SchmupEditor/data/"
    #define FOLDER_CONFIG "F:/GitHub/SchmupEditor/data/config/"
    #define FILE_CONFIG "F:/GitHub/SchmupEditor/data/config/config.json"
#define FILE_ENNEMY_TEST "F:/GitHub/SchmupEditor/data/project_example/ennemies/7up.ennemy"
    #elif __linux
#define SOFTWARE_ROOT "/home/florent/Git/SchmupEditor.git/data/"
#define FOLDER_CONFIG "/home/florent/Git/SchmupEditor.git/data/config/"
#define FILE_CONFIG "/home/florent/Git/SchmupEditor.git/data/config/config.json"
#define FILE_ENNEMY_TEST "/home/florent/Git/SchmupEditor.git/data/project_example/ennemies/7up.ennemy"
    #endif
#else
    #define SOFTWARE_ROOT "./"
    #define FOLDER_CONFIG "config/"
    #define FILE_CONFIG "config/config.json"
#endif

/*Extensions*/
#define EX_PROJECT "shp"
#define EX_ENNEMY "ennemy"
#define EX_BULLET "bullet"
#define EX_PATH "path"
#define EX_PATTERN "pattern"
#define EX_LEVEL "level"
#define EX_JSON "json"

enum OutputLevel{
    LEVEL_VERBOSE=0,
    LEVEL_TOP_WIDGET
};

#endif // CONSTANTES

