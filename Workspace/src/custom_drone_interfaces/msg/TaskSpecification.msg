#   Future proof task handling. 
#   Current flags:
#   1   = TAKE_OFF
#   2   = LANDING
#   3   = CAMERA_IMAGE			The UAV is instructed to take image(s).
#   4   = VIDEO_START_CAPTURE 	Video capture starts.
#   5   = VIDEO_STOP_CAPTURE	Video capture ends.
#   
#   255 = TO_TASK               Nothing to do
int16 flag
float64[5] settings 