#include "PressFilter.h"
#include "I18n.h"
#include "Parameters.h"
#include "SettingsStore.h"

Dasher::CPressFilter::CPressFilter(CSettingsStore* pSettingsStore, CDasherInterfaceBase* pInterface, CFrameRate* pFramerate, const char *szName) : CDefaultFilter(pSettingsStore, pInterface, pFramerate, szName)
{
	declareSwitchSetting(BP_LM_ADAPTIVE, _("Switch Setting 1"), _("Test Description"));
	declareSwitchSetting(BP_LM_ADAPTIVE, _("Switch Setting 2"), _("Test Description"));

    declareDropdownSetting(LP_GEOMETRY, "Dropdown Setting 1", "Test Description",  {
        {"Old Style", Dasher::Options::ScreenGeometry::old_style},
        {"Square without Crosshair", Dasher::Options::ScreenGeometry::square_no_xhair},
        {"Squish", Dasher::Options::ScreenGeometry::squish},
        {"Squaish + Log", Dasher::Options::ScreenGeometry::squish_and_log},
    });
	declareDropdownSetting(LP_GEOMETRY, "Dropdown Setting 2", "Test Description",  {
        {"Old Style", Dasher::Options::ScreenGeometry::old_style},
        {"Square without Crosshair", Dasher::Options::ScreenGeometry::square_no_xhair},
        {"Squish", Dasher::Options::ScreenGeometry::squish},
        {"Squaish + Log", Dasher::Options::ScreenGeometry::squish_and_log},
    });

	declareTextboxSetting(SP_ALPHABET_3, "Textbox Setting 1", "Test Description");
	declareTextboxSetting(SP_ALPHABET_3, "Textbox Setting 2", "Test Description");

	declareSliderSetting(LP_MAX_BITRATE, "Slider Setting 1", "Test Description", 1, 1000, 10);
	declareSliderSetting(LP_MAX_BITRATE, "Slider Setting 2", "Test Description", 1, 1000, 50);

	declareSpinButtonSetting(LP_X_LIMIT_SPEED, "Spin Setting 1", "Test Description", 1, 1000, 10);
	declareSpinButtonSetting(LP_X_LIMIT_SPEED, "Spin Setting 2", "Test Description", 1, 1000, 50);
}

void Dasher::CPressFilter::KeyDown(unsigned long iTime, Keys::VirtualKey Key, CDasherView* pDasherView, CDasherInput* pInput, CDasherModel* pModel)
{
	if ((Key == Keys::Big_Start_Stop_Key && m_pSettingsStore->GetBoolParameter(BP_START_SPACE))
		|| (Key == Keys::Primary_Input && m_pSettingsStore->GetBoolParameter(BP_START_MOUSE)))
	{
		run(iTime);
	}
	else if (Key == Keys::Secondary_Input || Key == Keys::Tertiary_Input || Key == Keys::Button_1)
	{
		//Other mouse buttons, if platforms support; or button 1
		if (m_pSettingsStore->GetBoolParameter(BP_TURBO_MODE)) m_bTurbo = true;
	}
}

void Dasher::CPressFilter::KeyUp(unsigned long iTime, Keys::VirtualKey Key, CDasherView* pView, CDasherInput* pInput, CDasherModel* pModel)
{
	if ((Key == Keys::Big_Start_Stop_Key && m_pSettingsStore->GetBoolParameter(BP_START_SPACE)) || (Key == Keys::Primary_Input && m_pSettingsStore->GetBoolParameter(BP_START_MOUSE)))
	{
		stop();
	}
	else if (Key == Keys::Secondary_Input || Key == Keys::Tertiary_Input || Key == Keys::Button_1) m_bTurbo = false;
}