#pragma once

#include <string>

namespace jscpp {

struct SourceLocation {
    std::string file;
    int line = 1;
    int column = 1;

    SourceLocation() = default;
    SourceLocation(std::string f, int l, int c) : file(std::move(f)), line(l), column(c) {}
};

} // namespace jscpp
