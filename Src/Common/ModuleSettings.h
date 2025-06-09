#pragma once

#include "Parameters.h"
#include <string>
#include <unordered_map>

enum setting_t {
  T_BOOL,
  T_LONG,
  T_LONGSPIN,
  T_STRING
};

typedef struct _SModuleSettings SModuleSettings;

struct _SModuleSettings {
  int iParameter;
  setting_t iType;
  int iMin;
  int iMax;
  int iDivisor;
  int iStep;
  const char *szDescription;
};

enum SettingsType
{
  Switch,
  TextField,
  Slider,
  Enum,
  Step
};

namespace Dasher {
  namespace Settings {
    struct ModuleSetting
    {
      SettingsType Type;
      ModuleSetting(SettingsType Type, Dasher::Parameter Param, std::string Name, std::string Description, bool AdvancedSetting) : Type(Type), Param(Param), Description(Description), Name(Name), AdvancedSetting(AdvancedSetting) {}
      virtual ~ModuleSetting() {};

      bool operator<(const ModuleSetting& other) const
      {
          return Name < other.Name;
      }
      
      std::string Name;
      std::string Description;
      Dasher::Parameter Param;
      bool AdvancedSetting;
    };
    
    struct TextboxSetting : ModuleSetting {
      TextboxSetting(Dasher::Parameter Param, std::string Name, std::string Description, bool AdvancedSetting) : ModuleSetting(SettingsType::TextField, Param, Name, Description, AdvancedSetting) {}
    };
    
    struct SliderSetting : ModuleSetting {
      SliderSetting(Dasher::Parameter Param, std::string Name, std::string Description, bool AdvancedSetting, int min, int max, int step) : ModuleSetting(SettingsType::Slider, Param, Name, Description, AdvancedSetting), min(min), max(max), step(step) {};
      int min;
      int max;
      int step;
    };

    struct SpinSetting : ModuleSetting {
      SpinSetting(Dasher::Parameter Param, std::string Name, std::string Description, bool AdvancedSetting, int min, int max, int step) : ModuleSetting(SettingsType::Step, Param, Name, Description, AdvancedSetting), min(min), max(max), step(step) {}
      int min;
      int max;
      int step;
    };

    struct EnumSetting : ModuleSetting {
      EnumSetting(Dasher::Parameter Param, std::string Name, std::string Description, bool AdvancedSetting, std::unordered_map<std::string, int> Enums) : ModuleSetting(SettingsType::Enum, Param, Name, Description, AdvancedSetting), Enums(Enums) {};
      std::unordered_map<std::string, int> Enums;
    };

    struct SwitchSetting : ModuleSetting {
      SwitchSetting(Dasher::Parameter Param, std::string Name, std::string Description, bool AdvancedSetting) : ModuleSetting(SettingsType::Switch, Param, Name, Description, AdvancedSetting) {};
    };
  }
}