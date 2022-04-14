# Vagrant Story Randomizer
A tool which will randomize a copy of Vagrant Story.

At the moment, this is in the form of a Python file which has been converted to an executable file. It will also only randomize the enemies right now. Item randomization is the next area which is to be addressed.

A randomized game has been proven to work with both Beetle PSX and DuckStation. 
## Updates
* Rooms with treasure chests will randomize enemies now. Both stable and experimental builds exist which implement these changes. The experimental build randomizes each enemy's random drop. It may need to be finalized to work around dummied items.
## To Do
* Randomize the random drops which enemies have, as well as the rates as and when they drop them. This is partially complete, but the fact that dummied items are included may produce unexpected results. To be tested. 
* Randomize the loot which is in the treasure chests. This will include making entirely new weapons. Get hyped.
* Randomize the rooms. This one's a bit more "pie in the sky" and will warrant a bigger crew.
## Using this GitHub project
Many can find these GitHubs tedious, myself included. The "Releases" folder exists for those who just want to extract the ZIP and get into the action. For those who wish to make their own alterations, the Python file has been included.

If you wish to convert an altered py file into an exe, make sure that your exe is in the same directory as the ZONES and MAPS directories, as well as a psx-mode2-en exe file after conversion in order for it to work. 
## Limitations
As mentioned earlier, this tool can only randomize enemies right now. 

Enemies can also only be changed to those which can be found within the same area. For example, Snowfly Forest opponents can only be swapped with other Snowfly Forest opponents.
## Credits
* ChaoticBrave: For making the randomizer of course!
* Valendian: For the extensive knowledge in Vagrant Story's file systems, as well as creating the superb VSTOOLS and GodHands packages.
* Christo: For the idea of creating a randomizer in the first place.
* CUE: For the psx-mode2 tool. The project would've been lost without it.
* gingerbeardman: For letting me use his translation of psx-mode2.
* NoharOSP: For being at hand to test this locally.
