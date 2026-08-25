# Vagrant Story Randomizer
A tool which will randomize a copy of Vagrant Story. 

A randomized game has been proven to work with both Beetle PSX, NO$PSX and DuckStation. Performance reportedly varies if ePSXe is used, so use that emulator at risk until problems which may affect it have been identified and resolved. 

For the latest version of the randomizer, check the Releases section.

For any extra information, please read the wiki available on the GitHub repository.

## Old and Experimental Releases
Both old stable and experimental builds can be found here:

https://mega.nz/folder/wFV3CTzQ#NPZK8E4Wy-c_98T4n2DMTQ

## Latest version
* 0.9.2.0 (25/08/2026): Made stat randomization more flexible. Added the option for Ashley to use ultimate spells. Gave the option to randomize frame windows (stable).

## To Do
If you wish to keep up-to-date with this project and what will be updated short-term, a link to the Trello can be found below:
https://trello.com/b/BZRfh8ht/vagrant-story-randomizer

## Using this GitHub project
Many can find these GitHubs tedious, myself included. The "Releases" section exists for those who just want to extract the ZIP and get into the action. For those who wish to make their own alterations, the C++ files have been included.

If you make any alterations to the source code and you want to bring your project to life, make sure that your exe is in the same directory as the ZONES and MAPS directories, as well as a psxinject exe file and its necessary dll files after conversion in order for it to work. 

## What are the parameters available?
* Enemies Placements: Randomizes the enemy placements within an area.
* Enemy Base Stats: Randomizes the enemy's HP, MP, STR, INT, AGL and speed stats.
* Enemy Base Equipment Stats: Randomizes the enemy's equipment values which are not related to class, affinity, blunt, edged, or piercing.
* Enemy Equipment Class Stats: Randomizes the enemy's equipment class values.
* Enemy Equipment Affinity Stats: Randomizes the enemy's equipment affinity values.
* Enemy Equipment Blunt/Edged/Piercing Stats: Randomizes the enemy's equipment blunt, edged, and piercing values.
* Enemy Appendages: Randomizes the values of enemy appendages.
* Drops: Randomizes what each enemy drops. This will only apply to the random drops of an enemy. Guaranteed drops are unaltered to prevent softlocks.
* Balance Item Stats: Makes the randomized stats of weapons, blades, grips, gems, shields, and armour in chests less extreme. Blade, grip and gem stats will also be adjusted by area in the story.
* Balance Item Quantities: Balances the quantities for items found in chests to be more like what is found in the vanilla game.
* Chests: Randomizes the contents of a chest.
* Chest Item Base Stats: Randomizes the equipment values which are not related to class, affinity, blunt, edged, or piercing.
* Chest Item Class Stats: Randomizes the equipment class values.
* Chest Item Affinity Stats: Randomizes the equipment affinity values.
* Chest Item Blunt/Edged/Piercing Stats: Randomizes the equipment blunt, edged, and piercing values.
* Area Progression: Randomizes where you go next depending on the area you're in.
* Enemy Models: Allows you to change which models an enemy uses. Though the randomized model has to be able to use the original enemy's weapon.
* Balance Enemy Stats: Will balance how the enemy stats are randomized so they are appropriate for the point of the game they are encountered.
* Inconsistent Gear: Makes equipment type, name, and models inconsistent between one another.
* Ashley's Base Stats: Randomizes Ashley's base stat and equipment values which are not related to class, affinity, blunt, edged, or piercing.
* Ashley's Class Stats: Randomizes Ashley's base stat and equipment class values.
* Ashley's Affinity Stats: Randomizes Ashley's base stat and equipment affinity values.
* Ashley's Blunt/Edged/Piercing Stats: Randomizes Ashley's blunt, edged, and piercing values.
* Fandango Blade and Grip: Randomizes the blade and grip which are used for the Fandango.
* Balance Ashley's Stats: Balances Ashley's stats and equipment to remain appropriate for the earlier parts of the game. 
* Ashley Stat Threshold: Determines the minimum and maximum STR, INT and AGL a balanced Ashley can have. You can choose from low, medium and high. Low is 75-125, medium is 50-150 and high is 25-175.
* Ashley's Misc Items: Randomizes Ashley's misc consumable items which he starts with.
* Misc Item Quantities: Randomizes the quantities of the randomized misc items.
* Mandatory Iron Maiden: You must beat Asura to access Great Cathedral. The means to access Iron Maiden outside of New Game + have been given to Kali.
* Open World: Gives Ashley access to every key and sigil at the start of the game.
* Ashley Build: Creates a starting build for Ashley based on a chosen weapon type. More details can be found on the randomizer GitHub repository wiki.
* Break Art Costs: Randomizes the costs to learn and use Break Arts.
* Balance Break Art Costs: Balances the possible values for Break Art costs.
* Area Music: Randomizes the music that plays in areas. More information can be found on the wiki.
* Restore Cut Music: Has "Lea Monde", "Lizardman", and "Within the City Walls" play for their appropriate areas and bosses.
* Boss Music: Randomizes the music that plays on boss fights.
* Ice Wolf: Will turn Hellhounds in City Walls into ice-based opponents (based on a bug).
* Blade Cost Stat: Randomizes the damage cost stat of blades in chests.
* Fandango Cost Stat: Randomizes the damage cost stat of the Fandango.
* Chain Ability Learning Costs: Randomizes the number of chains needed to learn each battle ability.
* Chain Ability Damage Costs: Randomizes the risk costs needed to use each chain ability.
* Learn Ultimate Spells: Replaces the Level 4 versions of elemental spells with ultimate spells used by enemies.
* Ability Time Frames: Randomizes the number of frames you have to use a chain or defense ability.

## Zenith options
* Free Teleport
* Perfect Analyze Hit Rate
* Manabreaker does not block friendly spells
* Drop system where repeatedly killing the same enemy increases the odds of dropping their equipment
* Specific bosses drop Warlock Grimoires
* Gremlins and Crimson Blades no longer cast spells.
Please consult the Vagrant Story Zenith WordPress for more information:
https://vszenith.wordpress.com/

## Limitations
Enemies can also only be changed to those which can be found within the same area. For example, Snowfly Forest opponents can only be swapped with other Snowfly Forest opponents.

Player character randomization was previously in the To Do list. Upon further testing, this will not be possible for the foreseeable future. If only because randomized characters are glitchy outside of battle mode. Should anyone still be interested though, this will be added in a later experimental build.

Certain locations are randomized rather than being on a room-by-room basis due to issues with how coordinates are translated from the ROM to the RAM. Because of this, only a selected few areas can be warped to with the locations randomizer. Locations which end with a door locked by a key, sigil, or have a cutscene transition won't be randomized as the game will not register the changes made by the tool. 

For some reason, if Ashley dies during the Greylands Incident, he will have the base game's starting stats when "Continue" is selected even if they were randomized. I will investigate this further if I can, but the best bet is to either not die or skip straight to the Wine Cellar.

The enemy model randomizer is highly unstable even on stable builds. The sheer quantity on enemy and model combinations means this is difficult to thoroughly ACID test. Use this parameter at risk.

Because there are two versions of the scene when Ashley encounters the Lizardmen, if restored, their battle track when play when the doors lock behind Ashley.

Model sizes can not be changed outside of RAM editing.

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
* the_eyes: For finding out where Ashley's initial equipment is in the game's files. Also for letting me use the Zenith features on an individual basis.
### Tools and Code
* Valendian: For the extensive knowledge in Vagrant Story's file systems, as well as creating the superb VSTOOLS and GodHands packages.
* CUE: For the psx-mode2 tool in the earlier builds. The project would've been lost without it.
* gingerbeardman: For letting me use his translation of psx-mode2 for the earlier builds.
* cebix: Creator of psximager, which is used for mpd file replacement in builds starting from v0.3.0.0.
* The Xenogears Perfect Works Build team: For very kindly providing the patcher code which is used in the GUI.
* ser-pounce: For the Rood Reverse project.
### Testing and Feedback
* NoharOSP: For being at hand to test this locally.
* mayaktheunholy: For discovering several errors with pre-0.5.1.0 builds.
* benjamin champion: Discovered that grips can be randomized in chests.
* Taterz: Discovered the Ghost crashes in the Catacombs, as well as several other bugs.
* Optrin: For discovering dll dependency errors and many, many, many other bugs.
* Another_Bloody_Wolf: For discovering the "untitled", enemy drop and Time Trial boss bugs, as well for suggesting the stat balance idea.
* Overlord Kego: For suggesting the option to keep randomized equipment stats.
* vagrant18: For suggesting the equipment consistency option.
* JDSilvergun: For suggesting balance improvements.
* Bledyo: For discovering bugs with the model randomizer, and suggesting both the option to choose stat thresholds and build options.
* Tabs: For discovering the libcrypto-3-x64.dll dependency.
* snapperfisch: For suggesting the split in how stats should be randomized.
### Special Thanks
* OddKara: Inspired me to do location-based randomizing rather than a room-by-room direction.
* redd2213: Inspired me to use a progress bar.
* Coffee Potato: Contributed Ashley build ideas.
* PowerPanda: Inspired me to create a music restoration option.
* riezahughes: Inspired me to approach the game's code on a more practical level.