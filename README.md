# celestia-g2-stereoscopic
Please first refer to https://github.com/bgodard/celestia-g2
on how to build (and install).
## About this
This repository just holds my modifications
for stereoscopics, so you may test or improve them.
I'm busy with blender at the moment, so I decided to push
that "unready" code. It's ready enough to enjoy stereoscopics.
We need only **one** repository for the project, so I didn't fork or
clone again.

In detail, for stereo-rendering there are (at the moment)
modifications in

* ./celestia/src/celestia/celestiacore.cpp
* ./celestia/src/celestia/celestiacore.h
* ./celestia/src/celengine/axisarrow.cpp
* ./celestia/src/celengine/render.cpp

You'd only need these 4 files from here within your
local clone from [celestia-g2](https://gitub.com/bgodard/celestia-g2)
and compile it (again). Download as zip (or clone it via git),
and just overwrite them.

(optional)
for QT splashscreen issue:
* ./celestia/src/qt/qtmain.cpp
* ./celestia/src/qt/qtappwin.cpp
* ./celestia/splash-g2.png
Or take a look at  [Celestia-g2-QTSplash](https://github.com/raeTen/celestia-g2-Qtsplash)
which includes the newer splash.png gimp sources if you want to move pixels.

I also changed some colors e.g. for orbit-lines, axis-arrows… -
to make it more comfortable  while using red-cyan anaglyph-mode.
Well. old-fashioned and depreacted, but still good, cheap and
useable at least to begin with stereoscopics.

As already mentioned, stereo is working with a known
little weakness on travelling _through_ far distances.
This is a proof of concept on how to modify the engine,
to have stereoscopic view, even for head mounted displays later on.
We don't loose FPS, 'cause the magic is called interlacing.

This is developed and tested with Linux, the modifications
should work on Mac and Win, too, I can't test them, perhaps
you, the reader, can and will do. 

Build and use (Linux):
For testing purposes you even don't need a final "make install", you
may run the binary out of your local clone path, and solve the -z's issue,
before I do ;-)

For now, F-Keys used are:
* SHIFT+F2 OR F3
   will toggle between "normal" "anaglyph" "shutter" "shutter_inverted" "crossed-eyed" "normal" and so on
   The modes themselves will be easily to be extended, e.g. "head-mounted-display" or whatever.
* SHIFT+F5/F6
   increase/decrease stereo depth which is nested with parallax point for now.
* SHIFT+F7
   switches internal defined left/right, well a kind of debug/research thing at all,
   but there's still no real standard on this issue afaik.

Platform independent unused keys are rare in celestia, so we should build a stereo-menu later on.

BTW: realtime communication rocks, the irc channel
[celestia on freenode irc](irc://irc.freenode.net/#celestia)
is still alive (again), never hesitate to join ;-)

###Technical Notes:
    
1. anaglyphic mode

   red-cyan glasses needed
   other anaglyph methods won't be supported (by me)

2. crossed-eyed-view mode

   for realtime stereoscopics without any utility and for
   recording hardware-independent stereo-videos;
   If you know about "crossed-eye"-stereos, and if you own two monitors,
   you may imagine the terrific effect... )
   Please note, at the moment we just have a "splitted view" with two
   situations at all. The active (splitted) view will be rendered as single stereo scene,
   while the inactive situation remains in "background". Not very user-friendly,
   I know, but that'll be solved later on, too.
   We also could do the same for above/under-stereo by horizontal split.
   It still uses to turn off verbosity manually, the "verbose"-text cannot
   be displayed on both sides, so it is confusing our brain (not our eyes) while turned on.
   Those modes will be a little more "special multi view" internally,
   so that the user don't need to take care of this.

2a parallel-eyed-view mode (not implemented yet - wait, Shift+F7 does this job at the moment)
    I believe some stereo-video-players need it this way...

3. support for shutter-glasses

    At least vblank-synced should work, but experimental,
    I don't own a quadbuffer, but sli consumer, so I cannot test.
    On weak machines it will flicker sometimes, it won't if celestia
    could drive the sync to the glasses itself...
    Hopefully nvidia tells us how to drive their ir-transmitter finally,
    to have more fun with Linux and their consumer cards.
    I'd love to hear from nvidia Linux+consumercard+stereo=no problem,
    In the end, we would just need to know how to sync the glasses via usb without
    having a vsync signal to it, in other words syncing by software,
    instead of hooking and modifying the scene by the gpu-driver like they do with directx
    Just for the fun on computing, you know...
    Or. if there's anyone out there who has figured out, help is welcome,
    afaik we are lack of some ansi escape codes...

4.  roadmap with topic to stereo:
    support for headmounted-displays (and other displays)
    internal 3D mouse-pointer (3D HID needed )
        
A lot of bits and bobs to do - as always :)

Finally:
Thanks to everybody (and especially to the NASA)
who worked on celestia, I just love this piece of software.
I'll contribute more, but meanwhile I'm busy with blender…

 




