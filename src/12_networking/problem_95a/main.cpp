#include <iostream>
#include <string>
#include <string_view>
#include <fstream>

#include "curl_easy.h"
#include "curl_exception.h"
#include "curl_header.h"

#include "json.hpp"

int main()
{
   face_manager manager(
      "https://westeurope.api.cognitive.microsoft.com/face/v1.0",
      "...(your api key)...");
   
#ifdef _WIN32
   std::string path = R"(res\albert_and_elsa.jpg)";
#else
   std::string path = R"(./res/albert_and_elsa.jpg)";
#endif

   auto results = manager.detect_from_file(path);

   for (auto const & face : results)
   {
      std::cout << "faceId: " << face.faceId << std::endl
                << "age:    " << face.attributes.age << std::endl
                << "gender: " << face.attributes.gender << std::endl
                << "rect:   " << "{" << face.rectangle.left 
                              << "," << face.rectangle.top
                              << "," << face.rectangle.width
                              << "," << face.rectangle.height
                              << "}" << std::endl << std::endl;
   }
}
