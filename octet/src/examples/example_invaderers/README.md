Wing Commander
I’ve worked out an idea for game but not sure if it will be anywhere near finished.
I’ve been researching Tile based games. The game is sort of based on asteroids but is a dog fight space battle and trading game, also a bit like elite but in 2D.
I’ve found a Tile based editor called Tiled that can create 32x32 pixel tiles and create a level map.
Wing Commander was a game by Origin, which was a space dog fight game between military and space aliens who looked like Lions.
It wasn’t quite 3D but 2.5D using a fake 3D or Isometric sprites for the ships and a cockpit view of space so you were flying your space ship and could shoot at enemy ships.
It had perspective and the sprites would get bigger as the got nearer.
An alternative game called Privateer allowed you to be a Merc, Pirate or Trader transporting cargo between planets and space stations.
The military game allowed you to fly missions with other ships, so you might be supporting a convoy of space battleships or space fighter carriers. As part of this mission you might have other space fighters who would fly on your wing in formation and would break to fight a bunch of enemy alien fighters once you found them.
My game is based on a 2D tiled space background with planets or space stations or large capital space ships such as fighter carriers or space battle ships.
Wing Commander used Jump engines that could jump through hyperspace wormholes to reach other planets or star systems. There was also a map that you could use to plot a course through the jump gates to reach far off planets.
The ships would be 2D and can turn left or right using the arrow keys and set an engine velocity.
The ships would have shields and not be destroyed by one hit but would be able to take some damage before being destroyed.
Initially weapons would be a simple missile system.
There would be an enemy ship AI and a support ship AI that would automatically attack enemy ships.
The enemy ships would attack you, your support fighters and any capital ships that you are defending.
If the capital ship is destroyed that is a mission fail but not a game over.
Wing Commander used a space fighter carrier ship as a base for your fighter to give mission briefings.
Privateer had bases on Planets or Space stations that allowed upgrades of ships and weapons and either bounty missions for merc’s (mercenaries) or cargo missions or ability to buy a cargo from a trading terminal.
By flying cargo to a different planet, you could make profits in game gold that you could se to buy a better ship or weapons.
So, starting with the Invaders game, I think the first thing to do is remove the enemy sprites and bombs.
Then change the movement of ship so it can fly around the page.
Add the tile based background with a space based stars and planets background.
The tile background should have a viewpoint that allows it to scroll and it should be much bigger than a single screen.
Then I would look at working at an AI for the enemy alien ships.
This could be modified to work as a support AI for extra military fighter and capital ships.
This would include a shield system for the ships to allow for the ship to be damaged before being destroyed which should hopefully make for a longer game.
The text could be changed to give information about shield strength, damage, engine speed and weapons charge.
The game would be over if your ship is destroyed.
Game Commands
Left arrow – turn Left
Right arrow -  turn right
Space Bar – fire missile
J – Jump drive (only works near a jump gate)
Do I need a key to increase engine speed? Or to start with just make that the ship is always moving forward?
Using the arrow keys will change where ship is pointing. It can fly in one of eight directions, which includes North, East, West and South. Also, North East, North West and South East and South West.
If ship is flying North and you press right arrow key it will change to flying North East.
If you press right arrow key again it will now be flying East.
If you then press the left arrow key the ship will be flying North East.
A second right arrow key press will bring ship back to flying North.
When the ship reaches the top of tile map it will wrap to be at the bottom of the tile map.
If the ship reaches the start of the map by flying West, it will wrap to the end of the map.
By doing this the map will be circular. As most of the map will be black space tiles or tiles with stars it should not be noticeable if you wrap the map.
Once more level and planets are available there would need to be some logic for getting the jump gates to work. Different gates would jump to different level maps. The J key would allow you to hyper jump but would only work within a certain distance from the jump gate. There should be some sort of indication saying that you can use jump drive.
A level should have a minimum of two jump gates. Some levels might have 3 or 4 jump gates.
Levels might contain Planets, Space stations and large capital ships.
One level could contain the Fleet or the Fleet might be able to move to different points in the map.
Future Upgrades
Different levels can have planets or space stations and jump gates to different maps.
One mission type would be to defend capital ships as they jump through the jump gates.
Another mission might be to defend cargo ships from pirates.
Another mission might be to escort ships to the main fleet.
Upgrades would be to add maps for bases and mission briefings. Adding more text and stats with a promotion for killing a certain number of ships.
You could start as Flight Lieutenant, be promoted to Captain, Major, Colonel, Squadron leader and Wing Commander.
Having a map of the jump gates would be useful.
The ability to dock with a base ship would allow for a selection of missions or ability to fly different ships such as bomber or destroyers.
Adding pirate, mercenary, religious zealots and cargo trade ships might make game more interesting.
Defending Cargo ships or killing pirates or zealots might improve your score.
Score could be ship kills of different types.
It might be possible to include missions to attack alien capital ships as extra missions.
It would be possible to re-code game as a 3D game, with 3D ships, Planets and Space stations.
A procedural generator could be used to generate 3D Planets.

