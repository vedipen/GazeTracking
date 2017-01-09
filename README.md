# GazeTracking
Gaze Tracking module for Pediatric Perimeter, undertaken by Srujana - Innovation at LVPEI. A novel device to measure and quantify visual fields and reaction times to light stimulus in infants. This device would assist in the early detection of neonatal eye diseases and early signs of vision-threatening conditions .

Use
===

Basic
-----

frame

> the number of the frame processed

timestamp 

> the timer of video being processed in seconds

confidence 

> how confident is the tracker in current landmark detection estimate

success 

> is the track successful (is there a face in the frame or do we think
		> we tracked it well)

Gaze
----

gaze_0_x, gaze_0_y, gaze_0_z 

> Eye gaze direction vector in world coordinates for eye 0 (normalized)

gaze_1_x, gaze_1_y, gaze_2_z 

> Eye gaze direction vector in world coordinates for eye 0 (normalized)

Pose
----

pose_Tx, pose_Ty, pose_Tz 

> the location of the head with respect to camera in millimetre
> (positive Z is away from the camera)

pose_Rx, pose_Ry, pose_Rz 

> Rotation is in radians around X,Y,Z axes with the convention R = Rx *
> Ry * Rz, left-handed positive sign. The rotation can be either in
> world or camera coordinates (for visualisation we want rotation with
> respect to world coordinates). This is controlled by world_coord <1/0>
> flag

Run
----

	FeatureExtraction.exe -verbose -no2Dfp -no3Dfp -noMparams -noAUs -fx 700 -fy 700
	-of "C:\Users\Dipen\Desktop\test.txt"

