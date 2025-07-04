/*
  ==============================================================================

    MenuPanel.cpp
    Created: 25 Nov 2021 8:56:49am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MenuPanel.h"

#include "PluginNameParameters.h"

//==============================================================================
MenuPanel::MenuPanel(PluginNameAudioProcessor* inProcessor, ContextMenu* inContextMenu)
:   PanelBase(inProcessor, inContextMenu)
{
    setName("MenuPanel");
    setComponentID("MenuPanelID");
    
    // initialize each button and add them to the scene
    for (juce::TextButton* button : buttons) {
        button->setTriggeredOnMouseDown(true);
        button->addListener(this);
        addAndMakeVisible(button);
    }
    
    // master and advanced need to be toggleable 
    masterButton.setClickingTogglesState(true);
    
    advancedButton.setClickingTogglesState(true);
    advancedButton.setToggleable(processor->settings.getChild(PluginNameSettings::PNS_GUIScale).getProperty(juce::Identifier("value")));
}

MenuPanel::~MenuPanel()
{
    
}

//==============================================================================
void MenuPanel::resized()
{
    masterButton.setBounds(getWidth()*0.1f, getHeight() * 0.50f, getWidth() * 0.8f, 40);
    advancedButton.setBounds(getWidth()*0.1f, masterButton.getBottom() + 10, getWidth() * 0.8f, 40);
    accountButton.setBounds(getWidth()*0.1f, advancedButton.getBottom() + 10, getWidth() * 0.8f, 40);
}

//==============================================================================
void MenuPanel::buttonClicked(juce::Button* b)
{
    bool rightClick = juce::ModifierKeys::getCurrentModifiers().isPopupMenu();
    
    if (rightClick) {
        contextMenu->showMenu(b->getName());
        juce::MessageManager::broadcastMessage("PluginName Context_Menu_Shown");
    }
    else {
        if (b == &masterButton) {
            // TODO: add masterOnOff parameter and toggle it here
        }
        else if (b == &advancedButton) {
            PluginNameSettings::showSidePanel = advancedButton.getToggleState();
            
            getParentComponent()->resized();
        }
        else if (b == &accountButton) {
            juce::MessageManager::broadcastMessage("PluginName Show_Form");
        }
    }
}
