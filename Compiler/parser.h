#ifndef PARSER_H
#define PARSER_H
#include <QObject>
#include "token.h"
#include "abstractsyntaxtree.h"

/**
 * @brief The Parser class parses a token list generated by Lexer and produces an abstract syntax tree.
 */
class Parser : public QObject
{
		Q_OBJECT
	public:
		typedef QList<Token>::ConstIterator TokIterator;
		Parser();

		/**
		 * @brief parse Parses a token list and generates an AST
		 * @param tokens Token list
		 * @return The abstract syntax tree generated
		 */
		ast::Program *parse(const QList<Token> &tokens);

		/**
		 * @brief success
		 * @return True, if parsing succeeded, false otherwise.
		 */
		bool success() {return mStatus == Ok;}

	private:
		ast::ConstDefinition *tryConstDefinition(TokIterator &i);
		ast::GlobalDefinition *tryGlobalDefinition(TokIterator &i);
		ast::Variable::VarType tryVarAsType(TokIterator &i);
		ast::Variable::VarType tryVarType(TokIterator &i);
		ast::Variable::VarType tryVarTypeSymbol(TokIterator &i);
		ast::Node *tryReturn(TokIterator &i);
		ast::TypeDefinition *tryTypeDefinition(TokIterator &i);
		ast::Variable *expectVariableOrTypePtrDefinition(TokIterator &i);
		ast::Variable *tryVariableOrTypePtrDefinition(TokIterator &i);
		ast::Node *trySelectStatement(TokIterator &i);
		ast::Node *tryGotoGosubAndLabel(TokIterator &i);
		ast::Node *tryRedim(TokIterator &i);
		void expectVariableOrTypePtrDefinition(ast::Variable *var, TokIterator &i);
		ast::Node *tryDim(TokIterator &i);
		ast::Node *tryIfStatement(TokIterator &i);
		ast::Node *expectElseIfStatement(TokIterator &i);
		ast::Node *tryWhileStatement(TokIterator &i);
		ast::Node *tryRepeatStatement(TokIterator &i);
		ast::Node *tryForStatement(TokIterator &i);
		ast::Node *tryFunctionOrCommandCallOrArraySubscriptAssignment(TokIterator &i);
		ast::Block expectBlock(TokIterator &i);
		ast::Block expectInlineBlock(TokIterator &i);

		ast::FunctionDefinition *tryFunctionDefinition(TokIterator &i);
		ast::FunctionParametreDefinition expectFunctionParametreDefinition(TokIterator &i);

		ast::Node *expectExpression(TokIterator &i);
		ast::Node *expectLogicalOrExpression(TokIterator &i);
		ast::Node *expectLogicalAndExpression(TokIterator &i);
		ast::Node *expectEqualityExpression(TokIterator &i);
		ast::Node *expectRelativeExpression(TokIterator &i);
		ast::Node *expectBitShiftExpression(TokIterator &i);
		ast::Node *expectAdditiveExpression(TokIterator &i);
		ast::Node *expectMultiplicativeExpression(TokIterator &i);
		ast::Node *expectPowExpression(TokIterator &i);
		ast::Node *expectUnaryExpession(TokIterator &i);
		ast::Node *expectPrimaryExpression(TokIterator &i);
		ast::Node *tryAssignmentExpression(TokIterator &i);
		QString expectIdentifier(TokIterator &i);
		void expectEndOfStatement(TokIterator &i);
		enum Status {
			Error,
			ErrorButContinue,
			Ok
		};
		Status mStatus;

	signals:
		void error(int code, QString msg, int line, QFile *file);
		void warning(int code, QString msg, int line, QFile *file);
};

#endif // PARSER_H
