#ifndef COMMAND_VOCAB_H
#define COMMAND_VOCAB_H

// define your own namespace to hold constants
namespace vocab
{
  #include <string>
  using std::string;
    // constants have internal linkage by default
    // should i use extern?
    const string ADD_CMD_KEYWORD { "add" };
    const string RM_CMD_KEYWORD { "rm" };
    const string UPDATE_CMD_KEYWORD { "update" };
    const string EXIT_CMD_KEYWORD { "exit" };
    const string CLEAN_CMD_KEYWORD { "clean" };
    const string LIST_CMD_KEYWORD { "clean" };
    const string SEARCH_CMD_KEYWORD { "search" };
    const string HELP_CMD_KEYWORD { "help" };

    const string TYPE_FULL_TAG { "type" };
    const string KEYWORD_FULL_TAG { "keyword" };
    const string IMPORTANT_FULL_TAG { "important" };
    const string PARENT_FULL_TAG { "parent" };

    const string TYPE_SHORT_TAG { "t" };
    const string KEYWORD_SHORT_TAG { "kw" };
    const string IMPORTANT_SHORT_TAG { "i" };
    const string PARENT_SHORT_TAG { "p" };

    // ... other related constants
}
#endif