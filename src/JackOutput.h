/* amSynth
 * (c) 2001-2003 Nick Dowell
 */

#ifndef _JACK_OUTPUT_H
#define _JACK_OUTPUT_H

#ifdef with_jack
#include <jack/jack.h>
#endif

#include "AudioOutput.h"
#include "VoiceBoard/Synth--.h"
#include "Config.h"

class JackOutput : public GenericOutput {

public:
//			JackOutput	( );
	virtual		~JackOutput	( ) {};
	void		setInput	( NFSource & source );
	
	int		init		( Config & config );// returns 0 on success
	void		run		( );
	void		stop		( );
	
	string		get_error_msg	( )		{ return error_msg; };
	
	int		canRecord	( )		{ return 0; };
	void		startRecording	( );
	void		stopRecording	( );
	void		setOutputFile	( string file )	{ wavoutfile = file; };
	string		getOutputFile	( )		{ return wavoutfile; };

	const char*	getTitle	( )	{ return client_name.c_str(); };

private:
	int	running;
	int	channels;
	Config	*config;
	string	wavoutfile;
	int	recording;
	int	bufsize, srate;
	string	client_name, error_msg;
};

#endif				// _AUDIO_OUTPUT_H
