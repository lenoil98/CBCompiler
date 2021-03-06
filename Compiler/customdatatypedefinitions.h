#ifndef CUSTOMDATATYPEDEFINITIONS_H
#define CUSTOMDATATYPEDEFINITIONS_H
#include <QString>
#include <QObject>
#include "codepoint.h"

class CustomDataTypeDefinitions : public QObject {
		Q_OBJECT
	public:
		struct CustomDataType {
				/** CB type name*/
				QString mName;

				/** LLVM type name*/
				QString mDataType;
		};

		CustomDataTypeDefinitions(QObject *parent = 0);
		~CustomDataTypeDefinitions();

		bool parse(const QString &file);
		const QList<CustomDataType> &dataTypes() const { return mDataTypes; }
	signals:
		void error(int code, QString msg, CodePoint cp);
		void warning(int code, QString msg, CodePoint cp);
	private:
		void invalidFormatError(const QString &file);
		bool parseDataType(QJsonObject obj, CustomDataType &ret);


		QList<CustomDataType> mDataTypes;
};

#endif // CUSTOMDATATYPEDEFINITIONS_H
