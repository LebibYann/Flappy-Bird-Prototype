/*
** EPITECH PROJECT, 2023
** B-CPP-500-PAR-5-1-rtype-ethan.nguyen
** File description:
** TextureBank
*/

#pragma once

#include "IGraphic.hpp"

enum e_textureID {
    BIRDHOUSE_BACKGROUND,
    CUPHEAD_DEAD,
    CUPHEAD_IDLE,
    NB_TEXTURES
};

struct TextureInfo
{
    std::string path;
    RGraphic::RVect2_t dimension;
    std::size_t nframes;
};

namespace TexturesGlobal
{
    extern TextureInfo BANK[NB_TEXTURES];
}
