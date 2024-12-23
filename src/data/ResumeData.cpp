namespace resumeData {
  #include <string>
  #include <filesystem>
  #include "../../libraries/nlohmann/json.hpp"

  using ComponentType = std::string;
  using Keyword = std::string;
  using Content = std::string;
  using Id = int;

  struct Component {
    ComponentType type;
    Keyword kw;
    Content content;
    Id id;
    bool important;

    Component(ComponentType type, Keyword kw, Content content, Id id, bool important)
        : type(std::move(type)), kw(std::move(kw)), content(std::move(content)), id(std::move(id)),  important(std::move(important)) {};
    
  };
};