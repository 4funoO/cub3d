# cub3d

Poject goal was to recreate 2D map in to 3D, using [ray-casting](https://en.wikipedia.org/wiki/Ray_casting) technology.
[Wolfenstein](https://en.wikipedia.org/wiki/Wolfenstein_3D) is one of the example of this technology was implemented.

How to run:

* Copy repository on your device
* cd into repository and type "make" in terminal
* Run Executable cub3D with 2nd parameter path to the map (ex: "./cub3D maps/map.cub")
* Profit!

P.S. "Make fclean" will delete all compiled files.

Unfortunatelly run only on mac os.

How to create map:

* Create regular file with .cub extension (ex: "test.ber")
*  Edit it with any text editor
*  Add fields for wall textures should exist with a path to .xpm files

   a) NO *path_to_north_texture.xpm*
   
   b) EA *path_to_east_texture.xpm*
   
   c) WE *path_to_north_texture.xpm*
   
   d) SO *path_to_north_texture.xpm*
   
*  Add fields for Floor and Ceilig colour in RGB format

   a) C *R,G,B*
   
   b) F *R,G,B*
   
   *replace R G and B with numbers*

*  Fill the acutal map with following elements:

   a) '1' - defines a Wall
   
   b) ' ' - Empty space
   
   c) '0' - Free space
   
   d) 'P' - Player position

Please note: Map should have only 1 Player. Any empty spaces should be surrounded by walls.
P.S. You need to find a key, to be able to open any door here ('E' button will do it).
