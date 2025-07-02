#Battery
float32 remaining			# From 1 to 0, -1 if unknown
float32 time_remaining_s		# predicted time in seconds remaining until battery is empty under previous averaged load, NAN if unknown
uint8 battery_warning			# Battery warning level
bool battery_unhealthy			# Battery unhealthy

#Fail flags
bool angular_velocity_invalid		# Angular velocity invalid
bool attitude_invalid			# Attitude invalid
bool global_position_invalid		# Global position estimate invalid
bool wind_limit_exceeded		# Wind limit exceeded

# Failure
bool esc_arming_failure            # ESC failed to arm
bool imbalanced_prop               # Imbalanced propeller detected
bool motor_failure                 # Motor failure
