#include <iostream>

#include "bubble.h"
#include "cpputils/graphics/image.h"
using namespace std;

int main() {

  Bubble my_bubble;

  // Prompts the user for input to create the Bubble image.
  std::cout << "Tell me about your bubble.\n"
            << "Valid x, y and size are between 0 and 500.\n"
            << "Valid colors are red, orange, yellow, green, "
            << "teal, blue, and purple." << std::endl;

  std::string color;
  std::cout << "What color? ";
  std::cin >> color;

  int size = 0;
  std::cout << "What size? ";
  std::cin >> size;

  int x = 0;
  std::cout << "What x? ";
  std::cin >> x;

  int y = 0;
  std::cout << "What y? ";
  std::cin >> y;

  // ========================== YOUR CODE HERE =============================
  class Bubble {
  public:
  void SetX(int x);
  void SetY(int y);
  void SetSize(int size);
  void SetColor(const std::string&color);

  graphics::Color GetColor()const;
  int GetX()const;
  int GetY()const;
  int GetSize()const;

  std::string ToString() const;

  private:
  int x_;
  int y_;
  int size_;
  graphics::Color color_;
  };
  
  const int image_size = 500;
  graphics::Image image(image_size, image_size);
  if (image.DrawCircle(my_bubble.GetX(), my_bubble.GetY(), my_bubble.GetSize(),
                       my_bubble.GetColor()) &&
      image.SaveImageBmp("bubble.bmp")) {
    std::cout << my_bubble.ToString() << std::endl;
    std::cout << "Your bubble was saved to bubble.bmp" << std::endl;
  }
  return 0;
}
