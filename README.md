# Ursula's Shell Wireless Reciever

This is designed to work on an Adafruit Feather M0 with RF69HWC, but it should work with any board supporting the RadioHead library, and NeoPixel library.

All physical pin connections are listed in the beginning of the .INO

---

# Demonstration

you can see a demonstration of this project fully assembled [in this youtube video](https://www.youtube.com/watch?v=1lSk3tvIJRw)

---

## Other physical connections

On our build of the shell we installed a SPDT switch to act as a power switch to save power, we connected the center tap to ground, and one side to the 3.3v regulator enable input on our microcontroller board, and the other side to the groud of the neopixels. This configuration is **NOT** recommended.

We recommend using a DPDT switch instead, connect the first set of contacts as described before, and use the second set to switch the Vin to the neopixels (ensure this is the same side as the ground connection to the neopixels).

We also recommend if you intend to cast it like our build, to ensure you retain access to the USB, and Reset button (we used a pannel mount USB extension, and pannel mount push button attached to [this 3d printed part we designed](https://a360.co/2RlPItY)). If you are using a different microcontroller you should make sure you breakout whatever you need to reprogram in a **worst case** senario not just tipically as it is virtually impossible to access any connections on the microcontroller once cast in a liquid plastic.

## Costruction Notes

we also Laser Cut [this shell shape](https://a360.co/2zP46nG) to use as a scaffold for the electronics, however it was not the correct shape and significant physicall modifications had to be made to allow functionality, if taking an approach similar to this ensure that the scaffold will fit in the mold with any other parts (like our [connections mount point](https://a360.co/2RlPItY) used earlier) as we failed to take this into account and was forced to make last minute modifications to the acrylic scaffold, and the mounting point and the mold as a result.

