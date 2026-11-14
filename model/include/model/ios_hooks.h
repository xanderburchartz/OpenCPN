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

class wxAuiManager;

void ocpnios_FloatPluginPanes(wxAuiManager *mgr);
void ocpnios_HideBusyHud();
int ocpnios_OverlayInsetLeft();
int ocpnios_OverlayInsetRight();
void ocpnios_ShowBusyHud();
void ocpnios_ShowStartupBusy();
void ocpnios_TidyDocuments();
void ocpnios_WaitUntilActive();

#endif  // __OCPN__IOS__

#endif  // IOS_HOOKS_H_
