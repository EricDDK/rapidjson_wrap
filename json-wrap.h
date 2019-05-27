#ifndef _RAPIDJSON_WRAP_H__
#define _RAPIDJSON_WRAP_H__

#include <string>
#include "document.h"
#include "writer.h"
#include "stringbuffer.h"

RAPIDJSON_NAMESPACE_BEGIN

class Json
{
public:
	Json() {}
	~Json() {}
	Json(const Json& j) {}
	Json& operator=(const Json& j)
	{
		return *this;
	}

	Json(bool b) {}
	Json(int i) {}
	Json(double d) {}
	Json(const char* c) {}
	Json(const std::string& s) {}

public:
	void parse(const std::string& jsonFormat) 
	{
        _json.Parse(jsonFormat.c_str());
	}

public:
	Json& operator[](const std::string& key)
	{
		return *this;
	}

	Json& operator[](const char* key)
	{
		return *this;
	}

	Json& operator[](size_t index)
	{
		return *this;
	}

private:
	rapidjson::Document _json;
};

RAPIDJSON_NAMESPACE_END

#endif
