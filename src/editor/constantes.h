#ifndef CONSTANTES
#define CONSTANTES

#define DEBUG 1

#define FPS 60

#define VERSION_MAJ 0 //Major release
#define VERSION_MIN 0 //Minor release
#define VERSION_BUG 1 //Bugfix
#define VERSION_REV 1 //Code revision wo bugfix

#if DEBUG
    #define SOFTWARE_ROOT "F:/GitHub/SchmupEditor/data/"
    #define FOLDER_CONFIG "F:/GitHub/SchmupEditor/data/config/"
    #define FILE_CONFIG "F:/GitHub/SchmupEditor/data/config/config.json"
#else
    #define SOFTWARE_ROOT "./"
    #define FOLDER_CONFIG "config/"
    #define FILE_CONFIG "config/config.json"
#endif

enum OutputLevel{
    LEVEL_VERBOSE=0,
    LEVEL_TOP_WIDGET
};

#endif // CONSTANTES

