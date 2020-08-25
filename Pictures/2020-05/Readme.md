# The cockpit is...done?

By May, I had the whole thing built.  The pictures in this folder include more detailed "behind the scenes"
images of what the bird's nest of wires looks like between each of the panels.

For reference, I used several of the [Leo Bodnar](http://www.leobodnar.com/shop/index.php?main_page=index&cPath=94&zenid=41f0a7f40298148d5ff5bead11e34d14)
boards including four [BU0836A boards](http://www.leobodnar.com/shop/index.php?main_page=product_info&cPath=94&products_id=204&zenid=fcc1bcaa9d9931558e9c9466170ca3ff)
combined with [Matrix Breakout boards](http://www.leobodnar.com/shop/index.php?main_page=product_info&cPath=94&products_id=274&zenid=fcc1bcaa9d9931558e9c9466170ca3ff)
as well as one [BBI-64](http://www.leobodnar.com/shop/index.php?main_page=product_info&cPath=94&products_id=274&zenid=fcc1bcaa9d9931558e9c9466170ca3ff).

Going forward, I'm actually going to rewire and swap out a couple of the Bodnar boards for [Ardiono knockoff "Pro Micro"
boards](https://www.amazon.com/gp/product/B07FXCTVQP/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1).  These particular
boards can be set up to behave like USB HIDs, so DCS sees it as a game controller.  The Bodnar boards are great, but with
Arduino I can do things like setting an on-off toggle to send a joystick button press when the switch is either turned
on *or* off which helps avoid some .lua code in the setup.

# Not so fast!

The problem at this point was that I had not included the AMPCD, and I kept reaching for those buttons in VR.  It was also
often hard to quickly find the right switch/knob.
