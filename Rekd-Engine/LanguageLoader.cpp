#include "LanguageLoader.h"

Rekd2D::Core::LanguageLoader::LanguageLoader()
{
}

bool Rekd2D::Core::LanguageLoader::Load(const std::string& file)
{
	std::ifstream f(file);

	if (f.is_open())
	{
		while (!f.eof())
		{
			f.ignore(5, '"');
			std::string langCode;
			char x;
			while ((f.peek() != '"') && (f >> x)) langCode += x;
			f.ignore(1, '"');
			f.ignore(10, '"');
			std::string langFile;
			char y;
			while ((f.peek() != '"') && (f >> y)) langFile += y;
			f.ignore(1, '"');
			std::map<std::string, std::string> lang;
			std::ifstream lf(langFile);
			if (lf.is_open())
			{
				while (!lf.eof())
				{
					lf.ignore(5, '"');
					std::string key;
					char z;
					while ((lf.peek() != '"') && (lf >> z)) key += z;
					lf.ignore(1, '"');
					lf.ignore(10, '"');
					std::string value;
					char a;
					while ((lf.peek() != '"') && (lf >> a)) value += a;
					lf.ignore(1, '"');
					lang.insert(std::pair<std::string, std::string>(key, value));
				}
				std::cout << "Loaded " << langFile << " (" << langCode << ")" << std::endl;
			}
			langs.insert(std::pair<std::string, std::map<std::string, std::string>>(langCode, lang));
		}
		std::cout << "Loaded " << file << std::endl;
	}
	else return false;
	return true;
}

void Rekd2D::Core::LanguageLoader::Set(const std::string& lang, const std::string& key, const std::string& value)
{
	std::map<std::string, std::map<std::string, std::string>>::iterator it = langs.find(lang);
	if (it == langs.end())
	{
		langs.insert(std::pair<std::string, std::map<std::string, std::string>>(lang, std::map<std::string, std::string>()));
	}
	std::map<std::string, std::string>::iterator it2 = langs[lang].find(key);
	if (it2 == langs[lang].end())
	{
		langs[lang].insert(std::pair<std::string, std::string>(key, value));
	}
	else
	{
		langs[lang][key] = value;
	}
}

void Rekd2D::Core::LanguageLoader::SetDefault(const std::string& lang, const std::string& key, const std::string& value)
{
	std::map<std::string, std::map<std::string, std::string>>::iterator it = langs.find(lang);
	if (it == langs.end())
	{
		langs.insert(std::pair<std::string, std::map<std::string, std::string>>(lang, std::map<std::string, std::string>()));
	}
	std::map<std::string, std::string>::iterator it2 = langs[lang].find(key);
	if (it2 == langs[lang].end())
	{
		langs[lang].insert(std::pair<std::string, std::string>(key, value));
	}
}

std::string Rekd2D::Core::LanguageLoader::Get(const std::string& lang, const std::string& key, const std::string& callback)
{
	std::map<std::string, std::map<std::string, std::string>>::iterator it = langs.find(lang);
	if (it == langs.end())
	{
		return callback;
	}
	std::map<std::string, std::string>::iterator it2 = langs[lang].find(key);
	if (it2 == langs[lang].end())
	{
		return callback;
	}
	return langs[lang][key];
}