//
// Created by Alex on 12/6/2021.
//

#ifndef SFML_PROJECT_IMAGES_H
#define SFML_PROJECT_IMAGES_H
#include <SFML//Graphics.hpp>
#include <map>
#include "ImageName.h"

class Images {
private:
    static std::map<ImageName, sf::Texture> images;
    static std::string getImagePath(ImageName imageName);
    static void loadImage(ImageName imageName);
public:
    static sf::Texture& getImage(ImageName imageName);
};


#endif //SFML_PROJECT_IMAGES_H
