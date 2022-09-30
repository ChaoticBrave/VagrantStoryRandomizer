# Vagrant Story Randomizer
A tool which will randomize a copy of Vagrant Story. Right now, it will randomize the enemies, their drops and chest items.

A randomized game has been proven to work with both Beetle PSX and DuckStation. 
## Releases
Both stable and experimental builds can be found here:

https://mega.nz/folder/wFV3CTzQ#NPZK8E4Wy-c_98T4n2DMTQ

## Updates
* The 0.85 stable build has been uploaded to the MEGA link. This build has a variety of fixes for bugs which could render the game unusable. Because of this, it is highly recommended that you do not use any stable version before 0.85. 
* An experimental build which has room randomization is now available. You will find it in the Experimental Build folder using the MEGA link, and the source code for it in the "experimental" folder in "source". Keep in mind that it's still experimental. Most of the randomized rooms will crash. Because of this, I strongly suggest backing up your Vagrant Story BIN/CUE. 
## To Do
* Stabilize the rooms randomizer.
* Give the randomizer a proper GUI.
## Using this GitHub project
Many can find these GitHubs tedious, myself included. The "Releases" section exists for those who just want to extract the ZIP and get into the action. For those who wish to make their own alterations, the C++ files have been included.

If you make any alterations to the source code and you want to bring your project to life, make sure that your exe is in the same directory as the ZONES and MAPS directories, as well as a psxinject exe file and its necessary dll files after conversion in order for it to work. 
## Limitations
Grips in chests will not be updated. This is because, as far as I know, no Grips are in any of the chests.

Enemies can also only be changed to those which can be found within the same area. For example, Snowfly Forest opponents can only be swapped with other Snowfly Forest opponents.

Player character randomization was previously in the To Do list. Upon further testing, this will not be possible for the foreseeable future. If only because randomized characters are glitchy outside of battle mode. Should anyone still be interested though, this will be added in a later experimental build.

Most randomized rooms in experimental builds will cause the game to crash. I will look into a fix. For now, use the room randomizer at your own risk, and backup your BIN/CUE of Vagrant Story.
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
* mayaktheunholy: For discovering several errors with pre-0.85 builds.
