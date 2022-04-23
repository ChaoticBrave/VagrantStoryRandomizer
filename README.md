# Vagrant Story Randomizer
A tool which will randomize a copy of Vagrant Story.

At the moment, this is in the form of a Python file which has been converted to an executable file. Right now, it will randomize the enemies, their drops, and in the case of experimental builds, weapons in chests.

A randomized game has been proven to work with both Beetle PSX and DuckStation. 
## Releases
Both stable and experimental builds can be found here:
https://mega.nz/folder/wFV3CTzQ#NPZK8E4Wy-c_98T4n2DMTQ

## Updates
* MEGA is now being used to contain releases. They are becoming too large to upload to GitHub even as .zip files.
* psxinject is now the tool of choice when replacing .mpd files in the Vagrant Story .bin file with the randomized ones. This decision was made to prevent the project from relying on as many closed source software as possible.
* Stable builds can now randomize enemy drops. It appears as though having dummied items is inconsequential. Let me know if this is not the case though.
* Experimental builds can now randomize the weapons which appear in treasure chests. 
## To Do
* Randomize the rest of the loot which is in the treasure chests.
* Randomize the rooms. This one's a bit more "pie in the sky" and will warrant a bigger crew.
## Using this GitHub project
Many can find these GitHubs tedious, myself included. The "Releases" section exists for those who just want to extract the ZIP and get into the action. For those who wish to make their own alterations, the Python files has been included.

If you wish to convert an altered py file into an exe, make sure that your exe is in the same directory as the ZONES and MAPS directories, as well as a psxinject exe file and its necessary dll files after conversion in order for it to work. 
## Limitations
As mentioned earlier, this tool can only randomize enemies, their random drops and, in the case of experimental builds, weapons in chests right now. 

Enemies can also only be changed to those which can be found within the same area. For example, Snowfly Forest opponents can only be swapped with other Snowfly Forest opponents.
## Contact
If you queries about the project, the best places to contact me are either my Discord server or my Twitter DMs.

Discord:
https://discord.gg/xmgKtf2tN6

Twitter:
https://twitter.com/ChaoticBrave

## Credits
* ChaoticBrave: For making the randomizer of course!
* Valendian: For the extensive knowledge in Vagrant Story's file systems, as well as creating the superb VSTOOLS and GodHands packages.
* Christo: For the idea of creating a randomizer in the first place.
* CUE: For the psx-mode2 tool in the earlier builds. The project would've been lost without it.
* gingerbeardman: For letting me use his translation of psx-mode2 for the earlier builds.
* cebix: Creator of psximager, which is used for mpd file replacement in builds starting from v0.20.
* NoharOSP: For being at hand to test this locally.
