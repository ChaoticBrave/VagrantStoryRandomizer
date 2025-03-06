# Vagrant Story Randomizer
A tool which will randomize a copy of Vagrant Story. Right now, it will randomize the enemies, their drops and chest items.

A randomized game has been proven to work with both Beetle PSX and DuckStation. 
## Releases
If you want the latest build, use the Latest folder. The latest experimental build will be in the Experimental Builds folder.

Both old stable and experimental builds can be found here:

https://mega.nz/folder/wFV3CTzQ#NPZK8E4Wy-c_98T4n2DMTQ

## Updates
* Stabilised the enemy stat randomizer and added a balance option. Though you should be careful using the model randomizer.
* Added the option to randomize Ashley's starting stats and equipment. There is also the option to balance how these are randomized.

## To Do
* Add Zenith QoL features.

If you wish to keep up-to-date with this project and what will be updated short-term, a link to the Trello can be found below:
https://trello.com/b/BZRfh8ht/vagrant-story-randomizer
## Using this GitHub project
Many can find these GitHubs tedious, myself included. The "Releases" section exists for those who just want to extract the ZIP and get into the action. For those who wish to make their own alterations, the C++ files have been included.

If you make any alterations to the source code and you want to bring your project to life, make sure that your exe is in the same directory as the ZONES and MAPS directories, as well as a psxinject exe file and its necessary dll files after conversion in order for it to work. 
## What are the parameters available?
* Enemies: Randomizes the enemy placements within an area.
* Chests: Randomizes the contents of a chest.
* Drops: Randomizes what each enemy drops. This will only apply to the random drops of an enemy. Guaranteed drops are unaltered to prevent softlocks.
* Balance Item Stats: Makes the randomized stats of weapons, blades, grips, gems, shields, and armour in chests less extreme.
* Area Progression: Randomizes where you go next depending on the area you're in.
* Keep Item Stats: Prevents the stats of weapons, blades, grips, gems, shields, and armour in chests from being randomized.
* Enemy Models: Allows you to change which models an enemy uses. Though the randomized model has to be able to use the original enemy's weapon.
* Enemy Stats: Allows you to randomize the various stats and equipment of an enemy.
* Balance Enemy Stats: Will balance how the enemy stats are randomized so they are appropriate for the point of the game they are encountered.
* Inconsistent Gear: Makes equipment type, name, and models inconsistent between one another.
* Ashley's Stats: Randomizes Ashley's starting stats and equipment.
* Fandango Stats: Randomizes the blade and grip which are used for the Fandango.
* Balance Ashley's Stats: Balances Ashley's stats and equipment to remain appropriate for the earlier parts of the game. 

## Limitations
Enemies can also only be changed to those which can be found within the same area. For example, Snowfly Forest opponents can only be swapped with other Snowfly Forest opponents.

Player character randomization was previously in the To Do list. Upon further testing, this will not be possible for the foreseeable future. If only because randomized characters are glitchy outside of battle mode. Should anyone still be interested though, this will be added in a later experimental build.

Certain locations are randomized rather than being on a room-by-room basis due to issues with how coordinates are translated from the ROM to the RAM. Because of this, only a selected few areas can be warped to with the locations randomizer. Locations which end with a door locked by a key, sigil, or have a cutscene transition won't be randomized as the game will not register the changes made by the tool. 

For some reason, if Ashley dies during the Greylands Incident, he will have the base game's starting stats when "Continue" is selected even if they were randomized. I will investigate this further if I can, but the best bet is to either not die or skip straight to the Wine Cellar.

## Contact
If you queries about the project, the best places to contact me are either one of my two Discord servers or my Twitter DMs.

Discord:

* Mullenkamp: https://discord.gg/PfbZAkTeCN
* Personal Discord: https://discord.gg/xmgKtf2tN6
* Kingdom of Ivalice: https://discord.gg/WZ2DbjHXJF

Twitter:

https://twitter.com/ChaoticBrave

Tumblr:

https://www.tumblr.com/chaoticbraves-workshop

Ko-fi:

https://ko-fi.com/chaoticbrave

## Credits
# Design and Development
* ChaoticBrave: For making the randomizer of course!
* Christo: For the idea of creating a randomizer in the first place. Also provided masses of feedback regarding how Blades and Grips are handled.
* the_eyes: For finding out where Ashley's initial equipment is in the game's files.
# Tools and Code
* Valendian: For the extensive knowledge in Vagrant Story's file systems, as well as creating the superb VSTOOLS and GodHands packages.
* CUE: For the psx-mode2 tool in the earlier builds. The project would've been lost without it.
* gingerbeardman: For letting me use his translation of psx-mode2 for the earlier builds.
* cebix: Creator of psximager, which is used for mpd file replacement in builds starting from v0.3.0.0.
* The Xenogears Perfect Works Build team: For very kindly providing the patcher code which is used in the GUI.
# Testing and Feedback
* NoharOSP: For being at hand to test this locally.
* mayaktheunholy: For discovering several errors with pre-0.5.1.0 builds.
* benjamin champion: Discovered that grips can be randomized in chests.
* Taterz: Discovered the Ghost crashes in the Catacombs, as well as several other bugs.
* Optrin: For discovering dll dependency errors and several other bugs.
* Another_Bloody_Wolf: For discovering the "untitled", enemy drop and Time Trial boss bugs, as well for suggesting the stat balance idea.
* Overlord Kego: For suggesting the option to keep randomized equipment stats.
* vagrant18: For suggesting the equipment consistency option.
# Special Thanks
* OddKara: Inspired me to do location-based randomizing rather than a room-by-room direction.
