#ifndef __CONFIGREADER_H__
#define __CONFIGREADER_H__

#include <string>
#include <vector>

#include "Settings.h"

namespace evolver {

  const std::string SEPARATOR = " = ";

  const std::string SCREEN_HEADER = "Screen";
  const std::string KEY_HEADER = "Keyboard";

  class ConfigReader {
  public:
    ConfigReader (void);
    ~ConfigReader (void);
    ConfigReader (const ConfigReader &original);

    ConfigReader &operator= (const ConfigReader &rhs);

    std::string getConfigPath (void);

    void setConfigPath (std::string configPath);

    bool loadConfig (void);
    bool writeConfig (void);    
    
  protected:
    void copyConfigReader (const ConfigReader &original);

  private:
    std::string configPath;
    std::vector<Setting*> settings;
  };

}

#endif
