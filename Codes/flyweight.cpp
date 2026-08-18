#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Asteroid {
  // intrinsic properties: shared among many asteroid objects
  double length;
  double width;
  double height;
  double weight;
  string color;

public:
  Asteroid(double length, double width, double height, double weight, string color)
      : length(length), width(width), height(height), weight(weight), color(std::move(color)) {}

  void draw(int posX, int posY, int velX, int velY) const {
    cout << "Asteroid: color=" << color
         << ", size=(" << length << ", " << width << ", " << height << ")"
         << ", weight=" << weight
         << ", position=(" << posX << ", " << posY << ")"
         << ", velocity=(" << velX << ", " << velY << ")" << endl;
  }

  size_t getMemoryUsage() const {
    return sizeof(*this) + color.capacity();
  }
};

class AsteroidFactory {
  map<string, shared_ptr<Asteroid>> cache;

public:
  shared_ptr<Asteroid> getAsteroid(double length, double width, double height,
                                  double weight, const string &color) {
    string key = to_string(length) + "|" + to_string(width) + "|" + to_string(height) + "|" +
                 to_string(weight) + "|" + color;

    auto it = cache.find(key);
    if (it != cache.end()) {
      return it->second;
    }

    auto asteroid = make_shared<Asteroid>(length, width, height, weight, color);
    cache[key] = asteroid;
    return asteroid;
  }

  size_t getTotalMemoryUsage() const {
    size_t total = 0;
    for (const auto &entry : cache) {
      total += entry.second->getMemoryUsage();
    }
    return total;
  }
};

int main() {
  AsteroidFactory factory;

  // Same intrinsic properties reused many times; only extrinsic values change
  vector<shared_ptr<Asteroid>> asteroids;
  asteroids.push_back(factory.getAsteroid(10, 8, 7, 120.5, "gray"));
  asteroids.push_back(factory.getAsteroid(10, 8, 7, 120.5, "gray"));
  asteroids.push_back(factory.getAsteroid(10, 8, 7, 120.5, "gray"));
  asteroids.push_back(factory.getAsteroid(12, 9, 7, 180.0, "red"));
  asteroids.push_back(factory.getAsteroid(12, 9, 7, 180.0, "red"));
  // Extrinsic properties differ per asteroid instance
  asteroids[0]->draw(100, 200, 2, -1);
  asteroids[1]->draw(250, 150, -3, 2);
  asteroids[2]->draw(430, 310, 4, 0);
  asteroids[3]->draw(80, 70, 1, 3);
  asteroids[4]->draw(500, 120, -2, -1);
  cout << "Total shared asteroid memory: " << factory.getTotalMemoryUsage() << " bytes" << endl;
  return 0;
}