#Simple scene with a plane

[scene]
name=scene_plane

[render]
size_x=800
size_y=600

[camera]
position_x=200.0
position_y=0.0
position_z=0.0
rotation_x=0.0
rotation_y=0.0
rotation_z=0.0

[object]
name=plane
position_x=0.0
position_y=0.0
position_z=0.0
rotation_x=0.0
rotation_y=0.0
rotation_z=0.0
color=0x00ffff00

Window:
	Title: Scene 01
	Width: 800
	Height: 600

Camera:
	Position: 5.0 0.0 10.0
	Rotation: 30.0 20.0 -7.0

Light:
	Position: 0.0 0.0 0.0
	Intensity: 1.0000

Sphere:
	Position: 20.0 0.0 0.0
	Rotation: 0.0 0.0 0.0
	Radius: 10.0
	Color: #1e8bc3

Plane:
	Position: 0.0 0.0 0.0
	Rotation: 0.0 0.0 0.0
	Color: #1e8bc3
