/*
 *  MIDILearnDialog.h
 *
 *  Copyright (c) 2001-2012 Nick Dowell
 *
 *  This file is part of amsynth.
 *
 *  amsynth is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  amsynth is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with amsynth.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../UpdateListener.h"

class MidiController;
class PresetController;

class MIDILearnDialog : public UpdateListener
{
public:

	MIDILearnDialog(MidiController *midiController, PresetController *presetController, GtkWindow *parent);
	~MIDILearnDialog();

	void run_modal(unsigned param_idx);	

private:

	virtual void update();

	void last_active_controller_changed();

	GtkWidget		*_dialog;
	GtkWidget		*_paramNameEntry;
	GtkWidget	*_ccSpinButton;

	MidiController	*_midiController;
	PresetController *_presetController;
};

