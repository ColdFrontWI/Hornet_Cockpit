-----------------------------------------------------------------------------------------
-- Eric's F/A-18C custom key commands
-- Insert into default.lua immediately after:
--     join(res.keyCommands,{
-- File location to default.lua ~\DCSWorld\Mods\aircraft\FA-18C\Input\FA-18C\joystick
-- Additional categories of controls will be present in the "CUSTOM..." categories
-----------------------------------------------------------------------------------------

-- WARTHOG THROTTLE SPECIAL CONTROLS
-- Throttles IDLE/OFF
{down = iCommandLeftEngineStop,	up = iCommandLeftEngineStart, value_down =  1.0, value_up = 1.0,	name = _('Throttle (Left) - OFF/IDLE'), category = {_('CUSTOM - Warthog Throttle')}},
{down = iCommandRightEngineStop, up = iCommandRightEngineStart, value_down =  1.0, value_up = 1.0,	name = _('Throttle (Right) - OFF/IDLE'), category = {_('CUSTOM - Warthog Throttle')}},
-- Throttle pinky switch for exterior lights
{down = hotas_commands.THROTTLE_EXTERIOR_LIGTHS, up = hotas_commands.THROTTLE_EXTERIOR_LIGTHS, cockpit_device_id = devices.HOTAS, value_down =  1.0, value_up = 0.0, name = _('Exterior Lights Switch - Toggle'), category = {_('CUSTOM - Warthog Throttle')}},


-- CODE FOR TOGGLES THAT DO NOT HAVE PROPER ON/OFF SETTINGS
-- Some toggles only have switches that allow for down/up settings with a toggle
{down = gear_commands.LaunchBarSw,      cockpit_device_id = devices.GEAR_INTERFACE,    value_down = -1.0, name = _('Launch Bar - Retract'),         category = {_('CUSTOM - Arduino')}},
{down = gear_commands.LaunchBarSw,      cockpit_device_id = devices.GEAR_INTERFACE,    value_down =  1.0, name = _('Launch Bar - Extend'),          category = {_('CUSTOM - Arduino')}},
{down = engines_commands.APU_ControlSw,	cockpit_device_id = devices.ENGINES_INTERFACE, value_down =  1.0, name = _('APU Control Switch - ON'),      category = {_('CUSTOM - Arduino')}},
{down = engines_commands.APU_ControlSw,	cockpit_device_id = devices.ENGINES_INTERFACE, value_down = -1.0, name = _('APU Control Switch - OFF'),     category = {_('CUSTOM - Arduino')}},
{down = fuel_commands.DumpSw,           cockpit_device_id = devices.FUEL_INTERFACE,    value_down =  1.0, name = _('Fuel Dump Switch - ON'),        category = {_('CUSTOM - Arduino')}},
{down = fuel_commands.DumpSw,           cockpit_device_id = devices.FUEL_INTERFACE,    value_down =  0.0, name = _('Fuel Dump Switch - OFF'),       category = {_('CUSTOM - Arduino')}},
{down = ECS_commands.AV_COOL_Sw,        cockpit_device_id = devices.ECS_INTERFACE,     value_down =  1.0, name = _('AV COOL Switch - EMERG'),       category = {_('CUSTOM - Arduino')}},
{down = ECS_commands.AV_COOL_Sw,        cockpit_device_id = devices.ECS_INTERFACE,     value_down =  0.0, name = _('AV COOL Switch - NORM'),        category = {_('CUSTOM - Arduino')}},
{down = elec_commands.PitotHeater,      cockpit_device_id = devices.ELEC_INTERFACE,    value_down =  1.0, name = _('Pitot Heater Switch - ON'),     category = {_('CUSTOM - Arduino')}},
{down = elec_commands.PitotHeater,      cockpit_device_id = devices.ELEC_INTERFACE,    value_down = -1.0, name = _('Pitot Heater Switch - OFF'),    category = {_('CUSTOM - Arduino')}},
{down = cptlights_commands.HookBypass,  cockpit_device_id = devices.CPT_LIGTHS,        value_down =  1.0, name = _('Hook Bypass Switch - FIELD'),   category = {_('CUSTOM - Arduino')}},
{down = cptlights_commands.HookBypass,  cockpit_device_id = devices.CPT_LIGTHS,        value_down = -1.0, name = _('Hook Bypass Switch - CARRIER'), category = {_('CUSTOM - Arduino')}},


-- LEFT CONSOLE SPECIAL CONTROLS
-- OBOGS
{down = oxygen_commands.OBOGS_ControlSw, up = oxygen_commands.OBOGS_ControlSw, cockpit_device_id = devices.OXYGEN_INTERFACE, value_down = 1.0, value_up = 0.0, name = _('OBOGS - Toggle'), category = {_('CUSTOM - Left Console')}},
-- GAIN
{down = ctrl_commands.GainSw, up = ctrl_commands.GainSw, cockpit_device_id = devices.CONTROL_INTERFACE, value_down =  1.0, value_up = 0.0, name = _('GAIN Switch - Toggle'), category = {_('CUSTOM - Left Console')}},
{down = ctrl_commands.GainSwCover, up = ctrl_commands.GainSwCover, cockpit_device_id = devices.CONTROL_INTERFACE, value_down =  1.0, value_up = 0.0, name = _('GAIN Switch Cover - Toggle Norm'), category = {_('CUSTOM - Left Console')}},
{down = ctrl_commands.GainSwCover, up = ctrl_commands.GainSwCover, cockpit_device_id = devices.CONTROL_INTERFACE, value_down =  0.0, value_up = 1.0, name = _('GAIN Switch Cover - Toggle Reverse'), category = {_('CUSTOM - Left Console')}},
-- INTR WING
{down = fuel_commands.IntrWingInhibitSw, up = fuel_commands.IntrWingInhibitSw, cockpit_device_id = devices.FUEL_INTERFACE, value_down = 1.0, value_up = 0.0, name = _('INTR WING - Toggle'), category = {_('CUSTOM - Left Console')}},
-- Landing gear
{down = iCommandPlaneGearUp, up = iCommandPlaneGearDown, name = _('Landing Gear - Toggle Norm'), category = _('CUSTOM - Left Console')},
{down = iCommandPlaneGearDown, up = iCommandPlaneGearUp, name = _('Landing Gear - Toggle Reverse'), category = _('CUSTOM - Left Console')},
-- Launch Bar
{down = gear_commands.LaunchBarSw, up = gear_commands.LaunchBarSw, cockpit_device_id = devices.GEAR_INTERFACE, value_down = 1.0, value_up = -1.0, name = _('Launch Bar - Toggle Norm'), category = {_('CUSTOM - Left Console')}},
{down = gear_commands.LaunchBarSw, up = gear_commands.LaunchBarSw, cockpit_device_id = devices.GEAR_INTERFACE, value_down = -1.0, value_up = 1.0, name = _('Launch Bar - Toggle Reverse'), category = {_('CUSTOM - Left Console')}},
-- Park/Emergency Brake
{down = gear_commands.EmergParkHandleOnOff,	up = gear_commands.EmergParkHandleOnOff, cockpit_device_id = devices.GEAR_INTERFACE, value_down = -1.0, value_up = 1.0, name = _('Parking Brake Pull - Momentary'), category = {_('CUSTOM - Left Console')}},
-- Anti Skid
{down = gear_commands.AntiSkidSw, up = gear_commands.AntiSkidSw, cockpit_device_id = devices.GEAR_INTERFACE, value_down = 1.0, value_up = 0.0, name = _('Anti Skid Switch - Toggle'), category = {_('CUSTOM - Left Console')}},
-- Landing / Taxi light
{down = extlights_commands.LdgTaxi, up = extlights_commands.LdgTaxi, cockpit_device_id = devices.EXT_LIGHTS, value_down = 1.0, value_up = 0.0, name = _('Landing / Taxi Light - Toggle'), category = {_('CUSTOM - Left Console')}},
-- Hook Bypass
{down = cptlights_commands.HookBypass, up = cptlights_commands.HookBypass, cockpit_device_id = devices.CPT_LIGTHS, value_down = 1.0, value_up = -1.0, name = _('Hook Bypass Switch - Toggle Norm'), category = {_('CUSTOM - Left Console')}},
{down = cptlights_commands.HookBypass, up = cptlights_commands.HookBypass, cockpit_device_id = devices.CPT_LIGTHS, value_down = -1.0, value_up = 1.0, name = _('Hook Bypass Switch - Toggle Reverse'), category = {_('CUSTOM - Left Console')}},


-- RIGHT CONSOLE SPECIAL CONTROLS
-- Wing Fold stuff
{down = ctrl_commands.WingFoldPull, up = ctrl_commands.WingFoldPull, cockpit_device_id = devices.CONTROL_INTERFACE,	value_down =  0.0, value_up = 1.0, name = _('Wing Fold Stow Toggle'), category = {_('CUSTOM - Right Console')}},
-- LTD/R
-- Updated to reflect only two positions for the LTD/R switch
{down = tgp_commands.LtdrArm_EXT, up = tgp_commands.LtdrArm_EXT, cockpit_device_id = devices.TGP_INTERFACE, value_down = 1.0, value_up = -1.0, name = _('LTD/R Switch - Toggle'), category = {_('CUSTOM - Right Console'), }},
-- {down = tgp_commands.Ltdr, up = tgp_commands.Ltdr, cockpit_device_id = devices.TGP_INTERFACE, value_down = -1.0, value_up = 0.0, name = _('LTD/R Switch - Toggle AFT/SAFE'), category = {_('CUSTOM - Right Console')}},
-- {down = tgp_commands.Ltdr, up = tgp_commands.Ltdr, cockpit_device_id = devices.TGP_INTERFACE, value_down =  1.0, value_up = 0.0, name = _('LTD/R Switch - Toggle ARM/SAFE'), category = {_('CUSTOM - Right Console')}},
-- LST/NFLIR
{down = tgp_commands.Lst, up = tgp_commands.Lst, cockpit_device_id = devices.TGP_INTERFACE, value_down =  1.0, value_up = 0, name = _('LST/NFLR Switch - Toggle'), category = {_('CUSTOM - Right Console')}},
-- Hook
{down = gear_commands.HookHandle, up = gear_commands.HookHandle, cockpit_device_id = devices.GEAR_INTERFACE, value_down =  0.0,	value_up = 1.0, name = _('Arresting Hook - Toggle Reverse'), category = {_('CUSTOM - Right Console')}},
{down = gear_commands.HookHandle, up = gear_commands.HookHandle, cockpit_device_id = devices.GEAR_INTERFACE, value_down =  1.0,	value_up = 0.0, name = _('Arresting Hook - Toggle Norm'), category = {_('CUSTOM - Right Console')}},
-- Pitot Heat
{down = elec_commands.PitotHeater, up = elec_commands.PitotHeater, cockpit_device_id = devices.ELEC_INTERFACE, value_down =  1.0, value_up = -1.0, name = _('Pitot Heater Switch - Toggle'),category = {_('CUSTOM - Right Console')}},
-- Left and right generator
{down = elec_commands.LGenSw, up = elec_commands.LGenSw, cockpit_device_id = devices.ELEC_INTERFACE, value_down = 1.0, value_up = 0.0, name = _('Left Generator - Toggle'), category = {_('CUSTOM - Right Console')}},
{down = elec_commands.RGenSw, up = elec_commands.RGenSw, cockpit_device_id = devices.ELEC_INTERFACE, value_down = 1.0, value_up = 0.0, name = _('Right Generator - Toggle'), category = {_('CUSTOM - Right Console')}},


-- INSTRUMENT PANEL SPECIAL CONTROLS
-- Master Arm Switch
{down = SMS_commands.MasterArmSw, up = SMS_commands.MasterArmSw, cockpit_device_id = devices.SMS, value_down =  1.0, value_up = 0.0, name = _('Master Arm - Toggle'), category = {_('CUSTOM - Inst Panel')}},
-- HUD Day/Night
{down = HUD_commands.HUD_SymbBrightSelKnob, up = HUD_commands.HUD_SymbBrightSelKnob, cockpit_device_id = devices.HUD, value_down = 1.0, value_up = 0.0, name = _('HUD Day/Night - Toggle Norm'), category = {_('CUSTOM - Inst Panel')}},
{down = HUD_commands.HUD_SymbBrightSelKnob, up = HUD_commands.HUD_SymbBrightSelKnob, cockpit_device_id = devices.HUD, value_down = 0.0, value_up = 1.0, name = _('HUD Day/Night - Toggle Reverse'), category = {_('CUSTOM - Inst Panel')}},
-- ALT Baro/Rdr
{down = HUD_commands.HUD_AltitudeSw, up = HUD_commands.HUD_AltitudeSw, cockpit_device_id = devices.HUD, value_down = 1.0, value_up = 0.0, name = _('HUD Alt Baro/RDR - Toggle Norm'), category = {_('CUSTOM - Inst Panel')}},
{down = HUD_commands.HUD_AltitudeSw, up = HUD_commands.HUD_AltitudeSw, cockpit_device_id = devices.HUD, value_down = 0.0, value_up = 1.0, name = _('HUD Alt Baro/RDR - Toggle Reverse'), category = {_('CUSTOM - Inst Panel')}},
-- Spin Recovery
{down = ctrl_commands.SpinRecCover, up = ctrl_commands.SpinRecCover, cockpit_device_id = devices.CONTROL_INTERFACE, value_down = 0.0, value_up = 1.0, name = _('Spin Recovery Cover - Toggle Open/Close'), category = {_('CUSTOM - Inst Panel')}},
{down = ctrl_commands.SpinRec, up = ctrl_commands.SpinRec, cockpit_device_id = devices.CONTROL_INTERFACE, value_down = 1.0, value_up = 0.0, name = _('Spin Recovery - Toggle RCVY/NORM'), category = {_('CUSTOM - Inst Panel')}},


-- REFERENCE
-- {	down = hotas_commands.THROTTLE_EXTERIOR_LIGTHS_EXT,																				cockpit_device_id = devices.HOTAS,	value_down =  1.0,					name = _('Exterior Lights Switch - ON/OFF'),				category = {_('Throttle Grip'), _('HOTAS')}},
-- {	down = hotas_commands.THROTTLE_EXTERIOR_LIGTHS,																					cockpit_device_id = devices.HOTAS,	value_down =  1.0,					name = _('Exterior Lights Switch - ON'),					category = {_('Throttle Grip'), _('HOTAS')}},
-- {	down = hotas_commands.THROTTLE_EXTERIOR_LIGTHS,																					cockpit_device_id = devices.HOTAS,	value_down =  0.0,					name = _('Exterior Lights Switch - OFF'),					category = {_('Throttle Grip'), _('HOTAS')}},

-- {	down = fuel_commands.IntrWingInhibitSw_EXT,														cockpit_device_id = devices.FUEL_INTERFACE,			value_down =  0.0,						name = _('Internal Wing Tank Fuel Control Switch - INHIBIT/NORM'),	category = {_('Left Console'), _('Exterior Lights Panel')}},
-- {	down = fuel_commands.IntrWingInhibitSw,															cockpit_device_id = devices.FUEL_INTERFACE,			value_down =  1.0,						name = _('Internal Wing Tank Fuel Control Switch - INHIBIT'),		category = {_('Left Console'), _('Exterior Lights Panel')}},
-- {	down = fuel_commands.IntrWingInhibitSw,															cockpit_device_id = devices.FUEL_INTERFACE,			value_down =  0.0,						name = _('Internal Wing Tank Fuel Control Switch - NORM'),			category = {_('Left Console'), _('Exterior Lights Panel')}},

-- {	down = ctrl_commands.GainSwCover_EXT,															cockpit_device_id = devices.CONTROL_INTERFACE,		value_down =  0.0,						name = _('GAIN Switch Cover - OPEN/CLOSE'),							category = {_('Left Console'), _('FCS Panel')}},
-- {	down = ctrl_commands.GainSwCover,																cockpit_device_id = devices.CONTROL_INTERFACE,		value_down =  1.0,						name = _('GAIN Switch Cover - OPEN'),								category = {_('Left Console'), _('FCS Panel')}},
-- {	down = ctrl_commands.GainSwCover,																cockpit_device_id = devices.CONTROL_INTERFACE,		value_down =  0.0,						name = _('GAIN Switch Cover - CLOSE'),								category = {_('Left Console'), _('FCS Panel')}},
-- {	down = ctrl_commands.GainSw_EXT,																cockpit_device_id = devices.CONTROL_INTERFACE,		value_down =  0.0,						name = _('GAIN Switch - NORM/ORIDE'),								category = {_('Left Console'), _('FCS Panel')}},
-- {	down = ctrl_commands.GainSw,																	cockpit_device_id = devices.CONTROL_INTERFACE,		value_down =  1.0,						name = _('GAIN Switch - ORIDE'),									category = {_('Left Console'), _('FCS Panel')}},
-- {	down = ctrl_commands.GainSw,																	cockpit_device_id = devices.CONTROL_INTERFACE,		value_down =  0.0,						name = _('GAIN Switch - NORM'),										category = {_('Left Console'), _('FCS Panel')}},


-- For some reason, the ECM controls are commented in the default.lua file.
-- Adding them back, and putting them in the CUSTOM group.
-- Turns out these don't work, so re-commenting
-- {	down = _ITER,				cockpit_device_id = devices.CMDS,	value_down = -1.0,						name = _('ALQ-126 ECM Mode Switch - CCW'),				category = {_('CUSTOM')}},
-- {	down = _ITER,				cockpit_device_id = devices.CMDS,	value_down =  1.0,						name = _('ALQ-126 ECM Mode Switch - CW'),				category = {_('CUSTOM')}},
-- {	down = ,					cockpit_device_id = devices.CMDS,	value_down =  0.4,						name = _('ALQ-126 ECM Mode Switch - XMIT'),				category = {_('CUSTOM')}},
-- {	down = ,					cockpit_device_id = devices.CMDS,	value_down =  0.3,						name = _('ALQ-126 ECM Mode Switch - REC'),				category = {_('CUSTOM')}},
-- {	down = ,					cockpit_device_id = devices.CMDS,	value_down =  0.2,						name = _('ALQ-126 ECM Mode Switch - BIT'),				category = {_('CUSTOM')}},
-- {	down = ,					cockpit_device_id = devices.CMDS,	value_down =  0.1,						name = _('ALQ-126 ECM Mode Switch - STBY'),				category = {_('CUSTOM')}},
-- {	down = ,					cockpit_device_id = devices.CMDS,	value_down =  0.0,						name = _('ALQ-126 ECM Mode Switch - OFF'),				category = {_('CUSTOM')}},

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------