#include "Parameters.h"

#include "DasherTypes.h"

namespace Dasher{
  namespace Settings {

	const std::unordered_map<Parameter, const Parameter_Value> parameter_defaults = {
        {BP_DRAW_MOUSE_LINE       , Parameter_Value{"DrawMouseLine"        , PARAM_BOOL, Persistence::PERSISTENT, true , "Draw Mouse Line", "", Settings::UIControlType::Switch}},
		{BP_DRAW_MOUSE            , Parameter_Value{"DrawMouse"            , PARAM_BOOL, Persistence::PERSISTENT, true , "Draw Mouse Position", "", Settings::UIControlType::Switch}},
		{BP_CURVE_MOUSE_LINE      , Parameter_Value{"CurveMouseLine"       , PARAM_BOOL, Persistence::PERSISTENT, false, "Curve mouse line according to screen nonlinearity", "", Settings::UIControlType::Switch}},
		{BP_START_MOUSE           , Parameter_Value{"StartOnLeft"          , PARAM_BOOL, Persistence::PERSISTENT, true , "StartOnLeft", "", Settings::UIControlType::Switch}},
		{BP_START_SPACE           , Parameter_Value{"StartOnSpace"         , PARAM_BOOL, Persistence::PERSISTENT, false, "StartOnSpace", "", Settings::UIControlType::Switch}},
		{BP_PALETTE_CHANGE        , Parameter_Value{"PaletteChange"        , PARAM_BOOL, Persistence::PERSISTENT, false , "Switch from color palette in setting automatically to the one provided in the alphabet"}},
		{BP_TURBO_MODE            , Parameter_Value{"TurboMode"            , PARAM_BOOL, Persistence::PERSISTENT, true , "Boost speed when holding key1 or right mouse button", "", Settings::UIControlType::Switch}},
		{BP_SMOOTH_PRESS_MODE     , Parameter_Value{"SmoothPressMode"      , PARAM_BOOL, Persistence::PERSISTENT, true , "Use Press-Input in the Smoothing-Input-Filter", "", Settings::UIControlType::Switch}},
		{BP_SMOOTH_DRAW_MOUSE     , Parameter_Value{"SmoothDrawMouse"      , PARAM_BOOL, Persistence::PERSISTENT, false, "Draw an additional mouse cursor for the actual mouse position.", "", Settings::UIControlType::Switch}},
		{BP_SMOOTH_DRAW_MOUSE_LINE, Parameter_Value{"SmoothDrawMouseLine"  , PARAM_BOOL, Persistence::PERSISTENT, false, "Draw an additional mouse cursor line for the actual mouse position.", "", Settings::UIControlType::Switch}},
		{BP_SMOOTH_ONLY_FORWARD   , Parameter_Value{"SmoothOnlyForward"    , PARAM_BOOL, Persistence::PERSISTENT, true , "In the Smoothing-Input-Filter, only apply smoothing if the cursor is moving forward", "", Settings::UIControlType::Switch}},
		{BP_EXACT_DYNAMICS        , Parameter_Value{"ExactDynamics"        , PARAM_BOOL, Persistence::PERSISTENT, false, "Use exact computation of per-frame movement (slower)", "", Settings::UIControlType::Switch}},
		{BP_AUTOCALIBRATE         , Parameter_Value{"Autocalibrate"        , PARAM_BOOL, Persistence::PERSISTENT, false, "Automatically learn TargetOffset e.g. gazetracking", "", Settings::UIControlType::Switch}},
		{BP_REMAP_XTREME          , Parameter_Value{"RemapXtreme"          , PARAM_BOOL, Persistence::PERSISTENT, false, "Pointer at extreme Y translates more and zooms less", "", Settings::UIControlType::Switch}},
		{BP_AUTO_SPEEDCONTROL     , Parameter_Value{"AutoSpeedControl"     , PARAM_BOOL, Persistence::PERSISTENT, true , "AutoSpeedControl", "", Settings::UIControlType::Switch}},
		{BP_LM_ADAPTIVE           , Parameter_Value{"LMAdaptive"           , PARAM_BOOL, Persistence::PERSISTENT, true , "Whether language model should learn as you enter text"}},
		{BP_NONLINEAR_Y           , Parameter_Value{"NonlinearY"           , PARAM_BOOL, Persistence::PERSISTENT, true , "Apply nonlinearities to Y axis (i.e. compress top &amp; bottom)"}},
		{BP_STOP_OUTSIDE          , Parameter_Value{"PauseOutside"         , PARAM_BOOL, Persistence::PERSISTENT, false, "Whether to stop when pointer leaves canvas area", "", Settings::UIControlType::Switch}},
#ifdef TARGET_OS_IPHONE                              
		{BP_BACKOFF_BUTTON       , Parameter_Value{"BackoffButton"        , PARAM_BOOL, Persistence::PERSISTENT, false, "Whether to enable the extra backoff button in dynamic mode", "", Settings::UIControlType::Switch}},
#else                                         
		{BP_BACKOFF_BUTTON        , Parameter_Value{"BackoffButton"        , PARAM_BOOL, Persistence::PERSISTENT, true , "Whether to enable the extra backoff button in dynamic mode", "", Settings::UIControlType::Switch}},
#endif                                          
		{BP_TWOBUTTON_REVERSE     , Parameter_Value{"TwoButtonReverse"     , PARAM_BOOL, Persistence::PERSISTENT, false, "Reverse the up/down buttons in two button mode", "", Settings::UIControlType::Switch}},
		{BP_2B_INVERT_DOUBLE      , Parameter_Value{"TwoButtonInvertDouble", PARAM_BOOL, Persistence::PERSISTENT, false, "Double-press acts as opposite button in two-button mode", "", Settings::UIControlType::Switch}},
		{BP_SLOW_START            , Parameter_Value{"SlowStart"            , PARAM_BOOL, Persistence::PERSISTENT, false, "Start at low speed and increase", "", Settings::UIControlType::Switch}},
		{BP_COPY_ALL_ON_STOP      , Parameter_Value{"CopyOnStop"           , PARAM_BOOL, Persistence::PERSISTENT, false, "Copy all text to clipboard whenever we stop"}},
		{BP_SPEAK_ALL_ON_STOP     , Parameter_Value{"SpeakOnStop"          , PARAM_BOOL, Persistence::PERSISTENT, false, "Speak all text whenever we stop"}},
		{BP_SPEAK_WORDS           , Parameter_Value{"SpeakWords"           , PARAM_BOOL, Persistence::PERSISTENT, false, "Speak words as they are written"}},
		{BP_GAME_HELP_DRAW_PATH   , Parameter_Value{"GameDrawPath"         , PARAM_BOOL, Persistence::PERSISTENT, true , "When we give help, show the shortest path to the target sentence"}},
		{BP_TWO_PUSH_RELEASE_TIME , Parameter_Value{"TwoPushReleaseTime"   , PARAM_BOOL, Persistence::PERSISTENT, false, "Use push and release times of single press rather than push times of two presses", "", Settings::UIControlType::Switch}},
		{BP_SIMULATE_TRANSPARENCY , Parameter_Value{"SimulateTransparency" , PARAM_BOOL, Persistence::PERSISTENT, false, "Enable the internal color mixing and thus the need to support alpha blending in the renderer." }},
									 
		{LP_ORIENTATION           , Parameter_Value{ "ScreenOrientation"         , PARAM_LONG, Persistence::PERSISTENT, -2l  , "Screen Orientation"}},
		{LP_MAX_BITRATE           , Parameter_Value{ "MaxBitRateTimes100"        , PARAM_LONG, Persistence::PERSISTENT, 80l  , "Max Bit Rate Times 100", "", Settings::UIControlType::Step, 1, 1000, 1, 1}},
		{LP_FRAMERATE             , Parameter_Value{ "FrameRate"                 , PARAM_LONG, Persistence::EPHEMERAL , 3200l , "Decaying average of last known frame rates, *100"}},
		{LP_LANGUAGE_MODEL_ID     , Parameter_Value{ "LanguageModelID"           , PARAM_LONG, Persistence::PERSISTENT, 0l    , "LanguageModelID"}},
		{LP_DASHER_FONTSIZE       , Parameter_Value{ "DasherFontSize"            , PARAM_LONG, Persistence::PERSISTENT, 22l    , "Font size reached at crosshair (in points)"}},
		{LP_MESSAGE_FONTSIZE      , Parameter_Value{ "MessageFontSize"           , PARAM_LONG, Persistence::PERSISTENT, 14l   , "Size of font for messages (in points)"}},
		{LP_SHAPE_TYPE            , Parameter_Value{ "RenderStyle"               , PARAM_LONG, Persistence::PERSISTENT, static_cast<long>(Options::OVERLAPPING_RECTANGLE), "Shapes to render in (see Options::Rendering_Shape_Types)"}},
		{LP_START_MODE            , Parameter_Value{ "StartMode"                 , PARAM_LONG, Persistence::PERSISTENT, static_cast<long>(Options::StartMode::none), "Movement Starting Mode", "", Settings::UIControlType::Enum, {
			{"None", Options::StartMode::none},
			{"Circle Start", Options::StartMode::circle_start},
			{"Mouse Positon Start", Options::StartMode::mouse_pos_start}
		}}},
		{LP_UNIFORM               , Parameter_Value{ "UniformTimes1000"          , PARAM_LONG, Persistence::PERSISTENT, 50l   , "UniformTimes1000"}},
		{LP_MOUSEPOSDIST          , Parameter_Value{ "MousePositionBoxDistance"  , PARAM_LONG, Persistence::PERSISTENT, 50l   , "MousePositionBoxDistance"}},
		{LP_PY_PROB_SORT_THRES    , Parameter_Value{ "PYProbabilitySortThreshold", PARAM_LONG, Persistence::PERSISTENT, 85l   , "Sort converted syms in descending probability order up to this percentage"}},
		{LP_MESSAGE_TIME          , Parameter_Value{ "MessageTime"               , PARAM_LONG, Persistence::PERSISTENT, 2500l , "Time for which non-modal messages are displayed, in ms"}},
		{LP_LM_MAX_ORDER          , Parameter_Value{ "LMMaxOrder"                , PARAM_LONG, Persistence::PERSISTENT, 5l    , "LMMaxOrder"}},
		{LP_LM_EXCLUSION          , Parameter_Value{ "LMExclusion"               , PARAM_LONG, Persistence::PERSISTENT, 0l    , "LMExclusion" }},
		{LP_LM_UPDATE_EXCLUSION   , Parameter_Value{ "LMUpdateExclusion"         , PARAM_LONG, Persistence::PERSISTENT, 1l    , "LMUpdateExclusion"}},
		{LP_LM_ALPHA              , Parameter_Value{ "LMAlpha"                   , PARAM_LONG, Persistence::PERSISTENT, 49l   , "LMAlpha"}},
		{LP_LM_BETA               , Parameter_Value{ "LMBeta"                    , PARAM_LONG, Persistence::PERSISTENT, 77l   , "LMBeta"}},
		{LP_LM_MIXTURE            , Parameter_Value{ "LMMixture"                 , PARAM_LONG, Persistence::PERSISTENT, 50l   , "LMMixture"}},
		{LP_LINE_WIDTH            , Parameter_Value{ "LineWidth"                 , PARAM_LONG, Persistence::PERSISTENT, 1l    , "Width to draw crosshair and mouse line", "", Settings::UIControlType::Step, 0, 1000, 1, 1}},
		{LP_GEOMETRY              , Parameter_Value{ "Geometry"                  , PARAM_LONG, Persistence::PERSISTENT, static_cast<long>(Options::ScreenGeometry::old_style)    , "Screen geometry (mostly for tall thin screens) - see Options::ScreenGeometry", "", Settings::UIControlType::Enum, {
			{"Old Style", Options::ScreenGeometry::old_style},
			{"Square No xHair", Options::ScreenGeometry::square_no_xhair},
			{"Squish", Options::ScreenGeometry::squish},
			{"Squish and Log", Options::ScreenGeometry::squish_and_log}
		}}},
		{LP_LM_WORD_ALPHA         , Parameter_Value{ "WordAlpha"                 , PARAM_LONG, Persistence::PERSISTENT, 50l   , "Alpha value for word-based model"}},
		{LP_USER_LOG_LEVEL_MASK   , Parameter_Value{ "UserLogLevelMask"          , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Controls level of user logging, 0 = none, 1 = short, 2 = detailed, 3 = both"}},
		{LP_ZOOMSTEPS             , Parameter_Value{ "Zoomsteps"                 , PARAM_LONG, Persistence::PERSISTENT, 32l   , "Integerised ratio of zoom size for click/button mode, denom 64.", "", Settings::UIControlType::Step, 1, 63, 1, 1}},
		{LP_B                     , Parameter_Value{ "ButtonMenuBoxes"           , PARAM_LONG, Persistence::PERSISTENT, 4l    , "Number of boxes for button menu mode", "", Settings::UIControlType::Step, 2, 10, 1, 1}},
		{LP_S                     , Parameter_Value{ "ButtonMenuSafety"          , PARAM_LONG, Persistence::PERSISTENT, 25l   , "Safety parameter for button mode, in percent.", "", Settings::UIControlType::Step, 0, 256, 1, 1}},
#ifdef TARGET_OS_IPHONE           	 
		{LP_BUTTON_SCAN_TIME     , Parameter_Value{ "ButtonMenuScanTime"        , PARAM_LONG, Persistence::PERSISTENT, 600l  , "Scanning time in menu mode (0 = don't scan), in ms", "", Settings::UIControlType::Step, 0, 2000, 1, 100}},
#else                              
		{LP_BUTTON_SCAN_TIME      , Parameter_Value{ "ButtonMenuScanTime"        , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Scanning time in menu mode (0 = don't scan), in ms", "", Settings::UIControlType::Step, 0, 2000, 1, 100}},
#endif                             
		{LP_R                     , Parameter_Value{ "ButtonModeNonuniformity"   , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Button mode box non-uniformity", "", Settings::UIControlType::Step, -89, 89, 1, 10}},
		{LP_RIGHTZOOM             , Parameter_Value{ "ButtonCompassModeRightZoom", PARAM_LONG, Persistence::PERSISTENT, 5120l , "Zoomfactor (*1024) for compass mode", "", Settings::UIControlType::Step, 1024, 10240, 1024, 1024}},
#ifdef TARGET_OS_IPHONE           	 
		{LP_NODE_BUDGET          , Parameter_Value{ "NodeBudget"                , PARAM_LONG, Persistence::PERSISTENT, 1000l , "Target (min) number of node objects to maintain"}},
#else                              
		{LP_NODE_BUDGET           , Parameter_Value{ "NodeBudget"                , PARAM_LONG, Persistence::PERSISTENT, 3000l , "Target (min) number of node objects to maintain"}},
#endif                             
		{LP_OUTLINE_WIDTH         , Parameter_Value{ "OutlineWidth"              , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Absolute value is line width to draw boxes (fill iff >=0)" }},
		{LP_TEXT_PADDING          , Parameter_Value{ "TextPadding"               , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Pixel distance to inset the letters into the boxes" }},
		{LP_MIN_NODE_SIZE         , Parameter_Value{ "MinNodeSize"               , PARAM_LONG, Persistence::PERSISTENT, 50l   , "Minimum size of node (in dasher coords) to draw" }}, 
		{LP_NONLINEAR_X           , Parameter_Value{ "NonLinearX"                , PARAM_LONG, Persistence::PERSISTENT, 5l    , "Nonlinear compression of X-axis (0 = none, higher = more extreme)"}},
		{LP_AUTOSPEED_SENSITIVITY , Parameter_Value{ "AutospeedSensitivity"      , PARAM_LONG, Persistence::PERSISTENT, 100l  , "Sensitivity of automatic speed control (percent)"}},
		{LP_SOCKET_PORT           , Parameter_Value{ "SocketPort"                , PARAM_LONG, Persistence::PERSISTENT, 20320l, "UDP/TCP socket to use for network socket input"}},
		{LP_SOCKET_INPUT_X_MIN    , Parameter_Value{ "SocketInputXMinTimes1000"  , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Bottom of range of X values expected from network input"}},
		{LP_SOCKET_INPUT_X_MAX    , Parameter_Value{ "SocketInputXMaxTimes1000"  , PARAM_LONG, Persistence::PERSISTENT, 1000l , "Top of range of X values expected from network input"}},
		{LP_SOCKET_INPUT_Y_MIN    , Parameter_Value{ "SocketInputYMinTimes1000"  , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Bottom of range of Y values expected from network input"}},
		{LP_SOCKET_INPUT_Y_MAX    , Parameter_Value{ "SocketInputYMaxTimes1000"  , PARAM_LONG, Persistence::PERSISTENT, 1000l , "Top of range of Y values expected from network input"}},
		{LP_CIRCLE_PERCENT        , Parameter_Value{ "CirclePercent"             , PARAM_LONG, Persistence::PERSISTENT, 10l   , "Percentage of nominal vertical range to use for radius of start circle"}},
		{LP_TWO_BUTTON_OFFSET     , Parameter_Value{ "TwoButtonOffset"           , PARAM_LONG, Persistence::PERSISTENT, 1638l , "Offset for two button dynamic mode", "", Settings::UIControlType::Step, 1024, 2048, 2048, 100}},
		{LP_HOLD_TIME             , Parameter_Value{ "HoldTime"                  , PARAM_LONG, Persistence::PERSISTENT, 1000l , "Time for which buttons must be held to count as long presses, in ms"}},
		{LP_MULTIPRESS_TIME       , Parameter_Value{ "MultipressTime"            , PARAM_LONG, Persistence::PERSISTENT, 1000l , "Time in which multiple presses must occur, in ms", "", Settings::UIControlType::Step, 100, 10000, 1000, 100}},
		{LP_SLOW_START_TIME       , Parameter_Value{ "SlowStartTime"             , PARAM_LONG, Persistence::PERSISTENT, 1000l , "Time over which slow start occurs", "", Settings::UIControlType::Step, 0, 10000, 1000, 100}},
		{LP_SMOOTH_TAU            , Parameter_Value{ "SmoothTau"                 , PARAM_LONG, Persistence::PERSISTENT, 250l ,  "Factor Tau, that is used in smoothing input mode for exponential smoothing. Greater Zero, more smoothing the greater.", "", Settings::UIControlType::Step, 1, 1000, 1, 1}},
		{LP_TWO_PUSH_OUTER        , Parameter_Value{ "TwoPushOuter"              , PARAM_LONG, Persistence::PERSISTENT, 1792l , "Offset for one button dynamic mode outer marker", "", Settings::UIControlType::Step, 1024, 2048, 2048, 128}},
		{LP_TWO_PUSH_LONG         , Parameter_Value{ "TwoPushLong"               , PARAM_LONG, Persistence::PERSISTENT, 512l  , "Distance between down markers (long gap)", "", Settings::UIControlType::Step, 128, 1024, 2048, 128}},
		{LP_TWO_PUSH_SHORT        , Parameter_Value{ "TwoPushShort"              , PARAM_LONG, Persistence::PERSISTENT, 80l   , "Distance between up markers, as percentage of long gap", "", Settings::UIControlType::Step, 10, 90, 100, 1}},
		{LP_TWO_PUSH_TOLERANCE    , Parameter_Value{ "TwoPushTolerance"          , PARAM_LONG, Persistence::PERSISTENT, 100l  , "Tolerance of two-push-mode pushes, in ms", "", Settings::UIControlType::Step, 50, 1000, 1, 10}},
		{LP_DYNAMIC_BUTTON_LAG    , Parameter_Value{ "DynamicButtonLag"          , PARAM_LONG, Persistence::PERSISTENT, 50l   , "Lag of pushes in dynamic button mode (ms)", "", Settings::UIControlType::Step, 0, 1000, 1, 25}},
		{LP_STATIC1B_TIME         , Parameter_Value{ "Static1BTime"              , PARAM_LONG, Persistence::PERSISTENT, 2000l , "Time for static-1B mode to scan from top to bottom (ms)", "", Settings::UIControlType::Step, 100, 5000, 1, 100}},
		{LP_STATIC1B_ZOOM         , Parameter_Value{ "Static1BZoom"              , PARAM_LONG, Persistence::PERSISTENT, 8l    , "Zoom factor for static-1B mode", "", Settings::UIControlType::Step, 1, 16, 1, 1}},
		{LP_DEMO_SPRING           , Parameter_Value{ "DemoSpring"                , PARAM_LONG, Persistence::PERSISTENT, 100l  , "Springyness in Demo-mode", "", Settings::UIControlType::Step, 0, 1000, 1, 1}},
		{LP_DEMO_NOISE_MEM        , Parameter_Value{ "DemoNoiseMem"              , PARAM_LONG, Persistence::PERSISTENT, 100l  , "Memory parameter for noise in Demo-mode", "", Settings::UIControlType::Step, 0, 1000, 1, 1}},
		{LP_DEMO_NOISE_MAG        , Parameter_Value{ "DemoNoiseMag"              , PARAM_LONG, Persistence::PERSISTENT, 325l  , "Magnitude of noise in Demo-mode", "", Settings::UIControlType::Step, 0, 1000, 1, 1}},
		{LP_MAXZOOM               , Parameter_Value{ "ClickMaxZoom"              , PARAM_LONG, Persistence::PERSISTENT, 200l  , "Maximum zoom possible in click mode (times 10)", "", Settings::UIControlType::Step, 11, 400, 10, 1}},
		{LP_DYNAMIC_SPEED_INC     , Parameter_Value{ "DynamicSpeedInc"           , PARAM_LONG, Persistence::PERSISTENT, 3l    , "%age by which dynamic mode auto speed control increases speed", "", Settings::UIControlType::Step, 1, 100, 1, 1}},
		{LP_DYNAMIC_SPEED_FREQ    , Parameter_Value{ "DynamicSpeedFreq"          , PARAM_LONG, Persistence::PERSISTENT, 10l   , "Seconds after which dynamic mode auto speed control increases speed", "", Settings::UIControlType::Step, 1, 1000, 1 , 1}},
		{LP_DYNAMIC_SPEED_DEC     , Parameter_Value{ "DynamicSpeedDec"           , PARAM_LONG, Persistence::PERSISTENT, 8l    , "%age by which dynamic mode auto speed control decreases speed on reverse", "", Settings::UIControlType::Step, 1, 99, 1, 1}},
		{LP_TAP_TIME              , Parameter_Value{ "TapTime"                   , PARAM_LONG, Persistence::PERSISTENT, 200l  , "Max length of a stylus 'tap' rather than hold (ms)", "", Settings::UIControlType::Step, 1, 1000, 1, 25}},
#ifdef TARGET_OS_IPHONE           	 
		{LP_MARGIN_WIDTH         , Parameter_Value{ "MarginWidth"               , PARAM_LONG, Persistence::PERSISTENT, 500l  , "Width of RHS margin (in Dasher co-ords)"}},
#else                              
		{LP_MARGIN_WIDTH          , Parameter_Value{ "MarginWidth"               , PARAM_LONG, Persistence::PERSISTENT, 300l  , "Width of RHS margin (in Dasher co-ords)"}},
#endif                             
		{LP_TARGET_OFFSET         , Parameter_Value{ "TargetOffset"              , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Vertical distance between mouse pointer and target (400=screen height)", "", Settings::UIControlType::Step, -100, 100, 400, 1}},
		{LP_X_LIMIT_SPEED         , Parameter_Value{ "XLimitSpeed"               , PARAM_LONG, Persistence::PERSISTENT, 800l  , "X Co-ordinate at which maximum speed is reached (&lt;2048=xhair)", "", Settings::UIControlType::Step, 1, 8000, 1536, 1}},
		{LP_GAME_HELP_DIST        , Parameter_Value{ "GameHelpDistance"          , PARAM_LONG, Persistence::PERSISTENT, 1920l , "Distance of sentence from center to decide user needs help"}},
		{LP_GAME_HELP_TIME        , Parameter_Value{ "GameHelpTime"              , PARAM_LONG, Persistence::PERSISTENT, 0l    , "Time for which user must need help before help drawn"}},
								
								
		{SP_ALPHABET_ID          , Parameter_Value{ "AlphabetID"       , PARAM_STRING, Persistence::PERSISTENT, std::string("")              , "AlphabetID"}},
		{SP_ALPHABET_1           , Parameter_Value{ "Alphabet1"        , PARAM_STRING, Persistence::PERSISTENT, std::string("")              , "Alphabet History 1"}},
		{SP_ALPHABET_2           , Parameter_Value{ "Alphabet2"        , PARAM_STRING, Persistence::PERSISTENT, std::string("")              , "Alphabet History 2"}},
		{SP_ALPHABET_3           , Parameter_Value{ "Alphabet3"        , PARAM_STRING, Persistence::PERSISTENT, std::string("")              , "Alphabet History 3"}},
		{SP_ALPHABET_4           , Parameter_Value{ "Alphabet4"        , PARAM_STRING, Persistence::PERSISTENT, std::string("")              , "Alphabet History 4"}},
		{ SP_COLOUR_ID           , Parameter_Value{ "ColourID"         , PARAM_STRING, Persistence::PERSISTENT, std::string("Default")       , "ColourID" }},
		{SP_DASHER_FONT          , Parameter_Value{ "DasherFont"       , PARAM_STRING, Persistence::PERSISTENT, std::string("")              , "DasherFont"}},
		{SP_GAME_TEXT_FILE       , Parameter_Value{ "GameTextFile"     , PARAM_STRING, Persistence::PERSISTENT, std::string("")              , "User-specified file with strings to practice writing"}},
#ifdef TARGET_OS_IPHONE           
		{SP_INPUT_FILTER        , Parameter_Value{ "InputFilter"      , PARAM_STRING, Persistence::PERSISTENT, std::string("Stylus Control"), "Input filter used to provide the current control mode"}},
#else                             
		{SP_INPUT_FILTER         , Parameter_Value{ "InputFilter"      , PARAM_STRING, Persistence::PERSISTENT, std::string("Normal Control"), "Input filter used to provide the current control mode"}},
#endif                            
		{SP_INPUT_DEVICE         , Parameter_Value{ "InputDevice"      , PARAM_STRING, Persistence::PERSISTENT, std::string("Mouse Input")   , "Driver for the input device"}},
		{SP_BUTTON_MAPPINGS      , Parameter_Value{ "ButtonMap"        , PARAM_STRING, Persistence::PERSISTENT, std::string("")              , "Button assignments used in UI"}},
		{SP_JOYSTICK_XAXIS       , Parameter_Value{ "JoystickXAxis"    , PARAM_STRING, Persistence::PERSISTENT, std::string("")			  , "Joystick axis used for X-axis input"}},
		{SP_JOYSTICK_YAXIS       , Parameter_Value{ "JoystickYAxis"    , PARAM_STRING, Persistence::PERSISTENT, std::string("")			  , "Joystick axis used for Y-axis input"}}
	};

	ParameterType GetParameterType(Parameter parameter) {
		if (parameter_defaults.find(parameter) != parameter_defaults.end())
		{
			return parameter_defaults.at(parameter).type;
		}
		return PARAM_INVALID;
	}

	std::pair<Parameter, ParameterType> GetParameter(const std::string& parameterName) {

		for(auto& [key, value] : parameter_defaults)
		{
			if(value.storageName == parameterName) return {key, value.type};
		}
		return {PM_INVALID, PARAM_INVALID};
	}

	std::string GetParameterName(Parameter parameter) {
		if (parameter_defaults.find(parameter) != parameter_defaults.end())
		{
			return parameter_defaults.at(parameter).storageName;
		}
		return "";
	}

} //end namespace Settings
} //end namespace Dasher
