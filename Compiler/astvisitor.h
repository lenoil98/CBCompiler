#ifndef ASTVISITOR_H
#define ASTVISITOR_H
#include "abstractsyntaxtree.h"
namespace ast {

#define AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT( _NODE_ ) virtual void visit(_NODE_ *n);
#define AST_VISITOR_PRE_DEFINE_DEFAULT_ACT_BEFORE(_NODE_) virtual bool actBefore(_NODE_ *n);
#define AST_VISITOR_PRE_DEFINE_DEFAULT_ACT_AFTER(_NODE_) virtual void actAfter(_NODE_ *n);
#define AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(_NODE_) AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT( _NODE_ ) \
	AST_VISITOR_PRE_DEFINE_DEFAULT_ACT_BEFORE(_NODE_) \
	AST_VISITOR_PRE_DEFINE_DEFAULT_ACT_AFTER(_NODE_)


#define AST_VISITOR_DEFINE_DEFAULT_VISIT( _NODE_ ) void Visitor::visit(_NODE_ *n) {\
	if (actBefore(n)) return; \
	for (ChildNodeIterator i = n->childNodesBegin(), cnEnd = n->childNodesEnd(); i != cnEnd; ++i) { \
		(*i)->accept(this); \
	} \
	actAfter(n); }
#define AST_VISITOR_DEFINE_DEFAULT_ACT_BEFORE(_NODE_) bool Visitor::actBefore(_NODE_ *) {  return false; }
#define AST_VISITOR_DEFINE_DEFAULT_ACT_AFTER(_NODE_) void Visitor::actAfter(_NODE_ *) { }
#define AST_VISITOR_DEFINE_DEFAULT_VISIT_FUNCS(_NODE_) AST_VISITOR_DEFINE_DEFAULT_VISIT( _NODE_ ) \
	AST_VISITOR_DEFINE_DEFAULT_ACT_BEFORE(_NODE_) \
	AST_VISITOR_DEFINE_DEFAULT_ACT_AFTER(_NODE_)

class Visitor {
	public:
		Visitor();
		virtual ~Visitor();
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Block)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Integer)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Float)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(String)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Identifier)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Label)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(List)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Goto)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Gosub)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Return)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Exit)

		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(DefaultType)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(BasicType)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(NamedType)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(ArrayType)

		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Expression)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(ExpressionNode)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Unary)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(ArraySubscript)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(FunctionCall)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(KeywordFunctionCall)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(DefaultValue)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Variable)

		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(IfStatement)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(WhileStatement)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(RepeatForeverStatement)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(RepeatUntilStatement)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(ForToStatement)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(ForEachStatement)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(SelectStatement)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(SelectCase)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Const)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Dim)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Redim)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Global)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(VariableDefinition)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(ArrayInitialization)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(FunctionDefinition)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(TypeDefinition)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(StructDefinition)
		AST_VISITOR_PRE_DEFINE_DEFAULT_VISIT_FUNCS(Program)
};

}
#endif // ASTVISITOR_H
