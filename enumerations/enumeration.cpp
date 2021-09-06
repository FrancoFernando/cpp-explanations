#include <iostream>

enum ClassicEnum{
  red = 0,
  green = 2,
  blue // = 3
};

enum struct ScopedEnum{
  red = 0,
  green = 2,
  blue, // = 3
  purple
};

enum class Color{
  red,
  blue,
  green
};

enum struct Shape : char{
  circle = 10,
  square, // 11
  triangle // 12
};


int main(){
	
  std::cout << "classic green: " << green << std::endl; // 2
  std::cout << "scoped green: " << ScopedEnum::green << std::endl; // 2
  
  // implicitely converted to int
  int classic_green = green;
  // need explicit cast
  int scoped_green = static_cast<int>(ScopedEnum::green);

  // Error: green already in scope
  //int green = 8;

  // Correct: purple not in scope 
  int purple = static_cast<int>(ScopedEnum::purple);  

  std::cout << "sizeof(Color)= "  << sizeof(Color) << std::endl;    //int 
  std::cout << "sizeof(Shape)= "  << sizeof(Shape) << std::endl;    //char
}

