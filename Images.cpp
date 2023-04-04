//
// Created by Alex on 12/6/2021.
//

#include "Images.h"

std::map<ImageName, sf::Texture> Images::images;

std::string Images::getImagePath(ImageName imageName)
{
    switch(imageName)
    {
        case MENU: return "FastFurious.png";
        case WINNER: return "winScreen.jpg";
        case GAMESCREEN: return "GameScreen.jpg";
        case BACK: return "images/backCard.png";
        case ACES: return "images/ace_of_clubs.png";
        case TWOS: return "images/2_of_clubs.png";
        case THREES: return "images/3_of_clubs.png";
        case FOURS: return "images/4_of_clubs.png";
        case FIVES: return "images/5_of_clubs.png";
        case SIXS: return "images/6_of_clubs.png";
        case SEVENS: return "images/7_of_clubs.png";
        case EIGHTS: return "images/8_of_clubs.png";
        case NINES: return "images/9_of_clubs.png";
        case TENS: return "images/10_of_clubs.png";
        case JACKS: return "images/jack_of_clubs.png";
        case QUEENS: return "images/queen_of_clubs.png";
        case KINGS: return "images/king_of_clubs.png";
    }
}

void Images::loadImage(ImageName imageName)
{
    images[imageName] = sf::Texture();
    images[imageName].loadFromFile(getImagePath(imageName));
}

sf::Texture &Images::getImage(ImageName imageName)
{
    loadImage(imageName);
    return images[imageName];
}
