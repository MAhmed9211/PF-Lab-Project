#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class GameObject
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    std::string name;

public:
    GameObject(std::string imageLocation, sf::Vector2f position, std::string name)
    {
        texture.loadFromFile(imageLocation);
        sprite.setTexture(texture);
        sprite.setPosition(position);
        this->position = position;
        this->name = name;
    }

    virtual void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }

    virtual void displayInfo()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Position: (" << position.x << ", " << position.y << ")" << std::endl;
    }
};

class Bike : public GameObject
{
public:
    Bike(std::string imageLocation, sf::Vector2f position, std::string name) :
        GameObject(imageLocation, position, name)
    {
    }
};

class Car : public GameObject
{
public:
    Car(std::string imageLocation, sf::Vector2f position, std::string name) :
        GameObject(imageLocation, position, name)
    {
    }
};

class UtilityTruck : public GameObject
{
public:
    UtilityTruck(std::string imageLocation, sf::Vector2f position, std::string name) :
        GameObject(imageLocation, position, name)
    {
    }
};

class CommercialTruck : public GameObject
{
public:
    CommercialTruck(std::string imageLocation, sf::Vector2f position, std::string name) :
        GameObject(imageLocation, position, name)
    {
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Vehicle Simulation");

    std::vector<GameObject*> vehicles;
    vehicles.push_back(new Bike("bike.png", sf::Vector2f(100, 100), "Bike 1"));
    vehicles.push_back(new Car("car.png", sf::Vector2f(200, 200), "Car 1"));
    vehicles.push_back(new UtilityTruck("utility_truck.png", sf::Vector2f(300, 300), "Utility Truck 1"));
    vehicles.push_back(new CommercialTruck("commercial_truck.png", sf::Vector2f(400, 400), "Commercial Truck 1"));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for (GameObject* vehicle : vehicles)
        {
            vehicle->draw(window);
        }

        window.display();
    }

    return 0;
}