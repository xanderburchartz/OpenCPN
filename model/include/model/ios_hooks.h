/**************************************************************************
 *   Copyright (C) 2026 by Xander Burchartz                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <https://www.gnu.org/licenses/>. *
 ***************************************************************************/

/**
 * \file
 *
 * Functions of the iOS app layer that the core calls. They are implemented
 * in the iOS app (app/ios in the opencpn-ios repository).
 */

#ifndef IOS_HOOKS_H_
#define IOS_HOOKS_H_

#ifdef __OCPN__IOS__

#include <wx/string.h>

class EventVar;
class MyConfig;
class wxAuiManager;
class wxCheckBox;
class wxColour;
class wxDC;
class wxDialog;
class wxFrame;
class wxGridCellRenderer;
class wxPanel;
class wxScrolledWindow;
class wxSizer;
class wxSizerFlags;
class wxSpinCtrl;
class wxStaticText;
class wxTextCtrl;
class wxWindow;

void ocpnios_AddAlertButtons(wxDialog* dlg, wxSizer* topsizer, long style);
void ocpnios_AddAlertTitle(wxDialog* dlg, wxSizer* topsizer,
                           const wxString& caption);
void ocpnios_AddSourceButtons(wxWindow* panel, wxSizer* vbox,
                              EventVar& evt_add_connection);
void ocpnios_ApplySchemeColors(wxFrame* frame);
void ocpnios_ConfigLocaleResetOnce(MyConfig* cfg);
void ocpnios_ConfigTextScaleDefault(MyConfig* cfg);
wxString ocpnios_DisplayPath(const wxString& path);
void ocpnios_DrawTtyMessage(wxWindow* win, wxDC& dc, const wxString& ws,
                            int& data_pos, int y, int line_height);
void ocpnios_FloatPluginPanes(wxAuiManager* mgr);
void ocpnios_HideBusyHud();
void ocpnios_MapBundleDataPath(wxString& val);
void ocpnios_MapContainerChartDir(wxString& dirname, int& nAdjustChartDirs);
void ocpnios_NetmaskRowLayout(wxPanel* row, wxStaticText* text,
                              wxSpinCtrl* spin, const wxSizerFlags& flags);
wxGridCellRenderer* ocpnios_NewSwitchCellRenderer();
void ocpnios_NmeaFilterRowLayout(wxPanel* row, wxCheckBox*& checkbox,
                                 wxTextCtrl*& filter_period);
void ocpnios_OnStartupDone();
int ocpnios_OverlayInsetLeft();
int ocpnios_OverlayInsetRight();
wxColour ocpnios_PluginCardBg();
wxColour ocpnios_PluginPageBg();
wxString ocpnios_PluginWrap(wxWindow* win, const wxString& text, int width);
void ocpnios_RmdFitButtons(wxWindow* dlg, int margin, wxScrolledWindow* winr,
                           wxScrolledWindow* wint, wxScrolledWindow* winw,
                           wxScrolledWindow* winl);
void ocpnios_ShowBusyHud();
void ocpnios_ShowStartupBusy();
wxString ocpnios_TcFull(const wxString& shown);
wxString ocpnios_TcShow(const wxString& full);
void ocpnios_TidyDocuments();
void ocpnios_WaitUntilActive();

// Built-in plugins, statically linked (app/ios/static_plugins.cpp).
extern "C" {
struct ocpnios_StaticPlugin {
  const char* file_name;
  void* (*create)(void* manager);
  void (*destroy)(void* plugin);
  const char* common_name;
};
const ocpnios_StaticPlugin* ocpnios_StaticPlugins();
const ocpnios_StaticPlugin* ocpnios_FindStaticPlugin(const char* file_name);
}

#endif  // __OCPN__IOS__

#endif  // IOS_HOOKS_H_
