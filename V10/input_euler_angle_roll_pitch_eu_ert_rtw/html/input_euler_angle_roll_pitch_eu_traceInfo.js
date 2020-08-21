function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "input_euler_angle_roll_pitch_eu"};
	this.sidHashMap["input_euler_angle_roll_pitch_eu"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "Copter_Plane_h2g_4_and_1:2208"};
	this.sidHashMap["Copter_Plane_h2g_4_and_1:2208"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>:1"] = {sid: "Copter_Plane_h2g_4_and_1:2208:1"};
	this.sidHashMap["Copter_Plane_h2g_4_and_1:2208:1"] = {rtwname: "<S1>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
