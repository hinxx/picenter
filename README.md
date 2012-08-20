PiCenter
========

Introduction
------------
PiCenter is a lightweight launcher for OMXPlayer (Raspberry Pi) and is currently under heavy development. It may be ugly and not as feature-rich as XBMC, but I want a small media-centre on the PI that supports the features I want + a centre that is quite fast and not so resource hungry as XBMC. The future plans are
* stable, small API for plugins, so nearly everybody can develop plugins for PiCenter
* dynamic plugin loading
* Video thumbnails
* Audio plugin (play music, playlist support...)
* Jupiterbroadcasting plugin (watch LIVE + stream all podcasts)
* (maybe) Youtube plugin

Dependencies
------------
> SDL
> SDL-ttf

Configuration and Compilation
-----------------------------
PiCenter is being configured through source code. Have a look at 'conf.h' and 'settings.mak' for further descriptions. Type 'make' to compile the source code.

How to run
----------
Run 'picenter' from within the console.

Keybindings
-----------
* Up/Down - Folder/File up/down
* Left/Right - Switch page
* Return - Open folder or start movie
* H - Return to home (conf.h)
* . - Go to ..
* Escape - Quit

Licensing
---------
The code has been licensed under the GPL v2.
