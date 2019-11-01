# stygmorgan
A arranger keyboard emulator
![A arranger keyboard emulator](https://github.com/holborn2019/stygmorgan/blob/master/extra/sty.png)
The Chord Song Sequencer
![Chord Sequencer](https://github.com/holborn2019/stygmorgan/blob/master/extra/styseq.png)
The Style Pattern List Edit
![Pattern Edit](https://github.com/holborn2019/stygmorgan/blob/master/extra/styedt.png)

WARNING: Im sure this code just compile on 32bit, if u have 64bit machine and u reach to compile please send me the changes to fix the code on the repository.

This program actually doesent produce any sound, just reveive/send MIDI events, to use on a live performance is needed a MIDI keyboard that can be any kind of controller with or without sound to play as you play on a real arranger keyboard. Off course to use the Sequencer u dont need that.

They are many applications that u can use to produce the sound, personally I use Qsynth as frontend of Fluidsynth with the MuseScore_General_Full.sf2 with the Reverb patameters: Room=18 Damp=0 Width=2 Level=52 and the Chorus parameters: N=3 Level=100 Speed=30 Depth=68 with Fluidsynth version 1.1.11. And I think sounds pretty good.

To improve sound quality you can also use Multiple Jack Outputs on fluidsynth, if you dont increase the Audio Channels option on jack fluidsynth you just will have two extra stereo channels one for the Reverb and one for Chorus, that can be connected to external effects with more quality than the ones bring fluidsynth. 

You can use Multiple Audio Outputs increasing Audio Channels to 16 and also Audio Groups to 16 that will bring 16 stereo channels,that can be connected to a mixer, using Ardour or Non-mixer you can add lot of plugins on each channel, but remember that many plugins means many CPU usage, and also u will need to adjust levels for each pattern on mixer that like always is a problem for a live performance but not for the sequencer. The way is create channels for Reverb and Chorus and do "sends on the mixer" but is not easy control that level. I was not reach to use OSCtoMidi converter that bring Non-mixer and also Ardour give me some problems.

My favorite confiuration is using this 16 stereo channels provided with Fluidsynth with REAPER that brings the way to do "sends" and control the level of this "sends" to the effects receiving the midi control channel messages that stygmorgan send. Also I add compressor and EQ plugins on Drums and Bass and of course multi band compressor for the Master. And also you have ready to record any thing played on stygmorgan, is fantastic and really dont use so much CPU. 

I found lot of the Style files on the net that I was import, edit and mix for this configuration, but off course you can also use other programs to produce sound, LinuxSampler Timidity and others. You can get better sound than the provided in a soundfont synthesizer that's sure, but is also sure you will need to remix all the patterns on each style and is lot of work believe me. Also if you have plan to use really big samples to have better sound on the sampler think that probably the sampler cant change all the sounds faster and that's a big problem on a live performance, at least on a slow computers like mine, but is not a problem with the sequencer. 

Each soundfont synthesizer sounds different with the same soundfont .SF2 file, even FluidSynth 2.0 sounds really different than FluidSynth 1.1, personally I prefer Fluidsynth 1.1, for my taste Fluidsynth 2.0 sounds more dark, that doesent meant is better or worst, that meants is different, the quality of sounds is messured in patameters like samplerate and others. what is true at least on my computer is that Fluidsynth 2.0 use significative less CPU than 1.1 version.

What does stygmorgan is import style files V1.0 and do some tweaks to try to convert to General Midi standart. It does pretty well sometimes but with the far away to GM style files is needed to edit some things after u import. Stygmorgan has the tools to edit all on the style to reach this.
The sequencer bring the option to export the song as MIDI file that u can edit on a DAW and really help if you find a style that is more or less like you need on your project.

stygmorgan is a hardcoded program, runs on ALSA and JACK at the same time and I like that, but this also stop the idea to use fluidsynth as an internal synthesizer that was do more easy my life :-) Anyway use Fluidsynth as internal synthesizer is always on mind.


Just Enjoy :-)
