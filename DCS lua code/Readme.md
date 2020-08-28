# DCS .lua code

Toggle switches present a challenge when building any kind of button box.  While they send an input when you
turn the toggle "on," they don't provide any kind of signal when you turn the toggle "off."  There are some
ways around this:
* You can use ON-ON toggles rather than ON-OFF, but that takes up twice as many inputs on your board.
* You can write Arduino code that will send signal both when a toggle is switched on OR off.  Some examples can be found in the
[Arduino Code](https://github.com/ColdFrontWI/Hornet_Cockpit/tree/master/Arduino%20Code) folder.

Fortunately, DCS offers a way to handle this by adding custom controls to an aircraft's "default.lua" file.  Some of these
types of controls may already be set up:
* In the A-10C, all of the toggles on the TM Warthog throttle work
out of the box
* On the Hornet, ED has added appropriate functionality for all of the ON-OFF-ON toggles in the cockpit.  But if you
want the ON-OFF toggles to work, you generally need to add your own custom controls.

You should be able to add any of the "default - *Aircraft* append.lua" files in this folder, to the "default.lua"
file for the relevant plane, and additional options will show up in the DCS control setup.  For the Hornet, the file is
located at *~\DCSWorld\Mods\aircraft\FA-18C\Input\FA-18C\joystick*.  Once you edit
default.lua you will see some additional control groups in the setup page, per the image below.
You can then bind them to whichever controls you want.
  
<img src="Custom_control_screenshot.PNG" width=1000>

## Other notes
* For my cockpit, I set some of the controls up in "reverse" for various reasons.  For example, the toggle I
use for the arresting hook is "on" in the down position rather than up.  If you find some of my custom controls
work in reverse, you can edit it to suit your needs.
* Recommend you keep a copy of your "append" file around separate from the main default.lua.  DCS updates occasionally
overwirte default.lua, and if you don't have the append file you'll have to rewrite from scratch.  Ask me how I know ;).

## Other aircraft

Obviously not relevant for the Hornet, but I'm also including the files I set up for the Warthog and the Mustaing here.
