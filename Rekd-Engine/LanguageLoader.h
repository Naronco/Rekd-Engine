#ifndef REKD_LANGUAGELOADER_H_
#define REKD_LANGUAGELOADER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <map>

namespace Rekd2D
{
	namespace Core
	{
		class LanguageLoader
		{
		public:
			LanguageLoader();

			bool Load(const std::string& file);
			void Set(const std::string& lang, const std::string& key, const std::string& value);
			void SetDefault(const std::string& lang, const std::string& key, const std::string& value);
			std::string Get(const std::string& lang, const std::string& key, const std::string& callback);
		protected:
			std::map<std::string, std::map<std::string, std::string>> langs;
		};
	}
}
#endif