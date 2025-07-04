/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

// panels
#include "PanelBase.h"
#include "MenuPanel.h"
#include "PresetPanel.h"
#include "MainPanel.h"
#include "SidePanel.h"

// overlays
#include "PresetDisplayOverlay.h"
#include "SavePresetOverlay.h"
#include "DeletePresetOverlay.h"
#include "UpdatePresetOverlay.h"

// registration
#include "RegistrationStatus.h"
#include "UnlockForm.h"

#include "ContextMenu.h"

//==============================================================================
/**
*/
class PluginNameAudioProcessorEditor
:   public juce::AudioProcessorEditor,
    private juce::Timer
{
public:
    //==============================================================================
    PluginNameAudioProcessorEditor (PluginNameAudioProcessor&);
    ~PluginNameAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    void timerCallback() override;
    void unlockApp();
    void checkFeature();
    
    //==============================================================================
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginNameAudioProcessor& audioProcessor;
    
    //==============================================================================
    ContextMenu contextMenu;
    
    //==============================================================================
    // panel hierarchy
    MenuPanel menuPanel;
    PresetPanel presetPanel;
    MainPanel mainPanel;
    SidePanel sidePanel;
    
    //==============================================================================
    std::vector<PanelBase *> panels = {
        &menuPanel,
        &presetPanel,
        &mainPanel,
        &sidePanel
    };
    
    //==============================================================================
    // overlays
    PresetDisplayOverlay displayPresetOverlay;
    SavePresetOverlay savePresetOverlay;
    DeletePresetOverlay deletePresetOverlay;
    UpdatePresetOverlay updatePresetOverlay;
    
    //==============================================================================
    std::vector<PanelBase *> overlays = {
        &displayPresetOverlay,
        &savePresetOverlay,
        &deletePresetOverlay,
        &updatePresetOverlay
    };
    
    //==============================================================================
    juce::TextButton unlockButton { "Unlock" },
                     secretButton { "Super Secret Feature" };

    MarketplaceStatus marketplaceStatus;
    UnlockForm unlockForm;

    bool isUnlocked = false;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginNameAudioProcessorEditor)
};
