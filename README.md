# Eric's Hornet Cockpit file repository

A bunch of files I've created as part of designing and building a home cockpit for the F/A-18C.  Used in DCS playing in VR.

Folders here are:
* [**Pictures**](Pictures) is a good place to start as it includes writeups at several points in the history of
the build.  Part of that is a lot of pictures of the finished panel as well as the assembly process.
* [**DXF files**](DXF%20Files) contains CAD drawings that I used for the design of the side consoles and front panel, as well as
drawings used to construct the enclosures.  I created these in QCAD, but the drawings are in DXF format, so they should be
editable by most CAD tools.
* [**STL files**](STL%20Files) are the designs I created and used to 3D print various cockpit knobs and switches.  Having controls with the
right shape make things *much* easier in VR.  I'm not including gcode at this point as every printer is different, so you'll have to slice
these yourself.  I designed all of these in Fusion360, but I'm not including those files, mostly because Fusion360 is cloud-based, and it's
a pain to extract them to your machine.
* [**Arduino Code**](Arduino%20Code) are the programs I have written to drive the Arduino boards I use in my build.  While this is very specific
to my use cases, if you are new to Arduino coding this may provide some ideas.  [The Rradme](Arduino%20Code/Readme.md) also includes
info about which boards work and a couple of code libraries that are likely to be needed.
* [**DCS lua code**](DCS%20lua%20code) are my customizations to the "default.lua" file that defines how cockpit controls work.  With some
modifications to the .lua code it is possible, for example, to make toggle switches send an action when turned OFF in addition to
when turned ON.  [The readme](DCS%20lua%20code/Readme.md) explains the location of the files within the DCS install and provides guidance
on how to incorporate into DCS.

<img src="Pictures/2020-08/IMG_7684.JPG">

## License information

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
