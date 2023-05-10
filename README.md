# Vagrant Story Randomizer
A tool which will randomize a copy of Vagrant Story. Right now, it will randomize the enemies, their drops and chest items.

A randomized game has been proven to work with both Beetle PSX and DuckStation. 
## Releases
Both stable and experimental builds can be found here:

https://mega.nz/folder/wFV3CTzQ#NPZK8E4Wy-c_98T4n2DMTQ

## Updates
* This is it my friends, we now have a GUI available for the randomizer! It's basic, but it hopefully gets the job done. The console version is still available via early versions on the MEGA link. If there are any issues with the GUI, please let me know through the Discord link below.
## To Do
* Make the enemy drops randomizer independent from the enemy randomizer.
* Randomize enemy stats.
* Randomize Ashley's starting data.
* Last ditch effort to change which models enemies and Ashley use, 
## Using this GitHub project
Many can find these GitHubs tedious, myself included. The "Releases" section exists for those who just want to extract the ZIP and get into the action. For those who wish to make their own alterations, the C++ files have been included.

If you make any alterations to the source code and you want to bring your project to life, make sure that your exe is in the same directory as the ZONES and MAPS directories, as well as a psxinject exe file and its necessary dll files after conversion in order for it to work. 
## Limitations
Enemies can also only be changed to those which can be found within the same area. For example, Snowfly Forest opponents can only be swapped with other Snowfly Forest opponents.

Player character randomization was previously in the To Do list. Upon further testing, this will not be possible for the foreseeable future. If only because randomized characters are glitchy outside of battle mode. Should anyone still be interested though, this will be added in a later experimental build.

Certain locations are randomized rather than being on a room-by-room basis due to issues with how coordinates are translated from the ROM to the RAM. Because of this, only a selected few areas can be warped to with the locations randomizer. Locations which end with a door locked by a key, sigil, or have a cutscene transition won't be randomized as the game will not register the changes made by the tool. 
## Contact
If you queries about the project, the best places to contact me are either my Discord server or my Twitter DMs.

Discord:

https://discord.gg/xmgKtf2tN6

Twitter:

https://twitter.com/ChaoticBrave

Tumblr:

https://www.tumblr.com/chaoticbraves-workshop

## Credits
* ChaoticBrave: For making the randomizer of course!
* Valendian: For the extensive knowledge in Vagrant Story's file systems, as well as creating the superb VSTOOLS and GodHands packages.
* Christo: For the idea of creating a randomizer in the first place.
* CUE: For the psx-mode2 tool in the earlier builds. The project would've been lost without it.
* gingerbeardman: For letting me use his translation of psx-mode2 for the earlier builds.
* cebix: Creator of psximager, which is used for mpd file replacement in builds starting from v0.3.0.0.
* NoharOSP: For being at hand to test this locally.
* mayaktheunholy: For discovering several errors with pre-0.5.1.0 builds.
* OddKara: Inspired me to do location-based randomizing rather than a room-by-room direction.
* benjamin champion: Discovered that grips can be randomized in chests.
* Taterz: Discovered the Ghost crashes in the Catacombs.
