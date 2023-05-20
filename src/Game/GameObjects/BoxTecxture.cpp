#include "BoxTexture.h"

BoxTexture::BoxTexture(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName, bool cilinder) : GameObject(game, pos, dim), cilinder(cilinder)
{
    this->cilinder = cilinder;
    img.load(imgName);
    texture = img.getTexture();
    if (!cilinder)
    {
        box.set(dim.x, dim.y, dim.z);
        box.setPosition(pos.x, pos.y, pos.z);
        box.mapTexCoordsFromTexture(texture);
    }
    else
    {
        int resolution = 50; // Resolución del cilindro (número de segmentos)
        cylinder.set(dim.x / 2, dim.y, resolution, true);
        cylinder.setPosition(pos.x, pos.y, pos.z);
    }
}

BoxTexture::~BoxTexture() {}

void BoxTexture::draw()
{

    if (this->cilinder)
    {
        ofEnableDepthTest();

        texture.bind();

        // Dibuja el cilindro
        cylinder.draw();

        // Desactiva la textura
        texture.unbind();
        ofDisableDepthTest();
    }
    else
    {
        texture.bind();
        box.draw();
        texture.unbind();
    }
}
