---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------- Eric's modifications to allow use of custom button box ----------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-- BUTTON BOX
-- Parking brake
{down = device_commands.Button_6, up = device_commands.Button_6, cockpit_device_id = devices.CONTROL_SYSTEM, value_down = 1.0, value_up = 0.0, name = _('BB Wheel brake Parking'), category = _('CUSTOM')},

-- Landing lights
-- Toggle only, not directional: {down = device_commands.Button_4, up = device_commands.Button_4, cockpit_device_id = devices.LIGHT_SYSTEM, value_down = 1.0, value_up = 0.0, name = _('BB Landing Light (old)'), category = _('CUSTOM')},
-- {down = device_commands.Button_3, up = device_commands.Button_3, cockpit_device_id = devices.LIGHT_SYSTEM, value_down = 1.0, value_up = 0.0, name = _('BB Landing Light - OLD: TOGGLE ONLY'), category = _('CUSTOM')},
{down = device_commands.Button_7, up = device_commands.Button_7, cockpit_device_id = devices.LIGHT_SYSTEM, value_down = 1, value_up = 0, name = _('BB Landing Light'), category = _('CUSTOM')},


-- Placeholder for bottom left (ON)-OFF-(ON) switch

-- Landing gear
-- Toggle only, not directional: {down = device_commands.Button_4, up = device_commands.Button_4, cockpit_device_id = devices.CONTROL_SYSTEM, value_down = 1.0, value_up = 0.0, name = _('BB Landing Gear Up/Down (old)'), category = _('CUSTOM')},
{down = device_commands.Button_3, up = device_commands.Button_3, cockpit_device_id = devices.CONTROL_SYSTEM, value_down = 1.0, value_up = 0.0, name = _('BB Landing Gear Up/Down'), category = _('CUSTOM')},


-- Gun safety switch
{down = device_commands.Button_7, up = device_commands.Button_7, cockpit_device_id  = devices.FRONT_SWITCH_BOX, value_down = 1.0, value_up = 0.0, name = _('BB Gun safety switch GUN CAMERA SIGHT'), category = _('CUSTOM')},
{down = device_commands.Button_7, up = device_commands.Button_7, cockpit_device_id  = devices.FRONT_SWITCH_BOX, value_down = -1.0, value_up = 0.0, name = _('BB Gun safety switch CAMERA SIGHT'), category = _('CUSTOM')},
-- {down = device_commands.Button_7, cockpit_device_id  = devices.FRONT_SWITCH_BOX, value_down = 0.0, name = _('BB Gun safety switch OFF'), category = _('BUTTON BOX')},

-- K-14 Gunsight
{down = device_commands.Button_3, up = device_commands.Button_3, cockpit_device_id  = devices.K14_GUNSIGHT, value_down = 0.0, value_up = 0.1, name = _('BB Gunsight mode FIXED'), category = _('CUSTOM')},
{down = device_commands.Button_3, up = device_commands.Button_3, cockpit_device_id  = devices.K14_GUNSIGHT, value_down = 0.2, value_up = 0.1, name = _('BB Gunsight mode GYRO'), category = _('CUSTOM')},
-- {down = device_commands.Button_3, cockpit_device_id  = devices.K14_GUNSIGHT, value_down = 0.1,	 name = _('Gunsight mode FIXED GYRO'), category = _('BUTTON BOX')},

-- Rocket release control switch
{down = device_commands.Button_7, up = device_commands.Button_7, cockpit_device_id = devices.WEAPON_CONTROL, value_down = 0.0, value_up = 0.1, name = _('BB Rockets release control switch OFF'), category = _('CUSTOM')},
{down = device_commands.Button_7, up = device_commands.Button_7, cockpit_device_id = devices.WEAPON_CONTROL, value_down = 0.2, value_up = 0.1, name = _('BB Rockets release control switch AUTO'), category = _('CUSTOM')},
-- {down = device_commands.Button_7, cockpit_device_id  = devices.WEAPON_CONTROL, value_down = 0.1, name = _('Rockets release control switch SINGLE'), category = _('BUTTON BOX')},

-- Rocket Delay/Inst
-- Toggle only: {down = device_commands.Button_11, up = device_commands.Button_11, cockpit_device_id = devices.WEAPON_CONTROL, value_down = 1, value_up = 0, name = _('BB Rockets Delay/Inst (old)'), category = _('CUSTOM')},
{down = device_commands.Button_14, up = device_commands.Button_14, cockpit_device_id = devices.WEAPON_CONTROL, value_down = 0, value_up = 1, name = _('BB Rockets Delay/Inst'), category = _('CUSTOM')},

-- Bomb Release
{down = device_commands.Button_9, up = device_commands.Button_9, cockpit_device_id = devices.FRONT_SWITCH_BOX, value_down = 0.0, value_up = -1.0, name = _('BB Bomb arming switch left ARM'), category = _('CUSTOM')},
{down = device_commands.Button_10, up = device_commands.Button_10, cockpit_device_id = devices.FRONT_SWITCH_BOX, value_down = 0.0, value_up = -1.0, name = _('BB Bomb arming switch right ARM'), category = _('CUSTOM')},

-- Rear Warning Radar
{down = device_commands.Button_7, up = device_commands.Button_7, cockpit_device_id  = devices.TAIL_WARNING_RADAR, value_down = 1.0, value_up = 0.0, name = _('BB Rear Warning Radar'), category = _('CUSTOM')},


-- THROTTLE BASE
-- Battery and Generator
{down = device_commands.Button_13, up = device_commands.Button_13, cockpit_device_id = devices.RIGHT_SWITCH_PANEL, value_down = 1.0, value_up = 0.0, name = _('THROTTLE BASE Generator On/Off'), category = _('CUSTOM')},
{down = device_commands.Button_12, up = device_commands.Button_12, cockpit_device_id = devices.RIGHT_SWITCH_PANEL, value_down = 1.0, value_up = 0.0, name = _('THROTTLE BASE Battery On/Off'), category = _('CUSTOM')},


-- Primer & Starter
{down = device_commands.Button_11, up = device_commands.Button_11, cockpit_device_id  = devices.ENGINE_CONTROL_PANEL, value_down = 1.0, value_up = 0.0, name = _('THROTTLE BASE Primer'), category = _('CUSTOM')},
-- {down = device_commands.Button_14, up = device_commands.Button_14, cockpit_device_id  = devices.ENGINE_CONTROL_PANEL, value_down = 1.0, value_up = 0.0, name = _('THROTTLE BASE Primer'), category = _('CUSTOM')},
{down = device_commands.Button_8, up = device_commands.Button_8, cockpit_device_id  = devices.ENGINE_CONTROL_PANEL, value_down = 1.0, value_up = 0.0, name = _('THROTTLE BASE Starter Activate'), category = _('CUSTOM')},
-- {down = device_commands.Button_8, up = device_commands.Button_9, cockpit_device_id  = devices.ENGINE_CONTROL_PANEL, value_down = 1.0, value_up = 0.0, name = _('THROTTLE BASE Starter Cover (Reverse)'), category = _('CUSTOM')},
{down = device_commands.Button_9, up = device_commands.Button_9, cockpit_device_id  = devices.ENGINE_CONTROL_PANEL, value_down = 0.0, value_up = 1.0, name = _('THROTTLE BASE Starter Cover'), category = _('CUSTOM')},


-- Ignition
{down = device_commands.Button_2, up = device_commands.Button_2, cockpit_device_id = devices.FRONT_SWITCH_BOX, value_down = 0.3,value_up = 0.0, name = _('THROTTLE BASE Ignition On(Both)/Off'), category = _('CUSTOM')},
-- {down = device_commands.Button_2, cockpit_device_id  = devices.FRONT_SWITCH_BOX, value_down = 0.0,	 name = _('Ignition switch OFF'), category = _('Front Switch Box')},
-- {down = device_commands.Button_2, cockpit_device_id  = devices.FRONT_SWITCH_BOX, value_down = 0.1,	 name = _('Ignition switch Right'), category = _('Front Switch Box')},
-- {down = device_commands.Button_2, cockpit_device_id  = devices.FRONT_SWITCH_BOX, value_down = 0.2,	 name = _('Ignition switch Left'), category = _('Front Switch Box')},


-- Fuel Booster
{down = device_commands.Button_12, up = device_commands.Button_12, cockpit_device_id = devices.ENGINE_CONTROL_PANEL, value_down = 1.0, value_up = 0.0, name = _('THROTTLE BASE Fuel Booster ON/OFF'), category = _('CUSTOM')},
-- {down = device_commands.Button_12, cockpit_device_id = devices.ENGINE_CONTROL_PANEL, value_down = 0.0, name = _('Fuel Booster OFF'), category = _('Engine Control Panel')},

-- Fuel shut-off
{down = device_commands.Button_5, up = device_commands.Button_5, cockpit_device_id  = devices.FUEL_SYSTEM, value_down = 1.0, value_up = 0.0, name = _('THROTTLE BASE Fuel shut-off ON/OFF'), category = _('CUSTOM')},

-- Fuel Selector
{down = device_commands.Button_1, up = device_commands.Button_1, cockpit_device_id = devices.FUEL_SYSTEM, value_down = 0.1, value_up = 0.2, name = _('THROTTLE BASE Fuel selector Left/Fuselage'), category = _('CUSTOM')},
{down = device_commands.Button_1, up = device_commands.Button_1, cockpit_device_id = devices.FUEL_SYSTEM, value_down = 0.3, value_up = 0.2, name = _('THROTTLE BASE Fuel selector Right/Fuselage'), category = _('CUSTOM')},
-- {down = device_commands.Button_1, cockpit_device_id  = devices.FUEL_SYSTEM, value_down = 0.0, name = _('Fuel selector Right Combat Tank'), category = _('Fuel Control')},
-- {down = device_commands.Button_1, cockpit_device_id  = devices.FUEL_SYSTEM, value_down = 0.2, name = _('Fuel selector Fuselage Tank'), category = _('Fuel Control')},
-- {down = device_commands.Button_1, cockpit_device_id  = devices.FUEL_SYSTEM, value_down = 0.4, name = _('Fuel selector Left Combat Tank'), category = _('Fuel Control')},

-- THROTTLE HANDLE
-- Mixture
{down = device_commands.Button_11, up = device_commands.Button_11, cockpit_device_id = devices.ENGINE_SYSTEM, value_down = 0.0, value_up = 0.1, name = _('THROTTLE Mixture IDLE CUT OFF'), category = _('CUSTOM')},
{down = device_commands.Button_11, up = device_commands.Button_11, cockpit_device_id = devices.ENGINE_SYSTEM, value_down = 0.2, value_up = 0.1, name = _('THROTTLE Mixture EMERGENCY FULL RICH'), category = _('CUSTOM')},
-- {down = device_commands.Button_11, cockpit_device_id  = devices.ENGINE_SYSTEM, value_down = 0.1, name = _('Mixture RUN'), category = _('Flight Control')},

-- Wing and Tail Lights
{down = device_commands.Button_17, cockpit_device_id  = devices.RIGHT_SWITCH_PANEL, value_down = 1.0, name = _('THROTTLE Position lights wing (rotary)'), category = _('CUSTOM')},
{down = device_commands.Button_18, cockpit_device_id  = devices.RIGHT_SWITCH_PANEL, value_down = 1.0, name = _('THROTTLE Position light tail (rotary)'), category = _('CUSTOM')},

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
