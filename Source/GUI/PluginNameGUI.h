/*
  ==============================================================================

    PluginNameGUI.h
    Created: 25 Nov 2021 8:56:01am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

//==============================================================================
class PluginNameGUI {
public:
    static constexpr float ratio = 1.618f; // golden ratio
    static constexpr float height = 400,
                         width  = height * ratio;
    
    //==============================================================================
    class Scale {
    public:
        static constexpr float small = 0.8f,
        standard = 1.0f,
        large = 1.2f,
        extra_large = 1.4f,
        XXL = 2.0f;
    };
    
    //==============================================================================
    static constexpr int corner_size = 1, line_thickness = 1;
};

//==============================================================================
class MenuPanelGUI {
public:
    //==============================================================================
    static constexpr float width  = PluginNameGUI::width * 0.13f,
                         height = PluginNameGUI::height;
};

//==============================================================================
class PresetPanelGUI {
public:
    //==============================================================================
    static constexpr float width  = PluginNameGUI::width - MenuPanelGUI::width,
                         height = PluginNameGUI::height * 0.09f;
    
    //==============================================================================
    static constexpr float undo_redo_width  = height * 0.7f,
                         undo_redo_height = undo_redo_width;
    
    static constexpr float change_preset_width  = undo_redo_width,
                         change_preset_height = undo_redo_width;
    
    static constexpr float preset_display_width  = 100,
                         preset_display_height = undo_redo_width;
    
    static constexpr float A_B_Copy_width  = undo_redo_width,
                         A_B_Copy_height = undo_redo_width;
};

//==============================================================================
class MainPanelGUI {
public:
    //==============================================================================
    static constexpr float width  = PluginNameGUI::width - MenuPanelGUI::width,
                         height = PluginNameGUI::height - PresetPanelGUI::height;
    
};

//==============================================================================
class SidePanelGUI {
public:
    //==============================================================================
    static constexpr float width  = PluginNameGUI::width - PluginNameGUI::height,
                         height = PluginNameGUI::height;
    
};

//==============================================================================
class DisplayPresetOverlayGUI {
public:
    //==============================================================================
    static constexpr float width  = PluginNameGUI::width - MenuPanelGUI::width,
                         height = PluginNameGUI::height;
};

//==============================================================================
class ActionPresetOverlayGUI {
public:
    //==============================================================================
    static constexpr float width  = PluginNameGUI::width,
                         height = PluginNameGUI::height;
};

