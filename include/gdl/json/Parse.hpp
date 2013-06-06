#ifndef GDL_JSON_PARSE_HPP
#define GDL_JSON_PARSE_HPP

#include <gdl/json/Value.hpp>
#include <gdl/json/Object.hpp>
#include <gdl/json/Array.hpp>
#include <gdl/json/String.hpp>

#include <algorithm>
#include <cassert>
#include <sstream>

namespace gdl
{
namespace json
{

namespace
{

std::shared_ptr<json::Object> parseObject(const std::string&);
std::shared_ptr<json::Array> parseArray(const std::string&);
std::string parseString(const std::string&);
std::shared_ptr<json::String> parseValue(const std::string&);
std::string between(const std::string&, const char, const char);
std::vector<std::string> split(const std::string&, const char);

}

json::Object parse(std::string json)
{
	json.erase(std::remove_if(json.begin(), json.end(), ::isspace), json.end());
	assert(*json.begin() == '{' && *json.rbegin() == '}');

	json::Object obj;

	std::string object = between(json, '{', '}');
	std::vector<std::string> items = split(object, ',');

	for (const auto& item : items)
	{
		std::string string = parseString(item);
		switch (*(item.begin()+string.size()+3))
		{
			case '{':
			{
				obj.insert(std::make_pair(string, parseObject(item.substr(string.size()+3, item.size()))));
				break;
			}
			case '[':
			{
				obj.insert(std::make_pair(string, parseArray(item.substr(string.size()+3, item.size()))));
				break;
			}
			default:
			{
				obj.insert(std::make_pair(string, parseValue(item.substr(string.size()+3, item.size()))));
			}
		}
	}

	return obj;
}

namespace
{

std::shared_ptr<json::Object> parseObject(const std::string& json)
{
	assert(*json.begin() == '{' && *json.rbegin() == '}');

	auto obj = std::make_shared<json::Object>();

	std::string object = between(json, '{', '}');
	std::vector<std::string> items = split(object, ',');

	for (const auto& item : items)
	{
		std::string string = parseString(item);
		switch (*(item.begin()+string.size()+3))
		{
			case '{':
			{
				obj->insert(std::make_pair(string, parseObject(item.substr(string.size()+3, item.size()))));
				break;
			}
			case '[':
			{
				obj->insert(std::make_pair(string, parseArray(item.substr(string.size()+3, item.size()))));
				break;
			}
			default:
			{
				obj->insert(std::make_pair(string, parseValue(item.substr(string.size()+3, item.size()))));
			}
		}
	}

	return obj;
}

std::shared_ptr<json::Array> parseArray(const std::string& json)
{
	assert(*json.begin() == '[' && *json.rbegin() == ']');

	std::string array = between(json, '[', ']');
	std::vector<std::string> items = split(array, ',');
	auto result = std::make_shared<json::Array>();

	for (const auto& item : items)
	{
		auto v = std::make_shared<json::String>(between(item, '"', '"'));
		result->push_back(v);
	}

	return result;
}

std::string parseString(const std::string& json)
{
	assert(json.front() == '"');

	size_t start = json.find("\"")+1;
	size_t end = json.find_first_of("\"", start);
	return json.substr(start, end-start);
}

std::shared_ptr<json::String> parseValue(const std::string& json)
{
	// TODO: true, false, number check
	assert(json.front() == '"');

	size_t start = json.find("\"")+1;
	size_t end = json.find_first_of("\"", start);

	auto out = std::make_shared<json::String>(json.substr(start, end-start));
	return out;
}

std::string between(const std::string& str, const char start, const char end)
{
	assert(std::count(str.begin(), str.end(), start) && std::count(str.begin(), str.end(), end));

	size_t startpos = str.find(start)+1;
	size_t endpos = str.rfind(end);
	return str.substr(startpos, endpos-startpos);
}

std::vector<std::string> split(const std::string& json, const char delimiter)
{
	std::vector<std::string> result;

	std::istringstream ss(json);
	std::string token, buffer;
	unsigned int objectOpenCount = 0, arrayOpenCount = 0, objectCloseCount = 0, arrayCloseCount = 0;

	while (std::getline(ss, token, delimiter))
	{
		objectOpenCount += std::count(token.begin(), token.end(), '{');
		arrayOpenCount += std::count(token.begin(), token.end(), '[');
		objectCloseCount += std::count(token.begin(), token.end(), '}');
		arrayCloseCount += std::count(token.begin(), token.end(), ']');

		if (objectOpenCount == objectCloseCount && arrayOpenCount == arrayCloseCount)
		{
			if (buffer.size() > 0)
			{
				token = (buffer += token);

				buffer.clear();
				objectOpenCount = 0;
				arrayOpenCount = 0;
				objectCloseCount = 0;
				arrayCloseCount = 0;
			}
			result.push_back(token);
		}
		else
		{
			buffer += token + delimiter;
		}
	}

	return result;
}
}

}
}

#endif // GDL_JSON_PARSE_HPP
