
# celestia-g2-stereoscopic
Please refer to https://github.com/bgodard/celestia-g2

a) anaglyphic mode

   red-cyan glasses needed

b) crossed-eye-view mode 

   for realtime stereoscopics without any utilities and for
   recording hardware-independent stereo-videos;
   If you know about "crossed-eye"-stereos, and if you own two monitors,
   you may imagine the terrific effect... ) 

c) support for shutter-glasses 

    at least vblank-synced should work, but experimental

d) roadmap: support for headmounted-displays (other than *-glasses)

A lot of bits and bobs to do, patch(es) will follow ...

-----------------------------------------------------------------------------
Stereo is working for most situations right now, but there's a "little" issue
on moving through far distances. I need to understand the whole engine,so
I'm busy on that. I want the stereo rendering without any user interaction,
(just choosing stereo mode and a suitable users stereo depth value)
See cel_stereofrustum.png for the "problem" with negative z on back plane(s).
It'll be useless to change the render process (sorting the lists e.g.), because
it will be to expensive, and the "problem" would still exist on some "places",
when moving around through far distances.
The solution on this is to gather those situations as  a defined value and switch
left/right eye on that. This is what I'll try …




