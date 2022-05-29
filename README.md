# Vagrant Story Randomizer
A tool which will randomize a copy of Vagrant Story.

At the moment, this is in the form of a Python file which has been converted to an executable file. Right now, it will randomize the enemies, their drops and chest items.

A randomized game has been proven to work with both Beetle PSX and DuckStation. 
## Releases
Both stable and experimental builds can be found here:

https://mega.nz/folder/wFV3CTzQ#NPZK8E4Wy-c_98T4n2DMTQ

## Updates
* All chest items will be randomized now. You can find this build in the Stable Builds folder in the MEGA link; it will be named Vagrant_Story_Randomizer_v0.80. Any consumable items needed to progress through the story are not randomized. It appears as though having dummied items is inconsequential. Let me know if this is not the case though. 
## To Do
* Randomize the rooms. This one's a bit more "pie in the sky" and will warrant a bigger crew.
* Make each different part of the randomizer a function where the user decides what should be randomized or not.
## Using this GitHub project
Many can find these GitHubs tedious, myself included. The "Releases" section exists for those who just want to extract the ZIP and get into the action. For those who wish to make their own alterations, the Python files has been included.

If you wish to convert an altered py file into an exe, make sure that your exe is in the same directory as the ZONES and MAPS directories, as well as a psxinject exe file and its necessary dll files after conversion in order for it to work. 
## Limitations
As mentioned earlier, this tool can only randomize enemies, their random drops and chests items right now. 

Grips in chests will not be updated. This is because, as far as I know, no Grips are in any of the chests.

Enemies can also only be changed to those which can be found within the same area. For example, Snowfly Forest opponents can only be swapped with other Snowfly Forest opponents.

Player character randomization was previously in the To Do list. Upon further testing, this will not be possible for the foreseeable future. If only because randomized characters are glitchy outside of battle mode. Should anyone still be interested though, this will be added in a later experimental build.
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
