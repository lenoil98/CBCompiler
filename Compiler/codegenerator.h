#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H
#include "scope.h"
#include "abstractsyntaxtree.h"
#include "runtime.h"
#include "stringpool.h"
#include "constantvalue.h"
#include "constantexpressionevaluator.h"
#include "symbolcollectortypechecker.h"
class CBFunction;
class TypeSymbol;
class CodeGenerator : public QObject{
		Q_OBJECT
	public:
		CodeGenerator();
		bool initialize(const QString &runtimeFile);
		bool generate(ast::Program *program);
	private:
		bool addRuntimeFunctions();
		bool addFunctions(ast::Program *program);
		bool checkMainScope(ast::Program *program);
		bool checkFunctions();
		bool evaluateConstants(ast::Program *program);
		bool addGlobalsToScope(ast::Program *program);
		bool addTypesToScope(ast::Program *program);
		Runtime mRuntime;
		StringPool mStringPool;
		ConstantExpressionEvaluator mConstEval;
		SymbolCollectorTypeChecker mTypeChecker;
		QList<ValueType*> mValueTypes;
		Scope mGlobalScope;
		Scope mMainScope;

		TypeSymbol *findTypeSymbol(const QString &typeName, QFile *f, int line);
		QList<CBFunction*> mCBFunctions;
	signals:
		void error(int code, QString msg, int line, QFile *file);
		void warning(int code, QString msg, int line, QFile *file);
};

#endif // CODEGENERATOR_H
