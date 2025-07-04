/*
  ==============================================================================

    PresetDisplayOverlay.h
    Created: 25 Nov 2021 8:57:24am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "OverlayBase.h"

#include "PresetManager.h"
#include "PresetViewItem.h"

//==============================================================================
class PresetDisplayOverlay
:   public OverlayBase,
    public juce::Button::Listener
{
public:
    //==============================================================================
    PresetDisplayOverlay(PluginNameAudioProcessor* inProcessor, ContextMenu* inContextMenu);
    ~PresetDisplayOverlay() override;
    
    //==============================================================================
    void resized() override;
    
    //==============================================================================
    void buttonClicked(juce::Button*) override;
    
    //==============================================================================
    PresetManager* getPresetManager();
    
    //==============================================================================
    void showContextMenu(juce::String name, bool isUserPreset);
    
private:
    //==============================================================================
    PresetManager *presetManager;
    
    //==============================================================================
    juce::TextButton addNewPreset {"+"};
    juce::TextButton setDefault {"default"};
    juce::TextButton dismissOverlay {"x"};
    
    //==============================================================================
    std::vector<juce::TextButton*> buttons = {
        &addNewPreset,
        &setDefault,
        &dismissOverlay
    };
    
    //==============================================================================
    juce::Viewport displayViewport;
    juce::TreeView presetsDisplay;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetDisplayOverlay)
};
