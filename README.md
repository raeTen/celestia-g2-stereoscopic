# celestia-g2-stereoscopic
Please first refer to https://github.com/bgodard/celestia-g2
on how to build (and install).
## About this
This repository just holds my modifications
for stereoscopics, so you may test or improve them.
I'm busy with blender at the moment, so I decided to push
that "unready" code. It's ready enough to enjoy stereoscopics.
We need only one repository for the project, so I didn't fork or
clone again.

There are modifications in

* ./celestia/src/celestia/celestiacore.cpp
* ./celestia/src/celestia/celestiacore.h
* ./celestia/src/celengine/axisarrow.cpp
* ./celestia/src/celengine/render.cpp

You'd need these 4 files from here within your
local clone from [celestia-g2](https://gitub.com/bgodard/celestia-g2)
and compile it (again). Download as zip (or clone it via git).

## Update (7/2015)
I ported the modifications to a class, and created a small dockable qt widget
for stereo settings, so we could easily tinker around with more
values belonging to stereoscopics. I don't know if we need to
have updated UI values from core-values, maybe we could skip the shifted
"core-keys" later on.
For the qtwidget you'll need another 5 files
the new:
* ./celestia/src/celestia/qt/qtstereosettings.h
* ./celestia/src/celestia/qt/qtstereosettings.cpp

the updated (just to include the widget):

* ./celestia/src/celestia/qt/qtappwin.h
* ./celestia/src/celestia/qt/qtappwin.cpp

and the new splash

* ./celestia/splash-g2.png
## ---------------

and just overwrite them in your local clone.

If you want to push pixels within splash-g2.png,
please take a look at  [Celestia-g2-QTSplash](https://github.com/raeTen/celestia-g2-Qtsplash)
which includes the newer splash.png gimp sources.
Don't use the qt code from there …

I had also changed some colors e.g. for orbit-lines, axis-arrows… -
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

* OR use the new dockable qtwidget for these settings

~~Platform independent unused keys are rare in celestia, so we should build a stereo-menu later on.~~

BTW: realtime communication rocks, never hesitate to join
irc.freenode.net/#celestia

## Technical Notes
    
1. anaglyphic mode

   red-cyan glasses needed
   other anaglyph methods won't be supported (by me)

2. crossed-eyed-view mode

   for realtime stereoscopics without any utility and for
   recording hardware-independent stereo-videos;
   If you know about "crossed-eye"-stereos, and if you own two monitors,
   you may imagine the terrific effect … )
   Please note, at the moment we just have a "splitted view" with two
   situations at all. The active (splitted) view will be rendered as single stereo scene,
   while the inactive situation remains in "background". Not very user-friendly,
   I know, but that'll be solved later on, too.
   We also could do the same for above/under-stereo by horizontal split.
   It still uses to turn off verbosity manually, the "verbose"-text cannot
   be displayed on both sides, so it is confusing our brain (not our eyes) while turned on.
   Those modes will be a little more "special multi view" internally,
   so that the user don't need to take care of this.

   parallel-eyed-view mode (not implemented yet - wait, Shift+F7 does this job at the moment)
   I believe some stereo-video-players need it this way.

3. support for shutter-glasses

    ~~At least vblank-synced should work, but experimental,
    I don't own a quadbuffer, but sli consumer, so I cannot test.
    On weak machines it will flicker sometimes, it won't if celestia
    could drive the sync to the glasses itself.
    Hopefully nvidia tells us how to drive their ir-transmitter finally,
    to have more fun with Linux and their consumer cards.~~
    I'd love to hear from nvidia Linux+consumercard+stereo=no problem,
    ~~In the end, we would just need to know how to sync the glasses via usb without
    having a vsync signal to it, in other words syncing by software,
    instead of hooking and modifying the scene by the gpu-driver like they do with directx
    Just for the fun on computing, you know.
    Or. if there's anyone out there who has figured out, help is appreciated,
    afaik we are lack of some ansi escape codes …~~
## Updated notes on shutters [9 2015]
    After some more investigations on nVidia shutters, I have created an open letter
    to nVidia, because there is defacto no technical reason why they do not support
    quadbuffering on Geforces lastly with Linux and Co. I knew about that in abstract,
    now I know from my practical experience.
    
    [open letter to nVidia](https://github.com/raeTen/celestia-g2-stereoscopic/blob/master/open-letter-to-nvidia.md)
    
    Shutter-glasses in general require quadbuffering for the following reasons:
    
    * no need for "dirty" platform-dependent tricks
    * keeping the first defined eye render process in sync with shutters in stable manner
    
    quadbuffering also makes it a lot of easier to modify any 3D-application to be stereoscopic
    even if this is not required for other projection types than shutter-glasses.
    After all I can also state that there is no real "problem" having quadbuffering on Geforces at all.
    Let's see how nVidia reacts, if the reaction is negative at that point, I'm going to
    obtain an competioner product with quadbuffering support on Linux. After that I'll be
    able to make celestia ready for shutterglasses at all. BTW the code works with lack
    of keeping "first eye" in sync with blanking. I worked around that issue, but that
    would be "Linux only". That is not what we want, because I just love the open-source community
    for the paragon of democracy. The fact and decision to develop with Linux only, doesn't mean that
    I want to exclude any other platform. I am pretty sure that this is our common position.
    The religious fundamentalists ever could be found in the "Windows only-camp", that's nothing
    I stand for.
    …
    
4.  roadmap with topic to stereo:
    support for headmounted-displays (and other displays)
    internal 3D mouse-pointer (3D HID needed )
        
A lot of bits and bobs to do - as always :)

#Updated notes and thoughts…

## Thoughts on celestia development in general

Apart from stereoscopics and my gaining experience with modelling, I tumbled over
issues associated with the 3ds format. I didn't find a way to have an exported
3ds (scene) which is being (imported) exposed correctly by celestia.
I tried *actual* modelling software like blender, Wings3D and so on.
(even lightwave but not autodesk yet).
If I import a *correct working* 3ds file (e.g. isscomplete.3ds) to blender (2.6x >),
blender poses this correctly, but then exporting it without any modifications
will make the 3ds unusable with celestia. I believe something went wrong
with the chunks according to material/transparency, and that already happens while
importing to blender, but i don't know yet for sure. That worked in the past
didn't it?

No one to blame for, that holy shit (pardon) is just sophisticated matter.
Unfortunately 3ds is still proprietary, but "well known" over the years.
Even with its doslike limitations it would be sufficient for cel things.
They have "max" these days, they won't hurt themselves to make
3ds an open format as a standard, simple and interchanging (what it is) format,
right?
It would be just the contrary, because the complete IT world would be just
nothing without open formats and standards. I would never blame closed source
software devs,  but we should blame those who
want to hide supposedly secrets for ages and fleecing the general public.
First and foremost the parted knowledge is the thing, which keeps the scientific headway.
J.C. and id-soft is a shining example HOW it works.

To cut a long story short:
Free software for free software ;-)
I read about the cmod exporter for historic blender versions. *This* is
the thing we need in future if you ask me, because we want to
be platform-independent and not dependent on these mystic-monger ;-).

Fixing the thing with 3ds parsing/importing/exporting for blender
OR within celestia importer would be very nice. I don't have a clue
in detail yet, so helping out with this is very very much aapreciated.
If anyone has got a copycat "cmod-exporter".py for blender (2.4 <) -
please make it public again, it was linked within the original forum,
which is still down :-/
Porting that to blender 2.7.x > should be the easiest way.


## Finally:
Thanks to everybody (and especially to the NASA),
who worked on celestia, I just love this piece of software.
I'm sure Pluto and Charon will get a nice texture these days!
I'll contribute more, but meanwhile I'm busy with blender again …
