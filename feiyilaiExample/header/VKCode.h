#pragma once
#include <string>
#include <unordered_map>

class VKCode
{
public:
	VKCode();
	~VKCode();

public:
	int GetVKCode(const std::string& key) const;
	int GetFKCode(const std::string& key) const;

private:
	std::unordered_map<std::string, int> m_VKCode;
	std::unordered_map<std::string, int> m_FKCode;
};

