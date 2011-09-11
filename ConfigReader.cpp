#include <string>
#include <map>
#include <iostream>
#include <fstream>

#include "Settings.h"
#include "ConfigReader.h"

namespace evolver {
  
  ConfigReader::ConfigReader () {
    this->configPath = "";
    this->settings = new std::map<enum ConfigType, Settings*>();
  }

  ConfigReader::~ConfigReader () {
    delete this->settings;
  }

  ConfigReader::ConfigReader (const ConfigReader &original) {
    this->copyConfigReader(original);
  }

  ConfigReader &ConfigReader::operator= (const ConfigReader &rhs) {
    if (this != &rhs) {
      this->copyConfigReader(rhs);
    }

    return *this;
  }

  std::string ConfigReader::getConfigPath () {
    return this->configPath;
  }

  Settings *ConfigReader::getSettings (enum ConfigType config) {
    return *(this->settings)[config];
  }

  void ConfigReader::setConfigPath (std::string configPath) {
    this->configPath = configPath;

    return;
  }

  void ConfigReader::addSettings (enum ConfigType config, 
				  Settings *setting) {
    *(this->settings)[config] = setting;

    return;
  }

  bool ConfigReader::loadConfig (const char *configPath) {
    bool success;
    std::ifstream config;
    std::string configType;
    std::string option, value;
  
  }

  void ConfigReader::copyConfigReader (const ConfigReader &original) {
    this->configPath = original.configPath;
    *(this->settings) = *(original.settings);

    return;
  }

}
