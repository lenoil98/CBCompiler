#ifndef TYPEPOINTERVALUETYPE_H
#define TYPEPOINTERVALUETYPE_H
#include "valuetype.h"
class TypeSymbol;
class TypePointerValueType : public ValueType {
	public:
		TypePointerValueType(Runtime *r, TypeSymbol *s);
		Type type()const{return TypePointer;}
		virtual QString name()const;
		virtual CastCostType castCost(ValueType *to) const;
		virtual Value cast(llvm::IRBuilder<> *builder, const Value &v) const;
		TypeSymbol *typeSymbol() const {return mTypeSymbol;}
		bool isTypePointer() const{return true;}
		bool isNumber() const{return false;}
	private:
		TypeSymbol *mTypeSymbol;
};

class NullTypePointerValueType : public ValueType {
	public:
		NullTypePointerValueType(Runtime *r) :ValueType(r){}
		Type type() const {return NULLTypePointer;}
		QString name() const {return "NULL";}
		CastCostType castCost(ValueType *) const {return 0;}
		Value cast(llvm::IRBuilder<> *builder, const Value &v) const;
		bool isTypePointer() const{return true;}
		bool isNumber() const{return false;}
};
#endif // TYPEPOINTERVALUETYPE_H