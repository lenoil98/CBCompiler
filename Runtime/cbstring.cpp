#include "cbstring.h"
std::string String::staticEmptyString;

String::String(CB_StringData *d) :
	mData(d) {
	if (mData) mData->increase();
}

String::String(const char *txt) :
	mData(0) {
	if (txt && txt[0] != 0) {
		mData = new CB_StringData(txt);
	}
}

String::String(const std::string &s) :
	mData(0) {
	if (!s.empty()) {
		mData = new CB_StringData(s);
	}
}

String::String(const String &o) : mData(o.mData) {
	if (mData) mData->increase();
}

String & String::operator=(const String &o) {
	CB_StringData *tD = this->mData;
	this->mData = o.mData;
	if (this->mData) this->mData->increase();
	if (tD) {
		if (mData->decrease()) {
			delete mData;
		}

	}
	return *this;
}

String String::operator +(const String &a) {
	if (this->mData == 0) return a;
	if (a.mData == 0) return *this;
	return this->mData->mString + a.mData->mString;
}


String::~String() {
	if (mData) {
		if (mData->decrease()) { //No more references
			delete mData;
		}
	}
}

const std::string &String::getRef() const {
	if (mData) {
		return mData->mString;
	}
	return staticEmptyString;
}

CBString String::returnCBString() {
	if (mData)
		mData->increase();
	return mData;
}


void CB_StringData::increase() {
	mRefCount.increase();
}

bool CB_StringData::decrease() {
	return !mRefCount.decrease();
}



//CBF

extern "C" CBString CBF_CB_StringConstruct (const char *txt) {
	if (txt) {
		return new CB_StringData(txt);
	}
	return 0;
}

extern "C" void CBF_CB_StringDestruct (CBString str) {
	if (str)
		if (str->decrease()) delete str;
}

extern "C" void CBF_CB_StringAssign(CBString *target, CBString s) {
	if ((*target)) {
		if((*target)->decrease()) {
			delete *target;
		}
	}
	if (s) {
		s->increase();
	}
	*target = s;
}


extern "C" CBString CBF_CB_StringAddition(CBString a, CBString b) {
	if (!a) {
		if (b) b->increase();
		return b;
	}
	if (!b) {
		if (a) a->increase();
		return a;
	}
	return new CB_StringData(a->mString + b->mString);
}

extern "C" int CBF_CB_StringToInt(CBString s) {
	if (!s) return 0;
	try {
		return boost::lexical_cast<int>(s->mString);
	}catch(boost::bad_lexical_cast &) {
		return 0;
	}
}

extern "C" float CBF_CB_StringToFloat(CBString s) {
	if (!s) return 0;
	try {
		return boost::lexical_cast<float>(s->mString);
	}catch(boost::bad_lexical_cast &) {
		return 0;
	}
}

extern "C" CBString CBF_CB_FloatToString(float f) {
	return new CB_StringData(boost::lexical_cast<std::string>(f));
}

extern "C" CBString CBF_CB_IntToString(int i) {
	return new CB_StringData(boost::lexical_cast<std::string>(i));
}


