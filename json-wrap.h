#ifndef _RAPIDJSON_WRAP_H__
#define _RAPIDJSON_WRAP_H__

#include "document.h"
#include "writer.h"
#include "stringbuffer.h"

RAPIDJSON_NAMESPACE_BEGIN

class Json
{
public:
	Json() {}
	~Json() {}

public:
	void parse(const std::string& jsonFormat) {
		_json.Parse(jsonFormat.c_str());
	}

public:
	template<typename T>
	T get(const std::string& key) {
		if (_json.HasMember(key.c_str())) {
			return static_cast<T>(_json[key.c_str()].GetInt());
		}
		return NULL;
	}

private:
	rapidjson::Document _json;
};

RAPIDJSON_NAMESPACE_END

#endif