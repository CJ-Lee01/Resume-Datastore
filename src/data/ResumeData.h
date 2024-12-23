#ifndef RESUMEDATA_H
#define RESUMEDATA_H
#include <string>
#include <filesystem>
namespace resumeData {


  using ComponentType = std::string;
  using Keyword = std::string;
  using Content = std::string;
  using Id = int;

  struct Component {
    ComponentType type;
    Keyword kw;
    Content content;
    Id id;

    Component(ComponentType type, Keyword kw, Content content, Id id)
        : type(std::move(type)), kw(std::move(kw)), content(std::move(content)), id(std::move(id)) {}

    
  };
};

#endif