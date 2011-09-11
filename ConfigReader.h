#ifndef __CONFIGREADER_H__
#define __CONFIGREADER_H__

#include <string>
#include <map>

namespace evolver {

  class Settings;

  enum ConfigType { SCREEN, KEY };

  const std::string SEPARATOR = " = ";

  const std::string SCREEN_HEADER = "Screen";
  const std::string KEY_HEADER = "Keyboard";

  class ConfigReader {
  public:
    ConfigReader (void);
    ~ConfigReader (void);
    ConfigReader (const ConfigReader &original);

    ConfigReader &operator= (const ConfigReader &rhs);

    Settings *getSettings (enum ConfigType config);

    void addSettings (enum ConfigType config, Settings *setting);

    bool loadConfig (const char *configPath);
    bool writeConfig (const char *configPath);    
    
  protected:
    void copyConfigReader (const ConfigReader &original);

  private:
    std::map<enum ConfigType, Settings*> *settings;
  };

}

#endif
