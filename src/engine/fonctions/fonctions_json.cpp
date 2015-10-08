#include "fonctions_json.h"
#include "fonctions.h"

#include "constantes.h"

Json::Value saveAndLoad(Json::Value root, const char* file)
{
    saveJSONFile(root, file);
    root = loadJSONFile(file);
    return root;
}

Json::Value loadJSONFile(const char* filePath)
{
    Json::Value root; // will contains the root value after parsing
    Json::Reader reader;
    std::ifstream test(filePath, std::ifstream::binary);
    bool parsingSuccessful = reader.parse(test, root) ;
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout << "JSON ERROR : " << reader.getFormattedErrorMessages() << std::endl;
        return Json::nullValue;
    }

    test.close();

    return root;
}

void saveJSONFile(Json::Value root, const char* filePath)
{
    Json::StyledWriter writer;
    std::ofstream mFile;
    mFile.open(filePath);
    mFile << writer.write(root);
    mFile.close();
}
