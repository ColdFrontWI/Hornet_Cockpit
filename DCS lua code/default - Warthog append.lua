---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------- Eric's modifications to allow use of custom button box ----------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------- Landing gear panel ----------------------------------------------------------------------------------
-- Anti-skid: Works, but does not auto turn off when battery power removed
{down = 3029, up = 3028, cockpit_device_id = 38, value_down = 1.0,	value_up = -1.0, name = _('Anti-skid switch CLICKABLE'), category = _('Button Box - Landing gear panel')},
-- Old {down = iCommandPlaneLGPAntiSkid, up = iCommandPlaneLGPAntiSkid, name = _('Anti-Skid TOGGLE'), category = _('Button Box - Landing gear panel')},

-- Taxi / landing lights
{down = iCommandPlaneLGPLandLight, up = iCommandPlaneLGPLightsOff, name = _('Landing Lights TOGGLE'), category = _('Button Box - Landing gear panel')},
{down = iCommandPlaneLGPTaxiLight, up = iCommandPlaneLGPLightsOff, name = _('Taxi Lights TOGGLE'), category = _('Button Box - Landing gear panel')},

-- Landing gear
{down = iCommandPlaneGearUp, up = iCommandPlaneGearDown, name = _('Landing Gear TOGGLE'), category = _('Button Box - Landing gear panel')},

-- Non-working anti-skid implementations
-- Only toggles the state {down = 3028, cockpit_device_id = 38, value_down = 1.0,	value_up = -1.0, name = _('Anti-skid switch CLICKABLE 28 down only'), category = _('Button Box - Landing gear panel')},
-- {down = 3028, up = 3028, cockpit_device_id = 38, value_down = 1.0,	value_up = -1.0, name = _('Anti-skid switch CLICKABLE 28 up/down'), category = _('Button Box - Landing gear panel')},
-- Only turns on {down = 3029, cockpit_device_id = 38, value_down = 1.0,	value_up = -1.0, name = _('Anti-skid switch CLICKABLE 29 down only'), category = _('Button Box - Landing gear panel')},
-- {down = 3029, up = 3029, cockpit_device_id = 38, value_down = 1.0,	value_up = -1.0, name = _('Anti-skid switch CLICKABLE 29 down/up'), category = _('Button Box - Landing gear panel')},
-- On always toggles {down = 3028, up = 3029, cockpit_device_id = 38, value_down = 1.0,	value_up = -1.0, name = _('Anti-skid switch CLICKABLE 28 down / 29 up'), category = _('Button Box - Landing gear panel')},
-- On always turns on.  Every OTHER off turns off {down = 3029, up = 3028, cockpit_device_id = 38, value_down = 1.0,	value_up = 1.0, name = _('Anti-skid switch CLICKABLE 29 down / 28 up, both +1'), category = _('Button Box - Landing gear panel')},
-- Off always turns on.  Every OTHER on turns off {down = 3028, up = 3029, cockpit_device_id = 38, value_down = 1.0,	value_up = 1.0, name = _('Anti-skid switch CLICKABLE 28 down / 29 up, both +1'), category = _('Button Box - Landing gear panel')},


---------------------------------------------------------------------------------------- AHCP -----------------------------------------------------------------------------------------
-- Master ARM/TRAIN
{down = iCommandPlaneAHCPMasterArm, up = iCommandPlaneAHCPMasterSafe,	name = _('Master switch ARM TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},
{down = iCommandPlaneAHCPMasterTrain, up = iCommandPlaneAHCPMasterSafe,	name = _('Master switch TRAIN TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},

-- Gun PACARM/ARM
{down = iCommandPlaneAHCPGUNPACArm, up = iCommandPlaneAHCPGUNSafe,		name = _('GUN/PAC switch PACARM TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},
{down = iCommandPlaneAHCPGUNArm, up = iCommandPlaneAHCPGUNSafe,			name = _('GUN/PAC switch GUNARM TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},-- Laser Arm

-- Laser ARM/TRAIN
{down = iCommandPlaneAHCPLaserArm, up = iCommandPlaneAHCPLaserSafe, 	name = _('LASER switch ARM TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},
{down = iCommandPlaneAHCPLaserTrain, up = iCommandPlaneAHCPLaserSafe, 	name = _('LASER switch TRAIN TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},

-- TGP
{down = 3004, up = 3004, cockpit_device_id = 7, value_down = 1.0,	value_up = -1.0, name = _('TGP switch CLICKABLE'), category = _('Button Box - Armament HUD Control Panel')},
-- Old {down = iCommandPlaneAHCPTGPOnOff, up = iCommandPlaneAHCPTGPOnOff, 		name = _('TGP switch TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},

-- CICU
{down = 3008, up = 3008, cockpit_device_id = 7, value_down = 1.0,	value_up = -1.0, name = _('CICU switch CLICKABLE'), category = _('Button Box - Armament HUD Control Panel')},
-- Old {down = iCommandPlaneAHCPCICUOnOff, up = iCommandPlaneAHCPCICUOnOff, 	name = _('CICU switch TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},

-- JTRS
{down = 3009, up = 3009, cockpit_device_id = 7, value_down = 1.0,	value_up = -1.0, name = _('JTRS switch CLICKABLE'), category = _('Button Box - Armament HUD Control Panel')},
-- Old {down = iCommandPlaneAHCPJTRSOnOff, up = iCommandPlaneAHCPJTRSOnOff, 	name = _('JTRS switch TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},

-- IFFCC
{down = iCommandPlaneAHCPIFFCCOn, up = iCommandPlaneAHCPIFFCCTest, 		name = _('IFFCC switch ON TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},
{down = iCommandPlaneAHCPIFFCCOff, up = iCommandPlaneAHCPIFFCCTest, 	name = _('IFFCC switch OFF TOGGLE'), category = _('Button Box - Armament HUD Control Panel')},

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
