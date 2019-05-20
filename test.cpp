#include "json-wrap.h"

struct TraditionObject1 {
	char c;
};

struct TraditionObject {
	std::string key1;
	bool key2;
	char key3;
	TraditionObject1 *key4;
};

struct Tradition {
	int64_t userID;
	int tableID;
	int seatID;
	TraditionObject* traditionObject;
};

void testJsonWrap1()
{
	std::string jsonFormat = "{\"value\": 123}";
	rapidjson::Json json;
	json.parse(jsonFormat);
	int value = json.get<int>("value");
	return;
}

void testJsonWrap2()
{

	return;
}

void testTraditionRapidJson()
{
	rapidjson::Document document;
	document.SetObject();
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
	document.AddMember<int64_t>("userID", (int64_t)INT_MAX * 10, allocator);
	document.AddMember<int>("tableID", INT_MAX, allocator);
	document.AddMember<int>("seatID", INT_MIN, allocator);
	rapidjson::Value object(rapidjson::kObjectType);
	object.AddMember("key1", rapidjson::Value("Value1", allocator), allocator);
	object.AddMember("key2", true, allocator);
	object.AddMember("key3", NULL, allocator);
	rapidjson::Value object1(rapidjson::kObjectType);
	object1.AddMember<char>("c", 'a', allocator);
	object.AddMember("key4", object1, allocator);
	document.AddMember("object", object, allocator);

	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	document.Accept(writer);
	std::string result = buffer.GetString();

	Tradition *tradition = new Tradition;
	rapidjson::Document documentResult;
	documentResult.Parse(result.c_str());
	tradition->userID = documentResult["userID"].GetInt64();
	tradition->tableID = documentResult["tableID"].GetInt();
	tradition->tableID = documentResult["tableID"].GetInt();
	tradition->traditionObject = new TraditionObject;
	tradition->traditionObject->key4 = new TraditionObject1;
	tradition->traditionObject->key1 = documentResult["object"]["key1"].GetString();
	tradition->traditionObject->key2 = documentResult["object"]["key2"].GetBool();
	tradition->traditionObject->key3 = documentResult["object"]["key3"].GetInt();
	tradition->traditionObject->key4->c = documentResult["object"]["key4"]["c"].GetInt();

	delete tradition->traditionObject->key4;
	delete tradition->traditionObject;
	delete tradition;
	return;
}

int main()
{
	testJsonWrap1();
	testTraditionRapidJson();
	system("pause");
	return 1;
}