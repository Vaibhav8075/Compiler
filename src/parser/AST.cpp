#include "AST.h"

namespace jscpp {

void IntLiteral::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void BoolLiteral::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void NullptrLiteral::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void IdentifierExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void BinaryExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void UnaryExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void CallExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void ArrayAccessExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void NewExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void DerefExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }

void BlockStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void ExprStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void VarDeclStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void IfStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void WhileStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void ReturnStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void DeleteStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

void FunctionDecl::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void Program::accept(ASTVisitor& visitor) { visitor.visit(*this); }

} // namespace jscpp
