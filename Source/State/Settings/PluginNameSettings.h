/*
  ==============================================================================

    PluginNameSettings.h
    Created: 10 Jan 2022 1:19:26pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

//==============================================================================
class PluginNameSettings {
public:
    //==============================================================================
    enum Settings {
        PNS_GUIScale = 0,
        PNS_showSidePanel,
        PNS_showHoverTips,
        PNS_defaultPresetName,
        PNS_TotalNumSettings
    };
    
    //==============================================================================
    inline static const juce::String IDs[PNS_TotalNumSettings] =
    {
        "GUIScale",
        "showSidePanel",
        "showHoverTips",
        "defaultPresetName"
    };
    
    inline static const juce::var Values[PNS_TotalNumSettings] =
    {
        1.0,
        false,
        true,
        "Default"
    };
    
    inline static bool showSidePanel;
};
