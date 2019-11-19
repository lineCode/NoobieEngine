#pragma once

#include <glm/glm.hpp>

class Materials
{
public:
    // GOLD material - ambient, diffuse, specular, and shininess
    static glm::vec4 goldAmbient() { return glm::vec4{ 0.2473f, 0.1995f, 0.0745f, 1 }; }
    static glm::vec4 goldDiffuse() { return glm::vec4{ 0.7516f, 0.6065f, 0.2265f, 1 };}
    static glm::vec4 goldSpecular() { return glm::vec4{ 0.6283f, 0.5559f, 0.3661f, 1 };}
    static float goldShininess() { return 51.2f; }

    // SILVER material - ambient, diffuse, specular, and shininess
    static glm::vec4 silverAmbient() { return glm::vec4{ 0.1923f, 0.1923f, 0.1923f, 1 };}
    static glm::vec4 silverDiffuse() { return glm::vec4{ 0.5075f, 0.5075f, 0.5075f, 1 };}
    static glm::vec4 silverSpecular() { return glm::vec4{ 0.5083f, 0.5083f, 0.5083f, 1 };}
    static float silverShininess() { return 51.2f; }

    // BRONZE material - ambient, diffuse, specular, and shininess
    static glm::vec4 bronzeAmbient() { return glm::vec4{ 0.2125f, 0.1275f, 0.0540f, 1 };}
    static glm::vec4 bronzeDiffuse() { return glm::vec4{ 0.7140f, 0.4284f, 0.1814f, 1 };}
    static glm::vec4 bronzeSpecular() { return glm::vec4{ 0.3936f, 0.2719f, 0.1667f, 1 };}
    static float bronzeShininess() { return 25.6f; }
};
