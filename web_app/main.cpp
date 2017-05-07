#include <cppnow17/web/make_context.hpp>
//#include <emscripten.h>
#include <emscripten/val.h>

extern "C"
{
  void start();
}

void start()
{
  auto root_element = emscripten::val::global("document").template
    call<emscripten::val>("getElementById", emscripten::val("nbdl-app"));

  static auto ctx = cppnow17::web::make_context(
    std::move(root_element)
  );
}
