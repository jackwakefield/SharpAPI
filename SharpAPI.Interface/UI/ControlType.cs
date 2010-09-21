/*
 *  This file is a part of SharpAPI.
 *
 *  Copyright (C) 2010 Jack Wakefield
 *  
 *  SharpAPI is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SharpAPI is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with SharpAPI.  If not, see <http://www.gnu.org/licenses/>.
 */

namespace SharpAPI.UI {
    /// <summary>
    /// The control type.
    /// </summary>
    public enum ControlType {
        Image = 0x0100,
        Button = 0x0200,
        EditBox = 0x0300,
        ListBox = 0x0400,
        ScrollBar = 0x0500,
        ComboBox = 0x0600,
        Dialog = 0x0700,
        Static = 0x0800,
        ScrollBox = 0x0900,
        Caption = 0x0A00,
        RadioBox = 0x0B00,
        RadioButton = 0x0C00,
        MessageBox = 0x0D00,
        PushButton = 0x0E00,
        Tree = 0x0F00,
        Guage = 0x1000,
        JComboBox = 0x1100,
        JListBox = 0x1200,
        TabbedPane = 0x1300,
        StatusBar = 0x1400,
        ZListBox = 0x1500,
        CheckBox = 0x1600,
        Pane = 0x1700,
        Slot = 0x1800,
        Table = 0x1900
    }
}