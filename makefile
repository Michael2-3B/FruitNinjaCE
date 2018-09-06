# ----------------------------
# Set NAME to the program name
# Set ICON to the png icon file name
# Set DESCRIPTION to display within a compatible shell
# Set COMPRESSED to "YES" to create a compressed program
# ----------------------------

NAME        ?= CSWIPE
COMPRESSED  ?= NO
ICON        ?= iconc.png
DESCRIPTION ?= "Swipe the calculator keys just like you would swipe the screen in fruit ninja."

# ----------------------------

include $(CEDEV)/include/.makefile
