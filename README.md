# Vagrant Story Randomizer
A tool which will randomize a copy of Vagrant Story. 

A randomized game has been proven to work with both Beetle PSX, NO$PSX and DuckStation. Performance reportedly varies if ePSXe is used, so use that emulator at risk until problems which may affect it have been identified and resolved. 

For the latest version of the randomizer, check the Releases section.

## Old and Experimental Releases
Both old stable and experimental builds can be found here:

https://mega.nz/folder/wFV3CTzQ#NPZK8E4Wy-c_98T4n2DMTQ

## Changelog
* 0.1.0.0 (04/04/2022): Basic enemy randomizer using Python.
* 0.1.0.1 (10/04/2022): Added random drop randomization (experimental).
* 0.2.0.0 (12/04/2022): Altered rooms with treasure chests so that they actually randomize (stable).
* 0.2.0.1 (12/04/2022): Altered rooms with treasure chests so that they actually randomize (experimental).
* 0.3.0.0 (21/04/2022): Added random drop randomization (stable). psxinject from the psximager package is now used for mpd file replacement.
* 0.3.0.1 (23/04/2022): Randomized the Weapons which appear in treasure chests alongside their Gems (experimental). 
* 0.3.0.2 (29/04/2022): Randomized the Blades which appear in treasure chests. The Dark and Evil values of Weapon Gems will also now be randomized (experimental). 
* 0.3.0.3 (15/05/2022): Randomized the Shields which appear in treasure chests alongside their Gems. The item type for Blades will also now be randomized (experimental). 
* 0.3.0.4 (18/05/2022): Randomized the Armor which appears in treasure chests (experimental).
* 0.3.0.5 (22/05/2022): Randomized the Accessory which appears in treasure chests (experimental).
* 0.3.0.6 (24/05/2022): Randomized the Gems which appear in treasure chests (experimental).
* 0.4.0.0 (28/05/2022): Chests are now fully randomized. Any chests which have story-important items will not have their consumable items randomized (stable). 
* 0.5.0.0 (28/08/2022): The randomizer source code has now fully migrated to C++ (stable). 
* 0.5.0.1 (13/09/2022): An early room randomizer has been added (experimental). 
* 0.5.1.0 (30/09/2022): Several bug fixes and QoL improvements have been added. There is less reliance on downloading Visual Studio, anything related to psinject has been delegated to another folder, agility penalties are less strict with weapons, Dummy enemies will not be included as enemies to be fought, and bosses aren't randomized anymore due to reports of softlocking.
* 0.6.0.0 (24/01/2023): A game progression randomizer has been added (stable).
* 0.7.0.0 (28/01/2023): Grips can now be randomized in chests (stable).
* 0.7.1.0 (13/03/2023): Ghosts in the Catacombs will not be randomized so as to prevent crashes (stable).
* 0.7.2.0 (14/03/2023): To prevent further crashes, the enemies which weren't originally Ghosts won't be Ghosts. Rodent-Ridden Chamber is now exempt from enemy randomization (stable).
* 0.8.0.0 (10/05/2023): The entire randomizer has been converted to a GUI (stable).
* 0.8.1.0 (18/05/2023): Fixed a dll dependency error (stable).
* 0.8.2.0 (11/06/2023): Several bug fixes have been applied. Specifically for crashes in the Sanctum, Abandoned Mines B1, and Town Center. Options to save and enter seeds are now available (stable). 
* 0.8.3.0 (13/06/2023): Fixed an issue where the Sanctum and Catacombs changed enemies which were initially Ghosts. If other enemies are fought in their places, the game will freeze. Ever since that issue was discovered, the randomizer was supposed to prevent from Ghosts from being changed. However, up until this release, a coding error prevented such an operation from working properly (stable). 
* 0.8.4.0 (24/06/2023): Fixed an issue where the randomizer would crash when given seeds of a greater value than 2,147,483,647. Objects needed to solve puzzles will also no longer be randomized (stable).   
* 0.8.5.0 (05/07/2023): Fixed several bugs. The first is one where Snowfly Forest can load up the Time Trial version of the Earth Dragon; which will lead to two versions appearing and potentially locking up the game. Secondly, more Town Center East areas will no longer lock up. Thirdly, models for equipment will now only be type-specific. For example, Shields can now only use Shield models. Finally, if Keys and Sigils will appear in chests, the quantity will now only be 1 (stable). 
* 0.8.6.0 (16/08/2023): Made several fixes to issues which I've left hanging for too long. Any items which were called "untitled" were starting to become nuisances, so they will no longer appear in chests nor as drops. Enemies will now only drop consumable items. Time Trial copies of bosses will no longer appear. Equipment types will only use names within their pools. For example, blades will only use names of blades. This should hopefully deal with problems when crafting where empty combinations are "eating" donors. There are now also options to balance randomized equipment stats and leave the stats intact. Finally, there should be no more cases where the randomizer outright skips operations. The main cost is that a console window will show up when executing each option you select. It won't be for very long though (stable).
* 0.8.65.0 (28/08/2023): Fixed a bug where custom seeds being added would have their final character erased when stored. When the chest randomizer produces a Grimoire, there will now only be one. Finally, when consumable items are randomized, the quantity can only go as high as 100 (stable).
* 0.8.7.0 (14/09/2023): Your BIN/CUE pair for the game no longer needs to be in the same folder as the randomizer, you can clear any stored seed, you can restore your game back to a vanilla state, and there are now tool tips explaining what each parameter does (stable).
* 0.8.8.0 (21/11/2023): More stats are included in the "Keep Item Stats" option; chiefly the equipment material and weapon target sphere. An option has also been added where a randomized item will use that item's name and model. For example, a randomized Arbalest will use that name, item category, and the appropriate model. The "Revert to Vanilla" option should actually work properly now (stable).
* 0.8.82.0 (23/01/2024): Backwards travel for the area randomizer has been made more consistent. For example, if the next area after the Wine Cellar was Snowfly Forest, you can go back to the former through the latter. Though issues with the door code has meant that the Temple of Kiltia can no longer be a randomized destination. It will be missed... Blades will no longer use materials which can't be used with them, like Wood. This means less graphic glitches, hooray! Weapons will also now be randomized in a way where Grips will be set to those which can be combined with their paired Blade. This should make crafting a more consistent experience. You will also now be given the option to revert to the vanilla file system before you randomize. This will mean less buttons you have to press if you want a fresh randomized game (stable). 
* 0.8.83.0 (01/02/2024): Shields will now only refer to Shield models. No more cases of the Holy Win being a Shield! The Beast's Domain is now being counted as a boss room due to how there is a forced fight with Lizardmen. Being a boss room means the enemies won't be randomized. Shields no longer use negative values for Blunt, Edged and Piercing stats due to how they show up as positive in menus (stable).   
* 0.8.84.0 (14/02/2024): A bug has been fixed where the chest in Rust in Piece wasn't being randomized and producing garbage data (stable).
* 0.8.85.0 (19/02/2024): A bug has been fixed where the "Keep Item Stats" parameter produces half-finished Gems in Weapons and Shields (stable).
* 0.8.86.0 (08/04/2024): Randomized weapon names, models and types are now consistent by default, with an option to make them inconsistent (stable).
* 0.8.87.0 (28/05/2024): Saved seeds will now remember ticked parameters (stable).
* 0.8.87.1 (30/05/2024): Created a version of v0.8.87.0 which has the enemy model randomizer (experimental).
* 0.8.87.2 (10/11/2024): Created a initial version of an enemy stat randomizer. The randomizer will also accept seeds parameters properly, and no longer prompts you when reverting the game back to the vanilla maps and zones. The "Enemy Drops" parameter is also independent from the regular "Enemies" parameter (experimental).
* 0.8.9.0 (06/03/2025): Made the enemy stat randomizer stable, though you should still be careful using it. There is also the option to balance the enemy stats so they appropriate for the point in the game where they are encountered. Finally, the option to randomize Ashley's stats and equipment has been included (stable).
* 0.8.91.0 (28/03/2025): Altered the "Balance Item Stats" option so that the weapon and gem stats scale with game progression, and the item quantities do not go higher than 10. "Keep Item Stats" has had its name changed and effect inverted to be more consistent with how enemy parameters are named. Item stats will now be kept by default, and you need to tick "Item Stats" to see them randomized. "Item Stats" must also be ticked for "Balance Item Stats" to be available. If either "Balance Item Stats" or "Balance Ashley's Stats" are ticked, then agility drops will also be balanced by the blade and grip types you are using (stable).
* 0.8.92.0 (31/05/2025): Fixed some bugs concerning Ghost appearances in the Catacombs and Orcs in Abandoned Mines B2. Also added an option to balance the item quantities from chests so they can only go as high as 10 (stable).
* 0.8.93.0 (27/07/2025): Changed the Chests randomizer so that the blades and grips produced have their original stats if Item Stats is not selected. For example, a produced Hand of Light will have 30 STR, 0 INT and -7 AGI. The randomizer will also scale to monitors that have apps and text at a size greater than 100%. When the game loads, the randomizer will now check the hash. If it matches a vanilla game, you won't have the opportunity to revert back until your copy is randomized. You will not be asked if you want to revert if you start randomizing a vanilla game (stable).
* 0.8.94.0 (14/10/2025): Updated the model randomizer so that bosses are not changed. Also edited some enemy models to be left intact to prevent freezes. Added the option to randomize the misc items in Ashley's bag, and a dropdown menu where you can choose the thresholds for how high or low Ashley's STR, INT and AGL can reach. The UI is also now in wide form (stable).
* 0.8.95.0 (23/10/2025): Updated the area progression option so that you have to go through Catacombs and Sanctum before the location is randomised. Fixed a bug where enemy models are not randomised in the Wine Cellar. Fixed several model randomizer crashes. Fixed a bug where a seed refusing to select Enemy Stats unticks Balance Enemy Stats (stable).
* 0.8.96.0 (11/11/2025): Added a library needed to get the randomizer working if said library hasn't been downloaded already. Ensured that the minimum HP and MP Ashley can have are 40 and 5 respectively even without the balanced option ticked (stable).

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
* Balance Item Stats: Makes the randomized stats of weapons, blades, grips, gems, shields, and armour in chests less extreme. Blade, grip and gem stats will also be adjusted by area in the story.
* Area Progression: Randomizes where you go next depending on the area you're in.
* Item Stats: Randomizes the stats of weapons, blades, grips, gems, shields, and armour in chests from being randomized.
* Enemy Models: Allows you to change which models an enemy uses. Though the randomized model has to be able to use the original enemy's weapon.
* Enemy Stats: Allows you to randomize the various stats and equipment of an enemy.
* Balance Enemy Stats: Will balance how the enemy stats are randomized so they are appropriate for the point of the game they are encountered.
* Inconsistent Gear: Makes equipment type, name, and models inconsistent between one another.
* Ashley's Stats: Randomizes Ashley's starting stats and equipment.
* Fandango Stats: Randomizes the blade and grip which are used for the Fandango.
* Balance Ashley's Stats: Balances Ashley's stats and equipment to remain appropriate for the earlier parts of the game. 
* Ashley Stat Threshold: Determines the minimum and maximum STR, INT and AGL a balanced Ashley can have. You can choose from low, medium and high. Low is 75-125, medium is 50-150 and high is 25-175.
* Ashley's Misc Items: Randomizes Ashley's misc consumable items which he starts with.
* Misc Item Quantities: Randomizes the quantities of the randomized misc items.

## Limitations
Enemies can also only be changed to those which can be found within the same area. For example, Snowfly Forest opponents can only be swapped with other Snowfly Forest opponents.

Player character randomization was previously in the To Do list. Upon further testing, this will not be possible for the foreseeable future. If only because randomized characters are glitchy outside of battle mode. Should anyone still be interested though, this will be added in a later experimental build.

Certain locations are randomized rather than being on a room-by-room basis due to issues with how coordinates are translated from the ROM to the RAM. Because of this, only a selected few areas can be warped to with the locations randomizer. Locations which end with a door locked by a key, sigil, or have a cutscene transition won't be randomized as the game will not register the changes made by the tool. 

For some reason, if Ashley dies during the Greylands Incident, he will have the base game's starting stats when "Continue" is selected even if they were randomized. I will investigate this further if I can, but the best bet is to either not die or skip straight to the Wine Cellar.

The enemy model randomizer is highly unstable even on stable builds. The sheer quantity on enemy and model combinations means this is difficult to thoroughly ACID test. Use this parameter at risk.

## Contact
If you queries about the project, the best places to contact me are either one of my two Discord servers or my Twitter DMs.

Discord:

* Mullenkamp: https://discord.gg/PfbZAkTeCN
* Personal Discord: https://discord.gg/xmgKtf2tN6
* Kingdom of Ivalice: https://discord.gg/WZ2DbjHXJF

Bluesky:
https://bsky.app/profile/chaoticbrave.bsky.social

Twitter:

https://twitter.com/ChaoticBrave

Tumblr:

https://www.tumblr.com/chaoticbraves-workshop

Ko-fi:

https://ko-fi.com/chaoticbrave

## Credits
### Design and Development
* ChaoticBrave: For making the randomizer of course!
* Christo: For the idea of creating a randomizer in the first place. Also provided masses of feedback regarding how Blades and Grips are handled.
* the_eyes: For finding out where Ashley's initial equipment is in the game's files.
### Tools and Code
* Valendian: For the extensive knowledge in Vagrant Story's file systems, as well as creating the superb VSTOOLS and GodHands packages.
* CUE: For the psx-mode2 tool in the earlier builds. The project would've been lost without it.
* gingerbeardman: For letting me use his translation of psx-mode2 for the earlier builds.
* cebix: Creator of psximager, which is used for mpd file replacement in builds starting from v0.3.0.0.
* The Xenogears Perfect Works Build team: For very kindly providing the patcher code which is used in the GUI.
### Testing and Feedback
* NoharOSP: For being at hand to test this locally.
* mayaktheunholy: For discovering several errors with pre-0.5.1.0 builds.
* benjamin champion: Discovered that grips can be randomized in chests.
* Taterz: Discovered the Ghost crashes in the Catacombs, as well as several other bugs.
* Optrin: For discovering dll dependency errors and several other bugs.
* Another_Bloody_Wolf: For discovering the "untitled", enemy drop and Time Trial boss bugs, as well for suggesting the stat balance idea.
* Overlord Kego: For suggesting the option to keep randomized equipment stats.
* vagrant18: For suggesting the equipment consistency option.
* JDSilvergun: For suggesting balance improvements.
* Bledyo: For discovering bugs with the model randomizer and suggesting the option to choose stat thresholds.
* Tabs: For discovering the libcrypto-3-x64.dll dependency.
### Special Thanks
* OddKara: Inspired me to do location-based randomizing rather than a room-by-room direction.
