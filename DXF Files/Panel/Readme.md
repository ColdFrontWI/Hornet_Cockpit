# Panel Layout

This is the full panel that I used for construction.  This was drawn in QCAD using several sources:
* The NATOPS manual foldout.  I created the image files in the ./Bitmap subfolder, inserted them into QCAD,
scaled them to the appropriate size, and then used them for reference.  Some things were intentionally
drawn smaller to make things fit, notably the three displays.
* To get the scaling right, I used the dimensions provided for a few of the panels available
from [PC Flights](http://pcflights.com/index.php?main_page=index&cPath=47_70).
* Building a cardboard mockup, sticking printouts to it, and sitting in a chair for a long time pulling
my VR headset on and off to see how things fit together.

Couple of comments on the main DXF file:
* There are a lot of layers here that I used to visualize, but turned off all but CutTier1, EmergHatch,
SwCenter, SwDrill, SwitchTier1, and TextTier1 to print.
* The bitmaps are in the DXF, but they reference an absolute path on my PC.  If you want them to show up,
open the DXF in a text editor, find the instances of .png, and replace all of the path information with
whatever is appropriate for your setup.
* On the bottom right of the front panel below and to the right of the "steam gauges" are a few buttons
that are not Hornet specific.  I use them for things like recentering VR, opening and moving around
in my checklists, slowing down/speeding up time, etc.

In terms of the actual construction, it was fairly straightforward:
* Cut the acrylic to size
* Print the panels at 1:1 on [full-sheet labels](https://www.amazon.com/gp/product/B074KQRJKN/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1).
Obviously it doesn't all fit on one sheet, so I had to cut them carefully, and fit them together
* Cut/drill the holes needed for your switches.  The SwCenter and and SwDrill layers in the DXF help with this.
* Install the switches and wire it up!
