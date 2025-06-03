// DasherModule.h
// 
// Copyright (c) 2008 The Dasher Team
//
// This file is part of Dasher.
//
// Dasher is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//  
// Dasher is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with Dasher; if not, write to the Free Software 
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#pragma once

#include "../Common/ModuleSettings.h"
#include <memory>
#include <vector>

class CDasherModule;

/// \ingroup Core
/// @{
class CDasherModule {
public:
    CDasherModule(const char *szName);
    virtual ~CDasherModule() = default;

    virtual const char *GetName();

    virtual bool GetSettings(SModuleSettings **pSettings, int *iCount) {
        return false;
    }

private:
    const char *m_szName;

public:
    // "New" UI Settings definitions:
    typedef std::vector<std::unique_ptr<Dasher::Settings::ModuleSetting>> UISettingList;
    // Fill this list using the provided methods below to define which UI components could be used by the UI to change your respective setting
    virtual void GetUISettings(UISettingList& List){};
    static void DeclareTextboxSetting(UISettingList& List, Dasher::Parameter Param, std::string Name, std::string Description){List.push_back(std::make_unique<Dasher::Settings::TextboxSetting>(Param, Name, Description));}
    static void DeclareSliderSetting(UISettingList& List, Dasher::Parameter Param, std::string Name, std::string Description, int min, int max, int step){List.push_back(std::make_unique<Dasher::Settings::SliderSetting>(Param, Name, Description, min, max, step));}
    static void DeclareSpinButtonSetting(UISettingList& List, Dasher::Parameter Param, std::string Name, std::string Description, int min, int max, int step){List.push_back(std::make_unique<Dasher::Settings::SpinSetting>(Param, Name, Description, min, max, step));}
    static void DeclareDropdownSetting(UISettingList& List, Dasher::Parameter Param, std::string Name, std::string Description, std::unordered_map<std::string, int> Enums){List.push_back(std::make_unique<Dasher::Settings::EnumSetting>(Param, Name, Description, Enums));}
    static void DeclareSwitchSetting(UISettingList& List, Dasher::Parameter Param, std::string Name, std::string Description){List.push_back(std::make_unique<Dasher::Settings::SwitchSetting>(Param, Name, Description));}
};
/// @}

