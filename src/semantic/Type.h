#pragma once

#include <string>
#include <memory>
#include <vector>

namespace jscpp {

enum class TypeKind {
    Int,
    Bool,
    Void,
    Pointer,
    Array,
    Nullptr_t,
    Unknown
};

class Type {
public:
    TypeKind kind;
    std::shared_ptr<Type> baseType; // For Pointer or Array
    int arraySize = 0; // For Array

    Type(TypeKind kind) : kind(kind) {}
    Type(TypeKind kind, std::shared_ptr<Type> base) : kind(kind), baseType(std::move(base)) {}
    Type(TypeKind kind, std::shared_ptr<Type> base, int size) : kind(kind), baseType(std::move(base)), arraySize(size) {}

    bool operator==(const Type& other) const {
        if (kind != other.kind) return false;
        if (kind == TypeKind::Pointer || kind == TypeKind::Array) {
            return *baseType == *other.baseType;
        }
        return true;
    }
    bool operator!=(const Type& other) const { return !(*this == other); }

    std::string toString() const {
        switch (kind) {
            case TypeKind::Int: return "int";
            case TypeKind::Bool: return "bool";
            case TypeKind::Void: return "void";
            case TypeKind::Nullptr_t: return "nullptr_t";
            case TypeKind::Pointer: return baseType->toString() + "*";
            case TypeKind::Array: return baseType->toString() + "[" + std::to_string(arraySize) + "]";
            default: return "unknown";
        }
    }
};

} // namespace jscpp
